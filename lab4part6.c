#include <avr/io.h>
#include <avr/interrupt.h>
int count=0;

int main(void){
  TCNT0=100;
  
  TIMSK0  |= (1 << TOIE0);
    sei(); 
   TCCR0A=0x00;
  //TCCR0B=0x03;
TCCR0B=0x05;
  DDRB=DDRB|(1<<5);
  PORTB=0xff;
  
  while(1){
  
  }



}

ISR (TIMER0_OVF_vect) // timer0 overflow interrupt
{
   if(count%10==0)
    PORTB=PORTB^(1<<5);
   
 
count++;
}
