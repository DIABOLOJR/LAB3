#include "ADC.h"

int canal;
void ADC (int canal){
    switch (canal){
        case 0:
            ADCON1=0;
            ADCON0=0b01000001;
            break;
    
        case 1:
            ADCON1=0;
            ADCON0=0b01000101;
            break;}
}
