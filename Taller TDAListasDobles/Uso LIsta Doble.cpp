#include "TDAListaDobles.cpp"

using namespace std;

int main(){
	
	TDAListaDoble *listaDE;
	listaDE = Inicilizar();
	nodoLDE *nodoDE;
	crearLista(listaDE, 0);
	
	for(int i=0; i<4; i++){
		nodoDE = crearNodo();
		InsertarPorCabeza(listaDE, nodoDE);
	}
		
	ImprimirLista(listaDE);
}
