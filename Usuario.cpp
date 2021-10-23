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

//
Usuario::Usuario(string nombreUsuario, string contraseña, bool willAdmin, char carSold)
:uName{nombreUsuario},uPassword{contraseña},admin{willAdmin},sold{carSold}{

    cout << "Usuario Creado. \nNombre:"<< getUsrName() << "\n Administrador:" << isAdmin() <<endl;

}

void Usuario::setuName(string userName) {
    uName = userName;


}
void Usuario::setPassword(string pass) {
    uPassword = pass;
}



void Usuario::editPassword(string oldPassword, string newPasword) {
    if(oldPassword == uPassword){
        setPassword(newPasword);
        cout <<"contraseña cambiada"<<endl;
    }else {
        cout << "Contraseña incorrecta" << endl;
    }
}

void Usuario::editName(string currentPassword, std::string newName) {
    if (isThePasword(currentPassword)){
        setuName(newName);
    }

}
void Usuario::setFoundProduct(Producto product) {
    productsFound[0] = product;
}

void Usuario::findProductbyName(string nombre, vector<Producto> inventario) {
    for(unsigned long i{0} ; i >= inventario.size(); i++){

        if ( inventario[i].getpName() == nombre){
            i = inventario.size();
            setFoundProduct(inventario[i]) ;         //Estaría bueno implementar una búsqueda más optimizada

        }else{
            clearFoundProduct();

        }

    }

}
void Usuario::findProductbyId(int id , vector<Producto> inventarioAc) {
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



void Usuario::llenarCarrito(vector<Producto> inventario, int id, vector<Producto> carritoSuper) {

   findProductbyId(id, inventario);
   carrito = productsFound;

}

float Usuario::sellProducts(vector<Producto> inventarioB, int busquedaId) {

    while (true){
        llenarCarrito(inventarioB, busquedaId, vector<Producto>());
        if (!agregarMas){
            break;
        }
    }
    cout << "¿Pago recibido? s:si, n:no"<< endl;
    cin >> carritoVendido;
    if (carritoVendido == 's'){
        for (unsigned int i{0} ; i <= size(inventarioB); i++){
            inventarioB.erase(carrito[i]);

        }


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

void Usuario::editPrice(int prodEditarId, vector<Producto> invActual) {
    float nuevoPrecio;
    if (!isAdmin()){
        cout << "El usuario no es administrador"<< endl;
    }else{
        cout << "Por el momento sólo se puede reemplazar por id" << endl;
        findProductbyId(prodEditarId, invActual);
        productsFound[0].setPrice(nuevoPrecio);
    }

}

void Usuario::removeProduct(int pId, vector<Producto> invact) {
    findProductbyId(pId, invact);
    std::erase(invact, productsFoundIndex); //Pasmaos el vector de inventario y elimina el Index del producto encontrado
}

void Usuario::setAdmin(bool padm) {
    admin = padm;

}

void Usuario::setSold(char s) {
    if(s == 's'){
        sold = true;
    }else{
        sold = false;
    }
}

void Usuario::makeAdmin(char madmin) {

        switch (madmin) {
            case 's':
                setAdmin(true);
                break;
            case 'n':
                setAdmin(false);
                break;
            case 'c':
                break;
            default:
                cout << "Opción no válida, asignando empleado " << endl;
                break;

        }



}

std::string Usuario::getUsrName() {
    return uName;
}

std::string Usuario::getDefPassword() {
    return defaultPassword;
}

bool Usuario::isThePasword(string testPassword) {
    if(uPassword != testPassword){
        return false;
    }else{
        return true;
    }

}
















