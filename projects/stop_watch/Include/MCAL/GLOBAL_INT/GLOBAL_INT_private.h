/*
 * GLOBAL_INT_private.h
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_GLOBAL_INT_GLOBAL_INT_PRIVATE_H_
#define INCLUDE_MCAL_GLOBAL_INT_GLOBAL_INT_PRIVATE_H_


#define GINT_SREG	*((volatile u8*)0x5F)

#define GINT_ENABLE		1
#define GINT_DISABLE	0

#define GINT_GLOBAL_INT_BIT	7

#endif /* INCLUDE_MCAL_GLOBAL_INT_GLOBAL_INT_PRIVATE_H_ */
