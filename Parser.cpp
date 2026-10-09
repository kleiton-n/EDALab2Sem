#include "libs.h"

bool esTexto(Cadena c){
	return c[0] == '"';
}
	
bool esNumero(Cadena c) {
	if (c == NULL || *c == '\0') return false;
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] < '0' || c[i] > '9') return false;
	}
	return true;
}

TipoRetorno InsertarLineaParser(Parametros param){
	return InsertarLinea();
}
	
TipoRetorno ImprimirTextoParser(Parametros param){
	return ImprimirTexto();
}

TipoRetorno InsertarPalabraParser(Parametros param){ // preguntar al profe por parametros si tiene leak de memoria
	if (!esNumero(param.param1)){
		cout << "el primer parametro para InsertarPalabra debe de ser numerico e ingreso: " << param.param1 << endl;
		return ERRORES;
	}	
	if (!esNumero(param.param2)){
		cout << "el segundo parametro para InsertarPalabra debe de ser numerico e ingreso: " << param.param2 << endl;
		return ERRORES;
	}	
	if (!esTexto(param.param3)){
		cout << "el tercer parametro para InsertarPalabra debe de ser texto e ingreso: " << param.param3 << endl;
		cout << "los parametros de tipo texto deben de ser ingresado entre \"\"" << endl;
		return ERRORES;
	}
	param.param3 = strtok(param.param3, "\"");
	return InsertarPalabra(atoi(param.param1), atoi(param.param2), param.param3);
}

command commands[] = { // posibilidad de convertir en lista para obtener el tamanio
	{(Cadena)"InsertarLinea", InsertarLineaParser, 0},
	{(Cadena)"ImprimirTexto", ImprimirTextoParser, 0},
	{(Cadena)"InsertarPalabra", InsertarPalabraParser, 3}
};

#define CANT_COMANDOS 3

TipoRetorno parser(Cadena lineaEntrada) {
	
	Cadena separador = strtok(lineaEntrada, DELIMITADORES);
	Cadena nombreCmd = separador;
	
	// Buscamos el comando en la tabla
	int indexComando = -1;
	for(int i = 0; i < CANT_COMANDOS; i++){
		if (strcmp(minusculas(separador), minusculas(commands[i].nombre)) == 0) { // cmp cambiar por comparador unario de caracters para no genearar leack de memoria
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
	p.param1 = params[0];
	p.param2 = params[1];
	p.param3 = params[2];
	return commands[indexComando].funcion(p);
}
