/*
 * std.h
 *
 * Created: 23/5/2023 3:27:21 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef STD_H_
#define STD_H_


typedef unsigned char uint8_t;					/* 1 byte , 0 -> 255 */
typedef unsigned short int uint16_t;			/* 2 bytes, 0 -> 65,535 */
typedef unsigned long  int uint32_t;			/* 4 bytes, 0 -> 4,294,967,295 */
typedef unsigned long long int uint64_t;		/* 8 bytes, 0 -> 18,446,744,073,709,551,615 */

typedef signed char sint8_t;					/* 1 byte , -128 -> 127 */
typedef signed short int sint16_t;				/* 2 bytes, -32,768 -> 32,767 */
typedef signed long  int sint32_t;				/* 4 bytes, -2,147,483,648 -> 2,147,483,647 */
typedef signed long long int sint64_t;			/* 8 bytes, -9,223,372,036,854,775,807 -> 9,223,372,036,854,775,807 */

typedef float  f32;								/* 4 bytes, 3.4e-38 -> 3.4e+38 */
typedef double f64;								/* 8 bytes, 1.7e-308 -> 1.7e+308 */

typedef void vd;

#define STD_OK			1
#define STD_NOK			0

#define TRUE	1
#define FALSE	0

#define NULL	        0
#define NULL_PTR	    ( ( void * ) 0 )




#endif /* STD_H_ */