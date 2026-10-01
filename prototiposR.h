#ifndef PROTOTIPOSR_H
#define PROTOTIPOSR_H

TipoRetorno InsertarLinea();

TipoRetorno InsertarLineaEnPosicion(Posicion posicionLinea);

TipoRetorno BorrarLinea(Posicion posicionLinea);

TipoRetorno BorrarTodo();
	
TipoRetorno ImprimirTexto();
	
void muestroRetorno(int retorno);


#endif
