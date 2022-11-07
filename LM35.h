// License       : License.txt
// Specifications: Spec-LM35_LM35A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35.h
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM35_H__
#define __LM35_H__

#include "user_define.h"

// Components number
#define iLM35                   126U                    // Texas Instruments LM35, LM35A

// LM35, LM35A System Parts definitions
#define iLM35_xoff              0.0F                    // X offset [V]
#define iLM35_yoff              0.0F                    // Y offset [degree celsius]
#define iLM35_gain              0.01F                   // Gain [V/degree celsius]
#define iLM35_max               150.0F                  // Temperature Max [degree celsius]
#define iLM35_min               2.0F                    // Temperature Min [degree celsius]     CAUTION:-55[°C],the circuit needs a voltage Offset

extern const tbl_adc_t tbl_LM35;

#endif /*__LM35_H__*/
