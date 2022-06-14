#ifndef _TDAListaSimples
#define TDAListaSimples

struct TDANodo;

struct Informacion;

typedef struct TDAnodo *nodo;

typedef struct Informacion fecha;

TDAnodo *crearNodo();

void mostrarInfo(TDANodo *Nodo);

int esListaVacia(TDANodo *lista);

TDANodo *buscarElemento(TDANodo *inicio, Informacion elemento);

TDANodo *insertarNodoInicio(TDANodo *lista);

TDANodo *insertarNodoFinal(TDANodo *lista);

TDANodo *insertarNodoDespuesOtro(TDANodo *lista);

void mostrarLista(TDANodo *inicio);

void mostrarFechasMayores(TDAnodo *duqLista);

#include  "TDAListaSimples.cpp"
#endif
