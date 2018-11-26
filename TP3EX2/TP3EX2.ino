#define LDRPIN A2
#define LDRMAX 1200
#define R2 48
#define a 7.96
#define PINPIEZO 7
int ldrRead10bit() {
  return analogRead(LDRPIN);
}

float ldrReadVolt() {
  int digVal = ldrRead10bit();
  float voltVal = (digVal * 5.0) / 1023;
  return voltVal;
}

float ldrReadRldr() {
  return R2 * (5 /ldrReadVolt()-1) ;
}
bool uartRead(char validChar){
  if(Serial.available()>0){
    char rChar = Serial.read();
    if(rChar == validChar){
      return true;
    }
  }else return false;
}

int ldrReadLum() {
   return pow(a/ldrReadRldr(),10.0/3.0);
}

void ldrDisp(){

  Serial.print(ldrRead10bit());
  Serial.print(", ");
  Serial.print(ldrReadVolt());
  Serial.print(", ");
  Serial.print( ldrReadRldr());
  Serial.print(", ");
  Serial.println(ldrReadLum());
  
}
void setup() {
  Serial.begin(115200);
  pinMode(LDRPIN, INPUT);
  pinMode(PINPIEZO, OUTPUT);

}

void loop() {
  if(uartRead('t')){
    ldrDisp();
    tone(PINPIEZO,880,500);
    delay(500);
    tone(PINPIEZO,440,500);
    delay(500);
    noTone(PINPIEZO);
    
  }
  
  

}
