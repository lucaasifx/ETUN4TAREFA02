#include "pico/stdlib.h"
#include"hardware/pwm.h"
#include "pico/bootrom.h"
#include <stdio.h>
#include <stdlib.h>

// libs
#include "lib/led.h"
#include "lib/buzzer.h"


// ***************** MACROS ***************************

#define NUM_GPIOs 4



// **************** VARIAVEIS GLOBAIS *****************
typedef struct gpios {
    uint8_t used_gpios[NUM_GPIOs];
    bool gpio_state[NUM_GPIOs];
} GPIOS;

// *****************************************************


void display_menu() {
    printf("\033[2J\033[H");
    printf("==============================\n");
    printf(" TAREFA 02 EMBARCATECH \n");
    printf("==============================\n");
    printf("[1] Ligar LED verde (GPIO 11)\n");
    printf("[2] Ligar LED azul (GPIO 12)\n");
    printf("[3] Ligar LED vermelho (GPIO 13)\n");
    printf("[4] Ligar os tres LEDs (luz branca)\n");
    printf("[5] Desligar todos os LEDs\n");
    printf("[6] Acionar o buzzer por 2 segundos\n");
    printf("[7] Entrar no modo BOOTSEL\n");
    printf("==============================\n");
    puts("");
}

void disable_all_gpios_except(uint8_t *gpios, uint8_t exception) {
    for(int i = 0; i < NUM_GPIOs; i++) {
        if(gpios[i] != exception)
            gpio_put(gpios[i], false);
    }
}

int main() {
    stdio_init_all();
    int opc;
    
    // inicializa os leds
    init_led(LED_GREEN);
    init_led(LED_BLUE);
    init_led(LED_RED);

    //inicializa o buzzer
    init_buzzer(BUZZER01);

    GPIOS gpios_task;
    gpios_task.used_gpios[0] = LED_GREEN;
    gpios_task.used_gpios[1] = LED_BLUE;
    gpios_task.used_gpios[2] = LED_RED;
    gpios_task.used_gpios[3] = BUZZER01;

    getchar();
    while(true) {
        display_menu();
        while (true) {
            printf("Escolha uma opção: ");
            scanf("%d", &opc);
            if(opc >= 1 && opc <= 7)
                break;
            puts("");
        }
        switch (opc) {
            // exemplo
            case 1:
                turn_led_on(LED_GREEN);
                disable_all_gpios_except(gpios_task.used_gpios, LED_GREEN);
                break;
            case 2:
                
                break;
            case 3:
                turn_led_on(LED_RED);
                disable_all_gpios_except(gpios_task.used_gpios, LED_RED);
                break;
            case 4:
                turn_led_on(LED_RED);
                turn_led_on(LED_GREEN);
                turn_led_on(LED_BLUE);
                break;
            case 5:

                break;
            case 6:                
                turn_led_off(LED_RED);
                turn_led_off(LED_GREEN);
                turn_led_off(LED_BLUE);
                beep(BUZZER01, 2000);
                break;
            case 7:
                reset_usb_boot(0, 0);
                break;
            default:
                break;
        }
        
    }
    return 0;
}
