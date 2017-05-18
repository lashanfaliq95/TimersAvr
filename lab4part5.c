#include <avr/io.h>
#include <avr/interrupt.h>
int count=0;

int main(void){
  TCNT1=3036;
  
  TIMSK1  |= (1 << TOIE1);
    sei(); 
    TCCR1B |= (1 << CS12); 
  DDRB=DDRB|(1<<5);
  PORTB=0xff;
  PORTC=0xff;
  while(1){
  
  }



}

ISR (TIMER1_OVF_vect) // timer0 overflow interrupt
{
   
    PORTB=PORTB^(1<<5);
   
   if(count%6==0)
    PORTC=0b00010000;
    if(count%6==1 || count%6==5)
    PORTC=0b00001000;
  if(count%6==2 || count%6==4)
    PORTC=0b00000100;
  if(count%6==3)
    PORTC=0b00000010;

count++;
}
