#pragma once

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>

std::string toLowerCase(const std::string& str);
bool productoEnLista(const std::vector<std::string>& lista, const std::string& producto);
void insertarProducto(std::vector<std::string>& lista, const std::string& producto);
void mostrarLista(const std::vector<std::string>& lista);

#endif