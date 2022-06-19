#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(b)
#use fast_io(d)
int sayi=0;
#int_ext
void kesme()
{          
            output_b(0x00);
           
            output_high(pin_b4);         
            if (input(pin_b1) == 1) {delay_ms(2); while (input(pin_b1) == 1); sayi= 1; }
            if (input(pin_b2) == 1) {delay_ms(2); while (input(pin_b2) == 1); sayi= 4; }
            if (input(pin_b3) == 1) {delay_ms(2); while (input(pin_b3) == 1); sayi= 7 ; } 
            output_low(pin_b4);    
            
            output_high(pin_b5);         
            if (input(pin_b1) == 1) {delay_ms(2); while (input(pin_b1) == 1); sayi= 2; }
            if (input(pin_b2) == 1) {delay_ms(2); while (input(pin_b2) == 1); sayi= 5; }
            if (input(pin_b3) == 1) {delay_ms(2); while (input(pin_b3) == 1); sayi= 8 ; }        
            output_low(pin_b5); 
            
             output_high(pin_b6); 
            if (input(pin_b1) == 1) {delay_ms(2); while (input(pin_b1) == 1); sayi= 3; }
            if (input(pin_b2) == 1) {delay_ms(2); while (input(pin_b2) == 1); sayi= 6; }
            if (input(pin_b3) == 1) {delay_ms(2); while (input(pin_b3) == 1); sayi= 9 ; } 
            output_low(pin_b6); 
            
            for(int i = 0; i<sayi; i++)
            {
              output_high(pin_d0);
              delay_ms(650);
              output_low(pin_d0);
              delay_ms(650);            
            }            
            sayi=0;
            
            output_b(0b01110000);
            
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
   set_tris_b(0b00001111);
   output_b(0b01110000);
   output_d(0x00);
   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);

   while(true)
   {
      
   }
}
