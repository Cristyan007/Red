#include "database.h"
#include "red.h"
#include "funciones.h"
int main()
{
cout<<'\t'<<"--------- BIENVENIEDO A REDES ---------"<<'\t'<<endl<<endl<<endl;
red nueva;
bool program = true;
while (program){
    imprimirmenu();
    program = acciones(&nueva);
    }
}
