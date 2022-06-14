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

TDAnodo *insertarNodoParaOtraLista(TDAnodo *lista);

TDAnodo *duqueFechasMes(TDAnodo *john, string jairo);

void mostrarLista(TDANodo *inicio);

#include  "TDAListaSimples.cpp"
#endif
