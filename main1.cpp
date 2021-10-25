//
// Created by guerrero on 10/21/21.
//
#include <iostream>
/*#include "Tienda.h"
#include "Usuario.h"
#include "Producto.h"*/
#include "Product.h"
#include "User.h"
#include "Store.h"
#include <vector>


using namespace std;


void addFirstProduct();
vector<Product> inventario;
vector<User> listaUsuarios;
User usuarioPrueba{"Default User","password", true};
User usuarioActivo = usuarioPrueba;
Product productoPrueba{908, "Agua", "na",10.00};
bool firstTime = true;
bool correctLogin = false;




void createProduct();

void createUser();

void showCeroScreen();

void login();

void showEmployeMenu();

void showAdminMenu();

int main() {
    cout << "******************** Bienvenido a Grocery 0.1 ********************"<< endl;
   // Pantalla 0. No se ha usado el programa anteriormente.
    //       Registrar usuairo nuevo.
    //   Pide pontraseña del usuario default.

   while(firstTime){
       showCeroScreen();
   }
    login();
    if (correctLogin){
        if (!usuarioActivo.isAdmin()) {
            showEmployeMenu();
        } else {
            showAdminMenu();
        }
    } else {
        login();
    }




    //Pantalla 1. Ya se ingresó y se creó un usuairo
   //   Iniciar sesión


   //Pantalla 2. Se inició sesión
   //   Pantalla 2.1 Es admin
   //       [1] Registrar Usuario
   //       [2] Editar Precios
   //       [3] Vender Productos
   //       [4] Editar usuario
   //   Pantalla 2.2 No es admin
   //       [1] Vender Productos
   //       [2] Ver inventario
   //       [3] Editar Usuario
   //           [1] Editar Nombre
   //           [2] Editar contraseña



    return 0;
}

void showAdminMenu() {
int option;
cout << "Bienvenido " << usuarioActivo.getUsrName() << ", estas son tus opciones disponibles: \n"<< endl;
    cout << "Modo Administrador.\n[1] Registrar usuario\n[2] Actualizar precios\n[3] Vender productos\n[4] Editar Usuario\n[5] Añadir productos\n Ingresa la opcion: \n";
    cin.ignore();
    cin >> option;
    switch (option) {
        case 1:
            createUser();
            break;
        case 2:
            usuarioActivo.editPrice(inventario);
            break;
        case 3:
            usuarioActivo.sellProducts(inventario);
            break;
        case 4:
            usuarioActivo.editUser();
            break;
        case 5:
            createProduct();
            break;
        default:
            cout << "Por el momento sólo están esas opciones :)" << endl;

    }
}

void showEmployeMenu() {
    int option;
    cout << "Bienvenido " << usuarioActivo.getUsrName() << ", estas son tus opciones disponibles: \n"<< endl;
    cout << "Modo Empleado.\n[1] Vender productos\n[2] Editar Usuario\n Ingresa la opcion:\n";
    cin.ignore();
    cin >> option;
    switch (option) {
        case 1:
            usuarioActivo.sellProducts(inventario);
            break;
        case 2:
            usuarioActivo.editUser();
            break;
        default:
            cout << "Por el momento sólo están esas opciones :)";
            break;
    }
}

void showCeroScreen() {

    cout << "Es la primera vez que usas Grocery, por favor crea un usuario \n";
    createUser();
    firstTime = false;
}

void login() {
    std::vector<string>::iterator it;
    vector<string> onlyNames;
    std::string nameUserSearch;
    string password;
    cout << "Ingresa el nombre del Usuario: \n" <<endl;
    cin.ignore();
    getline(cin, nameUserSearch);



    for(int i = 0; i < listaUsuarios.size(); i++){
        onlyNames.push_back(listaUsuarios[i].getUsrName());
    }
    it = std::find(onlyNames.begin(), onlyNames.end(), nameUserSearch);
    if (it != onlyNames.end())
    {
        cout << "Ingrsa la contraseña:\n" <<endl;
        cin.ignore();
        getline(cin, password);
        if(listaUsuarios[it- onlyNames.begin()].isThePasword(password)){
            usuarioActivo = listaUsuarios[it-onlyNames.begin()];
            correctLogin = true;
       }

    }
    else {
        std::cout << "Usuario no encontrado.\n\n";

    }
} //Debería estar dentro de una clase

void createProduct() {
    std::string inName;
    std::string inExpiration;
    int inId;
    float inPrice;
    cout << "Ingresa el nobre del producto: \n" <<endl;
    getline(cin, inName);
    cout << "Ingresa el id: \n" << endl;
    cin >>inId;
    cin.ignore();
    cout << "Fecha de caducidad:\n" <<endl;
    getline(cin, inExpiration);
    cout << "Precio:\n" << endl;
    cin >> inPrice ;
    Product product{inId,inName,inExpiration,inPrice};
    inventario.push_back(product);


};

void createUser(){
    std::string inNameU;
    std::string inPasswU;
    std::string inRepeatPass;
    char admin;
    cout << "Ingresa el nobre del usuario: \n" <<endl;
    getline(cin, inNameU);
    cout << "Crea una contraseña: \n" << endl;
    cin.ignore();
    getline(cin, inPasswU);
    cout << "Repite la contraseña:\n" <<endl;
    cin.ignore();
    getline(cin, inRepeatPass);

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
