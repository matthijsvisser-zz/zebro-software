//--------------------------------------------------------------
// File     : clk.c
// Datum    : 2015.03.08
// Version  : 1.0
// Author   : Menno
// CPU      : Atxmega128
// Function : set internal clock to 32MHz
//--------------------------------------------------------------

#include <avr/io.h>
#include "clk.h"

void SystemClock_init(void)
{
	CCP			 =	CCP_IOREG_gc;
	OSC.CTRL	|=	OSC_RC32MEN_bm;
	while(!(OSC.STATUS & OSC_RC32MRDY_bm));
	CCP			 =	CCP_IOREG_gc;
	CLK.CTRL	 =	CLK_SCLKSEL_RC32M_gc;
}
