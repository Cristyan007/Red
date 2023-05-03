#include "funciones.h"

void imprimirmenu()
{
    cout<<"--------- MENU ---------"<<'\t'<<endl<<endl;
    cout<<"1)"<<' '<<"Leer archivo de redes."<<'\t'<<endl;
    cout<<"2)"<<' '<<"Crear un nuevo nodo."<<'\t'<<endl;
    cout<<"3)"<<' '<<"Asignar costo entre dos nodos."<<'\t'<<endl;
    cout<<"4)"<<' '<<"modificar costo entre dos nodos."<<'\t'<<endl;
    cout<<"5)"<<' '<<"Eliminar un nodo."<<'\t'<<endl;
    cout<<"6)"<<' '<<"Calcular la mejor ruta"<<'\t'<<endl;
    cout<<"7)"<<' '<<"salir."<<'\t'<<endl<<endl;
}

int opcionmenu()
{
    int num;
        bool valido = false;
        while (!valido) {
            cout << "Ingrese un numero (1-7): ";
            cin >> num;
            if (num >= 1 && num <= 7) {
                valido = true;
            }
        }
        return num;
}

bool acciones(red *nueva)
{
    int opcion = opcionmenu();

    if (opcion == 1){
        string archivo;
        cout<<"Ingrese el nombre del archivo o la ruta completa: "<<endl;
        cin>>archivo;
        nueva->archivo(archivo);
        nueva->imprimir();
        return true;

    }
    if (opcion == 2){
        string Newnodo;
        cout<<"Ingrese el nombre del nodo nuevo: "<<endl;
        cin>>Newnodo;
        nueva->agregarNodo(Newnodo);
        nueva->imprimir();
        return true;
    }
    if (opcion >= 3 && opcion <= 4){
        string nodo1,nodo2;
        int costo;
        cout<<"Ingrese el nombre del primer nodo: "<<endl;
        cin>>nodo1;
        cout<<"Ingrese el nombre del segundo nodo: "<<endl;
        cin>>nodo2;
        cout<<"Ingrese el costo entre ellos: "<<endl;
        cin>>costo;
        nueva->modificarCosto(nodo1,nodo2,costo);
        nueva->imprimir();
        return true;
    }
    if (opcion == 5){
        string nodo;
        cout<<"Ingrese el nombre del nodo a eliminar: "<<endl;
        cin>>nodo;
        nueva->eliminarNodo(nodo);
        nueva->imprimir();
        return true;
    }
    if (opcion == 6){
        string inicio;
        string fin;
        cout<<"Ingrese el nodo de partida"<<endl;
        cin>>inicio;
        cout<<"Ingrese el nodo al que desea llegar"<<endl;
        cin>>fin;
        nueva->bellmanFord(inicio,fin);
        return true;
    }
    if (opcion == 7){
        cout<<'\t'<<"--------- HASTA LA PROXIMA ---------"<<'\t'<<endl<<endl<<endl;
        return false;
    }
}

