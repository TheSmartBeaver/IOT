#ifndef LIGHT_CONTROL_OBJECT_H
#define LIGHT_CONTROL_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **light_control_object_create(void);
void print_LightControl(const anjay_dm_object_def_t **def);
void light_control_object_release(const anjay_dm_object_def_t **def);

#endif
