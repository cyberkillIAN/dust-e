#include <Servo.h>        //servo bibliotek
Servo servo;
//konstanter
const int TRIG_PIN = 9; // Arduino pin koblet til Ultrasonic Sensor TRIG pin
const int ECHO_PIN = 8; // Arduino pin koblet til Ultrasonic Sensor ECHO pin
const int servoPin = 13; // Arduino pin koblet til servoen
const int LED_PIN  = 2; // Arduino pin koblet til LED pin


const int maxAvstand = 5; // Avstand til sensor i cm

// Variabler for varighet av signal og distansen til sensoren
float duration;
float distance_cm;

void setup() {
  	Serial.begin (9600);       // Initialisere serial port
	  servo.attach(servoPin);

  	pinMode(TRIG_PIN, OUTPUT); // sett arduino pin til output mode
  	pinMode(ECHO_PIN, INPUT);  // sett arduino pin til input mode
  	pinMode(LED_PIN, OUTPUT);  // sett arduino pin til output mode

	  servo.write(0);         //servoen skal lukke lokket
	    delay(100);
   
}

void loop() {
  // generere 10-mikrosekund puls til TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // måle varighet av pulsen fra ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH);
  // regner ut distansen
  distance_cm = ((0.034 * duration)/2);
   Serial.println(distance_cm);  
  
  // hvis distansen er mindre enn den maksimale avstanden vil lyspæren lyse opp
  if(distance_cm < maxAvstand){
    digitalWrite(LED_PIN, HIGH); // LED lyser opp

     delay(1);
     servo.write(0);  
     delay(3000);
     servo.write(150);    
     delay(1000);
  }
  else{
      digitalWrite(LED_PIN, LOW); // LED slås av
  }

  delay(500);
}