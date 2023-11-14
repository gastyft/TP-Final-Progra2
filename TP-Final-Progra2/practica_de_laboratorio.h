#ifndef PRACTICA_DE_LABORATORIO_H_INCLUDED
#define PRACTICA_DE_LABORATORIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"
#include <ctype.h>
#define nombrePracticas "Practicas.bin"


///ESTRUCTURAS


typedef struct
{
    int nroPractica;
    char nombrePractica [30];
    int eliminado;
} practicas;


///PROTOTIPADO

void muestra_individual_practica (practicas a);
practicas cargar_practica_individual ();
int cargar_arreglo_dinamico (practicas * arreglo_practicas,int cantidad);
int redimensionar_arreglo (practicas * arreglo_practicas,int cantidad);
void cargar_archivo ();
void mostrarArchivo ();
int pasar_archivo_practicas_a_arreglo (practicas * arreglo_practicas, int * dimension);
void mostrar_arreglo(practicas* arreglo_practicas, int validos);
void dar_baja_practica(int nro_de_practica_a_validar);
void dar_alta_practica(int nro_de_practica_a_validar);
void buscar_practica_por_nombre (char practica_a_buscar[], practicas * arreglo_de_practicas,int validos,int indices [], int * cant_resultados);
void buscar_practica_por_numero(int numero_practica_a_buscar, practicas * arreglo_de_practicas, int validos);
practicas cargar_practica_individual_validacion_archivo ();
practicas practicaNula();
void modificar_nombre_practica(char nombre_buscar[], practicas * arreglo_practicas, int validos);
void modificar_nombre_practica_archivo (char nuevo_nombre[], practicas * arreglo_practicas, int i);
practicas validar_nro_practica_exista(practicas *arr,int validos,int nroPractica);
practicas validacion_nombre_practica(practicas practicaAvalidar);

#endif // PRACTICA_DE_LABORATORIO_H_INCLUDED
