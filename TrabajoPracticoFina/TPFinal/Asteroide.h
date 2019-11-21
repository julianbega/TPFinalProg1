#ifndef ASTEROIDES_H
#define ASTEROIDES_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Libreria/libreria.h"
#include "Definiciones.h"
#include "Nave.h"

using namespace std;

class Asteroide{
	int _cantAsteroides;
	int _x;
	int _y;
	int _aux;
public:
	Asteroide(int x, int y);
	~Asteroide();
	void mover();
	void borrar();
	void dibujar();
	int getCantAsteroides();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void colision(Nave* nave);
};
#endif