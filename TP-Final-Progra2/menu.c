#include "menu.h"
#include "Goto_xy.h"

///INGRESAR AL LOGIN Y DEPENDIENDO DE QUE TIPO SEA EL USER DARLE
///MENUS DE TECNICO EMPLEADO O ADMIN CON SUS FUNCIONALIDADES ACOTADAS POR PERFIL EXCEPTO EL ADMIN QUE ES EL QUE PUEDE HACER TODO.

void carga_puntos()  /// APERTURA DE PROYECTO
{
    int i,j;
    int num_puntos = 2;
    for (i = 0; i < 8; i++)
    {
        // Imprimir los puntos con movimiento

        for (j = 0; j < num_puntos; j++)
        {
            printf("..");
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
    system("cls");
}



void menuprincipal()
{
    char opc;
    color;
    printf("Abriendo APP, espere");
    carga_puntos();
    do
    {
        system("cls");
        consolaPrincipal();
        printf("\n");
        fflush(stdin);
        opc = getch();
        switch(opc)
        {
        case 49:
            system("cls");

            system("pause");
            break;
        case 50:
            system("cls");

            system("pause");
            break;
        case 51:
            system("cls");

            system("pause");
            break;

        case ESC:
            printf("Saliendo del programa...");
            carga_puntos();
            system("cls");
            firma();
            break;
        default:
            printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
            system("pause");
            break;

        }
    }
    while( opc != ESC);

}
void consolaPrincipal()
{

    printf("\n\n%c",201);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);
    printf("%c%59c\n",186,186);
    printf("%c%36s%23c\n",186,"UTN medic SALUD ",186);
    printf("%c%59c\n",186,186);
    printf("%c",204);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }
    printf("%c \n",185);
    printf("%c%59c\n",186,186);
    printf("%c%15s%44c\n",186,"Usuario:",186);
    printf("%c%59c\n",186,186);
    printf("%c%59c\n",186,186);
    printf("%c%15s%44c\n",186,"Contrasenia:",186);
    printf("%c%59c\n",186,186);
    printf("%c%59c\n",186,186);
    printf("%c",204);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }

    printf("%c \n",185);
    printf("%c%59c\n",186,186);
    printf("%c%15s%44c\n",186,"ESC   SALIR",186);
    printf("%c%59c\n",186,186);
    printf("%c",200);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);


}


void menu_contenedor()
{

    int isLoggedIn=-1;
    int cont= 3;
    char opcion=0;




do {
    isLoggedIn = login();

    if (isLoggedIn == -1) {
        cont--;
        if (cont <1) {
            printf("Ha alcanzado el limite de intentos. Saliendo del programa.\n");
                break;
        }
        printf("LE QUEDAN %d INTENTOS\n", cont);
/// BLOQUEAR PASAR DE ELIMINADO A 1 si no ingresa bien

        printf("Intente nuevamente o presione ESC para cerrar el programa\n");
        fflush(stdin);

        opcion = getch();
        if (opcion == ESC) {
            break;
        }
    }
system("cls");
} while (isLoggedIn == -1);


            do
            {
                if(isLoggedIn==1)
                {
                    printf("1- MENU EMPLEADOS \n");
                    printf("ESC LogOut \n");
                    char op1=0;
                    fflush(stdin);
                    op1=getch();

                    switch(op1){

                    case '1':
                        menu_empleados(isLoggedIn);
                        break;
                        ///OTROS CASE DE LOS MENUS DE LAS DEMAS ESTRUCTURAS;

                    case 27:
                        isLoggedIn=log_out();
                        break;

                    default:
                        printf("Ingreso una opcion incorrecta  \n");
                          printf("1- MENU EMPLEADOS \n");
                    printf("ESC LogOut \n");
                        fflush(stdin);
                        op1=getch();

                        break;
                    }

///menu pacientes
///menu practicas
///menu labos
///TODAS LAS FUNCIONES HABILITADAS
///ESC PARA SALIR DE LA SESION


                }
                if(isLoggedIn==2)
                {
///menu practicas para tecnico
///ESC PARA SALIR DE LA SESION
                }
                if(isLoggedIn==3)
                {
///menu pacientes
///menu practicas
///menu labos
///ESC PARA SALIR DE LA SESION
                }


                ///EN ALGUN LADO OPCION LOGOUT;
                ///DONDE ASIGNA ISLOGGEDIN A -1
            }
            while(isLoggedIn!=-1);



        //if(isLoggedin==-1)
        system("cls");
  printf("HA SALIDO DE LA SESION \n");
  usleep(1000000);
//    system("cls");



system("cls");
printf("Cerrando programa");
carga_puntos();
cierre_firma();

}
