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



Producto::Producto(int id, string nombreItem, string caducidad , float precioItem):
idR{id}, nombreProductoR{nombreItem},caducidadR{caducidad},precioR{precioItem}
{
    cout << "Producto creado. \n Id: "<<getId()<<"\nNombre: "<<getpName()<<"\nPrecio:"<<getPrice()<<endl;
    cout << "Producto creado. \n Id: "<<idR<<"\nNombre: "<<nombreItem<<"\nPrecio:"<<precioItem<<endl;
}

//constructores delegados
//Producto::Producto(): Producto{0,"None","None",00.00};

void Producto::setId(int itemId) {
    idR = itemId;
}

void Producto::setExpd(string expd) {
    caducidadR = expd;

}
void Producto::setpName(string itemName){
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

void Producto::setPrice(float precio) {
    precioR = precio;

}

float Producto::getPrice() {
    return precioR;
}





