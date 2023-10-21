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


void Switch_Handler(){
	static short counter = 0;
	
	
	if (counter == 0){
		GPIO_PORTF_DATA_R ^= 0x8;
		counter++;
	}
	
	GPIO_PORTF_DATA_R ^= 0x2;
	
	
	/*
	switch (counter % 3){
		case 0:
			// ROW0 - PF0
			
			// pulse row
			GPIO_PORTF_DATA_R |= 0x1;
			Clock_Delay1ms(100);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> Q
				//SendString("Q");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> W
				//SendString("W");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL2 -> E
				//SendString("E");
			}
			
			break;
		case 1:
			// ROW1 - PF1
			
			// pulse row
			GPIO_PORTF_DATA_R |= 0x2;
			Clock_Delay1ms(100);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> A
				//SendString("A");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> S
				//SendString("S");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL2 -> D
				//SendString("D");
			}
			
			break;
		case 2:
			// ROW2 - PF2
			
			// pulse row
			GPIO_PORTF_DATA_R |= 0x4;
			Clock_Delay1ms(100);
			
			// sense columns
			if (GPIO_PORTB_DATA_R & (1 << 4)){
				// COL0 -> Z
				//SendString("Z");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL1 -> X
				//SendString("X");
			}
			
			if (GPIO_PORTB_DATA_R & (1 << 5)){
				// COL2 -> C
				//SendString("C");
			}
			
			break;
	}
	
	GPIO_PORTF_DATA_R &= ~(1 + (1 << 1) + (1 << 2)); // clear pulse
	
	if (++counter >= 3){
		counter %= 3;
	}
	*/
}


void Switch_Init(){

	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R5; // Activate port B and F
	while ((SYSCTL_PRGPIO_R & (SYSCTL_PRGPIO_R1 | SYSCTL_PRGPIO_R5)) != (SYSCTL_PRGPIO_R1 | SYSCTL_PRGPIO_R5)){}
	
	GPIO_PORTF_DIR_R |= 1 + (1 << 1) + (1 << 2) + (1<<3); // Set rows to output
	GPIO_PORTF_DEN_R |= 1 + (1 << 1) + (1 << 2) + (1<<3);
	
	GPIO_PORTB_DEN_R |= (1 << 4) + (1 << 5) + (1 << 6);
	
	GPIO_PORTF_DATA_R ^= 0x4;
	
	Timer2A_Init(&Switch_Handler, 50000000, 4); // Poll at 100 Hz (3 cols)
}

void Switch_Stop(){
	Timer2A_Stop();
}
