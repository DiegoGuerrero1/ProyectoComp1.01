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
public:

    Tienda(string nombreTienda, Producto firstItem, vector<Producto> invAct, Usuario usrAct);

    void settName(std::string &);
    vector<Producto> getInv();
    void setInventario(Producto, vector<Producto>, Usuario);
    std::string getName();


private:
    std::string nombreTienda{""};
    vector<Producto> inventarioTienda{};
    //Default vars
    std::string defNombreTienda = "Tienda default";

};


}



#endif //PROYECTOCOMP1_01_TIENDA_H
