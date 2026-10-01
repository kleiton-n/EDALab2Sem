#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define MAX_CANT_PALABRAS_X_LINEA 5

enum _retorno{
	OK, ERRORR, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRetorno;

typedef char *Cadena;

struct nodo{
	nodo *ant;
	Cadena valor = new char[10]; //char valor[10];
	nodo *sig;
};

typedef struct nodo *lista;

typedef unsigned int Posicion;

typedef struct param {
	Posicion pos1;
	Posicion pos2;
	Cadena texto;
} Parametros;

typedef TipoRetorno (*ComandoFunc) (Parametros params);

typedef struct _command{
	Cadena nombre;
	ComandoFunc funcion;
	int cantParametros;
}command;

struct _cabezal {
	lista primero;
	lista ultimo;
};

typedef struct _cabezal cabezal;

#endif
