// Author: Michael W. Lloyd <micl_dev@protonmail.com>
// 
// Last Modified: 13/04/23

#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H

#include "tusb.h"

// Device descriptor
extern const tusb_desc_device_t usb_device_descriptor;

// HID Report Descriptor for keyboard
extern const uint8_t desc_hid_report_keyboard[];

// HID Report Descriptor for mouse
extern const uint8_t desc_hid_report_mouse[];

// Configuration descriptor
extern uint8_t const usb_configuration_descriptor[];

// Function to get the descriptor for the specified index
uint8_t const *tud_descriptor_configuration_cb(uint8_t index);

#endif // USB_DESCRIPTORS_H



