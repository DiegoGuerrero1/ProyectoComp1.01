//
// Created by guerrero on 10/23/21.
//

#include "User.h"
#include <string>

User::User(string userName, string userPassword, bool makeAdmin)
:name{userName}, password{userPassword}, admin{makeAdmin} {
    cout << "Usuario creado." <<"\nNombre: " <<userName << "\nAdministrador: "<< admin << endl;

}

void User::makeAdmin(char madmin) {
    switch (madmin) {
        case 's':
            setAdmin(true);
            cout << "El usuario " << getUsrName() <<" ahora es administrador" <<endl;
            break;
        case 'n':
            setAdmin(false);
            cout << "El usuario " << getUsrName() <<" es empleado" <<endl;
            break;
        case 'c':
            break;
        default:
            cout << "Opción no válida, asignando empleado " << endl;
            setAdmin(false);
            break;

    }

}

void User::setAdmin(bool sAdmin) {
    admin = sAdmin;

}

bool User::isThePasword(string testPassword) {
    if(testPassword==password){
        return true;
    }else{
        return false;
    }

}

std::string User::getUsrName() {
    return name;
}

void User::setuName(string userName) {
    name = userName;
}

void User::setPassword(string nPassword) {
    password = nPassword;
}

void User::editPassword() {
    std::string oldPassword;
    std::string newPassword;
    cout << "Ingresa la contraseña anterior" << endl;
    getline(cin, oldPassword);

    if(isThePasword(oldPassword)){
        cin.ignore();
        cout << "Ingresa la nueva contraseña" << endl;
        getline(cin, newPassword);
        setPassword(newPassword);
        cout <<"contraseña cambiada"<<endl;
    }else {
        cout << "Contraseña incorrecta" << endl;
    }
}

void User::editName() {
    std::string oldPassword;
    std::string newName;
    cout << "Ingresa la contraseña de la cuenta" << endl;
    getline(cin, oldPassword);
    if(isThePasword(oldPassword)){
        cin.ignore();
        cout << "Ingresa el nuevo nombre" << endl;
        getline(cin, newName);
        setuName(newName);
        cout <<"Nombre cambiado"<<endl;
    }else {
        cout << "Contraseña incorrecta" << endl;
    }
}

void User::setSold(char s) {
    if(s == 's'){
        moneyReceived = true;
    }else{
        moneyReceived = false;
    }
}

void User::llenarCarrito(vector<Product> inventario, int id) {
    findProductbyId(id, inventario);
    cart = foundProducts;

}

bool User::isAdmin() {
    if(!admin){
        return false;
    }else{
        return true;
    };
}

void User::findProductbyName( vector<Product> inventario) {
    std::string nombre;
    cout << "Ingresa el nombre del producto" << endl;
    getline(cin, nombre);
    for(unsigned long i{0} ; i >= inventario.size(); i++){

        if ( inventario[i].getpName() == nombre){
            i = inventario.size();
            setFoundProduct(inventario[i]) ;         //Estaría bueno implementar una búsqueda más optimizada

        }else{
            clearFoundProduct();
            cout << "No se encontró ningún producto."<<endl;

        }

    }
}

void User::findProductbyId(int id, vector<Product> inventarioAc) {
    for (unsigned long i{0}; i >= inventarioAc.size(); i++) {

        if (inventarioAc[i].getId() == id) {
            setFoundProduct(inventarioAc[i]);
            //Estaría bueno implementar una búsqueda más optimizada
            i = inventarioAc.size();


        } else {
            clearFoundProduct();
            cout << "No se encontró ningún producto."<<endl;

        }
    }
}

float User::sellProducts(vector<Product>, int) {
    return 0;
}

void User::vaciarCarrito() {
  cart.clear();
}

void User::editPrice(vector<Product> inventario) {
    int idProducto;
    float nuevoPrecio;
    if (!isAdmin()){
        cout << "El usuario no es administrador"<< endl;
    }else{
        cout << "Por el momento sólo se puede reemplazar buscando por id \n Ingrese id: \n" << endl;
        cin >> idProducto;
        for (unsigned long i{0}; i >= inventario.size(); i++) {

            if (inventario[i].getId() == idProducto) {
                inventario[i].setPrice(nuevoPrecio);
                //Estaría bueno implementar una búsqueda más optimizada
                i = inventario.size();

            } else {
                clearFoundProduct();
                cout << "No se encontró ningún producto."<<endl;

            }
        }
    }
}

void User::setFoundProduct(Product producto) {
    foundProducts[0] = producto;
}

void User::clearFoundProduct() {
    foundProducts.clear();

}

void User::removeProduct(int prodId, vector<Product> inventario) {

    }

}
