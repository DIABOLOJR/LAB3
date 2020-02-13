#include "8 bits.h"
#include <xc.h>
#include <stdint.h>
#define RS  PORTDbits.RD6
#define EN  PORTDbits.RD7
#define TRISRS TRISDbits.TRISD6
#define TRISEN TRISDbits.TRISD7
#define PUERTOTRS TRISB
#define PUERTO PORTB
int dms;
int dus;
void delay_ms(int dms){
    for(int i = 0; i<dms; i++){// ciclo para el aumento en miisegundos.
        for(int j = 0; j<255; j++);
    }
}

void delay_us (int dus){
    for(int i = 0; i<dus; i++);// ciclo para el aumento en microseg
}


void Tiempocontrol (void){
    EN = 1;
    delay_us(5);
    EN = 0;
    delay_us(5);
}

void Control (char valor){
    RS =0;
    PUERTO = valor;
    Tiempocontrol();
    delay_ms(2);
}

void ON (char valor1){
    RS =1;
    PUERTO = valor1;
    Tiempocontrol();
    delay_us(50);
}

void LCDvalue (void){
    TRISRS=0;
    TRISEN=0;
    PUERTOTRS=0;
    RS=0;
    EN=0;
    PUERTO=0;
    delay_ms(50);
    Control(0x02);
    Control(0x38);
    Control(0x0C);
    Control(0x06);
    
}

void impresion (char *valor){
    while (*valor){
        ON(*valor);
        valor++;
    }
}

void lcddirection(int x, int y, char *valor){
    char posicion;
    switch (y) {
        case 1:
            posicion = 0x80 + x;
            break;
        case 2:
            posicion = 0xC0 + x;
            break;
        default:
            posicion = 0x80 +    x;
            break;
    }
    Control (posicion);
    impresion (valor);
}



void clean (void){
    Control(0x01);
}


