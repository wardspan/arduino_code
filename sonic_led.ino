#include <Arduino.h>

float distance;
int duration;
int RED_pin = 2;
int YELLOW_pin = 3;
int GREEN_pin = 5;
int BLUE_pin = 4;
int Trig_pin = 8;
int Echo_pin = 10;

void setup() {
    pinMode(RED_pin, OUTPUT);
    pinMode(YELLOW_pin, OUTPUT);
    pinMode(GREEN_pin, OUTPUT);
    pinMode(BLUE_pin, OUTPUT);
    pinMode(Trig_pin, OUTPUT);
    pinMode(Echo_pin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(Trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig_pin, LOW);
    duration = pulseIn(Echo_pin, HIGH);
    distance = duration * 0.034 / 2;
    delay(500);

    Serial.print("Distance = ");
}
  Serial.print (distance);
  Serial.print (" CM");
  Serial.println();

  if (distance>=250)
  {
    digitalWrite (GREEN_pin, HIGH);
    delay (500);
    digitalWrite (GREEN_pin, LOW);
    delay (500);
    digitalWrite (GREEN_pin, HIGH);
  }
  else if (distance>=150)
  {
    digitalWrite (YELLOW_pin, HIGH);
    delay (100);
    digitalWrite (YELLOW_pin, LOW);
    delay (100);
    digitalWrite (YELLOW_pin, HIGH);
    delay (100);
  }
  else if (distance>=75)
  {
    digitalWrite (BLUE_pin, HIGH);
    delay (100);
    digitalWrite (BLUE_pin, LOW);
    delay (100);
    digitalWrite (BLUE_pin, HIGH);
    delay (100);
  }
  else
  {
    digitalWrite (RED_pin, HIGH);
    delay (100);
    digitalWrite (RED_pin, LOW);
    delay (100);
    digitalWrite (RED_pin, HIGH);
    delay (100);
  }
}