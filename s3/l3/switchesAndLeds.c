#include "ripes_system.h"
/* Switches and LEDs
 * This program will toggle an LED in an LED matrix when the corresponding
 * switch is toggled.
 *
 * To run this program, make sure that you have instantiated one of
 each of the
 * following peripherals in the I/O tab:
 * - "LED Matrix"
 * - "Switches"
 */
unsigned* led_base = (unsigned *) LED_MATRIX_0_BASE;
#define W LED_MATRIX_0_WIDTH
unsigned* switch_base = (unsigned *) SWITCHES_0_BASE;

int switch_translated_at(int idx)
{
    return (*switch_base >> (SWITCHES_0_N - idx - 1)) & 0x1;
}

int main() {
    for (int i = 0; i < SWITCHES_0_N; i++) {
        unsigned color = 0x0;
        if (switch_translated_at(i))
            color = 0xFF << (((SWITCHES_0_N - i + 1) % 3) * 8);
        led_base[i + W] = led_base[i + W*2] = led_base[i] = color;
    }
    return 0;
}