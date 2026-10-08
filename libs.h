#ifndef LIBS_H
#define LIBS_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string.h>
#ifdef _WIN32
	//librerias de Windows
	#include <windows.h>
#else
	//equivalentes en UNIX
	#include <stdio_ext.h>
#endif

//Arriba de esta linea ingresar otras librerias
//-----------------------------------------------------------
using namespace std;
#include "definiciones.h"
#include "prototiposTools.h"
//-----------------------------------------------------------
//Abajo de esta linea ingresar includes del proyecto

#include "prototiposF.h"
#include "prototiposR.h"
#include "Parser.h"
#endif
