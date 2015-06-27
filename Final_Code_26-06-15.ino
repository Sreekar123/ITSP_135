// ITSP Project Code, IIT Bombay
// Automated Solar Water Pump System
// Team ID : 135
// Team Shadow

#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11); 
int enablepin=13; 
int motorpin1=4;
int motorpin2=8;
int inputvalue; 

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("Please press 1 to switch on the motor and 2 to turn it off...");
  pinMode(enablepin,OUTPUT);
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  digitalWrite(enablepin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Genotronex.available()){
   inputvalue=Genotronex.read();
   if(inputvalue=='1'){   // if number 1 pressed ....
   digitalWrite(motorpin1,HIGH);
   digitalWrite(motorpin2,LOW);
   Genotronex.println("Motor is on ...");
   }
   else
   if (inputvalue=='0'){// if number 0 pressed ....
   digitalWrite(motorpin1,LOW);
   digitalWrite(motorpin2,LOW);
   Genotronex.println("Motor is off ...");
  }
}
delay(100);// prepare for next data ...
}

