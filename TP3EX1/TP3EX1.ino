#define buttonPin 4     // the number of the pushbutton pin
#define ledPin 13      // the number of the LED pin

bool buttonRead(int pinNumber){
  return digitalRead(pinNumber);
}

void ex1(){
  buttonRead(buttonPin);
  if(buttonState == LOW){ //pullup
    Serial.println("Button is pressed");
  }else{
    Serial.println("Button is not pressed");
  }
  delay(100);
  }
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ex1();
  
}
