//
// Created by guerrero on 10/23/21.
//

#ifndef PROYECTOCOMP1_01_USER_H
#define PROYECTOCOMP1_01_USER_H
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

class User {
public:
    //constructor
    User(std::string, std::string, bool);


    //Methods
    void makeAdmin(char);
    void setAdmin(bool);
    bool isThePasword(std::string);
        //setters and getters
    std::string getUsrName();
    /*void setuName(std::string);
    void setPassword(std::string);


        //Miscelaneus
    void editPassword(std::string, std::string);
    void editName(std::string, std::string);
    void setSold(char);
    void llenarCarrito(vector<Producto>, int , vector<Producto>);
    bool isAdmin();

        //Accesibles al usuario final
    void findProductbyName(std::string, vector<Producto>);
    void findProductbyId(int id, vector<Producto>);
    float sellProducts(vector<Producto>, int); //Regresará el total
    void vaciarCarrito();
    void editPrice(int, vector<Producto>);
    void setFoundProduct(Producto);
    void clearFoundProduct();
    void removeProduct(int, vector<Producto>); */
private:
    std::string name;
    std::string password;
    bool admin;
    float sellBill;
    std::vector<Product> cart;
    bool addItemCart;
    std::vector<Product> foundProducts;
    char moneyReceived;

};


#endif //PROYECTOCOMP1_01_USER_H
