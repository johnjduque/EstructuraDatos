TDALista *insertarLlamadocobrada(TDALista *john,TDANodo *jairoBuscado){
	llamadaCobradas *duqueLLamadac;

	duqueLLamadac=new(llamadaCobradas);
	cout<<"\nIngrese Telefono destino:   ";
	cin>>duqueLLamadac->telefonoDestino;
	cout<<"Ingrese total cobrado:   ";
	cin>>duqueLLamadac->totalCobrado;
	cout<<"Ingrese total llamadas:   ";
	cin>>duqueLLamadac->totalLlamadas;
	duqueLLamadac->sigllamadaCobrada = nodoBuscado->celular.llamadasCobradas;
	nodoBuscado->celular.llamadasCobradas = duqueLLamadac;
	
	return john;
}

TDALista *insertarListaZuluaga (TDALista *johnLlam){
    TDANodo *nuevoDuqNodo, *nodoZulBuscado;
    short opcion;
    string celular;
    do {
    	
		cout<<"Ingresa el numero del celular ";
		cin>>celular;
		nodoZulBuscado = buscarCelular(celular, johnLlam);
    	if (nodoZulBuscado == NULL) 	{
			
			nuevoDuqNodo = crearNodo(celular);
			
			if (johnLlam== NULL)
			{   
				johnLlam = new(TDALista);
				johnLlam->cab=johnLlam->fin=nuevoDuqNodo;
			}
			else {
				nuevoDuqNodo->sig = johnLlam->cab;
				johnLlam->cab = nuevoDuqNodo;
			}
		}
		else
		{
			johnLlam = insertarLlamadocobrada(johnLlam, nodoZulBuscado);
		}
	    cout <<"\nDigite cero (0)  para salir  ";
	    cin>>opcion;
	    
	}while (opcion !=0);
	return johnLlam;
}

TDALista *duqMostrarLlamadaCo (TDALista jLista, string zulCelular){
	TDALista *aux, 
	TDANodo *cel,
	llamadaCobradas *llam,
	aux = jLista;
	llam = aux->celular.llamadasCobradas;
	
	while(aux != NULL){
		cel = buscarCelular(zulCelular, jLista);
		if(cel){
			while(cel->celular.llamadasCobradas.sigllamadaCobrada != NULL && llam != NULL){
				aux = cel->celular.llamadasCobradas.sigllamadaCobrada;
				llam = aux->sigllamadaCobrada;				
			}
			if(cel->celular.llamadasCobradas.sigllamadaCobrada == NULL){
				cout<<"No hay llamadas cobradas registradas";
			}
			return aux;
		}
		else{
			cout<<"Celular no encontrado";
		}
	} 
}

