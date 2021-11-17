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
#include <termios.h>
#include <unistd.h>

using namespace std;


void addFirstProduct();

vector<User> listaUsuarios;
User adminDefault{"Default User", "compu", true};
User usuarioActivo = adminDefault;
Product productoPrueba{908, "Agua", "na",10.00};
vector<Product> inventario;
bool firstTime = true;
bool correctLogin = false;




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

usuarioActivo.sellProducts(inventario);

    return 0;
}

void showAdminMenu() {
int option;
cout << "Bienvenido " << usuarioActivo.getUsrName() << ", estas son tus opciones disponibles: \n"<< endl;
    cout << "Modo Administrador.\n[1] Registrar usuario\n[2] Actualizar precios\n[3] Vender productos\n[4] Editar Usuario\n[5] Añadir productos\n Ingresa la opcion: \n";
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

    string pass;
    cout << "Es la primera vez que usas Grocery, por favor crea un usuario \n";
    createUser();
    cout << "También crea un producto para empezar el inventario \n" << endl;
    createProduct();
    firstTime = false;

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

    for(int i = 0; i < listaUsuarios.size(); i++){
        onlyNames.push_back(listaUsuarios[i].getUsrName());
    }
    it = std::find(onlyNames.begin(), onlyNames.end(), nameUserSearch);
    if (it != onlyNames.end())
    {
        cout << "Ingrsa la contraseña:\n" <<endl;
        usuarioActivo.inputPassword(password);

        if(listaUsuarios[it- onlyNames.begin()].isThePasword(password)){
            usuarioActivo = listaUsuarios[it-onlyNames.begin()]; // Asignamos que el usuario encontrado ahora es el usuario activo
            correctLogin = true;
       }

    }
    else {
        std::cout << "Usuario no encontrado.\n";

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


};

void createUser(){
    cout << "******** Registrar Usuario **********" << endl;
    std::string inNameU;
    std::string inPasswU;
    std::string inRepeatPass;
    char admin;
    cout << "Ingresa el nobre del usuario: \n" <<endl;
    getline(cin, inNameU);
    cout << "Crea una contraseña: \n" << endl;
    usuarioActivo.inputPassword(inPasswU);
    cout << "Repite la contraseña:\n" <<endl;
    usuarioActivo.inputPassword(inRepeatPass);

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

/*void echo( bool on = true )
{
    struct termios settings;
    tcgetattr( STDIN_FILENO, &settings );
    settings.c_lflag = on
                       ? (settings.c_lflag |   ECHO )
                       : (settings.c_lflag & ~(ECHO));
    tcsetattr( STDIN_FILENO, TCSANOW, &settings );
}*/