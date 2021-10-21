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
    explicit Producto(int=0000, std::string="" , std::string="" , float = 0.0);  //Creamos constructor default

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
    int idR{0000};
    std::string caducidadR{"00/00/00"};
    std::string nombreProductoR{"None"};
    float precioR{00.00};

};




#endif
