#ifndef RED_H
#define RED_H
#include <iostream>
#include<vector>
#include<map>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include "enrutador.h"
#include "database.h"
using namespace std;

class red
{
public:
    red();
    void imprimir();
    void agregarNodo(string nombre);
    void eliminarNodo(string nombre);
    void modificarCosto(string nombre, string nombre2, int valor);
    bool NodeExist(string nombre);
    vector<string> nodosArchivo(vector<string> v1, vector<string> v2);
    void archivo(string archivo);
    void bellmanFord(string origen, string destino);
private:
    void eliminardato(string dato);
    void inserdato(string nombre, enrutador valor);
    map<string,enrutador> nodos;
    map<string,enrutador>::iterator j;
};










#endif // RED_H
