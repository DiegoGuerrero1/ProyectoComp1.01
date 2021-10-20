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
    Tienda(std::string&, Producto);

    //Métodos  set y get (Omitir en el diseño del menú)

    void settName(std::string&);
    void setInventario(Producto);
    vector<Producto> getInv();
    std::string getName();


private:
    std::string nombreTiendaR;
    vector<Producto> inventarioR;

};






#endif //PROYECTOCOMP1_01_TIENDA_H
