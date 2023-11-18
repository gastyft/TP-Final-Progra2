#ifndef EMPLEADO_DE_LABORATORIO_H_INCLUDED
#define EMPLEADO_DE_LABORATORIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <ctype.h>
#include "Goto_xy.h"
#define ESC 27
#define ARCH_EMPLEADO "Empleado.bin"
#include "menu.h"

///ESTRUCTURAS

typedef struct {
int DNI;
char apellido_y_nombre[40];
char usuario[20];
char contrasenia[20];
char perfil[20];
int eliminado;

}empleado_de_laboratorio;




/// ADMIN con prioridad 1 y este puede crear usuarios con prioridad 2 o 3. Solo el admin puede crear nuevos usuarios.
///Para administradores(admin con todas las funciones) Rol 1
///Para profesionales del Laboratorio (bioquímicos o técnicos) Rol 2
///Para administrativos del Laboratorio(empleado) Rol 3

///CREAR UN LOGIN Y QUE ESTE SEA TRANSFERIDO EN TODOS LOS COMPONENTES, QUE MEDIANTE IF EN EL MENU SE LE VAN A HABILITAR LAS OPCIONES
/// DEPENDIENDO DE QUE TIPO DE USUARIO SEA.
///CREAR UN USUARIO UNICO QUE SE LLAME ADMIN CON CONTRASEÑA ADMIN CUYO MENU POSEA PODER ABSOLUTO SOBRE TODO.


///PROTOTIPADO
empleado_de_laboratorio validaciones_nombre_usuario( empleado_de_laboratorio empleado);
empleado_de_laboratorio validaciones( empleado_de_laboratorio empleado,char num[20],int *flag);
void crear_usuario();
void mostrar_1_empleado(empleado_de_laboratorio empleado);
void mostrar_empleados();
void mostrar_empleados_inactivos();
void mostrar_empleados_activos();
void mostrar_empleado_por_apellido();
  void mostrar_empleados_lista(empleado_de_laboratorio emp, int i);
void dar_baja_empleado();
void dar_alta_empleado_logico( empleado_de_laboratorio empleado);
void modificar_empleado();
void menu_empleados(int isLoggedin);
int login( );
int log_out();
int validar_dni_empleado(char numero[]);
void funcion_about_us();
void imprimir_con_puntos(const char *parrafo);
void menu_altas_usuarios();
void ordenar_seleccion_empleado(empleado_de_laboratorio emp[],int validos);
int posmenor_empleado(empleado_de_laboratorio emp[],int validos,int pos);
void mostrar_empleado_por_apellido();
void menu_muestra_empleados();
int validar_tipo_perfil(char numero[]);
#endif // EMPLEADO_DE_LABORATORIO_H_INCLUDED
