#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
void setup() {
  Serial.begin(9600); 
}

void loop()
{
  Serial.print(ultrasonic.Distance(CM)); // CM or INC
  Serial.println(" cm" );
  delay(100);
  Serial.print(ultrasonic.Distance(IN)); // CM or INC
  Serial.println(" cm" );
  delay(100);
  Serial.println("Taking the average of 10 distance values in cm.....");
  Serial.print(ultrasonic.AverageCm(10)); // change 10 to the number that you need.
  Serial.println("Taking the average of 10 distance values in inch.....");
  Serial.print(ultrasonic.AverageIn(10)); // change 10 to the number that you need.
}
