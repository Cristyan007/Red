#ifndef RED_H
#define RED_H

#include <iostream>
#include<vector>
#include<map>
#include "enrutador.h"
using namespace std;

class red
{
public:
    red();
    void imprimir();
    void agregarNodo(char nombre);
    void eliminarNodo(char nombre);
    void modificarCosto(char nombre, char nombre2, int valor);
    bool NodeExist(char nombre);

private:
    void eliminardato(char dato);
    void inserdato(char nombre, enrutador valor);
    map<char,enrutador> nodos;
    map<char,enrutador>::iterator j;
};










#endif // RED_H
