
/*
   SONAR_QUINTET_SEQUENCE
   TEAM 1B: FINAL CODE
   Code used to test a pair of sensors for the composite
   smart device, in sequence
*/

#include "pitches.h"

// Pin placements
int trigPin1 = 2;
int trigPin2 = 3;
int trigPin3 = 4;
int trigPin4 = 5;
int trigPin5 = 6;
int trigPin6 = 7;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

int echoPin1 = A0;
int echoPin2 = A1;
int echoPin3 = A2;
int echoPin4 = A3;
int echoPin5 = A4;
int echoPin6 = A5;

int notePin = 8;
int noteDuration = 1000 / 4; //quarter second
int note = NOTE_B3;

float distanceThreshold = 70; //in cm
unsigned long pauseBetweenNotes = 250;

void setup() {
  // put your setup code here, to run once:


  // Setting up the various Trigger pins
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(trigPin6, OUTPUT);
  
  // Setting up the various Echo pins
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
  pinMode(echoPin6, INPUT);


  // Initializing all the Echo pins to low
  digitalWrite(echoPin1, LOW);
  digitalWrite(echoPin2, LOW);
  digitalWrite(echoPin3, LOW);
  digitalWrite(echoPin4, LOW);
  digitalWrite(echoPin5, LOW);
  digitalWrite(echoPin6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Send signal through First Distance Sensor
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin1, LOW);

  // Read from First Distance Sensor
  while (digitalRead(echoPin1) == LOW) {
    // do nothing
  }
  unsigned long startTime1 = micros();
  while (digitalRead(echoPin1) == HIGH) {
    // do nothing
  }
  unsigned long duration1 = micros() - startTime1;
  // Calculate second sensor distance in cm
  float distance1 = duration1 / 58.;

  //Send signal through Second Distance Sensor
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin2, LOW);
  // Read from Second Distance Sensor
  while (digitalRead(echoPin2) == LOW) {
    // do nothing
  }
  unsigned long startTime2 = micros();
  while (digitalRead(echoPin2) == HIGH) {
    // do nothing
  }
  unsigned long duration2 = micros() - startTime2;
  // Calculate second sensor distance in cm
  float distance2 = duration2 / 58.;

  //Send signal through Third Distance Sensor
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin3, LOW);

  // Read from Third Distance Sensor
  while (digitalRead(echoPin3) == LOW) {
    // do nothing
  }
  unsigned long startTime3 = micros();
  while (digitalRead(echoPin3) == HIGH) {
    // do nothing
  }
  unsigned long duration3 = micros() - startTime3;
  // Calculate third sensor distance in cm
  float distance3 = duration3 / 58.;

  //Send signal through Fourth Distance Sensor
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin4, LOW);

  // Read from Fourth Distance Sensor
  while (digitalRead(echoPin4) == LOW) {
    // do nothing
  }
  unsigned long startTime4 = micros();
  while (digitalRead(echoPin4) == HIGH) {
    // do nothing
  }
  unsigned long duration4 = micros() - startTime4;
  // Calculate fourth sensor distance in cm
  float distance4 = duration4 / 58.;

  //Send signal through Fifth Distance Sensor
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin5, LOW);

  // Read from Fifth Distance Sensor
  while (digitalRead(echoPin5) == LOW) {
    // do nothing
  }
  unsigned long startTime5 = micros();
  while (digitalRead(echoPin5) == HIGH) {
    // do nothing
  }
  unsigned long duration5 = micros() - startTime5;
  // Calculate fifth sensor distance in cm
  float distance5 = duration5 / 58.;


  //Send signal through Sixth Distance Sensor
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin6, LOW);


  // Read from Sixth Distance Sensor
  while (digitalRead(echoPin6) == LOW) {
    // do nothing
  }
  unsigned long startTime6 = micros();
  while (digitalRead(echoPin6) == HIGH) {
    // do nothing
  }
  unsigned long duration6 = micros() - startTime6;
  // Calculate sixth sensor distance in cm
  float distance6 = duration6 / 58.;


  // Compare distance to a pre-set threshold
  if ((distance1 > 110) // 110 cm
      && (distance2 > distanceThreshold)
      && (distance3 > distanceThreshold)
      && (distance4 > distanceThreshold)
      && (distance5 > 90) //90 cm
      && (distance6 > distanceThreshold)) {
    noTone(notePin); // no sound
  }
  else {
    tone(notePin, note, noteDuration); // play note
  }


  // Time delays
  delay(pauseBetweenNotes);
}




