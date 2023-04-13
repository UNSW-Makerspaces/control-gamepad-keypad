// Author: Michael W. Lloyd <micl_dev@protonmail.com>
// 
// Last Modified: 13/04/23

#include <stdio.h>
#include <cmath>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "tusb.h"
#include "usb_descriptors.h" 
#include "pico/stdlib.h"
#include "PicoLED.h"

#define LED_PIN 17
#define LED_LENGTH 1

enum LedColor { LED_RED, LED_GREEN, LED_BLUE, LED_WHITE };
void update_led(PicoLED led, LedColor col); 

int main() {

    tusb_init();

    // 0. Initialize LED strip
    printf("0. Initialize LED strip");
    PicoLED led(
        LED_PIN,            // Data line is connected to pin 0. (GP0)
        LED_LENGTH,         // Strip is 6 LEDs long.
        pio0,               // Use PIO 0 for creating the state machine.
        0,                  // Index of the state machine that will be created for controlling the LED strip
                            // You can have 4 state machines per PIO-Block up to 8 overall.
                            // See Chapter 3 in: https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf
        PicoLED::FORMAT_GRB  // Pixel format used by the LED strip
    );


    while (true) {
        update_led(led, LED_WHITE)
        // Main loop
        sleep_ms(50);
    }


    return 0;
}


void update_led(PicoLED led, LedColor col) { 

    // FIXME: Use input color
    if(col == LED_RED) { 
        // uwu 
    } 

    // Pick a random color
    uint32_t color = (uint32_t)rand();
    // Pick a random direction
    int8_t dir = (rand() & 1 ? 1 : -1);
    // Setup start and end offsets for the loop
    uint8_t start = (dir > 0 ? 0 : LED_LENGTH);
    uint8_t end = (dir > 0 ? LED_LENGTH : 0);
    for (uint8_t led = start; led != end; led += dir) {
        led.setPixelColor(led, color);
        led.show();
        sleep_ms(50);
    }

    return; 
}
