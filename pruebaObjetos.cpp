//
// Created by guerrero on 10/23/21.
//

#include "Tienda.h"
#include "Producto.h"
#include "Usuario.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int mai(){
    Producto producto{1,"none","00/00/00",00.00};
    Usuario usuario;
    //cout << "Usuario Creado. \nNombre:"<< usuario.getUsrName() << "\n Administrador:" << usuario.isAdmin() <<endl;
    Tienda tienda;
    //cout << "Tienda creada \nNombre: "<< tienda.getName()<<endl;

    return 0;
};