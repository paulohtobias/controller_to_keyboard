/**
 * Controller to Keyboard
 *
 * main.c
 *
 * Paulo Tobias
 * paulohtobias@outlook.com
 */

#include <stdio.h>
#include <string.h>
#include "keyboard.h"
#include <strsafe.h>

int main(int argc, char *argv[]){
    WORD key;
	UINT retval;

	while (1) {
		printf("Key: ");
		scanf("%hx", &key);

		if (key == 0) {
			break;
		}

		retval = ctk_keyboard_press_keys(&key, 1);
		printf("retval: %d\n", retval);
		if (retval != 1) {
			return 1;
		}

		retval = ctk_keyboard_release_keys(&key, 1);
		printf("retval: %d\n", retval);
		if (retval != 1) {
			return 1;
		}

	}

    return 0;
}
