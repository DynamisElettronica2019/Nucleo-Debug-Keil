/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
#define NUCLEO_F7_ID (uint16_t) 510
#include "GCU_Model_genCode.h"


CAN_FilterTypeDef CAN_Filter_Config;
uint8_t GCU_Packet_Data[8];
CAN_TxHeaderTypeDef GCU_Packet_Header;

//static CAN_FilterTypeDef CAN_Filter_Config;
static CAN_RxHeaderTypeDef CAN_Received_0_Message_Header;
static CAN_RxHeaderTypeDef CAN_Received_1_Message_Header;
static uint8_t CAN_Received_0_Message_Data[8];
static uint8_t CAN_Received_1_Message_Data[8];

static uint8_t nucleo_F7_Packet_Data[8];
static CAN_TxHeaderTypeDef nucleo_F7_Packet_Header;
/* USER CODE END 0 */

CAN_HandleTypeDef hcan1;

/* CAN1 init function */
void MX_CAN1_Init(void)
{

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 6;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_2TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_6TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN1 GPIO Configuration    
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(CAN1_TX_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN1_TX_IRQn);
    HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();
  
    /**CAN1 GPIO Configuration    
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN1_TX_IRQn);
    HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

void CAN1_Unpack(void)
{
	
}	

void CAN1_Filter_Setup(void)
{
	/*mittente: NUCLEOF4
	Id:     (0011111xxxx)
	Mask: 0x1DE0   (0111 1111 0000)
	Filter: 0x5E0  (0001 1111 0000)*/
	
	CAN_Filter_Config.FilterBank = 0;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
	CAN_Filter_Config.FilterIdHigh = (0x1F0 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = (0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
	CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
		
	HAL_CAN_ConfigFilter(&hcan1, &CAN_Filter_Config);
}	


void CAN1_Start(void)
{
	CAN1_Filter_Setup();
	
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_TX_MAILBOX_EMPTY);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO1_MSG_PENDING);
	HAL_CAN_Start(&hcan1);
}	


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CAN_Received_0_Message_Header, CAN_Received_0_Message_Data);
	
	for(int i=0; i<DIM; i++)
		rtU.CAN[i] = 0;
	
	rtU.CAN[0] |= CAN_Received_0_Message_Header.StdId >>8;
	rtU.CAN[1] |= CAN_Received_0_Message_Header.StdId;
	
	for(int i=2; i<DIM; i++)
		rtU.CAN[i] = CAN_Received_0_Message_Data[i];
	
	if(rtU.SelectMode == CAN_READ_MODE)
	{	
		//qui va inserito lo step per l'interpretazione del messaggio
		GCU_Model_genCode_step2();
	}
	
	HAL_GPIO_TogglePin(GPIOB, GreenLed_Pin);	
	//CAN1_Send_Nucleo_F7_Packet();
}

extern void CAN1_Send_Nucleo_F7_Packet(void)
{
	uint32_t nucleo_F7_Packet_Mailbox;
	nucleo_F7_Packet_Header.StdId = NUCLEO_F7_ID;
  nucleo_F7_Packet_Header.RTR = CAN_RTR_DATA;
  nucleo_F7_Packet_Header.IDE = CAN_ID_STD;
  nucleo_F7_Packet_Header.DLC = 8;
  nucleo_F7_Packet_Header.TransmitGlobalTime = DISABLE;
  nucleo_F7_Packet_Data[0] = 6;
  nucleo_F7_Packet_Data[1] = 0;
  nucleo_F7_Packet_Data[2] = 10;
  nucleo_F7_Packet_Data[3] = 0;
  nucleo_F7_Packet_Data[4] = 0;
  nucleo_F7_Packet_Data[5] = 6;
	nucleo_F7_Packet_Data[6] = 0;
  nucleo_F7_Packet_Data[7] = 5;
	
	HAL_CAN_AddTxMessage(&hcan1, &nucleo_F7_Packet_Header, nucleo_F7_Packet_Data, &nucleo_F7_Packet_Mailbox);
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
