#include "libs.h"

cabezal l;

//1
TipoRetorno InsertarLinea(){
//	Insertar_Linea();
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
	return OK;
}

//2
TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea){
	return NO_IMPLEMENTADA;
}

//3
TipoRetorno BorrarLinea(Posicion posicionLinea){
	return NO_IMPLEMENTADA;
}

//4
TipoRetorno BorrarTodo(){
	return NO_IMPLEMENTADA;
}

//6
TipoRetorno ImprimirTexto(){
	if(esLineaVacia(l)){
		cout << "Texto vacio";
	}else{
		lista_ln aux = l.primero;
		int i = 1;
		while(!esLineaVacia(aux)){
			cout << i << ": ";
			mostrarTexto();
			cout << endl;
			aux = aux.sig;
			i++;
		}
	}
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
