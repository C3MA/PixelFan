#ifndef SPI_DMA_H
#define SPI_DMA_H

#include <stdint.h>

void spiDmaStartTransmission(uint8_t *pData, uint16_t size);
void spiDmaStartTransmissionByTimer(uint8_t *pData, uint16_t size);

void spi2DmaStart(uint8_t *pData, uint16_t size);

#endif
