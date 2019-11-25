#include "Juego.h"

Juego::Juego(){
	init();	
}

Juego::~Juego(){
	for (int i = 0; i < 3; i++){
		if (_vecAst[i] != NULL){
			delete _vecAst[i];
		}
	}
	if (_nave != NULL){
			delete _nave;
	}
	for (int i = 0; i < TOPEB; i++){
		if (_vecB[i] != NULL){
			delete _vecB[i];
		}
	}
}

void Juego::init(){
	_gameOver=false;
	_tecla=0;
	_puntos=0;
	_resultado=false;
	for (int i = 0; i < 3; i++){
		_vecAst[i] = NULL;
	}
	_nave=new Nave(38,20,3,3);
	_vecAst[0]=new Asteroide(10, 4);
	_vecAst[1]=new Asteroide(4, 8);
	_vecAst[2]=new Asteroide(15, 10);
	for (int i = 0; i < TOPEB; i++){
		_vecB[i] = NULL;
	}
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
		draw();
	}
	result();
}


void Juego::input(){
	if(_tecla=getKey(false)){
		_nave->borrar();
		switch(_tecla){
		case KEY_UP:
			if (_nave->getY() > MIN_FIL + 1){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->setY(_nave->getY() - 1);
			}
			break;

		case KEY_LEFT:
			if (_nave->getX() > MIN_COL+1){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->setX(_nave->getX() - 1);
			}
			break;

		case KEY_RIGHT:
			if (_nave->getX() < MAX_COL -5){
			gotoxy(_nave->getX(), _nave->getY());
			_nave->setX(_nave->getX() + 1);
			}
			break;

		case KEY_DOWN:
			if (_nave->getY() < MAX_FIL-3){
				gotoxy(_nave->getX(), _nave->getY());
				_nave->setY(_nave->getY() + 1);
			}
			break; 

		case KEY_ESC:

			gameOver();
			break;
		case FIRE:

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
			_vecAst[i]->setX(rand() % MAX_X + MIN_X);
			_vecAst[i]->setY(3);
		}
	}
	for (int i = 0; i < 3; i++){
		_vecAst[i]->colision(_nave);
	}
	_nave->vidasCero();
	_nave->corazonesCero();
	if (_nave->getVidas() <= 1 && _nave->getCorazones() <= 0){
	 _nave->setVidas(0);
	 _gameOver = true;
	
	}
	
	
	if(_gameOver == true){
	 _nave->borrar();
	 for (int i = 0; i < 3; i++){
		 _vecAst[i]->borrar();
	}
	}
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
	gotoxy(MAX_X/2,MAX_Y/2);
	cout<<"GAME OVER";
}

void Juego::display(){

	gotoxy(2,1);
	cout<<"Vidas "<< _nave->getVidas() <<	 "  Salud " << _nave->getCorazones() ;
	if(_nave->getCorazones() == 1) cout << (char)CORAZON;
	if(_nave->getCorazones() == 2) cout << (char)CORAZON<<(char)CORAZON;
	if(_nave->getCorazones() == 3) cout << (char)CORAZON<<(char)CORAZON<<(char)CORAZON;
	gotoxy(28,1); cout << "                        Cantidad de asteroides: " << Asteroide::getCantAsteroides();
}