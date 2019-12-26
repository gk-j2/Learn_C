#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

#define INTERVAL (1U * US_PER_SEC)
#define LED1 GPIO_PIN(PORT_C,8)
#define LED2 GPIO_PIN(PORT_C,9)
#define BTN  GPIO_PIN(PORT_A,0)

static void btn_handler(void *arg) {
	(void)arg;
	gpio_toggle(LED1);
}

int main(void) {
	gpio_init(LED1, GPIO_OUT);
    gpio_init(LED2, GPIO_OUT);
	gpio_init_int(BTN, GPIO_IN, GPIO_BOTH, btn_handler, NULL);
	gpio_clear(LED2);
    gpio_clear(LED1);
 
    xtimer_ticks32_t last_wakeup = xtimer_now();
 
    while(1) {
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        gpio_toggle(LED2);
    }
}  
