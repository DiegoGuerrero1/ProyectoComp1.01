//
// Created by guerrero on 10/19/21.
//

#ifndef PROYECTOCOMP1_01_TIENDA_H
#define PROYECTOCOMP1_01_TIENDA_H

using namespace std;
class Tienda{
public:
    explicit Tienda(std::string& nombreTienda);

    //Métodos  set y get (Omitir en el diseño del menú)
    void setName();
    void getName();

    //Métodos Principales
    void vender();
    void Inv();
    void editPrecios();
    void agregarProductos();

private:
    std::string Name;

};






#endif //PROYECTOCOMP1_01_TIENDA_H
