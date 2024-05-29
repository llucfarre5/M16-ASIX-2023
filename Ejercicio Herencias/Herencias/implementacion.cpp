#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

void batalla(Personaje& heroe, Personaje& enemigo) {
    while (heroe.estaVivo() && enemigo.estaVivo()) {
        heroe.atacar(enemigo);
        if (!enemigo.estaVivo()) {
            cout << enemigo.getNombre() << " ha sido derrotado!" << endl;
            break;
        }
        enemigo.atacar(heroe);
        if (!heroe.estaVivo()) {
            cout << heroe.getNombre() << " ha sido derrotado! Game Over." << endl;
            exit(0);
        }
    }
}

void imprimirMapa(vector<vector<char>>& mapa, int heroeX, int heroeY) {
    for (int i = 0; i < mapa.size(); ++i) {
        for (int j = 0; j < mapa[i].size(); ++j) {
            if (i == heroeX && j == heroeY) {
                cout << 'H' << " ";
            }
            else if (mapa[i][j] == 'E') {
                cout << 'E' << " ";
            }
            else if (mapa[i][j] == 'S') {
                cout << 'S' << " ";
            }
            else {
                cout << '.' << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    const int nFilas = 10;
    const int nColumnas = 10;

    vector<vector<char>> mapa(nFilas, vector<char>(nColumnas, ' '));

    int salidaX = nFilas - 1;
    int salidaY = rand() % nColumnas;
    mapa[salidaX][salidaY] = 'S';

    vector<string> nombresEnemigos = { "Darmian Suarez", "Casemiro", "Pepe", "Chiellini", "Sergio Ramos" };
    vector<Personaje> enemigos;
    for (int i = 0; i < 5; ++i) {
        int ex = rand() % nFilas;
        int ey = rand() % nColumnas;
        enemigos.push_back(Personaje(nombresEnemigos[i], 50, 10, ex, ey));
        mapa[ex][ey] = 'E';
    }

    EnemigoFinal jefeFinal("Fali", 100, 30, salidaX, salidaY, 30, 40);

    Personaje heroe("Bebeto", 200, 20, 0, 0);

    bool ganado = false;

    while (!ganado) {
        imprimirMapa(mapa, heroe.getPosX(), heroe.getPosY());
        cout << "Muevete (w/a/s/d): ";
        char movimiento;
        cin >> movimiento;

        int nuevoX = heroe.getPosX();
        int nuevoY = heroe.getPosY();

        if (movimiento == 'w' && nuevoX > 0) nuevoX--;
        if (movimiento == 's' && nuevoX < nFilas - 1) nuevoX++;
        if (movimiento == 'a' && nuevoY > 0) nuevoY--;
        if (movimiento == 'd' && nuevoY < nColumnas - 1) nuevoY++;

        heroe.setPosX(nuevoX);
        heroe.setPosY(nuevoY);

        for (auto& enemigo : enemigos) {
            if (heroe.getPosX() == enemigo.getPosX() && heroe.getPosY() == enemigo.getPosY()) {
                cout << "Te has encontrado con " << enemigo.getNombre() << "!" << endl;
                batalla(heroe, enemigo);
            }
        }

        if (heroe.getPosX() == salidaX && heroe.getPosY() == salidaY) {
            cout << "Te has encontrado con el enemigo final!" << endl;
            batalla(heroe, jefeFinal);
            if (heroe.estaVivo()) {
                cout << "¡Has ganado el juego!" << endl;
                ganado = true;
                break;
            }
        }
    }

    return 0;
}
