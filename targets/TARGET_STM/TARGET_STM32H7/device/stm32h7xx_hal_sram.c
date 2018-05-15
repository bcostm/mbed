/**
  ******************************************************************************
  * @file    stm32h7xx_hal_sram.c
  * @author  MCD Application Team
  * @brief   SRAM HAL module driver.
  *          This file provides a generic firmware to drive SRAM memories
  *          mounted as external device.
  *
  @verbatim
  ==============================================================================
                          ##### How to use this driver #####
  ==============================================================================
  [..]
    This driver is a generic layered driver which contains a set of APIs used to
    control SRAM memories. It uses the FMC layer functions to interface
    with SRAM devices.
    The following sequence should be followed to configure the FMC to interface
    with SRAM/PSRAM memories:

   (#) Declare a SRAM_HandleTypeDef handle structure, for example:
          SRAM_HandleTypeDef  hsram

       (++) Fill the SRAM_HandleTypeDef handle "Init" field with the allowed
            values of the structure member.

       (++) Fill the SRAM_HandleTypeDef handle "Instance" field with a predefined
            base register instance for NOR or SRAM device

       (++) Fill the SRAM_HandleTypeDef handle "Extended" field with a predefined
            base register instance for NOR or SRAM extended mode

   (#) Declare two FMC_NORSRAM_TimingTypeDef structures, for both normal and extended
       mode timings; for example:
          FMC_NORSRAM_TimingTypeDef  Timing and FMC_NORSRAM_TimingTypeDef  ExTiming;
      and fill its fields with the allowed values of the structure member.

   (#) Initialize the SRAM Controller by calling the function HAL_SRAM_Init(). This function
       performs the following sequence:

       (##) MSP hardware layer configuration using the function HAL_SRAM_MspInit()
       (##) Control register configuration using the FMC NORSRAM interface function
            FMC_NORSRAM_Init()
       (##) Timing register configuration using the FMC NORSRAM interface function
            FMC_NORSRAM_Timing_Init()
       (##) Extended mode Timing register configuration using the FMC NORSRAM interface function
            FMC_NORSRAM_Extended_Timing_Init()
       (##) Enable the SRAM device using the macro __FMC_NORSRAM_ENABLE()

   (#) At this stage you can perform read/write accesses from/to the memory connected
       to the NOR/SRAM Bank. You can perform either polling or DMA transfer using the
       following APIs:
       (++) HAL_SRAM_Read()/HAL_SRAM_Write() for polling read/write access
       (++) HAL_SRAM_Read_DMA()/HAL_SRAM_Write_DMA() for DMA read/write transfer

   (#) You can also control the SRAM device by calling the control APIs HAL_SRAM_WriteOperation_Enable()/
       HAL_SRAM_WriteOperation_Disable() to respectively enable/disable the SRAM write operation

   (#) You can continuously monitor the SRAM device HAL state by calling the function
       HAL_SRAM_GetState()

       *** Callback registration ***
    =============================================
    [..]
      The compilation define  USE_HAL_SRAM_REGISTER_CALLBACKS when set to 1
      allows the user to configure dynamically the driver callbacks.

      Use Functions @ref HAL_SRAM_RegisterCallback() to register a user callback,
      it allows to register following callbacks:
        (+) MspInitCallback    : SRAM MspInit.
        (+) MspDeInitCallback  : SRAM MspDeInit.
      This function takes as parameters the HAL peripheral handle, the Callback ID
      and a pointer to the user callback function.

      Use function @ref HAL_SRAM_UnRegisterCallback() to reset a callback to the default
      weak (surcharged) function. It allows to reset following callbacks:
        (+) MspInitCallback    : SRAM MspInit.
        (+) MspDeInitCallback  : SRAM MspDeInit.
      This function) takes as parameters the HAL peripheral handle and the Callback ID.

      By default, after the @ref HAL_SRAM_Init and if the state is HAL_SRAM_STATE_RESET
      all callbacks are reset to the corresponding legacy weak (surcharged) functions.
      Exception done for MspInit and MspDeInit callbacks that are respectively
      reset to the legacy weak (surcharged) functions in the @ref HAL_SRAM_Init
      and @ref  HAL_SRAM_DeInit only when these callbacks are null (not registered beforehand).
      If not, MspInit or MspDeInit are not null, the @ref HAL_SRAM_Init and @ref HAL_SRAM_DeInit
      keep and use the user MspInit/MspDeInit callbacks (registered beforehand)

      Callbacks can be registered/unregistered in READY state only.
      Exception done for MspInit/MspDeInit callbacks that can be registered/unregistered
      in READY or RESET state, thus registered (user) MspInit/DeInit callbacks can be used
      during the Init/DeInit.
      In that case first register the MspInit/MspDeInit user callbacks
      using @ref HAL_SRAM_RegisterCallback before calling @ref HAL_SRAM_DeInit
      or @ref HAL_SRAM_Init function.

      When The compilation define USE_HAL_SRAM_REGISTER_CALLBACKS is set to 0 or
      not defined, the callback registering feature is not available
      and weak (surcharged) callbacks are used.

  @endverbatim
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

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/** @addtogroup STM32H7xx_HAL_Driver
  * @{
  */

