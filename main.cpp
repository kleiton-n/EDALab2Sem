#include "libs.h"

#define MAX_LINEA_ENTRADA 256

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
		if (cadcmp(separador, (Cadena)"salir")|| cadcmp(separador, (Cadena)"exit")|| cadcmp(separador, (Cadena)"qqq")) {
			break;
		}
		
		// Invoca al parser y despachador de comandos
		muestroRetorno(parser(texto));
	}
	
	return 0;
}
