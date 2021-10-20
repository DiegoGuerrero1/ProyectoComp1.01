//
// Created by guerrero on 10/19/21.
//Tienda.cpp
#include "Tienda.h"
#include <string>
#include <iostream>
#include "Producto.h"
#include "Usuario.h"
#include <vector>
using namespace std;
//Definición de constructor
Tienda::Tienda(std::string &tnombre = "DefaultStore", Producto firstItem = cocacola, vector<Producto> invAct = {0}, Usuario usrAct) {
    settName(tnombre);
    setInventario(firstItem, invAct, usrAct);

}

void Tienda::settName(string &nombreTienda) {
    nombreTiendaR = nombreTienda;
}


vector<Producto> Tienda::getInv() {
    return inventarioR;
}

void Tienda::setInventario(const Producto& unProducto, vector<Producto> inventarioActual, Usuario usuarioActual) {
    if (usuarioActual.isAdmin()){
        inventarioActual.push_back(unProducto);
    }

}

std::string Tienda::getName() {
    return nombreTiendaR;
}
