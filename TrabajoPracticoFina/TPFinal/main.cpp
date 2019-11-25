#include "Juego.h"

void main(){
	Juego* juego = NULL;
	juego = new Juego;
	if(juego != NULL){
	juego->play();
	}
	if(juego != NULL){
		delete juego;
	}
	cin.get();
}