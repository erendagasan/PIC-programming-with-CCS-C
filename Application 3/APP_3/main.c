#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
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
                   }; 
int i=0;
int sayi = 0;
unsigned int saniye,birler=0,onlar=0,dakika,d_birler=0,d_onlar=0;
#int_timer0
void timer0_kesmesi()
{
   set_timer0(217);
   if(sayi==100)
      {
         i++;
         saniye=i%60;
         birler=saniye%10;
         onlar=saniye/10;

         dakika=i/60;
         d_birler=dakika%10;
         d_onlar=dakika/10;
         sayi=0;
      }
   sayi++;
}
void seven_segment()
{
   output_d(seg[birler]);output_high(pin_c0); 
   delay_ms(1);output_low(pin_c0);     
   output_d(seg[onlar]);output_high(pin_c1); 
   delay_ms(1);output_low(pin_c1);      
   output_d(seg[d_birler]);output_high(pin_c2);
   delay_ms(1);output_low(pin_c2);      
   output_d(seg[d_onlar]);output_high(pin_c4); 
   delay_ms(1);output_low(pin_c4);   
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
   set_tris_b(0x00);
   output_b(0x00);
   set_tris_d(0x00);
   output_d(0);
   set_tris_c(0x00);
   output_c(0);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(217);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   while(true)
   {
      seven_segment();
   }
}







