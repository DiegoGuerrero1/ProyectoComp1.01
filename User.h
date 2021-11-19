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
    ~User();


    //Methods
    void makeAdmin(char);
    void setAdmin(bool);
    bool isThePasword(string &testPassword);
        //setters and getters
    std::string getUsrName();
    void setuName(std::string);
    void setPassword(std::string);


        //Miscelaneus
    void editPassword();
    void editName();
    void setSold(char);
    void addtoCart(vector<Product> &inventario);
    bool isAdmin();
    void echo(bool on);
    void inputPassword(string &pwrd);

    static Product & findProductbyId(vector<Product> &inventario);
    void sellProducts(vector<Product> &inventario); //Regresará el total
    void vaciarCarrito();
    void editPrice(vector<Product> &inventario);

    void editUser();

    void addProducts(Product, vector<Product>);

private:
    std::string name;
    std::string password;
    bool admin;
    Product* foundItemPTR;
    std::vector<Product*> cart; // Un vector de apuntadores de el objeto producto
                                // Esto con la finalidad de poder eliminarlos desde el carrito si se venden
                                // En el caso de que no se vendan simplemente se eliminaría el apuntador del carrito mas no el objeto del inventario
    bool addItemCart;

    char moneyReceived;


};


#endif //PROYECTOCOMP1_01_USER_H
