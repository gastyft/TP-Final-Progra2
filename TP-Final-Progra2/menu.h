#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include "empleado_de_laboratorio.h"
#include "pacientes.h"
#include "practicas_x_ingreso.h"
#include "practica_de_laboratorio.h"
#include "ingreso_laboratorio_nuevo.h"
#include "pacientes.h"
#include "Firma.h"
#include "Goto_xy.h"
#include <windows.h>
#define ENTER 13
#define ESC 27
#define color system("COLOR B")
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW   "\x1b[33m"
#define COLOR_PURPLE "\x1b[35m"
#define COLOR_BLUE    "\x1b[36m"
#define COLOR_WHITE  "\x1b[38m"
///PROTOTIPADO
void consola_login();
void consola_vacia();
void menuprincipal();
void menu_contenedor();
void apertura_programa();
void consola_pacientes();
void consola_pacientes();
void setConsoleColor(int text, int background);


#endif // MENU_H_INCLUDED
