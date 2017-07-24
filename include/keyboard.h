/* 
 * File:   keyboard.h
 * Author: paulo
 *
 * Created on 24 de Julho de 2017, 11:04
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define WINVER 0x0500
#include <windows.h>
#include <stdio.h>

void press_key(WORD key);

void release_key(WORD key);

#endif //KEYBOARD_H

