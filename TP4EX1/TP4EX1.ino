

void setup() {
  Serial.begin(115200);

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


void loop() {
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
