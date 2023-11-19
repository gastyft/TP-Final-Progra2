#ifndef INGRESO_LABORATORIO_NUEVO_H_INCLUDED
#define INGRESO_LABORATORIO_NUEVO_H_INCLUDED
#include "pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define ESC 27
#define nombrearchivo "Ingresos.bin"

struct arbolPaciente;

typedef struct
{
    int numeroIngreso;///dato unico y autoincremental
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dni;///dato unico
    int matriculaProfesional;
    int eliminado;
} ingresosLaboratorio;

typedef struct nodoLab
{
    ingresosLaboratorio labo;
    struct nodoLab * siguiente;
     struct nodo_simple_pxi* listaIngresoPrac;
} nodoLab;


typedef struct
{
    int dia;
    int mes;
    int anio;
} stFecha;

typedef struct nodoPracticasxingreso
{
    int numeroIngresoPractica;
    int numeroPractica;
    char resultado[40];
    struct nodoPracticasxingreso  * siguiente;
} nodoPracticasxingreso;



typedef struct
{
    int nrodeIngreso;
    int nropractica;
    char Resultado [40];
} Practicaporingreso;

//PROTOTIPADOS

///funciones de listas (ingresos laboratorio)
nodoLab * crear_nodo_lab(ingresosLaboratorio laboratorio);
nodoLab * agregar_al_principio (nodoLab * listaLab,nodoLab *nuevo);


///carga
ingresosLaboratorio carga_un_ingreso_laboratorio(int dni);
///muestra
void muestra_un_laboratorio(ingresosLaboratorio laboratorio);
///validaciones
ingresosLaboratorio asignacion_de_numero_de_ingreso (ingresosLaboratorio laboratorio);
int validacion_matricula();
int validacion_para_cantidad_de_ingresos ();
ingresosLaboratorio validacion_fecha_ingreso(ingresosLaboratorio laboratorio);
ingresosLaboratorio validacion_fecha_retiro(ingresosLaboratorio laboratorio);
///Cambia estado en lista
void cambiar_estado_eliminado (int dniabuscar, int flag);
// struct arbolPaciente * cambiar_estado_eliminado_lista(struct arbolPaciente *arbol,int nroingreso,int dni,int flag);
struct  arbolPaciente* menu_ingresos_laboratorio (struct  arbolPaciente * arbol);

void menu_modificacion_ingresos_laboratorio(struct arbolPaciente * arbol);
nodoLab * cambiar_estado_eliminado_lista(struct arbolPaciente *arbol,int nroingreso,int dni,int flag);
void menu_consulta_ingresos_laboratorio(struct arbolPaciente * arbol);
///pregunta
int retorna_dni();
///alta y baja
struct arbolPaciente * alta_ingresos_laboratorio(struct arbolPaciente * arbol);
struct arbolPaciente * baja_ingresos_laboratorio(struct arbolPaciente * arbol);
struct arbolPaciente * alta_de_ingreso_por_numero(struct arbolPaciente * arbol);
int verificar_existencia_nroingreso_alta (int nroingresoabuscar,int * flag);
///consulta
void consulta_por_numero_de_ingreso(struct arbolPaciente *arbol);
void consulta_por_dni(struct arbolPaciente * arbol);


 void mostrar_ingreso (ingresosLaboratorio a, int i);
ingresosLaboratorio validacion_modificacion_ingreso(ingresosLaboratorio laboratorio);
ingresosLaboratorio validacion_modificacion_retiro(ingresosLaboratorio laboratorio);
#endif // INGRESO_LABORATORIO_NUEVO_H_INCLUDED
