#ifndef PRACTICAS_X_INGRESO_H_INCLUDED
#define PRACTICAS_X_INGRESO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "practica_de_laboratorio.h"
#include <conio.h>
#define ESC 27
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#define ESC 27
#define nombrePracticasxIngreso "Practicas.bin"
#include "ingreso_de_laboratorio.h"
#include "menu.h"


///ESTRUCTURAS
typedef struct
{
    int nroIngreso;
    int nroPractica;
    char resultado [40];
    int eliminado;
}pracXingreso;


typedef struct nodo_simple_pxi{

    struct nodo_simple_pxi * siguiente;
    pracXingreso dato;

} nodo_simple_pxi;

///PROTOTIPADO

pracXingreso cargar_individual_x_ingreso (int nroIngreso);
nodo_simple_pxi * inic_lista();
nodo_simple_pxi * agregar_ppio(nodo_simple_pxi * lista, nodo_simple_pxi * nuevo);
nodo_simple_pxi * crear_nodo_doble (pracXingreso dato);
nodo_simple_pxi * buscar_ultimo_nodo_recursivo (nodo_simple_pxi * lista);

void muestra_lista (nodo_simple_pxi *lista);
nodo_simple_pxi * buscar_nodo(nodo_simple_pxi * lista, int dato);
void muestra_individual (pracXingreso a);
void muestra_lista_desde_archivo (const char * archivo_practicas, nodo_simple_pxi * lista);
nodo_simple_pxi * crear_nodo_pxi (pracXingreso dato);
///FUNCIONES CRUD
nodo_simple_pxi *modifica_un_nodo_prac_x_ingreso_admin(nodo_simple_pxi *aModificar);
nodo_simple_pxi *cargar_practicas_x_ingreso_tecnico(nodo_simple_pxi *lista) ;
void baja_de_pxi(pracXingreso eliminar);
nodo_simple_pxi *alta_logica_archivo(nodo_simple_pxi *lista,int nroIngreso);

nodo_simple_pxi *modifica_un_nodo_prac_x_ingreso_tecnico(nodo_simple_pxi *aModificar);
pracXingreso cargar_individual_administrativo ();
void carga_alta_pracXingreso(pracXingreso a);
void muestra_individual_prac_x_ingreso (pracXingreso a);
struct arbolPaciente* cargar_arbol_nuevo_practica_x_ingreso(struct arbolPaciente *arbol);
struct arbolPaciente *modificar_practicas_x_ingreso_incorpora_arbol( struct arbolPaciente*arbol);
struct arbolPaciente * menu_practicas_x_ingreso( struct arbolPaciente *arbol);
struct arbolPaciente *cargar_resultado_practicas_x_ingreso_incorpora_arbol_tecnico(struct arbolPaciente*arbol);
void muestra_individual_con_nombre (pracXingreso a);
void carga_alta_pracXingreso(pracXingreso a);

#endif // PRACTICAS_X_INGRESO_H_INCLUDED
