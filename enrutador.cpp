#include "enrutador.h"


enrutador::enrutador()
{

}

void enrutador::assing_name(char name)
{
    this->name = name;
    conexiones.insert(pair<char,int>(name,0));
}

void enrutador::asigConex(char enrutador, int valor)
{
    conexiones.insert(pair<char,int>(enrutador,valor));
}

void enrutador::eliminarConex(char enrutador)
{
    conexiones.erase(enrutador);
}

void enrutador::modificarEnrutador(char enrutador, int valor)
{
    conexiones[enrutador] = valor;
}

void enrutador::imprimirMapa()
{

    cout<<name<<"\t";
    for (l= conexiones.begin(); l != conexiones.end(); ++l){
        cout<<l->second<<"\t";
    }
}