/** @defgroup SRAM SRAM
  * @brief SRAM driver modules
  * @{
  */
#ifdef HAL_SRAM_MODULE_ENABLED
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup SRAM_Exported_Functions SRAM Exported Functions
  * @{
  */

/** @defgroup SRAM_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief    Initialization and Configuration functions.
  *
  @verbatim
  ==============================================================================
           ##### SRAM Initialization and de_initialization functions #####
  ==============================================================================
    [..]  This section provides functions allowing to initialize/de-initialize
          the SRAM memory

@endverbatim
  * @{
  */

/**
  * @brief  Performs the SRAM device initialization sequence
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  Timing: Pointer to SRAM control timing structure
  * @param  ExtTiming: Pointer to SRAM extended mode timing structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Init(SRAM_HandleTypeDef *hsram, FMC_NORSRAM_TimingTypeDef *Timing, FMC_NORSRAM_TimingTypeDef *ExtTiming)
{
  /* Check the SRAM handle parameter */
  if(hsram == NULL)
  {
     return HAL_ERROR;
  }

#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)

  if(hsram->State == HAL_SRAM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hsram->Lock = HAL_UNLOCKED;

    if(hsram->MspInitCallback == NULL)
    {
      hsram->MspInitCallback = HAL_SRAM_MspInit;
    }

    /* Init the low level hardware */
    hsram->MspInitCallback(hsram);
  }
#else
  if(hsram->State == HAL_SRAM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hsram->Lock = HAL_UNLOCKED;
    /* Initialize the low level hardware (MSP) */
    HAL_SRAM_MspInit(hsram);
  }
#endif
  /* Initialize SRAM control Interface */
  (void) FMC_NORSRAM_Init(hsram->Instance, &(hsram->Init));  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Initialize SRAM timing Interface */
  (void) FMC_NORSRAM_Timing_Init(hsram->Instance, Timing, hsram->Init.NSBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Initialize SRAM extended mode timing Interface */
  (void) FMC_NORSRAM_Extended_Timing_Init(hsram->Extended, ExtTiming, hsram->Init.NSBank,  hsram->Init.ExtendedMode);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Enable the NORSRAM device */
  __FMC_NORSRAM_ENABLE(hsram->Instance, hsram->Init.NSBank);

  /* Enable FMC IP */
  __FMC_ENABLE();

  return HAL_OK;
}

/**
  * @brief  Performs the SRAM device De-initialization sequence.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef  HAL_SRAM_DeInit(SRAM_HandleTypeDef *hsram)
{
#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
  if(hsram->MspDeInitCallback == NULL)
  {
    hsram->MspDeInitCallback = HAL_SRAM_MspDeInit;
  }

  /* DeInit the low level hardware */
  hsram->MspDeInitCallback(hsram);
#else
  /* De-Initialize the low level hardware (MSP) */
  HAL_SRAM_MspDeInit(hsram);
#endif
  /* Configure the SRAM registers with their reset values */
  (void) FMC_NORSRAM_DeInit(hsram->Instance, hsram->Extended, hsram->Init.NSBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  hsram->State = HAL_SRAM_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  SRAM MSP Init.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval None
  */
__weak void HAL_SRAM_MspInit(SRAM_HandleTypeDef *hsram)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsram);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_SRAM_MspInit could be implemented in the user file
   */
}

/**
  * @brief  SRAM MSP DeInit.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval None
  */
__weak void HAL_SRAM_MspDeInit(SRAM_HandleTypeDef *hsram)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hsram);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_SRAM_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  DMA transfer complete callback.
  * @param  hmdma: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval None
  */
__weak void HAL_SRAM_DMA_XferCpltCallback(MDMA_HandleTypeDef *hmdma)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hmdma);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_SRAM_DMA_XferCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  DMA transfer complete error callback.
  * @param  hmdma: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval None
  */
