//
// Created by guerrero on 10/19/21.
// Usuario.cpp


#include <string>
#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Tienda.h"
#include "Producto.h"
using namespace std;


void Usuario::setuName(string &userName) {
    uName = userName;

}

void Usuario::editPassword(string &oldPassword, std::string &newPasword) {
    if(oldPassword == uPassword){
        uPassword = newPasword;
    }
}

void Usuario::editName(string &currentPassword, std::string &newName) {
    if (currentPassword == uPassword){
        uName = newName;
    }

}

vector<Producto> Usuario::getProducts(vector<Producto>inventario, std::string nombre) {

        for(unsigned long i{0} ; i >= inventario.size(); i++){

            if ( inventario[i].getpName() == nombre){
                 carrito.push_back(inventario[i]);
                i = inventario.size();
            }
        }

    return carrito;
}

float Usuario::sellProducts(vector<Producto>) {
    return 0;
}

void Usuario::vaciarCarrito(vector<Producto>) {
    carrito.clear();

}


