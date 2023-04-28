#include "database.h"
#include "red.h"
int main()
{
 //database db;
 //string text;
 //db.assign_name("prueba4.txt");
 //db.inser_row("hola que mas",1);
 //cout<<text<<endl;
 enrutador ruters,ruters2;
 red nueva;
// ruters.assing_name('A');

// ruters.asigConex('B',30);
// ruters.asigConex('c',20);
// ruters.asigConex('d',3043);
// ruters.imprimirMapa();

// ruters2.assing_name('B');
// ruters2.asigConex('A',30);
// ruters2.asigConex('c',607);
// ruters2.asigConex('d',8097);
// ruters2.imprimirMapa();
 nueva.agregarNodo('a');
 nueva.agregarNodo('b');
 nueva.agregarNodo('c');
 nueva.agregarNodo('d');
nueva.modificarCosto('a','b',100);
nueva.modificarCosto('c','d',170);
nueva.modificarCosto('e','j',170);
nueva.imprimir();
 nueva.eliminarNodo('b');
 cout<<endl;
 nueva.imprimir();
 nueva.agregarNodo('w');
 nueva.agregarNodo('b');
 nueva.modificarCosto('w','b',10);
 nueva.modificarCosto('d','a',17);
 nueva.modificarCosto('c','d',-1);
 cout<<endl;
 nueva.imprimir();
}
