#ifndef TIME_OBJECT_H
#define TIME_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **on_off_switch_object_create(void);
void on_off_switch_object_release(const anjay_dm_object_def_t **def);

#endif
