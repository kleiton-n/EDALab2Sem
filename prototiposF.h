#ifndef PROTOTIPOSF_H
#define PROTOTIPOSF_H

void Insertar_Linea(cabezal &l);
bool esTextoVacio(cabezal l);
bool esLineaVacia(lista_ln ln);
int cantLineas(lista_ln primero);
lista_ln obtenerLinea(lista_ln ln, Posicion posicionLinea);
bool esPalabraVacia(cabezal l);
bool existeLinea(lista_ln ln, Posicion posicionLinea);
lista_p obtenerPalabras(lista_ln ln,Posicion posicionLinea);


void Borrar_Linea(cabezal &l, Posicion posicionLinea);
void mostrarTexto(lista_p p);
int cantPalabras(lista_p p);
void Insertar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar, cabezal &l);
void Borrar_Palabra(Posicion posicionLinea, Posicion posicionPalabra, cabezal &l);

#endif
