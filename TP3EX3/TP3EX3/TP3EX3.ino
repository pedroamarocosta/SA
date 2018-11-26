#define LEDPIN 12
#define BUTTONPIN 5
#define LDRPIN 2 
#define VOLTAGE 5

bool buttonRead(int buttonPin){
  return digitalRead(buttonPin);
}

int LDRRead10bit(){
  return analogRead(LDRPIN);
} 

void lightLED(){
  
}
  
void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(LDRPIN, INPUT);
}

void loop() {
  bool buttonState = buttonRead(BUTTONPIN);
  while(buttonState == LOW){
    delay(100);
    Serial.println("Luminosity level: " + String(LDRRead10bit()));
    buttonState = HIGH;
  }
}


