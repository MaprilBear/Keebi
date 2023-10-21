#include "inc/tm4c123gh6pm.h"
#include "inc/Timer2A.h"
#include "inc/Unified_Port_Init.h"
#include "inc/CortexM.h"
#include "usb_dev_keyboard.h"

#define ROW0 PF0
#define ROW1 PF1
#define ROW2 PF2
#define COL0 PB4
#define COL1 PB5
#define COL2 PB6

uint8_t lastRow0 = 0;
uint8_t lastRow1 = 0;
uint8_t lastRow2 = 0;

void Switch_Handler(){
	static short counter = 0;
	
	uint8_t currentRow0 = 0;
	uint8_t currentRow1 = 0;
	uint8_t currentRow2 = 0;
	
			// ROW0 - PF0
			
			/*
			// pulse row
			GPIO_PORTF_DATA_R |= 0x2;
			Clock_Delay(100);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> Q
				currentRow0 |= 0x1;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> W
				currentRow0 |= 0x2;
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 6)){
				// COL2 -> E
				currentRow0 |= 0x4;
			}
			
			if ((currentRow0 & 0x1) != (lastRow0 & 0x1)){
				if (currentRow0 & 0x1){
					// Pressing 0,0 = Q
					PressKey('Q');
				} else {
					// Releasing 0,0 = Q
					ReleaseKey('Q');
				}
			}
			
			if ((currentRow0 & 0x2) != (lastRow0 & 0x2)){
				if (currentRow0 & 0x2){
					// Pressing 0,1 = W
					PressKey('W');
				} else {
					// Releasing 0,1 = W
					ReleaseKey('W');
				}
			}
			
			if ((currentRow0 & 0x4) != (lastRow0 & 0x4)){
				if (currentRow0 & 0x4){
					// Pressing 0,2 = E
					PressKey('E');
				} else {
					// Releasing 0,2 = E
					ReleaseKey('E');
				}
			}
			
			lastRow0 = currentRow0;
			
			
			GPIO_PORTF_DATA_R = 0;
			Clock_Delay(100);
			
			*/
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
			//Clock_Delay(100);
			
			// ROW2 - PF2
			/*
			// pulse row
			GPIO_PORTF_DATA_R |= 0x8;
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
			Clock_Delay(100);
	*/
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
