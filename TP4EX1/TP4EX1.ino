
#define ASCEND 0
#define STAY 1
#define DESCEND 2


void setup() {
  Serial.begin(1200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, OUTPUT);
}

int tdR(){
  unsigned long timeStamp = micros();
  digitalRead(0);  
  int elapsedTime = micros() - timeStamp;
  return elapsedTime;
}

int taR(){
  unsigned long timeStamp = micros();
  analogRead(0);  
  int elapsedTime = micros() - timeStamp;
  return elapsedTime;
}

bool timeOver(int intervalo, unsigned long timeStamp){
  int elapsedTime = (micros() - timeStamp);
  if(elapsedTime >= intervalo){
    return true;
  }else{
    Serial.println(elapsedTime);
    return false;
  }
}

void EX1(){
  int intervalo = taR();
  Serial.println("The interval measured in function is " + String(intervalo));
  delay(500);
  unsigned long timeStamp = micros();
  bool hasPassed = false;
  while(!hasPassed){
      hasPassed = timeOver(intervalo, timeStamp);
  }
  Serial.println("The interval has passed!!");
  analogWrite(3, 1);
}

bool uartRead(char validChar){
  if(Serial.available()>0){
    char rChar = Serial.read();
    if(rChar == validChar){
      return true;
    }
  }else {
    return false;
  }
}

void crescentCycle(){
  unsigned long timeStamp = millis(); 
  for(int i=0; i<=80; i++){
    while(millis() - timeStamp < 50){
    }
    int maximum = 0.8 * 255; 
    int val = map(i, 0, 80, 0, maximum);
    analogWrite(1, val);
    Serial.println(val);
    timeStamp = millis();
    }
}
void constantCycle(){
  unsigned long timeStamp = millis();
  int maximum = 255*0.8;
  for(int i=0; i<100; i++){
    while(millis() - timeStamp < 50){
      }
    analogWrite(1,maximum);
    Serial.println("Constant!");
    timeStamp = millis();
  }
}
void descendingCycle(){
  unsigned long timeStamp = micros();
  for(int i=80; i>=0; i--){
    int maximum = 0.8 * 255; 
    while(micros() - timeStamp < 12500){
      int val = map(i, 0, 80, 0, maximum);
      analogWrite(1, val);
      Serial.println("Descending");
      timeStamp = micros();
    }
  }
}
void cycle(){
  static unsigned long timeStamp = millis();
  static byte stateSweep = 0;
  static long intensidade = 0;
  switch (stateSweep){
    case ASCEND:
      //Serial.println("ASCEND");
      intensidade = 204*(millis()-timeStamp)/4000;
      Serial.println(intensidade);
      analogWrite(LED_BUILTIN, intensidade);
      if(intensidade >=204){
        stateSweep = STAY;
        timeStamp = millis();
      }
      break;
     case STAY:
     //Serial.println("STAY");
      Serial.println(intensidade);
      analogWrite(LED_BUILTIN, intensidade);
      if((millis()-timeStamp) > 5000){
        stateSweep = DESCEND;
        timeStamp = millis();
      }
      break;
      case DESCEND:
      //Serial.println("DESCEND");
      intensidade = 204-204*(millis()-timeStamp)/1000;
      Serial.println(intensidade);
      analogWrite(LED_BUILTIN, intensidade);
      if(intensidade <= 0){
        stateSweep = ASCEND;
        timeStamp = millis();
      }
      break;
  }
}

void loop() {
//  char validChar = 'A';
//  if(uartRead(validChar)){
//    }
  digitalWrite(3, HIGH);
  digitalWrite(3, LOW);
  cycle();
}
