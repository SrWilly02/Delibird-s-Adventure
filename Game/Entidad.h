#pragma once
#include "Dependencias.h"
class Entidad 
{
protected:
	int x, y; //Posicion del objeto en pantalla
	int dx, dy; //Dirección del movimiento del objeto
	int ancho, alto; //Dimensiones del objeto en pantalla
	int IDx;

public:
	Entidad() { 
		x = y = 0; 
		dx = dy = 0; 
		ancho = alto = 0; 
		IDx = 0; 
	}
	
	Rectangle Area() { //Posicion actual
		return Rectangle(x, y, ancho, alto);
	}

	Rectangle NextArea() { //Siguiente posicion
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	Rectangle HitBox() {
		return Rectangle(x + ancho / 4, y + alto / 3 - 5, ancho / 2, alto * 2 / 3);
	}

	Rectangle NextHitBox() {
		return Rectangle(x + ancho / 4 + dx, y + alto / 3 - 5 + dy, ancho / 2, alto * 2 / 3);
	}

	virtual void Mover(Graphics ^ g) {
		x += dx; y += dy;
	}

	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		g->FillRectangle(Brushes::Black, Area());
	}

	void SetDX(int value) {
		dx = value;
	}
	
	void SetDY(int value) {
		dy = value;
	}
};