#include <16f877A.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT
#use fast_io(a)
#use fast_io(c)


void main()
{  


   
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
  
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);

   setup_CCP2(CCP_OFF);
   
   setup_CCP1(ccp_pwm);
   set_tris_a(0b00001111);
   set_tris_c(0x00);
   
   int pwm_period = 124;
   
   setup_timer_2(T2_DIV_BY_4,pwm_period,1);
   
   
   int duty_cycle = 62;
   set_pwm1_duty(duty_cycle);
   while(true)
   {  
      if(input(pin_a0))
      {
      while(input(pin_a0));
      delay_ms(30);
      duty_cycle+=6;
      if(duty_cycle>124)
         {
           duty_cycle=124;
         }
      }
      set_pwm1_duty(duty_cycle);
      
      if(input(pin_a1))
      {
      while(input(pin_a1));
      delay_ms(30);
      duty_cycle-=6;
      if(duty_cycle<6)
         {
           duty_cycle=6;
         }
      set_pwm1_duty(duty_cycle);
      }
      
      
      
      
      if(input(pin_a3))
      {
      while(input(pin_a3));
      delay_ms(30);
      pwm_period+=1;
      if(pwm_period>255)
         {
           pwm_period=255;
         }
         setup_timer_2(T2_DIV_BY_4,pwm_period,1);
      }
      
      if(input(pin_a2))
      {
      while(input(pin_a2));
      delay_ms(30);
      pwm_period-=1;
      
      if(pwm_period<0)
         {
           pwm_period=0;
         }
         setup_timer_2(T2_DIV_BY_4,pwm_period,1);
      }
      
      
      
      
      
      
      
      
      
      
      
      
   }
}
