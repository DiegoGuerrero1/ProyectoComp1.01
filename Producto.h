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

using namespace std;
//Definición de la clase Producto
class Producto{
public:
    explicit Producto(int id, const std::string& caducidad);  //Creamos constructor default
    //métodos set() y get()
    void setId(int);
    void setExpd(std::string&);
    void getId(std::string);
private:
    int id;
    std::string caducidad;


};




#endif
