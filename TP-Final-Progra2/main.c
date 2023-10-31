#include <stdio.h>
#include <stdlib.h>

#include "menu.h"


int main()
{
   /// menuprincipal();
    color;
    char archivo_empleados[]="archivo_empleados";
   /// crear_usuario(archivo_empleados);
 mostrar_empleados(archivo_empleados);
     system("pause");
   modificar_empleado(archivo_empleados);

    int isLoggedin=login(archivo_empleados);
    if(isLoggedin==1)
    printf("EL USUARIO ES UN ADMIN \n");

/**

PARA EL MENU
MIENTRAS NO HAGA LOGOUT ENTONCES ESE MENU DE USUARIO especifico.
*/

 while(isLoggedin==1){


      printf("EL USUARIO ES EL ADMIN \n");
        printf("DESEA SEGUIR \n");
           char o=0;
fflush(stdin);
o=getch();
   if(o==ENTER){
    isLoggedin=log_out();
}

}
 while(isLoggedin==2){


      printf("EL USUARIO ES UN TECNICO \n");
        printf("DESEA SEGUIR \n");
           char o=0;
fflush(stdin);
o=getch();
   if(o==ENTER){
    isLoggedin=log_out();
}

}

 while(isLoggedin==3){


      printf("EL USUARIO ES UN EMPLEADO \n");
        printf("DESEA SEGUIR \n");
           char o=0;
fflush(stdin);
o=getch();
   if(o==ENTER){
    isLoggedin=log_out();
}

}
  if(isLoggedin==-1)
    system("cls");

   printf("HA SALIDO DE LA SESION \n");



   /// FUNCIONES PACIENTES

//    char dni[10];
//    char archi_pacientes[] = "pacientes.bin";
//    arbolPaciente *arbol;
//    arbol = inic_arbol();
//    arbol = cargar_arbol_pacientes(archi_pacientes,arbol);
//    arbol = crear_paciente(archi_pacientes,arbol);
//    mostrar_pacientes(arbol);
//   arbol= modificar_paciente_buscar(archi_pacientes,arbol);
//   mostrar_pacientes(arbol);
    return 0;
}
