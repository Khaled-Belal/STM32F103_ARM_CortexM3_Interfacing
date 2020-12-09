#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"


#include "MDMA/MDMA_Interface.h"
#include "MDMA/MDMA_Private.h"
#include "MDMA/MDMA_Config.h"




#define MDMA_PERIPHERAL		0
#define MDMA_MEMORY			1


#define MDMA_SINGLE			0
#define MDMA_CIRCULAR		1


#define MDMA_LOW_PRIORITY		0
#define MDMA_MED_PRIORITY		1
#define MDMA_HIGH_PRIORITY		2
#define MDMA_V_HIGH_PRIORITY	3


typedef enum 
{
	MDMA_CH1=0 , MDMA_CH2 , MDMA_CH3 ,  MDMA_CH4 ,  MDMA_CH5 ,  MDMA_CH6 ,  MDMA_CH7  ,
	
	MDMA_PRIORITY_LOW = 0 , MDMA_PRIORITY_MEDIUM , MDMA_PRIORITY_HIGH , MDMA_PRIORITY_V_HIGH ,
	
	MDMA_CONNECTION_PERI_MEM = 0 , MDMA_CONNECTION_MEM_PERI ,  MDMA_CONNECTION_MEM_MEM , 
	
}Channel_Parameters ;





ErrorState 	MDMA_EnuSetConfiguration ( u8 Copy_U8ChannelNum 	, u8 Copy_U8ChannelPriority , u8 Copy_U8ConnectionMode  ,
									   u8 Copy_U8MemorySize 	, u8 Copy_U8PeripheralSize  , u8 Copy_U8MemoryInc 		,  u8 Copy_U8PeriperalInc  )										
{
	
	/* Reset all Configurations, MAke Sure DMA is Disabled to begin Configuration */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR = 0x00000000 ;

	/* Priority */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR |= ( Copy_U8ChannelPriority & 0b11 ) << 12 ;
	
	
	/*  ConnectionMode */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR |= ( Copy_U8ConnectionMode & 0b11 ) << 12 ;
	
	
	/*   */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR |= ( Copy_U8ChannelPriority & 0b11 ) << 12 ;
	
	
	/*   */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR |= ( Copy_U8ChannelPriority & 0b11 ) << 12 ;
	
	
	/*   */
	MDMA -> CHANNEL[Copy_U8ChannelNum].CCR |= ( Copy_U8ChannelPriority & 0b11 ) << 12 ;
	

	(0b0000) |  ((Copy_U8ChannelDestination&0b11) << 4) |  ((Copy_U8ChannelMode&0b11) << 5) | ((Copy_U8ChannelPriority&0b11) << 12)   ;
	
	
	return ES_OK ;
}





ErrorState 	MDMA_EnuChannelEnable (u8 Copy_U8ChannelNum) 
{
	
	SET_BIT( MDMA -> CHANNEL[Copy_U8ChannelNum-1].CCR , 0 )  ;
	
	
	return ES_OK ;
}





ErrorState 	MDMA_EnuChannelDisable (u8 Copy_U8ChannelNum) 
{
	
	CLR_BIT( MDMA -> CHANNEL[Copy_U8ChannelNum-1].CCR , 0 )  ;
	
	
	return ES_OK ;
	
}





ErrorState 	MDMA_EnuChannelInterruptEnable (u8 Copy_U8ChannelNum) 
{
	MDMA -> CHANNEL[Copy_U8ChannelNum-1].CCR |= (0b111)<<1    ;
	
	
	return ES_OK ;
}





ErrorState 	MDMA_EnuSetAddress (u8 Copy_U8ChannelNum , u32 Copy_U32SourceVal , u32 Copy_U32DestinationVal , u16 Copy_U16TransactionNums ) 
{
	MDMA -> CHANNEL[Copy_U8ChannelNum-1].CPAR   =  Copy_U32DestinationVal   ;

	MDMA -> CHANNEL[Copy_U8ChannelNum-1].CMAR   =  Copy_U32SourceVal		;
	
	MDMA -> CHANNEL[Copy_U8ChannelNum-1].CNDTR	=  Copy_U16TransactionNums	 		;
	

	return ES_OK ;
}






ErrorState 	MDMA_EnuClearFlag (u8 Copy_U8ChannelNum) 
{
	MDMA -> IFCR  | =	 ( (Copy_U8ChannelNum-1) * 4 )
	
	
}





ErrorState 	MDMA_EnuGetFlag(u8 Copy_U8ChannelNum) 
{
	
	
	
}






ErrorState 	MDMA_EnuSetCallBack(u8 Copy_U8ChannelNum , void (* PFun )(void)  ) 
{
	
	
	
}




