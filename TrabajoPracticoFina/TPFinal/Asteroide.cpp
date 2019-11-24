#include "Asteroide.h"

int Asteroide::_cantAsteroides=0;

Asteroide::Asteroide(int x, int y){
	_x = x;
	_y = y;
	_aux = 0;
	_cantAsteroides++;
}
Asteroide::~Asteroide(){
	_cantAsteroides--;
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
	if (getY() == nave->getY() &&
		getX() == nave->getX()+2 ){
			nave->setCorazones(nave->getCorazones()-1);
			setX(rand() % MAX_COL-1 + MIN_COL+1);
			setY(3);
		}
	else if(getY() == nave->getY()+1 &&
			getX() <= nave->getX()+3&&
			getX() >= nave->getX()+1){
				nave->setCorazones(nave->getCorazones()-1);
				setX(rand() % MAX_COL-1 + MIN_COL+1);
				setY(3);
	}else if(getY() == nave->getY()+2 &&
			getX() <= nave->getX()+4 &&
			getX() >= nave->getX()){
				nave->setCorazones(nave->getCorazones()-1);
				setX(rand() % MAX_COL-1 + MIN_COL+1);
				setY(3);
	}
		
}
void Asteroide::setX(int x){
	_x = x;
}
void Asteroide::setY(int y){
	_y = y;
}