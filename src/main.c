/*
 * main.c
 *
 *  Created on: Oct 12, 2018
 *      Author: Hampota
 */


/*
 * main.c
 *
 *  Created on: Oct 11, 2018
 *      Author: Hampota
 */


#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MRCC_interface.h"
#include "GENERAL_PURPOSE_TIMER_interface.h"




void main()
{


	MRCC_Initialize();
	MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
	MRCC_EnableClock(BUS_ABP2,PERIPHERAL_AFIO);
	MRCC_EnableClock(BUS_ABP1,PERIPHERAL_TIMER2);
	MDIO_Initialize();
	MTIMER2_Initialize();
	while(1)
	{
		increase();
		decrease();

	}
}


