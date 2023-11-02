#include "practica_de_laboratorio.h"




///practicas se abre el archivo y se guardan en arreglos
///practicas por ingreso en lista simple


void muestra_individual_practica (practicas a)
{
    printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
    printf("\n NOMBRE DE PRACTICA %s\n",a.nombrePractica);
    printf("\n ELIMINADO:%d\n",a.eliminado);
    if(a.eliminado==1)
        printf("\n La practica esta dada de baja \n");
    else
        printf("\n La practica esta activa \n");

}

practicas cargar_practica_individual ()
{
    practicas practica;
    printf("\n NUMERO DE PRACTICA:\n");
    scanf("%d",&practica.nroPractica);
    printf("\n NOMBRE DE PRACTICA:\n");
    fflush(stdin);
    gets(practica.nombrePractica);
    practica.eliminado=0;
    return practica;
}

void cargar_archivo ()
{
    FILE * archi = fopen(nombrePracticas, "ab");
    char opcion=0;
    practicas a;

    if (archi)
    {

        while (opcion!=27)
        {
            a=cargar_practica_individual();
            fwrite(&a,sizeof(practicas),1,archi);
            printf("PRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n ");
            fflush(stdin);
            opcion=getch();

        }

        fclose(archi);
    }
}

void mostrarArchivo ()
{
    FILE * archi = fopen(nombrePracticas, "rb");
    practicas a;

    if (archi)
    {
        while (fread(&a,sizeof(practicas),1,archi)>0)
        {
            if(a.eliminado==0)
                muestra_individual_practica(a);
        }
        fclose(archi);
    }
    else
        printf("ERROR EN EL ARCHIVO PRACTICAS EN FUNCTION MOSTRAR PRACTICAS DESDE ARCHIVO \n");

}

int pasar_archivo_practicas_a_arreglo(practicas * arreglo_practicas, int *dimension)
{
    FILE *archi = fopen(nombrePracticas, "rb");
    practicas a;
    int i = 0;

    if (archi) {
        while (fread(&a, sizeof(practicas), 1, archi) > 0) {
            if (i >= *dimension) {
                (*dimension) *= 2;
                arreglo_practicas = (practicas *)realloc(arreglo_practicas, sizeof(practicas) * (*dimension));
                if (arreglo_practicas == NULL) {
                    printf("Error al realojar memoria. No se han guardado todas las prácticas.\n");
                    fclose(archi);
                    return i;
                }
            }

            arreglo_practicas[i] = a;
            i++;
        }
        fclose(archi);
    } else {
        printf("ERROR EN EL ARCHIVO PRACTICAS\n");
    }

    return i;
}

void mostrar_arreglo(practicas* arreglo_practicas, int validos)
{
    int i=0;

    while (i<validos)
    {
        if (arreglo_practicas[i].eliminado==0)
        muestra_individual_practica(arreglo_practicas[i]);
        i++;
    }

}

///hacer funcion para ver si la practica esta en algun ingreso, si esta en algun ingreso la baja no puede pasar. (practicas por ingreso)
///trae la practica entera, hay que verificar que el numero y el nombre de la practica coincidan en la misma practica - YA LO SOLUCIONE SOLO TRAYENDO EL NUMERO DE PRACTICA


void dar_baja_practica(int nro_de_practica_a_validar)
{
    FILE *archi=fopen(nombrePracticas,"r+b");
    char respuesta ='s';

    practicas practica;

    if(archi)
    {
        while(fread(&practica,sizeof(practicas),1,archi)>0)
        {
            if(practica.nroPractica==nro_de_practica_a_validar)
            {
               if(practica.eliminado==0)
                {
                printf("\nIngreso el numero: %d ----> que corresponde a la practica: %s. Esta de acuerdo con darla de baja? 's' si lo esta. cualquier otra tecla si no. \n",practica.nroPractica,practica.nombrePractica);
                scanf("%c",&respuesta);

                if (respuesta=='s')
                {
                practica.eliminado=1;

                fseek(archi,-(long)sizeof(practicas),SEEK_CUR);
                fwrite(&practica,sizeof(practicas),1,archi);
                return;
                }
                }
                else
                    printf("\nEsa practica ya esta dada de baja.\n");

            }
        }
    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR BAJA PRACTICA\n");

    fclose(archi);

}

void dar_alta_practica(int nro_de_practica_a_validar)
{
    FILE *archi=fopen(nombrePracticas,"r+b");

    practicas practica;
    char respuesta='s';

    if(archi)
    {
        while(fread(&practica,sizeof(practicas),1,archi)>0)
        {
            if(practica.nroPractica==nro_de_practica_a_validar)
            {
                if(practica.eliminado==1)
                {
                printf("\nIngreso el numero: %d ----> que corresponde a la practica: %s. Esta de acuerdo con darla de alta? 's' si lo esta. cualquier otra tecla si no. \n",practica.nroPractica,practica.nombrePractica);
                scanf("%c",&respuesta);

                if (respuesta=='s')
                {
                practica.eliminado=0;

                fseek(archi,-(long)sizeof(practicas),SEEK_CUR);
                fwrite(&practica,sizeof(practicas),1,archi);
                return;
                }
                }
                else
                    printf("\nEsa practica ya esta dada de alta.\n");

            }
        }
    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR BAJA PRACTICA\n");

    fclose(archi);

}

void buscar_practica_por_nombre (char practica_a_buscar[], practicas * arreglo_de_practicas,int validos)
{
    int i=0;
    char busqueda[strlen(practica_a_buscar)];
    strcpy(busqueda,practica_a_buscar);

    for (int j=0; j<strlen(busqueda); j++)
        {
            busqueda[j]=tolower(busqueda[j]);
        }
        printf("\n BUSQUEDA:   %s",busqueda);

    while (i<validos)
    {
        char aux [strlen(arreglo_de_practicas[i].nombrePractica)];
        strcpy(aux,arreglo_de_practicas[i].nombrePractica);

        for (int j=0; j<strlen(aux); j++)
        {
            aux[j]=tolower(aux[j]);
        }
        if (strncmp(aux,busqueda,strlen(busqueda))==0)
        {
            printf("\nPRACTICA: %s ",aux);
        }
        else
            printf("\n NO COINCIDE %s  ",aux);

        i++;
    }
}


///CREAR NUEVA PRACTICA INDIVIDUAL (se suma al arreglo? al archivo?)

///buscar practica por numero

///menu que cuando seleccionas quede subrayado

