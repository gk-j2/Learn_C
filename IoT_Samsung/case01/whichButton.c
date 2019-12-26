#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"
#include "thread.h"
#include <stdio.h>

#define INTERVAL (2U * US_PER_SEC)
#define BTN1  GPIO_PIN(PORT_A,4)
#define BTN2  GPIO_PIN(PORT_A,5)
#define BTN3  GPIO_PIN(PORT_B,8)
#define BTN4  GPIO_PIN(PORT_B,9)

int btn_pressed;
xtimer_ticks32_t btn_timer;

static void btn_handler(void *arg) {
	int btn_num = (int) arg;
	xtimer_ticks32_t current = xtimer_now ();
	printf("BTN %d | TICK %lu\n",btn_num,current.ticks32);
	if (xtimer_usec_from_ticks(xtimer_diff(current, btn_timer)) > 100000) {
		printf("press %d\n",btn_num);
		btn_timer = current;
		btn_pressed = btn_num;
	} else {
		printf("ignore %d\n",btn_num);
	}

	
}

int main(void) {

    gpio_init_int(BTN1, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 1);
    gpio_init_int(BTN2, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 2);
    gpio_init_int(BTN3, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 3);
    gpio_init_int(BTN4, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 4);
	while (1) {;}
	return (0);
}  
