/**
 * Generated by anjay_codegen.py on 2021-02-21 15:53:29
 *
 * LwM2M Object: On/Off switch
 * ID: 3342, URN: urn:oma:lwm2m:ext:3342:1.1, Optional, Multiple
 *
 * This IPSO object should be used with an On/Off switch to report the
 * state of the switch.
 */
#include <assert.h>
#include <stdbool.h>

#include <anjay/anjay.h>
#include <avsystem/commons/avs_defs.h>
#include <avsystem/commons/avs_list.h>
#include <avsystem/commons/avs_memory.h>

/**
 * Digital Input State: R, Single, Mandatory
 * type: boolean, range: N/A, unit: N/A
 * The current state of a digital input.
 */
#define RID_DIGITAL_INPUT_STATE 5500

/**
 * Digital Input Counter: R, Single, Optional
 * type: integer, range: N/A, unit: N/A
 * The cumulative value of active state detected.
 */
#define RID_DIGITAL_INPUT_COUNTER 5501

/**
 * Timestamp: R, Single, Optional
 * type: time, range: N/A, unit: N/A
 * The timestamp of when the measurement was performed.
 */
#define RID_TIMESTAMP 5518

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

/**
 * Fractional Timestamp: R, Single, Optional
 * type: float, range: 0..1, unit: s
 * Fractional part of the timestamp when sub-second precision is used
 * (e.g., 0.23 for 230 ms).
 */
#define RID_FRACTIONAL_TIMESTAMP 6050

typedef struct on_off_switch_instance_struct
{
    anjay_iid_t iid;
    char application_type[64];
    bool switch_state;
    uint64_t last_notify_timestamp;

    // TODO: instance state
} on_off_switch_instance_t;

typedef struct on_off_switch_object_struct
{
    const anjay_dm_object_def_t *def;
    AVS_LIST(on_off_switch_instance_t)
    instances;

    // TODO: object state
} on_off_switch_object_t;

static inline on_off_switch_object_t *
get_obj(const anjay_dm_object_def_t *const *obj_ptr)
{
    assert(obj_ptr);
    return AVS_CONTAINER_OF(obj_ptr, on_off_switch_object_t, def);
}

static on_off_switch_instance_t *find_instance(const on_off_switch_object_t *obj,
                                               anjay_iid_t iid)
{
    AVS_LIST(on_off_switch_instance_t)
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

    AVS_LIST(on_off_switch_instance_t)
    it;
    AVS_LIST_FOREACH(it, get_obj(obj_ptr)->instances)
    {
        anjay_dm_emit(ctx, it->iid);
    }

    return 0;
}

static int init_instance(on_off_switch_instance_t *inst, anjay_iid_t iid)
{
    assert(iid != ANJAY_ID_INVALID);

    inst->iid = iid;
    // TODO: instance init
    inst->application_type[0] = '\0';
    inst->switch_state = false;

    // TODO: return 0 on success, negative value on failure
    return 0;
}

static void release_instance(on_off_switch_instance_t *inst)
{
    // TODO: instance cleanup
    (void)inst;
}

static on_off_switch_instance_t *
add_instance(on_off_switch_object_t *obj, anjay_iid_t iid)
{
    assert(find_instance(obj, iid) == NULL);

    AVS_LIST(on_off_switch_instance_t)
    created =
        AVS_LIST_NEW_ELEMENT(on_off_switch_instance_t);
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

    AVS_LIST(on_off_switch_instance_t) * ptr;
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
    on_off_switch_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    return add_instance(obj, iid) ? 0 : ANJAY_ERR_INTERNAL;
}

