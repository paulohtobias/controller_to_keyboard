#include "keyboard.h"

void press_key(WORD key){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key;
    ip.ki.wScan = key;
    ip.ki.dwFlags = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

void release_key(WORD key){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key;
    ip.ki.wScan = key;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    SendInput(1, &ip, sizeof(INPUT));
}