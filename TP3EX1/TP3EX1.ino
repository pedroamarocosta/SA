#define BUTTONPIN 4     // the number of the pushbutton pin
#define LEDPIN 13      // the number of the LED pin
#define POTPIN A1
#define RPOTMAX 0.93    //Máximo do potenciometro é 0.93KOHM
#define VOLTAGE 4.80    //Máximo do potenciometro é 0.93KOHM

bool buttonRead(){
  return !digitalRead(BUTTONPIN);
}

bool uartRead(char validChar){
  char receivedChar;
  if(Serial.available() > 0){
      receivedChar = Serial.read();
      if(receivedChar == validChar){
        //Serial.println(receivedChar);
        return true;
        }
     }
   return false;
}

int potRead10bit(){
  return analogRead(POTPIN);
  }

float potReadVolt(){
  return (VOLTAGE * potRead10bit())/1023.0;
  }

float potReadR23(){
  return (RPOTMAX * potReadVolt())/VOLTAGE;
  }

int potReadPos(){
  return (100 * potReadR23());
  }

void EX1(){
  bool buttonState = buttonRead();
  if(buttonState == HIGH){ //pullup
    Serial.println("Button is pressed");
  }else{
    Serial.println("Button is not pressed");
  }
}

void EX2(){
  if(uartRead('A')){
    //Serial.println("UART function successfull.");
    }
  }
  
void EX3(){
  int Rpot = potRead10bit();
  Serial.print(Rpot);
  Serial.print(", ");
  }
  
void EX4(){
  float Rpot = potReadVolt();
  Serial.print(Rpot);
  Serial.print(", ");
  }

void EX5(){
  float Vpot = potReadR23();
  Serial.print(Vpot);
  Serial.print(", ");
  }

void EX6(){
  float Rpot = potReadPos();
  Serial.print(Rpot);
  }

void EX7(){
  EX3();
  EX4();
  EX5();
  EX6();
  Serial.println();
  }
  
void EX8(){
  bool buttonState = buttonRead();
  if(buttonState == HIGH){ 
    EX7();
    digitalWrite(LEDPIN, HIGH);
    delay(200);
    digitalWrite(LEDPIN, LOW);
    delay(200);
    digitalWrite(LEDPIN, HIGH);
    delay(200);
    digitalWrite(LEDPIN, LOW);
    delay(200);
    digitalWrite(LEDPIN, HIGH);
    delay(200);
    digitalWrite(LEDPIN, LOW);
    }
  }

void setup() {
  Serial.begin(115200);
  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(LEDPIN, OUTPUT);
  pinMode(POTPIN, INPUT);
}

void loop() {
  //EX1(); //Função bool buttonRead()
  //EX2(); //Função bool uartRead(char validChar) 
  //EX3(); //Função int potRead10bit()
  //EX4();
  //EX5();
  //EX6();
  //EX7();
  EX8();
  
}
