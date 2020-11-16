/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"


#include <stdio.h>
#include "platform.h"
#include "xil_cache.h"


int main()
{
	init_platform();
	Xil_DCacheDisable();
	uint32_t * index = 0x43C00000;
	uint32_t * init = 0x43C00004;
	uint64_t * n0 = 0x00000010;
	uint64_t * n1 = 0x00000018;
	uint64_t * n2 = 0x00000020;
	uint64_t * n00 = 0x00000100;
	uint64_t * n01 = 0x00000108;
	uint64_t * n02 = 0x00000110;
	uint64_t * n03 = 0x00000118;
	int i = 0;
	*index = (uint32_t) 0;
	*n0 = (uint64_t) 1;
	*n1 = (uint64_t) 2;
	*n2 = (uint64_t) 0x0003000400000100;
	*n00 = (uint64_t) 8;
	*n01 = (uint64_t) 6;
	*n02 = (uint64_t) 7;
	*n03 = (uint64_t) 0x0002000400000000;
    printf("Start\n\r");
    while(1){
    	*init = (uint32_t) 1;
    	*init = (uint32_t) 0;
    }
    cleanup_platform();
    return 0;
}

