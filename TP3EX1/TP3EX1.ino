#include <TP3.h>

#define LDRPIN A2
#define PIEZOPIN 7
#define BUTTONPIN 4
#define LEDPIN 5
#define POTPIN A1
#define LDRMAX 1200
#define POTMAX 1.1
#define R2 48
#define a 7.96

TP3 tp3(LDRPIN, PIEZOPIN, BUTTONPIN, LEDPIN, POTPIN,  LDRMAX, POTMAX, R2, a);
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  
  bool buttonState = tp3.buttonRead();
  if(buttonState == LOW){
    Serial.println("Button is pressed");
  }
  
  delay(100);
  
  char validChar = 't';
  bool isCharReceived = tp3.uartRead(validChar);
  if(isCharReceived){
    Serial.println("Valid char received");}
}
