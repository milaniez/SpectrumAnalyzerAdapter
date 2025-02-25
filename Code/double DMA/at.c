/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/23/2013
Author  : MzZ
Company : MzZ
Comments: 


Chip type               : ATxmega128A1
Program type            : Application
AVR Core Clock frequency: 32.000000 MHz
Memory model            : Small
Data Stack size         : 2048
*****************************************************/

// I/O Registers definitions
#include <io.h>

// Delay functions
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Declare your global variables here

// System Clocks initialization
void system_clocks_init(void)
{
unsigned char n,s;

// Optimize for speed
#pragma optsize- 
// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// External 16000.000 kHz oscillator initialization
OSC.XOSCCTRL=OSC_FRQRANGE_12TO16_gc | OSC_XOSCSEL_XTAL_16KCLK_gc;
// Enable the external oscillator
OSC.CTRL|=OSC_XOSCEN_bm;

// Wait for the external oscillator to stabilize
while ((OSC.STATUS & OSC_XOSCRDY_bm)==0);

// PLL initialization
// PLL clock cource: External Osc. or Clock
// PLL multiplication factor: 2
// PLL frequency: 32.000000 MHz
// Set the PLL clock source and multiplication factor
n=(OSC.PLLCTRL & (~(OSC_PLLSRC_gm | OSC_PLLFAC_gm))) |
	OSC_PLLSRC_XOSC_gc | 2;
CCP=CCP_IOREG_gc;
OSC.PLLCTRL=n;
// Enable the PLL
OSC.CTRL|=OSC_PLLEN_bm;

// System Clock prescaler A division factor: 1
// System Clock prescalers B & C division factors: B:1, C:1
// ClkPer4: 32000.000 kHz
// ClkPer2: 32000.000 kHz
// ClkPer:  32000.000 kHz
// ClkCPU:  32000.000 kHz
n=(CLK.PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm))) |
	CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc;
CCP=CCP_IOREG_gc;
CLK.PSCTRL=n;

// Wait for the PLL to stabilize
while ((OSC.STATUS & OSC_PLLRDY_bm)==0);

// Select the system clock source: Phase Locked Loop
n=(CLK.CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_PLL_gc;
CCP=CCP_IOREG_gc;
CLK.CTRL=n;

// Disable the unused oscillators: 2 MHz, 32 MHz, internal 32 kHz
OSC.CTRL&= ~(OSC_RC2MEN_bm | OSC_RC32MEN_bm | OSC_RC32KEN_bm);

// Peripheral Clock output: Disabled
PORTCFG.CLKEVOUT=(PORTCFG.CLKEVOUT & (~PORTCFG_CLKOUT_gm)) | PORTCFG_CLKOUT_OFF_gc;

// Restore interrupts enabled/disabled state
SREG=s;
// Restore optimization for size if needed
#pragma optsize_default
}

