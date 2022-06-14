#ifndef _TDAListaSimplesEnteros
#define TDAListaSimplesEnteros

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

TDAnodo *insertarNodoConInfo(TDAnodo *lista, TDAnodo *nuevo);

TDAnodo *borrarNodo(TDAnodo *lista, TDAnodo *nodoBorrar);

TDAnodo *johnCrearNodoMultiplicacion(int jairo, TDAnodo *duque);

TDAnodo *johnJairoInsertarNodoParaOtraLista(TDAnodo *zuluaga);

#include  "TDAListaSimplesEnteros.cpp"
#endif
