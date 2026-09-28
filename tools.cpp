#include "libs.h"

void pausa(){
	cout << endl << endl << "Presione [ENTER] para continuar";
	getchar();
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

char minuscula(char c){
	// si el caracter está en mayuscula lo pasa a minusculas utilizando los valores ASCII
	if(c >= 65 && c <= 90){
		return c+32;
	}
	return c;
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
