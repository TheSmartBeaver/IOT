#ifndef TIME_OBJECT_H
#define TIME_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **light_control_object_create(void);
void light_control_object_release(const anjay_dm_object_def_t **def);

#endif
