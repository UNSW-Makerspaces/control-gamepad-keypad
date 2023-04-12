#include "usb_descriptors.h"

const tusb_desc_device_t device_descriptor = {
    .bLength = sizeof(tusb_desc_device_t),
    .bDescriptorType = TUSB_DESC_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = 0,
    .bDeviceSubClass = 0,
    .bDeviceProtocol = 0,
    .bMaxPacketSize0 = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor = 0xCafe,
    .idProduct = 0x0001,
    .bcdDevice = 0x0100,
    .iManufacturer = 1,
    .iProduct = 2,
    .iSerialNumber = 0,
    .bNumConfigurations = 1
};

// HID Report Descriptor for keyboard
uint8_t const desc_hid_report_keyboard[] = {
    // Add HID report descriptor for keyboard
    // You can find a standard keyboard HID report descriptor using USB.org's HID Descriptor Tool
};

// HID Report Descriptor for mouse
uint8_t const desc_hid_report_mouse[] = {
    // Add HID report descriptor for mouse
    // You can find a standard mouse HID report descriptor using USB.org's HID Descriptor Tool
};

// Configuration Descriptor
uint8_t const configuration_descriptor[] = {
    // Add configuration descriptor, interface descriptors (for keyboard and mouse), HID descriptors, and endpoint descriptors
    // Make sure to include both desc_hid_report_keyboard and desc_hid_report_mouse
};

// String Descriptor
char const *string_descriptor_arr[] = {
    (const char[]) {0x09, 0x04},// supported language is English (0x0409)
    "micl.dev",                 // Manufacturer
    "laser_controlpad",         // Product
};

// Invoked when received GET HID REPORT DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const *tud_hid_descriptor_report_cb(uint8_t itf)
{
    if (itf == 0) // Interface 0 is the keyboard
    {
        return desc_hid_report_keyboard;
    }
    else if (itf == 1) // Interface 1 is the mouse
    {
        return desc_hid_report_mouse;
    }

    return NULL;
}




