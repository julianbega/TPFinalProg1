#ifndef BALA_H
#define BALA_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Libreria/libreria.h"
#include "Definiciones.h"
#include "Asteroide.h"

using namespace std;

class Bala{
	int _cantBalas;
	int _x;
	int _y;
	int _aux;
public:
	Bala(int x, int y);
	~Bala();
	bool afuera();
	void borrar();
	void dibujar();
	void mover();
	int getCantBalas();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void colision(Asteroide* asteroide);
};
#endif