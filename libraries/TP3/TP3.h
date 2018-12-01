/*
  TP3.h - Class library for SA TP3.
*/

#ifndef TP3_h
#define TP3_h

#include "Arduino.h"


class TP3
{
  public:
    TP3(int LDRPIN, int PINPIEZO,  int BUTTONPIN, int LDRMAX, int R2, float a);
    int LDRRead10bit();
    float LDRReadVolt();
    float LDRReadRLDR();
    int LDRReadLum();
    bool UARTRead(char validChar);
	bool buttonRead();
	void LDRDisplay();
  private:
    int _LDRPIN;
	int _PINPIEZO;
	int _BUTTONPIN;
    int _LDRMAX;
    int _R2;
    float _a;

};

#endif
