// MathClient.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include "MathLibrary.h"

int main() {
    std::vector<std::string> listaDeCompra;

    std::string producto;
    char continuar;

    do {
        std::cout << "Ingrese el nombre del producto: ";
        std::cin >> producto;

        insertarProducto(listaDeCompra, producto);

        std::cout << "¿Desea agregar otro producto? (y/n): ";
        std::cin >> continuar;

    } while (continuar == 'y' || continuar == 'Y');

    mostrarLista(listaDeCompra);

    return 0;
}