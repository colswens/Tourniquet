// Stepper Set up
#include <Stepper.h> 
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;


//  Pulse Sensor Variables
int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore. 
//original Threshold 550
 
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  //pins control motor
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  //Onboard LED blinks w hearbeat
  pinMode(LED13,OUTPUT);
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
 
  
  Serial.begin(9600);
  motor.setSpeed(40);
}
 
void loop()
{
  
    Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value. 
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.

   
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     digitalWrite(LED13,HIGH);
     motor.step(100);          
   } else {
     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }


   delay(10);
   
  //motor.step(200);
  //if (Serial.available())
  //{
  //  int steps = Serial.parseInt();
  //  motor.step(steps);
  //}
}
