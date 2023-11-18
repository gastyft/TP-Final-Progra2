#include "menu.h"


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


// NO SE USA
//void menuprincipal()
//{
//    char opc;
//
//    printf("Abriendo APP, espere");
//    carga_puntos();
//    do
//    {
//        system("cls");
/////        consolaPrincipal();
//        printf("\n");
//        fflush(stdin);
//        opc = getch();
//        switch(opc)
//        {
//        case 49:
//            system("cls");
//
//            system("pause");
//            break;
//        case 50:
//            system("cls");
//
//            system("pause");
//            break;
//        case 51:
//            system("cls");
//
//            system("pause");
//            break;
//
//        case ESC:
//            printf("Saliendo del programa...");
//            carga_puntos();
//            system("cls");
//            firma();
//            break;
//        default:
//            printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
//            system("pause");
//            break;
//
//        }
//    }
//    while( opc != ESC);
//
//}
void consola_login()
{
    color;
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
    printf("%c%15s%44c\n",186,"",186);
    printf("%c%59c\n",186,186);
    printf("%c%59c\n",186,186);
    printf("%c%15s%44c\n",186,"",186);
    printf("%c%59c\n",186,186);
    printf("%c%59c\n",186,186);
    printf("%c",204);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }

    printf("%c \n",185);
    printf("%c%59c\n",186,186);

    printf("%c%59c\n",186,186);
    printf("%c",200);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);


}

void consola_vacia()
{
    color;
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
    printf("%c%15s%44c\n",186,"",186);
    printf("%c%59c\n",186,186);
    printf("%c%59c\n",186,186);
    printf("%c%15s%44c\n",186,"",186);
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

    apertura_programa();

    arbolPaciente *arbol=inic_arbol();

    do
    {
        isLoggedIn = login();
        if (isLoggedIn == -1)
        {
            cont--;
            if (cont <1)
            {
                gotoxy(2,11);
                int contame1=0;
                printf(COLOR_YELLOW);
                printf("Ha alcanzado el limite de intentos.Saliendo del programa.\n");
                gotoxy(2,12);
                printf("ANOTATE LA CONTRASENIA LA PROXIMA\n");
                while(contame1<400)
                {
                    usleep(10000);
                    contame1++;
                }
                printf(COLOR_RESET);
                break;
            }
            gotoxy(2,8);
            printf(COLOR_RED);
            printf("LE QUEDAN %d INTENTOS\n", cont);
/// BLOQUEAR PASAR DE ELIMINADO A 1 si no ingresa bien
            gotoxy(2,9);
            printf("Intente nuevamente o presione ESC para cerrar el programa\n");
            fflush(stdin);
            printf(COLOR_RESET);
            opcion = getch();
            if (opcion == ESC)
            {
                break;
            }
        }
        system("cls");
    }
    while (isLoggedIn == -1);
///CARGA DE ESTRUCTURAS COMPUESTAS
    arbol= cargar_arbol_pacientes("pacientes.bin",arbol);
      arbol= cargar_arbol_ingresos(arbol);    ///CARGA PRACTICAS INCLUIDA EN CARGA ARBOL INGRESOS

    do
    {
        if(isLoggedIn==1) ///admin
        {
            system("cls");
            consola_vacia();
            gotoxy(21,7);
            printf("1- MENU EMPLEADOS \n");
            gotoxy(21,8);
            printf("2- MENU PACIENTES \n");
            gotoxy(21,9);
            printf("3- MENU INGRESOS LAB");
            gotoxy(21,10);
            printf("4- MENU PRACTICAS");
            gotoxy(21,11);
            printf("5- About Us");
            gotoxy(21,12);
            printf("ESC LogOut \n");



            char op1=0;
            fflush(stdin);
            op1=getch();

            switch(op1)
            {
            case '1':
                menu_empleados(isLoggedIn);
                break;
            ///OTROS CASE DE LOS MENUS DE LAS DEMAS ESTRUCTURAS;
            case '2':
                arbol= menu_pacientes("pacientes.bin", arbol);

                break;
            case '3':

                arbol=menu_ingresos_laboratorio(arbol);
                system("pause");
                break;
            case '4':

                break;
            case '5':
                system("cls");
                funcion_about_us();
                break;
            case '6':
                system("cls");

                break;
            case 27:
                isLoggedIn=log_out();
                break;
            default:
                system("cls");
                gotoxy(21,7);
                printf("Ingreso una opcion incorrecta  \n");
                int contame=0;
                while(contame<200)
                {
                    usleep(10000);
                    contame++;
                }
                system("cls");
                consola_vacia();

                gotoxy(21,7);
                printf("1- MENU EMPLEADOS \n");
                gotoxy(21,8);
                printf("2- MENU PACIENTES \n");
                gotoxy(21,9);
                printf("3- Yo tendria otro menu :) ...");
                gotoxy(21,10);
                printf("4- Yo tendria otro menu :) ...");
                gotoxy(21,11);
                printf("5- About Us");
                gotoxy(21,12);
                printf("6- Me parece una banda...");
                gotoxy(21,13);
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
        if(isLoggedIn==2) ///Tecnico o bioquimico administrativo laboratorio
        {
///menu practicas para tecnico
///ESC PARA SALIR DE LA SESION
        }
        if(isLoggedIn==3) ///empleadoo administrativo
        {
///menu pacientes empleado solo ver
///menu practicas empleado
///menu labos empleado cambiar fechas, numero matricula
///ESC PARA SALIR DE LA SESION
        }


        ///EN ALGUN LADO OPCION LOGOUT;
        ///DONDE ASIGNA ISLOGGEDIN A -1
    }
    while(isLoggedIn!=-1);



    //if(isLoggedin==-1)
    system("cls");
    color;
    printf("HA SALIDO DE LA SESION \n");
    int salid1=0;
    while(salid1<80)
    {
        usleep(10000);
        salid1++;
    }
    system("cls");
    color;
    printf("Cerrando programa");
    carga_puntos();
    cierre_firma();
}
void apertura_programa()
{
    color;

    printf("Abriendo APP, espere");
    carga_puntos();
}





void consola_pacientes()
{
    system("color b");
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
    printf("%c%8i%26s%25c\n",186,1,"Alta Paciente",186);
    printf("%c%8i%29s%22c\n",186,2,"Modificar Paciente",186);
    printf("%c%8i%28s%23c\n",186,3,"Baja de Paciente",186);
    printf("%c%8i%28s%23c\n",186,4,"Consuta Paciente",186);
    printf("%c%8i%29s%22c\n",186,5,"Listado de ingreso",186);
    printf("%c%8i%30s%21c\n",186,6,"Consulta de ingreso",186);
    printf("%c%8i%30s%21c\n",186,7,"Listado de Pacientes",186);
    printf("%c%59c\n",186,186);
    printf("%c",204);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }

    printf("%c \n",185);
    printf("%c%59c\n",186,186);
    printf("%c%17s%42c\n",186,"ESC   SALIR",186);
    printf("%c%59c\n",186,186);
    printf("%c",200);
    for(int i=0; i <58; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);


}
