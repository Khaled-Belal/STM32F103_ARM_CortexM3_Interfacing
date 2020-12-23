#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"


#include "MSPI1/MSPI1_Interface.h"
#include "MSPI1/MSPI1_Private.h"
#include "MSPI1/MSPI1_Config.h"

#include  "MGPIO/MGPIO_Interface.h" 



/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
ErrorState		MSPI1_EnuInit( void ) 
{
	
#if MSPI1_DUPLEX_DIRECTION	==	MSPI1_DUPLEX_FULL

	CLR_BIT ( MSPI1 -> CR1 , 15 ) ;

#elif MSPI1_DUPLEX_DIRECTION	==	MSPI1_DUPLEX_HALF_RECIEVE

	SET_BIT ( MSPI1 -> CR1 , 15 ) ;
	CLR_BIT ( MSPI1 -> CR1 , 14 ) ;
	
	
#elif MSPI1_DUPLEX_DIRECTION	==	MSPI1_DUPLEX_HALF_TRANSMIT

	SET_BIT ( MSPI1 -> CR1 , 15 ) ;
	SET_BIT ( MSPI1 -> CR1 , 14 ) ;
	
#else
	
#endif	
	
	
	

#if MSPI1_MODE_TYPE	 ==	MSPI1_MODE_MASTER
	
	/*   */
	MGPIO_EnuSetPinDir(PIN_A5)	;	//
	MGPIO_EnuSetPinDir(PIN_A6)	;	//
	MGPIO_EnuSetPinDir(PIN_A7)	;	//
	MGPIO_EnuSetPinDir(PIN_A8)	;	//
	
	
	
	/* Enable Master Mode */
	SET_BIT ( MSPI1 -> CR1 , 2 ) ;
	
	#if  SSM_CONFIG  == SSM_CONFIG_HARDWARE
	
		/* SSM */
		CLR_BIT ( MSPI1 -> CR1 , 9 ) ;
		/* SSI Don`t Care */
		
		/* SSOE  , Set the SS Pin With LOW Automatically */
		SET_BIT ( MSPI1 -> CR2 , 2 ) ;
		
	
	#elif 	SSM_CONFIG  == SSM_CONFIG_SOFTWARE
		
		/* SSM , Software */
		SET_BIT ( MSPI1 -> CR1 , 9 ) ;
		/* SSI , Slave Not Selected */
		SET_BIT ( MSPI1 -> CR1 , 8 ) ;
		
	
	#else
		#error 	"Attention, Wrong SSM_CONFIG !!"
	#endif
	
	
	
	
#elif MSPI1_MODE_TYPE	==	MSPI1_MODE_SLAVE
	
	/*   */
	MGPIO_EnuSetPinDir(PIN_A5)	;	//
	MGPIO_EnuSetPinDir(PIN_A6)	;	//
	MGPIO_EnuSetPinDir(PIN_A7)	;	//
	MGPIO_EnuSetPinDir(PIN_A8)	;	//
	

	/* Enable Slave Mode */
	CLR_BIT ( MSPI1 -> CR1 , 2 ) ;
	
	#if  SSM_CONFIG  == SSM_CONFIG_HARDWARE
	
		/* SSM */
		CLR_BIT ( MSPI1 -> CR1 , 9 ) ;
		
	#elif 	SSM_CONFIG  == SSM_CONFIG_SOFTWARE
		
		/* SSM */
		SET_BIT ( MSPI1 -> CR1 , 9 ) ;
		
		/* SSI */
		CLR_BIT ( MSPI1 -> CR1 , 8 ) ;
		MSPI1 -> CR1 |= NSS_CONFIG   ;

	
	#else
		#error 	"Attention, Wrong SSM_CONFIG !!"
	#endif
	

#else

#endif





#if MSPI1_CPOL	==	MSPI1_CPOL_LOW_0

	CLR_BIT ( MSPI1 -> CR1 , 1 ) ;

#elif MSPI1_CPOL	==	MSPI1_CPOL_HIGH_1

	SET_BIT ( MSPI1 -> CR1 , 1 ) ;
	
#else
	
#endif



#if MSPI1_CPHA	==	MSPI1_CPHA_LOW_0

	CLR_BIT ( MSPI1 -> CR1 , 0 ) ;

#elif MSPI1_CPHA	==	MSPI1_CPHA_HIGH_1

	SET_BIT ( MSPI1 -> CR1 , 0 ) ;
	
#else
	
#endif




 
#if MSPI1_DATA_FRAME_FORMAT	==	MSPI1_LSB

	SET_BIT ( MSPI1 -> CR1 , 7 ) ;

#elif MSPI1_DATA_FRAME_FORMAT	==	MSPI1_HSB

	CLR_BIT ( MSPI1 -> CR1 , 7 ) ;

#else
	
#endif



 
 
 

#if MSPI1_DATA_SIZE	==	MSPI1_DATA_SIZE_8_BITS

	CLR_BIT ( MSPI1 -> CR1 , 11 ) ;

#elif MSPI1_DATA_SIZE	==	MSPI1_DATA_SIZE_16_BITS

	SET_BIT ( MSPI1 -> CR1 , 11 ) ;

#else
	
#endif







/* BAUD RATE CONFIG */
/********************/
	MSPI1 -> CR1 &= ~( 0b111 << 3 )		;
 	//MSPI1 -> CR1 &= 0xFFC7    ;
	MSPI1 -> CR1 |= ( MSPI1_BAUD_RATE  << 3 )		;
	
	
	
	
	return ES_OK ;
}







