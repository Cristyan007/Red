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
    cout<<endl;
}

bool red::NodeExist(string nombre)
{
    return nodos.find(nombre)!=nodos.end();
}

vector<string> red::nodosArchivo(vector<string> v1, vector<string>  v2)
{
    vector<string> v3;
    for (unsigned int i = 0; i < v1.size(); ++i){
        auto it = std::find(v3.begin(), v3.end(),v1[i]);
            if(!(it != v3.end())){
              v3.push_back(v1[i]);
            }
    }
    for (unsigned int i = 0; i < v2.size(); ++i){
        auto it = std::find(v3.begin(), v3.end(),v2[i]);
            if(!(it != v3.end())){
            v3.push_back(v2[i]);
            }
    }
    return v3;
}

void red::archivo(string archivo)
{
    database informacion1,informacion,informacion2;
    informacion1.assign_name(archivo);
    informacion.assign_name(archivo);
    informacion2.assign_name(archivo);
    if(informacion.vacioOrfull()){
        vector<string> columna1 = informacion1.get_col_database(0,' ');
        vector<string> columna2 = informacion.get_col_database(1,' ');
        vector<string> columna3 = informacion2.get_col_database(2,' ');
        vector<string> nodosarchivos = nodosArchivo(columna1,columna2);
        for (unsigned int i = 0; i < nodosarchivos.size(); ++i) {
            agregarNodo(nodosarchivos[i]);
        }
        for (unsigned int i = 0; i < columna1.size(); ++i) {
            modificarCosto(columna1[i],columna2[i],std::stoi(columna3[i]));
        }
    }

}

void red::eliminardato(string dato)
{
    if(NodeExist(dato)){
       nodos.erase(dato);
    }
}

void red::inserdato(string nombre, enrutador valor)
{
    if(!NodeExist(nombre)){
       nodos.insert(pair<string,enrutador>(nombre,valor));
    }
}

void red::agregarNodo(string nombre)
{
    if(!NodeExist(nombre)){
        enrutador objeto;
        objeto.assing_name(nombre);

        for (j = nodos.begin(); j != nodos.end(); ++j) {
            objeto.asigConex(j->first,-1);
            j->second.asigConex(nombre,-1);
        }
        inserdato(nombre,objeto);
        cout<<'\t'<<"--- NODO "<<nombre<<" CREADO ---"<<'\t'<<endl;
    }
}

void red::eliminarNodo(string nombre)
{
    if(NodeExist(nombre)){
        for (j = nodos.begin(); j != nodos.end(); ++j) {
            j->second.eliminarConex(nombre);
        }
        eliminardato(nombre);
        cout<<'\t'<<"--- NODO "<<nombre<<" ELIMINADO ---"<<'\t'<<endl;
    }
}

void red::modificarCosto(string nombre, string nombre2, int valor)
{
    if (NodeExist(nombre) && NodeExist(nombre2)) {
        nodos[nombre].modificarEnrutador(nombre2, valor);
        nodos[nombre2].modificarEnrutador(nombre, valor);
        cout<<'\t'<<"--- COSTO ENTRE "<<nombre<<" Y "<<nombre2<<" MODIFICADO ---"<<'\t'<<endl;
    }
}

void red::bellmanFord(string origen, string destino) {
    map<string, int> distancias;
    map<string, string> anteriores;
    int num_nodos = nodos.size();

    // Inicializar distancias a infinito y el nodo anterior a vacío
    for (auto& i : nodos) {
        if (i.first == origen) {
            distancias[i.first] = 0;
        } else {
            distancias[i.first] = INT_MAX;
        }
        anteriores[i.first] = "";
    }

    // Realizar n-1 iteraciones para encontrar la ruta mínima
    for (int i = 1; i < num_nodos; i++) {
        for (auto& nodo : nodos) {
            string nodo_actual = nodo.first;
            for (auto& c : nodo.second.conexiones) {
                if (c.second == -1) {
                    continue; // ignorar nodos desconectados
                }
                int distancia = distancias[nodo_actual] + c.second;
                if (distancia < distancias[c.first]) {
                    distancias[c.first] = distancia;
                    anteriores[c.first] = nodo_actual;
                }
            }
        }
    }

    // Verificar si hay ciclos de pesos negativos
    for (auto& nodo : nodos) {
        string nodo_actual = nodo.first;
        for (auto& c : nodo.second.conexiones) {
            if (c.second == -1) {
                continue; // ignorar nodos desconectados
            }
            int distancia = distancias[nodo_actual] + c.second;
            if (distancia < distancias[c.first]) {
                cout << "El grafo contiene un ciclo de pesos negativos." << endl;
                return;
            }
        }
    }

    // Recuperar la ruta más corta desde el origen hasta el destino
    stack<string> ruta;
    string nodo = destino;

    while (nodo != origen) {
        ruta.push(nodo);
        nodo = anteriores[nodo];
    }

    ruta.push(origen);

    cout << "Ruta mas corta desde " << origen << " hasta " << destino << " es:" << endl;
    while (!ruta.empty()) {
        cout << ruta.top();
        ruta.pop();
        if (!ruta.empty()) {
            cout << " -> ";
        }
    }

    cout << endl << "La distancia total es: " << distancias[destino] << endl;
}



