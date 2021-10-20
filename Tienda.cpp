//
// Created by guerrero on 10/19/21.
//Tienda.cpp
#include "Tienda.h"
#include <string>
#include <iostream>
#include "Producto.h"
#include <vector>
using namespace std;
//Definición de constructor
Tienda::Tienda(std::string &tnombre, Producto firstItem) {
    settName(tnombre);
    setInventario(firstItem);

}

void Tienda::settName(string &nombreTienda) {
    nombreTiendaR = nombreTienda;
}


vector<Producto> Tienda::getInv() {
    return inventarioR;
}

void Tienda::setInventario(Producto unProducto) {
    inventarioR.push_back(unProducto);
}

std::string Tienda::getName() {
    return nombreTiendaR;
}
