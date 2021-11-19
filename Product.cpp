//
// Created by guerrero on 10/23/21.
//

#include "Product.h"
#include <string>
#include <iostream>

using namespace std;

Product::Product(int pId,string pName, string pExpiration, float pPrice)
: id{pId},name{pName},expiration{pExpiration}, price{pPrice}{

    cout << "Producto creado. \nId: "<<id<<"\nNombre: "<< name << "\nCaducidad: "<< expiration <<"\nPrecio: "<<price<<endl;
    //cout << "Producto creado. \n Id: "<<getId()<<"\nNombre: "<<getpName()<<"\nPrecio:"<<getPrice()<<endl;
}

void Product::setExpd(string expd) {
    expiration = expd;

}
void Product::setpName(string itemName){
    name = itemName;

}
int Product::getId() {
    return id;
}

std::string Product::getExpd() {

    return expiration;
}

std::string Product::getpName() {
    return name;
}

void Product::setPrice(float precio) {
    price = precio;

}

float Product::getPrice() {
    return price;
}

void Product::setId(int) {

}

Product::~Product() {
cout << "Producto " << getpName() <<" con id: "<< getId() << " eliminado" << endl;
}
