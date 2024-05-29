#pragma once
#ifndef ENEMIGO_FINAL_H
#define ENEMIGO_FINAL_H

#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    int superAtaque1;
    int superAtaque2; 

public:
    EnemigoFinal(std::string nombre, int vida, int ataque, int posX, int posY, int sa1, int sa2);
    void atacar(Personaje& objetivo) override;
};

#endif