
#include "NewPing.h"
 
#define TRIGGER_PIN_1  10
#define ECHO_PIN_1     10
#define TRIGGER_PIN_2  5
#define ECHO_PIN_2     5
#define MAX_DISTANCE 400
#define TRIGGER_PIN_3  8
#define ECHO_PIN_3     8
 
NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
 
// Define Variables
float duration1; // Stores First HC-SR04 pulse duration value
float duration2; // Stores Second HC-SR04 pulse duration value
float duration3; // Stores third HC-SR04 pulse duration value
float distance1; // Stores calculated distance in cm for First Sensor
float distance2; // Stores calculated distance in cm for Second Sensor
float distance3; // Stores calculated distance in cm for Third Sensor
const int motorPin = 3; // Stores PIN connected to vibrator motor
const int iterations = 5;
const int danger = 10; // Distance from which vibration engine will start working
  
void setup() {
  Serial.begin (9600);
  pinMode(motorPin, OUTPUT);
}
 
void loop()
{
   
  
  // Measure duration for first sensor
    
  duration1 = sonar1.ping_median(iterations);
  
  // Add a delay between sensor readings
  
  delay(1000);
  
  // Measure duration the second sensor
  
  duration2 = sonar2.ping_median(iterations);

  delay(1000);
  
  // Measure duration the third sensor
  
  duration3 = sonar3.ping_median(iterations);
  
  // Calculate the distances for all sensors
  
  distance1 = (duration1 / 2) * 0.0343;
  distance2 = (duration2 / 2) * 0.0343;
  distance3 = (duration3 / 2) * 0.0343;
  
  // Send results to Serial Monitor
  
    Serial.print("Distance 1: ");
 
    if (distance1 >= 400 || distance1 <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.print(distance1);
    Serial.print(" cm ");
    if (distance1 <= danger){
      digitalWrite(motorPin, HIGH); //vibrate
      delay(1000);
    }
    else{
      digitalWrite(motorPin, LOW);  //stop vibrating
    }
    }
    
    Serial.print("Distance 2: ");
 
    if (distance2 >= 400 || distance2 <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.print(distance2);
    Serial.print(" cm");
    if (distance2 <= danger){
          digitalWrite(motorPin, HIGH); //vibrate
          delay(1000);
    }
    else{
      digitalWrite(motorPin, LOW);  //stop vibrating
    }
    }
    }
  
    Serial.print("Distance 3: ");
  
    if (distance3 >= 400 || distance3 <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.print(distance2);
    Serial.print(" cm");
    if (distance3 <= danger){
      digitalWrite(motorPin, HIGH); //vibrate
      delay(1000);
    }
    else{
      digitalWrite(motorPin, LOW);  //stop vibrating
    }
    }
  
  Serial.println(" ");
}
