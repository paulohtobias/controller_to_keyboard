/**
 * Controller to Keyboard
 *
 * keyboard.c
 *
 * Paulo Tobias
 * paulohtobias@outlook.com
 */

#define WINVER 0x0500
#include <windows.h>
#include "keyboard.h"

UINT ctk_keyboard_press_keys(const WORD *keys, int keys_len) {
    INPUT ip[keys_len];

	for (int i = 0; i < keys_len; i++) {
		ip[i].type = INPUT_KEYBOARD;
		ip[i].ki.wVk = keys[i];
		ip[i].ki.wScan = keys[i];
		ip[i].ki.dwFlags = 0;
		ip[i].ki.time = 0;
		ip[i].ki.dwExtraInfo = 0;
	}

    return SendInput(keys_len, ip, sizeof *ip);
}

UINT ctk_keyboard_release_keys(const WORD *keys, int keys_len) {
    INPUT ip[keys_len];

	for (int i = 0; i < keys_len; i++) {
		ip[i].type = INPUT_KEYBOARD;
		ip[i].ki.wVk = keys[i];
		ip[i].ki.wScan = keys[i];
		ip[i].ki.dwFlags = KEYEVENTF_KEYUP;
		ip[i].ki.time = 0;
		ip[i].ki.dwExtraInfo = 0;
	}

    return SendInput(keys_len, ip, sizeof *ip);
}
