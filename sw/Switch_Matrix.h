#ifndef __SWITCH_MATRIX__
#define __SWITCH_MATRIX__

#include "usblib/usbhid.h"
#include <stdint.h>

#define WINDOWS_KEY 0x65
#define PAUSE 0xE8
#define DELETE 0x4C
#define HOME 0x4A
#define END 0x4D
#define INSERT 0x49
#define MUTE 0xEF
#define PREV 0xEA
#define NEXT 0xEB
#define CALC 0xFB
#define VOL_UP 0xED
#define VOL_DN 0xEE
void Switch_Init(void);
void Switch_Stop(void);
void Switch_Start(void);

extern uint8_t KeyboardMatrix[2][5][14]; 

#endif