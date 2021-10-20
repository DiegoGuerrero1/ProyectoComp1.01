/*
 * Authors: Diego Guerrero, Luis Daiman, Ivan Olvera
 * Contact: diegoguerrero@comunidad.unam.mx, Pongan sus correos porfas jasjas 
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
    Producto(int, string&, std::string&);  //Creamos constructor default
    //métodos set() y get()
    void setId(int&);
    void setExpd(std::string&);
    void setpName(std::string&);
    int getId();
    std::string getExpd();
    std::string getpName();


private:
    int idR;
    string caducidadR;
    string nombreProductoR;

};




#endif
