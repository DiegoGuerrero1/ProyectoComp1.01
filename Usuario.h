//
// Created by guerrero on 10/19/21.
//

#ifndef PROYECTOCOMP1_01_USUARIO_H
#define PROYECTOCOMP1_01_USUARIO_H
#include <string>

using namespace std;

class Usuario{
public:
    explicit Usuario(std::string nombreUsuario, std::string contraseña);
    //métodos get y set
    void setUName(std::string&);
    void setPassword(std::string, std::string); //Necesita dos strings, una es la contraseña anterior y la otra es la nueva

    //Métodos principales
    void editPassword();
    void editName();

private:
    std::string password;
    std::string uName;


//Creo que ya está (por ahora)
};


#endif //PROYECTOCOMP1_01_USUARIO_H
