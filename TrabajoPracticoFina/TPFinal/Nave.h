#ifndef NAVE_H
#define NAVE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Libreria/libreria.h"
#include "Definiciones.h"

using namespace std;

class Nave{
	int _corazones;
	int _vidas;
	int _x;
	int _y;
public:
	Nave(int x, int y, int vidas, int corazones);
	~Nave();
	void borrar();
	void corazones();
	void corazonesCero();
	void dibujar();
	void dibujarCorazones();
	int getCorazones();
	int getVidas();
	int getX();
	int getY();
	void morir();
	void mover();
	void setX(int x);
	void setY(int y);
	void vidas();
	void vidasCero();

};
#endif