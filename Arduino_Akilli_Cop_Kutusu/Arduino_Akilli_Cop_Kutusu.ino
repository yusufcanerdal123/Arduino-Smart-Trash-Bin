#include <Servo.h>
Servo servo1;

int led = 7;

int echo_pin = 8;
int trig_pin = 9;

void setup() {
pinMode(echo_pin,INPUT);
pinMode(trig_pin,OUTPUT);

pinMode(led,OUTPUT);
servo1.attach(3);

Serial.begin(9600);
}

void loop() {
  
long sure,mesafe;
digitalWrite(trig_pin, LOW);
delayMicroseconds(2);
digitalWrite(trig_pin, HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin, LOW);
sure = pulseIn(echo_pin, HIGH);
mesafe = (sure/2) / 29.1;


if (mesafe <= 30)
{
  servo1.write(120);
  digitalWrite(led,HIGH);
  delay(3500);
}

else
{
servo1.write(0);
digitalWrite(led,LOW);
}


}
