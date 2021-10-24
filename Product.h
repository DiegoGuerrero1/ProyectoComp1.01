//
// Created by guerrero on 10/23/21.
//

#ifndef PROYECTOCOMP1_01_PRODUCT_H
#define PROYECTOCOMP1_01_PRODUCT_H
#include <string>
#include <iostream>

using namespace std;

class Product {
public:
    //Constructor
    explicit Product(int, std::string,std::string, float );

    //Methods
    void setId(int);
    void setExpd(std::string);
    void setpName(std::string);
    void setPrice(float);
    int getId();
    std::string getExpd();
    std::string getpName();
    float getPrice();


private:
    //Member variables
    int id;
    std::string name;
    std::string expiration;
    float price;

};


#endif //PROYECTOCOMP1_01_PRODUCT_H
