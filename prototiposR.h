#ifndef PROTOTIPOSR_H
#define PROTOTIPOSR_H

TipoRetorno InsertarLinea();

TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea);

TipoRetorno InsertarPalabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

TipoRetorno BorrarLinea(Posicion posicionLinea);

TipoRetorno BorrarTodo();
	
TipoRetorno ImprimirTexto();
	
void muestroRetorno(int retorno);


#endif
