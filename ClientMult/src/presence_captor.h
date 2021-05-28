#ifndef PRESENCE_OBJECT_H
#define PRESENCE_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **presence_object_create(void);
void make_detection(const anjay_dm_object_def_t **def, int iid);
void presence_object_release(const anjay_dm_object_def_t **def);
void presence_object_notify(anjay_t *anjay, const anjay_dm_object_def_t **def);

#endif