#include "Bala.h"

Bala::Bala(int x, int y){
	_x = x;
	_y = y;
	_aux = 0;
}
Bala::~Bala(){
}
bool Bala::afuera(){
	if(getY() <= AFUERA-1 ){
		return true;
	}
	else{		
	return false;
	}
}
void Bala::borrar(){
	gotoxy(_x,_y);  cout<<" ";
}
void Bala::mover(){
	_aux++;
	if(_aux > 10){
		gotoxy(_x,_y);
		borrar();
		if(getX()>=MIN_FIL){
			_y--;
		}

		_aux = 0;
	}
}
void Bala::dibujar(){
	if(getY() > AFUERA-1 ){
		gotoxy(_x,_y); 
		cout<<"I";
	}
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

void Bala::colision(Asteroide* asteroide){
	if (getX() == asteroide->getX() && getY() == asteroide->getY()){
		setY(MIN_Y-3);
		borrar();
		asteroide->borrar();
		asteroide->setY(MIN_Y);
		asteroide->setX(rand() % MAX_X + MIN_X);
	}
}

