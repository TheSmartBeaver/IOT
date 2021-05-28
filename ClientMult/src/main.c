#include <anjay/anjay.h>
#include <anjay/attr_storage.h>
#include <anjay/security.h>
#include <anjay/server.h>
#include <avsystem/commons/avs_log.h>

#include <pthread.h>
#include <string.h>

#include <poll.h>

#include "dimmer.h"
#include "on_off_switch.h"
#include "light_control.h"
#include "presence_captor.h"

/*dimmer_object_create(void);
on_off_switch_object_create(void);
light_control_object_create(void);
presence_object_create(void);

dimmer_object_release(const anjay_dm_object_def_t **def);
on_off_switch_object_release(const anjay_dm_object_def_t **def);
light_control_object_release(const anjay_dm_object_def_t **def);
presence_object_release(const anjay_dm_object_def_t **def);*/

typedef struct objects_to_be_modified
{
    const anjay_dm_object_def_t **dimmer_object;
    const anjay_dm_object_def_t **on_off_switch_object;
    const anjay_dm_object_def_t **light_control_object;
    const anjay_dm_object_def_t **presence_captor_object;

    anjay_t *anjay;

} objects_to_be_modified_t;

int main_loop(anjay_t *anjay)
{
    while (true)
    {
        // Obtain all network data sources
        AVS_LIST(avs_net_socket_t *const)
        sockets = anjay_get_sockets(anjay);

        // Prepare to poll() on them
        size_t numsocks = AVS_LIST_SIZE(sockets);
        struct pollfd pollfds[numsocks];
        size_t i = 0;
        AVS_LIST(avs_net_socket_t *const)
        sock;
        AVS_LIST_FOREACH(sock, sockets)
        {
            pollfds[i].fd = *(const int *)avs_net_socket_get_system(*sock);
            pollfds[i].events = POLLIN;
            pollfds[i].revents = 0;
            ++i;
        }

        const int max_wait_time_ms = 1000;
        // Determine the expected time to the next job in milliseconds.
        // If there is no job we will wait till something arrives for
        // at most 1 second (i.e. max_wait_time_ms).
        int wait_ms =
            anjay_sched_calculate_wait_time_ms(anjay, max_wait_time_ms);

        // Wait for the events if necessary, and handle them.
        if (poll(pollfds, numsocks, wait_ms) > 0)
        {
            int socket_id = 0;
            AVS_LIST(avs_net_socket_t *const)
            socket = NULL;
            AVS_LIST_FOREACH(socket, sockets)
            {
                if (pollfds[socket_id].revents)
                {
                    if (anjay_serve(anjay, *socket))
                    {
                        avs_log(tutorial, ERROR, "anjay_serve failed");
                    }
                }
                ++socket_id;
            }
        }

        // Finally run the scheduler
        //printf("\n ON BOUCLE \n");
        anjay_sched_run(anjay);
    }
    return 0;
}

// Installs Security Object and adds and instance of it.
// An instance of Security Object provides information needed to connect to
// LwM2M server.
static int setup_security_object(anjay_t *anjay)
{
    if (anjay_security_object_install(anjay))
    {
        return -1;
    }

    static const char PSK_IDENTITY[] = "identity";
    static const char PSK_KEY[] = "P4s$w0rd";

    anjay_security_instance_t security_instance = {
        .ssid = 1,
        //Utiliser cet URI localement pour Leshan : coap://0.0.0.0/0.0.0.0:5683
        .server_uri = "coap://localhost:5683",
        //.server_uri = "coap://try-anjay.avsystem.com:5683",
        .security_mode = ANJAY_SECURITY_NOSEC};

    // Anjay will assign Instance ID automatically
    anjay_iid_t security_instance_id = ANJAY_ID_INVALID;
    if (anjay_security_object_add_instance(anjay, &security_instance,
                                           &security_instance_id))
    {
        return -1;
    }

    return 0;
}

// Installs Server Object and adds and instance of it.
// An instance of Server Object provides the data related to a LwM2M Server.
static int setup_server_object(anjay_t *anjay)
{
    if (anjay_server_object_install(anjay))
    {
        return -1;
    }

    const anjay_server_instance_t server_instance = {
        // Server Short ID
        .ssid = 1,
        // Client will send Update message often than every 60 seconds
        .lifetime = 60,
        // Disable Default Minimum Period resource
        .default_min_period = -1,
        // Disable Default Maximum Period resource
        .default_max_period = -1,
        // Disable Disable Timeout resource
        .disable_timeout = -1,
        // Sets preferred transport to UDP
        .binding = "U"};

    // Anjay will assign Instance ID automatically
    anjay_iid_t server_instance_id = ANJAY_ID_INVALID;
    if (anjay_server_object_add_instance(anjay, &server_instance,
                                         &server_instance_id))
    {
        return -1;
    }

    return 0;
}

