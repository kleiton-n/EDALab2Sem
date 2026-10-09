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
		cout << "actualmente no hay lineas en el documento" << endl;
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
	}else if(posicionPalabra > (cantPalabras(obtenerPalabras(l.primero, posicionLinea))+1)){
		cout << "la posicon de la palabra debe de ser una posicion validad dentro de la linea" << endl;
		return ERRORES;
	}
	Insertar_Palabra(posicionLinea, posicionPalabra, palabraAIngresar, l);
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
