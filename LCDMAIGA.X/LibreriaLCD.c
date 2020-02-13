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
            posicion = 0x80 + x;
            break;
    }
    Control (posicion);
    impresion (valor);
}


void valoradc (int x, int z){
    
    switch (z) {
        case 0:
            lcddirection (x,2,"0");
            break;
        case 1:
            lcddirection (x,2,"1");
            break;
        case 2:
            lcddirection (x,2,"2");
            break;
        case 3:
            lcddirection (x,2,"3");
            break;
        case 4:
            lcddirection (x,2,"4");
            break;
        case 5:
            lcddirection (x,2,"5");
            break;
        case 6:
            lcddirection (x,2,"6");
            break;
        case 7:
            lcddirection (x,2,"7");
            break;
        case 8:
            lcddirection (x,2,"8");
            break;
        case 9:
            lcddirection (x,2,"9");
            break;
        case 10:
            lcddirection (x,2,"A");
            break;
        case 11:
            lcddirection (x,2,"B");
            break;
        case 12:
            lcddirection (x,2,"C");
            break;
        case 13:
            lcddirection (x,2,"D");
            break; 
        case 14:
            lcddirection (x,2,"E");
            break;    
        case 15:
            lcddirection (x,2,"F");
            break;    
        default:
            lcddirection (x,2,"0");
            break;
    }
  
}


void clean (void){
    Control(0x01);
}


