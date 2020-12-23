#ifndef  _MUSART1_CONFIG_H_
#define  _MUSART1_CONFIG_H_




/****************************************************************************************************/
#define F_CPU  8000000UL
/****************************************************************************************************/

	

/****************************************************************************************************/
#define MSUART1_BAUD_RATE	9600
/****************************************************************************************************/




/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_DATA_LENGTH_8_BITS
	01- MUSART1_DATA_LENGTH_9_BITS

*/
#define MUSART1_WORD_LENGTH		MUSART1_DATA_LENGTH_8_BITS
/****************************************************************************************************/
/****************************************************************************************************/





/****************************************************************************************************/
/****************************************************************************************************/
/*
  	00- MUSART1_RX_GATE_EN
	01- MUSART1_TX_GATE_EN
	02- MUSART1_TX_RX_GATE_EN
	03- MUSART1_TX_RX_GATE_DIS
*/

#define MUSART1_DATA_GATE		 MUSART1_TX_RX_GATE_EN
/****************************************************************************************************/
/****************************************************************************************************/





/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_COMPLETE_TRANSMIT_INT_DISABLED
	01- MUSART1_COMPLETE_TRANSMIT_INT_ENABLED
*/
#define MUSART1_COMPLETE_TRANSMIT_INT		MUSART1_COMPLETE_TRANSMIT_INT_DISABLED
/****************************************************************************************************/
/****************************************************************************************************/



/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_TRANSMIT_INT_DISABLED
	01- MUSART1_TRANSMIT_INT_ENABLED
*/
#define MUSART1_TRANSMIT_INT 	MUSART1_TRANSMIT_INT_DISABLED
/****************************************************************************************************/
/****************************************************************************************************/



/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_RECEIVER_INT_DISABLED
	01- MUSART1_RECEIVER_INT_ENABLED
*/
#define MUSART1_RECEIVER_INT 	MUSART1_RECEIVER_INT_DISABLED
/****************************************************************************************************/
/****************************************************************************************************/



/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_PARITY_DISABLED
	01- MUSART1_PARITY_ODD
	02- MUSART1_PARITY_EVEN
*/
#define MUSART1_PARITY	MUSART1_PARITY_DISABLED
/****************************************************************************************************/
/****************************************************************************************************/




/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_STOP_BITS_1
	01- MUSART1_STOP_BITS_2
	02- MUSART1_STOP_BITS_0_5
	03- MUSART1_STOP_BITS_1_5
*/
#define MUSART1_STOP_BITS	MUSART1_STOP_BITS_1
/****************************************************************************************************/
/****************************************************************************************************/






/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_CLK_DISABLED
	01- MUSART1_CLK_ENABLED
*/
#define MUSART1_CLK 	MUSART1_CLK_DISABLED
/**********************************************/


/**********************************************/
#if MUSART1_CLK == MUSART1_CLK_ENABLED
/**********************************************/
	/*
		00- MUSART1_CLK_POL_LOW
		01- MUSART1_CLK_POL_HIGH
	*/
	#define MUSART1_CLK_POL 	MUSART1_CLK_POL_LOW
	/**********************************************/



	/**********************************************/
	/*
		00- MUSART1_CLK_PHASE_READ_WRITE
		01- MUSART1_CLK_PHASE_WRITE_READ
	*/
	#define MUSART1_CLK_PHASE 	MUSART1_CLK_PHASE_WRITE_READ
	/**********************************************/


#endif
/****************************************************************************************************/
/****************************************************************************************************/





/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_CTS_HW_ENABLE
	01- MUSART1_CTS_HW_DISABLE
*/
#define MUSART1_CTS_HW  	MUSART1_CTS_HW_DISABLE
/****************************************************************************************************/
/****************************************************************************************************/



/****************************************************************************************************/
/****************************************************************************************************/
/*
	00- MUSART1_RTS_HW_ENABLE
	01- MUSART1_RTS_HW_DISABLE
*/
#define MUSART1_RTS_HW  	MUSART1_RTS_HW_DISABLE
/****************************************************************************************************/
/****************************************************************************************************/







#endif
