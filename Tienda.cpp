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
Tienda::Tienda(string nombreT, Producto productoInicial, vector<Producto> invT, Usuario aUsr)
: nombreTienda{nombreT},
  productoVacio{productoInicial},
  invTienda{invT},
  actualUsr{aUsr}{
    cout << "Tienda " << nombreTienda <<" creada" << endl;
}


 /*{  //Ya no tienen caso los métodos set
    settName(nombreTienda);
    setInventario(productoVacio,inventarioTienda ,usuairodef);
}*/


void Tienda::settName(string nombreTienda) {
    nombreTienda = nombreTienda;
}


vector<Producto> Tienda::getInv() {
    return invTienda;
}

void Tienda::setInventario(Producto unProducto, vector<Producto> inventarioActual, Usuario usuarioActual) {
    if (usuarioActual.isAdmin()){
        inventarioActual.push_back(unProducto);
    }

}

std::string Tienda::getName() {
    return nombreTienda;
}


