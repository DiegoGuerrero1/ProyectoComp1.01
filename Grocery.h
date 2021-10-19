/*
 * Authors: Diego Guerrero, Luis Daiman, Ivan Olvera
 * Contact: diegoguerrero@comunidad.unam.mx, Pongan sus correos porfas jasjas 
 * Date: 18/10/21 
 */ 

#ifndef GROCERY_H
#define GROCERY_H
#include "array"
#include "vector"
#include "string"

class Producto{
    std::string id;
    std::string nombre;
    std::string caducidad;
    std::string tipo;
};

class Tienda{
	public:
    explicit Tienda(std::string& name const):
    nombre{name}{

    }




    std::string nombre;
};



#endif
