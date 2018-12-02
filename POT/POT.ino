#define BUTTONPIN 4
#define LEDPIN 13
#define POTPIN A1
#define POTMAX 1.1
bool buttonRead(){

  bool state = digitalRead(BUTTONPIN);
  return  !state;
}

bool uartRead(char validChar){
  return true;
}

int potRead10bit(){
  return analogRead(POTPIN);
}

float potReadVolt(){
  int digVal = potRead10bit();
  float voltVal = (digVal*5.0)/1023;
  return voltVal;
}

float potReadRpotR23(){
  
  return (POTMAX * potReadVolt())/5;
}
int potReadPos(){
  return 100*potReadRpotR23();
}

void Ex1(){
    if(buttonRead()){
    Serial.println("Button is pressed");
  }
  else{
    Serial.println("Button is not pressed");
    }

    delay(100);
}
void Ex2(){
  Serial.println("valor digital: " + String(potRead10bit()) + "Voltagem: "+String(potReadVolt())+"V  R23: " + String(potReadRpotR23())+"kOhm  Posição: " + String(potReadPos()) );
  delay(100);
}
void setup() {
  Serial.begin(115200);

  pinMode(BUTTONPIN,INPUT_PULLUP);
  pinMode(LEDPIN,OUTPUT);
  pinMode(POTPIN,INPUT);

}

void loop() {

  //Ex1();
  Ex2();
  
}
