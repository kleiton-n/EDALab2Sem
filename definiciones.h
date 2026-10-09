#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define MAX_CANT_PALABRAS_X_LINEA 3
#define DELIMITADORES "(, );"

enum _retorno{
	OK, ERRORES, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRetorno;

typedef char *Cadena;

typedef unsigned int Posicion;

// COMMANDS
typedef struct param {
	Cadena param1 = NULL;
	Cadena param2 = NULL;
	Cadena param3 = NULL;
} Parametros;

typedef TipoRetorno (*ComandoFunc) (Parametros params);

typedef struct _command{
	Cadena nombre;
	ComandoFunc funcion;
	int cantParametros;
}command;

// COMMANDS

typedef struct nodop{
	Cadena valor = new char[15];
	nodop *sig;
}*lista_p;

typedef struct nodoln{
	nodoln *ant;
	lista_p valor;
	nodoln *sig;
}*lista_ln;

typedef struct _cabezal {
	lista_ln primero = NULL;
	lista_ln ultimo = NULL;
}cabezal;

#endif
