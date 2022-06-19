#include <16f877A.h>
#use delay(clock=4000000)
#fuses HS,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG
#use fast_io(d)

void setup_cfg()
{
 setup_psp(PSP_DISABLed);
 setup_spi(SPI_SS_DISABLed);
 setup_timer_1(T1_DISABLed);
 setup_timer_2(T2_DISABLed,0,1);
 setup_adc_ports(NO_ANALOGS);
 setup_adc(ADC_OFF);
 setup_CCP1(CCP_OFF);
 setup_CCP2(CCP_OFF); 
}




void main()
{     
   setup_cfg();
   set_tris_d(0x00);
   output_d(0x00);
   int sayac = 0;
   while(1)
   {
       
     output_d(0xff&(1<<sayac));
     delay_ms(200);
     output_d(0x00&(1<<sayac));
     sayac++;
     if(sayac == 8)
       {
         sayac = 0;       
       }
   }
   

}


