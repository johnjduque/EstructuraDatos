#include "TDACola.cpp"

int devolverTiempoAtencion(TDACola *colaC){
  int tiempo=0;
  //Deposito
	if(colaC->inicio->info.transaccion==1){
    tiempo+=3;
  }
  //Retiro
  if(colaC->inicio->info.transaccion==2){
    tiempo+=5;
  }
  //Transferencia
  if(colaC->inicio->info.transaccion==3){
    tiempo+=4;
  }
  //Otros
  if(colaC->inicio->info.transaccion==4){
    tiempo+=3;
  }
	return tiempo;
}

int main(){
  TDACola  *colaClientes;
  colaClientes=NULL;

  for (int i= 1; i<=5; i++) {
  	colaClientes = insertarCola(colaClientes);
  }

  int minutos=0;
  //Se reinicia cada 7 minutos que ingresa un nuevo cliente
  int minutosIngreso=0;
  //Se resta tiempo de atencion hasta 0
  int tiempoAtencion = devolverTiempoAtencion(colaClientes);
  int cantidadAtendidos=0;
  
 while(minutos<10){
   cout<<"Minutos: "<<minutos<<endl;

   if(tiempoAtencion>0){
  	cout << "Se atiende a: ";
  	mostrarNodo(colaClientes);
    tiempoAtencion--;
   }

   else if(tiempoAtencion==0){
     if(colaClientes!=NULL){
     cout << "Se termina de atender a: ";
  	mostrarNodo(colaClientes);
    cantidadAtendidos++;
    
    if(colaClientes->inicio->sig!=NULL){
    colaClientes=eliminarCola(colaClientes);
    tiempoAtencion=devolverTiempoAtencion(colaClientes);
     }
   }
   else{
       colaClientes=NULL;
       tiempoAtencion=0;
     }
   }

   if(minutosIngreso==7){
     cout<<"Ha ingresado un nuevo cliente a la cola";
     colaClientes=insertarCola(colaClientes);
     tiempoAtencion=devolverTiempoAtencion(colaClientes);
     minutosIngreso=0;
   }
   else if(minutosIngreso<7){
      minutosIngreso++;
   }
    minutos++;

    cout<<"Faltan: "<<60-minutos<<" minutos para que termine la hora "<<endl;
    cout<<"Hemos atendido a "<<cantidadAtendidos<<" personas hasta ahora "<<endl;
}
  return 0;
  
}

