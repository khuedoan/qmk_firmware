#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define SPLIT_USB_DETECT
#define MASTER_LEFT

// TODO optimize this
#undef TAPPING_TERM
#define TAPPING_TERM 500
#define HOLD_ON_OTHER_KEY_PRESS
