#ifndef PRACTICAS_X_INGRESO_H_INCLUDED
#define PRACTICAS_X_INGRESO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "practica_de_laboratorio.h"
#include <conio.h>
#define ESC 27
#include <malloc.h>




///ESTRUCTURAS
typedef struct
{
    int nroIngreso;
    int nroPractica;
    char resultado [40];
}pracXingreso;


typedef struct _nodo_simple_pxi{

    struct _nodo_simple_pxi * siguiente;
    pracXingreso dato;

} nodo_simple_pxi;
///PROTOTIPADO

pracXingreso cargar_individual ();
nodo_simple_pxi * inic_lista();
nodo_simple_pxi * agregar_ppio(nodo_simple_pxi * lista, nodo_simple_pxi * nuevo);
nodo_simple_pxi * crear_nodo_doble (pracXingreso dato);
nodo_simple_pxi * buscar_ultimo_nodo_recursivo (nodo_simple_pxi * lista);
nodo_simple_pxi * agregar_final (nodo_simple_pxi*,nodo_simple_pxi*);
nodo_simple_pxi * agregar_orden (nodo_simple_pxi *,nodo_simple_pxi*);
nodo_simple_pxi * cargar_lista (nodo_simple_pxi*);
void muestra_lista (nodo_simple_pxi*);
nodo_simple_pxi * borrar_nodo_foble (nodo_simple_pxi * lista, int dato);
nodo_simple_pxi * buscar_nodo(nodo_simple_pxi * lista, int dato);
void muestra_individual (pracXingreso a);
void muestra_lista_desde_archivo (const char * archivo_practicas, nodo_simple_pxi * lista);



#endif // PRACTICAS_X_INGRESO_H_INCLUDED
