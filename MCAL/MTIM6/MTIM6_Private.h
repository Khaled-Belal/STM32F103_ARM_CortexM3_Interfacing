#ifndef		_MTIM6_PRIVATE_H_
#define 	_MTIM6_PRIVATE_H_




typedef struct 
{
	volatile u32 CR1 ;
	volatile u32 CR2 ;
	
	volatile u32 RESERVED1 ;
	
	volatile u32 DIER ;
	volatile u32 SR ;
	volatile u32 EGR ;
	
	volatile u32 RESERVED2[3] ;
	
	volatile u32 CNT ;
	volatile u32 PSC ;
	volatile u32 ARR ;
	
}MTIM0_Type ;


#define   MTIM6		((volatile MTIM0_Type *) 0x40001000 )
#define   MTIM7		((volatile MTIM0_Type *) 0x40001400 )














#endif