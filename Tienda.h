//
// Created by guerrero on 10/19/21.
//Tienda.h

#ifndef PROYECTOCOMP1_01_TIENDA_H
#define PROYECTOCOMP1_01_TIENDA_H
#include <string>
#include <vector>
#include "Producto.h"
#include "Usuario.h"

using namespace std;
class Tienda{

    Tienda(string &tnombre, Producto firstItem, vector<Producto> invAct, Usuario usuarioDefault);

    void settName(std::string&);
    vector<Producto> getInv();
    void setInventario(const Producto&, vector<Producto>, Usuario);
    std::string getName();



private:
    std::string nombreTiendaR;
    vector<Producto> inventarioR;

    //Default vars
    std::string defNombreTienda = "Tienda default";

};


}



#endif //PROYECTOCOMP1_01_TIENDA_H
