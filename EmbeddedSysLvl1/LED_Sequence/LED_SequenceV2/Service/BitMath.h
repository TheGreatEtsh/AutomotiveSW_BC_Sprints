/*
 * BitMath.h
 *
 * Created: 6/1/2022 3:52:19 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define	SET_BIT(Reg,BitNo)		(Reg |= (1<<BitNo))
#define	CLR_BIT(Reg,BitNo)		(Reg &= (~(1<<BitNo)))
#define TOG_BIT(Reg,BitNo)		(Reg ^= (1<<BitNo))
#define GET_BIT(Reg,BitNo)		(1   &  (Reg>>BitNo))



#endif /* BITMATH_H_ */