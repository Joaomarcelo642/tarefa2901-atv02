#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED1 11
#define LED2 12
#define LED3 13
#define BUTTON 5

volatile bool sequence_running = false;
int estado = 0;

// Callback para gerenciar a sequência de desligamento dos LEDs
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    switch (estado) {
        case 0:
            gpio_put(LED1, 0);
            break;
        case 1:
            gpio_put(LED2, 0);
            break;
        case 2:
            gpio_put(LED3, 0);
            sequence_running = false; // Permite nova ativação
            return 0;
    }
    estado++;
    add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    return 0;
}

void button_callback(uint gpio, uint32_t events) {
    if (!sequence_running) {
        sequence_running = true;
        estado = 0;
        gpio_put(LED1, 1);
        gpio_put(LED2, 1);
        gpio_put(LED3, 1);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED1);
    gpio_init(LED2);
    gpio_init(LED3);
    gpio_set_dir(LED1, GPIO_OUT);
    gpio_set_dir(LED2, GPIO_OUT);
    gpio_set_dir(LED3, GPIO_OUT);
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &button_callback);
    gpio_set_irq_callback(button_callback);
    irq_set_enabled(IO_IRQ_BANK0, true);
    
    while (1) {
        tight_loop_contents();
    }
}
