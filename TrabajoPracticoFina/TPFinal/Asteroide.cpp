#include "Asteroide.h"

Asteroide::Asteroide(int x, int y){
	_x = x;
	_y = y;
	_aux = 0;
}
Asteroide::~Asteroide(){
}
void Asteroide::mover(){
	_aux++;
	if(_aux > 200){
		gotoxy(_x,_y);
		borrar();
		if(getX()>=MIN_FIL){
			_y++;
		}

		_aux = 0;
	}
}
void Asteroide::borrar(){
	gotoxy(_x,_y);  
	cout<<" ";
}
void Asteroide::dibujar(){
	gotoxy(_x,_y); 
	cout<<(char)30;
}
int Asteroide::getCantAsteroides(){
	return _cantAsteroides;
}
int Asteroide::getX(){
	return _x;
}
int Asteroide::getY(){
	return _y;
}
void Asteroide::colision(Nave* nave){
	nave->getX();
	nave->getY();
}
void Asteroide::setX(int x){
	_x = x;
}
void Asteroide::setY(int y){
	_y = y;
}