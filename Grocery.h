/*
 * Authors: Diego Guerrero, Luis Daiman, Ivan Olvera
 * Contact: diegoguerrero@comunidad.unam.mx, Pongan sus correos porfas jasjas 
 * Date: 18/10/21
 * INTERFACE.
 */ 

#ifndef GROCERY_H
#define GROCERY_H //Evitamos iclusiones múltiples del header
#include "array"
#include "vector"
#include "string"

using namespace std;
//Definición de la clase Producto
class Producto{
public:
    explicit Producto(int id, std::string caducidad);  //Creamos constructor default

private:
    int id;
    std::string caducidad;


};

class Tienda{
public:
    explicit Tienda(std::string& nombreTienda);
    //Generamos las funciones
    //Las funciones "Vender" y "Ver inventairo" Deberían permanecer públicas para cada usuario
    void vender();
    void GetInv();
    void editPrecios();
    void agregarProductos();

private:
    std::string Name;

};

class Usuario{
public:
    explicit Usuario(std::string nombreUsuario, std::string contraseña);
    void editPassword();
    void editName();

private:
    std::string password;
    std::string uName;


//Creo que ya está (por ahora)
};



#endif
