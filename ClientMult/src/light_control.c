/**
 * Generated by anjay_codegen.py on 2021-02-21 15:52:57
 *
 * LwM2M Object: Light Control
 * ID: 3311, URN: urn:oma:lwm2m:ext:3311, Optional, Multiple
 *
 * This Object is used to control a light source, such as a LED or other
 * light.  It allows a light to be turned on or off and its dimmer
 * setting to be control as a % between 0 and 100. An optional colour
 * setting enables a string to be used to indicate the desired colour.
 */
#include <assert.h>
#include <stdbool.h>

#include <anjay/anjay.h>
#include <avsystem/commons/avs_defs.h>
#include <avsystem/commons/avs_list.h>
#include <avsystem/commons/avs_memory.h>

/**
 * Sensor Units: R, Single, Optional
 * type: string, range: N/A, unit: N/A
 * Measurement Units Definition.
 */
#define RID_SENSOR_UNITS 5701

/**
 * Colour: RW, Single, Optional
 * type: string, range: N/A, unit: N/A
 * A string representing a value in some color space.
 */
#define RID_COLOUR 5706

/**
 * Application Type: RW, Single, Optional
 * type: string, range: N/A, unit: N/A
 * The application type of the sensor or actuator as a string depending
 * on the use case.
 */
#define RID_APPLICATION_TYPE 5750

/**
 * Cumulative active power: R, Single, Optional
 * type: float, range: N/A, unit: Wh
 * The cumulative active power since the last cumulative energy reset or
 * device start.
 */
#define RID_CUMULATIVE_ACTIVE_POWER 5805

/**
 * Power factor: R, Single, Optional
 * type: float, range: N/A, unit: N/A
 * If applicable, the power factor of the current consumption.
 */
#define RID_POWER_FACTOR 5820

/**
 * On/Off: RW, Single, Mandatory
 * type: boolean, range: N/A, unit: N/A
 * On/off control. Boolean value where True is On and False is Off.
 */
#define RID_ON_OFF 5850

/**
 * Dimmer: RW, Single, Optional
 * type: integer, range: 0..100, unit: /100
 * This resource represents a dimmer setting, which has an Integer value
 * between 0 and 100 as a percentage.
 */
#define RID_DIMMER 5851

/**
 * On time: RW, Single, Optional
 * type: integer, range: N/A, unit: s
 * The time in seconds that the device has been on. Writing a value of 0
 * resets the counter.
 */
#define RID_ON_TIME 5852

typedef struct light_control_instance_struct
{
    anjay_iid_t iid;
    char application_type[64];
    bool on_off_state;
    int dimmer;
    char color[64];
    char application_type_backup[64];
    uint64_t last_notify_timestamp;
    // TODO: instance state
} light_control_instance_t;

typedef struct light_control_object_struct
{
    const anjay_dm_object_def_t *def;
    AVS_LIST(light_control_instance_t)
    instances;

    // TODO: object state
} light_control_object_t;

static inline light_control_object_t *
get_obj(const anjay_dm_object_def_t *const *obj_ptr)
{
    assert(obj_ptr);
    return AVS_CONTAINER_OF(obj_ptr, light_control_object_t, def);
}

static light_control_instance_t *find_instance(const light_control_object_t *obj,
                                               anjay_iid_t iid)
{
    AVS_LIST(light_control_instance_t)
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

    AVS_LIST(light_control_instance_t)
    it;
    AVS_LIST_FOREACH(it, get_obj(obj_ptr)->instances)
    {
        anjay_dm_emit(ctx, it->iid);
    }

    return 0;
}

static int init_instance(light_control_instance_t *inst, anjay_iid_t iid)
{
    assert(iid != ANJAY_ID_INVALID);

    inst->iid = iid;
    // TODO: instance init
    inst->application_type[0] = '\0';
    inst->color[0] = '\0';
    inst->dimmer = 0;
    inst->on_off_state = false;

    // TODO: return 0 on success, negative value on failure
    return 0;
}

static void release_instance(light_control_instance_t *inst)
{
    // TODO: instance cleanup
    (void)inst;
}

static light_control_instance_t *
add_instance(light_control_object_t *obj, anjay_iid_t iid)
{
    assert(find_instance(obj, iid) == NULL);

    AVS_LIST(light_control_instance_t)
    created =
        AVS_LIST_NEW_ELEMENT(light_control_instance_t);
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

    AVS_LIST(light_control_instance_t) * ptr;
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
    light_control_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    return add_instance(obj, iid) ? 0 : ANJAY_ERR_INTERNAL;
}

