#ifndef PROTOTIPOSR_H
#define PROTOTIPOSR_H

TipoRetorno InsertarLinea();

TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea);

TipoRetorno InsertarPalabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

TipoRetorno BorrarLinea(Posicion posicionLinea);

	
TipoRetorno ImprimirTexto();

TipoRetorno ClearP();

TipoRetorno BorrarPalabra(Posicion posicionLinea, Posicion posicionPalabra);

TipoRetorno BorrarTodo();

void muestroRetorno(int retorno);


#endif
