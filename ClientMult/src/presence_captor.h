#ifndef PRESENCE_OBJECT_H
#define PRESENCE_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **presence_object_create(void);
void presence_object_release(const anjay_dm_object_def_t **def);

#endif