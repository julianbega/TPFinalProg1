#include "Juego.h"

void main(){

	Juego* juego = new Juego;
	juego->play();
	if(juego != NULL){
		delete juego;
	}
}