#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

// Configure TinyUSB stack
#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE)
#define CFG_TUSB_OS                 (OPT_OS_NONE)
#define CFG_TUSB_MEM_ALIGN          __attribute__((aligned(4)))
#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_DEBUG              0

// HID settings
#define CFG_TUD_HID                 1
#define CFG_TUD_HID_KEYBOARD        1
#define CFG_TUD_HID_MOUSE           1

#endif // _TUSB_CONFIG_H_
