#include <stdio.h>
#include <stdlib.h>
#define color system("COLOR B")
#include "menu.h"



int main()
{
    color;
    char archivo_empleados[]="archivo_empleados";
    ///crear_usuario(archivo_empleados);
  ///  mostrar_empleados(archivo_empleados);
   /// system("pause");
    ///modificar_empleado(archivo_empleados);


    int num=login(archivo_empleados);
    if(num==1)
    printf("EL USUARIO ES UN ADMIN \n");


    if(num==2)
    printf("EL USUARIO ES UN TECNICO \n");

    if(num==3)
    printf("EL USUARIO ES UN empleado \n");

   if(num!=-1){
    num=log_out();
   }
   system("pause");
  if(num==-1)
   printf("HA SALIDO DE LA SESION \n");

    return 0;
}
