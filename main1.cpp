//
// Created by guerrero on 10/21/21.
//
#include <iostream>
#include "Product.h"
#include "User.h"
#include "Store.h"
#include <vector>
#include <ostream>
#include <fstream>
#include <algorithm>


using namespace std;


void addFirstProduct();

// Variables globales
User adminDefault; // De aquí viene la contrasela defauilt.
User* usuarioActivoPTR = &adminDefault; // Es el apuntador que nos dice qué usuario es el activo.
vector<User> listaUsuarios; //La lista de todos los usuarios. Se pasa por valor ya que queremos copias.
vector<Product> inventario; // Un vector con productos es el inventario.
bool firstTime = true; // sirve para saber si mostrar la pantalla cero (no se ha creado usuairos).
bool correctLogin = false; // Se usa para validar el correcto incio de sesión.
vector<Product*> carritoAct; // El carrito es un vector de apuntadores. Apunta que productos queremos comprar.
bool log = true; // Variable para activar un nuevo inicio de sesión.
char regresar= 'y'; // Variable para indicar un retorno al menú principal.



// Declaraciones de Métodos del main();

void createProduct();
void createUser();
void showCeroScreen();
void login();
void showEmployeMenu();
void showAdminMenu();
void writeCsv(vector<Product> &upload);



// Main
int main() {
    cout << "******************** Bienvenido a Grocery 0.1 ********************"<< endl; //Bienvenida
while(firstTime){ // Pantalla 0. No se ha usado el programa anteriormente.
        showCeroScreen();
}

// Se inicia sesión

while (log){ //Mientras la variable de incio de sesión sea verdadera, se activará el inicio de sesión.
    login(); //Llamamos al método login().
    if (correctLogin){ // Si se inició correctamente entonces procede a mostrar los menús.
        if (!usuarioActivoPTR->isAdmin()) { // Validamos quie el usuario activo sea administrador
            showEmployeMenu(); // Es administrador, menú completo.
        } else {
            showAdminMenu(); // No es administrador, menú limitado.
        }
    } else {
        cout << "No se inició sesión correctamente" << endl;
    }

}


// Creamos el csv con todas las modificaciones. Este csv emula una base de datos.
    writeCsv(inventario);
// Aquí termina el programa.
    return 0;
}


// ************* IMPLEMENTACIÓN DE LAS FUNCIONES DEL MAIN ***********************************************************************************



void writeCsv(vector<Product> &upload) {
    ofstream inventory;
    inventory.open("inventory.csv");
    inventory << "id"<<","<<"Nombre"<<","<<"Caducidad"<<","<<"Precio"<<endl;
    for(int i = 0; i <= upload.size() ; i++){ //Escirbimos el csv.
        inventory << upload[i].getId() <<","<< upload[i].getpName()<<","<<upload[i].getExpd() <<","<<upload[i].getPrice()<<endl;

    }
    cout << "csv creado"<<endl;

} // Función para generar un csv para posteriormente procesarlo con python.


void showAdminMenu() { // función para mostrar el menú de administrador
int option; //Variable para el switch

    while(regresar == 'y'){
        cout << "Bienvenido " << usuarioActivoPTR->getUsrName() << ", estas son tus opciones disponibles: \n" << endl;
        cout << "Modo Administrador.\n[1] Registrar usuario\n[2] Actualizar precios\n[3] "
                "Vender productos\n[4] Editar Usuario\n[5] Añadir productos\n"
                "[6] Iniciar otra sesión \n[7] Salir\n" << "Ingresa la opcion: \n" <<endl;
        cin >> option;
        regresar = 'n'; // Variable para generar un loop en cada opción y poder reutilizarla
        switch (option) {
            case 1: // Registrar usuario
                while (regresar == 'n') {
                    createUser();
                    cout << "¿Regresar al menú?[y/n]:" << endl;
                    cin >> regresar;
                }
                break;
            case 2:
                while (regresar == 'n') {
                    usuarioActivoPTR->editPrice(inventario); //Llamamos la función de editrar usuario
                    cout << "¿Regresar al menú?[y/n]:" << endl;
                    cin >> regresar;
                }
                writeCsv(inventario); //Guardamos cambios

                break;
            case 3:
                while (regresar == 'n') {
                usuarioActivoPTR->sellProducts(inventario, carritoAct); //Llamamos la función vender productos
                cout << "¿Regresar al menú?[y/n]:" << endl;
                cin >> regresar;
                }
                writeCsv(inventario);
                break;
            case 4:
                while(regresar == 'n'){
                    usuarioActivoPTR->editUser(); // Llamada a la función para editar usuario actual
                    cout << "¿Regresar al menú?[y/n]:" << endl;
                    cin >> regresar;
                }
                writeCsv(inventario);

                break;
            case 5:
                while(regresar == 'n'){
                    createProduct(); //Fucnión para crear un producto
                    cout << "¿Regresar al menú?[y/n]:" << endl;
                    cin >> regresar;
                }
                writeCsv(inventario);
                break;
            case 6:
                log = true; // Asignamos el valor de verdadero, para que cuando se salga del siwtch repita la función de login()
                break;

            case 7:
                regresar = 'n'; // Para poder salir del ciclo while y continuar en el main.
                break;

            default:
                cout << "Por el momento sólo están esas opciones :)" << endl;
                regresar = 'y'; // Regresar al menú
                break;

        }

    }

}

