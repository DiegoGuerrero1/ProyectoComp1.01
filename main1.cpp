//
// Created by guerrero on 10/21/21.
//
#include <iostream>
#include "Product.h"
#include "User.h"
#include "Store.h"
#include <vector>



using namespace std;


void addFirstProduct();


User adminDefault;
User* usuarioActivoPTR = &adminDefault;
vector<User> listaUsuarios;
Product productoPrueba{908, "Agua", "na",10.00};
vector<Product> inventario;
bool firstTime = true;
bool correctLogin = false;
vector<Product*> carritoAct;





void createProduct();

void createUser();

void showCeroScreen();

void login();

void showEmployeMenu();

void showAdminMenu();

//void echo(bool);

int main() {
    cout << "******************** Bienvenido a Grocery 0.1 ********************"<< endl;
   // Pantalla 0. No se ha usado el programa anteriormente.
    //       Registrar usuairo nuevo.
    //   Pide pontraseña del usuario default.
while(firstTime){
        showCeroScreen();
}
//Iniciamos sesión

    login();
    if (correctLogin){
        if (!usuarioActivoPTR->isAdmin()) {
            showEmployeMenu();
        } else {
            showAdminMenu();
        }
    } else {
       cout << "No se inició sesión correctamente" << endl;
    }


    return 0;
}

void showAdminMenu() {
int option;
char regresar='y';
    cout << "Bienvenido " << usuarioActivoPTR->getUsrName() << ", estas son tus opciones disponibles: \n" << endl;
    while (regresar == 'y'){
        cout << "Modo Administrador.\n[1] Registrar usuario\n[2] Actualizar precios\n[3] Vender productos\n[4] Editar Usuario\n[5] Añadir productos\n Ingresa la opcion: \n";
        cin >> option;


        switch (option) {
            case 1:
                createUser();
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                break;
            case 2:
                usuarioActivoPTR->editPrice(inventario);
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                break;
            case 3:
                usuarioActivoPTR->sellProducts(inventario, carritoAct);
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                break;
            case 4:
                usuarioActivoPTR->editUser();
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                break;
            case 5:
                createProduct();
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                break;
            default:
                cout << "Por el momento sólo están esas opciones :)" << endl;

        }

    }

}

void showEmployeMenu() {
    int option;
    cout << "Bienvenido " << usuarioActivoPTR->getUsrName() << ", estas son tus opciones disponibles: \n" << endl;
    cout << "Modo Empleado.\n[1] Vender productos\n[2] Editar Usuario\n Ingresa la opcion:\n";
    cin.ignore();
    cin >> option;
    switch (option) {
        case 1:
            usuarioActivoPTR->sellProducts(inventario, carritoAct);
            break;
        case 2:
            usuarioActivoPTR->editUser();
            break;
        default:
            cout << "Por el momento sólo están esas opciones :)";
            break;
    }
}

void showCeroScreen() {

    string pass;

    pass = usuarioActivoPTR->getpass("Es la primera vez que usas Grocery, por favor ingresa la constraseña del administrador default",
                                     true);

    if(adminDefault.isThePasword(pass)){
        createUser();
        cout << "Ahora crea un producto para empezar el inventario \n" << endl;
        createProduct();
        firstTime = false;

    }else{
        cout << "Contraseña incorrecta" << endl;

    }



}

void login() {
    cout << "********** Iniciar Sesión *********" <<endl;
    std::vector<string>::iterator it;
    vector<string> onlyNames;
    std::string nameUserSearch;
    string password;
    cout << "Ingresa el nombre del Usuario: \n" <<endl;
    cin.ignore();
    getline(cin, nameUserSearch);

    for(auto & listaUsuario : listaUsuarios){
        onlyNames.push_back(listaUsuario.getUsrName());
    }
    it = find(onlyNames.begin(), onlyNames.end(), nameUserSearch);
    if (it != onlyNames.end())
    {
        cout << "Ingresa la contraseña:\n" <<endl;
        usuarioActivoPTR->inputPassword(password);

        if(listaUsuarios[it- onlyNames.begin()].isThePasword(password)){
            usuarioActivoPTR = &listaUsuarios[it - onlyNames.begin()]; // Asignamos que el usuario encontrado ahora es el usuario activo
            correctLogin = true;
       }

    }
    else {
        std::cout << "Usuario no encontrado.\n";
        correctLogin = false;

    }
} //Debería estar dentro de una clase

void createProduct() {
    cout << "*********** Crear producto ***********" << endl;
    std::string inName;
    std::string inExpiration;
    int inId;
    float inPrice;
    cout << "Ingresa el nobre del producto: \n" <<endl;
    cin.ignore();
    getline(cin, inName);
    cout << "Ingresa el id: \n" << endl;
    cin >>inId;
    cout << "Fecha de caducidad:\n" <<endl;
    cin.ignore();
    getline(cin, inExpiration);
    cout << "Precio:\n" << endl;
    cin >> inPrice ;
    Product product{inId,inName,inExpiration,inPrice};
    inventario.push_back(product); //Se agrega al inventario
// NOTA: al finalizar este método dice que se eliminó el objeto, esto es verdad, pero pasamos una copia al vector de lista de usuarios.
// Por lo tanto se creó, se copió a la lista y se eliminó el original

};

void createUser(){
    cout << "******** Registrar Usuario **********" << endl;
    std::string inNameU;
    std::string inPasswU;
    std::string inRepeatPass;
    char admin;
    cout << "Ingresa el nobre del usuario: \n" <<endl;
    cin.ignore();
    getline(cin, inNameU);
    cout << "Crea una contraseña: \n" << endl;
    usuarioActivoPTR->inputPassword(inPasswU);
    cout << "Repite la contraseña:\n" <<endl;
    usuarioActivoPTR->inputPassword(inRepeatPass);

    if(inPasswU == inRepeatPass){
        User newUser{inNameU, inPasswU, false};
       cout << "¿Hacer administrador? s:si, n:no" << endl;
       cin >> admin;
       newUser.makeAdmin(admin);
       listaUsuarios.push_back(newUser);


    }else{
        cout <<"Las contraseñas no coinciden, cancelando operación";
    }





}