static int instance_remove(anjay_t *anjay,
                           const anjay_dm_object_def_t *const *obj_ptr,
                           anjay_iid_t iid)
{
    (void)anjay;
    light_control_object_t *obj = get_obj(obj_ptr);
    assert(obj);

    AVS_LIST(light_control_instance_t) * it;
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

    light_control_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    light_control_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    // TODO: instance reset
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

    anjay_dm_emit_res(ctx, RID_SENSOR_UNITS,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_COLOUR,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_APPLICATION_TYPE,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_CUMULATIVE_ACTIVE_POWER,
                      ANJAY_DM_RES_R, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_POWER_FACTOR,
                      ANJAY_DM_RES_R, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_ON_OFF,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_DIMMER,
                      ANJAY_DM_RES_RW, ANJAY_DM_RES_PRESENT);
    anjay_dm_emit_res(ctx, RID_ON_TIME,
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

    light_control_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    light_control_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
    case RID_SENSOR_UNITS:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_string(ctx, ""); // TODO

    case RID_COLOUR:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_string(ctx, inst->color); // TODO

    case RID_APPLICATION_TYPE:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_string(ctx, inst->application_type); // TODO

    case RID_CUMULATIVE_ACTIVE_POWER:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_float(ctx, 0); // TODO

    case RID_POWER_FACTOR:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_float(ctx, 0); // TODO

    case RID_ON_OFF:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_bool(ctx, inst->on_off_state); // TODO

    case RID_DIMMER:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i32(ctx, inst->dimmer); // TODO

    case RID_ON_TIME:
        assert(riid == ANJAY_ID_INVALID);
        return anjay_ret_i32(ctx, 0); // TODO

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

    light_control_object_t *obj = get_obj(obj_ptr);
    assert(obj);
    light_control_instance_t *inst = find_instance(obj, iid);
    assert(inst);

    switch (rid)
    {
    case RID_COLOUR:
    {
        assert(riid == ANJAY_ID_INVALID);
        char value[256];                                                // TODO
        return anjay_get_string(ctx, inst->color, sizeof(inst->color)); // TODO
    }

    case RID_APPLICATION_TYPE:
    {
        assert(riid == ANJAY_ID_INVALID);
        char value[256];                                                                      // TODO
        return anjay_get_string(ctx, inst->application_type, sizeof(inst->application_type)); // TODO
    }

    case RID_ON_OFF:
    {
        assert(riid == ANJAY_ID_INVALID);
        bool value;                                      // TODO
        return anjay_get_bool(ctx, &inst->on_off_state); // TODO
    }

    case RID_DIMMER:
    {
        assert(riid == ANJAY_ID_INVALID);
        int32_t value;                                  // TODO
        int result = anjay_get_i32(ctx, &inst->dimmer); // TODO
        printf("Nouvelle value de dimmer light control n° %d : %d \n", iid, inst->dimmer);
        return result;
    }

    case RID_ON_TIME:
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
    .oid = 3311,
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

const anjay_dm_object_def_t **light_control_object_create(void)
{
    light_control_object_t *obj = (light_control_object_t *)avs_calloc(1, sizeof(light_control_object_t));
    if (!obj)
    {
        return NULL;
    }
    obj->def = &OBJ_DEF;

    // TODO: object init
    //ON Crée plusieurs instances !!!!
    light_control_instance_t *inst = add_instance(obj, 0);
    light_control_instance_t *inst1 = add_instance(obj, 1);
    light_control_instance_t *inst2 = add_instance(obj, 2);
    if (inst)
    {
        //On modifie uniquement la première instance !
        strcpy(inst->application_type, "light control");
        inst->dimmer = 1;
        inst->on_off_state = false;
        strcpy(inst->color, "white");
        printf("\n INITTTTT \n");
    }
    else
    {
        avs_free(obj);
        return NULL;
    }

    return &obj->def;
}

void light_control_object_release(const anjay_dm_object_def_t **def)
{
    if (def)
    {
        light_control_object_t *obj = get_obj(def);
        AVS_LIST_CLEAR(&obj->instances)
        {
            release_instance(obj->instances);
        }

        // TODO: object cleanup

        avs_free(obj);
    }
}

void print_LightControl(const anjay_dm_object_def_t **def)
{
    if (def)
    {
        light_control_object_t *obj = get_obj(def);
        printf("color : %s\n", &obj->instances[0].color);
        printf("dimmer : %d\n", obj->instances[0].dimmer);
        printf("On-Off-State : %d\n", obj->instances[0].on_off_state);
    }
}