#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"
#include "thread.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "irq.h"

#define INTERVAL (2U * US_PER_SEC)
#define BTN1  GPIO_PIN(PORT_A,4)
#define BTN2  GPIO_PIN(PORT_A,5)
#define BTN3  GPIO_PIN(PORT_B,8)
#define BTN4  GPIO_PIN(PORT_B,9)
#define LED1 GPIO_PIN(PORT_B,0)
static gpio_t BUTTONS[] = {BTN1, BTN1, BTN2, BTN3, BTN4};

int passwd[] = {1,1,1,1};
int but_passwd[] = {0,0,0,0};

int btn_pressed;
xtimer_ticks32_t btn_timer;

void add(int btn_num, int *but_passwd) {
	but_passwd[3] = but_passwd[2];
	but_passwd[2] = but_passwd[1];
	but_passwd[1] = but_passwd[0];
	but_passwd[0] = btn_num;
}

int is_passwd(int *but_passwd, int *passwd) {
	int i = 0;
	while (but_passwd[3-i] == passwd[i] && i < 4)
		i++;
	if (i == 4) {
		for (int j = 0; j < 4; j++) {
			but_passwd[j] = 0;
		}
		printf("passwd is Ok\n");
		return 1;
	}
	else return 0;
}

static void btn_handler(void *arg) {
	int btn_num = (int) arg;
	gpio_irq_disable(BUTTONS[btn_num]);
	xtimer_ticks32_t current = xtimer_now ();	
	if (xtimer_usec_from_ticks(xtimer_diff(current, btn_timer)) > 3000000) {
		printf("BTN %d | TICK %lu\n",btn_num,current.ticks32);
		add(btn_num, but_passwd);
		printf("BTN_PASSWD | [%d]--[%d]--[%d]--[%d]\n", but_passwd[0], but_passwd[1], but_passwd[2], but_passwd[3]);
		if (is_passwd(passwd, but_passwd)) {
			xtimer_ticks32_t last_wakeup = xtimer_now();
			gpio_toggle(LED1);
			xtimer_periodic_wakeup(&last_wakeup, 10U * US_PER_SEC);
			gpio_toggle(LED1);
		}
		btn_timer = current;
		btn_pressed = btn_num;
	} else {
		printf("IGN %d | TICK %lu\n",btn_num,current.ticks32);
	}
	gpio_irq_enable(BUTTONS[btn_num]);
}

int main(void) {
	gpio_init(LED1, GPIO_OUT);
	gpio_clear(LED1);
    gpio_init_int(BTN1, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 1);
    gpio_init_int(BTN2, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 2);
    gpio_init_int(BTN3, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 3);
    gpio_init_int(BTN4, GPIO_IN_PU, GPIO_FALLING, btn_handler, (void *) 4);
	while (1) {;}
	return (0);
}  
