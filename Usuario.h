//
// Created by guerrero on 10/19/21.
//Usuario.h


#ifndef PROYECTOCOMP1_01_USUARIO_H
#define PROYECTOCOMP1_01_USUARIO_H
#include <string>
#include <iostream>
#include <vector>
#include "Tienda.h"
#include "Producto.h"


using namespace std;

class Usuario{
public:
    explicit Usuario(std::string nombreUsuario const, std::string contraseña );
    //métodos get y set
    void setuName(std::string&);
    void editPassword(std::string&, std::string&); //Nueva contraseña, contraseña anterior
    void editName(std::string&, std::stringn&); //Nombre, Contraseña
    //void addProducts(); Implementada en Tienda
    vector<Producto> getProducts(vector<Producto>, std::string); // Inventario, nombre del producto a cambiar

    float sellProducts(vector<Producto>); //Regresará el total
    void vaciarCarrito(vector<Producto>);

    //getInv();


private:
    std::string uPassword;
    std::string uName const;
    bool admin const; //Constante porque no se puede cambiar, al menos por ahora no.
    float venta;
    vector<Producto> carrito;




};


#endif
