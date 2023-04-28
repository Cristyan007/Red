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
    void assing_name(char nombre);
    void find_connecciones();
    void asigConex(char enrutador, int valor);
    void eliminarConex(char enrutador);
    void modificarEnrutador(char enrutador, int valor);
    void imprimirMapa();
private:
    char name;
    map<char,int> conexiones;
    map<char,int>::iterator l;
};

























#endif // ENRUTADOR_H