// Ports initialization
void ports_init(void)
{
// PORTA initialization
// OUT register
PORTA.OUT=0x00;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Input
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTA.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTA.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTA.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTA.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTA.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTA.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTA.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTA.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTA.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTA.INTCTRL=(PORTA.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTA.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTA.INT1MASK=0x00;

// PORTB initialization
// OUT register
PORTB.OUT=0x00;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Input
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTB.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTB.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTB.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTB.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTB.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTB.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTB.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTB.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTB.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTB.INTCTRL=(PORTB.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTB.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTB.INT1MASK=0x00;

// PORTC initialization
// OUT register
PORTC.OUT=0x00;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Input
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTC.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTC.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTC.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTC.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTC.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTC.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTC.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTC.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTC.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTC.INTCTRL=(PORTC.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTC.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTC.INT1MASK=0x00;

// PORTD initialization
// OUT register
PORTD.OUT=0x0F;
// Bit0: Output
// Bit1: Output
// Bit2: Output
// Bit3: Output
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTD.DIR=0x0F;
// Bit0 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTD.PIN0CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTD.PIN1CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTD.PIN2CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTD.PIN3CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit4 Input/Sense configuration: Sense rising edge
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTD.PIN4CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_RISING_gc;
// Bit5 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit5 Input/Sense configuration: Sense rising edge
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTD.PIN5CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_RISING_gc;
// Bit6 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit6 Input/Sense configuration: Sense rising edge
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTD.PIN6CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_RISING_gc;
// Bit7 Output/Pull configuration: Totempole/Pull-down (on input)
// Bit7 Input/Sense configuration: Sense rising edge
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTD.PIN7CTRL=PORT_OPC_PULLDOWN_gc | PORT_ISC_RISING_gc;
// Interrupt 0 level: High
// Interrupt 1 level: Disabled
PORTD.INTCTRL=(PORTD.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_HI_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: On
// Bit5 pin change interrupt 0: On
// Bit6 pin change interrupt 0: On
// Bit7 pin change interrupt 0: On
PORTD.INT0MASK=0xF0;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTD.INT1MASK=0x00;

// PORTE initialization
// OUT register
PORTE.OUT=0x00;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Input
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTE.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTE.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTE.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTE.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTE.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTE.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTE.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTE.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTE.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTE.INTCTRL=(PORTE.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTE.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTE.INT1MASK=0x00;

// PORTF initialization
// OUT register
PORTF.OUT=0x08;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Output
// Bit4: Input
// Bit5: Input
// Bit6: Input
// Bit7: Input
PORTF.DIR=0x08;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTF.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTF.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTF.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTF.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTF.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTF.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTF.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTF.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTF.INTCTRL=(PORTF.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTF.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTF.INT1MASK=0x00;

// PORTH initialization
// OUT register
PORTH.OUT=0x00;
// Bit0: Output
// Bit1: Output
// Bit2: Output
// Bit3: Output
// Bit4: Output
// Bit5: Output
// Bit6: Output
// Bit7: Output
PORTH.DIR=0xFF;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTH.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTH.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTH.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTH.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTH.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTH.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTH.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTH.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTH.INTCTRL=(PORTH.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTH.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTH.INT1MASK=0x00;

// PORTJ initialization
// OUT register
PORTJ.OUT=0x00;
// Bit0: Output
// Bit1: Output
// Bit2: Output
// Bit3: Output
// Bit4: Output
// Bit5: Output
// Bit6: Output
// Bit7: Output
PORTJ.DIR=0xFF;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTJ.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTJ.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTJ.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTJ.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTJ.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTJ.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTJ.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTJ.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTJ.INTCTRL=(PORTJ.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTJ.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTJ.INT1MASK=0x00;

// PORTK initialization
// OUT register
PORTK.OUT=0x00;
// Bit0: Output
// Bit1: Output
// Bit2: Output
// Bit3: Output
// Bit4: Output
// Bit5: Output
// Bit6: Output
// Bit7: Output
PORTK.DIR=0xFF;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTK.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTK.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTK.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTK.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit4 Output/Pull configuration: Totempole/No
// Bit4 Input/Sense configuration: Sense both edges
// Bit4 inverted: Off
// Bit4 slew rate limitation: Off
PORTK.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit5 Output/Pull configuration: Totempole/No
// Bit5 Input/Sense configuration: Sense both edges
// Bit5 inverted: Off
// Bit5 slew rate limitation: Off
PORTK.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit6 Output/Pull configuration: Totempole/No
// Bit6 Input/Sense configuration: Sense both edges
// Bit6 inverted: Off
// Bit6 slew rate limitation: Off
PORTK.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit7 Output/Pull configuration: Totempole/No
// Bit7 Input/Sense configuration: Sense both edges
// Bit7 inverted: Off
// Bit7 slew rate limitation: Off
PORTK.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTK.INTCTRL=(PORTK.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
// Bit4 pin change interrupt 0: Off
// Bit5 pin change interrupt 0: Off
// Bit6 pin change interrupt 0: Off
// Bit7 pin change interrupt 0: Off
PORTK.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
// Bit4 pin change interrupt 1: Off
// Bit5 pin change interrupt 1: Off
// Bit6 pin change interrupt 1: Off
// Bit7 pin change interrupt 1: Off
PORTK.INT1MASK=0x00;

// PORTQ initialization
// OUT register
PORTQ.OUT=0x00;
// Bit0: Input
// Bit1: Input
// Bit2: Input
// Bit3: Input
PORTQ.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTQ.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTQ.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit2 Output/Pull configuration: Totempole/No
// Bit2 Input/Sense configuration: Sense both edges
// Bit2 inverted: Off
// Bit2 slew rate limitation: Off
PORTQ.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit3 Output/Pull configuration: Totempole/No
// Bit3 Input/Sense configuration: Sense both edges
// Bit3 inverted: Off
// Bit3 slew rate limitation: Off
PORTQ.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTQ.INTCTRL=(PORTQ.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
// Bit2 pin change interrupt 0: Off
// Bit3 pin change interrupt 0: Off
PORTQ.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
// Bit2 pin change interrupt 1: Off
// Bit3 pin change interrupt 1: Off
PORTQ.INT1MASK=0x00;

// PORTR initialization
// OUT register
PORTR.OUT=0x00;
// Bit0: Input
// Bit1: Input
PORTR.DIR=0x00;
// Bit0 Output/Pull configuration: Totempole/No
// Bit0 Input/Sense configuration: Sense both edges
// Bit0 inverted: Off
// Bit0 slew rate limitation: Off
PORTR.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Bit1 Output/Pull configuration: Totempole/No
// Bit1 Input/Sense configuration: Sense both edges
// Bit1 inverted: Off
// Bit1 slew rate limitation: Off
PORTR.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
// Interrupt 0 level: Disabled
// Interrupt 1 level: Disabled
PORTR.INTCTRL=(PORTR.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
// Bit0 pin change interrupt 0: Off
// Bit1 pin change interrupt 0: Off
PORTR.INT0MASK=0x00;
// Bit0 pin change interrupt 1: Off
// Bit1 pin change interrupt 1: Off
PORTR.INT1MASK=0x00;
}

// Virtual Ports initialization
void vports_init(void)
{
// PORTA mapped to VPORT0
// PORTB mapped to VPORT1
PORTCFG.VPCTRLA=PORTCFG_VP1MAP_PORTB_gc | PORTCFG_VP0MAP_PORTA_gc;
// PORTC mapped to VPORT2
// PORTD mapped to VPORT3
PORTCFG.VPCTRLB=PORTCFG_VP3MAP_PORTD_gc | PORTCFG_VP2MAP_PORTC_gc;
}

// Disable a Timer/Counter type 0
void tc0_disable(TC0_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=(ptc->CTRLA & (~TC0_CLKSEL_gm)) | TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

// Disable a Timer/Counter type 1
void tc1_disable(TC1_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=(ptc->CTRLA & (~TC1_CLKSEL_gm)) | TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

// Global variables
#define radix   9
#define fft_N   ((unsigned int)(0x01 << radix))
#define Vref    2.0

typedef struct
        {
            float real;
            float imag;
        } complex;

union _data_unifier_
{
    complex fft_results[fft_N];
    signed int adc_data[fft_N];
    unsigned char adc_bytes[fft_N*4];
    float fft_abs[fft_N];
    unsigned char fft_abs_uc[fft_N << 1];
} fft_adc;

//______________________________________________________________SAMPLING_FUNCTIONS_&_VARIABLES_&_INTERRUPTS_____________________


// Initializations

// Timer/Counter TCD0 initialization (Sampling commence)
void tcd0_init(void)
{
unsigned char s;

// Note: the correct PORTD direction for the Compare Channels outputs
// is configured in the ports_init function

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc0_disable(&TCD0);
// Clock source: Peripheral Clock/1024
TCD0.CTRLA=(TCD0.CTRLA & (~TC0_CLKSEL_gm)) | TC_CLKSEL_DIV1024_gc;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
// Compare/Capture on channel C: Off
// Compare/Capture on channel D: Off
TCD0.CTRLB=(TCD0.CTRLB & (~(TC0_CCAEN_bm | TC0_CCBEN_bm | TC0_CCCEN_bm | TC0_CCDEN_bm | TC0_WGMODE_gm))) |
	TC_WGMODE_NORMAL_gc;

// Capture event source: None
// Capture event action: None
TCD0.CTRLD=(TCD0.CTRLD & (~(TC0_EVACT_gm | TC0_EVSEL_gm))) |
	TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Overflow interrupt: Medium Level
// Error interrupt: Disabled
TCD0.INTCTRLA=(TCD0.INTCTRLA & (~(TC0_ERRINTLVL_gm | TC0_OVFINTLVL_gm))) |
	TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_MED_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
// Compare/Capture channel C interrupt: Disabled
// Compare/Capture channel D interrupt: Disabled
TCD0.INTCTRLB=(TCD0.INTCTRLB & (~(TC0_CCDINTLVL_gm | TC0_CCCINTLVL_gm | TC0_CCBINTLVL_gm | TC0_CCAINTLVL_gm))) |
	TC_CCDINTLVL_OFF_gc | TC_CCCINTLVL_OFF_gc | TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESD.CTRL&= ~HIRES_HREN0_bm;

// Clear the interrupt flags
TCD0.INTFLAGS=TCD0.INTFLAGS;
// Set counter register
TCD0.CNT=0x0000;
// Set period register
TCD0.PER=0x7A11;
// Set channel A Compare/Capture register
TCD0.CCA=0x0000;
// Set channel B Compare/Capture register
TCD0.CCB=0x0000;
// Set channel C Compare/Capture register
TCD0.CCC=0x0000;
// Set channel D Compare/Capture register
TCD0.CCD=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}
inline void sampling_commence_disable (void)
{
    TCD0.CTRLA = 0x00;
    TCD0.CNT = 0x00;
    TCD0.INTFLAGS = 0x01;
}
inline void sampling_commence_enable (void)
{
    TCD0.CTRLA = TC_CLKSEL_DIV1024_gc;
}

#define SAMPLING_TIMER_PER  TCC0.PER
// Timer/Counter TCC0 initialization (ADC trigger timer)
void tcc0_init(void)
{
unsigned char s;
unsigned char n;

// Note: the correct PORTC direction for the Compare Channels outputs
// is configured in the ports_init function

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc0_disable(&TCC0);
// Clock source: Peripheral Clock/1
TCC0.CTRLA=(TCC0.CTRLA & (~TC0_CLKSEL_gm)) | TC_CLKSEL_DIV1_gc;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
// Compare/Capture on channel C: Off
// Compare/Capture on channel D: Off
TCC0.CTRLB=(TCC0.CTRLB & (~(TC0_CCAEN_bm | TC0_CCBEN_bm | TC0_CCCEN_bm | TC0_CCDEN_bm | TC0_WGMODE_gm))) |
	TC_WGMODE_NORMAL_gc;

// Capture event source: None
// Capture event action: None
TCC0.CTRLD=(TCC0.CTRLD & (~(TC0_EVACT_gm | TC0_EVSEL_gm))) |
	TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Overflow interrupt: Disabled
// Error interrupt: Disabled
TCC0.INTCTRLA=(TCC0.INTCTRLA & (~(TC0_ERRINTLVL_gm | TC0_OVFINTLVL_gm))) |
	TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_OFF_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
// Compare/Capture channel C interrupt: Disabled
// Compare/Capture channel D interrupt: Disabled
TCC0.INTCTRLB=(TCC0.INTCTRLB & (~(TC0_CCDINTLVL_gm | TC0_CCCINTLVL_gm | TC0_CCBINTLVL_gm | TC0_CCAINTLVL_gm))) |
	TC_CCDINTLVL_OFF_gc | TC_CCCINTLVL_OFF_gc | TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESC.CTRL&= ~HIRES_HREN0_bm;

// Advanced Waveform Extension initialization
// Optimize for speed
#pragma optsize- 
// Disable locking the AWEX configuration registers just to be sure
n=MCU.AWEXLOCK & (~MCU_AWEXCLOCK_bm);
CCP=CCP_IOREG_gc;
MCU.AWEXLOCK=n;
// Restore optimization for size if needed
#pragma optsize_default

// Pattern generation: Off
// Dead time insertion: Off
AWEXC.CTRL&= ~(AWEX_PGM_bm | AWEX_CWCM_bm | AWEX_DTICCDEN_bm | AWEX_DTICCCEN_bm | AWEX_DTICCBEN_bm | AWEX_DTICCAEN_bm);

// Fault protection initialization
// Fault detection on OCD Break detection: On
// Fault detection restart mode: Latched Mode
// Fault detection action: None (Fault protection disabled)
AWEXC.FDCTRL=(AWEXC.FDCTRL & (~(AWEX_FDDBD_bm | AWEX_FDMODE_bm | AWEX_FDACT_gm))) |
	AWEX_FDACT_NONE_gc;
// Fault detect events: 
// Event channel 0: Off
// Event channel 1: Off
// Event channel 2: Off
// Event channel 3: Off
// Event channel 4: Off
// Event channel 5: Off
// Event channel 6: Off
// Event channel 7: Off
AWEXC.FDEVMASK=0b00000000;
// Make sure the fault detect flag is cleared
AWEXC.STATUS|=AWEXC.STATUS & AWEX_FDF_bm;

// Clear the interrupt flags
TCC0.INTFLAGS=TCC0.INTFLAGS;
// Set counter register
TCC0.CNT=0x0000;
// Set period register
TCC0.PER=0x000F;
// Set channel A Compare/Capture register
TCC0.CCA=0x0000;
// Set channel B Compare/Capture register
TCC0.CCB=0x0000;
// Set channel C Compare/Capture register
TCC0.CCC=0x0000;
// Set channel D Compare/Capture register
TCC0.CCD=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}
unsigned char TCC0_CTRLA_temp = 0x00;
inline void sampling_disable (void)
{
    TCC0_CTRLA_temp = TCC0.CTRLA;
    TCC0.CTRLA = 0x00;
    TCC0.CNT = 0x00;
}
inline void sampling_enable (void)
{
    TCC0.CTRLA = TCC0_CTRLA_temp;
}

// Event System initialization (ADC trigger Event)
void event_system_init(void)
{
// Event System Channel 0 source: None
EVSYS.CH0MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 1 source: None
EVSYS.CH1MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 2 source: None
EVSYS.CH2MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 3 source: None
EVSYS.CH3MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 4 source: None
EVSYS.CH4MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 5 source: None
EVSYS.CH5MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 6 source: None
EVSYS.CH6MUX=EVSYS_CHMUX_OFF_gc;
// Event System Channel 7 source: Timer/Counter C0 Overflow
EVSYS.CH7MUX=EVSYS_CHMUX_TCC0_OVF_gc;

// Event System Channel 0 Digital Filter Coefficient: 1 Sample
EVSYS.CH0CTRL=(EVSYS.CH0CTRL & (~(EVSYS_QDIRM_gm | EVSYS_QDIEN_bm | EVSYS_QDEN_bm | EVSYS_DIGFILT_gm))) |
	EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 1 Digital Filter Coefficient: 1 Sample
EVSYS.CH1CTRL=EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 2 Digital Filter Coefficient: 1 Sample
EVSYS.CH2CTRL=(EVSYS.CH2CTRL & (~(EVSYS_QDIRM_gm | EVSYS_QDIEN_bm | EVSYS_QDEN_bm | EVSYS_DIGFILT_gm))) |
	EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 3 Digital Filter Coefficient: 1 Sample
EVSYS.CH3CTRL=EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 4 Digital Filter Coefficient: 1 Sample
EVSYS.CH4CTRL=(EVSYS.CH4CTRL & (~(EVSYS_QDIRM_gm | EVSYS_QDIEN_bm | EVSYS_QDEN_bm | EVSYS_DIGFILT_gm))) |
	EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 5 Digital Filter Coefficient: 1 Sample
EVSYS.CH5CTRL=EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 6 Digital Filter Coefficient: 1 Sample
EVSYS.CH6CTRL=EVSYS_DIGFILT_1SAMPLE_gc;
// Event System Channel 7 Digital Filter Coefficient: 1 Sample
EVSYS.CH7CTRL=EVSYS_DIGFILT_1SAMPLE_gc;

// Event System Channel 0 output: Disabled
// Note: the correct direction for the Event System Channel 0 output
// is configured in the ports_init function
PORTCFG.CLKEVOUT=(PORTCFG.CLKEVOUT & (~PORTCFG_EVOUT_gm)) | PORTCFG_EVOUT_OFF_gc;
}

// ADC initialization
// Function used to read the calibration byte from the
// signature row, specified by 'index'
#pragma optsize-
unsigned char read_calibration_byte(unsigned char index)
{
unsigned char r;
NVM.CMD=NVM_CMD_READ_CALIB_ROW_gc;
r=*((flash unsigned char*) index);
// Clean up NVM command register
NVM.CMD=NVM_CMD_NO_OPERATION_gc;
return r;
}
#pragma optsize_default

// ADCA initialization
// Variable used to store the ADC offset
// for 12 Bit Signed conversion mode
signed int adca_offset;

void adca_init(unsigned char gain)
{
unsigned char i;
int offs;

// ADCA is enabled
// Resolution: 12 Bits
// Load the calibration value for 12 Bit resolution
// from the signature row
ADCA.CALL=read_calibration_byte(PROD_SIGNATURES_START+ADCACAL0_offset);
ADCA.CALH=read_calibration_byte(PROD_SIGNATURES_START+ADCACAL1_offset);

// Free Running mode: Off
// Conversion mode: Signed
ADCA.CTRLB=(ADCA.CTRLB & (~(ADC_CONMODE_bm | ADC_FREERUN_bm | ADC_RESOLUTION_gm))) |
	ADC_CONMODE_bm | ADC_RESOLUTION_12BIT_gc;

// Clock frequency: 2000.000 kHz
ADCA.PRESCALER=(ADCA.PRESCALER & (~ADC_PRESCALER_gm)) | ADC_PRESCALER_DIV16_gc;

// Reference: 
// Temperature reference: Off
ADCA.REFCTRL=(ADCA.REFCTRL & ((~(ADC_REFSEL_gm | ADC_TEMPREF_bm)) | ADC_BANDGAP_bm)) |
	ADC_REFSEL_AREFA_gc;

    // Read and save the ADC offset using channel 0
    ADCA.CH0.CTRL=(ADCA.CH0.CTRL & (~(ADC_CH_START_bm | ADC_CH_GAINFAC_gm | ADC_CH_INPUTMODE_gm))) |
    	gain | ADC_CH_INPUTMODE_DIFF_gc;
    ADCA.CH0.MUXCTRL=(ADCA.CH0.MUXCTRL & (~(ADC_CH_MUXPOS_gm | ADC_CH_MUXNEG_gm))) |
    	ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN0_gc;
    // Enable the ADC in order to read the offset
    ADCA.CTRLA|=ADC_ENABLE_bm;
    // Insert a delay to allow the ADC common mode voltage to stabilize
    delay_us(5);
    // Perform several offset measurements and store the mean value
    offs=0;
    for (i=0; i<16; i++)
    {
        // Start the AD conversion on channel 0
        ADCA.CH0.CTRL|=ADC_CH_START_bm;
        // Wait for the AD conversion to complete
        while ((ADCA.CH0.INTFLAGS & ADC_CH_CHIF_bm)==0);
        // Clear the interrupt flag
        ADCA.CH0.INTFLAGS=ADC_CH_CHIF_bm;
        // Read the offset
        offs+=(signed char) ADCA.CH0.RES;
    }
    // Disable the ADC
    ADCA.CTRLA&= ~ADC_ENABLE_bm;
    // Store the mean value of the offset
    adca_offset=(signed char) (offs >> 4);

// Initialize the ADC Compare register
ADCA.CMPL=0x00;
ADCA.CMPH=0x00;

// ADC channel 0 gain: 1
// ADC channel 0 input mode: Differential input signal with gain
//ADCA.CH0.CTRL=(ADCA.CH0.CTRL & (~(ADC_CH_START_bm | ADC_CH_GAINFAC_gm | ADC_CH_INPUTMODE_gm))) |
//	ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_DIFFWGAIN_gc;
ADCA.CH0.CTRL=(ADCA.CH0.CTRL & (~(ADC_CH_START_bm | ADC_CH_GAINFAC_gm | ADC_CH_INPUTMODE_gm))) |
	gain | ADC_CH_INPUTMODE_DIFFWGAIN_gc;

// ADC channel 0 positive input: ADC2 pin
// ADC channel 0 negative input: ADC5 pin
ADCA.CH0.MUXCTRL=(ADCA.CH0.MUXCTRL & (~(ADC_CH_MUXPOS_gm | ADC_CH_MUXNEG_gm))) |
	ADC_CH_MUXPOS_PIN2_gc | ADC_CH_MUXNEG_PIN5_gc;

// AD conversion is started by the event system
// Event channel(s): 7 trigger(s) ADC channel(s): 0
ADCA.EVCTRL=ADC_EVSEL_7_gc | ADC_EVACT_CH0_gc;

// Channel 0 interrupt: Disabled
ADCA.CH0.INTCTRL=(ADCA.CH0.INTCTRL & (~(ADC_CH_INTMODE_gm | ADC_CH_INTLVL_gm))) |
	ADC_CH_INTMODE_COMPLETE_gc | ADC_CH_INTLVL_OFF_gc;
// Channel 1 interrupt: Disabled
ADCA.CH1.INTCTRL&= ~(ADC_CH_INTMODE_gm | ADC_CH_INTLVL_gm);
// Channel 2 interrupt: Disabled
ADCA.CH2.INTCTRL&= ~(ADC_CH_INTMODE_gm | ADC_CH_INTLVL_gm);
// Channel 3 interrupt: Disabled
ADCA.CH3.INTCTRL&= ~(ADC_CH_INTMODE_gm | ADC_CH_INTLVL_gm);

// Enable the ADC
ADCA.CTRLA|=ADC_ENABLE_bm;
// Insert a delay to allow the ADC common mode voltage to stabilize
delay_us(2);
}

inline void dma_controller_reset (void)
{
    DMA.CTRL = 0b00000000;
    while (DMA.CTRL & 0b10000000);
    DMA.CTRL = 0b01000000;
    while (DMA.CTRL & 0b01000000);
}
inline void dma_channel0_reset (void)
{
    DMA.CH0.CTRLA = 0b00000000;
    while (DMA.CH0.CTRLA & 0b10000000);
    DMA.CH0.CTRLA = 0b01000000;
    while (DMA.CH0.CTRLA & 0b01000000);
}
inline void dma_channel1_reset (void)
{
    DMA.CH1.CTRLA = 0b00000000;
    while (DMA.CH1.CTRLA & 0b10000000);
    DMA.CH1.CTRLA = 0b01000000;
    while (DMA.CH1.CTRLA & 0b01000000);
}
// Direct Memory Access (DMA) initialization (copies ADC output to adc data vector without CPU overhead)
inline void dma_disable (void)
{
    dma_controller_reset();
    dma_channel0_reset();
    dma_channel1_reset();
}
inline void dma_init (void)
{
    DMA.CH0.ADDRCTRL = 0b00000101;
    DMA.CH0.TRIGSRC = 0x10 + 0x00;
    DMA.CH0.TRFCNT = fft_N;
    DMA.CH0.REPCNT = 0x01;
    DMA.CH0.SRCADDR = ((unsigned long)(&ADCA.CH0.RESH));
    DMA.CH0.DESTADDR = ((unsigned long)(&(fft_adc.adc_bytes[3*fft_N])));
    DMA.CH0.CTRLB = 0b00000011;
    DMA.CH0.CTRLA = 0b10000000;
    DMA.CH1.ADDRCTRL = 0b00000101;
    DMA.CH1.TRIGSRC = 0x10 + 0x00;
    DMA.CH1.TRFCNT = fft_N;
    DMA.CH1.REPCNT = 0x01;
    DMA.CH1.SRCADDR = ((unsigned long)(&ADCA.CH0.RESL));
    DMA.CH1.DESTADDR = ((unsigned long)(&(fft_adc.adc_bytes[2*fft_N])));
    DMA.CH1.CTRLB = 0b00000011;
    DMA.CH1.CTRLA = 0b10000000;
    DMA.CTRL = 0b10000011;
}

#define SAMPLING_STATE_IDLE     0
#define SAMPLING_STATE_SAMPLING 1
#define SAMPLING_STATE_FFT      2
#define SAMPLING_STATE_UPDATING 3

unsigned char sampling_state = SAMPLING_STATE_IDLE;


unsigned char dma_1st_int = 0;
// Timer/counter TCD0 Overflow/Underflow interrupt service routine
interrupt [TCD0_OVF_vect] void tcd0_overflow_isr(void)
{
// write your code here
    if (sampling_state == SAMPLING_STATE_IDLE)
    {
        dma_init();
        sampling_enable();
        sampling_state = SAMPLING_STATE_SAMPLING;
        dma_1st_int = 0;
    }
}

// DMA channel1 transaction complete interrupt service routine
interrupt [DMA_CH1_vect] void dma_ch1_isr (void)
{
    if (dma_1st_int)
    {
        sampling_disable();
        dma_disable();
        sampling_state = SAMPLING_STATE_FFT;
    }
    dma_1st_int = 1;
}

// DMA channel0 transaction complete interrupt service routine
interrupt [DMA_CH0_vect] void dma_ch0_isr (void)
{
    if (dma_1st_int)
    {
        sampling_disable();
        dma_disable();
        sampling_state = SAMPLING_STATE_FFT;
    }
    dma_1st_int = 1;
}

//______________________________________________________________DAC_FUNCTIONS_&_VARIABLES_&_INTERRUPTS__________________________

// Timer/Counter TCE0 initialization
void tce0_init(void)
{
unsigned char s;
unsigned char n;

// Note: the correct PORTE direction for the Compare Channels outputs
// is configured in the ports_init function

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc0_disable(&TCE0);
// Clock source: Peripheral Clock/1
//TCE0.CTRLA=(TCE0.CTRLA & (~TC0_CLKSEL_gm)) | TC_CLKSEL_DIV1_gc;
TCE0.CTRLA = 0;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
// Compare/Capture on channel C: Off
// Compare/Capture on channel D: Off
TCE0.CTRLB=(TCE0.CTRLB & (~(TC0_CCAEN_bm | TC0_CCBEN_bm | TC0_CCCEN_bm | TC0_CCDEN_bm | TC0_WGMODE_gm))) |
	TC_WGMODE_NORMAL_gc;

// Capture event source: None
// Capture event action: None
TCE0.CTRLD=(TCE0.CTRLD & (~(TC0_EVACT_gm | TC0_EVSEL_gm))) |
	TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Overflow interrupt: Medium Level
// Error interrupt: Disabled
TCE0.INTCTRLA=(TCE0.INTCTRLA & (~(TC0_ERRINTLVL_gm | TC0_OVFINTLVL_gm))) |
	TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_MED_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
// Compare/Capture channel C interrupt: Disabled
// Compare/Capture channel D interrupt: Disabled
TCE0.INTCTRLB=(TCE0.INTCTRLB & (~(TC0_CCDINTLVL_gm | TC0_CCCINTLVL_gm | TC0_CCBINTLVL_gm | TC0_CCAINTLVL_gm))) |
	TC_CCDINTLVL_OFF_gc | TC_CCCINTLVL_OFF_gc | TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESE.CTRL&= ~HIRES_HREN0_bm;

// Advanced Waveform Extension initialization
// Optimize for speed
#pragma optsize- 
// Disable locking the AWEX configuration registers just to be sure
n=MCU.AWEXLOCK & (~MCU_AWEXELOCK_bm);
CCP=CCP_IOREG_gc;
MCU.AWEXLOCK=n;
// Restore optimization for size if needed
#pragma optsize_default

// Pattern generation: Off
// Dead time insertion: Off
AWEXE.CTRL&= ~(AWEX_PGM_bm | AWEX_CWCM_bm | AWEX_DTICCDEN_bm | AWEX_DTICCCEN_bm | AWEX_DTICCBEN_bm | AWEX_DTICCAEN_bm);

// Fault protection initialization
// Fault detection on OCD Break detection: On
// Fault detection restart mode: Latched Mode
// Fault detection action: None (Fault protection disabled)
AWEXE.FDCTRL=(AWEXE.FDCTRL & (~(AWEX_FDDBD_bm | AWEX_FDMODE_bm | AWEX_FDACT_gm))) |
	AWEX_FDACT_NONE_gc;
// Fault detect events: 
// Event channel 0: Off
// Event channel 1: Off
// Event channel 2: Off
// Event channel 3: Off
// Event channel 4: Off
// Event channel 5: Off
// Event channel 6: Off
// Event channel 7: Off
AWEXE.FDEVMASK=0b00000000;
// Make sure the fault detect flag is cleared
AWEXE.STATUS|=AWEXE.STATUS & AWEX_FDF_bm;

// Clear the interrupt flags
TCE0.INTFLAGS=TCE0.INTFLAGS;
// Set counter register
TCE0.CNT=0x0000;
// Set period register
TCE0.PER=0x009F;
// Set channel A Compare/Capture register
TCE0.CCA=0x0000;
// Set channel B Compare/Capture register
TCE0.CCB=0x0000;
// Set channel C Compare/Capture register
TCE0.CCC=0x0000;
// Set channel D Compare/Capture register
TCE0.CCD=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}
#define DAC_INPUT_LEN   ((unsigned int)(1 << (radix - 1)))
unsigned char dac_inputs_min[DAC_INPUT_LEN];
unsigned char dac_inputs_max[DAC_INPUT_LEN];
register unsigned char dac_x_ptr = 0;
register unsigned char dac_x_port_ptr0 = 0;
register unsigned char dac_x_port_ptr1 = 0;
register unsigned char dac_y_ptr = 0x01;
register unsigned char dac_y_max;
inline void dac_disable (void)
{
    TCE0.CTRLA = 0x00;
    dac_x_ptr = 0;
    dac_x_port_ptr0 = 0;
    dac_x_port_ptr1 = 0;
    dac_y_ptr = 0;
    TCE0.CNT = 0x0000;
}
inline void dac_enable (void)
{
    TCE0.CTRLA = TC_CLKSEL_DIV1_gc;
}

// Timer/Counter TCE1 initialization
void tce1_init(void)
{
unsigned char s;

// Note: the correct PORTE direction for the Compare Channels outputs
// is configured in the ports_init function

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc1_disable(&TCE1);
// Clock source: Peripheral Clock/1
//TCE1.CTRLA=(TCE1.CTRLA & (~TC1_CLKSEL_gm)) | TC_CLKSEL_DIV1_gc;
TCE1.CTRLA = 0x00;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
TCE1.CTRLB=(TCE1.CTRLB & (~(TC1_CCAEN_bm | TC1_CCBEN_bm | TC1_WGMODE_gm))) |
	TC_WGMODE_NORMAL_gc;

// Capture event source: None
// Capture event action: None
TCE1.CTRLD=(TCE1.CTRLD & (~(TC1_EVACT_gm | TC1_EVSEL_gm))) |
	TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Overflow interrupt: High Level
// Error interrupt: Disabled
TCE1.INTCTRLA=(TCE1.INTCTRLA & (~(TC1_ERRINTLVL_gm | TC1_OVFINTLVL_gm))) |
	TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_HI_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
TCE1.INTCTRLB=(TCE1.INTCTRLB & (~(TC1_CCBINTLVL_gm | TC1_CCAINTLVL_gm))) |
	TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESE.CTRL&= ~HIRES_HREN1_bm;

// Clear the interrupt flags
TCE1.INTFLAGS=TCE1.INTFLAGS;
// Set counter register
TCE1.CNT=0x0000;
// Set period register
TCE1.PER=0x07F;
// Set channel A Compare/Capture register
TCE1.CCA=0x0000;
// Set channel B Compare/Capture register
TCE1.CCB=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}
inline void calibration_disable (void)
{
    TCE1.CTRLA = 0x00;
}
inline void calibration_enable (void)
{
    TCE1.CTRLA = TC_CLKSEL_DIV1_gc;
}

// Timer/counter TCE0 Overflow/Underflow interrupt service routine
interrupt [TCE0_OVF_vect] void tce0_overflow_isr(void)
{
    PORTK.OUT = dac_y_ptr;
    PORTJ.OUT = dac_x_port_ptr1;
    PORTH.OUT = dac_x_port_ptr0;
    dac_y_ptr++;
    if (dac_y_ptr >= dac_y_max)
    {
        dac_x_ptr++;
        
//        dac_x_port_ptr0 = (dac_x_ptr << 4) & 0xF0;
//        dac_x_port_ptr1 = (dac_x_ptr >> 4) & 0x0F;
        dac_x_port_ptr0 = dac_x_ptr;
#asm
        swap    R9 ; swap dac_x_port_ptr0
#endasm
        dac_x_port_ptr1 = dac_x_port_ptr0;
        dac_x_port_ptr0 &= 0xF0;
        dac_x_port_ptr1 &= 0x0F;
        dac_y_ptr = dac_inputs_min[dac_x_ptr];
        dac_y_max = dac_inputs_max[dac_x_ptr];
    }
}


// Timer/counter TCE1 Overflow/Underflow interrupt service routine
interrupt [TCE1_OVF_vect] void tce1_overflow_isr(void)
{
// write your code here
    static unsigned char state = 0;
    static union _char2int_
    {
        unsigned int i;
        unsigned char c[2];
    } x_val = {0}, y_val = {0};
    PORTJ.OUT = y_val.c[1] | x_val.c[0];
    PORTH.OUT = y_val.c[0];            
    PORTK.OUT = x_val.c[1];
    switch (state)
    {
    case 0:
        if (++y_val.i == 0x0FFF)
            state = 1;
        break;
    case 1:
        x_val.i += 0x10;
        if (x_val.i == 0xFFF0)
            state = 2;
        break;
    case 2:
        if (--y_val.i == 0x0001)
            state = 3;
        break;
    case 3:
        x_val.i -= 0x10;
        if (x_val.i == 0x0010)
            state = 0;
        break;
    }
}


//______________________________________________________________KEYPAD_FUNCTIONS_&_VARIABLES_&_INTERRUPTS_______________________
// Initialization
// Timer/Counter TCF0 initialization (Bounce and error detector timer for Keypad)
void tcf0_init(void)
{
unsigned char s;

// Note: the correct PORTF direction for the Compare Channels outputs
// is configured in the ports_init function

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc0_disable(&TCF0);
// Clock source: Peripheral Clock/64
TCF0.CTRLA=(TCF0.CTRLA & (~TC0_CLKSEL_gm)) | TC_CLKSEL_DIV64_gc;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
// Compare/Capture on channel C: Off
// Compare/Capture on channel D: Off
TCF0.CTRLB=(TCF0.CTRLB & (~(TC0_CCAEN_bm | TC0_CCBEN_bm | TC0_CCCEN_bm | TC0_CCDEN_bm | TC0_WGMODE_gm))) |
	TC_WGMODE_NORMAL_gc;

// Capture event source: None
// Capture event action: None
TCF0.CTRLD=(TCF0.CTRLD & (~(TC0_EVACT_gm | TC0_EVSEL_gm))) |
	TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Overflow interrupt: Low Level
// Error interrupt: Disabled
TCF0.INTCTRLA=(TCF0.INTCTRLA & (~(TC0_ERRINTLVL_gm | TC0_OVFINTLVL_gm))) |
	TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_LO_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
// Compare/Capture channel C interrupt: Disabled
// Compare/Capture channel D interrupt: Disabled
TCF0.INTCTRLB=(TCF0.INTCTRLB & (~(TC0_CCDINTLVL_gm | TC0_CCCINTLVL_gm | TC0_CCBINTLVL_gm | TC0_CCAINTLVL_gm))) |
	TC_CCDINTLVL_OFF_gc | TC_CCCINTLVL_OFF_gc | TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESF.CTRL&= ~HIRES_HREN0_bm;

// Clear the interrupt flags
TCF0.INTFLAGS=TCF0.INTFLAGS;
// Set counter register
TCF0.CNT=0x0000;
// Set period register
TCF0.PER=0x61A7;
// Set channel A Compare/Capture register
TCF0.CCA=0x0000;
// Set channel B Compare/Capture register
TCF0.CCB=0x0000;
// Set channel C Compare/Capture register
TCF0.CCC=0x0000;
// Set channel D Compare/Capture register
TCF0.CCD=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}

// Global Variables for Keypad
#define KEY_COUNT		16
unsigned char key_col_pos_temp;
unsigned char key_col_pos, key_row_pos;
unsigned char key_pos;
unsigned char key;

#define KEY_BACKSPACE	10
#define KEY_CALIBRATE	11
#define KEY_UNITS		12
#define KEY_SET			13
#define KEY_ENTER		14
#define KEY_MINUS		15
#define KEY_RIGHT		9
#define KEY_LEFT		7
flash unsigned char key_pos_to_key[KEY_COUNT] = {1,2,3,KEY_BACKSPACE,4,5,6,KEY_CALIBRATE,7,8,9,
                                                    KEY_UNITS,KEY_SET,0,KEY_ENTER,KEY_MINUS};

enum _menu_states_
{
	menu_state_calib = 0,
	menu_state_show_freq,
	menu_state_show_div,
	menu_state_show_min,
	menu_state_show_gain,
	menu_state_set_freq,
	menu_state_set_div,
	menu_state_set_min,
	menu_state_set_gain,
	menu_state_invalid_state,
}
next_menu_state, current_menu_state = menu_state_calib;

void menu_display_calib (void)
{
	lcd_clear();
	lcd_putsf("calibrate");
    dac_disable();
	//  disable other preipherals
	sampling_commence_disable();
    sampling_disable();
    dma_disable();
	//  enable callibration
	calibration_enable();
}

static unsigned char number_input_number_cntr;
signed long int number_input (unsigned char minus_enable, unsigned char max_digits, unsigned char lcd_x_offset, unsigned char lcd_y)
{
	static signed int number;
	if ((current_menu_state < menu_state_set_freq) || (current_menu_state > menu_state_set_min))
	{
		number = 0;
		number_input_number_cntr = 0;
	}
	else
	{
		if ((key < 10) && (number_input_number_cntr < max_digits))
		{
			number = 10*number + key;
			lcd_putchar(key + '0');
			number_input_number_cntr++;
		}
		else if ((key == KEY_BACKSPACE) && (number_input_number_cntr > 0))
		{
			number /= 10;
			number_input_number_cntr--;
			lcd_gotoxy(lcd_x_offset + number_input_number_cntr,lcd_y);
			if (number_input_number_cntr)
				lcd_putchar(' ');
			else
				lcd_putchar('?');
			lcd_gotoxy(lcd_x_offset + number_input_number_cntr,lcd_y);
			
		}
		else if ((key == KEY_MINUS) && (minus_enable))
		{
			number = -number;
			lcd_gotoxy(lcd_x_offset - 1,lcd_y);
			if (number < 0)
				lcd_putchar('-');
			else
				lcd_putchar(' ');
			lcd_gotoxy(lcd_x_offset + number_input_number_cntr,lcd_y);
		}
	}
	
	return number;
}

void menu_display_show_freq (void)
{
	char str[5];
	unsigned int freq;
	if (number_input_number_cntr && (key == KEY_ENTER))
	{
		freq = number_input(0,0,0,0);
        if (freq > 2000)
			freq = 2000;
        if (freq == 0)
            freq = 1;
		// Disable Sampling Timer and what so ever
		sampling_commence_disable();
        sampling_disable();
        dma_disable();
		// Update sampling timer PER register
		SAMPLING_TIMER_PER = _MCU_CLOCK_FREQUENCY_/1000/freq - 1;
		// Enable Sampling Timer and what so ever
		dma_init();
        sampling_enable();
        sampling_commence_enable();
	}
    else if (current_menu_state == menu_state_calib)
    {
        calibration_disable();
		dma_init();
        sampling_enable();
        sampling_commence_enable();
        dac_enable();
    }
	itoa(_MCU_CLOCK_FREQUENCY_/1000/(((unsigned long)(SAMPLING_TIMER_PER)) + 1),str);
	lcd_clear();
	lcd_putsf("Sampling Freq =");
	lcd_gotoxy(0,1);
	lcd_puts(str);
	lcd_gotoxy(5,1);
	lcd_putsf("KHz");
}
void menu_display_set_freq (void)
{
	if (current_menu_state != menu_state_set_freq)
	{
		lcd_clear();
		lcd_putsf("Set Samp Freq:");
		lcd_gotoxy(5,1);
		lcd_putsf("KHz");
		lcd_gotoxy(0,1);
	}
	number_input(0,4,0,1);
}

float abs_to_dac_coeff0 = 255.0;
float abs_to_dac_coeff1 = -0.0001275;
signed long int oscope_min = 0.0;
unsigned long int oscope_div = 250000.0;
void min_div_to_coeff (void)
{
    abs_to_dac_coeff1 = -255.0/8.0/((float)(oscope_div));
    abs_to_dac_coeff0 = 255.0 + ((float)(oscope_min))*255.0/8.0/((float)(oscope_div));
}
#define UNIT_COUNT      4
#define DIV_UNIT_UV		0
#define DIV_UNIT_MV		1
#define DIV_UNIT_DB		2
#define DIV_UNIT_DBM    3
#define LOG10IMPEDANCE	1.69897
float abs_fft_uV (float input)
{
    return pow(input,0.5)*1000000.0;
}
float abs_fft_mV (float input)
{
    return pow(input,0.5)*1000.0;
}
float abs_fft_dB (float input)
{
    return 10.0*log10(input) - 10*LOG10IMPEDANCE;
}
float abs_fft_dBm (float input)
{
    return 10.0*log10(input) + (30.0 - 10*LOG10IMPEDANCE);
}
flash struct _units_
{
	signed long int min;
	signed long int max;
	char unit_msg[4];
    unsigned char number_input_max_digits;
	float (* abs_fft_fcn)(float input);
} units[UNIT_COUNT] =
{
	{0,2000000,"uV ",7,
	(float (*)(float)) abs_fft_uV},
	{0,2000,"mV ",4,
	(float (*)(float)) abs_fft_mV},
	{-105 - ((signed long int)(10.0*LOG10IMPEDANCE)),10 - ((signed long int)(10.0*LOG10IMPEDANCE))
    ,"dB ",4,(float (*)(float)) abs_fft_dB},
	{-75 - ((signed long int)(10.0*LOG10IMPEDANCE)),40 - ((signed long int)(10.0*LOG10IMPEDANCE))
    ,"dBm",4,(float (*)(float)) abs_fft_dBm}
};
unsigned char next_unit, current_unit = 0;
void menu_display_show_div (void)
{
	char str[9];
    if (number_input_number_cntr && (key == KEY_ENTER))
    {
        oscope_div = number_input(0,0,0,0);
        if (8*oscope_div > (units[next_unit].max -  units[next_unit].min))
            oscope_div = (units[next_unit].max - units[next_unit].min)/8;
        // Disable sampling
        sampling_commence_disable();
        sampling_disable();
        dma_disable();
        // update coefficients
        min_div_to_coeff();
        current_unit = next_unit;
        // enable sampling
        dma_init();
        sampling_enable();
        sampling_commence_enable();
    }
    ltoa(oscope_div,str);
    lcd_clear();
    lcd_putsf("PerDiv Val");
    lcd_gotoxy(0,1);
    lcd_puts(str);
    lcd_putchar(' ');
    lcd_putsf(units[current_unit].unit_msg);
}
void menu_display_set_div (void)
{
    if (key == KEY_UNITS)
    {
        lcd_gotoxy(units[next_unit].number_input_max_digits + 2,1);
        lcd_putsf("   "); 
        next_unit++;
        next_unit %= UNIT_COUNT;
        lcd_gotoxy(units[next_unit].number_input_max_digits + 2,1);
        lcd_putsf(units[next_unit].unit_msg);
    }
    else
    {
        if (current_menu_state != menu_state_set_div)
        {
            next_unit = current_unit;
            lcd_clear();
            lcd_putsf("Set PerDiv Val:");
            lcd_gotoxy(units[next_unit].number_input_max_digits + 2,1);
            lcd_putsf(units[next_unit].unit_msg);
            lcd_gotoxy(1,1);
        }
        number_input(0,units[next_unit].number_input_max_digits,1,1);
    }
}

void menu_display_show_min (void)
{
	char str[9];
    if (number_input_number_cntr && (key == KEY_ENTER))
    {
        oscope_min = number_input(0,0,0,0);
        if (oscope_min < units[current_unit].min)
            oscope_min = units[current_unit].min;
        else if (units[current_unit].min > (units[current_unit].max - 8*oscope_div))
            oscope_min = units[current_unit].max - 8*oscope_div;
        // Disable sampling
        sampling_commence_disable();
        sampling_disable();
        dma_disable();
        // update coefficients
        min_div_to_coeff();
        // enable sampling
        dma_init();
        sampling_enable();
        sampling_commence_enable();
    }
    ltoa(oscope_min,str);
    lcd_clear();
    lcd_putsf("Min Val");
    lcd_gotoxy(0,1);
    lcd_puts(str);
    lcd_putchar(' ');
    lcd_putsf(units[current_unit].unit_msg);
}
void menu_display_set_min (void)
{
	if (current_menu_state != menu_state_set_div)
    {
        lcd_clear();
        lcd_putsf("Set Min Val:");
        lcd_gotoxy(units[current_unit].number_input_max_digits + 2,1);
        lcd_putsf(units[current_unit].unit_msg);
        lcd_gotoxy(1,1);
    }
    number_input(1,units[current_unit].number_input_max_digits,1,1);
}

unsigned char gain_index = 0;
unsigned char next_gain_index;
void menu_display_show_gain (void)
{
    char str[3];
    if ((current_menu_state == menu_state_set_gain) && (gain_index != next_gain_index) && (key == KEY_ENTER))
    {
        gain_index = next_gain_index;
        // Disable sampeling
        sampling_commence_disable();
        sampling_disable();
        dma_disable();
        // re-init ADC
        adca_init(gain_index << 2);
        // Enable sampling
        dma_init();
        sampling_enable();
        sampling_commence_enable();
    }
    itoa(1 << ((unsigned int)(gain_index)),str);
    lcd_clear();
    lcd_putsf("Gain = ");
    lcd_puts(str);
}
void menu_display_set_gain (void)
{
    unsigned char str[3];
	if (current_menu_state != menu_state_set_gain)
    {
        next_gain_index = gain_index;
        lcd_clear();
        lcd_putsf("Set Gain: ");
    }
    else
    {
        if (key == KEY_RIGHT)
        {
            next_gain_index++;
            next_gain_index %= 7;
        }
        else if (key == KEY_LEFT)
        {
            next_gain_index--;
            if ((next_gain_index > 6))
                next_gain_index = 0;
        }
    }
    lcd_gotoxy(10,0);
    lcd_putsf("  ");
    lcd_gotoxy(10,0);
    itoa(1 << ((unsigned int)(next_gain_index)),str);
    lcd_puts(str);
}

flash struct _menu_state_data_
{
	void (* menu_fcn)();
	enum _menu_states_ menu_next_state[KEY_COUNT];
} menu_state_data[9] =
{
	{
		(void (*)()) menu_display_calib,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_freq,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state}},
	{
		(void (*)()) menu_display_show_freq,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_gain,
			menu_state_invalid_state,	menu_state_show_div,
			menu_state_invalid_state,	menu_state_calib,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_set_freq,		menu_state_invalid_state}},
	{
		(void (*)()) menu_display_show_div,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_freq,
			menu_state_invalid_state,	menu_state_show_min,
			menu_state_invalid_state,	menu_state_calib,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_set_div,			menu_state_invalid_state}},
	{
		(void (*)()) menu_display_show_min,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_div,
			menu_state_invalid_state,	menu_state_show_gain,
			menu_state_invalid_state,	menu_state_calib,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_set_min,			menu_state_invalid_state}},
	{
		(void (*)()) menu_display_show_gain,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_min,
			menu_state_invalid_state,	menu_state_show_freq,
			menu_state_invalid_state,	menu_state_calib,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_set_gain,		menu_state_invalid_state}},
	{
		(void (*)()) menu_display_set_freq,
		{
			menu_state_set_freq,		menu_state_set_freq,
			menu_state_set_freq,		menu_state_set_freq,
			menu_state_set_freq,		menu_state_set_freq,
			menu_state_set_freq,		menu_state_set_freq,
			menu_state_set_freq,		menu_state_set_freq,
			menu_state_set_freq,		menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_freq,
			menu_state_show_freq,		menu_state_invalid_state}},
	{
		(void (*)()) menu_display_set_div,
		{
			menu_state_set_div,			menu_state_set_div,
			menu_state_set_div,			menu_state_set_div,
			menu_state_set_div,			menu_state_set_div,
			menu_state_set_div,			menu_state_set_div,
			menu_state_set_div,			menu_state_set_div,
			menu_state_set_div,			menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_div,
			menu_state_show_div,		menu_state_invalid_state}},
	{
		(void (*)()) menu_display_set_min,
		{
			menu_state_set_min,			menu_state_set_min,
			menu_state_set_min,			menu_state_set_min,
			menu_state_set_min,			menu_state_set_min,
			menu_state_set_min,			menu_state_set_min,
			menu_state_set_min,			menu_state_set_min,
			menu_state_set_min,			menu_state_invalid_state,
			menu_state_set_min,			menu_state_show_min,
			menu_state_show_min,		menu_state_set_min}},
	{
		(void (*)()) menu_display_set_gain,
		{
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_set_gain,
			menu_state_invalid_state,	menu_state_set_gain,
			menu_state_invalid_state,	menu_state_invalid_state,
			menu_state_invalid_state,	menu_state_show_gain,
			menu_state_show_gain,		menu_state_invalid_state}}
};

void KP_function (void)
{
    next_menu_state = menu_state_data[current_menu_state].menu_next_state[key];
	if (next_menu_state != menu_state_invalid_state)
    {
		(*menu_state_data[next_menu_state].menu_fcn)();
        current_menu_state = next_menu_state;
    }
}

// PORTD interrupt 0 service routine
interrupt [PORTD_INT0_vect] void portd_int0_isr(void)
{
// write your code here
    key_col_pos_temp = ((PORTD.IN >> 4) & 0x0F); // record temporary column
    PORTD.INT0MASK = 0x00; // disable keypad port interrupt
    PORTD.INTFLAGS = 0x01;
    TCF0.CNT = 0x0000; // clear keypad timer counter
    TCF0.CTRLA = (TCF0.CTRLA & (~TC1_CLKSEL_gm)) | TC_CLKSEL_DIV64_gc; // enable timer counting
}

// Timer/counter TCF0 Overflow/Underflow interrupt service routine
interrupt [TCF0_OVF_vect] void tcf0_overflow_isr(void)
{
// write your code here
    TCF0.CTRLA = 0x00; // disable keypad timer counting
    TCF0.CNT = 0x0001;
    if (((PORTD.IN >> 4) & 0x0F) == key_col_pos_temp)
    {
        PORTD.DIR = 0xF0;
        PORTD.OUT = 0xF0;
        key_row_pos = PORTD.IN & 0x0F;
        switch (key_col_pos_temp)
        {
        case 0x01:
            key_col_pos = 0;
            break;
        case 0x02:
            key_col_pos = 1;
            break;
        case 0x04:
            key_col_pos = 2;
            break;
        case 0x08:
            key_col_pos = 3;
            break;
        }
        switch ((~key_row_pos) & 0x0F)
        {
        case 0x01:
            key_row_pos = 0;
            break;
        case 0x02:
            key_row_pos = 1;
            break;
        case 0x04:
            key_row_pos = 2;
            break;
        case 0x08:
            key_row_pos = 3;
            break;
        }
        key_pos = 0x0F & (key_row_pos | (key_col_pos << 0x02));
		key = key_pos_to_key[key_pos];
        KP_function();
    }
    PORTD.DIR = 0x0F;
    PORTD.OUT = 0x0F;
    PORTD.INTFLAGS = 0x01;
    PORTD.INT0MASK = 0xF0;
}

//______________________________________________________________FFT_FUNCTIONS_&_VARIABLES_______________________________________

inline void add (complex *x, complex y)
{
    x->real += y.real;
    x->imag += y.imag;
    return;
}

inline void mul (complex *x, complex y)
{
    float temp;
    temp = x->real*y.real - x->imag*y.imag;
    x->imag = x->imag*y.real + x->real*y.imag;
    x->real = temp;
    return;
}

inline void neg (complex *x)
{
    x->real = -x->real;
    x->imag = -x->imag;
    return;
}

flash complex W[fft_N] =
{
    {1.0,0.0},
    {0.99992472,0.01227153838},
    {0.99969882,0.02454122901},
    {0.99932235,0.0368072242},
    {0.99879545,0.0490676761},
    {0.9981181,0.061320737},
    {0.99729043,0.0735645667},
    {0.99631262,0.0857973099},
    {0.99518472,0.0980171412},
    {0.99390697,0.110222206},
    {0.99247956,0.122410677},
    {0.99090266,0.134580702},
    {0.98917651,0.146730468},
    {0.98730141,0.15885815},
    {0.98527765,0.170961887},
    {0.98310548,0.183039889},
    {0.98078525,0.195090324},
    {0.97831738,0.207111374},
    {0.97570211,0.219101235},
    {0.97293997,0.231058106},
    {0.97003126,0.242980182},
    {0.96697646,0.254865646},
    {0.96377605,0.266712755},
    {0.9604305,0.27851969},
    {0.95694035,0.290284663},
    {0.95330602,0.302005947},
    {0.94952816,0.313681751},
    {0.9456073,0.32531029},
    {0.94154406,0.33688986},
    {0.93733901,0.34841868},
    {0.93299282,0.35989505},
    {0.92850608,0.37131721},
    {0.9238795,0.38268343},
    {0.91911387,0.39399204},
    {0.91420978,0.40524131},
    {0.909168,0.41642955},
    {0.90398932,0.42755508},
    {0.89867449,0.43861625},
    {0.8932243,0.44961134},
    {0.88763964,0.46053872},
    {0.88192129,0.47139674},
    {0.87607008,0.48218378},
    {0.87008697,0.4928982},
    {0.86397284,0.50353837},
    {0.8577286,0.51410276},
    {0.8513552,0.52458966},
    {0.84485358,0.53499764},
    {0.83822471,0.54532498},
    {0.8314696,0.55557024},
    {0.82458931,0.56573182},
    {0.81758481,0.57580817},
    {0.81045717,0.58579785},
    {0.80320752,0.59569931},
    {0.79583693,0.60551107},
    {0.78834641,0.61523157},
    {0.78073722,0.62485951},
    {0.77301043,0.63439327},
    {0.76516724,0.64383155},
    {0.75720882,0.65317285},
    {0.74913639,0.6624158},
    {0.74095112,0.67155898},
    {0.73265427,0.680601},
    {0.7242471,0.68954057},
    {0.71573085,0.69837624},
    {0.70710677,0.70710677},
    {0.69837624,0.71573085},
    {0.68954057,0.7242471},
    {0.680601,0.73265427},
    {0.67155898,0.74095112},
    {0.6624158,0.74913639},
    {0.65317285,0.75720882},
    {0.64383155,0.76516724},
    {0.63439327,0.77301043},
    {0.62485951,0.78073722},
    {0.61523157,0.78834641},
    {0.60551107,0.79583693},
    {0.59569931,0.80320752},
    {0.58579785,0.81045717},
    {0.57580817,0.81758481},
    {0.56573182,0.82458931},
    {0.55557024,0.8314696},
    {0.54532498,0.83822471},
    {0.53499764,0.84485358},
    {0.52458966,0.8513552},
    {0.51410276,0.8577286},
    {0.50353837,0.86397284},
    {0.4928982,0.87008697},
    {0.48218378,0.87607008},
    {0.47139674,0.88192129},
    {0.46053872,0.88763964},
    {0.44961134,0.8932243},
    {0.43861625,0.89867449},
    {0.42755508,0.90398932},
    {0.41642955,0.909168},
    {0.40524131,0.91420978},
    {0.39399204,0.91911387},
    {0.38268343,0.9238795},
    {0.37131721,0.92850608},
    {0.35989505,0.93299282},
    {0.34841868,0.93733901},
    {0.33688986,0.94154406},
    {0.32531029,0.9456073},
    {0.313681751,0.94952816},
    {0.302005947,0.95330602},
    {0.290284663,0.95694035},
    {0.27851969,0.9604305},
    {0.266712755,0.96377605},
    {0.254865646,0.96697646},
    {0.242980182,0.97003126},
    {0.231058106,0.97293997},
    {0.219101235,0.97570211},
    {0.207111374,0.97831738},
    {0.195090324,0.98078525},
    {0.183039889,0.98310548},
    {0.170961887,0.98527765},
    {0.15885815,0.98730141},
    {0.146730468,0.98917651},
    {0.134580702,0.99090266},
    {0.122410677,0.99247956},
    {0.110222206,0.99390697},
    {0.0980171412,0.99518472},
    {0.0857973099,0.99631262},
    {0.0735645667,0.99729043},
    {0.061320737,0.9981181},
    {0.0490676761,0.99879545},
    {0.0368072242,0.99932235},
    {0.02454122901,0.99969882},
    {0.01227153838,0.99992472},
    {0.0,1.0},
    {-0.01227153838,0.99992472},
    {-0.02454122901,0.99969882},
    {-0.0368072242,0.99932235},
    {-0.0490676761,0.99879545},
    {-0.061320737,0.9981181},
    {-0.0735645667,0.99729043},
    {-0.0857973099,0.99631262},
    {-0.0980171412,0.99518472},
    {-0.110222206,0.99390697},
    {-0.122410677,0.99247956},
    {-0.134580702,0.99090266},
    {-0.146730468,0.98917651},
    {-0.15885815,0.98730141},
    {-0.170961887,0.98527765},
    {-0.183039889,0.98310548},
    {-0.195090324,0.98078525},
    {-0.207111374,0.97831738},
    {-0.219101235,0.97570211},
    {-0.231058106,0.97293997},
    {-0.242980182,0.97003126},
    {-0.254865646,0.96697646},
    {-0.266712755,0.96377605},
    {-0.27851969,0.9604305},
    {-0.290284663,0.95694035},
    {-0.302005947,0.95330602},
    {-0.313681751,0.94952816},
    {-0.32531029,0.9456073},
    {-0.33688986,0.94154406},
    {-0.34841868,0.93733901},
    {-0.35989505,0.93299282},
    {-0.37131721,0.92850608},
    {-0.38268343,0.9238795},
    {-0.39399204,0.91911387},
    {-0.40524131,0.91420978},
    {-0.41642955,0.909168},
    {-0.42755508,0.90398932},
    {-0.43861625,0.89867449},
    {-0.44961134,0.8932243},
    {-0.46053872,0.88763964},
    {-0.47139674,0.88192129},
    {-0.48218378,0.87607008},
    {-0.4928982,0.87008697},
    {-0.50353837,0.86397284},
    {-0.51410276,0.8577286},
    {-0.52458966,0.8513552},
    {-0.53499764,0.84485358},
    {-0.54532498,0.83822471},
    {-0.55557024,0.8314696},
    {-0.56573182,0.82458931},
    {-0.57580817,0.81758481},
    {-0.58579785,0.81045717},
    {-0.59569931,0.80320752},
    {-0.60551107,0.79583693},
    {-0.61523157,0.78834641},
    {-0.62485951,0.78073722},
    {-0.63439327,0.77301043},
    {-0.64383155,0.76516724},
    {-0.65317285,0.75720882},
    {-0.6624158,0.74913639},
    {-0.67155898,0.74095112},
    {-0.680601,0.73265427},
    {-0.68954057,0.7242471},
    {-0.69837624,0.71573085},
    {-0.70710677,0.70710677},
    {-0.71573085,0.69837624},
    {-0.7242471,0.68954057},
    {-0.73265427,0.680601},
    {-0.74095112,0.67155898},
    {-0.74913639,0.6624158},
    {-0.75720882,0.65317285},
    {-0.76516724,0.64383155},
    {-0.77301043,0.63439327},
    {-0.78073722,0.62485951},
    {-0.78834641,0.61523157},
    {-0.79583693,0.60551107},
    {-0.80320752,0.59569931},
    {-0.81045717,0.58579785},
    {-0.81758481,0.57580817},
    {-0.82458931,0.56573182},
    {-0.8314696,0.55557024},
    {-0.83822471,0.54532498},
    {-0.84485358,0.53499764},
    {-0.8513552,0.52458966},
    {-0.8577286,0.51410276},
    {-0.86397284,0.50353837},
    {-0.87008697,0.4928982},
    {-0.87607008,0.48218378},
    {-0.88192129,0.47139674},
    {-0.88763964,0.46053872},
    {-0.8932243,0.44961134},
    {-0.89867449,0.43861625},
    {-0.90398932,0.42755508},
    {-0.909168,0.41642955},
    {-0.91420978,0.40524131},
    {-0.91911387,0.39399204},
    {-0.9238795,0.38268343},
    {-0.92850608,0.37131721},
    {-0.93299282,0.35989505},
    {-0.93733901,0.34841868},
    {-0.94154406,0.33688986},
    {-0.9456073,0.32531029},
    {-0.94952816,0.313681751},
    {-0.95330602,0.302005947},
    {-0.95694035,0.290284663},
    {-0.9604305,0.27851969},
    {-0.96377605,0.266712755},
    {-0.96697646,0.254865646},
    {-0.97003126,0.242980182},
    {-0.97293997,0.231058106},
    {-0.97570211,0.219101235},
    {-0.97831738,0.207111374},
    {-0.98078525,0.195090324},
    {-0.98310548,0.183039889},
    {-0.98527765,0.170961887},
    {-0.98730141,0.15885815},
    {-0.98917651,0.146730468},
    {-0.99090266,0.134580702},
    {-0.99247956,0.122410677},
    {-0.99390697,0.110222206},
    {-0.99518472,0.0980171412},
    {-0.99631262,0.0857973099},
    {-0.99729043,0.0735645667},
    {-0.9981181,0.061320737},
    {-0.99879545,0.0490676761},
    {-0.99932235,0.0368072242},
    {-0.99969882,0.02454122901},
    {-0.99992472,0.01227153838},
    {-1.0,0.0},
    {-0.99992472,-0.01227153838},
    {-0.99969882,-0.02454122901},
    {-0.99932235,-0.0368072242},
    {-0.99879545,-0.0490676761},
    {-0.9981181,-0.061320737},
    {-0.99729043,-0.0735645667},
    {-0.99631262,-0.0857973099},
    {-0.99518472,-0.0980171412},
    {-0.99390697,-0.110222206},
    {-0.99247956,-0.122410677},
    {-0.99090266,-0.134580702},
    {-0.98917651,-0.146730468},
    {-0.98730141,-0.15885815},
    {-0.98527765,-0.170961887},
    {-0.98310548,-0.183039889},
    {-0.98078525,-0.195090324},
    {-0.97831738,-0.207111374},
    {-0.97570211,-0.219101235},
    {-0.97293997,-0.231058106},
    {-0.97003126,-0.242980182},
    {-0.96697646,-0.254865646},
    {-0.96377605,-0.266712755},
    {-0.9604305,-0.27851969},
    {-0.95694035,-0.290284663},
    {-0.95330602,-0.302005947},
    {-0.94952816,-0.313681751},
    {-0.9456073,-0.32531029},
    {-0.94154406,-0.33688986},
    {-0.93733901,-0.34841868},
    {-0.93299282,-0.35989505},
    {-0.92850608,-0.37131721},
    {-0.9238795,-0.38268343},
    {-0.91911387,-0.39399204},
    {-0.91420978,-0.40524131},
    {-0.909168,-0.41642955},
    {-0.90398932,-0.42755508},
    {-0.89867449,-0.43861625},
    {-0.8932243,-0.44961134},
    {-0.88763964,-0.46053872},
    {-0.88192129,-0.47139674},
    {-0.87607008,-0.48218378},
    {-0.87008697,-0.4928982},
    {-0.86397284,-0.50353837},
    {-0.8577286,-0.51410276},
    {-0.8513552,-0.52458966},
    {-0.84485358,-0.53499764},
    {-0.83822471,-0.54532498},
    {-0.8314696,-0.55557024},
    {-0.82458931,-0.56573182},
    {-0.81758481,-0.57580817},
    {-0.81045717,-0.58579785},
    {-0.80320752,-0.59569931},
    {-0.79583693,-0.60551107},
    {-0.78834641,-0.61523157},
    {-0.78073722,-0.62485951},
    {-0.77301043,-0.63439327},
    {-0.76516724,-0.64383155},
    {-0.75720882,-0.65317285},
    {-0.74913639,-0.6624158},
    {-0.74095112,-0.67155898},
    {-0.73265427,-0.680601},
    {-0.7242471,-0.68954057},
    {-0.71573085,-0.69837624},
    {-0.70710677,-0.70710677},
    {-0.69837624,-0.71573085},
    {-0.68954057,-0.7242471},
    {-0.680601,-0.73265427},
    {-0.67155898,-0.74095112},
    {-0.6624158,-0.74913639},
    {-0.65317285,-0.75720882},
    {-0.64383155,-0.76516724},
    {-0.63439327,-0.77301043},
    {-0.62485951,-0.78073722},
    {-0.61523157,-0.78834641},
    {-0.60551107,-0.79583693},
    {-0.59569931,-0.80320752},
    {-0.58579785,-0.81045717},
    {-0.57580817,-0.81758481},
    {-0.56573182,-0.82458931},
    {-0.55557024,-0.8314696},
    {-0.54532498,-0.83822471},
    {-0.53499764,-0.84485358},
    {-0.52458966,-0.8513552},
    {-0.51410276,-0.8577286},
    {-0.50353837,-0.86397284},
    {-0.4928982,-0.87008697},
    {-0.48218378,-0.87607008},
    {-0.47139674,-0.88192129},
    {-0.46053872,-0.88763964},
    {-0.44961134,-0.8932243},
    {-0.43861625,-0.89867449},
    {-0.42755508,-0.90398932},
    {-0.41642955,-0.909168},
    {-0.40524131,-0.91420978},
    {-0.39399204,-0.91911387},
    {-0.38268343,-0.9238795},
    {-0.37131721,-0.92850608},
    {-0.35989505,-0.93299282},
    {-0.34841868,-0.93733901},
    {-0.33688986,-0.94154406},
    {-0.32531029,-0.9456073},
    {-0.313681751,-0.94952816},
    {-0.302005947,-0.95330602},
    {-0.290284663,-0.95694035},
    {-0.27851969,-0.9604305},
    {-0.266712755,-0.96377605},
    {-0.254865646,-0.96697646},
    {-0.242980182,-0.97003126},
    {-0.231058106,-0.97293997},
    {-0.219101235,-0.97570211},
    {-0.207111374,-0.97831738},
    {-0.195090324,-0.98078525},
    {-0.183039889,-0.98310548},
    {-0.170961887,-0.98527765},
    {-0.15885815,-0.98730141},
    {-0.146730468,-0.98917651},
    {-0.134580702,-0.99090266},
    {-0.122410677,-0.99247956},
    {-0.110222206,-0.99390697},
    {-0.0980171412,-0.99518472},
    {-0.0857973099,-0.99631262},
    {-0.0735645667,-0.99729043},
    {-0.061320737,-0.9981181},
    {-0.0490676761,-0.99879545},
    {-0.0368072242,-0.99932235},
    {-0.02454122901,-0.99969882},
    {-0.01227153838,-0.99992472},
    {0.0,-1.0},
    {0.01227153838,-0.99992472},
    {0.02454122901,-0.99969882},
    {0.0368072242,-0.99932235},
    {0.0490676761,-0.99879545},
    {0.061320737,-0.9981181},
    {0.0735645667,-0.99729043},
    {0.0857973099,-0.99631262},
    {0.0980171412,-0.99518472},
    {0.110222206,-0.99390697},
    {0.122410677,-0.99247956},
    {0.134580702,-0.99090266},
    {0.146730468,-0.98917651},
    {0.15885815,-0.98730141},
    {0.170961887,-0.98527765},
    {0.183039889,-0.98310548},
    {0.195090324,-0.98078525},
    {0.207111374,-0.97831738},
    {0.219101235,-0.97570211},
    {0.231058106,-0.97293997},
    {0.242980182,-0.97003126},
    {0.254865646,-0.96697646},
    {0.266712755,-0.96377605},
    {0.27851969,-0.9604305},
    {0.290284663,-0.95694035},
    {0.302005947,-0.95330602},
    {0.313681751,-0.94952816},
    {0.32531029,-0.9456073},
    {0.33688986,-0.94154406},
    {0.34841868,-0.93733901},
    {0.35989505,-0.93299282},
    {0.37131721,-0.92850608},
    {0.38268343,-0.9238795},
    {0.39399204,-0.91911387},
    {0.40524131,-0.91420978},
    {0.41642955,-0.909168},
    {0.42755508,-0.90398932},
    {0.43861625,-0.89867449},
    {0.44961134,-0.8932243},
    {0.46053872,-0.88763964},
    {0.47139674,-0.88192129},
    {0.48218378,-0.87607008},
    {0.4928982,-0.87008697},
    {0.50353837,-0.86397284},
    {0.51410276,-0.8577286},
    {0.52458966,-0.8513552},
    {0.53499764,-0.84485358},
    {0.54532498,-0.83822471},
    {0.55557024,-0.8314696},
    {0.56573182,-0.82458931},
    {0.57580817,-0.81758481},
    {0.58579785,-0.81045717},
    {0.59569931,-0.80320752},
    {0.60551107,-0.79583693},
    {0.61523157,-0.78834641},
    {0.62485951,-0.78073722},
    {0.63439327,-0.77301043},
    {0.64383155,-0.76516724},
    {0.65317285,-0.75720882},
    {0.6624158,-0.74913639},
    {0.67155898,-0.74095112},
    {0.680601,-0.73265427},
    {0.68954057,-0.7242471},
    {0.69837624,-0.71573085},
    {0.70710677,-0.70710677},
    {0.71573085,-0.69837624},
    {0.7242471,-0.68954057},
    {0.73265427,-0.680601},
    {0.74095112,-0.67155898},
    {0.74913639,-0.6624158},
    {0.75720882,-0.65317285},
    {0.76516724,-0.64383155},
    {0.77301043,-0.63439327},
    {0.78073722,-0.62485951},
    {0.78834641,-0.61523157},
    {0.79583693,-0.60551107},
    {0.80320752,-0.59569931},
    {0.81045717,-0.58579785},
    {0.81758481,-0.57580817},
    {0.82458931,-0.56573182},
    {0.8314696,-0.55557024},
    {0.83822471,-0.54532498},
    {0.84485358,-0.53499764},
    {0.8513552,-0.52458966},
    {0.8577286,-0.51410276},
    {0.86397284,-0.50353837},
    {0.87008697,-0.4928982},
    {0.87607008,-0.48218378},
    {0.88192129,-0.47139674},
    {0.88763964,-0.46053872},
    {0.8932243,-0.44961134},
    {0.89867449,-0.43861625},
    {0.90398932,-0.42755508},
    {0.909168,-0.41642955},
    {0.91420978,-0.40524131},
    {0.91911387,-0.39399204},
    {0.9238795,-0.38268343},
    {0.92850608,-0.37131721},
    {0.93299282,-0.35989505},
    {0.93733901,-0.34841868},
    {0.94154406,-0.33688986},
    {0.9456073,-0.32531029},
    {0.94952816,-0.313681751},
    {0.95330602,-0.302005947},
    {0.95694035,-0.290284663},
    {0.9604305,-0.27851969},
    {0.96377605,-0.266712755},
    {0.96697646,-0.254865646},
    {0.97003126,-0.242980182},
    {0.97293997,-0.231058106},
    {0.97570211,-0.219101235},
    {0.97831738,-0.207111374},
    {0.98078525,-0.195090324},
    {0.98310548,-0.183039889},
    {0.98527765,-0.170961887},
    {0.98730141,-0.15885815},
    {0.98917651,-0.146730468},
    {0.99090266,-0.134580702},
    {0.99247956,-0.122410677},
    {0.99390697,-0.110222206},
    {0.99518472,-0.0980171412},
    {0.99631262,-0.0857973099},
    {0.99729043,-0.0735645667},
    {0.9981181,-0.061320737},
    {0.99879545,-0.0490676761},
    {0.99932235,-0.0368072242},
    {0.99969882,-0.02454122901},
    {0.99992472,-0.01227153838}
};

inline void mul_Wi (complex *x, unsigned int i)
{
    complex temp;
    temp.real = W[i].real;
    temp.imag = W[i].imag;
    mul(x,temp);
    return;
}

inline void butterfly (complex *x0, complex *x1, unsigned int i)
{
	complex temp;
	mul_Wi(x1,i);
	temp = *x0;
	add(x0,*x1);
	neg(x1);
	add(x1,temp);
	return;
}

inline void fft (void)
{
	unsigned int i, j, x1i,x2i,index;
	for (i = 0; i < radix; i++)
		for (j = 0; j < (1 << (radix - 1)); j++)
		{
			x1i = (((((unsigned int)(1)) << i) - 1) & j) | ((~((((unsigned int)(1)) << (i + 1)) - 1)) & (j << 1));
			x2i = x1i | (((unsigned int)(1)) << i);
			index = (j*(1 << ((radix - 1) - i))) & ((fft_N >> 1) - 1);
			butterfly(&(fft_adc.fft_results[x1i]),&(fft_adc.fft_results[x2i]),index);
		}
}

#pragma warn-
unsigned int anagram (unsigned int x)
{
#asm
	push r26
	push r27
	push r28
	ld r26,y
	ldd r27,y+1
	clr r30
	clr r31
	ldi r28,LOW(9)
anagram_loop:
	ror r27
	ror r26
	rol r30
	rol r31
	dec r28
	brne anagram_loop
	pop r28
	pop r27
	pop r26
#endasm
}
#pragma warn+

inline void rearrange_adc_data (void)
{
    unsigned int i;
    for (i = 0; i < fft_N; i++)
        fft_adc.adc_data[i] = (((unsigned int)(fft_adc.adc_bytes[2*fft_N + anagram(i)])) & 0x00FF)
            | ((((unsigned int)(fft_adc.adc_bytes[3*fft_N + anagram(i)])) << 8) & 0xFF00);
}

inline void cast_to_complex (void)
{
	signed int i;
	for (i = fft_N - 1; i >= 0; i--)
	{
		fft_adc.fft_results[i].real = ((float)(fft_adc.adc_data[i] - adca_offset))*
            Vref/2048.0/((float)(((unsigned int)(1)) << gain_index))/fft_N;
		fft_adc.fft_results[i].imag = 0.0;
	}
}

inline void abs_fft (void)
{
    unsigned int i;
    for (i = 0; i < (fft_N >> 1); i++)
        fft_adc.fft_abs[i] =
            (*units[current_unit].abs_fft_fcn)(fft_adc.fft_results[i].real*fft_adc.fft_results[i].real +
            fft_adc.fft_results[i].imag*fft_adc.fft_results[i].imag);
}

inline void convert_for_dac (void)
{
    unsigned int i;
    for (i = 0; i < (fft_N >> 1); i++)
        fft_adc.fft_abs[i] = abs_to_dac_coeff1*fft_adc.fft_abs[i] + abs_to_dac_coeff0;
}

signed int nearest_si (float input)
{
    if (input >= 32766.5)
        return 32767;
    if (input < -32767.5)
        return -32768;
    if (input >= 0)
    {
        if ((input - floor(input)) < 0.5)
            return ((signed int)(input));
        return ((signed int)(input)) + 1;
    }
    if ((input - floor(input)) < 0.5)
        return ((signed int)(input)) - 1;
    return ((signed int)(input));
}

unsigned char ucmax (float input1, float input2)
{
    if (input1 > input2)
    {
        if (input1 > 255.0)
            return 255;
        if (input1 < 0.0)
            return 0;
        return nearest_si(input1);
    }
    if (input2 > 255.0)
        return 255;
    if (input2 < 0.0)
        return 0;
    return nearest_si(input2);
}

unsigned char ucmin (float input1, float input2)
{
    if (input1 < input2)
    {
        if (input1 > 255.0)
            return 255;
        if (input1 < 0.0)
            return 0;
        return nearest_si(input1);
    }
    if (input2 > 255.0)
        return 255;
    if (input2 < 0.0)
        return 0;
    return nearest_si(input2);
}

unsigned char ucmax3 (float input1, float input2, float input3)
{
    if ((input1 > input2) && (input1 > input3))
    {
        if (input1 > 255.0)
            return 255;
        if (input1 < 0.0)
            return 0;
        return nearest_si(input1);
    }
    if (input2 > input3)
    {
        if (input2 > 255.0)
            return 255;
        if (input2 < 0.0)
            return 0;
        return nearest_si(input2);
    }
    if (input3 > 255.0)
        return 255;
    if (input3 < 0.0)
        return 0;
    return nearest_si(input3);
}

unsigned char ucmin3 (float input1, float input2, float input3)
{
    if ((input1 < input2) && (input1 < input3))
    {
        if (input1 > 255.0)
            return 255;
        if (input1 < 0.0)
            return 0;
        return nearest_si(input1);
    }
    if (input2 < input3)
    {
        if (input2 > 255.0)
            return 255;
        if (input2 < 0.0)
            return 0;
        return nearest_si(input2);
    }
    if (input3 > 255.0)
        return 255;
    if (input3 < 0.0)
        return 0;
    return nearest_si(input3);
}

//______________________________________________________________MAIN____________________________________________________________
void main(void)
{
// Declare your local variables here
unsigned char n;
unsigned int i;

do {
    // Interrupt system initialization
    // Optimize for speed
#pragma optsize- 
    // Make sure the interrupts are disabled
#asm("cli")
    // Low level interrupt: On
    // Round-robin scheduling for low level interrupt: Off
    // Medium level interrupt: On
    // High level interrupt: On
    // The interrupt vectors will be placed at the start of the Application FLASH section
    n=(PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
    	PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
    CCP=CCP_IOREG_gc;
    PMIC.CTRL=n;
    // Set the default priority for round-robin scheduling
    PMIC.INTPRI=0x00;
    // Restore optimization for size if needed
#pragma optsize_default
    
    // System clocks initialization
    system_clocks_init();
    
    // Event system initialization
    event_system_init();
    
    // Ports initialization
    ports_init();
    
    // Virtual Ports initialization
    vports_init();
    
    // Timer/Counter TCC0 initialization
    tcc0_init();
    
    // Timer/Counter TCD0 initialization
    tcd0_init();
    
    // Timer/Counter TCE0 initialization
    tce0_init();
    
    // Timer/Counter TCE1 initialization
    tce1_init();
    
    // Timer/Counter TCF0 initialization
    tcf0_init();
    
    // ADCA initialization
    adca_init((gain_index << 2) & 0b00011100);
    
    // Alphanumeric LCD initialization
    // Connections specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTE Bit 0
    // RD - PORTE Bit 1
    // EN - PORTE Bit 2
    // D4 - PORTE Bit 4
    // D5 - PORTE Bit 5
    // D6 - PORTE Bit 6
    // D7 - PORTE Bit 7
    // Characters/line: 16
    lcd_init(16);
    delay_ms(500);
    lcd_clear();
    lcd_putsf("MzZ");
    delay_ms(1000);
    lcd_clear();
    
    TCF0.CNT = 0x0000;
    TCF0.INTFLAGS = 0x01;
    TCF0.CTRLA = 0x00;

    menu_display_calib();
    
} while(0);

// Globally enable interrupts
#asm("sei")

    while (current_menu_state == menu_state_calib);
    lcd_clear();
    while (1)
    {
        // Place your code here
        while (sampling_state != SAMPLING_STATE_FFT);
        rearrange_adc_data();
        cast_to_complex();
        fft();
        abs_fft();
        convert_for_dac();
        sampling_state = SAMPLING_STATE_UPDATING;
        dac_inputs_max[255] = ucmax(fft_adc.fft_abs[0],(fft_adc.fft_abs[0] + fft_adc.fft_abs[1])*0.5);
        dac_inputs_min[255] = ucmin(fft_adc.fft_abs[0],(fft_adc.fft_abs[0] + fft_adc.fft_abs[1])*0.5);
        for (i = 1; i < 255; i++)
        {
            dac_inputs_max[255 - i] = ucmax3(fft_adc.fft_abs[i],(fft_adc.fft_abs[i] + fft_adc.fft_abs[i + 1])*0.5,
                (fft_adc.fft_abs[i] + fft_adc.fft_abs[i - 1])*0.5);
            dac_inputs_min[255 - i] = ucmin3(fft_adc.fft_abs[i],(fft_adc.fft_abs[i] + fft_adc.fft_abs[i + 1])*0.5,
                (fft_adc.fft_abs[i] + fft_adc.fft_abs[i - 1])*0.5);
        }
        dac_inputs_max[0] = ucmax(fft_adc.fft_abs[255],(fft_adc.fft_abs[255] + fft_adc.fft_abs[254])*0.5);
        dac_inputs_min[0] = ucmin(fft_adc.fft_abs[255],(fft_adc.fft_abs[255] + fft_adc.fft_abs[254])*0.5);
        sampling_state = SAMPLING_STATE_IDLE;
    }
}
