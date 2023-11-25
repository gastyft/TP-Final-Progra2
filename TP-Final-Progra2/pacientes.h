#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

#include "ingreso_de_laboratorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Goto_xy.h"
#include "practicas_x_ingreso.h"
#define ESC 27

struct nodoLab;


///ESTRUCTURAS
typedef struct {
char Apellido_nombre[40];
 int edad;
 int dni;
 char direccion[30];
 char telefono[15];
 int eliminado;

}stPaciente;

typedef struct arbolPaciente {

 stPaciente paciente;
 struct arbolPaciente *izq;
 struct arbolPaciente *der;
 struct nodoLab *ingresos;

}arbolPaciente;


///PROTOTIPADO
arbolPaciente* cargar_arbol_pacientes(char nombre_paciente[],arbolPaciente *arbol); /// CARGA EL ARBOL AL INICIO DEL PROGRAMA
int validar(char numero[]);
int validar_nombre(const char nombre[]);
int validar_char(char Letras[]);

struct nodoLab *buscar_ingreso_porNumero(arbolPaciente *arbol,int dato); /// BUSCA EL INGRESO EN EL ARBOL Y DEVUELVE EL NODO

arbolPaciente* inic_arbol();
arbolPaciente* crear_nodo_arbol(stPaciente dato);
arbolPaciente *agregar_paciente(arbolPaciente *lista,arbolPaciente *nuevo);
arbolPaciente * buscar_paciente(arbolPaciente *arbol,int dato);
arbolPaciente *crear_paciente(char nombre[20],arbolPaciente *arbol);
int crear_dni(arbolPaciente *arbol);
int crear_edad();
void cargar_Archivo_paciente(char nombre[],stPaciente a);
void mostrar_pacientes(stPaciente a, int i);
void mostrar_paciente_porapellido(arbolPaciente *arbol);
int posmenor(stPaciente a[],int validos,int pos);
void copiar_arbol_arreglo(stPaciente a[] ,arbolPaciente *arbol, int *i, int validos);
void ordenar_seleccion(stPaciente a[],int validos);
void mostrar_paciente(stPaciente a);
void mostrar_pacientes_arbol(arbolPaciente *arbol);
arbolPaciente * modificar_paciente_buscar(char nombre_paciente[],arbolPaciente * arbol);
stPaciente modificar_paciente(stPaciente a,arbolPaciente *arbol);
void modificar_archivo_pacientes(char nombre[],int dni_buscar,stPaciente paciente);
arbolPaciente* baja_paciente(char nombre_paciente[],arbolPaciente *arbol);
int contar_nodos(arbolPaciente *arbol);
void consulta_paciente(arbolPaciente *arbol);
void listado_ingresos_dePaciente(arbolPaciente *arbol);

arbolPaciente* cargar_arbol_ingresos(arbolPaciente *arbol);  /// CARGA LOS INGRESOS Y PRACTICAS AL INICIO DEL PROGRAMA
void consulta_ingreso_particular(arbolPaciente *arbol);
arbolPaciente* menu_pacientes(char nombre_pacientes[],arbolPaciente *arbol);
arbolPaciente *menu_pacientes_labo(char nombre_pacientes[],arbolPaciente *arbol);
void mostrar_ingresos();
int validar_edad(char numero[]);




//void mostrar_ingreso (ingresosLaboratorio a, int i);

#endif // PACIENTES_H_INCLUDED
