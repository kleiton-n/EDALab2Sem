#include "libs.h"

// PRE orgien debe de existir
Cadena copiarCadena(Cadena origen){	
	Cadena copia = new char[strlen(origen) + 1]; 
	strcpy(copia, origen);
	return copia;
}

// LISTA DOBLE ENCADENADA
bool esTextoVacio(cabezal l){
	return l.primero == NULL && l.ultimo == NULL;
}

bool esLineaVacia(lista_ln ln){
	return ln == NULL;
}

// DIX functions
bool esDixVacio(diccionario dix){
	return dix == NULL;
}


bool existePalabraDix(diccionario d, Cadena p){
	if(esDixVacio(d)){
		return false;
	}else if(strcmp(d->palabra, p) == 0){
		return true;
	}else if(strcmp(d->palabra, p) > 0){
		return existePalabraDix(d->izq, p);
	}else{
		return existePalabraDix(d->der, p);
	}
}
	
void IngresarPalabraDix(diccionario &d, Cadena p){
	if(esDixVacio(d)){
		d = new _diccionario;
		d->palabra = copiarCadena(p);
	}else{
		if(strcmp(d->palabra, p) > 0){
			IngresarPalabraDix(d->izq, p);
		}else{
			IngresarPalabraDix(d->der, p);
		}
	}
}
	
// pre diccionario no vacio
void imprimirInorden(diccionario d){
	if(!esDixVacio(d)){
		imprimirInorden(d->izq);
		cout << d->palabra << endl;
		imprimirInorden(d->der);
	}
}
	
