
#include <iostream>
#include "Enemigo.h"

int main() {
    srand(time(0)); // Inicializa la semilla para generar números aleatorios


    Lancha lancha1("Guardia Civil", 0, 1);
    Lancha lancha2("narcolancha", 0, 1);

    for (int turno = 1; turno <= 5; turno++) {
        std::cout << "Turno " << turno << std::endl;

        lancha1.avanzar();
        lancha2.avanzar();

        if (lancha1.obtenerNitro() == 1) {
            char respuesta;
            std::cout << "¿Desea usar el nitro para " << lancha1.obtenerNombre() << "? (s/n): ";
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                lancha1.usarNitro();
            }
        }

        if (lancha2.obtenerNitro() == 1) {
            char respuesta;
            std::cout << "¿Desea usar el nitro para " << lancha2.obtenerNombre() << "? (s/n): ";
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                lancha2.usarNitro();
            }
        }

        if (lancha2.obtenerNombre() == "narcolancha") {
            char respuesta;
            std::cout << "¿Desea tirar una caja de cocaina con " << lancha2.obtenerNombre() << "? (s/n): ";
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                lancha2.tirarCocaina(lancha1);
            }
        }
    }

}