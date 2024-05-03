#include "Enemigo.h"

Lancha::Lancha(std::string _nombre, int _velocidad, int _nitro) : nombre(_nombre), velocidad(_velocidad), nitro(_nitro), distancia_recorrida(0) {}

void Lancha::usarNitro() {
    if (nitro == 1) {
        int random = rand() % 2;
        if (random == 0) {
            velocidad /= 2;
        }
        else {
            velocidad *= 2;
        }
        nitro = 0;
        std::cout << nombre << " activa el nitro" << std::endl;
    }
    else {
        std::cout << "No hay nitro disponible para " << nombre << std::endl;
    }
}

void Lancha::tirarCocaina(Lancha& otraLancha) {
    int random = rand() % 2;
    if (random == 0) {
        otraLancha.velocidad -= 3;
        std::cout << "Alberto Nunyez Feijoo ha tirado una caja de cocaina y ha acertado. ";
        std::cout << "La otra lancha pierde 3 de velocidad." << std::endl;
    }
    else {
        std::cout << "Alberto Nunyez Feijoo ha tirado una caja de cocaina, pero ha fallado." << std::endl;
        velocidad -= 3;
        std::cout << nombre << " pierde 3 de velocidad." << std::endl;
    }
}

void Lancha::avanzar() {
    int dado = rand() % 6 + 1;
    velocidad += dado;
    distancia_recorrida += velocidad;
    std::cout << nombre << " avanza con una velocidad de " << velocidad << " (Dado: " << dado << ")" << std::endl;
}

void Lancha::mostrarEstado() const {
    std::cout << nombre << " ha recorrido " << distancia_recorrida << " metros." << std::endl;
}

std::string Lancha::obtenerNombre() const{
    return nombre;
}

int Lancha::obtenerNitro() const{
    return nitro;
}
