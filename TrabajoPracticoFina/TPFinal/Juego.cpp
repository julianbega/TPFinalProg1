#include "Juego.h"

Juego::Juego(){
	_nave=new Nave(38,20,3,3);
	for (int i = 0; i < 3; i++){
		_vecAst[i] = NULL;
	}
	_vecAst[0]=new Asteroide(10, 4);
	_vecAst[1]=new Asteroide(4, 8);
	_vecAst[2]=new Asteroide(15, 10);
}

Juego::~Juego(){

}

void Juego::init(){
	_gameOver=false;
	_tecla=0;
	_puntos=0;
	_resultado=false;
	srand(time(NULL));
}

bool Juego::gameOver(){
	return _gameOver;
}

void Juego::play(){
	init();
	marco(MIN_COL, MIN_FIL, MAX_COL, MAX_FIL);
	hideCursor();
	while (!_gameOver){
		input();
		update();
		
	}
	result();
}


void Juego::input(){
	if(_tecla=getKey(false)){
		switch(_tecla){
		case KEY_UP:
			if (_nave->getY() > MIN_FIL + 1){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->borrar();
			_nave->setY(_nave->getY() - 1);
			}
			break;

		case KEY_LEFT:
			if (_nave->getX() > MIN_COL+1){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->borrar();
			_nave->setX(_nave->getX() - 1);
			}
			break;

		case KEY_RIGHT:
			if (_nave->getX() < MAX_COL -5){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->borrar();
			_nave->setX(_nave->getX() + 1);
			}
			break;

		case KEY_DOWN:
			if (_nave->getY() < MAX_FIL-3){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->borrar();
			_nave->setY(_nave->getY() + 1);
			}
			break; 

		case KEY_ESC:

			gameOver();
			break;

		default:
			break;
		}
	}
}


void Juego::update(){
	for (int i = 0; i < 3; i++){
		_vecAst[i]->mover();
		if(_vecAst[i]->getY()>=MAX_FIL){
			_vecAst[i]->setX(rand() % MAX_COL + MIN_COL-1);
			_vecAst[i]->setY(3);
		}
	}
	draw();
}

void Juego::draw(){
	if(_nave != NULL){
		_nave->dibujar();
	}	
	for (int i = 0; i < 3; i++){
		_vecAst[i]->dibujar();
	}
	display();
}

void Juego::result(){

}

void Juego::display(){
	gotoxy(2,1);
	cout<<"Vidas "<< _nave->getVidas() <<	 "  Salud ";
	if(_nave->getCorazones() == 1) cout << (char)CORAZON;
	if(_nave->getCorazones() == 2) cout << (char)CORAZON<<(char)CORAZON;
	if(_nave->getCorazones() == 3) cout << (char)CORAZON<<(char)CORAZON<<(char)CORAZON;
}