#include "MathLibrary.h"

#include <iostream>
#include <vector>
#include <algorithm>

std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool productoEnLista(const std::vector<std::string>& lista, const std::string& producto) {
    std::string productoMinusculas = toLowerCase(producto);
    for (const auto& item : lista) {
        if (toLowerCase(item) == productoMinusculas) {
            return true;
        }
    }
    return false;
}

void insertarProducto(std::vector<std::string>& lista, const std::string& producto) {
    std::string productoMinusculas = toLowerCase(producto);
    auto it = std::find_if(lista.begin(), lista.end(), [&](const std::string& item) {
        return toLowerCase(item) == productoMinusculas;
        });

    if (it != lista.end()) {
        *it = producto;
        std::cout << "Producto modificado en la lista.\n";
    }
    else {
        lista.push_back(producto);
        std::cout << "Producto agregado a la lista.\n";
    }
}

void mostrarLista(const std::vector<std::string>& lista) {
    if (lista.empty()) {
        std::cout << "La lista de la compra está vacía.\n";
    }
    else {
        std::cout << "Lista de la compra:\n";
        for (const auto& item : lista) {
            std::cout << "- " << item << "\n";
        }
    }
}