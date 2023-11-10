#include "inc/tm4c123gh6pm.h"
#include "inc/Timer2A.h"
#include "inc/Unified_Port_Init.h"
#include "inc/CortexM.h"
#include "usb_dev_keyboard.h"
#include "Switch_Matrix.h"

#define ROW0 PF3
#define ROW1 PF2
#define ROW2 PF1
#define ROW3 PF0
#define ROW4 PC3 // TDO, must unlock


#define COL0 PC6
#define COL1 PC7
#define COL2 PD7
#define COL3 PE0
#define COL4 PE1
#define COL5 PE2
#define COL6 PE3
#define COL7 PF4
#define COL8 PB7
#define COL9 PB6
#define COL10 PE5
#define COL11 PE4
#define COL12 PB4
#define COL13 PB5

uint8_t modifier = 0;

uint16_t lastRow0 = 0;
uint16_t lastRow1 = 0;
uint16_t lastRow2 = 0;
uint16_t lastRow3 = 0;
uint16_t lastRow4 = 0;

void Switch_Handler(){
	static short counter = 0;
	
	uint16_t currentRow0 = 0;
	uint16_t currentRow1 = 0;
	uint16_t currentRow2 = 0;
  uint16_t currentRow3 = 0;
  uint16_t currentRow4 = 0;
	
			// ROW0 - PF3
			
			// pulse row
			GPIO_PORTF_DATA_R |= (1 << 3);
			Clock_Delay(100);
			
			// sense columns
      currentRow0 = (!!COL0) + (!!COL1 << 1) + (!!COL2 << 2) + (!!COL3 << 3) 
                    + (!!COL4 << 4) + (!!COL5 << 5) + (!!COL6 << 6) + (!!COL7 << 7) 
                    + (!!COL8 << 8) + (!!COL9 << 9) + (!!COL10 << 10) + (!!COL11 << 11)
                    + (!!COL12 << 12) + (!!COL13 << 13);
  
      for (int i = 0; i < 14; i++){
          uint8_t current = !!(currentRow0 & (1 << i));
          uint8_t prev = !!(lastRow0 & (1 << i));
        
          if (current != prev){
            if (current){
              // Now on, key press
              PressKey(KeyboardMatrix[modifier][0][i]);
            } else {
              // Now off, key released
              ReleaseKey(KeyboardMatrix[modifier][0][i]);
            }
          }
      }
  
      /*
			Clock_Delay(10000);
			
			
			// ROW1 - PF1
			
			// pulse row
			GPIO_PORTF_DATA_R |= 0x4;
			Clock_Delay(10);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> A
				currentRow1 |= 0x1;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> S
				currentRow1 |= 0x2;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 6)){
				// COL2 -> D
				currentRow1 |= 0x4;
			}
			
			if ((currentRow1 & 0x1) != (lastRow1 & 0x1)){
				if (currentRow1 & 0x1){
					// Pressing 1,0 = A
					PressKey('A');
				} else {
					// Releasing 1,0 = A
					ReleaseKey('A');
				}
			}
			
			if ((currentRow1 & 0x2) != (lastRow1 & 0x2)){
				if (currentRow1 & 0x2){
					// Pressing 1,1 = S
					PressKey('S');
				} else {
					// Releasing 1,1 = S
					ReleaseKey('S');
				}
			}
			
			if ((currentRow1 & 0x4) != (lastRow1 & 0x4)){
				if (currentRow1 & 0x4){
					// Pressing 1,2 = D
					PressKey('D');
				} else {
					// Releasing 1,2 = D
					ReleaseKey('D');
				}
			}
			
			lastRow1 = currentRow1;
			
			GPIO_PORTF_DATA_R = 0;
			Clock_Delay(100);
			
			// ROW2 - PF2
			
			// pulse row
			GPIO_PORTF_DATA_R |= 0x1;
			Clock_Delay(100);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> Z
				currentRow2 |= 0x1;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> X
				currentRow2 |= 0x2;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 6)){
				// COL2 -> C
				currentRow2 |= 0x4;
			}
			
			if ((currentRow2 & 0x1) != (lastRow2 & 0x1)){
				if (currentRow2 & 0x1){
					// Pressing 2,0 = Z
					PressKey('Z');
				} else {
					// Releasing 2,0 = Z
					ReleaseKey('Z');
				}
			}
			
			if ((currentRow2 & 0x2) != (lastRow2 & 0x2)){
				if (currentRow2 & 0x2){
					// Pressing 2,1 = X
					PressKey('X');
				} else {
					// Releasing 2,1 = X
					ReleaseKey('X');
				}
			}
			
			if ((currentRow2 & 0x4) != (lastRow2 & 0x4)){
				if (currentRow2 & 0x4){
					// Pressing 2,2 = C
					PressKey('C');
				} else {
					// Releasing 2,2 = C
					ReleaseKey('C');
				}
			}
			
			lastRow2 = currentRow2;
			
	
			GPIO_PORTF_DATA_R = 0;
      */
			Clock_Delay(100);
	
}


void Switch_Init(){

	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R5; // Activate port B and F
	while ((SYSCTL_PRGPIO_R & (SYSCTL_PRGPIO_R1 | SYSCTL_PRGPIO_R5)) != (SYSCTL_PRGPIO_R1 | SYSCTL_PRGPIO_R5)){}
	
	GPIO_PORTF_DIR_R |= (1 << 1) + (1 << 2) + (1 << 3); // Set rows to output
	GPIO_PORTF_DEN_R |= 1 + (1 << 1) + (1 << 2) + (1<<3);
	
	GPIO_PORTB_DEN_R |= (1 << 4) + (1 << 5) + (1 << 6);
	
	
	Timer2A_Init(&Switch_Handler, 8000, 4); // Poll at 100 Hz (3 cols)
}

void Switch_Stop(){
	Timer2A_Stop();
}
