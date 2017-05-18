#include <avr/io.h>
#include <avr/interrupt.h>
int count=0;

int main(void){
  TCNT0=100;
  TCNT1=34285;
  TIMSK0  |= (1 << TOIE0);
  TIMSK1  |= (1 << TOIE1);
    sei(); 
   TCCR0A=0x00;
  //TCCR0B=0x03;
TCCR0B=0x05;
TCCR1A=0x00;

TCCR1B=0x04;
  DDRB=DDRB|(1<<5);
  DDRB=DDRB|(1<<4);
  PORTB=0xff;
  
  while(1){
  
  }



}

ISR (TIMER0_OVF_vect) // timer0 overflow interrupt
{
   if(count%5==0)
    PORTB=PORTB^(1<<5);
   
 
count++;
}

ISR (TIMER1_OVF_vect) // timer1 overflow interrupt
{
 PORTB=PORTB^(1<<4);
}