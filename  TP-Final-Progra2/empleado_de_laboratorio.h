#ifndef EMPLEADO_DE_LABORATORIO_H_INCLUDED
#define EMPLEADO_DE_LABORATORIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <ctype.h>
#define ESC 27
///ESTRUCTURAS

typedef struct {
int DNI;
char apellido_y_nombre[40];
char usuario[20];
char contrasenia[20];
char perfil[20];
int emliminado;

}empleado_de_laboratorio;




/// ADMIN con prioridad 1 y este puede crear usuarios con prioridad 2 o 3. Solo el admin puede crear nuevos usuarios.
///Para administradores(admin con todas las funciones)
///Para profesionales del Laboratorio (bioquímicos o técnicos)
///Para administrativos del Laboratorio(empleado)

///CREAR UN LOGIN Y QUE ESTE SEA TRANSFERIDO EN TODOS LOS COMPONENTES, QUE MEDIANTE IF EN EL MENU SE LE VAN A HABILITAR LAS OPCIONES
/// DEPENDIENDO DE QUE TIPO DE USUARIO SEA.
///CREAR UN USUARIO UNICO QUE SE LLAME ADMIN CON CONTRASEÑA ADMIN CUYO MENU POSEA PODER ABSOLUTO SOBRE TODO.


///PROTOTIPADO
empleado_de_laboratorio validaciones_nombre_usuario(char nombreArchivo[],empleado_de_laboratorio empleado);
empleado_de_laboratorio validaciones(char nombreArchivo[],empleado_de_laboratorio empleado,char num[20],int *flag);
void crear_usuario(char archivo_empleados[]);
void mostrar_1_empleado(empleado_de_laboratorio empleado);
void mostrar_empleados(char archivo_empleados[]);
void dar_baja_empleado(char archivo_empleados[],empleado_de_laboratorio empleado);
void dar_alta_empleado_logico(char archivo_empleados[],empleado_de_laboratorio empleado);
void modificar_empleado(char archivo_empleados[]);
int login(char archivo_empleados[]);
int log_out();

#endif // EMPLEADO_DE_LABORATORIO_H_INCLUDED
