#pragma once
#include "Entidad.h"

enum SpriteEnemigo {
	eCaminarAbajo,
	eCaminarArriba,
	eCaminarIzquierda,
	eCaminarDerecha
};

class Enemigo : public Entidad 
{
	SpriteEnemigo accion;
public:
	Enemigo(Bitmap^ img) {
		x = 70 + rand() % (360 - 1);
		y = 70 + rand() % (240 - 1);

		ancho = img->Width / 3;
		alto = img->Height / 4;

		if (rand() % 2 == 0) { //Desplazamiento del enemigo en X
			dx = rand() % 10 - 5; // Entre "-5" y "4"
			if (dx == 0) // Si sale "0", se le asigan "5"
				dx = 5; 
		}
		else { //Desplazamiento del enemigo en Y
			dy = rand() % 10 - 5; // Entre "-5" y "4"
			if (dy == 0) // Si sale "0", se le asigan "5"
				dy = 5;
		}

		accion = eCaminarAbajo;
	}

	void Mover(Graphics^ g) {
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width))
			dx *= -1;
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height))
			dy *= -1;

		if (dx < 0)
			accion = eCaminarIzquierda;
		else if (dx > 0)
			accion = eCaminarDerecha;
		else if (dy < 0)
			accion = eCaminarArriba;
		else if (dy > 0)
			accion = eCaminarAbajo;

		x += dx;
		y += dy;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Blue, HitBox());

		if (accion >= eCaminarArriba && accion <= eCaminarDerecha)
			IDx = (IDx + 1) % 3;
		else
			IDx = (IDx + 1) % 3;
	}
};

class Enemigos
{
	vector<Enemigo*> enemigos;
public:
	Enemigos(Bitmap^ img, int cant) {
		for (int i = 0; i < cant; i++)
			enemigos.push_back(new Enemigo(img));
	}
	~Enemigos() {
		for each (Enemigo * E in enemigos)
			delete E;
	}

	void Mover(Graphics^ g) {
		for each (Enemigo * E in enemigos)
			E->Mover(g);
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		for each (Enemigo * E in enemigos)
			E->Mostrar(g, img);
	}

	bool Colision(Rectangle obj) { //Indica si hay o no hay colisión 
		for each (Enemigo * E in enemigos)
			if (E->HitBox().IntersectsWith(obj))
				return true;

		return false;
	}
};