void *get_commands_from_terminal(void *p)
{
    char c;
    //char command[50];
    char *command = (char *)malloc((51) * sizeof(char));
    //char command_splitted[5][50];
    //int index_arg_command = 0;

    //TEST
    objects_to_be_modified_t *struct_ptr = (objects_to_be_modified_t *)p;
    print_LightControl(struct_ptr->light_control_object);

    while ((c = getchar()) != EOF)
    {
        //putchar(c);
        if (c == '\n')
        {
            printf("Commande détectée %s \n", command);

            char *token = strtok(command, " ");
            char *token2 = strtok(NULL, " "); //id de l'instance dont on modifie le state

            //printf("taille du 2è argument %d\n", strlen(token2));
            if (!token2)
            {
                printf("2ème argument manquant !\n");
                continue;
            }

            int id_inst = atoi(token2);
            printf("ARG 2 = %d\n", id_inst);
            printf("ARG 2 = %d\n", atoi(token2));

            if (strcmp(token, "a") == 0)
            {
                change_switch_state(struct_ptr->on_off_switch_object, id_inst, true);
                switch_object_notify(struct_ptr->anjay, struct_ptr->on_off_switch_object);
            }
            else if (strcmp(token, "e") == 0)
            {
                change_switch_state(struct_ptr->on_off_switch_object, id_inst, false);
                switch_object_notify(struct_ptr->anjay, struct_ptr->on_off_switch_object);
            }
            else if (strcmp(token, "+") == 0)
            {
                change_dimmer_level(struct_ptr->dimmer_object, id_inst, true);
                dimmer_object_notify(struct_ptr->anjay, struct_ptr->dimmer_object);
            }
            else if (strcmp(token, "-") == 0)
            {
                change_dimmer_level(struct_ptr->dimmer_object, id_inst, false);
                dimmer_object_notify(struct_ptr->anjay, struct_ptr->dimmer_object);
            }
            else if (strcmp(token, "presence") == 0)
            {

                make_detection(struct_ptr->presence_captor_object, id_inst);
                presence_object_notify(struct_ptr->anjay, struct_ptr->presence_captor_object);
            }
            else /* default: */
            {
                printf("Commande inconnue");
            }
            //memset(command, 0, sizeof(command));
            command = (char *)malloc((51) * sizeof(char));
        }
        else
        {
            strncat(command, &c, 1);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        avs_log(tutorial, ERROR, "usage: %s ENDPOINT_NAME", argv[0]);
        return -1;
    }

    const anjay_configuration_t CONFIG = {
        .endpoint_name = argv[1],
        .in_buffer_size = 4000,
        .out_buffer_size = 4000,
        .msg_cache_size = 4000};

    anjay_t *anjay = anjay_new(&CONFIG);
    if (!anjay)
    {
        avs_log(tutorial, ERROR, "Could not create Anjay object");
        return -1;
    }

    int result = 0;
    // Install Attribute storage and setup necessary objects
    if (anjay_attr_storage_install(anjay) || setup_security_object(anjay) || setup_server_object(anjay))
    {
        result = -1;
    }

    //MODIFIER
    const anjay_dm_object_def_t **dimmer_object = NULL;
    const anjay_dm_object_def_t **on_off_switch_object = NULL;
    const anjay_dm_object_def_t **light_control_object = NULL;
    const anjay_dm_object_def_t **presence_captor_object = NULL;
    if (!result)
    {
        //MODIFIER
        dimmer_object = dimmer_object_create();
        on_off_switch_object = on_off_switch_object_create();
        light_control_object = light_control_object_create();
        presence_captor_object = presence_object_create();
        //MODIFIER
        if (dimmer_object && on_off_switch_object && light_control_object && presence_captor_object)
        {
            //MODIFIER
            printf("\n ça passe 0\n");
            result = anjay_register_object(anjay, dimmer_object);
            printf("\n ça passe 1\n");
            result = anjay_register_object(anjay, on_off_switch_object);
            printf("\n ça passe 2\n");
            result = anjay_register_object(anjay, light_control_object);
            printf("\n ça passe 3\n");
            result = anjay_register_object(anjay, presence_captor_object);
            printf("\n ça passe 4\n");

            //print_LightControl(light_control_object);
        }
        else
        {
            result = -1;
        }
    }

    if (!result)
    {
        // ON LANCE thread pour récupérer commande du terminal !
        pthread_t id;

        // On passe les objets crées au thread en param
        objects_to_be_modified_t args;
        args.dimmer_object = dimmer_object;
        args.light_control_object = light_control_object;
        args.on_off_switch_object = on_off_switch_object;
        args.presence_captor_object = presence_captor_object;

        args.anjay = anjay;

        //print_LightControl(args.light_control_object);

        pthread_create(&id, NULL, get_commands_from_terminal, &args);

        //ON LOOP
        result = main_loop(anjay);
    }

    //ON ne vient jamais ICI car LOOP unbreakable ??????
    anjay_delete(anjay);
    //MODIFIER
    dimmer_object_release(dimmer_object);
    on_off_switch_object_release(on_off_switch_object);
    light_control_object_release(light_control_object);
    presence_object_release(presence_captor_object);
    return result;
}
