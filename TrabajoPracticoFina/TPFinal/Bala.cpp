#include "Bala.h"

Bala::Bala(int x, int y){
	_x = x;
	_y = y;
}
Bala::~Bala(){
}
bool Bala::afuera(){
	if(getY() > MAX_COL ){
		return true;
	}
	else{		
	return false;
	}
}
void Bala::borrar(){
	gotoxy(_x,_y);  cout<<"     ";
}
void Bala::dibujar(){
	gotoxy(_x,_y); 
	cout<<"B"<<(char)30;
}
int Bala::getCantBalas(){
	return _cantBalas;
}
int Bala::getX(){
	return _x;
}
int Bala::getY(){
	return _y;
}

void Bala::setX(int x){
	_x = x;
}
void Bala::setY(int y){
	_y = y;
}