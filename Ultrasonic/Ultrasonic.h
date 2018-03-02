// Ultrasonic-HR-SC04 arduino module.
// GitHub: https://github.com/anonysl/Ultrasonic-HC-SR04
// This code is openSource and for public use. 
// Created by anonysl.

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM true
#define IN false

class Ultrasonic
{
  public:
  
  Ultrasonic(int TP, int EP,int timeOut);
  Ultrasonic(int TP, int EP);
    long Interval();
    long Distance(boolean unit);
    long AverageCm(int avg);
    long AverageIn(int avg);

  private:
    int tP;
    int eP;
    int maxInterval;
    long duration,disCm,disIn;
};

#endif