#include <stdio.h>
#include <stdlib.h>



typedef struct {
    u_int8_t data; 
    u_int8_t enable : 1; 
    u_int8_t ready : 1; 
    

} SPI_REGS; 


volatile *SPI_Register = (SPI_REGS *)malloc(sizeof(SPI_REGS)); 

void spi_init(); 
void spi_transmit(SPI_REGS *data ); 
SPI_REGS *spi_receive(); 
void spi_wait();

int main(){

    spi_init(); 

    SPI_REGS dummyData = { .data = 0xFF, .enable = 1 , .ready = 1 };
    spi_transmit(&dummyData); 

    SPI_REGS *received_Data = spi_receive(); 
        
    return 0; 
}

void spi_wait(){
    while (! SPI_Register->ready)
    {
        /* wait */
    }
}


void spi_init(){

    spi_wait();
    
    SPI_Register->enable = 0b1; 

    spi_wait();
    
} 

void spi_transmit(SPI_REGS *data ){
    spi_wait();

    SPI_Register->data = data->data; 

    spi_wait();
}
