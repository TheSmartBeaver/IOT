#include <anjay/anjay.h>
#include <anjay/attr_storage.h>
#include <anjay/security.h>
#include <anjay/server.h>
#include <avsystem/commons/avs_log.h>

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
        .server_uri = "coap://try-anjay.avsystem.com:5683",
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

//Fonction prise de demo.c
/*static int
install_object(anjay_demo_t *demo,
               const anjay_dm_object_def_t **obj_ptr,
               anjay_demo_object_get_instances_t *get_instances_func,
               anjay_demo_object_notify_t *time_dependent_notify_func,
               anjay_demo_object_deleter_t *release_func)
{
    if (!obj_ptr)
    {
        return -1;
    }

    AVS_LIST(anjay_demo_object_t) *object_entry =
        AVS_LIST_APPEND_PTR(&demo->objects);
    assert(object_entry && !*object_entry);
    *object_entry = AVS_LIST_NEW_ELEMENT(anjay_demo_object_t);
    if (!*object_entry)
    {
        release_func(obj_ptr);
        return -1;
    }

    if (anjay_register_object(demo->anjay, obj_ptr))
    {
        release_func(obj_ptr);
        AVS_LIST_DELETE(object_entry);
        return -1;
    }

    (*object_entry)->obj_ptr = obj_ptr;
    (*object_entry)->get_instances_func =
        (get_instances_func ? get_instances_func : get_single_instance);
    (*object_entry)->time_dependent_notify_func = time_dependent_notify_func;
    (*object_entry)->release_func = release_func;
    return 0;
}*/

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
        }
        else
        {
            result = -1;
        }
    }

    if (!result)
    {
        result = main_loop(anjay);
    }

    anjay_delete(anjay);
    //MODIFIER
    dimmer_object_release(dimmer_object);
    on_off_switch_object_release(on_off_switch_object);
    light_control_object_release(light_control_object);
    presence_object_release(presence_captor_object);
    return result;
}
