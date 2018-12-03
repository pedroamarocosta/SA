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
//  Serial.println("Imprime o valor original 255 em base hexadecimal: "); 
//  Serial.println(255, HEX);
//  Serial.println("Imprime o valor original 255 em base binaria: "); 
//  Serial.println(255, BIN);
//  Serial.println("Imprime o valor original 255 em base decimal: "); 
//  Serial.println(255, DEC);
//  byte exemplo = 255; //Guardando o valor 255 em 1 byte. Se o valor for maior que 1 byte será truncado
//  Serial.println("Imprime a variavel byte exemplo nas 3 notacoes."); 
//  Serial.println(exemplo, HEX);
//  Serial.println(exemplo, DEC);
//  Serial.println(exemplo, BIN);
//  Serial.println("Se o valor nao foi truncado nao ocupa mais que o tipo byte, e portanto apenas 1 byte.");   
}

void loop(){
//	float rawVal = tp3.potReadVolt();
//	int val = (int)rawVal+ 1;
//	switch(val){
//		case 1:
//			tone(PIEZOPIN, 2, 500);
//			delay(500);
//			noTone(PIEZOPIN);
//			break;
//		case 2:
//			tone(PIEZOPIN, 4, 500);
//			delay(500);
//			noTone(PIEZOPIN);
//			break;
//		case 3:
//			tone(PIEZOPIN, 6, 500);
//			delay(500);
//			noTone(PIEZOPIN);
//			break;
//		case 4:
//			tone(PIEZOPIN, 8, 500);
//			delay(500);
//			noTone(PIEZOPIN);
//			break;
//		case 5:
//			tone(PIEZOPIN, 10, 500);
//			delay(500);
//			noTone(PIEZOPIN);
//			break;
//    default:
//      tone(PIEZOPIN, 10, 500);
//      delay(500);
//      noTone(PIEZOPIN);
//      break;
//	}
}
