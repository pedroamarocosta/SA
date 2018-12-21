#include <TP3.h>

#define LDRPIN A2
#define PIEZOPIN 7
#define BUTTONPIN 4
#define LEDPIN 5
#define POTPIN A1
#define LDRMAX 1200
#define R2 48
#define a 7.96

TP3 tp3(LDRPIN, PIEZOPIN, BUTTONPIN, LEDPIN, POTPIN, LDRMAX, R2, a);

void setup(){
	Serial.begin(115200);  
}

void loop(){
	float rawVal = tp3.potReadVolt();
	int val = (int)rawVal+ 1;
	switch(val){
		case 1:
			tone(PIEZOPIN, 2, 500);
			delay(500);
			noTone(PIEZOPIN);
			break;
		case 2:
			tone(PIEZOPIN, 4, 500);
			delay(500);
			noTone(PIEZOPIN);
			break;
		case 3:
			tone(PIEZOPIN, 6, 500);
			delay(500);
			noTone(PIEZOPIN);
			break;
		case 4:
			tone(PIEZOPIN, 8, 500);
			delay(500);
			noTone(PIEZOPIN);
			break;
		case 5:
			tone(PIEZOPIN, 10, 500);
			delay(500);
			noTone(PIEZOPIN);
			break;
    default:
      tone(PIEZOPIN, 10, 500);
      delay(500);
      noTone(PIEZOPIN);
      break;
	}
}
