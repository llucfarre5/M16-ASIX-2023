#include "EnemigoFinal.h"
#include <iostream>

using namespace std;

EnemigoFinal::EnemigoFinal(string nombre, int vida, int ataque, int posX, int posY, int sa1, int sa2)
    : Personaje(nombre, vida, ataque, posX, posY), superAtaque1(sa1), superAtaque2(sa2) {}

void EnemigoFinal::atacar(Personaje& objetivo) {
    int ataqueFinal = rand() % 2 == 0 ? superAtaque1 : superAtaque2;
    objetivo.recibirDanio(ataqueFinal);
    cout << nombre << " usa un super ataque y causa " << ataqueFinal << " de daño a " << objetivo.getNombre() << "." << endl;
}