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
    //void setInventario(const Producto&, vector<Producto>); Implementada en Tienda
    void llenarCarrito(vector<Producto>, int&, Usuario ); // Inventario, nombre del producto a cambiar
    bool isAdmin();
    void findProductbyName(std::string&, vector<Producto>&);
    void findProductbyId(int& id, vector<Producto>&);
    float sellProducts(vector<Producto>, std::string); //Regresará el total
    void vaciarCarrito();
    void editPrice(int &prodEditarId, Usuario uActual, vector<Producto> invActual);
    void setFoundProduct(Producto &product);
    void clearFoundProduct();



    //getInv();


private:
    std::string uPassword;
    std::string uName const;
    bool admin const; //Constante porque no se puede cambiar, al menos por ahora no.
    float venta;
    vector<Producto> carrito;
    bool agregarMas;
    float cuenta;
    vector<Producto&> productsFound; //Por referencia ya que voy a estar cambiando este objeto constantemente






};


#endif
