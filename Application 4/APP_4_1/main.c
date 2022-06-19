#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(b)
#use fast_io(d)
#byte PORTD =0x08
#int_ext
void kesme()
{
     PORTD ^= 0b11111111;
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
   
   set_tris_b(0x01);
   output_b(0x00);

   set_tris_d(0x00);
   output_d(0x00);

   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   while(true)
   {
      
   }
}
