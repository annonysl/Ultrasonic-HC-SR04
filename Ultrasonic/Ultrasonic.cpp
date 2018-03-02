// Ultrasonic-HR-SC04 arduino module.
// GitHub: https://github.com/anonysl/Ultrasonic-HC-SR04
// This code is openSource and for public use. 
// Created by anonysl.

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

#define CM true
#define IN false

Ultrasonic::Ultrasonic(int trigP, int echoP,int timeOut)
{
   pinMode(trigP,OUTPUT);
   pinMode(echoP,INPUT);
   tP=trigP;
   eP=echoP; 
   maxInterval=timeOut;
}

Ultrasonic::Ultrasonic(int trigP, int echoP)
{
   pinMode(trigP,OUTPUT);
   pinMode(echoP,INPUT);
   tP=trigP;
   eP=echoP; 
   maxInterval=4350;
}
long Ultrasonic::Interval()
{
  digitalWrite(tP, LOW);
  delayMicroseconds(2);
  digitalWrite(tP, HIGH);
  delayMicroseconds(10);
  digitalWrite(tP, LOW);
  duration = pulseIn(eP,HIGH,maxInterval);
  if ( duration == 0 ) {
  duration = maxInterval; 
  }
  return duration;
}

long Ultrasonic::Distance(boolean unit)
{
  Interval();
  if (unit) {
  disCm = duration /29 / 2 ;
  return disCm;
  } else {
  disIn = duration / 74 / 2;
  return disIn; 
  }
}

long Ultrasonic::AverageCm(int avg){
  long array[avg]={};
  long sum=0;
  for(int i=0;i<avg;i++){
    Interval();
    array[i]=duration /29 / 2 ;
    sum+=array[i];
    }
    return sum/10;
  }
long Ultrasonic::AverageIn(int avg){
  long array[avg]={};
  long sum=0;
  for(int i=0;i<avg;i++){
    Interval();
    array[i]=duration /74 / 2 ;
    sum+=array[i];
    }
    return sum/10;
  }