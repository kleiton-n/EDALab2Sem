#include "libs.h"

TipoRetorno InsertarLineaParser(Parametros param){
	return InsertarLinea();
}

command commands[1] = { // posibilidad de convertir en lista para obtener el tamanio
	{(Cadena)"InsertarLinea", InsertarLineaParser, 0}
};

#define CANT_COMANDOS 1

TipoRetorno parser(Cadena lineaEntrada) {
	
	Cadena separador = strtok(lineaEntrada, DELIMITADORES);
	Cadena nombreCmd = separador;
	
	// Buscamos el comando en la tabla
	int indexComando = -1;
//	cout << CANT_COMANDOS;
	getchar();
	getchar();
	for(int i = 0; i < CANT_COMANDOS; i++){
		if (strcmp(minusculas(separador), minusculas(commands[i].nombre)) == 0) {
			indexComando = i;
			break;
		}
	}
	
	if (indexComando == -1){
		cout << "Comando no reconocido: " << nombreCmd << endl;
		return ERRORES;
	}
	
	Cadena params[3] = {NULL, NULL, NULL};
	int cantParamsLeidos = 0;
	
	separador = strtok(NULL, DELIMITADORES);
	while(separador != NULL && cantParamsLeidos < 3){
		params[cantParamsLeidos] = separador;
		cantParamsLeidos++;
		separador = strtok(NULL, DELIMITADORES);
	}
	
	if (cantParamsLeidos < commands[indexComando].cantParametros) {
		cout << "Error: Cantidad insuficiente de parametros para " << nombreCmd << endl;
		return ERRORES;
	}
	
	Parametros p;
	p.param1 = params[1];
	p.param2 = params[2];
	p.param3 = params[3];
	
	return commands[indexComando].funcion(p);
}
