#include "libs.h"

//1
TipoRetorno InsertarLinea(){
	Insertar_Linea();
	return NO_IMPLEMENTADA;
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
	return NO_IMPLEMENTADA;
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
