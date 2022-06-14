#include "TDACola.cpp"

int devolverTiempoAtencion(TDACola *cola){
	
	int tiempo;
	
	if (cola->inicio->info.transaccion == 1 or cola->inicio->info.transaccion == 4){
		tiempo = 3;
	}
	else if (cola->inicio->info.transaccion == 2){
		tiempo = 5;
	}
	else{
		tiempo = 4;
	}
	return tiempo;
}

int main(){

	TDACola *cola;
	cola = NULL;
	int i = 1;
	int controlAtencion = 1;
	int cuantosClientes = 0;
	int j = 1;
	int clientesAtendidos = 0;
	int clienteLlega = 0;
	
	for (int i=1; i<= 5; i++){
		cola = insertarCola(cola);
		clienteLlega++;
	}
	
	while (i<=60){
		
		while(controlAtencion <= (devolverTiempoAtencion(cola) * (cola->inicio->info.cantidad))){
			
			cout<<endl<<"Reporte minuto: "<<i;
			cout<<endl<<"Se atiende a: ";
			mostrarNodo(cola);
			
			while(j == 7){
				cola = insertarCola(cola);
				j = 0;
				clienteLlega++;
			}
			i++;
			j++;
			controlAtencion++;		
		}
		cout<<endl<<"El tiempo usado con el cliente: "<<cola->inicio->info.nombre<<" es: "<<(devolverTiempoAtencion(cola) * (cola->inicio->info.cantidad))<<endl;
		eliminarCola(cola);
		clientesAtendidos++;
		controlAtencion = 1;
	}
		
	cout<<endl<<"En una hora atendio :"<<clientesAtendidos<<" clientes."<<endl;
	cout<<endl<<"Faltan por atender :"<<clienteLlega - clientesAtendidos<<" clientes."<<endl;
	
  return 0;
 
}

