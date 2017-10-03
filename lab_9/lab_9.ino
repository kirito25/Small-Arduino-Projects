/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int stop_val = 90;
int pot_pin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int motor_pin = 9;

void setup() {
//  pinMode(pot_pin, INPUT);
  pinMode(motor_pin, OUTPUT);
  myservo.attach(motor_pin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
//  val = analogRead(pot_pin);            // reads the value of the potentiometer (value between 0 and 1023)
//  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//  myservo.write(val);                  // sets the servo position according to the scaled value
  //delay(1500);    // waits for the servo to get there
  myservo.write(stop_val);
  delay(1000);
}