__weak void HAL_SRAM_DMA_XferErrorCallback(MDMA_HandleTypeDef *hmdma)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hmdma);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_SRAM_DMA_XferErrorCallback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup SRAM_Exported_Functions_Group2 Input Output and memory control functions
  * @brief    Input Output and memory control functions
  *
  @verbatim
  ==============================================================================
                  ##### SRAM Input and Output functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to use and control the SRAM memory

@endverbatim
  * @{
  */

/**
  * @brief  Reads 8-bit buffer from SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Read_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint8_t* pdstbuffer = pDstBuffer;
  __IO uint8_t * psramaddress = (uint8_t *)pAddress;

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Read data from memory */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint8_t *)psramaddress;
    pdstbuffer++;
    psramaddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Writes 8-bit buffer to SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Write_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint8_t* psrcbuffer = pSrcBuffer;
  __IO uint8_t * psramaddress = (uint8_t *)pAddress;

  /* Check the SRAM controller state */
  if(hsram->State == HAL_SRAM_STATE_PROTECTED)
  {
    return  HAL_ERROR;
  }

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint8_t *)psramaddress = *psrcbuffer;
    psrcbuffer++;
    psramaddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Reads 16-bit buffer from SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Read_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint16_t *pdstbuffer = pDstBuffer;
  __IO uint16_t * psramaddress = (uint16_t *)pAddress;

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Read data from memory */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint16_t *)psramaddress;
    pdstbuffer++;
    psramaddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Writes 16-bit buffer to SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Write_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint16_t *psrcbuffer = pSrcBuffer;
  __IO uint16_t * psramaddress = (uint16_t *)pAddress;

  /* Check the SRAM controller state */
  if(hsram->State == HAL_SRAM_STATE_PROTECTED)
  {
    return  HAL_ERROR;
  }

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint16_t *)psramaddress = *psrcbuffer;
    psrcbuffer++;
    psramaddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Reads 32-bit buffer from SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Read_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint32_t *pdstbuffer = pDstBuffer;
  uint32_t *paddress = pAddress;

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Read data from memory */
  for(; buffersize != 0U; buffersize--)
  {
    *pdstbuffer = *(__IO uint32_t *)paddress;
    pdstbuffer++;
    paddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Writes 32-bit buffer to SRAM memory.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Write_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize)
{
  uint32_t buffersize = BufferSize;
  uint32_t *psrcbuffer = pSrcBuffer;
  uint32_t *paddress = pAddress;

  /* Check the SRAM controller state */
  if(hsram->State == HAL_SRAM_STATE_PROTECTED)
  {
    return  HAL_ERROR;
  }

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Write data to memory */
  for(; buffersize != 0U; buffersize--)
  {
    *(__IO uint32_t *)paddress = *psrcbuffer;
    psrcbuffer++;
    paddress++;
  }

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Reads a Words data from the SRAM memory using DMA transfer.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to read start address
  * @param  pDstBuffer: Pointer to destination buffer
  * @param  BufferSize: Size of the buffer to read from memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Read_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer, uint32_t BufferSize)
{
  HAL_StatusTypeDef status;

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Configure DMA user callbacks */
  hsram->hmdma->XferCpltCallback  = HAL_SRAM_DMA_XferCpltCallback;
  hsram->hmdma->XferErrorCallback = HAL_SRAM_DMA_XferErrorCallback;

  /* Enable the DMA Stream */
  status = HAL_MDMA_Start_IT(hsram->hmdma, (uint32_t)pAddress, (uint32_t)pDstBuffer, (uint32_t)(BufferSize * 4U), 1);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return status;
}

/**
  * @brief  Writes a Words data buffer to SRAM memory using DMA transfer.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @param  pAddress: Pointer to write start address
  * @param  pSrcBuffer: Pointer to source buffer to write
  * @param  BufferSize: Size of the buffer to write to memory
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_Write_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer, uint32_t BufferSize)
{
  HAL_StatusTypeDef status;

  /* Check the SRAM controller state */
  if(hsram->State == HAL_SRAM_STATE_PROTECTED)
  {
    return  HAL_ERROR;
  }

  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Configure DMA user callbacks */
  hsram->hmdma->XferCpltCallback  = HAL_SRAM_DMA_XferCpltCallback;
  hsram->hmdma->XferErrorCallback = HAL_SRAM_DMA_XferErrorCallback;

  /* Enable the DMA Stream */
  status = HAL_MDMA_Start_IT(hsram->hmdma, (uint32_t)pSrcBuffer, (uint32_t)pAddress, (uint32_t)(BufferSize * 4U), 1);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return status;
}

