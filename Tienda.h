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


    explicit Tienda(string="");

    void settName(std::string &);
    vector<Producto> getInv();
    void setInventario(Producto, vector<Producto>, Usuario);
    std::string getName();


private:
    std::string nombreTienda{"Tienda default"};
    vector<Producto> inventarioTienda{};
    Usuario usuairodef;
    Producto productoVacio;



};


}



#endif //PROYECTOCOMP1_01_TIENDA_H
