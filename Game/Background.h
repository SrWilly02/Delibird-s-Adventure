#pragma once
#include "Entidad.h"
class Background : Entidad
{
public:
	Background(Bitmap^ img) {
		x = y = 0;
		ancho = img->Width;
		alto = img->Height;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawImage(img, Area());
	}
};