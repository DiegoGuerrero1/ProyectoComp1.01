//
// Created by guerrero on 10/23/21.
//

#include "User.h"
#include <string>
#include <termios.h>
#include <cstdio>
#include <unistd.h>
#include <iostream>


User::User(string userName, string userPassword, bool makeAdmin)
:name{userName}, password{userPassword}, admin{makeAdmin} {
    cout << "Usuario creado." <<"\nNombre: " <<userName << "\nAdministrador: "<< admin << endl;

}
User::User(): name{"Administrador Default"}, password{"compu"}, admin{true}{
    cout << "Usuario " <<getUsrName() << "\nAdministrador: "<< admin << endl;
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
        default:
            cout << "Opción no válida, asignando empleado " << endl;
            setAdmin(false);
            break;

    }

}

void User::setAdmin(bool sAdmin) {
    admin = sAdmin;

}

bool User::isThePasword(string &testPassword) {
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

void User::addtoCart(vector<Product> &inventario, vector<Product*> &cart ) {
        cart.push_back(&findProductbyId(inventario)); //Agregamos por referencia los productos por medio de un pushback

}

bool User::isAdmin() {
    if(!admin){
        return false;
    }else{
        return true;
    };
}

Product & User::findProductbyId(vector<Product> &inventario) { // No se si se podría crear una plantilla aquí, supongo que si.
    int idSearch;
    std::vector<int>::iterator it;
    vector<int> searchId;
    unsigned int productoFoundIndex;

    cout << "Ingresar id del producto\n" << endl;
    cin >> idSearch;
    cout << "Inventario original :\n";
    // for loop de rango i -> inventarioAc (inventario actual)
    for (auto &i: inventario) {
        cout << " " << i.getpName();
        //generando un vector de enteros para poder buscar en el con los puros id
        searchId.push_back(i.getId());
    }
    cout << "\n";
    // Element to be searched
    // El iterador es un apuntador
    it = find(searchId.begin(), searchId.end(), idSearch);

    if (it != searchId.end()) {
        productoFoundIndex = it - searchId.begin();
        cout << "Producto " << inventario[productoFoundIndex].getpName() << " con id " << idSearch << " encontrado en la posición: " << endl;
        cout << productoFoundIndex << " (countando desde cero) \n" << endl;
        return inventario[productoFoundIndex];

    } else {
        std::cout << "Producto no encontrado.\n\n";
        return inventario[productoFoundIndex];

    }

}



void User::vaciarCarrito(vector<Product*> &cart) {
    cart.clear();
}

void User::sellProducts(vector<Product> &inventario, vector<Product*> &cart) {
        char agregarMas;
        char carritoVendido;
        float sellBill = 0;

    do {
        addtoCart(inventario, cart) ;
        cout << "¿Agregar más productos al carrito?[y/n]" << endl;  //Agrega al carrito mientras el usuario quiera agragar más
        cin >> agregarMas;

    } while (agregarMas == 'y');

        for(auto & cart : cart){
            sellBill += cart->getPrice();

        }
        /*for( int i = 0 ; i <= cart.size(); i++){ //Para sacar la cuenta se usa un ciclo for que va sacando y sumando los precios de los productos del carrito
             sellBill += cart[i]->getPrice(); //Usamos la flecha ya que es un apuntador
             cout << i << endl;
             cout << sellBill << endl;

        }*/
    cout << "Cuenta final: " << sellBill <<"$"<<endl;

    cout << "¿Pago recibido? [y/n]:" << endl;
    cin >> carritoVendido;
    if (carritoVendido == 'y'){
        for (unsigned int i = 0; i <= cart.size(); i++) {
            delete cart[i]; // Como se vendieron los productos, se eliminan del inventario original por medio de su apuntador

        }
    }else{
        cout << "Operación cancelada" << endl;
        vaciarCarrito(cart);
    }
}


void User::editPrice(vector<Product> &inventario) {
    int idProducto;
    char mientras;
    float nuevoPrecio = 0;
    Product* sellItemPTR; // Importante: tiene que ser un apuntador. Si no lo es, no se puede realizar esta operación.
// No se puede devolver por valor ni por copia. Traté de crear otros vectores, sin embargo, tengo sospechas de que esop es la raíz de los bugs.
    if (!isAdmin()){
        cout << "El usuario no es administrador"<< endl;
    }else{
        do {
            sellItemPTR = &findProductbyId(inventario);
            cout << "Precio actual del producto: " << sellItemPTR->getPrice() << endl;
            cout << "Ingrese el nuevo precio: \n";
            cin >> nuevoPrecio;
            sellItemPTR->setPrice(nuevoPrecio);
            cout << "Precio de " << sellItemPTR->getpName() << " cambiado a: "<< sellItemPTR->getPrice() << endl;
            cout << "¿Continuar cambiando precios?[y/n]" << endl;
            cin >> mientras;
    } while (mientras=='y');
    }
}

void User::editUser() {
    int option;
    std::string newName;
    std::string newPassword;
    std::string oldPassword;
    char repetir='y';
    cout << "*********** Editar Usuario *********** \n";
    while (repetir == 'y') {
        cin.ignore();
        oldPassword = getpass("Ingresa tu contraseña:", true);
        if (isThePasword(oldPassword)) {
            cout << "¿Qué quieres cambiar? \n [1] Contraseña [2] Nombre de Usuario" << endl;
            cin >> option;
            switch (option) {
                case 1:
                    cout << "Ingresa la nueva contraseña\n" << endl;
                    cin.ignore();
                    getline(cin, newPassword);
                    password = newPassword;
                    cout << "Contraseña cambiada exitosamente\n" << "¿Realizar más cambios? [y/n]:" << endl;
                    cin >> repetir;
                    break;
                case 2:
                    cout << "Ingresa el nuevo nombre\n" << endl;
                    cin.ignore();
                    getline(cin, newName);
                    name = newName;
                    cout << "Nombre cambiado exitosamente a " << name << ". ¿Realizar más cambios? [y/n]:" << endl;
                    cin >> repetir;
                    break;
                default:
                    cout << "Opción no válida\n" << endl;
                    cout <<"¿Realizar más cambios? [y/n]:" << endl;
                    cin >> repetir;
                    break;
            }

        } else {
            cout << "Contraseña incorrecta" << endl;
        }
    }
}

void User::addProducts(Product newProduct, vector<Product> inventory) {
    inventory.push_back(newProduct);
}
//La única opción que encontré para tomar una contraseña de input y que no se renderizara en la terminal fue desactivar echo desde el programa

void User::echo(bool on = true) {
    struct termios settings;
    tcgetattr( STDIN_FILENO, &settings );
    settings.c_lflag = on
                       ? (settings.c_lflag |   ECHO )
                       : (settings.c_lflag & ~(ECHO));
    tcsetattr( STDIN_FILENO, TCSANOW, &settings );
}

void User::inputPassword(string &pwrd ) {
    //echo(false);
    cin.ignore();
    getline(cin, pwrd);
    //echo(true);

}

User::~User() {
cout << "Usuario " << getUsrName() << " eliminado" << endl;

}

// Tratando de hacer la contraseña invisible
int User:: getch() { //Creamos una función getch para usarla posteriormente.
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}





string User::getpass(const char *prompt, bool show_asterisk=true)
{
    const char BACKSPACE=127;
    const char RETURN=10;

    string password;
    unsigned char ch=0;

    cout <<prompt<<endl;

    while((ch=getch())!=RETURN)
    {
        if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                    cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
        else
        {
            password+=ch;
            if(show_asterisk)
                cout <<'*';
        }
    }
    cout <<endl;
    return password;
}