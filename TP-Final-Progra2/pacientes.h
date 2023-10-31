#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado_de_laboratorio.h"
#define ESC 27

///ESTRUCTURAS
typedef struct {
char Apellido_nombre[40];
 int edad;
 int dni;
 char direccion[30];
 char telefono[15];
 int eliminado;

}stPaciente;

typedef struct  arbolPaciente {

 stPaciente paciente;
 struct arbolPaciente *izq;
 struct arbolPaciente *der;
 struct nodoIngreso *ingreso;

}arbolPaciente;




///PROTOTIPADO
arbolPaciente* cargar_arbol_pacientes(char nombre_paciente[],arbolPaciente *arbol);
int validar(char numero[]);
int validar_nombre(const char nombre[]);
int validar_char(char Letras[]);
arbolPaciente* inic_arbol();
arbolPaciente* crear_nodo_arbol(stPaciente dato);
arbolPaciente *agregar_paciente(arbolPaciente *lista,arbolPaciente *nuevo);
arbolPaciente * buscar_paciente(arbolPaciente *arbol,int dato);
arbolPaciente *crear_paciente(char nombre[20],arbolPaciente *arbol);
int crear_dni(arbolPaciente *arbol);
int crear_edad();
void cargar_Archivo_paciente(char nombre[],stPaciente a);

void mostrar_paciente(stPaciente a);
void mostrar_pacientes(arbolPaciente *arbol);

arbolPaciente * modificar_paciente_buscar(char nombre_paciente[],arbolPaciente * arbol);
stPaciente modificar_paciente(stPaciente a,arbolPaciente *arbol);
void modificar_archivo_pacientes(char nombre[],int dni_buscar,stPaciente paciente);




#endif // PACIENTES_H_INCLUDED
