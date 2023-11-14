#ifndef INGRESO_DE_LABORATORIO_H_INCLUDED
#define INGRESO_DE_LABORATORIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27


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

/////PROTOTIPADOS
//nodoLab * inic_lista();
//nodoLab * crear_nodo_lab(ingresosLaboratorio laboratorio);
//nodoLab * agregar_al_principio (ingresosLaboratorio laboratorio,nodoLab * listaLab);
////stpaciente validacion_dni_existente(char nombreArchivo[],stpaciente paciente,int *flag);
//ingresosLaboratorio carga_un_laboratorio();
//void baja_laboratorio (char archivo[]);
//int cantidad_de_ingresos (char archivo[]);
//void muestra_un_laboratorio(ingresosLaboratorio laboratorio);
//void menu_baja_laboratorio(char nombrearchivo[]);
//void baja_laboratorio_por_ingreso(char nombrearchivo []);
//void alta_laboratorio_por_ingreso(char nombrearchivo []);
//void alta_laboratorio_por_dni(char nombrearchivo []);
//
 #endif // INGRESO_DE_LABORATORIO_H_INCLUDED
