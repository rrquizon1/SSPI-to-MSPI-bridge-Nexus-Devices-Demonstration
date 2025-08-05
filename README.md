# SSPI to MSPI Bridge

This is a demonstration of Lattice Nexus Devices' SSPI to MSPI bridge using Raspberry Pi. The Lattice Nexus SSPI to MSPI bridge is discussed in the ([Lattice Nexus sysCONFIG Document ](https://www.latticesemi.com/view_document?document_id=52790))

The SSPI to MSPI bridge is illustrated below for our sysCONFIG document:
<img width="951" height="613" alt="image" src="https://github.com/user-attachments/assets/e4296707-f22a-4a28-98fc-3218f35b89f2" />

To activate the SSPI to MSPI bridge you need to send the LSC_PROG_SPI command(0x3A 00 00 00) to open the bridge. For illustration see below:
<img width="1191" height="551" alt="image" src="https://github.com/user-attachments/assets/794c7929-0bfa-43d5-8253-00bd2305a83a" />



The example in this repository programs a bitstream image for Lattice Certus Pro NX Evaluation Board just to illustrate the SSPI to MSPI Bridge. It contains the following files:

* main.c - Contains SPI Flash Programming Flow
* spi.c- contains commands for SPI Flash Programmign via SSPI2MSPI BRidge
* spi_data.c- Contains bitstream data

The SSPI to MSPI Bridge is a simple but useful feature that makes it easier to update bitstream image or user data in the SPI Flash

## Some Notes
* SSPI of Lattice Nexus Devices are shared with JTAG pins. Disable JTAG via JTAGEN pin to activate SSPI mode.
* SPI FLash devices might have different commands for erasing or writing. Consult the datasheet of your target SPI Flash.

## Sample Terminal Run
<img width="639" height="462" alt="image" src="https://github.com/user-attachments/assets/f6bbc967-3aa0-4fcb-8ee8-a84a8962c992" />
