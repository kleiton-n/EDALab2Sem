#include "libs.h"

// LISTA DOBLE ENCADENADA
bool esTextoVacio(cabezal l){
	return l.primero == NULL && l.ultimo == NULL;
}

bool esLineaVacia(lista_ln ln){
	return ln == NULL;
}
	
bool existeLinea(lista_ln ln, Posicion posicionLinea){
	while(posicionLinea > 1 && !esLineaVacia(ln)){
		posicionLinea--;
		ln = ln->sig;
	}
	return !esLineaVacia(ln);
}
	
// PRE debe de existir la linea
lista_ln obtenerLinea(lista_ln ln, Posicion posicionLinea){
	while(posicionLinea > 1){
		ln = ln->sig;
		posicionLinea--;
	}
	return ln;
}

void Insertar_Linea(cabezal &l){
	lista_ln ln = new nodoln;
	ln->valor = NULL;
	ln->sig = NULL;
	ln->ant = l.ultimo;
	if (esTextoVacio(l)){
		l.primero = ln;
		l.ultimo = ln;
	}else{
		l.ultimo->sig = ln;
		l.ultimo = ln;
	}
}

// LISTA SIMPLE
bool esPalabraVacia(lista_p p){
	return p == NULL;
}

void mostrarTexto(lista_p p){
	while(!esPalabraVacia(p)){
		cout << p->valor << " ";
		p = p->sig;
	}
}

int cantPalabras(lista_p p){
	int contador = 0;
	while(!esPalabraVacia(p)){
		contador++;
		p = p->sig;
	}
	return contador;
}
	
// PRE debe de existir la linea
lista_p obtenerPalabras(lista_ln ln,Posicion posicionLinea){
	return obtenerLinea(ln, posicionLinea)->valor;
}
	
// PRE debe de existir la linea
lista_p	direccionPalabra(lista_p p,Posicion posicionPalabra){
	while (posicionPalabra > 1){
		p = p->sig;
		posicionPalabra--;
	}
	return p;
}

// PRE debe de existir la linea
bool existePalabraPosicion(lista_p p, Posicion posicionPalabra){
	return !esPalabraVacia(direccionPalabra(p, posicionPalabra));
}

// PRE orgien debe de existir
Cadena copiarCadena(Cadena origen) {	
	Cadena copia = new char[strlen(origen) + 1]; 
	strcpy(copia, origen);
	return copia;
}

void Insertar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar, cabezal &l){ //chequear que estemos usando todas las funciones si no borrar
	if (!existeLinea(l.primero,posicionLinea)){ // caso base
		Insertar_Linea(l);
		lista_p p = new nodop;
		p->valor = copiarCadena(palabraAIngresar);
		p->sig = NULL;
		l.ultimo->valor = p;
		cout << "aca1" << endl;
		return;
	}
	lista_p p = obtenerPalabras(l.primero, posicionLinea);
	if(esPalabraVacia(p)){
		p = new nodop;
		p->valor = copiarCadena(palabraAIngresar);
		p->sig = NULL;
		lista_ln ln = obtenerLinea(l.primero, posicionLinea);
		ln->valor = p;
	}else if (posicionPalabra == 1) {
		// inserto al inicio modularizar en caso de ser necesario
		lista_p aux = new nodop;
		aux->valor = copiarCadena(palabraAIngresar);
		aux->sig = p;
		lista_ln ln = obtenerLinea(l.primero, posicionLinea);
		ln->valor = aux;
		p = aux;
	}else{
		// inserto entre nodos  modularizar en caso de ser necesario
		lista_p ant = direccionPalabra(p, posicionPalabra - 1);
		lista_p aux = new nodop;
		aux->valor = copiarCadena(palabraAIngresar);
		aux->sig = ant->sig;
		ant->sig = aux;
	}
	if (cantPalabras(p) > MAX_CANT_PALABRAS_X_LINEA){ // recursivo
		int i = 1;
		while(i < MAX_CANT_PALABRAS_X_LINEA){
			p = p->sig;
			i++;
		}
		Cadena palabraSig = copiarCadena(p->sig->valor);
		delete[] p->sig->valor;
		delete p->sig;
		p->sig = NULL;
		Insertar_Palabra(posicionLinea+1, 1, palabraSig, l);
	}
}
