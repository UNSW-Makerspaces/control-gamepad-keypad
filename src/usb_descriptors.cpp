// Author: Michael W. Lloyd <micl_dev@protonmail.com>
// 
// Last Modified: 13/04/23

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

uint8_t const desc_hid_report_keyboard[] = {
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x06, // USAGE (Keyboard)
                // Descriptor for keyboard
    0xa1, 0x01, // COLLECTION (Application)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)
    0x19, 0xe0, //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7, //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x01, //   LOGICAL_MAXIMUM (1)
    0x75, 0x01, //   REPORT_SIZE (1)
    0x95, 0x08, //   REPORT_COUNT (8)
    0x81, 0x02, //   INPUT (Data,Var,Abs)
    0x95, 0x01, //   REPORT_COUNT (1)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x81, 0x03, //   INPUT (Cnst,Var,Abs)
    0x95, 0x05, //   REPORT_COUNT (5)
    0x75, 0x01, //   REPORT_SIZE (1)
    0x05, 0x08, //   USAGE_PAGE (LEDs)
    0x19, 0x01, //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05, //   USAGE_MAXIMUM (Kana)
    0x91, 0x02, //   OUTPUT (Data,Var,Abs)
    0x95, 0x01, //   REPORT_COUNT (1)
    0x75, 0x03, //   REPORT_SIZE (3)
    0x91, 0x03, //   OUTPUT (Cnst,Var,Abs)
    0x95, 0x06, //   REPORT_COUNT (6)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x65, //   LOGICAL_MAXIMUM (101)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)
    0x19, 0x00, //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65, //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00, //   INPUT (Data,Ary,Abs)
    0xc0        // END_COLLECTION
};



// Descriptor for mouse
uint8_t const desc_hid_report_mouse[] = {
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x02, // USAGE (Mouse)
    0xa1, 0x01, // COLLECTION (Application)
    0x09, 0x01, //   USAGE (Pointer)
    0xA1, 0x00, //   COLLECTION (Physical)
    0x05, 0x09, //     USAGE_PAGE (Button)
    0x19, 0x01, //     USAGE_MINIMUM (Button 1)
    0x29, 0x03, //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00, //     LOGICAL_MINIMUM (0)
    0x25, 0x01, //     LOGICAL_MAXIMUM (1)
    0x95, 0x03, //     REPORT_COUNT (3)
    0x75, 0x01, //     REPORT_SIZE (1)
    0x81, 0x02, //     INPUT (Data,Var,Abs)
    0x95, 0x01, //     REPORT_COUNT (1)
    0x75, 0x05, //     REPORT_SIZE (5)
    0x81, 0x03, //     INPUT (Cnst,Var,Abs)
    0x05, 0x01, //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30, //     USAGE (X)
    0x09, 0x31, //     USAGE (Y)
    0x15, 0x81, //     LOGICAL_MINIMUM (-127)
    0x25, 0x7F, //     LOGICAL_MAXIMUM (127)
    0x75, 0x08, //     REPORT_SIZE (8)
    0x95, 0x02, //     REPORT_COUNT (2)
    0x81, 0x06, //     INPUT (Data,Var,Rel)
    0xC0,       //   END_COLLECTION
    0xC0          // END_COLLECTION
};

uint8_t const configuration_descriptor[] = {
    // Configuration Descriptor
    0x09,                               // bLength
    TUSB_DESC_CONFIGURATION,            // bDescriptorType
    0x59, 0x00,                         // wTotalLength (89 bytes)
    0x02,                               // bNumInterfaces (2 interfaces)
    0x01,                               // bConfigurationValue
    0x00,                               // iConfiguration
    TUSB_DESC_CONFIG_ATT_BUS_POWER,     // bmAttributes (bus-powered)
    40,                                 // bMaxPower (80mA)

    // Interface Descriptor (Keyboard)
    0x09,                               // bLength
    TUSB_DESC_INTERFACE,                // bDescriptorType
    0x00,                               // bInterfaceNumber
    0x00,                               // bAlternateSetting
    0x01,                               // bNumEndpoints
    TUSB_CLASS_HID,                     // bInterfaceClass (HID)
    0x01,                               // bInterfaceSubClass (Boot)
    0x01,                               // bInterfaceProtocol (Keyboard)
    0x00,                               // iInterface

    // HID Descriptor (Keyboard)
    0x09,                               // bLength
    TUSB_DESC_HID,                      // bDescriptorType
    0x11, 0x01,                         // bcdHID (HID 1.11)
    0x00,                               // bCountryCode
    0x01,                               // bNumDescriptors
    TUSB_DESC_REPORT,                   // bDescriptorType
    sizeof(desc_hid_report_keyboard),   // wDescriptorLength

    // Endpoint Descriptor (Keyboard)
    0x07,                               // bLength
    TUSB_DESC_ENDPOINT,                 // bDescriptorType
    0x81,                               // bEndpointAddress (IN1)
    TUSB_XFER_INTERRUPT,                // bmAttributes (Interrupt)
    0x08, 0x00,                         // wMaxPacketSize (8 bytes)
    0x0A,                               // bInterval (10 ms)

    // Interface Descriptor (Mouse)
    0x09,                               // bLength
    TUSB_DESC_INTERFACE,                // bDescriptorType
    0x01,                               // bInterfaceNumber
    0x00,                               // bAlternateSetting
    0x01,                               // bNumEndpoints
    TUSB_CLASS_HID,                     // bInterfaceClass (HID)
    0x01,                               // bInterfaceSubClass (Boot)
    0x02,                               // bInterfaceProtocol (Mouse)
    0x00,                               // iInterface

    // HID Descriptor (Mouse)
    0x09,                               // bLength
    TUSB_DESC_HID,                      // bDescriptorType
    0x11, 0x01,                         // bcdHID (HID 1.11)
    0x00,                               // bCountryCode
    0x01,                               // bNumDescriptors
    TUSB_DESC_REPORT,                   // bDescriptorType
    sizeof(desc_hid_report_mouse),      // wDescriptorLength

    // Endpoint Descriptor (Mouse)
    0x07,                               // bLength
    TUSB_DESC_ENDPOINT,                 // bDescriptorType
                                        // Endpoint Descriptor (Mouse)
    0x07,                               // bLength
    TUSB_DESC_ENDPOINT,                 // bDescriptorType
    0x82,                               // bEndpointAddress (IN2)
    TUSB_XFER_INTERRUPT,                // bmAttributes (Interrupt)
    0x08, 0x00,                         // wMaxPacketSize (8 bytes)
    0x0A,                               // bInterval (10 ms)
};

// String Descriptor
char const *string_descriptor_arr[] = {
    (const char[]) {0x09, 0x04},// supported language is English (0x0409)
    "micl.dev",                 // Manufacturer
    "laser_controlpad",         // Product
};

// Invoked when received GET HID REPORT DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const *tud_hid_descriptor_report_cb(uint8_t itf) {

    // Interface 0 is the keyboard
    if (itf == 0) {
        return desc_hid_report_keyboard;
    } // Interface 1 is the mouse
    else if (itf == 1) {
        return desc_hid_report_mouse;
    }

    return NULL;
}
