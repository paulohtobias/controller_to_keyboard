/* 
 * File:   main.exe.c
 * Author: paulo
 *
 * Created on 24 de Julho de 2017, 08:14
 */

#include "controller.h"


int main(int argc, char *argv[]){
    /*
     * identifica controle 1
     * 
     * procura no arquivo (error checking...)
     * 
     * mapeia
     */
    
    Controller c1 = new_Controller();
    
    //mapeando algumas teclas
    c1.mapping[MAP_BUTTON_5] = 'W';
    c1.mapping[MAP_BUTTON_6] = 'D';
    c1.mapping[MAP_BUTTON_7] = 'S';
    c1.mapping[MAP_BUTTON_8] = 'A';
    c1.mapping[MAP_BUTTON_2] = 'O';
    
    while(1){
        controller_get_input(&c1);
        controller_to_keyboard(c1);
    }
    
    return 0;
}

