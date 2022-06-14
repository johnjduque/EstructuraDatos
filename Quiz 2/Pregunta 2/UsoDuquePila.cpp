#include "TDADuquePila.cpp"

bool esColorZuluaga(int colorduq){
	bool esColorDuq;
	if(colorduq == 1 or colorduq == 3){
		esColorDuq = true;
	}
	else{
		esColorDuq = false;
	}
	return esColorDuq;	
}

bool esFormaZuluaga(int formaduq){
	bool esFormaDuq;
	if(formaduq == 2 or formaduq == 3){
		esFormaDuq = true;
	}
	else{
		esFormaDuq = false;
	}
	return esFormaDuq;	
}

bool esGrosorZuluaga(int grosorduq){
	bool esGrosorDuq;
	if(grosorduq == 2){
		esGrosorDuq = true;
	}
	else{
		esGrosorDuq = false;
	}
	return esGrosorDuq;	
}

int main(){
	
	TDADuquePila *piladuq, *listaduq;
	piladuq = NULL;
	listaduq = NULL;
	
	JohnBloque bloqueduq;
	int cuantasApilaDuq = 0;
	int cuantasEnListaDuq = 0;
	
	int seguirduq = 0;
	
	cout<<"Si desea apilar bloques presione 1, de lo contrario presione otra tecla: ";
	cin>>seguirduq;
	
	while(seguirduq == 1){
		
		bloqueduq = crearBloqueJairo();
		if(esColorZuluaga(bloqueduq.colorduq) && esFormaZuluaga(bloqueduq.formaduq) && esGrosorZuluaga(bloqueduq.grosorduq)){
			piladuq = insertarPilaInfoZuluaga(piladuq, bloqueduq);
			cuantasApilaDuq = cuantasApilaDuq + 1;			
		}
		else{
			listaduq = insertarListaInfoZuluaga(listaduq, bloqueduq);
			cuantasEnListaDuq = cuantasEnListaDuq + 1;
		}
		
		cout<<"Si desea apilar bloques presione 1, de lo contrario presione otra tecla: ";
		cin>>seguirduq;
	}
	
	cout<<"Se apilaron: "<<cuantasApilaDuq<<" bloques"<<endl;
	cout<<"Se fueron a lista: "<<cuantasEnListaDuq<<" bloques"<<endl;	
		
	
	return 0;
}