#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User SRAM Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param hsram : SRAM handle
  * @param CallbackID : ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_SRAM_MSP_INIT_CB_ID       SRAM MspInit callback ID
  *          @arg @ref HAL_SRAM_MSP_DEINIT_CB_ID     SRAM MspDeInit callback ID
  * @param pCallback : pointer to the Callback function
  * @retval status
  */
HAL_StatusTypeDef HAL_SRAM_RegisterCallback (SRAM_HandleTypeDef *hsram, HAL_SRAM_CallbackIDTypeDef CallbackId, pSRAM_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(pCallback == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hsram);

  if((hsram->State == HAL_SRAM_STATE_READY) || (hsram->State == HAL_SRAM_STATE_RESET))
  {
    switch (CallbackId)
    {
    case HAL_SRAM_MSP_INIT_CB_ID :
      hsram->MspInitCallback = pCallback;
      break;
    case HAL_SRAM_MSP_DEINIT_CB_ID :
      hsram->MspDeInitCallback = pCallback;
      break;
    default :

      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsram);
  return status;
}

/**
  * @brief  Unregister a User SRAM Callback
  *         SRAM Callback is redirected to the weak (surcharged) predefined callback
  * @param hsram : SRAM handle
  * @param CallbackID : ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_SRAM_MSP_INIT_CB_ID       SRAM MspInit callback ID
  *          @arg @ref HAL_SRAM_MSP_DEINIT_CB_ID     SRAM MspDeInit callback ID
  * @retval status
  */
HAL_StatusTypeDef HAL_SRAM_UnRegisterCallback (SRAM_HandleTypeDef *hsram, HAL_SRAM_CallbackIDTypeDef CallbackId)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hsram);

  if((hsram->State == HAL_SRAM_STATE_READY) || (hsram->State == HAL_SRAM_STATE_RESET))
  {
    switch (CallbackId)
    {
    case HAL_SRAM_MSP_INIT_CB_ID :
      hsram->MspInitCallback = HAL_SRAM_MspInit;
      break;
    case HAL_SRAM_MSP_DEINIT_CB_ID :
      hsram->MspDeInitCallback = HAL_SRAM_MspDeInit;
      break;
    default :

      /* update return status */
      status =  HAL_ERROR;
      break;
    }
  }
  else
  {
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hsram);
  return status;
}
#endif

/**
  * @}
  */

/** @defgroup SRAM_Exported_Functions_Group3 Control functions
 *  @brief   Control functions
 *
@verbatim
  ==============================================================================
                        ##### SRAM Control functions #####
  ==============================================================================
  [..]
    This subsection provides a set of functions allowing to control dynamically
    the SRAM interface.

@endverbatim
  * @{
  */

/**
  * @brief  Enables dynamically SRAM write operation.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Enable(SRAM_HandleTypeDef *hsram)
{
  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Enable write operation */
  (void) FMC_NORSRAM_WriteOperation_Enable(hsram->Instance, hsram->Init.NSBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @brief  Disables dynamically SRAM write operation.
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Disable(SRAM_HandleTypeDef *hsram)
{
  /* Process Locked */
  __HAL_LOCK(hsram);

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_BUSY;

  /* Disable write operation */
  (void) FMC_NORSRAM_WriteOperation_Disable(hsram->Instance, hsram->Init.NSBank);  /* return value ignored(casted to void ) to prevent MISRA-2012 17.7 error as this functions return is always HAL_OK */

  /* Update the SRAM controller state */
  hsram->State = HAL_SRAM_STATE_PROTECTED;

  /* Process unlocked */
  __HAL_UNLOCK(hsram);

  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup SRAM_Exported_Functions_Group4 Peripheral State functions
 *  @brief   Peripheral State functions
 *
@verbatim
  ==============================================================================
                      ##### SRAM State functions #####
  ==============================================================================
  [..]
    This subsection permits to get in run-time the status of the SRAM controller
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Returns the SRAM controller state
  * @param  hsram: pointer to a SRAM_HandleTypeDef structure that contains
  *                the configuration information for SRAM module.
  * @retval HAL state
  */
HAL_SRAM_StateTypeDef HAL_SRAM_GetState(SRAM_HandleTypeDef *hsram)
{
  return hsram->State;
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* HAL_SRAM_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
