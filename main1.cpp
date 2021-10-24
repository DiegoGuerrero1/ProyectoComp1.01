//
// Created by guerrero on 10/21/21.
//
#include <iostream>
/*#include "Tienda.h"
#include "Usuario.h"
#include "Producto.h"*/
#include "Product.h"
#include "User.h"
#include <vector>

using namespace std;


void addFirstProduct();
vector<Product> inventario;
vector<User> listaUsuarios;


void createProduct();
void createUser();

int main() {
    createUser();
    createProduct();

    return 0;
}

void createProduct() {
    std::string inName;
    std::string inExpiration;
    int inId;
    float inPrice;
    cout << "Ingresa el nobre del producto: \n" <<endl;
    cin.ignore();
    getline(cin, inName);
    cout << "Ingresa el id: \n" << endl;
    cin.ignore();
    cin >>inId;
    cin.ignore();
    cout << "Fecha de caducidad:\n" <<endl;
    getline(cin, inExpiration);
    cout << "Precio:\n" << endl;
    cin >> inPrice ;
    Product product{inId,inName,inExpiration,inPrice};
    inventario.push_back(product);


};

void createUser(){
    std::string inNameU;
    std::string inPasswU;
    std::string inRepeatPass;
    char admin;
    cout << "Ingresa el nobre del usuario: \n" <<endl;
    getline(cin, inNameU);
    cout << "Crea una contraseña: \n" << endl;
    cin.ignore();
    getline(cin, inPasswU);
    cout << "Repite la contraseña:\n" <<endl;
    cin.ignore();
    getline(cin, inRepeatPass);

    if(inPasswU == inRepeatPass){
        User newUser{inNameU, inPasswU, false};
       cout << "¿Hacer administrador? s:si, n:no" << endl;
       cin >> admin;
       newUser.makeAdmin(admin);
       listaUsuarios.push_back(newUser);

    }else{
        cout <<"Las contraseñas no coinciden, cancelando operación";
    }





}
