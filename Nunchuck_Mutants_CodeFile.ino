/*------ Arduino Line Follower Code----- */
/*-------Including Libraries------*/
// Include NewPing Library
#include "NewPing.h"
/*-------Intializing IR Sensor------*/
int LS = 12; // left IR sensor
int RS = 11; // right IR sensor
/*-------Intializing Outputs------*/
int enA = 9; // Speed Control with PWM
int LM1 = 8; // left motor
int LM2 = 7; // left motor
int enB = 3; // Speed Control with PWM
int RM1 = 5; // right motor
int RM2 = 4; // right motor
/*-------Intializing Variables------*/
float distance;
/*-------Intializing HC-SR04 Sensor------*/
// Maximum Distance is 400 cm
#define TRIGGER_PIN  10 // Trigger Pin for the HC-SR04 Sensor
#define ECHO_PIN     6 // Echo Pin for the HC-SR04 Sensor
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() // Assigning...[Sensors and EchoPin as INPUT]&&[Motors and TrigPin as OUTPUT]
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
}

void loop()
{

  distance = sonar.ping_cm();
  
  while (distance <= 5 && distance >= 2) // Stop! (distance <= 10)
  {
  distance = sonar.ping_cm();
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  delay(500);
    if(distance >= 5)
    {
      break;
    }
  }  
  if(!(digitalRead(LS)) && !(digitalRead(RS))) // Move Forward (digitalRead(LS) && digitalRead(RS))
  {
  analogWrite(enA, 85);
  analogWrite(enB, 90);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right
  {
  analogWrite(enA, 85);
  analogWrite(enB, 90);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS))) // turn left
  {
  analogWrite(enA, 85);
  analogWrite(enB, 90);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  }
  
  if(digitalRead(LS) && digitalRead(RS)) // Move Forward At Intersections (digitalRead(LS)) && !(digitalRead(RS))
  {
  analogWrite(enA, 100);
  analogWrite(enB, 100);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  }
}
