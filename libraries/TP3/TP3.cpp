/*
  TP3.cpp - Functions library for SA TP3.
*/

#include "Arduino.h"
#include "TP3.h"

TP3::TP3(int LDRPIN, int PINPIEZO, int BUTTONPIN, int LDRMAX, int R2, float a)
{
  _LDRPIN = LDRPIN;
  _PINPIEZO = PINPIEZO;
  _BUTTONPIN = BUTTONPIN;
  _LDRMAX = LDRMAX;
  _R2 = R2;
  _a = a;
  pinMode(_LDRPIN, INPUT);
  pinMode(_PINPIEZO, OUTPUT);
  pinMode(_BUTTONPIN, INPUT_PULLUP);
}

int TP3::LDRRead10bit() {
  return analogRead(_LDRPIN);
}

float TP3::LDRReadVolt() {
  int digVal = LDRRead10bit();
  float voltVal = (digVal * 5.0) / 1023;
  return voltVal;
}

float TP3::LDRReadRLDR() {
  return _R2 * (5 /LDRReadVolt() - 1) ;
}

int TP3::LDRReadLum() {
   return pow(_a/LDRReadRLDR(),10.0/3.0);
}

bool TP3::UARTRead(char validChar){
  if(Serial.available()>0){
    char rChar = Serial.read();
    if(rChar == validChar){
      return true;
    }
  }else {
    return false;
  }
}

bool TP3::buttonRead(){
  return digitalRead(_BUTTONPIN);
  }

void TP3::LDRDisplay(){
  Serial.print(LDRRead10bit());
  Serial.print(", ");
  Serial.print(LDRReadVolt());
  Serial.print(", ");
  Serial.print(LDRReadRLDR());
  Serial.print(", ");
  Serial.println(LDRReadLum());
}

