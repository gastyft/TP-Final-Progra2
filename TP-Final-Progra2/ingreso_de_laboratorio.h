#ifndef INGRESO_DE_LABORATORIO_H_INCLUDED
#define INGRESO_DE_LABORATORIO_H_INCLUDED

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
    char fechaIngreso[11];
    char fechaRetiro[11];
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

void busqueda_filtro_fecha(); /// BUSCA LOS INGRESOS POR FECHA
int compararFechas(const char *fecha1, const char *fecha2);  /// BUSCA EL RANGO DE LA FECHA

#endif // INGRESO_DE_LABORATORIO_H_INCLUDED
