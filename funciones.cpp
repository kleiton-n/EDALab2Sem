#include "libs.h"

void Insertar_Linea(){
	// logica de inserto linea
}

// LISTA DOBLE ENCADENADA
bool esTextoVacio(cabezal l){
	return l.primero == NULL && l.ultimo == NULL;
}

bool esLineaVacia(lista_ln ln){
	return ln == NULL;
}
	
	
// LISTA SIMPLE
bool esPalabraVacia(lista_p p){
	return p == NULL;
}

void mostrarTexto(lista_p p){
	while(!esPalabraVacia(p)){
		cout << p->valor << " ";
		p = p.sig;
	}
}
