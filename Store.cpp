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
    name = newName;
}

vector<Product> Store::getInv() {
    return inventory;
} // El iterador es un apuntador

void Store::setInventario(Product product, vector<Product> inventory, User creator) {
    if (creator.isAdmin()){
        inventory.push_back(product);
    }
}

std::string Store::getName() {
    return name;
}
