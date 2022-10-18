#include "Header.h"
#include "MyFunction.h"



char sKey;
unsigned char nShifrText[] = "Привет";
unsigned char Maska, buff;
void encode() {
	Maska = 0x80;
	for (int i = 0; i < sizeof(nShifrText); i++){
		buff = nShifrText[i] & Maska;  // какой бит старший;
		nShifrText[i] = nShifrText[i] << 1;
		nShifrText[i] = nShifrText[i] | (buff >> 7);
		cout << nShifrText[i];
	}
	cout << endl;
}
void decode() {
	Maska = 0x1;
	for (int i = 0; i < sizeof(nShifrText); i++) {
		buff = nShifrText[i] & Maska; //находим младший бит 
		nShifrText[i] = nShifrText[i] >> 1;
		nShifrText[i] = nShifrText[i] | (buff << 7);
		cout << nShifrText[i];
	}
	cout << endl;
}
void Shifr() {
	for (int i = 0; i < sizeof(nShifrText); i++)
		cout << nShifrText[i];
	cout << endl;
}