#define LDRPIN A2
#define PINPIEZO 7
#define BUTTONPIN 5
#define LDRMAX 1200
#define R2 48
#define a 7.96

#define LEDPIN 12

#include "SA_TP3.h"
#include "SA_TP3.cpp"

TP3 tp3(LDRPIN, LDRMAX, R2, a, PINPIEZO)
  
void setup() {
  Serial.begin(115200);

}

void loop() {
  bool buttonState = tp3.buttonRead(BUTTONPIN);
  while(buttonState == LOW){
    delay(100);
    Serial.println("Luminosity level: " + String(tp3.LDRRead10bit()));
    buttonState = HIGH;
  }
}
