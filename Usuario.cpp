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
void Usuario::setFoundProduct(Producto &product) {
    productsFound[0] = product;
}

void Usuario::findProductbyName(string &nombre, vector<Producto> &inventario) {
    for(unsigned long i{0} ; i >= inventario.size(); i++){

        if ( inventario[i].getpName() == nombre){
            i = inventario.size();
            setFoundProduct(inventario[i]) ;         //Estaría bueno implementar una búsqueda más optimizada

        }else{
            clearFoundProduct();

        }

    }

}
void Usuario::findProductbyId(int &id , vector<Producto> &inventarioAc) {
    for(unsigned long i{0} ; i >= inventarioAc.size(); i++){

        if ( inventarioAc[i].getId() == id){
            setFoundProduct(inventarioAc[i]);
            productsFoundIndex = i; //Estaría bueno implementar una búsqueda más optimizada
            i = inventarioAc.size();


        }else{
            clearFoundProduct();

        }

    }

}



void Usuario::llenarCarrito(vector<Producto>inventario, int &id, Usuario usrA) {

   usrA.findProductbyId(id, inventario);
   carrito = productsFound;

}

float Usuario::sellProducts(vector<Producto> inventarioB, int &busquedaId, const Usuario& tUser) {
    while (true){
        llenarCarrito(inventarioB, busquedaId, tUser);
        if (!agregarMas){
            break;
        }
    }
    cout << "¿Pago recibido? s:si, n:no"<< endl;
    cin >> vendido;
    if (vendido =='s'){

    } else{
        cout << "Operación cancelada" <<endl;
        vaciarCarrito();
    }


   // return cuenta;
}


void Usuario::vaciarCarrito() {
    carrito.clear();

}

bool Usuario::isAdmin() {
    if(!admin){
        return false;
    }else{
        return true;
    };

}

void Usuario::clearFoundProduct() {
    productsFound.clear();
    cout << "No se encontró ningún producto."<<endl;
}

void Usuario::editPrice(int &prodEditarId, Usuario uActual, vector<Producto> invActual) {
    if (!uActual.isAdmin()){
        cout << "El usuario no es administrador"<< endl;
    }else{
        findProductbyId(prodEditarId, invActual);

    }

}

void Usuario::removeProduct(int &pId, vector<Producto> invact) {
    findProductbyId(pId, invact);
    std::erase(invact, productsFoundIndex); //Pasmaos el vector de inventario y elimina el Index del producto encontrado
}







