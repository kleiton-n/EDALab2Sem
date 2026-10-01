#include "libs.h"

TipoRetorno InsertarLineaParser(Parametros param){
	return InsertarLinea();
}

command commands[] = {
	{"InsertarLinea", InsertarLineaParser, 0}
};

#define CANT_COMANDOS (sizeof(commands) / sizeof(commands[0]))

TipoRetorno parser(char* lineaEntrada) {
	char nombreCmd[64];
	char arg1[64] = {0}, arg2[64] = {0}, arg3[64] = {0};
	
	// Intentamos leer el nombre del comando y hasta 3 argumentos
	int leidos = sscanf(lineaEntrada, "%s %s %s %s", nombreCmd, arg1, arg2, arg3);
	
	if (leidos < 1) {
		return ERRORR; // Línea vacía
	}
	
	int cantArgsIngresados = leidos - 1; // Descontamos el nombre del comando
	
	// Buscamos el comando en la tabla
	for (size_t i = 0; i < CANT_COMANDOS; i++) {
		if (strcmp(nombreCmd, commands[i].nombre) == 0) {
			
			// VALIDACIÓN: Verificamos que se ingresaron los parámetros necesarios
			if (cantArgsIngresados < commands[i].cantParametros) {
				printf("Error: El comando '%s' requiere %d parametro(s).\n", 
					   commands[i].nombre, commands[i].cantParametros);
				return ERRORR;
			}
			
			// Mapeamos los strings leídos a la estructura Parametros
			Parametros p;
			p.pos1 = 0;
			p.pos2 = 0;
			p.texto = NULL;
			
			// Mapeo según la cantidad esperada por el comando
			if (commands[i].cantParametros == 1) {
				if (esNumero(arg1)) {
					p.pos1 = (Posicion)atoi(arg1); // Ej: BorrarLinea(1)
				} else {
					p.texto = arg1;               // Ej: BorrarPalabraDiccionario("hola")
				}
			} 
			else if (commands[i].cantParametros == 2) {
				// Ej: BorrarPalabra(1, 2) o BorrarocurrenciasPalabraEnLinea(1, "hola")
				p.pos1 = (Posicion)atoi(arg1);
				if (esNumero(arg2)) {
					p.pos2 = (Posicion)atoi(arg2);
				} else {
					p.texto = arg2;
				}
			} 
			else if (commands[i].cantParametros == 3) {
				// Ej: InsertarPalabra(1, 2, "hola")
				p.pos1 = (Posicion)atoi(arg1);
				p.pos2 = (Posicion)atoi(arg2);
				p.texto = arg3;
			}
			
			// Una vez validados y armados los parámetros, ejecutamos la función
			return commands[i].funcion(p);
		}
	}
	
	printf("Comando no reconocido.\n");
	return ERRORR;
}
