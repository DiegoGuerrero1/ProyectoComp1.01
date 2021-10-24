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
    explicit Usuario(std::string="Default",std::string = "parosinohaypresenciales", bool = false, char ='n'); //Constructor default
    //métodos get y set
    void setuName(std::string);
    void setPassword(std::string);
    void setAdmin(bool);
    std::string getUsrName();
    void editPassword(std::string, std::string); //Nueva contraseña, contraseña anterior
    void editName(std::string, std::string); //Nombre, Contraseña
    void setSold(char);


    //void setInventario(const Producto&, vector<Producto>); Implementada en Tienda
    void llenarCarrito(vector<Producto>, int , vector<Producto>); // Inventario, nombre del producto a cambiar
    bool isAdmin();
    std::string getDefPassword();
    bool isThePasword(std::string); //Dice si es igual o no a la contraseña sin exponerla
    void findProductbyName(std::string, vector<Producto>);
    void findProductbyId(int id, vector<Producto>);
    float sellProducts(vector<Producto>, int); //Regresará el total
    void vaciarCarrito();
    void editPrice(int, vector<Producto>);
    void setFoundProduct(Producto);
    void clearFoundProduct();
    void removeProduct(int, vector<Producto>);
    void makeAdmin(char);





    //getInv();




private:
    std::string uPassword{"parosinohaypresenciales"};
    std::string uName{"Default"};
    bool admin{false}; //Constante porque no se puede cambiar, al menos por ahora no.
    //float venta{00.00};
    vector<Producto> carrito;
    bool agregarMas{false};
    float cuenta{00.00};
    vector<Producto&> productsFound; // must be public
    unsigned long productsFoundIndex{0}; //must be public
    char &carritoVendido{'n'};
    //bool &sold{false};
    char padm{'n'};

    std::string defaultPassword = "parosinohaypresenciales";


};


#endif
