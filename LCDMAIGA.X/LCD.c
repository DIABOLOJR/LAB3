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
#include "ADC.h"
#define _XTAL_FREQ 4000000

int dios;
int maria;
int jose;
int v1;
int v2;
int v3;
int v4;

/*
 *Variables y asignaciones previas
 */
//int eADC;

void darules (void){
    ANSEL = 0b00000011;
    ANSELH=0;
    TRISA = 0b00000011;
    ADC(0);
    delay_ms(50);
    dios = 1;
    
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;
    INTCONbits.GIE = 1;
    ADCON0bits.GO_DONE=1;

}


void __interrupt () isr (void){
    if (PIR1bits.ADIF == 1){
       if (dios ==1 ){
           dios =0;
       }
       else if(dios == 0){
           dios=1;
       }
       PIR1bits.ADIF =0;
    }
}
 


void CONVERSIOADC (void){
    if (dios == 1){
        maria = ADRESH;
        ADC(0);
        delay_ms(50);
        ADCON0bits.GO_DONE=1;
    }
    if (dios == 0){
        jose = ADRESH;
        ADC(1);
        delay_ms(50);
        ADCON0bits.GO_DONE=1;
    }
}

void nibbles(void){
    v1 = maria & 0b00001111;
    v2 = maria & 0b11110000;
    v2 = v2>>4;
    v3 = jose & 0b00001111;
    v4 = jose & 0b11110000;
    v4 = v4>>4;
            
}

void main(void) {
    darules();
    LCDvalue();/*Inicio de LCD*/
    delay_ms(130);
    lcddirection(0,1,"ESTUARDO MANCIO");
    delay_ms(130);
    lcddirection(0,2,"18027");
    delay_ms(500);
    lcddirection(0,1," ADC1 ADC2 CONT ");
    lcddirection(0,2,"                ");
    while (1){
        CONVERSIOADC();
        nibbles();
        valoradc (3, v1);
        valoradc (2, v2);
        valoradc (8, v3);
        valoradc (7, v4);
        
    }
    return;
}
