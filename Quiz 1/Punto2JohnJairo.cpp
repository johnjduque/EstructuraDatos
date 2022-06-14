//John Jairo Duque Zuluaga - hora inicio: 18:20

#include<iostream>
using namespace std;

struct duqCab{
	string fecha;
	string direccion;
	duqCab *apunt1, *apunt2, *apunt3;	
};

int main(){
	
	duqCab *nodoInicial;
	nodoInicial = new (duqCab);
	nodoInicial->direccion = " ";
	nodoInicial->fecha = " ";
	nodoInicial->apunt1 = new (duqCab);	
	nodoInicial->apunt2 = new (duqCab);
	nodoInicial->apunt3 = new (duqCab);
	
	nodoInicial->apunt1->direccion = "Tres Cantos - Rionegro";
	nodoInicial->apunt1->fecha = "Junio de 2020";
	nodoInicial->apunt1->apunt1 = NULL;
	nodoInicial->apunt1->apunt2 = NULL;
	nodoInicial->apunt1->apunt3 = nodoInicial->apunt2;
	
	nodoInicial->apunt2->direccion = "Tres Cantos - Rionegro";
	nodoInicial->apunt2->fecha = "Junio de 2020";
	nodoInicial->apunt2->apunt1 = NULL;
	nodoInicial->apunt2->apunt2 = NULL;
	nodoInicial->apunt2->apunt3 = nodoInicial->apunt3;
	
	nodoInicial->apunt3->direccion = "Tres Cantos - Rionegro";
	nodoInicial->apunt3->fecha = "Junio de 2020";
	nodoInicial->apunt3->apunt1 = NULL;
	nodoInicial->apunt3->apunt2 = NULL;
	nodoInicial->apunt3->apunt3 = NULL;
	
	return 0;
}
