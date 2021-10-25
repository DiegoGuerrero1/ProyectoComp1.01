//
// Created by guerrero on 10/23/21.
//

#include "Store.h"
#include "Product.h"
#include "User.h"
#include <string>
#include <iostream>

Store::Store(string storeName, Product firstItem, vector<Product> storeInventory, User usuarioBusqueda):
name{storeName}, initialProduct{firstItem}, inventory{storeInventory}, forsearchUser{usuarioBusqueda}
{
    cout << "Tienda creada." <<"\nNombre: " <<storeName << "\nCreador: "<< usuarioBusqueda.getUsrName() << endl;
}

void Store::settName(string newName) {

}

vector<Product> Store::getInv() {

}

void Store::setInventario(Product, vector<Product>, User) {

}

std::string Store::getName() {
    return std::string();
}
