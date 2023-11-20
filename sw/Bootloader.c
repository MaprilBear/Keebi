#include "./inc/Timer0A.h"
#include "Helpers.h"
#include "inc/CortexM.h"
#include "inc/tm4c123gh6pm.h"

// Apps
#include "Keyboard.h"
#include "App_BongoCat.h"

enum Apps{
    KEYBOARD, BONGO_CAT
} typedef Apps;

#define MAX_APPS 8

//***************************************************************************
//
//                              Event Handlers!
//
//***************************************************************************

uint8_t tickArraySize = 0;
void(*tickArray[8])(void);

// Main logic for each app
void AppTick(){
    for (int i = 0; i < tickArraySize; i++){
        tickArray[i]();
    }
}

uint8_t pressArraySize = 0;
void(*pressArray[8])(uint8_t);

void App_KeyPress(uint8_t usageCode){
    for (int i = 0; i < pressArraySize; i++) {
        (pressArray[i])(usageCode);
    }
}

int8_t releaseArraySize = 0;
void(*releaseArray[8])(uint8_t);

void App_KeyRelease(uint8_t usageCode){
    for (int i = 0; i < releaseArraySize; i++) {
        (releaseArray[i])(usageCode);
    }
}

//***************************************************************************
//
//                             App loading logic
//
//***************************************************************************

void LoadApp(Apps app){
    switch (app){
        case KEYBOARD:
            tickArraySize = ArrayAdd(App_Keyboard_Tick, tickArray, tickArraySize, MAX_APPS);
            pressArraySize = ArrayAddUint8(App_Keyboard_KeyPress, pressArray, pressArraySize, MAX_APPS);
            releaseArraySize = ArrayAddUint8(App_Keyboard_KeyRelease, releaseArray, releaseArraySize, MAX_APPS);
            App_Keyboard_Load();
            break;
        case BONGO_CAT:
            tickArraySize = ArrayAdd(App_BongoCat_Tick, tickArray, tickArraySize, MAX_APPS);
            pressArraySize = ArrayAddUint8(App_BongoCat_KeyPress, pressArray, pressArraySize, MAX_APPS);
            releaseArraySize = ArrayAddUint8(App_BongoCat_KeyRelease, releaseArray, releaseArraySize, MAX_APPS);
            App_BongoCat_Load();
            break;
    }
}

void UnloadApp(Apps app){
    switch (app){
        case KEYBOARD:
            App_Keyboard_Unload();
            tickArraySize = ArrayRemove(&App_Keyboard_Tick, tickArray, tickArraySize, MAX_APPS);
            pressArraySize = ArrayRemoveUint8(&App_Keyboard_KeyPress, pressArray, pressArraySize, MAX_APPS);
            releaseArraySize = ArrayRemoveUint8(&App_Keyboard_KeyRelease, releaseArray, releaseArraySize, MAX_APPS);
            break;
        case BONGO_CAT:
            App_BongoCat_Unload();
            tickArraySize = ArrayRemove(&App_BongoCat_Tick, tickArray, tickArraySize, MAX_APPS);
            pressArraySize = ArrayRemoveUint8(&App_BongoCat_KeyPress, pressArray, pressArraySize, MAX_APPS);
            releaseArraySize = ArrayRemoveUint8(&App_BongoCat_KeyRelease, releaseArray, releaseArraySize, MAX_APPS);
            break;
    }
}

void Bootloader_Entry(){
    Timer0A_Init(&AppTick, 2666666, 7); // Tick apps at 60 tps

    LoadApp(KEYBOARD);
    LoadApp(BONGO_CAT);

    while(1){
        WaitForInterrupt();
    }
}

