/*
 * Authors: Diego Guerrero
 * Contact: diegoguerrero@comunidad.unam.mx,
 * Date: 18/10/21
 * INTERFACE.
 */ 

#ifndef PRODUCTO_H
#define PRODUCTO_H //Evitamos iclusiones múltiples del header
#include "array"
#include "vector"
#include "string"
#include <iostream>

using namespace std;
//Definición de la clase Producto
class Producto{
public:
    Producto(int, string&, std::string&, float& );  //Creamos constructor default
    //métodos set() y get()
    void setId(int&);
    void setExpd(std::string&);
    void setpName(std::string&);
    void setPrice(float&);
    int getId();
    std::string getExpd();
    std::string getpName();
    float getPrice() const;


private:
    int idR;
    std::string caducidadR;
    std::string nombreProductoR;
    float precioR;

};




#endif
