#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"
#define INTERVAL (1U * US_PER_SEC)
#define LED1 GPIO_PIN(PORT_C,8)

static void btn_handler(void *arg) {
	(void)arg;
}

int main(void) {
	gpio_init(LED1, GPIO_OUT);
	gpio_clear(LED1);

	xtimer_ticks32_t last_wakeup = xtimer_now();
	
	while(1) {
		xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
		gpio_toggle(LED1);
		gpio_init_int(LED1, GPIO_IN_PU, GPIO_FALLING, btn_handler, NULL);
	}
}
