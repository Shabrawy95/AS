/*********************************************************************************************************************************
 *  Filename: common_macros.h
 *
 *  Description: Common Macros for AVR
 *
 *  Created on: Dec 27, 2019
 *
 *  Author: Shabrawy
 ********************************************************************************************************************************/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
/*Set specified bit*/
#define SET_BIT(REG, BIT) (REG|=(1<<BIT))
/*Clear specified bit*/
#define CLEAR_BIT(REG, BIT) (REG&=(~(1<<BIT)))
/*Toggle specified bit*/
#define TOGGLE_BIT(REG, BIT) (REG^=(1<<BIT))
/*Set pin value*/
#define SET_BIT_VAL(REG, BIT, VAL) (REG = ((REG)&(~(1<<BIT)))|(VAL<<BIT))

/********************************************************************************************************************************/

/*set reg*/
#define SET_REG(REG) (REG=0xFF)
/*set reg to specific value*/
#define SET_REG_VAL(REG, VAL) (REG=VAL)
/*Clear reg*/
#define CLEAR_REG(REG) (REG=0x00)
/*Toggle reg*/
#define TOGGLE_REG(REG) (REG^=0xFF)
/*Get reg*/
#define GET_REG(REG) (REG & 0xFF)
/*Get channel group*/
#define GET_CH_GROUP(REG, MASK, OFFSET) (((REG) & (MASK))>>(OFFSET))
/*Set channel group*/
#define SET_CH_GROUP(REG, MASK, OFFSET, VAL) (REG = ((REG) & (~MASK))|((VAL)<<(OFFSET)))
/********************************************************************************************************************************/

#define ROL(REG, NUM) (REG=(REG<<NUM)|(REG>>(8-NUM)))
/*Rotate right by specified number of bits*/
#define ROR(REG, NUM) (REG=(REG>>NUM)|(REG<<(8-NUM)))
/* check if bit is set */
#define BIT_IS_SET(REG, BIT) (REG&(1<<BIT))
/* check if bit is clear */
#define BIT_IS_CLEAR(REG, BIT) (!(REG&(1<<BIT)))
/*get bit value*/
#define GET_BIT(REG, BIT) ((REG & (1<<BIT))>>BIT)
/*get lower nibble*/

/********************************************************************************************************************************/

#define GET_LW_NIBBLE(REG) (REG & 0x0F)
/*get higher nibble*/
#define GET_HI_NIBBLE(REG) (REG & 0xF0)
/*clear lower nibble*/
#define CLEAR_LW_NIBBLE(REG) (REG&=0xF0)
/*clear higher nibble*/
#define CLEAR_HI_NIBBLE(REG) (REG&=0x0F)
/*set lower nibble*/
#define SET_LW_NIBBLE(REG) (REG|=0x0F)
/*set higher nibble*/
#define SET_HI_NIBBLE(REG) (REG|=0xF0)


#endif /* COMMON_MACROS_H_ */
