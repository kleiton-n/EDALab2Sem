#include "libs.h"

#define MAX_LINEA_ENTRADA 256

// TODO
// ver lo del memory leak

int main (int argc, char *argv[]) {
	char texto[MAX_LINEA_ENTRADA];
	// debug
	InsertarLinea();
	InsertarLinea();
	InsertarLinea();
	InsertarPalabra(1,1,(Cadena)"palabra1");
	InsertarPalabra(2,1,(Cadena)"palabra2");
	InsertarPalabra(3,1,(Cadena)"palabra3");
	ImprimirTexto();
	// cout << cantLineas(l.primero) << endl;
	// debug
	while (true) {
		cout << "> ";
		
		if (!cin.getline(texto, MAX_LINEA_ENTRADA)) {
			break;
		}
		
		// Ignora líneas vacías (si el usuario presiona Enter sin escribir nada)
		if (texto[0] == '\0') {
			continue;
		}
		
		// Opción para finalizar la ejecución del programa
		char tmp[MAX_LINEA_ENTRADA];
		strcpy(tmp,texto);
		Cadena separador = strtok(tmp, "(");
		if (cadcmp(separador, (Cadena)"salir")|| cadcmp(separador, (Cadena)"exit")) {
			break;
		}
		
		// Invoca al parser y despachador de comandos
		muestroRetorno(parser(texto));
	}
	
	return 0;
}
