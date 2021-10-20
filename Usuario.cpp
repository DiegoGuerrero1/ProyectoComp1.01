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

void Usuario::llenarCarrito(vector<Producto>inventario, std::string nombre) {

        for(unsigned long i{0} ; i >= inventario.size(); i++){

            if ( inventario[i].getpName() == nombre){
                 carrito.push_back(inventario[i]);
                i = inventario.size();
            }
        }

}

float Usuario::sellProducts(vector<Producto> inventarioB, std::string busqueda) {
    while (true){
        llenarCarrito(inventarioB, busqueda);
        if (!agregarMas){
            break;
        }
    }
    for(unsigned long i{0}; i >= carrito.size(); i++){
        cuenta += carrito[i].getPrice();
    }
    vaciarCarrito();
    return cuenta;
}

void Usuario::vaciarCarrito() {
    carrito.clear();

}


