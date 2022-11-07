// License       : License.txt
// Specifications: Spec-LM35_LM35A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35.cpp
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM35.h"

#if     iLM35_ma == iSMA                                // Simple moving average filter
static float32 LM35_sma_buf[iLM35_SMA_num];
static sma_f32_t LM35_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM35_SMA_num ,                                 // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM35_sma_buf[0]                                // buffer
};

#elif   iLM35_ma == iEMA                                // Exponential moving average filter
static ema_f32_t LM35_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM35_EMA_K                                     // Exponential smoothing factor
};

#elif   iLM35_ma == iWMA                                // Weighted moving average filter
static float32 LM35_wma_buf[iLM35_WMA_num];
static wma_f32_t LM35_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM35_WMA_num ,                                 // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM35_WMA_num * (iLM35_WMA_num + 1)/2 ,         // kn sum
        &LM35_wma_buf[0]                                // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM35 =
{
        iLM35                   ,
        iLM35_pin               ,
        iLM35_xoff              ,
        iLM35_yoff              ,
        iLM35_gain              ,
        iLM35_max               ,
        iLM35_min               ,
        iLM35_ma                ,
        
#if     iLM35_ma == iSMA                                // Simple moving average filter
        &LM35_Phy_SMA           ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35_ma == iEMA                                // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM35_Phy_EMA           ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35_ma == iWMA                                // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM35_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
