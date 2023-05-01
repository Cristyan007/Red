#include "enrutador.h"


enrutador::enrutador()
{

}
bool enrutador::ConexExist(string nombre)
{
    return conexiones.find(nombre)!=conexiones.end();
}

void enrutador::assing_name(string name)
{
    this->name = name;
    conexiones.insert(pair<string,int>(name,0));
}

void enrutador::asigConex(string enrutador, int valor)
{
    if(!ConexExist(enrutador)){
    conexiones.insert(pair<string,int>(enrutador,valor));
    }
}

void enrutador::eliminarConex(string enrutador)
{
    if(ConexExist(enrutador)){
    conexiones.erase(enrutador);
    }
}

void enrutador::modificarEnrutador(string enrutador, int valor)
{
    if(ConexExist(enrutador)){
    conexiones[enrutador] = valor;
    }
}

void enrutador::imprimirMapa()
{
    cout<<name<<"\t";
    for (l= conexiones.begin(); l != conexiones.end(); ++l){
        cout<<l->second<<"\t";
    }
}


