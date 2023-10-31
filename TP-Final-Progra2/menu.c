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
    for(int i=0; i <19; i++)
    {
        printf("%c",205);
    }
    printf("%c",203);
    for(int i=0; i <19; i++)
    {
        printf("%c",205);
    }
    printf("%c",203);
    for(int i=0; i <18; i++)
    {
        printf("%c",205);
    }
    printf("%c \n",185);
    printf("%c%20c%20c%19c\n",186,186,186,186);
    printf("%c%9i%11c%9i%11c%9i%10c\n",186,1,186,2,186,3,186);
    printf("%c%20c%20c%19c\n",186,186,186,186);
    printf("%c%16s%4c%15s%5c%15s%4c\n",186,"Administracion",186,"Laboratorio",186,"Laboratorio",186);
    printf("%c%20c%17s%3c%16s%3c\n",186,186,"Administracion",186,"Profecionales",186);
    printf("%c%20c%20c%19c\n",186,186,186,186);
    printf("%c",204);
    for(int i=0; i <19; i++)
    {
        printf("%c",205);
    }
    printf("%c",202);
    for(int i=0; i <19; i++)
    {
        printf("%c",205);
    }
    printf("%c",202);
    for(int i=0; i <18; i++)
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






