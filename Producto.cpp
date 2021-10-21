//
// Created by guerrero on 10/19/21.
//



#include <iostream>
#include <string>
#include "Producto.h"
#include "Usuario.h"

using namespace std;
// Si se pudooooo ahuevo xd

using namespace std;
//Declaración de Constructures de las clases



Producto::Producto(int id, std::string nombreItem, std::string caducidad , float precioItem){
    setId(id);
    setExpd(caducidad);
    setpName(nombreItem);
    setPrice(precioItem);



}
void Producto::setId(int& itemId) {
    idR = itemId;
}

void Producto::setExpd(std::string& expd) {
    caducidadR = expd;

}
void Producto::setpName(std::string& itemName){
    nombreProductoR = itemName;

}
int Producto::getId() {
    return idR;
}

std::string Producto::getExpd() {

    return caducidadR;
}

std::string Producto::getpName() {
    return nombreProductoR;
}

void Producto::setPrice(float &precio) {
    precioR = precio;

}

float Producto::getPrice() {
    return precioR;
}





