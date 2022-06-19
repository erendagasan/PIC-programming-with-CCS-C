#define LCD_ENABLE_PIN  PIN_C2  
#define LCD_RS_PIN      PIN_C0                          
#define LCD_RW_PIN      PIN_C1 
#include <16f877A.h>
#fuses HS, PUT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP
#device ADC=10
#use delay(clock=4M)
#include <lcd.c>              
#define LCD_DATA4       PIN_D4                       
#define LCD_DATA5       PIN_D5                         
#define LCD_DATA6       PIN_D6 
#define LCD_DATA7       PIN_D7
void ADC_read()
{
setup_ADC(ADC_clock_div_32);
setup_ADC_ports(AN0);
set_ADC_channel(0);
delay_ms(100);
}

void main()
{

int sicaklik_gerilim;
int sicaklik;
set_tris_a(0xff);
lcd_init();
ADC_read();

while(true)
{
   sicaklik_gerilim = read_adc();
   sicaklik = 500*sicaklik_gerilim/1023;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"SICAKLIK:%d%cC",sicaklik,223);
   delay_ms(1000);
}
}
