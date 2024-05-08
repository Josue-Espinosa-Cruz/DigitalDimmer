/*******************************************************************************
* File Name: In_0.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_In_0_H) /* Pins In_0_H */
#define CY_PINS_In_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "In_0_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} In_0_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   In_0_Read(void);
void    In_0_Write(uint8 value);
uint8   In_0_ReadDataReg(void);
#if defined(In_0__PC) || (CY_PSOC4_4200L) 
    void    In_0_SetDriveMode(uint8 mode);
#endif
void    In_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   In_0_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void In_0_Sleep(void); 
void In_0_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(In_0__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define In_0_DRIVE_MODE_BITS        (3)
    #define In_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - In_0_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the In_0_SetDriveMode() function.
         *  @{
         */
        #define In_0_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define In_0_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define In_0_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define In_0_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define In_0_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define In_0_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define In_0_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define In_0_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define In_0_MASK               In_0__MASK
#define In_0_SHIFT              In_0__SHIFT
#define In_0_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in In_0_SetInterruptMode() function.
     *  @{
     */
        #define In_0_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define In_0_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define In_0_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define In_0_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(In_0__SIO)
    #define In_0_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(In_0__PC) && (CY_PSOC4_4200L)
    #define In_0_USBIO_ENABLE               ((uint32)0x80000000u)
    #define In_0_USBIO_DISABLE              ((uint32)(~In_0_USBIO_ENABLE))
    #define In_0_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define In_0_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define In_0_USBIO_ENTER_SLEEP          ((uint32)((1u << In_0_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << In_0_USBIO_SUSPEND_DEL_SHIFT)))
    #define In_0_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << In_0_USBIO_SUSPEND_SHIFT)))
    #define In_0_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << In_0_USBIO_SUSPEND_DEL_SHIFT)))
    #define In_0_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(In_0__PC)
    /* Port Configuration */
    #define In_0_PC                 (* (reg32 *) In_0__PC)
#endif
/* Pin State */
#define In_0_PS                     (* (reg32 *) In_0__PS)
/* Data Register */
#define In_0_DR                     (* (reg32 *) In_0__DR)
/* Input Buffer Disable Override */
#define In_0_INP_DIS                (* (reg32 *) In_0__PC2)

/* Interrupt configuration Registers */
#define In_0_INTCFG                 (* (reg32 *) In_0__INTCFG)
#define In_0_INTSTAT                (* (reg32 *) In_0__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define In_0_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(In_0__SIO)
    #define In_0_SIO_REG            (* (reg32 *) In_0__SIO)
#endif /* (In_0__SIO_CFG) */

/* USBIO registers */
#if !defined(In_0__PC) && (CY_PSOC4_4200L)
    #define In_0_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define In_0_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define In_0_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define In_0_DRIVE_MODE_SHIFT       (0x00u)
#define In_0_DRIVE_MODE_MASK        (0x07u << In_0_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins In_0_H */


/* [] END OF FILE */
