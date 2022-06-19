#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(b)
#use fast_io(d)
#int_rb
void kesme()
{  
     if(input(pin_b4)){output_high(pin_d4); delay_ms(2000); output_low(pin_d4);}
     if(input(pin_b5)){output_high(pin_d5); delay_ms(2000); output_low(pin_d5);}
     if(input(pin_b6)){output_high(pin_d6); delay_ms(2000); output_low(pin_d6);}
     if(input(pin_b7)){output_high(pin_d7); delay_ms(2000); output_low(pin_d7);}
     output_b(0x00);
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
   set_tris_b(0xF0);
   output_b(0x00);
   set_tris_d(0x00);
   output_d(0x00);
   ext_int_edge(L_TO_H);
   enable_interrupts(int_rb);
   enable_interrupts(GLOBAL);
   while(true)
   {
      
   }
}
