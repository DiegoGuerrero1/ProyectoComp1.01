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

    explicit Tienda(std::string&, Producto&, vector<Producto>&, Usuario&);


    //Al usar objetos en un constructor se le llama composisión y deben ser inicializadas de manera diferente, inclusive los strings son objetos también.
    // también se pasan por referencia.
    void settName(std::string &);
    vector<Producto> getInv();
    void setInventario(Producto, vector<Producto>, Usuario);
    std::string getName();


private:
    std::string nombreTienda;
    vector<Producto> invTienda;
    Producto productoVacio;
    Usuario actualUsr;



};


}



#endif //PROYECTOCOMP1_01_TIENDA_H
