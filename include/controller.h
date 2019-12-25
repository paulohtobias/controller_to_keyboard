/* 
 * File:   controller.h
 * Author: paulo
 *
 * Created on 24 de Julho de 2017, 08:20
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include "keyboard.h"

#define default_deadzone 8000

typedef enum{
    POV_UP = 1,
    POV_RIGHT = 2,
    POV_DOWN = 4,
    POV_LEFT = 8,
    POV_CENTER = 128
}POV_CODE;

typedef enum{
    //direcional
    MAP_POV_UP,
    MAP_POV_RIGHT,
    MAP_POV_DOWN,
    MAP_POV_LEFT,
    
    //analogico esquerdo
    MAP_LS_UP,
    MAP_LS_RIGHT,
    MAP_LS_DOWN,
    MAP_LS_LEFT,
    
    //analogico direito
    MAP_RS_UP,
    MAP_RS_RIGHT,
    MAP_RS_DOWN,
    MAP_RS_LEFT,
    
    //botoes
    MAP_BUTTON_1,
    MAP_BUTTON_2,
    MAP_BUTTON_3,
    MAP_BUTTON_4,
    MAP_BUTTON_5,
    MAP_BUTTON_6,
    MAP_BUTTON_7,
    MAP_BUTTON_8,
    MAP_BUTTON_9,
    MAP_BUTTON_10,
    MAP_BUTTON_11,
    MAP_BUTTON_12,
    MAP_BUTTON_13,
    MAP_BUTTON_14,
    MAP_BUTTON_15,
    MAP_BUTTON_16,
    MAP_BUTTON_17,
    MAP_BUTTON_18,
    MAP_BUTTON_19,
    MAP_BUTTON_20,
    MAP_BUTTON_21,
    MAP_BUTTON_22,
    MAP_BUTTON_23,
    MAP_BUTTON_24,
    MAP_BUTTON_25,
    MAP_BUTTON_26,
    MAP_BUTTON_27,
    MAP_BUTTON_28,
    MAP_BUTTON_29,
    MAP_BUTTON_30,
    MAP_BUTTON_31,
    MAP_BUTTON_32
}CONTROLLER_MAP;

typedef struct Controller_{
    const char *name;
    
    //direcional
    int POV;
    
    //analogico esquerdo
    short LX; //eixo x
    short LY; //eixo y
    int LD; //deadzone
    
    //analogico direito
    short RX; //eixo x
    short RY; //eixo y
    int RD; //deadzone
    
    //gatilhos
    int TL;
    int TR;
    
    //botoes
    int total_buttons;
    int buttons_pressed;
    
    //mapeamento pro teclado
    char *mapping;
}Controller;

Controller new_Controller();

void update_axis(short *old, DWORD new, char key);

void controller_get_input(Controller *controller);

void controller_to_keyboard(Controller controller);

#endif //CONTROLLER_H

