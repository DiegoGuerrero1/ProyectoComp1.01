//
// Created by guerrero on 10/19/21.
//

#ifndef PROYECTOCOMP1_01_TIENDA_H
#define PROYECTOCOMP1_01_TIENDA_H
#include <string>
#include <vector>
#include "Producto.h"
#include "Usuario.h"

using namespace std;
class Tienda{
public:
    explicit Tienda(std::string& nombreTienda);

    //Métodos  set y get (Omitir en el diseño del menú)
    void setName(std::string&);
    std::string getName(std::string);
    Producto getProducto(int, vector <Producto>);


    //Métodos Principales
    void vender();
    vector<Producto> getInv(Tienda);
   void buscarProducto(Producto);
    void editPrecios();
    void agregarProductos(Producto);

private:
    std::string Name;
    vector<Producto> inventario;

};






#endif //PROYECTOCOMP1_01_TIENDA_H
