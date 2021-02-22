#ifndef DIMMER_OBJECT_H
#define DIMMER_OBJECT_H

#include <anjay/dm.h>

const anjay_dm_object_def_t **dimmer_object_create(void);
void dimmer_object_release(const anjay_dm_object_def_t **def);

#endif