/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
ErrorState		MSPI1_EnuEnable( void ) 
{
	/* Enable SPI */
	SET_BIT ( MSPI1 -> CR1 , 6 ) ;
	
	return ES_OK ;
	
	
}







/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
ErrorState		MSPI1_EnuDisable( void ) 
{
	/* Enable SPI */
	CLR_BIT ( MSPI1 -> CR1 , 6 ) ;
	
	return ES_OK ;
	
}









	
	
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
ErrorState		MSPI1_EnuSendReceiveSync( u8 Copy_U8DataToSend , u8 * Copy_PU8DataToReceive ) 
{
	/* Interrupt Disabled */
	MSPI1 -> CR2 &= 0   ;
	
	MGPIO_EnuSetPinVal(PIN_A5,LOW)	;	//	SS
	
	/* Send Data */
	MSPI1 -> DR = Copy_U8DataToSend   ;
		
	/* Wait For Busy Flag to Be Cleared , So Bus Get Freed */
	while ( GET_BIT( MSPI1 -> SR , 7  ) == 1  )  ;			/* Wait until Not Busy */
	
	/* Receive Data */
	* Copy_PU8DataToReceive   =   MSPI1 -> DR   ;
	
	MGPIO_EnuSetPinVal(PIN_A5,HIGH)	;	//	SS
	
	return ES_OK ;
}








/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
void (* MSPI1_PFun)(void) ;


ErrorState		MSPI1_EnuSendReceiveAsync( u8 Copy_U8DataToSend , void (* Copy_VoidCallBackPFun)( u8 Copy_U8DataToReceive )  )
{
	MGPIO_EnuSetPinVal(PIN_A5,LOW)	;	//	SS
	MSPI1_PFun  =  Copy_VoidCallBackPFun  ;
	
	/* Interrupt Control Enabled */
	MSPI1 -> CR2 &=~ ( 0b11 << 6 )   ;
	MSPI1 -> CR2 |= ( MSPI1_TX_RX_INTERUPT << 6 )   ;
	
	/* Send Data */
	MSPI1 -> DR = Copy_U8DataToSend   ;
	
	MGPIO_EnuSetPinVal(PIN_A5,HIGH)	;	//	SS
	
	return ES_OK ;
}









/********************************************************************************/
void SPI1_IRQHandler(void)
{
	MSPI1_PFun ( MSPI1 -> DR )  ;
	
}







