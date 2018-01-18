#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
unsigned int Tcount=0;
void delay5s();
void delay10s();
void song1();
void song2();
void song3(); 
void main(void) {
  /* put your own code here */
  


	EnableInterrupts;
	
	DDRH= 0x00;
	DDRB=0xFF;
	DDRP=0xff;
	
	
  DDRT = DDRT | 0x20;
  TSCR2= 0x00;
  TSCR1= 0x80;
  TCTL1=0x04;//(TCTL1 | 0x04) &( ~0x08);
	
	while(1){
		   
	
      	if(PTH==0) {
      	  
        	PTP=0x0E;
          PORTB = 0x3F;
          song1();
          song2();
          song3();
          delay5s();
      	}
      	
      	if(PTH==1) {
      	  
          PTP=0x0E;
          PORTB = 0x06;
          song1();
          delay5s();
      	}
      	 
    	 	if(PTH==2) {
      	  
        	PTP=0x0E;
          PORTB = 0x5B;
          song2();
          delay5s();
    	  }
    	  
    	  if(PTH==3) {
    	  
        	PTP=0x0E;
          PORTB = 0x4F;
          song3();
          delay5s();
    	  }	  
	} //end of while(1)



  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void song1(){

   unsigned int overflows1=0; 
   while(overflows1<5*366){
        TIOS = 0x20;
        TFLG2=0x80;
        TC5= TC5 +12000;
        while(!(TFLG2 & 0x80));
        overflows1 = overflows1 +1;              
   }
                  
   TIOS = 0x00;
}
 
 
 void song2(){

   unsigned int overflows2=0;
   while(overflows2<5*366){
        TIOS = 0x20;
        TFLG2=0x80;
        TC5= TC5 +6000;
        while(!(TFLG2 & 0x80));
        overflows2 = overflows2 +1;              
   }
                  
   TIOS = 0x00;
 }



 void song3(){
 
   unsigned int overflows3=0; 
   
   while(overflows3<5*366){
        TIOS = 0x20;
        TFLG2=0x80;
        TC5= TC5 +24000;
        while(!(TFLG2 & 0x80));
        overflows3 = overflows3 +1;              
   }
                  
   TIOS = 0x00;
           
 } 
 
void delay5s(){  
   unsigned int overflow1=0;
   TSCR1=0x80;
   TSCR2=0x00;
   while(overflow1<1830){
      TFLG2=0x80;
      while(!(TFLG2 & 0x80));
      overflow1 = overflow1 +1;
   }
}


void delay10s(){  
   unsigned int overflow2=0;
   TSCR1=0x80;
   TSCR2=0x00;
   while(overflow2<3660){
      TFLG2=0x80;
      while(!(TFLG2 & 0x80));
      overflow2 = overflow2 +1;
   }
}


    