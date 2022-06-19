#include <16f877A.h>
#use delay(clock=4M)
#fuses XT,NOWDT,NOPROTECT,HS
#use fast_io(d)
#use fast_io(c)
#include <stdlib.h>
#include <math.h>
#byte PORTD =0x00
#byte TRISD =0x00
#byte PORTC =0x00
#byte TRISC =0x00
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


void main()
{  
setup_cfg();
set_tris_d(0x00);
output_d(0);
set_tris_c(0x00);
output_c(0);
unsigned int saniye,birler=0,onlar=0,dakika,d_birler=0,d_onlar=0;
int i = 0; 
int flag =0; 

unsigned int seg[]={ 
                    0xFC, //0  
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


                   }; 

while(1)
{

saniye=i%60;
birler=saniye%10;
onlar=saniye/10;

dakika=i/60;
d_birler=dakika%10;
d_onlar=dakika/10;

output_d(seg[birler]);output_high(pin_c0); 
delay_ms(5);output_low(pin_c0);     
output_d(seg[onlar]);output_high(pin_c1); 
delay_ms(5);output_low(pin_c1);      
output_d(seg[d_birler]);output_high(pin_c2);
delay_ms(5);output_low(pin_c2);      
output_d(seg[d_onlar]);output_high(pin_c4); 
delay_ms(5);output_low(pin_c4);    


if(flag>=100) 
{
    i++;flag=0; 
}
flag++; 
}}

   
  







