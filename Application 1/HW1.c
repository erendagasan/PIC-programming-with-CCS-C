#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPROTECT
#use fast_io(d)
#include <stdlib.h>
#include <math.h>
#byte PORTD =0x08
#byte TRISD =0x88
int16 dig_veri;
float analog_temp;
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
{  srand(32312);
   setup_cfg();
   set_tris_d(0x00);
   output_d(0x00);
   
   int sayac = 0;
while(1)
   {
      PORTD = rand();
      delay_ms(3000);
      PORTD =(PORTD ^ (1 << 0));
      PORTD =(PORTD ^ (1 << 6));
      delay_ms(3000);
      PORTD = (PORTD | (1 << 1)| (1 << 2) | (1 << 3))  ;
      delay_ms(3000);
      PORTD = (PORTD & (~(1 << 4))) | (PORTD & (~(1 << 5))) |(PORTD & (~(1 << 6))) ;
      delay_ms(3000);
   }
  
}



