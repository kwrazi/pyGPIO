/*
 *
 * This file is part of pyA20.
 * mapping.h is python GPIO extension.
 *
 * Copyright (c) 2014 Stefan Mavrodiev @ OLIMEX LTD, <support@olimex.com>
 *
 * pyA20 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * mapping.h from: https://github.com/wdmomoxx/orangepi_ZERO_gpio_pyH2
 *
 */

#ifndef __MAPPING_H
#define __MAPPING_H

#include "gpio_lib.h"

/**
Structure that describe all gpio
*/
typedef struct _pin {
    char name[10];          // The processor pin
    int offset;             // Memory offset for the pin
    int pin_number;         // Number on the connector
}pin_t;

typedef struct _gpio {
    char connector_name[10];
    pin_t pins[41];
}gpio_t;


gpio_t gpio[] = {

/*
			J1		  	 J2
(UART0_RX)		|2|      microUSB        |1|	5V	
(UART0_TX)		|·|	 nicroSD	 |·|	5V	
GND			|·|	 		 |·|	3.3V
GPIO13 (TWI_SCL)	|·|			 |·|	GND	
GPIO12 (TWI_SDA)	|·|			 |·| 	GPIO18 (IOL11)
GPIO3 (SPI1_CS)		|·|			 |·|	GPIO16 (IOG11)
GPIO2 (SPI1_CLK)	|·|			 |·|	DM3 D-
GPIO0 (SPI1_MISO)	|·|			 |·|	DP3 D+
GPIO7 (SPI1_MOSI)	|·|			 |·|	DM2 D-	
GPIO9 (UART1_RX)	|·|			 |·|	DP2 D+
GPIO8 (UART1_TX)	|·|			 |·|	RDN
(CVBS)			|·|			 |·|	RDP	
(LINEOUT_L)		|·|			 |·|	TXN
(LINEOUT_R)		|·|			 |·|	TXP
(MICP)			|·|			 |·|	LED-LINK
(MICN)			|·|			 |·|	LED-SPD

*/  {"J1",
        {
            {   "GPIO13",  SUNXI_GPA(11),  8  },
            {   "GPIO12",  SUNXI_GPA(12), 10  },
            {   "GPIO3",   SUNXI_GPA(13), 12  },
            {   "GPIO2",   SUNXI_GPA(14), 14  },
            {   "GPIO0",   SUNXI_GPA(16), 16  },			
            {   "GPIO7",   SUNXI_GPA(15), 18  },
	    {   "GPIO9",   SUNXI_GPG(7),  20  },
            {   "GPIO8",   SUNXI_GPG(6),  22  },
            {
                {   0,  0,  0}
            },
        }
    },
	{"J2",
        {
            {   "GPIO18",  SUNXI_GPL(11),   9  },
	    {   "GPIO16",  SUNXI_GPG(11),  11  },
            {
                {   0,  0,  0}
            },
        }
    },	

/*
    #define PIN_PG0		SUNXI_GPG(0)
*/  {"LED",
        {
			{   "POWER_LED",   SUNXI_GPL(10),  1   },
			{   "STATUS_LED",  SUNXI_GPA(10),  2  },
            {
                {   0,  0,  0}
            },
        }
    },
};



#endif
