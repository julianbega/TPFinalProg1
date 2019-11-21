#ifndef BALA_H
#define BALA_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Libreria/libreria.h"
#include "Definiciones.h"

using namespace std;

class Bala{
	int _cantBalas;
	int _x;
	int _y;
public:
	Bala(int x, int y);
	~Bala();
	bool afuera();
	void borrar();
	void dibujar();
	int getCantBalas();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

};
#endif