#include  "LIB/STD_TYPES.h"
#include  "LIB/BIT_MATH.h"
#include  "LIB/ERROR_STATE.h"


#include  "MTIM6/MTIM6_Interface.h"
#include  "MTIM6/MTIM6_Private.h"
#include  "MTIM6/MTIM6_Config.h"






ErrorState	MTIM6_EnuInit(void)  
{
	/* Enable Auto Preload */
	SET_BIT ( MTIM6 -> CR1 , 7 )  ;
	
	/* Enable Contineous Pulse Mode */
	CLR_BIT ( MTIM6 -> CR1 , 3 )  ;
	
	/* Enable Event Update  */
	CLR_BIT ( MTIM6 -> CR1 , 1 )  ;
	
	/* Enable Overflow - Underflow Update */
	SET_BIT ( MTIM6 -> CR1 , 2 )  ;	
	
	/* Disable Overflow - Underflow Interrupt */
	CLR_BIT ( MTIM6 -> DIER , 0 )  ;

	/* Initialize Counts */
	MTIM6 -> CNT  =  1000 ; 
	
	/* Initialize Prescaller */
	MTIM6 -> PSC  =  1 ; 
	
	/* Initialize Prescaller */
	MTIM6 -> ARR  =  1000 ; 
	
	return ES_OK ;
}






ErrorState	MTIM6_EnuEnable(void)  
{
	/* Enable Timer */
	SET_BIT ( MTIM6 -> CR1 , 0 )  ;
	
	
	return ES_OK ;
}







ErrorState	MTIM6_EnuDisable(void)  
{
	
	
	
	return ES_OK ;
}
























