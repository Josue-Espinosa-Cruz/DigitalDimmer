/*******************************************************************************
* File Name: In_2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_In_2_ALIASES_H) /* Pins In_2_ALIASES_H */
#define CY_PINS_In_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define In_2_0			(In_2__0__PC)
#define In_2_0_PS		(In_2__0__PS)
#define In_2_0_PC		(In_2__0__PC)
#define In_2_0_DR		(In_2__0__DR)
#define In_2_0_SHIFT	(In_2__0__SHIFT)
#define In_2_0_INTR	((uint16)((uint16)0x0003u << (In_2__0__SHIFT*2u)))

#define In_2_INTR_ALL	 ((uint16)(In_2_0_INTR))


#endif /* End Pins In_2_ALIASES_H */


/* [] END OF FILE */
