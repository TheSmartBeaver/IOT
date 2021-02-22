/**
 * Generated by anjay_codegen.py on 2021-02-21 15:53:37
 *
 * LwM2M Object: Dimmer
 * ID: 3343, URN: urn:oma:lwm2m:ext:3343, Optional, Multiple
 *
 * This IPSO object should be used with a dimmer or level control to
 * report the state of the control.
 */
#include <assert.h>
#include <stdbool.h>

#include <anjay/anjay.h>
#include <avsystem/commons/avs_defs.h>
#include <avsystem/commons/avs_list.h>
#include <avsystem/commons/avs_memory.h>

/**
 * Level: RW, Single, Mandatory
 * type: float, range: 0..100, unit: /100
 * Used to represent a level control such as audio volume.
 */
#define RID_LEVEL 5548

/**
 * Application Type: RW, Single, Optional
 * type: string, range: N/A, unit: N/A
 * The application type of the sensor or actuator as a string depending
 * on the use case.
 */
#define RID_APPLICATION_TYPE 5750

/**
 * On time: RW, Single, Optional
 * type: integer, range: N/A, unit: s
 * The time in seconds that the device has been on. Writing a value of 0
 * resets the counter.
 */
#define RID_ON_TIME 5852

/**
 * Off Time: RW, Single, Optional
 * type: integer, range: N/A, unit: s
 * The time in seconds in the off state. Writing a value of 0 resets the
 * counter.
 */
#define RID_OFF_TIME 5854

typedef struct dimmer_instance_struct
{
    anjay_iid_t iid;
    char application_type[64];
    float level;
    char application_type_backup[64];
    // TODO???????: instance state
} dimmer_instance_t;

typedef struct dimmer_object_struct
{
    const anjay_dm_object_def_t *def;
    AVS_LIST(dimmer_instance_t)
    instances;

    // TODO??Besoin de rien de plus ???: object state
    //
} dimmer_object_t;

static inline dimmer_object_t *
get_obj(const anjay_dm_object_def_t *const *obj_ptr)
{
    assert(obj_ptr);
    return AVS_CONTAINER_OF(obj_ptr, dimmer_object_t, def);
}

static dimmer_instance_t *find_instance(const dimmer_object_t *obj,
                                        anjay_iid_t iid)
{
    AVS_LIST(dimmer_instance_t)
    it;
    AVS_LIST_FOREACH(it, obj->instances)
    {
        if (it->iid == iid)
        {
            return it;
        }
        else if (it->iid > iid)
        {
            break;
        }
    }

    return NULL;
}

static int list_instances(anjay_t *anjay,
                          const anjay_dm_object_def_t *const *obj_ptr,
                          anjay_dm_list_ctx_t *ctx)
{
    (void)anjay;

    AVS_LIST(dimmer_instance_t)
    it;
    AVS_LIST_FOREACH(it, get_obj(obj_ptr)->instances)
    {
        anjay_dm_emit(ctx, it->iid);
    }

    return 0;
}

static int init_instance(dimmer_instance_t *inst, anjay_iid_t iid)
{
    assert(iid != ANJAY_ID_INVALID);

    inst->iid = iid;
    //On init le state de l'instance
    // TODO???????: instance init
    inst->application_type[0] = '\0';
    inst->level = 0;

    // TODO: return 0 on success, negative value on failure
    return 0;
}

static void release_instance(dimmer_instance_t *inst)
{
    // TODO: instance cleanup
    // Je dois nettoyer des trucs ??

    (void)inst; //Pour éviter remarque compilateur var pas utilisé
}

static dimmer_instance_t *
add_instance(dimmer_object_t *obj, anjay_iid_t iid)
{
    assert(find_instance(obj, iid) == NULL);

    AVS_LIST(dimmer_instance_t)
    created =
        AVS_LIST_NEW_ELEMENT(dimmer_instance_t);
    if (!created)
    {
        return NULL;
    }

    int result = init_instance(created, iid);
    if (result)
    {
        AVS_LIST_CLEAR(&created);
        return NULL;
    }

    AVS_LIST(dimmer_instance_t) * ptr;
    AVS_LIST_FOREACH_PTR(ptr, &obj->instances)
    {
        if ((*ptr)->iid > created->iid)
        {
            break;
        }
    }

    AVS_LIST_INSERT(ptr, created);
    return created;
}

static int instance_create(anjay_t *anjay,
                           const anjay_dm_object_def_t *const *obj_ptr,
                           anjay_iid_t iid)
{
    (void)anjay;
    dimmer_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    return add_instance(obj, iid) ? 0 : ANJAY_ERR_INTERNAL;
}

static int instance_remove(anjay_t *anjay,
                           const anjay_dm_object_def_t *const *obj_ptr,
                           anjay_iid_t iid)
{
    (void)anjay;
    dimmer_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    AVS_LIST(dimmer_instance_t) * it;
    AVS_LIST_FOREACH_PTR(it, &obj->instances)
    {
        if ((*it)->iid == iid)
        {
            release_instance(*it);
            AVS_LIST_DELETE(it);
            return 0;
        }
        else if ((*it)->iid > iid)
        {
            break;
        }
    }

    assert(0);
    return ANJAY_ERR_NOT_FOUND;
}

