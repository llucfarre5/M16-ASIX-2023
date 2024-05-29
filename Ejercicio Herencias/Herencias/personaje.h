#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
protected:
    std::string nombre;
    int vida;
    int ataque;
    int posicionX;
    int posicionY;

public:
    Personaje(std::string nombre, int vida, int ataque, int posX, int posY);
    std::string getNombre();
    int getVida();
    int getAtaque();
    int getPosX();
    int getPosY();
    void setPosX(int x);
    void setPosY(int y);
    void recibirDanio(int danio);
    virtual void atacar(Personaje& objetivo);
    bool estaVivo();
};

#endif