diccionario unirDix(diccionario izq, diccionario der){
	if(esDixVacio(izq)){
		return der;
	}
	if(esDixVacio(der)){
		return izq;
	}
	diccionario centro = unirDix(izq->der, der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}
	
void borrarPlabraDix(diccionario &d,Cadena palabraABorrar){
	if(esDixVacio(d)){
		return;
	}else{
		if(strcmp(d->palabra, palabraABorrar) > 0){
			borrarPlabraDix(d->izq,palabraABorrar);
		}else if(strcmp(d->palabra,palabraABorrar) < 0){
			borrarPlabraDix(d->der,palabraABorrar);
		}else{
			diccionario dixABorrar = d;
			d = unirDix(d->izq, d->der);
			delete dixABorrar;
		}
	}
}

// DIX functions

int cantLineas(lista_ln primero){
	int cant = 0;
	while(!esLineaVacia(primero)){
		primero = primero->sig;
		cant++;
	}
	return cant;
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
	if(esTextoVacio(l)){
		l.primero = ln;
		l.ultimo = ln;
	}else{
		l.ultimo->sig = ln;
		l.ultimo = ln;
	}
}

void Insertar_LineaEnPosicion(Posicion posicionLinea, cabezal &l){
	
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
	while(posicionPalabra > 1){
		p = p->sig;
		posicionPalabra--;
	}
	return p;
}

// PRE debe de existir la linea
bool existePalabraPosicion(lista_p p, Posicion posicionPalabra){
	return !esPalabraVacia(direccionPalabra(p, posicionPalabra));
}

void Insertar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar, cabezal &l){ //chequear que estemos usando todas las funciones si no borrar
	if(!existeLinea(l.primero,posicionLinea)){ // caso base
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
	}else if(posicionPalabra == 1){
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
	if(cantPalabras(p) > MAX_CANT_PALABRAS_X_LINEA){ // recursivo
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
	
// pre la palabra y la linea debe de existir
void Borrar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, cabezal &l){
	lista_p p = obtenerPalabras(l.primero, posicionLinea);
	if(posicionPalabra == 1){
		lista_p aux = new nodop;
		aux = p->sig;
		lista_ln ln = obtenerLinea(l.primero, posicionLinea);
		delete p;
		ln->valor = aux;
		
	}else{
		lista_p aux = new nodop;
		while(posicionPalabra > 1){
			aux = p;
			p = p->sig;
			posicionPalabra --;
		}
		aux->sig = p->sig;
		delete p;
	}
}
	
void ComprimirTexto(cabezal &l){
	lista_ln ln = l.primero;
	
	while(!esLineaVacia(ln)){
		int cantidad = 0;
		lista_p ultima = NULL;
		
		lista_p p = ln->valor;
		cantidad = cantPalabras(p);
		
		while(!esPalabraVacia(p)){
			ultima = p;
			p = p->sig;
		}
		
		while(cantidad < MAX_CANT_PALABRAS_X_LINEA && ln->sig != NULL){
			
			lista_ln siguiente = ln->sig;
			
			if(!esPalabraVacia(siguiente->valor)){
				lista_p palabra = siguiente->valor;
				siguiente->valor = palabra->sig;
				palabra->sig = NULL;
				if(ultima == NULL){
					ln->valor = palabra;
				}else{
					ultima->sig = palabra;
				}
				ultima = palabra;
				cantidad++;
			}
			
			if(siguiente->valor == NULL){
				ln->sig = siguiente->sig;
				if(ln->sig != NULL){
					ln->sig->ant = ln;
				}else{
					l.ultimo = ln;
				}
				delete siguiente;
			}
		}
		
		if(ln->valor == NULL){
			lista_ln vacia = ln;
			ln = ln->sig;
			
			if(vacia->ant != NULL){
				vacia->ant->sig = ln;
			} else {
				l.primero = ln;
			}
			
			if(ln != NULL){
				ln->ant = vacia->ant;
			} else {
				l.ultimo = vacia->ant;
			}
			
			delete vacia;
		} else {
			ln = ln->sig;
		}
	}
}
	
void Borrar_Linea(cabezal &l, Posicion posicionLinea){
	lista_ln ln = obtenerLinea(l.primero, posicionLinea);
	
	for(int i = cantPalabras(ln->valor); i > 0; i--){
		Borrar_Palabra(posicionLinea, i, l);
	}
	
	if(ln->sig == NULL){
		l.ultimo = ln->ant;
	}else{
		ln->sig->ant = ln->ant;
	}
	
	if(ln->ant == NULL){
		l.primero = ln->sig;
	}else{
		ln->ant->sig = ln->sig;
	}
	delete ln;
	
}	

void Borrar_Todo(cabezal &l){
	while(l.primero != NULL){
		Borrar_Linea(l, 1);
	}
}

void Imprimir_Texto_Incorrecto(cabezal &l, diccionario d){
	if(esDixVacio(d)){
		lista_ln aux = l.primero;
		int i = 1;
		while(!esLineaVacia(aux)){
			cout << i << ": ";
			mostrarTexto(aux->valor);
			cout << endl;
			aux = aux->sig;
			i++;
		}
	}else{
		lista_ln auxln = l.primero;
		int i = 1;
		while(!esLineaVacia(auxln)){
			cout << i << ": ";
			lista_p auxp = auxln->valor;
			while(!esPalabraVacia(auxp)){
				if(!existePalabraDix(d,auxp->valor)){
					cout << auxp->valor << " ";
				}
				auxp = auxp->sig;
			}
			cout << endl;
			auxln = auxln->sig;
			i++;
		}
	}
}

void BorrarOcurrenciaPalabra(cabezal l, Cadena palabraABorrar){
	lista_ln ln = l.primero;
	for (int i = 1; !esLineaVacia(ln); i++){
		BorrarocurrenciaPalabraLN(l,i,palabraABorrar);
		ln = ln->sig;
	}
}

void BorrarocurrenciaPalabraLN(cabezal l, Posicion posicionLinea, Cadena palabraABorrar){
	lista_p p = obtenerPalabras(l.primero,posicionLinea); 
	for (int i = 1; !esPalabraVacia(p); i++){
		if(strcmp(p->valor,palabraABorrar) == 0){
			p = p->sig;
			Borrar_Palabra(posicionLinea,i,l);
		}else{
			p = p->sig;
		}
	}
}
