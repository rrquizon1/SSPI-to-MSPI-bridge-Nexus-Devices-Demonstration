#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <gpiod.h>
#include "spi_data.h"
#include "spi.h"





struct gpiod_line *cs;
struct gpiod_line *prgrmn;

#define num_chunks (g_iDataSize+3-1)/3

int main() {
     unsigned int start_address = 0x000000; //start address where to write
     unsigned char data_read[g_iDataSize];
    spi_init(2000*1024,&cs,&prgrmn);
    gpiod_line_set_value(prgrmn, 0);// programn pulled low
    usleep(50);// Wait time till initn goes high

     activation_key();// Send Slave SPI activation key
     
   
    usleep(1000);
    // FPGA Device ID read 	
    device_id();
    usleep(1000);
    
    //SPI Flash Device ID Read
    device_id_spi_bridge();
    //Write Enable Command
    write_enable();
    usleep(1000);
    //Bulk Erase
    chip_erase();
    
    usleep(100); 
   // sleep(1);
       SR_check();

    
    
    
   //Program FPGA bitstream
    write_data(g_pucDataArray,g_iDataSize,start_address );
    SR_check();
    //Read Data
    read_data(data_read,g_iDataSize,start_address);
    
    //Verification Process
    verify_data(data_read, g_pucDataArray, g_iDataSize);
  
    //Refresh
    refresh();


    rbpi_exit();
	
	
}
