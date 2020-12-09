#ifndef 	_MDMA_INTERFACE_H_
#define 	_MDMA_INTERFACE_H_




#include "LIB/ERROR_STATE.h"







ErrorState 	MDMA_EnuInit (void) ;





ErrorState 	MDMA_EnuChEnable (u8 Copy_U8ChannelNum) ;





ErrorState 	MDMA_EnuChDisable (u8 Copy_U8ChannelNum) ;





ErrorState 	MDMA_EnuInterruptModeEnable (u8 Copy_U8ChannelNum , u8 Copy_U8InterruptNum) ;



ErrorState 	MDMA_EnuInterruptModeDisable (u8 Copy_U8ChannelNum , u8 Copy_U8InterruptNum) ;








ErrorState 	MDMA_EnuSetAddress (u8 Copy_U8ChannelNum , u32 Copy_U32SourceVal , u32 Copy_U32DestinationVal , u16 Copy_U16TransactionNum ) ;






ErrorState 	MDMA_EnuClearFlag (u8 Copy_U8ChannelNum , u8 Copy_U8InterruptNum) ;





ErrorState 	MDMA_EnuGetFlag(u8 Copy_U8ChannelNum , u8 Copy_U8InterruptNum) ;






ErrorState 	MDMA_EnuSetCallBack(u8 Copy_U8ChannelNum , void (* PFun )(void)  ) ;





















#endif