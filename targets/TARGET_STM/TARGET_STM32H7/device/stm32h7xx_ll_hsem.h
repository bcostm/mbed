/**
  ******************************************************************************
  * @file    stm32h7xx_ll_hsem.h
  * @author  MCD Application Team
  * @brief   Header file of HSEM LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32H7xx_LL_HSEM_H
#define __STM32H7xx_LL_HSEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"

/** @addtogroup STM32H7xx_LL_Driver
  * @{
  */

#if defined(HSEM)

/** @defgroup HSEM_LL HSEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup HSEM_LL_Exported_Constants HSEM Exported Constants
  * @{
  */

/** @defgroup HSEM_LL_EC_COREID COREID Defines
  * @{
  */
#define LL_HSEM_COREID_NONE             0U
#define LL_HSEM_COREID_CPU1             HSEM_CR_COREID_CPU1
#define LL_HSEM_COREID_CPU2             HSEM_CR_COREID_CPU2
#define LL_HSEM_COREID                  HSEM_CR_COREID_CURRENT
/**
  * @}
  */

/** @defgroup HSEM_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_HSEM_ReadReg function
  * @{
  */

#define LL_HSEM_SEMAPHORE_0                HSEM_C1IER_ISE0
#define LL_HSEM_SEMAPHORE_1                HSEM_C1IER_ISE1
#define LL_HSEM_SEMAPHORE_2                HSEM_C1IER_ISE2
#define LL_HSEM_SEMAPHORE_3                HSEM_C1IER_ISE3
#define LL_HSEM_SEMAPHORE_4                HSEM_C1IER_ISE4
#define LL_HSEM_SEMAPHORE_5                HSEM_C1IER_ISE5
#define LL_HSEM_SEMAPHORE_6                HSEM_C1IER_ISE6
#define LL_HSEM_SEMAPHORE_7                HSEM_C1IER_ISE7
#define LL_HSEM_SEMAPHORE_8                HSEM_C1IER_ISE8
#define LL_HSEM_SEMAPHORE_9                HSEM_C1IER_ISE9
#define LL_HSEM_SEMAPHORE_10               HSEM_C1IER_ISE10
#define LL_HSEM_SEMAPHORE_11               HSEM_C1IER_ISE11
#define LL_HSEM_SEMAPHORE_12               HSEM_C1IER_ISE12
#define LL_HSEM_SEMAPHORE_13               HSEM_C1IER_ISE13
#define LL_HSEM_SEMAPHORE_14               HSEM_C1IER_ISE14
#define LL_HSEM_SEMAPHORE_15               HSEM_C1IER_ISE15
#define LL_HSEM_SEMAPHORE_16               HSEM_C1IER_ISE16
#define LL_HSEM_SEMAPHORE_17               HSEM_C1IER_ISE17
#define LL_HSEM_SEMAPHORE_18               HSEM_C1IER_ISE18
#define LL_HSEM_SEMAPHORE_19               HSEM_C1IER_ISE19
#define LL_HSEM_SEMAPHORE_20               HSEM_C1IER_ISE20
#define LL_HSEM_SEMAPHORE_21               HSEM_C1IER_ISE21
#define LL_HSEM_SEMAPHORE_22               HSEM_C1IER_ISE22
#define LL_HSEM_SEMAPHORE_23               HSEM_C1IER_ISE23
#define LL_HSEM_SEMAPHORE_24               HSEM_C1IER_ISE24
#define LL_HSEM_SEMAPHORE_25               HSEM_C1IER_ISE25
#define LL_HSEM_SEMAPHORE_26               HSEM_C1IER_ISE26
#define LL_HSEM_SEMAPHORE_27               HSEM_C1IER_ISE27
#define LL_HSEM_SEMAPHORE_28               HSEM_C1IER_ISE28
#define LL_HSEM_SEMAPHORE_29               HSEM_C1IER_ISE29
#define LL_HSEM_SEMAPHORE_30               HSEM_C1IER_ISE30
#define LL_HSEM_SEMAPHORE_31               HSEM_C1IER_ISE31
#define LL_HSEM_SEMAPHORE_ALL              0xFFFFFFFFU
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup HSEM_LL_Exported_Macros HSEM Exported Macros
  * @{
  */

/** @defgroup HSEM_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in HSEM register
  * @param  __INSTANCE__ HSEM Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_HSEM_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in HSEM register
  * @param  __INSTANCE__ HSEM Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_HSEM_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup HSEM_LL_Exported_Functions HSEM Exported Functions
  * @{
  */

/** @defgroup HSEM_LL_EF_Data_Management Data_Management
  * @{
  */


/**
* @brief  Return 1 if the semaphore is locked, else return 0.
* @rmtoll R            LOCK          LL_HSEM_IsSemaphoreLocked
* @param  HSEMx HSEM Instance.
* @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
* @retval State of bit (1 or 0).
*/
__STATIC_INLINE uint32_t LL_HSEM_IsSemaphoreLocked(HSEM_TypeDef *HSEMx, uint32_t Semaphore)
{
  return (uint32_t)(READ_BIT(HSEMx->R[Semaphore], HSEM_R_LOCK) == (HSEM_R_LOCK_Msk));
}

/**
  * @brief  Get core id.
  * @rmtoll R            COREID        LL_HSEM_GetCoreId
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_HSEM_COREID_NONE
  *         @arg @ref LL_HSEM_COREID_CPU1
  *         @arg @ref LL_HSEM_COREID_CPU2
  */
__STATIC_INLINE uint32_t LL_HSEM_GetCoreId(HSEM_TypeDef *HSEMx, uint32_t Semaphore)
{
  return (uint32_t)(READ_BIT(HSEMx->R[Semaphore], HSEM_R_COREID_Msk));
}

/**
  * @brief  Get process id.
  * @rmtoll R            PROCID        LL_HSEM_GetProcessId
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @retval Process number. Value between Min_Data=0 and Max_Data=255
  */
__STATIC_INLINE uint32_t LL_HSEM_GetProcessId(HSEM_TypeDef *HSEMx, uint32_t Semaphore)
{
  return (uint32_t)(READ_BIT(HSEMx->R[Semaphore], HSEM_R_PROCID_Msk));
}

/**
  * @brief  Get the lock by writing in R register.
  * @note The R register has to be read to determined if the lock is taken.
  * @rmtoll R            LOCK          LL_HSEM_SetLock
  * @rmtoll R            COREID        LL_HSEM_SetLock
  * @rmtoll R            PROCID        LL_HSEM_SetLock
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @param  process Process id. Value between Min_Data=0 and Max_Data=255
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_SetLock(HSEM_TypeDef *HSEMx, uint32_t Semaphore, uint32_t process)
{
  WRITE_REG(HSEMx->R[Semaphore], (HSEM_R_LOCK | LL_HSEM_COREID | process));
}

/**
  * @brief  Get the lock with 2-step lock.
  * @rmtoll R            LOCK          LL_HSEM_2StepLock
  * @rmtoll R            COREID        LL_HSEM_2StepLock
  * @rmtoll R            PROCID        LL_HSEM_2StepLock
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @param  process Process id. Value between Min_Data=0 and Max_Data=255
  * @retval 1 lock fail, 0 lock successfull or already locked by same process and core
  */
__STATIC_INLINE uint32_t LL_HSEM_2StepLock(HSEM_TypeDef *HSEMx, uint32_t Semaphore, uint32_t process)
{
  WRITE_REG(HSEMx->R[Semaphore], (HSEM_R_LOCK | LL_HSEM_COREID | process));
  return (uint32_t)(HSEMx->R[Semaphore] != (HSEM_R_LOCK | LL_HSEM_COREID | process));
}

/**
  * @brief  Get the lock with 1-step lock.
  * @rmtoll RLR          LOCK          LL_HSEM_1StepLock
  * @rmtoll RLR          COREID        LL_HSEM_1StepLock
  * @rmtoll RLR          PROCID        LL_HSEM_1StepLock
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @retval 1 lock fail, 0 lock successfull or already locked by same core
  */
__STATIC_INLINE uint32_t LL_HSEM_1StepLock(HSEM_TypeDef *HSEMx, uint32_t Semaphore)
{
  return (uint32_t)(HSEMx->RLR[Semaphore] != (HSEM_R_LOCK | LL_HSEM_COREID));
}

/**
  * @brief  Release the lock of the semaphore.
  * @note In case of LL_HSEM_1StepLock usage to lock a semaphore, the process is 0.
  * @rmtoll R            LOCK          LL_HSEM_ReleaseLock
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @param  process Process number. Value between Min_Data=0 and Max_Data=255
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_ReleaseLock(HSEM_TypeDef *HSEMx, uint32_t Semaphore, uint32_t process)
{
  WRITE_REG(HSEMx->R[Semaphore], (LL_HSEM_COREID | process));
}

/**
  * @brief  Get the lock status of the semaphore.
  * @rmtoll R            LOCK          LL_HSEM_GetStatus
  * @param  HSEMx HSEM Instance.
  * @param  Semaphore Semaphore number. Value between Min_Data=0 and Max_Data=31
  * @retval 0 semaphore is free, 1 semaphore is locked  */
__STATIC_INLINE uint32_t LL_HSEM_GetStatus(HSEM_TypeDef *HSEMx, uint32_t Semaphore)
{
  return (uint32_t)(HSEMx->R[Semaphore] != 0U);
}

/**
  * @brief  Set the key.
  * @rmtoll KEYR         KEY           LL_HSEM_SetKey
  * @param  HSEMx HSEM Instance.
  * @param  key Key value.
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_SetKey(HSEM_TypeDef *HSEMx, uint32_t key)
{
  WRITE_REG(HSEMx->KEYR, key << HSEM_KEYR_KEY_Pos);
}

/**
  * @brief  Get the key.
  * @rmtoll KEYR         KEY           LL_HSEM_GetKey
  * @param  HSEMx HSEM Instance.
  * @retval key to unlock all semaphore from the same core
  */
__STATIC_INLINE uint32_t LL_HSEM_GetKey(HSEM_TypeDef *HSEMx)
{
  return (uint32_t)(READ_BIT(HSEMx->KEYR, HSEM_KEYR_KEY) >> HSEM_KEYR_KEY_Pos);
}

/**
  * @brief  Release all semaphore with the same core id.
  * @rmtoll CR           KEY           LL_HSEM_ResetAllLock
  * @param  HSEMx HSEM Instance.
  * @param  key Key value.
  * @param  core This parameter can be one of the following values:
  *         @arg @ref LL_HSEM_COREID_CPU1
  *         @arg @ref LL_HSEM_COREID_CPU2
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_ResetAllLock(HSEM_TypeDef *HSEMx, uint32_t key, uint32_t core)
{
  WRITE_REG(HSEMx->CR, (key << HSEM_CR_KEY_Pos) | core);
}

/**
  * @}
  */

/** @defgroup HSEM_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable interrupt.
  * @rmtoll C1IER         ISEM          LL_HSEM_EnableIT_C1IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_EnableIT_C1IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  SET_BIT(HSEMx->C1IER, SemaphoreMask);
}

/**
  * @brief  Enable interrupt.
  * @rmtoll C2IER         ISEM          LL_HSEM_EnableIT_C2IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_EnableIT_C2IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  SET_BIT(HSEMx->C2IER, SemaphoreMask);
}

/**
  * @brief  Disable interrupt.
  * @rmtoll C1IER          ISEM          LL_HSEM_DisableIT_C1IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_DisableIT_C1IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  CLEAR_BIT(HSEMx->C1IER, SemaphoreMask);
}

/**
  * @brief  Disable interrupt.
  * @rmtoll C2IER          ISEM          LL_HSEM_DisableIT_C2IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_DisableIT_C2IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  CLEAR_BIT(HSEMx->C2IER, SemaphoreMask);
}

/**
  * @brief  Check if interrupt is enabled.
  * @rmtoll C1IER          ISEM          LL_HSEM_IsEnabledIT_C1IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsEnabledIT_C1IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C1IER, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @brief  Check if interrupt is enabled.
  * @rmtoll C2IER          ISEM          LL_HSEM_IsEnabledIT_C2IER
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsEnabledIT_C2IER(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C2IER, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @}
  */

/** @defgroup HSEM_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Clear interrupt status.
  * @rmtoll C1ICR         ISEM          LL_HSEM_ClearFlag_C1ICR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_ClearFlag_C1ICR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  WRITE_REG(HSEMx->C1ICR, SemaphoreMask);
}

/**
  * @brief  Clear interrupt status.
  * @rmtoll C2ICR         ISEM          LL_HSEM_ClearFlag_C2ICR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_HSEM_ClearFlag_C2ICR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  WRITE_REG(HSEMx->C2ICR, SemaphoreMask);
}

/**
  * @brief  Get interrupt status from ISR register.
  * @rmtoll C1ISR         ISEM          LL_HSEM_IsActiveFlag_C1ISR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsActiveFlag_C1ISR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C1ISR, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @brief  Get interrupt status from ISR register.
  * @rmtoll C2ISR         ISEM          LL_HSEM_IsActiveFlag_C2ISR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsActiveFlag_C2ISR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C2ISR, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @brief  Get interrupt status from MISR register.
  * @rmtoll C1MISR        ISEM          LL_HSEM_IsActiveFlag_C1MISR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsActiveFlag_C1MISR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C1MISR, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @brief  Get interrupt status from MISR register.
  * @rmtoll C2MISR        ISEM          LL_HSEM_IsActiveFlag_C2MISR
  * @param  HSEMx HSEM Instance.
  * @param  SemaphoreMask This parameter can be a combination of the following values:
  *         @arg @ref LL_HSEM_SEMAPHORE_0
  *         @arg @ref LL_HSEM_SEMAPHORE_1
  *         @arg @ref LL_HSEM_SEMAPHORE_2
  *         @arg @ref LL_HSEM_SEMAPHORE_3
  *         @arg @ref LL_HSEM_SEMAPHORE_4
  *         @arg @ref LL_HSEM_SEMAPHORE_5
  *         @arg @ref LL_HSEM_SEMAPHORE_6
  *         @arg @ref LL_HSEM_SEMAPHORE_7
  *         @arg @ref LL_HSEM_SEMAPHORE_8
  *         @arg @ref LL_HSEM_SEMAPHORE_9
  *         @arg @ref LL_HSEM_SEMAPHORE_10
  *         @arg @ref LL_HSEM_SEMAPHORE_11
  *         @arg @ref LL_HSEM_SEMAPHORE_12
  *         @arg @ref LL_HSEM_SEMAPHORE_13
  *         @arg @ref LL_HSEM_SEMAPHORE_14
  *         @arg @ref LL_HSEM_SEMAPHORE_15
  *         @arg @ref LL_HSEM_SEMAPHORE_16
  *         @arg @ref LL_HSEM_SEMAPHORE_17
  *         @arg @ref LL_HSEM_SEMAPHORE_18
  *         @arg @ref LL_HSEM_SEMAPHORE_19
  *         @arg @ref LL_HSEM_SEMAPHORE_20
  *         @arg @ref LL_HSEM_SEMAPHORE_21
  *         @arg @ref LL_HSEM_SEMAPHORE_22
  *         @arg @ref LL_HSEM_SEMAPHORE_23
  *         @arg @ref LL_HSEM_SEMAPHORE_24
  *         @arg @ref LL_HSEM_SEMAPHORE_25
  *         @arg @ref LL_HSEM_SEMAPHORE_26
  *         @arg @ref LL_HSEM_SEMAPHORE_27
  *         @arg @ref LL_HSEM_SEMAPHORE_28
  *         @arg @ref LL_HSEM_SEMAPHORE_29
  *         @arg @ref LL_HSEM_SEMAPHORE_30
  *         @arg @ref LL_HSEM_SEMAPHORE_31
  *         @arg @ref LL_HSEM_SEMAPHORE_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_HSEM_IsActiveFlag_C2MISR(HSEM_TypeDef *HSEMx, uint32_t SemaphoreMask)
{
  return (uint32_t)(READ_BIT(HSEMx->C2MISR, SemaphoreMask) == (SemaphoreMask));
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(HSEM1) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32H7xx_LL_HSEM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
