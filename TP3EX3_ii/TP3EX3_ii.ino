
/* Use File->Load Prog to
   load a different Program
*/

#define PINPIEZO 7
#define PINPOT A1

float potReadVolt(){
	int digVal = analogRead(PINPOT);
	float voltVal = (digVal*5.0)/1023;
	return voltVal;
	
}
void setup(){
	
	Serial.begin(9600);
	pinMode(PINPIEZO,OUTPUT);
	pinMode(PINPOT,INPUT);
}

void loop(){
	float rawVal = potReadVolt();
	int val = (int)rawVal;
	switch(val){
		case 1:
			tone(PINPIEZO,2,500);
			delay(500);
			//noTone(PINPIEZO);
			
			break;
		case 2:
			tone(PINPIEZO,4,500);
			delay(500);
			//noTone(PINPIEZO);
			break;
		case 3:
			tone(PINPIEZO,6,500);
			delay(500);
			//noTone(PINPIEZO);
			break;
		case 4:
			tone(PINPIEZO,8,500);
			delay(500);
			//noTone(PINPIEZO);
			break;
		case 5:
			tone(PINPIEZO,10,500);
			delay(500);
			//noTone(PINPIEZO);
			break;
			
			
	}
	
}
