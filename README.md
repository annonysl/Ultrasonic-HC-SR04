# Ultrasonic-HC-SR04
Ultrasonic-HC-SR04 sensor library for ArduinoIDE


Check the example code for help.

You can set the max distance as

    Ultrasonic ultra(TrigPin,EchoPin,TimeOut)

    entering timeOut duration
    TimeOut=58*max distance in cm.
Or you can use the default max distance is set to 75cm
    
    Ultrasonic ultra(TrigPin,EchoPin)

Distance can be easily get in cm or in
   
    Distance(CM);
    Distance(IN);
    
    
Average distance of any amount of readings can be taken easily
   
    AverageIn(numberOfvalues); //in Cm
    AverageCm(numberOfvalues); //in Inch
