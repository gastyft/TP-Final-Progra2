#ifndef INGRESO_DE_LABORATORIO_H_INCLUDED
#define INGRESO_DE_LABORATORIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURAS

typedef struct _nodoPracticas
{
    int numeroIngresoPractica;
    int numeroPractica;
    char resultado[40];
    struct nodoPracticas * siguiente;
} nodoPracticas;

typedef struct
{
    char apellido_nombre [40];
    int edad;
    int dni;
    char direccion[30];
    char telefono[15];
    int eliminado;
}stPaciente;

typedef struct _arbolPaciente
{
    stPaciente paciente;
    struct arbolPaciente *izq;
    struct arbolPaciente *der;
    struct nodoIngreso *ingreso;
}arbolPaciente;

typedef struct
{
    int numeroIngreso;///dato unico y autoincremental
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dni;///dato unico
    int matriculaProfesional;
    int eliminado;
} ingresosLaboratorio;

typedef struct _nodoLab
{
    ingresosLaboratorio labo;
    struct nodoLab * siguiente;
    nodoPracticasporingreso * lista;
} nodoLab;

///PROTOTIPADOS
nodoLab * inic_lista();
nodoLab * crear_nodo_lab(ingresosLaboratorio laboratorio);
nodoLab * agregar_al_principio (ingresosLaboratorio laboratorio,nodoLab * listaLab);
//stpaciente validacion_dni_existente(char nombreArchivo[],stpaciente paciente,int *flag);
ingresosLaboratorio carga_un_laboratorio();
void baja_laboratorio (char archivo[]);
int cantidad_de_ingresos (char archivo[]);
void muestra_un_laboratorio(ingresosLaboratorio laboratorio);
void menu_baja_laboratorio(char nombrearchivo[]);
void baja_laboratorio_por_ingreso(char nombrearchivo []);
void alta_laboratorio_por_ingreso(char nombrearchivo []);
void alta_laboratorio_por_dni(char nombrearchivo []);


#endif // INGRESO_DE_LABORATORIO_H_INCLUDED
