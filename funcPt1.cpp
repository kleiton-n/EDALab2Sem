#include "libs.h"

cabezal l;

//1
TipoRetorno InsertarLinea(){
	Insertar_Linea(l);
	return OK;
}

//8
TipoRetorno InsertarPalabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
	if(esTextoVacio(l)){
		cout << "Actualmente no existen lineas en el documento" << endl;
		return ERRORES;
	}else if(!existeLinea(l.primero, posicionLinea)){
		cout << "Linea " << posicionLinea << " no existe" << endl;
		return ERRORES;
	}else if(posicionPalabra > MAX_CANT_PALABRAS_X_LINEA){
		cout << "La posicion de la palabra supera la cantidad maxima de palabras por linea" << endl;
		return ERRORES;
	}else if(posicionPalabra < 1){
		cout << "la posicion de la palabra debe de ser un numero positivo" << endl;
		return ERRORES;
	}else if(posicionPalabra > (unsigned)(cantPalabras(obtenerPalabras(l.primero, posicionLinea))+1)){
		cout << "la posicon de la palabra debe de ser una posicion validad dentro de la linea" << endl;
		return ERRORES;
	}
	Insertar_Palabra(posicionLinea, posicionPalabra, palabraAIngresar, l);
	return OK;
}

//2
TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea){
	if (posicionLinea < 1){
		cout << "la posicion de la linea debe de ser un numero positivo" << endl;
		return ERRORES;
	}else if (posicionLinea > ((unsigned)cantLineas(l.primero) + 1)){
		cout << "la poscion indicada supera la cantidad de linesas actuales" << endl;
		return ERRORES;
	}
	if (posicionLinea > (unsigned)cantLineas(l.primero)){
		Insertar_Linea(l);
	}else{
		lista_ln ln = obtenerLinea(l.primero, posicionLinea);
		lista_ln aux = new nodoln;
		aux->valor = NULL;
		aux->ant = ln->ant;
		aux->sig = ln;
		ln->ant->sig = aux;
		ln->ant = aux;
	}
	return OK;
}

//3
TipoRetorno BorrarLinea(Posicion posicionLinea){
	if(esTextoVacio(l)){
		cout << "Actualmente no existen lineas en el documento" << endl;
		return ERRORES;
	}else if(!existeLinea(l.primero, posicionLinea)){
		cout << "Linea " << posicionLinea << " no existe" << endl;
		return ERRORES;
	}
	Borrar_Linea(l,posicionLinea);
	return OK;
}

//4
TipoRetorno BorrarTodo(){
	Borrar_Todo(l);
	return OK;
}

//6
TipoRetorno ImprimirTexto(){
	if(esTextoVacio(l)){
		cout << "Texto vacio" << endl;
	}else{
		lista_ln aux = l.primero;
		int i = 1;
		while(!esLineaVacia(aux)){
			cout << i << ": ";
			mostrarTexto(aux->valor);
			cout << endl;
			aux = aux->sig;
			i++;
		}
	}
	return OK;
}

TipoRetorno ClearP(){
	clear();
	return OK;
}
	
void muestroRetorno(int retorno){
	switch (retorno){
	case 0:
		cout << "OK"<<endl;
		break;
	case 1:
		cout << "ERROR"<<endl;
		break;
	case 2:
		cout << "NO IMPLEMENTADA" << endl;
		break;
	}
}

TipoRetorno BorrarPalabra(Posicion posicionLinea, Posicion posicionPalabra){
	Borrar_Palabra(posicionLinea, posicionPalabra, l);
	return OK;
}
