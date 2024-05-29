#include "Personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(string nombre, int vida, int ataque, int posX, int posY)
    : nombre(nombre), vida(vida), ataque(ataque), posicionX(posX), posicionY(posY) {}

string Personaje::getNombre() { return nombre; }

int Personaje::getVida() { return vida; }

int Personaje::getAtaque() { return ataque; }

int Personaje::getPosX() { return posicionX; }

int Personaje::getPosY() { return posicionY; }

void Personaje::setPosX(int x) { posicionX = x; }

void Personaje::setPosY(int y) { posicionY = y; }

void Personaje::recibirDanio(int danio) { vida -= danio; }

void Personaje::atacar(Personaje& objetivo) {
    objetivo.recibirDanio(ataque);
    cout << nombre << " ataca a " << objetivo.getNombre() << " y le causa " << ataque << " de daño." << endl;
}

bool Personaje::estaVivo() { return vida > 0; }