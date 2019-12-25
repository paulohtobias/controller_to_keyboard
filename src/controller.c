#include "controller.h"

Controller new_Controller(){
    
    SDL_Init(SDL_INIT_JOYSTICK);
    
    Controller controller;
    
    SDL_Joystick *controle1 = SDL_JoystickOpen(0);
    if(controle1 == NULL){
        printf(SDL_GetError());
        exit(1);
    }
    controller.name = SDL_JoystickName(controle1);
    controller.total_buttons = SDL_JoystickNumButtons(controle1);
    SDL_JoystickClose(controle1);
    
    controller.mapping = malloc(12 + controller.total_buttons);
    
    controller.LX = 0;
    controller.LY = 0;
    controller.LD = default_deadzone;
    controller.RX = 0;
    controller.RY = 0;
    controller.RD = default_deadzone;
    controller.TL = 0;
    controller.TR = 0;
    controller.POV = POV_CENTER;
    controller.buttons_pressed = 0;
    
    return controller;
}

void controller_get_input(Controller *controller){
    JOYINFOEX joy;
    joy.dwSize = sizeof(JOYINFOEX);
    joy.dwFlags = JOY_RETURNALL;
    MMRESULT result = joyGetPosEx(JOYSTICKID1, &joy);
    
    if(result == JOYERR_NOERROR){
        controller->LX = joy.dwXpos;
        controller->LY = joy.dwYpos;
        controller->RX = joy.dwZpos;
        controller->RY = joy.dwRpos;
        controller->TL = joy.dwUpos;
        controller->TR = joy.dwVpos;
        
        int i;
        for(i=0; i<4; i++){
            if(controller->POV != POV_CENTER){
                if(joy.dwPOV == 65500){
                    //direcional i foi levantado
                    release_key(controller->mapping[i]);
                }
            }
        }
        controller->POV = 1 << (joy.dwPOV/9000);
        
        for(i=0; i<controller->total_buttons; i++){
            if(controller->buttons_pressed & (1 << 1)){
                if((joy.dwButtons & (1 << 1) == 0)){
                    //botão i foi levantado
                    release_key(controller->mapping[12 + i]);
                }
            }
        }
        controller->buttons_pressed = joy.dwButtons;
    }else{
        printf("ERROR: controller_get_input\n");
        exit(1);
    }
}

void controller_to_keyboard(Controller controller){
    //direcional
    if(controller.POV & POV_UP){
        press_key(controller.mapping[MAP_POV_UP]);
    }
    if(controller.POV & POV_RIGHT){
        press_key(controller.mapping[MAP_POV_RIGHT]);
    }
    if(controller.POV & POV_DOWN){
        press_key(controller.mapping[MAP_POV_DOWN]);
    }
    if(controller.POV & POV_LEFT){
        press_key(controller.mapping[MAP_POV_LEFT]);
    }
    
    //analogico esquerdo
    if(controller.LY < -controller.LD){
        //press_key(controller.mapping[MAP_LS_UP]);
    }
    if(controller.LX > controller.LD){
        //press_key(controller.mapping[MAP_LS_RIGHT]);
    }
    if(controller.LY > controller.LD){
        //press_key(controller.mapping[MAP_LS_DOWN]);
    }
    if(controller.LX < -controller.LD){
        //press_key(controller.mapping[MAP_LS_LEFT]);
    }
    
    //analogico direito
    if(controller.RY < -controller.RD){
        //press_key(controller.mapping[MAP_RS_UP]);
    }
    if(controller.RX > controller.RD){
        //press_key(controller.mapping[MAP_RS_RIGHT]);
    }
    if(controller.RY > controller.RD){
        //press_key(controller.mapping[MAP_RS_DOWN]);
    }
    if(controller.RX < -controller.RD){
        //press_key(controller.mapping[MAP_RS_LEFT]);
    }
    
    int i;
    for(i=0; i<controller.total_buttons; i++){
        if(controller.buttons_pressed & (1 << i)){
            int j;
            for(j=0; j<controller.total_buttons; j++){
                release_key(controller.mapping[12 + j]);
            }
            press_key(controller.mapping[12 + i]);
        }
    }
}