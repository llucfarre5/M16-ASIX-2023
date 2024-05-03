#pragma once

#include <iostream>
#define LANCHA_H

using namespace std;

//class lancha1
//{
//private:
//	int velocidad;
//	int distanciaRecorrida;
//	string nameCorredor;
//	int nitro;

// public:
//	int getVelocidad();
//	void setHP(int pHP);
//	int getAttack();
//	void setAttack(int pattack);
//	string getName();
//	void setName(string pname);
//	void getParams();
//	Enemigo();
//	Enemigo(int pHp, int pattack, string pname);
//};

#include <string>
#include <cstdlib>
#include <ctime>

class Lancha {
private:
    std::string nombre;
    int velocidad;
    int distancia_recorrida;
    int nitro;

public:
    // Constructor
    Lancha(std::string _nombre, int _velocidad, int _nitro);

    // Métodos
    void usarNitro();
    void tirarCocaina(Lancha& otraLancha);
    void avanzar();
    void mostrarEstado() const;


    std::string obtenerNombre() const;
    int obtenerNitro() const;
};