/**
 * Controller to Keyboard
 *
 * keyboard.h
 *
 * Paulo Tobias
 * paulohtobias@outlook.com
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define WINVER 0x0500
#include <windows.h>

/**
 * Presses `key`.
 *
 * NOTE: key stays pressed unitl `ctk_keyboard_release_key(key)` is called.
 *
 * Params:
 *     @key: virtual-key code as seen on https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
 *
 * Return:
 *
 */
UINT ctk_keyboard_press_keys(const WORD *keys, int keys_len);

/**
 * Releases `key`.
 *
 * Params:
 *     @key: virtual-key code as seen on https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
 *
 * Return:
 *
 */
UINT ctk_keyboard_release_keys(const WORD *keys, int keys_len);

#endif /* KEYBOARD_H */
