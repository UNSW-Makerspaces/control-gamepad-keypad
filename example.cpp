#include <stdio.h>
int main()
{
    stdio_init_all();

    // 0. Initialize LED strip
    printf("0. Initialize LED strip");
    WS2812 ledStrip(
            LED_PIN,            // Data line is connected to pin 0. (GP0)
            LED_LENGTH,         // Strip is 6 LEDs long.
            pio0,               // Use PIO 0 for creating the state machine.
            0,                  // Index of the state machine that will be created for controlling the LED strip
                                // You can have 4 state machines per PIO-Block up to 8 overall.
                                // See Chapter 3 in: https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf
            WS2812::FORMAT_GRB  // Pixel format used by the LED strip
            );



    return 0;
}

 
