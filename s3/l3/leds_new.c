#include <assert.h>
#include "ripes_system.h"
/* LEDs
 * This program draws on an LED matrix peripheral.
 *
 * To run this program, make sure that you have instantiated an "LED
 Matrix"
 * peripheral in the "I/O" tab.
 */
#define W LED_MATRIX_0_WIDTH
#define H LED_MATRIX_0_HEIGHT
unsigned* led_base = (unsigned *) LED_MATRIX_0_BASE;

#define BACKGROUND_COLOR 0x00ffff
#define FOREGROUND_COLOR 0xff00ff

const static unsigned char bitmap[] = {
    0b0111110,
    0b0000010,
    0b0000100,
    0b0001000,
    0b0001000,
};

static_assert(sizeof bitmap/sizeof *bitmap == LED_MATRIX_0_HEIGHT, "");

void main() {    
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            unsigned color = bitmap[y]&(1<<(W-x-1)) 
                 ? FOREGROUND_COLOR 
                 : BACKGROUND_COLOR;
            unsigned idx = y * W + x;
            led_base[idx] = color;
        }
    }
}