#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class enrutador
{
public:
    enrutador();
    void assing_name(string nombre);
    void asigConex(string enrutador, int valor);
    void eliminarConex(string enrutador);
    void modificarEnrutador(string enrutador, int valor);
    void imprimirMapa();
    bool ConexExist(string nombre);
    void find_conexiones(map<string,enrutador>& nodos);
    map<string,int> conexiones;
private:
    string name;
    map<string,int>::iterator l;
};


#endif // ENRUTADOR_H
