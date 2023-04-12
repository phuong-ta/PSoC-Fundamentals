/*******************************************************************************
* File Name: BLED.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BLED_H) /* Pins BLED_H */
#define CY_PINS_BLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BLED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BLED__PORT == 15 && ((BLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BLED_Write(uint8 value);
void    BLED_SetDriveMode(uint8 mode);
uint8   BLED_ReadDataReg(void);
uint8   BLED_Read(void);
void    BLED_SetInterruptMode(uint16 position, uint16 mode);
uint8   BLED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BLED_SetDriveMode() function.
     *  @{
     */
        #define BLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BLED_DM_RES_UP          PIN_DM_RES_UP
        #define BLED_DM_RES_DWN         PIN_DM_RES_DWN
        #define BLED_DM_OD_LO           PIN_DM_OD_LO
        #define BLED_DM_OD_HI           PIN_DM_OD_HI
        #define BLED_DM_STRONG          PIN_DM_STRONG
        #define BLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BLED_MASK               BLED__MASK
#define BLED_SHIFT              BLED__SHIFT
#define BLED_WIDTH              1u

/* Interrupt constants */
#if defined(BLED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BLED_SetInterruptMode() function.
     *  @{
     */
        #define BLED_INTR_NONE      (uint16)(0x0000u)
        #define BLED_INTR_RISING    (uint16)(0x0001u)
        #define BLED_INTR_FALLING   (uint16)(0x0002u)
        #define BLED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BLED_INTR_MASK      (0x01u) 
#endif /* (BLED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLED_PS                     (* (reg8 *) BLED__PS)
/* Data Register */
#define BLED_DR                     (* (reg8 *) BLED__DR)
/* Port Number */
#define BLED_PRT_NUM                (* (reg8 *) BLED__PRT) 
/* Connect to Analog Globals */                                                  
#define BLED_AG                     (* (reg8 *) BLED__AG)                       
/* Analog MUX bux enable */
#define BLED_AMUX                   (* (reg8 *) BLED__AMUX) 
/* Bidirectional Enable */                                                        
#define BLED_BIE                    (* (reg8 *) BLED__BIE)
/* Bit-mask for Aliased Register Access */
#define BLED_BIT_MASK               (* (reg8 *) BLED__BIT_MASK)
/* Bypass Enable */
#define BLED_BYP                    (* (reg8 *) BLED__BYP)
/* Port wide control signals */                                                   
#define BLED_CTL                    (* (reg8 *) BLED__CTL)
/* Drive Modes */
#define BLED_DM0                    (* (reg8 *) BLED__DM0) 
#define BLED_DM1                    (* (reg8 *) BLED__DM1)
#define BLED_DM2                    (* (reg8 *) BLED__DM2) 
/* Input Buffer Disable Override */
#define BLED_INP_DIS                (* (reg8 *) BLED__INP_DIS)
/* LCD Common or Segment Drive */
#define BLED_LCD_COM_SEG            (* (reg8 *) BLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define BLED_LCD_EN                 (* (reg8 *) BLED__LCD_EN)
/* Slew Rate Control */
#define BLED_SLW                    (* (reg8 *) BLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BLED_PRTDSI__CAPS_SEL       (* (reg8 *) BLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BLED_PRTDSI__OE_SEL0        (* (reg8 *) BLED__PRTDSI__OE_SEL0) 
#define BLED_PRTDSI__OE_SEL1        (* (reg8 *) BLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BLED_PRTDSI__OUT_SEL0       (* (reg8 *) BLED__PRTDSI__OUT_SEL0) 
#define BLED_PRTDSI__OUT_SEL1       (* (reg8 *) BLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BLED_PRTDSI__SYNC_OUT       (* (reg8 *) BLED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BLED__SIO_CFG)
    #define BLED_SIO_HYST_EN        (* (reg8 *) BLED__SIO_HYST_EN)
    #define BLED_SIO_REG_HIFREQ     (* (reg8 *) BLED__SIO_REG_HIFREQ)
    #define BLED_SIO_CFG            (* (reg8 *) BLED__SIO_CFG)
    #define BLED_SIO_DIFF           (* (reg8 *) BLED__SIO_DIFF)
#endif /* (BLED__SIO_CFG) */

/* Interrupt Registers */
#if defined(BLED__INTSTAT)
    #define BLED_INTSTAT            (* (reg8 *) BLED__INTSTAT)
    #define BLED_SNAP               (* (reg8 *) BLED__SNAP)
    
	#define BLED_0_INTTYPE_REG 		(* (reg8 *) BLED__0__INTTYPE)
#endif /* (BLED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BLED_H */


/* [] END OF FILE */