static int instance_remove(anjay_t *anjay,
                           const anjay_dm_object_def_t *const *obj_ptr,
                           anjay_iid_t iid)
{
    (void)anjay;
    on_off_switch_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    AVS_LIST(on_off_switch_instance_t) * it;
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

    on_off_switch_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    on_off_switch_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    // TODO??????: instance reset
    inst->application_type[0] = '\0';
    inst->switch_state = false;
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

    anjay_dm_emit_res(ctx, RID_DIGITAL_INPUT_STATE,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_DIGITAL_INPUT_COUNTER,
                      ANJAY_DM_RES_R, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_TIMESTAMP,
                      ANJAY_DM_RES_R, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_APPLICATION_TYPE,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_ON_TIME,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_OFF_TIME,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_FRACTIONAL_TIMESTAMP,
                      ANJAY_DM_RES_R, ANJAY_DM_RES_PRESENT);
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

    on_off_switch_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    on_off_switch_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
    case RID_DIGITAL_INPUT_STATE:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_bool(ctx, inst->switch_state); // TODO

    case RID_DIGITAL_INPUT_COUNTER:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i32(ctx, 0); // TODO

    case RID_TIMESTAMP:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i64(ctx, 0); // TODO

    case RID_APPLICATION_TYPE:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_string(ctx, inst->application_type); // TODO

    case RID_ON_TIME:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i32(ctx, 0); // TODO

    case RID_OFF_TIME:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i32(ctx, 0); // TODO

    case RID_FRACTIONAL_TIMESTAMP:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_float(ctx, 0); // TODO

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

    on_off_switch_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    on_off_switch_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
        //Je rajoute ça mais sur le site ça dit qu'on est pas sensé pouvoir modifier... Pourquoi ??
    case RID_DIGITAL_INPUT_STATE:
    {
        assert(riid == ANJAY_ID_INVALID);
        anjay_get_bool(ctx, &inst->switch_state);
    }

    case RID_APPLICATION_TYPE:
    {
        assert(riid == ANJAY_ID_INVALID);                                                     // TODO
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
    .oid = 3342,
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

const anjay_dm_object_def_t **on_off_switch_object_create(void)
{
    on_off_switch_object_t *obj = (on_off_switch_object_t *)avs_calloc(1, sizeof(on_off_switch_object_t));
    if (!obj)
    {
        return NULL;
    }
    obj->def = &OBJ_DEF;

    // TODO: object init
    on_off_switch_instance_t *inst = add_instance(obj, 0);
    on_off_switch_instance_t *inst1 = add_instance(obj, 1);
    if (inst)
    {
        strcpy(inst->application_type, "On_off_Switch 0");
        strcpy(inst1->application_type, "On_off_Switch 1");
        inst->switch_state = false;
        printf("\n INITTTTT \n");
    }
    else
    {
        avs_free(obj);
        return NULL;
    }

    return &obj->def;
}

void on_off_switch_object_release(const anjay_dm_object_def_t **def)
{
    if (def)
    {
        on_off_switch_object_t *obj = get_obj(def);
        AVS_LIST_CLEAR(&obj->instances)
        {
            release_instance(obj->instances);
        }

        // TODO: object cleanup

        avs_free(obj);
    }
}

void change_switch_state(const anjay_dm_object_def_t **def, int iid, bool action)
{
    if (def)
    {
        on_off_switch_object_t *obj = get_obj(def);
        printf("change Switch %d action %s : \n", iid, &obj->instances[iid].switch_state ? "true" : "false");
        if (action)
        {
            obj->instances[iid].switch_state = true;
        }
        else
        {
            obj->instances[iid].switch_state = false;
        }
    }
}

void switch_object_notify(anjay_t *anjay, const anjay_dm_object_def_t **def)
{
    if (!anjay || !def)
    {
        return;
    }
    on_off_switch_object_t *obj = get_obj(def);

    uint64_t current_timestamp;
    if (avs_time_real_to_scalar(&current_timestamp, AVS_TIME_S,
                                avs_time_real_now()))
    {
        return;
    }

    //Type instance et non objet !!!!
    AVS_LIST(on_off_switch_instance_t)
    it;
    AVS_LIST_FOREACH(it, obj->instances)
    {
        if (it->last_notify_timestamp != current_timestamp)
        {
            // On notify que la ressource  RID_DIGITAL_INPUT_STATE a changé
            // NE PAS OUBLIER DE MODIF ID de l'objet !!!!!!!

            printf("On va notifier changement ressource switch\n");

            if (!anjay_notify_changed(anjay, 3342, it->iid, RID_DIGITAL_INPUT_STATE))
            {
                it->last_notify_timestamp = current_timestamp;
            }
        }
    }
}