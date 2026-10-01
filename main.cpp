#include "libs.h"

#define MAX_LINEA_ENTRADA 256

int main (int argc, char *argv[]) {
	char buffer[MAX_LINEA_ENTRADA];
	
	while (true) {
		cout << "> ";
		
		// Carga la línea ingresada por teclado o redirección de archivo
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			// Fin de archivo (EOF / Ctrl+D en Linux / Ctrl+Z en Windows)
			break; 
		}
		
		// Remueve el salto de línea '\n' al final del string si está presente
		size_t largo = strlen(buffer);
		if (largo > 0 && buffer[largo - 1] == '\n') {
			buffer[largo - 1] = '\0';
		}
		
		// Ignora líneas vacías (si el usuario presiona Enter sin escribir nada)
		if (buffer[0] == '\0') {
			continue;
		}
		
		// Opción para finalizar la ejecución del programa
		if (strcmp(buffer, "Salir") == 0 || strcmp(buffer, "exit") == 0) {
			break;
		}
		
		// Invoca al parser y despachador de comandos
		muestroRetorno(parser(buffer));
	}
	
	return 0;
}

