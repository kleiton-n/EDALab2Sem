#include "libs.h"

int esNumero(const char* str) {
	if (str == NULL || *str == '\0') return 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') return 0;
	}
	return 1;
}

void pausa(){
	cout << endl << endl << "Presione [ENTER] para continuar";
	getchar();
}
	
char minuscula(char c){
	// si el caracter está en mayuscula lo pasa a minusculas utilizando los valores ASCII
	if(c >= 65 && c <= 90){
		return c+32;
	}
	return c;
}

bool confirma(){
	char conf;
	do{
		cout << endl << "[Desea confirmar la accion S/N]: ";
		cin >> conf;
		purge();
		conf = minuscula(conf);
		if(conf != 'n' && conf != 's') cout << endl << "[(ERROR) vuelva a ingresar S/N]" << endl;
	} while(conf != 'n' && conf != 's');
	return conf == 's';
}

int ingOpcion(int max){
	int opcion = 0;
	
	do{
		cout << endl << endl << "Ingrese una opcion (1-" << max << "): ";
		cin >> opcion;
		purge();
		if (opcion < 1 || opcion > max) cout << endl << "Opcion Incorrecta. Vuelva a intentarlo. Debe de ingresar un valor entre 1 y " << max << ".";
	} while(opcion < 1 || opcion > max);
	return opcion;
}
	
Cadena minusculas(Cadena cad){  // tiene leak de memoria
	if (cad == NULL){
		return NULL;
	}
	int len = strlen(cad);
	Cadena ncad = new char[len+1];
	for(int i = 0; i < len; i++){
		ncad[i] = minuscula(cad[i]);
	}
	ncad[len] = '\0';
	return ncad;
}
	
void clear(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void purge(){
	#ifdef _WIN32
		fflush(stdin);
	#else
		__fpurge(stdin);
	#endif
}

void wait(int segundos){
	#ifdef _WIN32
		Sleep(segundos*1000);
	#else
		sleep(segundos);
	#endif
}
