#include "nave.h"

Nave::Nave(int x, int y, int vidas, int corazones){
	_x=x;
	_y=y;
	_vidas=vidas;
	_corazones=corazones;
}

void Nave::dibujar(){
	gotoxy(_x,_y); 
	cout<<"  "<<(char)30;
	gotoxy(_x,_y+1);
	cout<<" "<<(char)40<<(char)206<<(char)41;//207
	gotoxy(_x,_y+2);
	cout<<(char)30<<(char)190<<" "<<(char)212<<(char)30;
}
void Nave::borrar(){
	gotoxy(_x,_y);  cout<<"     ";
	gotoxy(_x,_y+1);cout<<"     ";
	gotoxy(_x,_y+2);cout<<"     ";
	gotoxy(_x,_y+1);cout<<"     ";

}


void Nave::morir(){
	if(_corazones==0){
		borrar();
		gotoxy(_x,_y);  cout<<"  ** ";
		gotoxy(_x,_y+1);cout<<" ****";
		gotoxy(_x,_y+2);cout<<"  ** ";
		miliSleep(200);
		borrar();
		gotoxy(_x,_y);  cout<<"* * *";
		gotoxy(_x,_y+1);cout<<" *** ";
		gotoxy(_x,_y+2);cout<<"* * *";
		miliSleep(200);
		borrar();
		_vidas--;
		_corazones=3;
		dibujar();
		dibujarCorazones();
	}
}

void Nave::setCorazones(int newCor){
	_corazones = newCor;
}

void Nave::corazonesCero(){
	if (getCorazones() == 0){
		if(getVidas() >= 1){
			morir();
		}
	}

}
void Nave::dibujarCorazones(){
}
int Nave::getCorazones(){
	return _corazones;
}
int Nave::getVidas(){
	return _vidas;
}
int Nave::getX(){
	return _x;
}
int Nave::getY(){
	return _y;
}

void Nave::setX(int x){
	_x = x;
}
void Nave::setY(int y){
	_y = y;
}
void Nave::setVidas(int newVida){
	_vidas = newVida;
}
void Nave::vidasCero(){
	if(getVidas() <= 0){
		
	}
}