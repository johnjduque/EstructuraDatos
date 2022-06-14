#include "TDALCJuego.cpp"
#include <time.h>
#include <stdlib.h>

int main(){
	
	TDAListaCircularJ *listaCircular, *listaEquipoUno, *listaEquipoDos;
	listaCircular = NULL;
	listaEquipoUno = NULL;
	listaEquipoDos = NULL;
	TDANodoCircularJ *nodo;
	nodo = NULL;
	
	int numeroAmigos = 0;
	int dado;
	int cuantosQuedan;
	string nombre;
	
	cout<<"¿Cuantos amigos van a jugar?"<<endl;
	cin>>numeroAmigos;
	
	for(int i=0; i<numeroAmigos; i++){
		nodo = crearNodoDatoJ(i + 1);
		listaCircular = insertarNodoJ(listaCircular, nodo);
		cout<<"Ingrese el nombre del jugador en sentido horario de la ronda"<<endl;
		cin>>nombre;
		cout<<"El numero asignado para "<<nombre<<" es: "<<i+1<<endl;
	}
	
	cout<<"Lista Inicial"<<endl;
	ImprimirListaJ(listaCircular);
	
	int j = 1;
	cuantosQuedan = numeroAmigos;
	
	while(j<=numeroAmigos+1){
		
		cout<<"El jugador: "<<listaCircular->inicio->info<<" lanza el dado"<<endl;
		dado = 1+rand()%(7-1);
		cout<<"Lanzando el dado...........saco -> "<<dado<<endl;
			
		if(j%2 == 0){
			listaCircular = sentidoAntiHorarioJ(listaCircular, dado, cuantosQuedan);
			listaEquipoDos = insertarNodoJ(listaEquipoUno, listaCircular->inicio);
			borrarElementoJ(listaCircular, listaCircular->inicio);
			cuantosQuedan = cuantosQuedan - 1;	
		}
		else{
			listaCircular = sentidoHorarioJ(listaCircular, dado);
			listaEquipoUno = insertarNodoJ(listaEquipoUno, listaCircular->inicio);
			borrarElementoJ(listaCircular, listaCircular->inicio);
			cuantosQuedan = cuantosQuedan - 1;									
		}
		
		j++;
	}
	
	cout<<"Lista despues de sorteo"<<endl;
	ImprimirListaJ(listaCircular);
	
	cout<<"Integrantes Equipo 1"<<endl;	
	ImprimirListaJ(listaEquipoUno);
	
	cout<<"Integrantes Equipo 2"<<endl;	
	ImprimirListaJ(listaEquipoDos);

	return 0;
}
