#include <16f877A.h>
#include <stdint.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(d)



unsigned int duty_cycle = 10;
unsigned int counter=0;
#int_timer0
void timer0_kesmesi()
{  
   set_timer0(250);


   if(counter < duty_cycle)
   {
   output_high(pin_d0);
  
   }


   if(counter >= duty_cycle)
   {
   output_low(pin_d0);
   }

   
    counter++;
   
   
   if(counter==100)
   {
      
   counter=0;
   }


   


}


void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);

   set_tris_d(0x00);



   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8);
   set_timer0(250);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   
   

   
   while(true)
   {
 
   }
}








