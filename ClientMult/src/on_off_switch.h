#ifndef SWITCH_OBJECT_H
#define SWITCH_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **on_off_switch_object_create(void);
void on_off_switch_object_release(const anjay_dm_object_def_t **def);
void switch_object_notify(anjay_t *anjay, const anjay_dm_object_def_t **def);
void change_switch_state(const anjay_dm_object_def_t **def, int iid, bool action);

#endif
