#define PINLDR A2
#define VOLTAGE 5
#define RMAX 1200
#define R2 48

int ldrRead10bit(){
  return analogRead(PINLDR);
  } 

float ldrReadVolt(){
  return (VOLTAGE * ldrRead10bit())/1023.0;
  }
  
float ldrReadRldr() {
  return 48 * ((5/ldrReadVolt())-1);
  }


void setup() {
  Serial.begin(115200);
  pinMode(PINLDR, INPUT);
}


void loop() {
 Serial.print("LDR 10 bit: ");
 Serial.println(ldrRead10bit());
 Serial.print("Voltagem : ");
 Serial.println(ldrReadVolt());
 Serial.print("LDR Resistencia : ");
 Serial.println(ldrReadRldr());
 delay(500);

}
