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

// PRE debe de existir la linea
lista_p obtenerPalabras(lista_ln ln,Posicion posicionLinea){
	return obtenerLinea(ln, posicionLinea)->valor;
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

void Insertar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar, cabezal &l){
	// palabra null se termina;
	// pos 1 > pos2 > pos3 ya estaba
	// pos 1 > aux > pos 2 > pos 3 > NULL
	// posicionpalkabra++ // 3-1
	// if posicionpalkabra > const {
		// if not linea sig existe crear posicionLinea+1
		// InsertarPalabra(posicionLinea+1, 1, aux->valor)
	//else return
	if (!existeLinea(l.primero,posicionLinea)){
//		Insertar_Linea(l);
//		lista_p p = new nodop;
//		p->valor = palabraAIngresar;
//		p->sig = NULL;
//		l.ultimo->valor = p;
//		return;
	}else if((cantPalabras(obtenerPalabras(l.primero, posicionLinea)) + 1) <= MAX_CANT_PALABRAS_X_LINEA){
		lista_p p = obtenerPalabras(l.primero, posicionLinea);
		if(esPalabraVacia(p)){
			p = new nodop;
			p->valor = palabraAIngresar;
			p->sig = NULL;
			lista_ln ln = obtenerLinea(l.primero, posicionLinea);
			ln->valor = p;
			return;
		}
		///// 
		if (!buscoValorRecursivo(l,datoNodo)){
			l = insertofinal(l,nuevoDato);
		}else{
			lista aux = new nodo;
			aux->valor = nuevoDato;
			aux->sig = direccionNodo(l,datoNodo)->sig;
			direccionNodo(l,datoNodo)->sig = aux;
		}
		return l;
		///// codigo sacado del proyecto de listas para imitar en esto
		
		return;
	}// caso recursivo
//	lista_p p = obtenerLinea(l.primero, posicionLinea);
//	lista_p aux = new nodop;
//	aux->valor = palabraAIngresar;
	
}
