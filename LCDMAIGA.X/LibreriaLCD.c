#include "8 bits.h"

#define RS  PORTDbits.RD7
#define EN  PORTDbits.RD6
#define TRISRS TRISDbits.TRISD7
#define TRISEN TRISDbits.TRISD6
#define PUERTOTRS TRISB
#define PUERTO PORTB

int value;
void Tiempocontrol (void){
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_us(5);
}

void Control (char valor){
    RS =0;
    PUERTO = valor & 0xF0;
    Tiempocontrol();
    PUERTO =((valor & 0xF0)<<4);
    Tiempocontrol();
    __delay_ms(2);
}
void LCDvalue (void){
    TRISRS=0;
    TRISEN=0;
    PUERTOTRS= 0b11111111;
    RS=0;
    EN=0;
    PUERTO=0;
    __delay_ms(50);
    Control(0x02);
    Control(0x28);
    Control(0x0C);
    Control(0x06);
    
}

void clean (void){
    Control(0x01);
}