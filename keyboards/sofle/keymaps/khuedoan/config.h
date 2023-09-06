#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define SPLIT_USB_DETECT
#define MASTER_LEFT

// TODO optimize this
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS

#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_WHEEL_MAX_SPEED 1
