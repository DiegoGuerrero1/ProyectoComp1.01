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
    User();
    ~User();


    //Methods
    void makeAdmin(char);
    void setAdmin(bool);
    bool isThePasword(string &testPassword);
        //setters and getters
    std::string getUsrName();
    void setuName(std::string);
    void setPassword(std::string);
    int getch();
    string getpass(const char*, bool );



        //Miscelaneus

    void addtoCart(vector<Product> &inventario,vector<Product*> &cart);
    bool isAdmin();

    static Product & findProductbyId(vector<Product> &inventario);
    void sellProducts(vector<Product> &inventario, vector<Product*> &cart); //Regresará el total
    void vaciarCarrito(vector<Product*> &cart);
    void editPrice(vector<Product> &inventario);

    void editUser();

    void addProducts(Product, vector<Product>);

private:
    std::string name;
    std::string password;
    bool admin;

};


#endif //PROYECTOCOMP1_01_USER_H
