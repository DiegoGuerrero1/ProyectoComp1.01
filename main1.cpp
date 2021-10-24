//
// Created by guerrero on 10/21/21.
//
#include <iostream>
/*#include "Tienda.h"
#include "Usuario.h"
#include "Producto.h"*/
#include "Product.h"
#include <vector>

using namespace std;


void addFirstProduct();
vector<Product> inventario;


void addProduct();

int main() {
    addProduct();

    return 0;
}

void addProduct() {
    std::string inName;
    std::string inExpiration;
    int inId;
    float inPrice;
    cout << "Ingresa el nobre del producto: \n" <<endl;
    getline(cin, inName);
    cout << "Ingresa el id: \n" << endl;
    cin >>inId;
    cin.ignore();
    cout << "Fecha de caducidad:\n" <<endl;
    getline(cin, inExpiration);
    cout << "Precio:\n" << endl;
    cin >> inPrice ;
    Product product{inId,inName,inExpiration,inPrice};
    inventario.push_back(product);


};

