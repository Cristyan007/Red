#include "red.h"


red::red()
{

}

void red::imprimir()
{
    cout<<'\t';
    for(j = nodos.begin(); j != nodos.end(); ++j){
        cout<<j->first<<'\t';
    }
    cout<<endl;
    for (j = nodos.begin(); j != nodos.end(); ++j) {
        j->second.imprimirMapa();
        cout<<endl;
    }
}

bool red::NodeExist(char nombre)
{
    return nodos.find(nombre)!=nodos.end();
}

void red::eliminardato(char dato)
{
    if(NodeExist(dato)){
       nodos.erase(dato);
    }
}

void red::inserdato(char nombre, enrutador valor)
{
    if(!NodeExist(nombre)){
       nodos.insert(pair<char,enrutador>(nombre,valor));
    }
}

void red::agregarNodo(char nombre)
{
    if(!NodeExist(nombre)){
        enrutador objeto;
        objeto.assing_name(nombre);

        for (j = nodos.begin(); j != nodos.end(); ++j) {
            objeto.asigConex(j->first,-1);
            j->second.asigConex(nombre,-1);
        }
        inserdato(nombre,objeto);

    }
}

void red::eliminarNodo(char nombre)
{
    if(NodeExist(nombre)){
        for (j = nodos.begin(); j != nodos.end(); ++j) {
            j->second.eliminarConex(nombre);
        }
        eliminardato(nombre);
    }
}

void red::modificarCosto(char nombre, char nombre2, int valor)
{
    if (NodeExist(nombre) && NodeExist(nombre2)) {
        nodos[nombre].modificarEnrutador(nombre2, valor);
        nodos[nombre2].modificarEnrutador(nombre, valor);
    }
}

