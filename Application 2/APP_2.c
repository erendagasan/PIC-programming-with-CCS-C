#include <16f877A.h>
#use delay(clock=4M)
#fuses XT,NOWDT,NOPROTECT,HS
#use fast_io(d)
#use fast_io(c)
#use fast_io(b)
#include <stdlib.h>
#include <math.h>
#byte PORTD =0x00
#byte TRISD =0x00
#byte PORTC =0x00
#byte TRISC =0x00
#byte PORTB =0x00
#byte TRISB =0x00

unsigned int seg[]={ 
                   
                    0x60, //1
                    0xDA, //2
                    0xF2, //3
                    0x66, //4
                    0xB6, //5
                    0xBE, //6
                    0xE0, //7
                    0xFE, //8
                    0xF6, //9
                    0xEE, //A
                    0x3E, //b
                    0x9C, //C
                    0x7A  //D
                    0xFC, //0
                   }; 
void setup_cfg()
{
 setup_psp(PSP_DISABLed);
 setup_spi(SPI_SS_DISABLed);
 setup_timer_1(T1_DISABLed);
 setup_timer_2(T2_DISABLed,0,1);
 setup_adc_ports(ALL_ANALOG);
 setup_adc(ADC_CLOCK_INTERNAL);
 setup_CCP1(CCP_OFF);
 setup_CCP2(CCP_OFF); 
}
unsigned int segmen[4]={0};
unsigned int segmen1_y=0, segmen2_y=0, segmen3_y=0, segmen4_y=0;

void seven_segment_tarama()
{
     output_d(seg[segmen[0]-1]);output_high(pin_c0); 
     delay_ms(2);output_low(pin_c0); 
    
     output_d(seg[segmen[1]-1]);output_high(pin_c1);
     delay_ms(2);output_low(pin_c1);      

     output_d(seg[segmen[2]-1]);output_high(pin_c2);
     delay_ms(2);output_low(pin_c2);   

     output_d(seg[segmen[3]-1]);output_high(pin_c4); 
     delay_ms(2);output_low(pin_c4);  
}


int tus_oku(){
output_b(0x00);
            output_high(pin_b3);
            if (input(pin_b4) == 1) {delay_ms(2); while (input(pin_b4) == 1){seven_segment_tarama();};return 10; }
            if (input(pin_b5) == 1) {delay_ms(2); while (input(pin_b5) == 1){seven_segment_tarama();}; return 3; }
            if (input(pin_b6) == 1) {delay_ms(2); while (input(pin_b6) == 1){seven_segment_tarama();}; return 2; }
            if (input(pin_b7) == 1) {delay_ms(2); while (input(pin_b7) == 1){seven_segment_tarama();}; return 1 ; } //'A'
            output_high(pin_b2);
            if (input(pin_b4) == 1) {delay_ms(2); while (input(pin_b4) == 1){seven_segment_tarama();};return 11; }
            if (input(pin_b5) == 1) {delay_ms(2); while (input(pin_b5) == 1){seven_segment_tarama();}; return 6; }
            if (input(pin_b6) == 1) {delay_ms(2); while (input(pin_b6) == 1){seven_segment_tarama();}; return 5; }
            if (input(pin_b7) == 1) {delay_ms(2); while (input(pin_b7) == 1){seven_segment_tarama();}; return 4 ; } //'b'
            output_high(pin_b1);
            if (input(pin_b4) == 1) {delay_ms(2); while (input(pin_b4) == 1){seven_segment_tarama();};return 12; }
            if (input(pin_b5) == 1) {delay_ms(2); while (input(pin_b5) == 1){seven_segment_tarama();}; return 9; }
            if (input(pin_b6) == 1) {delay_ms(2); while (input(pin_b6) == 1){seven_segment_tarama();}; return 8; }
            if (input(pin_b7) == 1) {delay_ms(2); while (input(pin_b7) == 1){seven_segment_tarama();}; return 7 ; } //'C'
            output_high(pin_b0);
            if (input(pin_b4) == 1) {delay_ms(2); while (input(pin_b4) == 1){seven_segment_tarama();};return 13; }

            if (input(pin_b6) == 1) {delay_ms(2); while (input(pin_b6) == 1){seven_segment_tarama();}; return 14; }
            
            
           
   }


void main()
{  
setup_cfg();
set_tris_d(0x00);
output_d(0);
set_tris_c(0x00);
output_c(0);
set_tris_b(0b11110000);
int counter=0;

while(1)
{

if(tus_oku())
{ 

       segmen[3]=segmen[2];
       segmen[2]=segmen[1];
       segmen[1]=segmen[0];
      segmen[0]=tus_oku();
  
}

output_d(seg[segmen[0]-1]);output_high(pin_c0); 
delay_ms(2);output_low(pin_c0); 
    
output_d(seg[segmen[1]-1]);output_high(pin_c1); 
delay_ms(2);output_low(pin_c1);      

output_d(seg[segmen[2]-1]);output_high(pin_c2);
delay_ms(2);output_low(pin_c2);   

output_d(seg[segmen[3]-1]);output_high(pin_c4); 
delay_ms(2);output_low(pin_c4);    
}

}