void showEmployeMenu() { // Mostrar el menú inclopeto
    int option;
    regresar = 'y';

    while (regresar == 'y'){
        cout << "Bienvenido " << usuarioActivoPTR->getUsrName() << ", estas son tus opciones disponibles: \n" << endl;
        cout << "Modo Empleado.\n[1] Vender productos\n[2] Editar Usuario\n Ingresa la opcion:\n";
        cin.ignore();
        cin >> option;
        switch (option) {
            case 1:
                while (regresar == 'y'){
                    usuarioActivoPTR->sellProducts(inventario, carritoAct);
                    cout << "¿Regresar al menú?[y/n]"<<endl;
                    cin >> regresar;
                }

                break;
            case 2:
                while(regresar == 'y'){
                    usuarioActivoPTR->editUser();
                    cout << "¿Regresar al menú?[y/n]"<<endl;
                    cin >> regresar;
                }
                break;

            default:
                cout << "Por el momento sólo están esas opciones :)"<<endl;
                regresar = 'y';
                break;
            }

         }
    }

void showCeroScreen() {

    string pass; //Contraseña a probar

    pass = usuarioActivoPTR->getpass("Es la primera vez que usas Grocery, por favor ingresa la constraseña del administrador default",
                                     true); // Usamos funcion getpass para que no se vea la contraseña

    if(adminDefault.isThePasword(pass)){
        createUser(); //Se crea un usuairo para empezar la lista de usuarios y no usar la del administrador default
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
    cout << "Ingresa el nombre del Usuario:\n" <<endl;
    cin.ignore();
    getline(cin, nameUserSearch);


    for(auto & listaUsuario : listaUsuarios){  //Se realiza una búsqueda en la lista de usuarios
        onlyNames.push_back(listaUsuario.getUsrName()); // Creamos un nuevo vector que contenga sólo nombres
                                                        // Es mpas sencillo buscarlo si es un vector con sólo strings
    }
    it = find(onlyNames.begin(), onlyNames.end(), nameUserSearch);
    if (it != onlyNames.end())
    {
        password = usuarioActivoPTR->getpass("Ingresa la contraseña:",true); // Pedimos que ingrese la constraseña con getpass.

        if(listaUsuarios[it- onlyNames.begin()].isThePasword(password)){ // Se valida la constraseña
            usuarioActivoPTR = &listaUsuarios[it - onlyNames.begin()]; // Asignamos que el usuario encontrado ahora es el usuario activo
            correctLogin = true;
       }else{
            cout << "Contraseña incorrecta" << endl;
        }

    }
    else {
        std::cout << "Usuario no encontrado.\n";
        correctLogin = false;

    }
    log = false; //Para que no vuelva a inciar sesión a menos que el usuario lo indique
}

void createProduct() {
    cout << "*********** Crear producto ***********" << endl;
    std::string inName;
    std::string inExpiration;
    int inId;
    float inPrice;
    cout << "Ingresa el nombre del producto: \n" <<endl;
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
// NOTA: al finalizar este método dice que se eliminó el objeto. Pero pasamos una copia al vector de lista de usuarios.
// Por lo tanto se creó, se copió a la lista y se eliminó el original.

};

void createUser() {
    cout << "******** Registrar Usuario **********" << endl;
    std::string inNameU;
    std::string inPasswU;
    std::string inRepeatPass;
    char admin;
    cout << "Ingresa el nombre del usuario: \n" << endl;

    if(!firstTime) cin.ignore(); // Es un parche: En la pantalla cero, si se coloca el cin.ignore omite la primero letra.
                                // Pero fuera de esta pantalla lo necesita para omitir el salto de línea.

    getline(cin, inNameU);

    inPasswU = usuarioActivoPTR->getpass("Crea una contraseña:", true);
    inRepeatPass = usuarioActivoPTR->getpass("Repite la contraseña", true);


    if (inPasswU == inRepeatPass) {
        User* nuserPTR = new User{inNameU, inPasswU, false};
        //User newUser{inNameU, inPasswU, false};
        cout << "¿Hacer administrador? s:si, n:no" << endl;
        cin >> admin;
        nuserPTR->makeAdmin(admin);
        listaUsuarios.push_back(*nuserPTR);


    } else {
        cout << "Las contraseñas no coinciden, cancelando operación";
    }
}





