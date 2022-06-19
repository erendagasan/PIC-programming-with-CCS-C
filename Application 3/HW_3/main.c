#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(d)
#byte PORTD =0x08
#byte TRISD =0x88
int i=0;
int j=0;
int sayi = 0;

#int_timer0
void timer0_kesmesi()
{
   set_timer0(217);
   if(sayi==50)
      {  
            if(i == 8){i=0;}            
            PORTD^= (128>>i);
            i++;            
      } 
   if(sayi ==80)
   {
            if(j == 8){j=0;}            
            PORTD^= (1<<j);
            j++;    
   sayi=0;
   }
   sayi++;
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
   output_d(0);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(217);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   while(true);

}








