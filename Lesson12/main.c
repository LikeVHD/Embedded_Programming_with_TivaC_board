#include <stdint.h>
#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

struct Point {
    

};
int main() {

    SYSCTL_RCGCGPIO_R |= (1U << 5);  /* enable clock for GPIOF */
    SYSCTL_GPIOHBCTL_R |= (1U << 5); /* enable AHB for GPIOF */
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);

    /* turn all LEDs off */
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED | LED_BLUE | LED_GREEN] = 0U;
}

////////////////////////////////////////////////////////////////
// NOTE: the file main_fact.c in the project directory contains
// the code that corrupted the stack as explained in the
// Lesson10 video.