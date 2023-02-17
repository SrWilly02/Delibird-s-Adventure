#pragma once
#include "Entidad.h"

enum SpriteJugador {
	CaminarAbajo,
	CaminarArriba,
	CaminarIzquierda,
	CaminarDerecha
};

class Jugador : public Entidad
{
private:
	int vidas;
	SpriteJugador accion;
public:
	Jugador(Bitmap^ img, int v) {
		x = 290; y = 315; //Posicion del jugador
		dx = dy = 0;

		// Recorte del sprite
		ancho = img->Width / 3; 
		alto = img->Height / 4;

		accion = CaminarAbajo;

		vidas = v;
	}

	void SetAccion(SpriteJugador value) {
		accion = value;
	}

	void SetVidas(int value) {
		vidas += value;
	}

	int GetVidas() {
		return vidas;
	}

	void Mover(Graphics^ g) { //Controla la velocidad del jugador y evita que salga del formulario
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width) 
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawString("" + vidas, gcnew Font("Arial", 20), Brushes::Blue, 70, 20); //Mostrar el tiempo

		//Mostrar el sprite recortado, con sus animaciones
		Rectangle corte = Rectangle(IDx* ancho, accion* alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Blue, HitBox());

		if (dx != 0 || dy != 0) {
			IDx = (IDx + 1) % 3;
		}
	}
};