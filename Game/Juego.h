#pragma once
#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "Background.h"
ref class ControladorJuego //Clase que controla elementos del juego
{
private:
	Jugador* jugador;
	Obstaculos* obstaculos;
	Enemigos* enemigos;
	Background* background;
	Background* vidaBackground;

	Bitmap^ imgArbusto;
	Bitmap^ imgDelibird;
	Bitmap^ imgBackground;
	Bitmap^ imgVidas;
	Bitmap^ imgGengar;

	int cooldownAtaqueEnemigo;

	int tiempo;

	bool resultado;
public:
	ControladorJuego(int v, int e, int t) { //Inicializar
		imgArbusto = gcnew Bitmap("img/Arbusto.png");
		imgDelibird = gcnew Bitmap("img/Delibird.png");
		imgGengar = gcnew Bitmap("img/Gengar.png");
		imgBackground = gcnew Bitmap("img/Game_Background.png");
		imgVidas = gcnew Bitmap("img/Delibird_Vidas.png");

		vidaBackground = new Background(imgVidas);
		background = new Background(imgBackground);
		jugador = new Jugador(imgDelibird, v);
		obstaculos = new Obstaculos(12, jugador->Area(), imgArbusto);
		enemigos = new Enemigos(imgGengar, e);

		cooldownAtaqueEnemigo = 0;

		tiempo = t * 1000 + clock();
	}
	~ControladorJuego() {
		delete jugador, obstaculos, imgArbusto;
	}

	bool GetResultado() {
		return resultado;
	}
	
	bool Mover(Graphics^ g) {
		if (enemigos->Colision(jugador->HitBox()) && clock() - cooldownAtaqueEnemigo >= 2300) {
			cooldownAtaqueEnemigo = clock();
			jugador->SetVidas(-1);

			if (jugador->GetVidas() == 0) {
				return false;
			}
		}

		if (clock() >= tiempo) {
			resultado = true;
			return false;
		}

		if (obstaculos->Colision(jugador->NextHitBox()) == false) {
			jugador->Mover(g);
		}

		obstaculos->Mover(g);
		enemigos->Mover(g);

		return true;
	}

	void Mostrar(Graphics^ g) {
		background->Mostrar(g, imgBackground);
		
		enemigos->Mostrar(g, imgGengar);
		
		jugador->Mostrar(g, imgDelibird);
		
		obstaculos->Mostrar(g, imgArbusto);

		g->DrawString("Tiempo: " + ((tiempo - clock()) / 1000), gcnew Font("Arial", 22), Brushes::Blue, 400, 20);
		vidaBackground->Mostrar(g, imgVidas);
	}

	void MovimientoJugador(bool accion, Keys tecla) { //Verifica si la tecla está presionada o no
		int v = 4;
		if (accion == true) { //La tecla está presionada
			if (tecla == Keys::Up) {
				jugador->SetDY(-v);
				jugador->SetAccion(CaminarArriba);
			} 
			else if (tecla == Keys::Down) {
				jugador->SetDY(v);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::Left) {
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right) {
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
		}
		else { //La tecla no está presionada
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}
	}
};