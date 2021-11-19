//
// Created by guerrero on 10/23/21.
//

#ifndef PROYECTOCOMP1_01_STORE_H
#define PROYECTOCOMP1_01_STORE_H
#include <string>
#include <vector>
#include "Product.h"
#include "User.h"


class Store {
public:
    explicit Store(std::string, Product, std::vector<Product>, User);
    ~Store();
//Methods
    void settName(std::string);
    vector<Product> getInv();
    void setInventario(Product, vector<Product>, User);
    std::string getName();

private:
    std::string name;
    Product initialProduct;
    vector<Product> inventory;
    User forsearchUser;

};

#endif //PROYECTOCOMP1_01_STORE_H
