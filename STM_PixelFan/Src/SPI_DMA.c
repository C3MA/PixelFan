/*
 * SPI_DMA.c
 *
 *  Created on: Jan 13, 2020
 *      Author: Enny
 */

#include "SPI_DMA.h"
#include "stm32g0xx_hal.h"

void spiDmaStartTransmission(uint8_t *pData, uint16_t size)
{
	SPI1->CR2 |= SPI_CR2_TXDMAEN;			//Transmit from DMA enable

	DMA1_Channel1->CCR &= ~DMA_CCR_EN;

	DMA1_Channel1->CNDTR = size;
	DMA1_Channel1->CPAR = (uint32_t)(&(SPI1->DR));		//peripheral address
	DMA1_Channel1->CMAR = (uint32_t)pData;		//memory Address

	//TIM15->DIER &= ~TIM_DIER_UDE;		//Update DMA Request
	//DMAMUX1_Channel1->CCR = 0;

	//DMAMUX1_RequestGenerator1->RGCR &= ~DMAMUX_RGxCR_GE;

	DMA1_Channel1->CCR |= (DMA_MINC_ENABLE | DMA_CCR_DIR | DMA_CCR_TCIE | DMA_CCR_EN);	//memory increment enable

	//DMA1_Channel1->CCR |= DMA_CCR_DIR;		//Direction: Memory to peripheral
	//DMA1_Channel1->CCR |= DMA_CCR_TCIE;		//Transfer complete interrupt enable
	//DMA1_Channel1->CCR |= DMA_CCR_EN;	//Channel enable
}

void spiDmaStartTransmissionByTimer(uint8_t *pData, uint16_t size)
{
	SPI1->CR2 |= SPI_CR2_TXDMAEN;			//Transmit from DMA enable

	DMA1_Channel1->CCR &= ~DMA_CCR_EN;

	DMA1_Channel1->CNDTR = size;
	DMA1_Channel1->CPAR = &SPI1->DR;		//peripheral address
	DMA1_Channel1->CMAR = pData;		//memory Address

	TIM15->DIER |= TIM_DIER_UDE;		//Update DMA Request
	DMAMUX1_Channel1->CCR = 43 | DMAMUX_CxCR_EGE;

	DMAMUX1_RequestGenerator1->RGCR |= DMAMUX_RGxCR_GE;

	DMA1_Channel1->CCR |= (DMA_MINC_ENABLE | DMA_CCR_DIR | DMA_CCR_TCIE | DMA_CCR_EN);	//memory increment enable

	//DMA1_Channel1->CCR |= DMA_CCR_DIR;		//Direction: Memory to peripheral
	//DMA1_Channel1->CCR |= DMA_CCR_TCIE;		//Transfer complete interrupt enable
	//DMA1_Channel1->CCR |= DMA_CCR_EN;	//Channel enable
}

void spi2DmaStart(uint8_t *pData, uint16_t size)
{
	SPI2->CR2 |= SPI_CR2_RXDMAEN;			//SPI Receive to DMA enable

	//SPI2->CR2 |= SPI_CR2_RXNEIE;

	DMA1_Channel2->CCR &= ~DMA_CCR_EN;

	DMA1_Channel2->CNDTR = size;
	DMA1_Channel2->CPAR = &SPI2->DR;		//peripheral address
	DMA1_Channel2->CMAR = pData;		//memory Address
	DMA1_Channel2->CCR |= DMA_CCR_TCIE;		//Transfer complete interrupt enable
	DMA1_Channel2->CCR |= DMA_CCR_CIRC;		//Transfer complete interrupt enable
	DMA1_Channel2->CCR &= ~DMA_CCR_PSIZE;		//peripheral size = 8 Bit
	DMA1_Channel2->CCR &= ~DMA_CCR_MSIZE;		//memory size = 8 Bit

	DMA1_Channel2->CCR |= (DMA_MINC_ENABLE | DMA_CCR_EN);	//memory increment enable

	SPI2->CR1 |= SPI_CR1_SPE;		//enable SPI

}
