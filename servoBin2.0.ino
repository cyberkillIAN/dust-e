#include <Servo.h>        //servo library
Servo servo;
//konstanter
const int TRIG_PIN = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 8; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int servoPin = 13;
const int LED_PIN  = 2; // Arduino pin connected to LED's pin


const int maxAvstand = 5; // centimeters

// variabler:
float duration;
float distance_cm;

void setup() {
  	Serial.begin (9600);       // initialize serial port
	  servo.attach(servoPin);

  	pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  	pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  	pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode

	  servo.write(0);         //servoen skal lukke lokket
	    delay(100);
   
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = ((0.034 * duration)/2);
   Serial.println(distance_cm);  
  

  if(distance_cm < maxAvstand){
    digitalWrite(LED_PIN, HIGH); // turn on LED

     delay(1);
     servo.write(0);  
     delay(3000);
     servo.write(150);    
     delay(1000);
  }
  else{
      digitalWrite(LED_PIN, LOW); // turn off LED
  }

  delay(500);
}