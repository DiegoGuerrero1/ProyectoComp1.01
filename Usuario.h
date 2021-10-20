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
    void setnPassword(std::string, std::string); //Necesita dos strings, una es la contraseña anterior y la otra es la nueva

    //Métodos principales
    void editPassword(std::string&, std::std::string&); //Nueva contraseña, contraseña anterior
    void editName(std::std::string&, std::std::stringn&); //Nombre, Contraseña
    //void addProducts(); Implementada en Tienda
    vector<Producto> getProducts(vector<Producto>, std::std::string); // Inventario, nombre del producto a cambiar

    float sellProducts(vector<Producto>); //Regresará el total

    //getInv();


private:
    std::string password;
    std::string uName const;
    bool admin const; //Constante porque no se puede cambiar, al menos por ahora no.
    float venta;




};


#endif
