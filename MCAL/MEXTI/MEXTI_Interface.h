#ifndef		_MEXTI_INTERFACE_H_
#define 	_MEXTI_INTERFACE_H_


#include "LIB/ERROR_STATE.h"



typedef enum MEXTI_CONFIG
{
	MEXTI_TRIGGER_RISING = 0  ,  MEXTI_TRIGGER_FALLING  ,  MEXTI_TRIGGER_ON_CHANGE  ,
	
	MEXTI_CH0 = 0  , MEXTI_CH1  , MEXTI_CH2   , MEXTI_CH3   , MEXTI_CH4   , MEXTI_CH5   , MEXTI_CH6   , MEXTI_CH7  ,
	
	MEXTI_CH8  	, MEXTI_CH9  , MEXTI_CH10  , MEXTI_CH11  , MEXTI_CH12  , MEXTI_CH13  , MEXTI_CH14  , MEXTI_CH15  
	
}MEXTI_Config ;






/**********************************************************************************************************/
/********************************  EXTI Channel & TriggerMode Selection  **********************************/
/**********************************************************************************************************/
ErrorState		MEXTI_EnuInit(u8 Copy_U8EXTIChannelNum,u8 Copy_U8TriggerMode) ;







/*******************************************************************************************************/
/********************************  EXTI Channel Enable  ************************************************/
/*******************************************************************************************************/
ErrorState		MEXTI_EnuChannelEnable(u8 Copy_U8EXTIChannelNum) ;






/*******************************************************************************************************/
/********************************  EXTI Channel Disable  ***********************************************/
/*******************************************************************************************************/
ErrorState		MEXTI_EnuChannelDisable(u8 Copy_U8EXTIChannelNum) ;






/************************************************************************************************/
/********************************  EXTI Wait For Flag  ******************************************/
/************************************************************************************************/
ErrorState		MEXTI_EnuLinePolling(u8 Copy_U8EXTILineNum) ;







/*******************************************************************************************************/
/********************************  EXTI Triggering by Software  ****************************************/
/*******************************************************************************************************/
ErrorState		MEXTI_EnuChannelSoftWareTrigger(u8 Copy_U8EXTIChannelNum);







/*******************************************************************************************************/
/********************************  CallBack Function Configuration *************************************/
/*******************************************************************************************************/
ErrorState		MEXTI_EnuSetCallBack(u8 Copy_U8EXTIChannelNum , void (*PFun)(void)) ;







	









#endif
