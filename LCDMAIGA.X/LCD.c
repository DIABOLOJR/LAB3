// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
// Configuración del PIC
#pragma config FOSC = INTRC_CLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
 
/*
 *Bibliotecas
 */
#include <xc.h>
#include <stdint.h>
#include "8 bits.h"
#define _XTAL_FREQ 4000000


/*
 *Variables y asignaciones previas
 */
//int eADC;



/*
void __interrupt () isr (void){
    if (ADCON0bits.GO_DONE == 0){
       eADC = 1;
       PIR1bits.ADIF =0;
    }
}
 */





void main(void) {
    LCDvalue();/*Inicio de LCD*/
    impresion("HOLA");
    delay_ms(130);
    lcddirection(6,1,"EGMR");
    delay_ms(130);
    lcddirection(6,2,"JR");    
 
    while (1){}
    return;
}
