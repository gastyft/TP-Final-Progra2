#define LoKJuegoConC main ///By Marian

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_WHITE   "\x1b[38m"

int main()
{
    // color;
//   consolaPrincipal();

///    setConsoleColor(15,10); /// LETRA BLANCA FONDO VERDE
///    setConsoleColor(15,4);  ///LETRA BLANCA FONDO ROJO
///    setConsoleColor(15,5);   ///LETRA BLANCA FONDO VIOLETA (QUEDA BUENO)
///    printf("12312412412512 12 12 125 12 ");

    menu_contenedor();
//     crear_usuario();


    ///CONTRASEÑA ADMIN: Admin123!

//  crear_usuario();
    /**

    PARA EL MENU
    MIENTRAS NO HAGA LOGOUT ENTONCES ESE MENU DE USUARIO especifico.
    */



    /// FUNCIONES PACIENTES

    return 0;
}
/*
int compararFechas(const char *fecha1, const char *fecha2)
{
    int dia1, mes1, anio1, dia2, mes2, anio2;

    sscanf(fecha1, "%d/%d/%d", &dia1, &mes1, &anio1);
    sscanf(fecha2, "%d/%d/%d", &dia2, &mes2, &anio2);

    if (anio1 < anio2)  ///compara anios si es mayor o menor entre si
        return -1;
    else if (anio1 > anio2)
        return 1;

    ///si los anios son iguales comparas meses
    if (mes1 < mes2)
        return -1;
    else if (mes1 > mes2)
        return 1;

    ///si anios y meses son  iguales se comparan dias
    if (dia1 < dia2)
        return -1;
    else if (dia1 > dia2)
        return 1;

    ///devuelve 0 si son iguales
    return 0;
}

void busqueda_filtro_fecha()
{
    FILE *archi = fopen(nombrearchivo, "r+b");

    ingresosLaboratorio labos;

    char desde[11];
    char hasta[11];

    if (archi)
    {
        printf("Ingrese fecha desde (dd/mm/yyyy)\n");
        fflush(stdin);
        gets(desde);

        printf("Ingrese fecha hasta (dd/mm/yyyy)\n");
        fflush(stdin);
        gets(hasta);
 int i = 2;
 int encontrado=0;

    system("cls");
        setConsoleColor(15,5);
   gotoxy(3,1);
  printf("INGRESO     FECHA INGRESO   FECHA RETIRO        DNI         MATRICULA       ELIMINADO        ");
  setConsoleColor(11,0);
        while (fread(&labos, sizeof(ingresosLaboratorio), 1, archi) > 0)
        {
            if (compararFechas(labos.fechaIngreso,desde ) >= 0 && compararFechas(labos.fechaIngreso, hasta) <= 0)
            {
                 mostrar_ingreso(labos,i);
                i++;
                encontrado=1;
            }

            }
 if (!encontrado)
        {
            system("cls");
            setConsoleColor(15, 4);
            printf("No se encontraron fechas en ese intervalo de tiempo");
            setConsoleColor(11, 0);
        }

        fclose(archi);
    }
    else
        printf("ERROR EN EL ARCHIVO EN FUNCION BUSQUEDA FILTRO FECHA\n");
}
*/
