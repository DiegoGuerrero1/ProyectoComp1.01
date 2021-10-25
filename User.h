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
    void setuName(std::string);
    void setPassword(std::string);


        //Miscelaneus
    void editPassword();
    void editName();
    void setSold(char);
    void llenarCarrito(vector<Product>);
    bool isAdmin();

        //Accesibles al usuario final
    void findProductbyName( vector<Product>);
    void findProductbyId(vector<Product>);
    float sellProducts(vector<Product>); //Regresará el total
    void vaciarCarrito();
    void editPrice(vector<Product>);
    void setFoundProduct(Product);
    void clearFoundProduct();
    void removeProductFound(vector<Product>);

    void editUser();

    void addProducts(Product, vector<Product>);

private:
    std::string name;
    std::string password;
    bool admin;
    float sellBill;
    std::vector<Product> cart;
    bool addItemCart;
    std::vector<Product> foundProducts;
    char moneyReceived;
    unsigned int productoFoundIndex;

};


#endif //PROYECTOCOMP1_01_USER_H