static int instance_reset(anjay_t *anjay,
                          const anjay_dm_object_def_t *const *obj_ptr,
                          anjay_iid_t iid)
{
    (void)anjay;

    dimmer_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    dimmer_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    // TODO??????: instance reset
    inst->application_type[0] = '\0';
    inst->level = 0;
    return 0;
}

static int list_resources(anjay_t *anjay,
                          const anjay_dm_object_def_t *const *obj_ptr,
                          anjay_iid_t iid,
                          anjay_dm_resource_list_ctx_t *ctx)
{
    (void)anjay;
    (void)obj_ptr;
    (void)iid;

    //J'ajoute possibilité d'écriture pour level...
    anjay_dm_emit_res(ctx, RID_LEVEL,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_APPLICATION_TYPE,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_ON_TIME,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_OFF_TIME,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    return 0;
}

static int resource_read(anjay_t *anjay,
                         const anjay_dm_object_def_t *const *obj_ptr,
                         anjay_iid_t iid,
                         anjay_rid_t rid,
                         anjay_riid_t riid,
                         anjay_output_ctx_t *ctx)
{
    (void)anjay;

    printf("\n On lit un truc \n ");

    dimmer_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    dimmer_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
    case RID_LEVEL:
        assert(riid == ANJAY_ID_INVALID);
        //return anjay_ret_float(ctx, inst->level); // TODO
        // Niveau luminosité !
        printf("On lit level \n ");
        return anjay_ret_float(ctx, inst->level);

    case RID_APPLICATION_TYPE:
        assert(riid == ANJAY_ID_INVALID);
        printf("On lit app type \n ");
        return anjay_ret_string(ctx, inst->application_type);

    case RID_ON_TIME:
        assert(riid == ANJAY_ID_INVALID);
        printf("On lit onTime \n ");
        return anjay_ret_i32(ctx, 0); // TODO
        // Pas utile ???

    case RID_OFF_TIME:
        assert(riid == ANJAY_ID_INVALID);
        printf("On lit offTime \n ");
        return anjay_ret_i32(ctx, 0); // TODO
        // Pas utile ???

    default:
        return ANJAY_ERR_METHOD_NOT_ALLOWED;
    }
}

static int resource_write(anjay_t *anjay,
                          const anjay_dm_object_def_t *const *obj_ptr,
                          anjay_iid_t iid,
                          anjay_rid_t rid,
                          anjay_riid_t riid,
                          anjay_input_ctx_t *ctx)
{
    (void)anjay;

    printf("\n On écrit un truc \n ");

    dimmer_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    dimmer_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
    case RID_LEVEL:
    {
        assert(riid == ANJAY_ID_INVALID);
        //float value;                         // TODO
        //INTERDIRE les valeurs hors de l'intervalle 0-1
        return anjay_get_float(ctx, &inst->level); // TODO

        //float value = 99.0;                  // TODO
        //return anjay_get_float(ctx, &value); // TODO
    }

    case RID_APPLICATION_TYPE:
    {
        assert(riid == ANJAY_ID_INVALID);
        //char value[256];                                    // TODO
        return anjay_get_string(ctx, inst->application_type, sizeof(inst->application_type)); // TODO
    }

    case RID_ON_TIME:
    {
        assert(riid == ANJAY_ID_INVALID);
        int32_t value;                     // TODO
        return anjay_get_i32(ctx, &value); // TODO
    }

    case RID_OFF_TIME:
    {
        assert(riid == ANJAY_ID_INVALID);
        int32_t value;                     // TODO
        return anjay_get_i32(ctx, &value); // TODO
    }

    default:
        return ANJAY_ERR_METHOD_NOT_ALLOWED;
    }
}

static const anjay_dm_object_def_t OBJ_DEF = {
    .oid = 3343,
    .handlers = {
        .list_instances = list_instances,
        .instance_create = instance_create,
        .instance_remove = instance_remove,
        .instance_reset = instance_reset,

        .list_resources = list_resources,
        .resource_read = resource_read,
        .resource_write = resource_write,

        // TODO: implement these if transactional write/create is required
        .transaction_begin = anjay_dm_transaction_NOOP,
        .transaction_validate = anjay_dm_transaction_NOOP,
        .transaction_commit = anjay_dm_transaction_NOOP,
        .transaction_rollback = anjay_dm_transaction_NOOP}};

const anjay_dm_object_def_t **dimmer_object_create(void)
{
    dimmer_object_t *obj = (dimmer_object_t *)avs_calloc(1, sizeof(dimmer_object_t));
    if (!obj)
    {
        return NULL;
    }
    obj->def = &OBJ_DEF;

    // TODO?????????: object init
    dimmer_instance_t *inst = add_instance(obj, 0);
    if (inst)
    {
        strcpy(inst->application_type, "Dimmer");
        inst->level = 57;
        printf("\n INITTTTT \n");
    }
    else
    {
        avs_free(obj);
        return NULL;
    }

    return &obj->def;
}

void dimmer_object_release(const anjay_dm_object_def_t **def)
{
    if (def)
    {
        dimmer_object_t *obj = get_obj(def);
        AVS_LIST_CLEAR(&obj->instances)
        {
            release_instance(obj->instances);
        }

        // TODO??????????: object cleanup

        avs_free(obj);
    }
}
