#include "libs.h"

#define MAX_LINEA_ENTRADA 256

// TODO
// chequear funciones con parametros de 1,2 y 3
// ver lo del memory leak

int main (int argc, char *argv[]) {
	char texto[MAX_LINEA_ENTRADA];
	
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
		separador = minusculas(separador); // ver el aproach para escribir directo en la varaible para evitar leack de memoria
		if (strcmp(separador, "salir") == 0 || strcmp(separador, "exit") == 0) {
			break;
		}
		
		// Invoca al parser y despachador de comandos
		muestroRetorno(parser(texto));
	}
	
	return 0;
}
