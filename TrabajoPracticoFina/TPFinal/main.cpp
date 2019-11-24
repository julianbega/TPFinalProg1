#include "Juego.h"

void main(){
	Juego* juego = NULL;
	juego = new Juego;
	juego->play();
	if(juego != NULL){
		delete juego;
	}
	cin.get();
}