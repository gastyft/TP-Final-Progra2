#include "practica_de_laboratorio.h"

practicas practica_nula() ///Funcion devuelve practica nula
{
    practicas nula;
    nula.nroPractica = 0; // O cualquier valor que no sea válido para nroPractica
    nula.nombrePractica[0] = '\0'; // Nombre vacío
    nula.eliminado = 0; // Indicador por defecto
    return nula;
}


void muestra_individual_practica (practicas a)   ///Muestra individual de una practica
{
    printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
    printf("\n NOMBRE DE PRACTICA %s\n",a.nombrePractica);
    printf("\n ELIMINADO:%d\n",a.eliminado);
    if(a.eliminado==1)
        printf("\n La practica esta dada de baja \n");
    else
        printf("\n La practica esta activa \n");

}


void muestra_individual_archivo (practicas a,int i)  ///Muestra individual que recibe una practica y contador para mostrar en tabla
{
    gotoxy(6,i);
    printf("%i",a.nroPractica);
    gotoxy(11,i);
    printf("%s",a.nombrePractica);
    gotoxy(35,i);
    if (a.eliminado == 0)
    {
        setConsoleColor(15,10); // Verde
        printf("  %-3s", "No");
    }
    else
    {

        setConsoleColor(15,4);// Rojo
        printf("  %-3s", "Si");
    }
    setConsoleColor(11,0);

}

practicas cargar_practica_individual ()  ///Carga una practica
{
    practicas practica;
    int validacion;

    printf("\n NOMBRE DE PRACTICA:\n");
    fflush(stdin);
    gets(practica.nombrePractica);
    validacion=validacion_nombre_practica(practica);
    practica.nroPractica=cantidad_de_ingresos();
    if (validacion==0)
        printf("\n NUMERO DE PRACTICA: %d \n",practica.nroPractica);
    practica.eliminado=0;
    return practica;
}

void cargar_archivo ()    ///Carga el archivo con practica nueva
{
    FILE * archi = fopen(nombrePracticas, "ab");
    char opcion=0;
    practicas a;
    int validacion;

    if (archi)
    {
        while (opcion!=27)
        {
            a=cargar_practica_individual();
            validacion=validacion_nombre_practica(a);
            if (validacion==0)
            {
                fwrite(&a, sizeof(practicas), 1, archi);
                fseek(archi,0,SEEK_END);
            }
            else
            {
                printf("\nIngrese otro nombre, ese ya existe\n");
            }

            printf("PRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n ");
            fflush(stdin);
            opcion=getch();
        }

    }

    fclose(archi);
}

void mostrarArchivo_todos()   ///Muestro de todas practicas activas e inactivas
{
    system("cls");
    FILE * archi = fopen(nombrePracticas, "rb");
    practicas a;
    int i = 2;

    if (archi)
    {
        printf("\n   Numero  Nombre Practica       Eliminado ");
        while (fread(&a,sizeof(practicas),1,archi)>0)
        {

            muestra_individual_archivo(a,i);
            i++;

        }
        fclose(archi);
    }
    else
        printf("ERROR EN EL ARCHIVO PRACTICAS EN FUNCTION MOSTRAR PRACTICAS DESDE ARCHIVO \n");

}
void mostrarArchivo()   ///contenedora de mostrar individual archivo activas
{
    system("cls");
    FILE * archi = fopen(nombrePracticas, "rb");
    practicas a;
    int i = 2;

    if (archi)
    {
        printf("\n   Numero  Nombre Practica       Eliminado ");
        while (fread(&a,sizeof(practicas),1,archi)>0)
        {
            if(a.eliminado==0)
            {

                muestra_individual_archivo(a,i);
                i++;
            }
        }
        fclose(archi);
    }
    else
        printf("ERROR EN EL ARCHIVO PRACTICAS EN FUNCTION MOSTRAR PRACTICAS DESDE ARCHIVO \n");

}
void mostrarArchivoInactivas()  ///Muestra solo inactivas
{
    system("cls");
    FILE * archi = fopen(nombrePracticas, "rb");
    practicas a;
    int i = 2;

    if (archi)
    {
        printf("\n   Numero  Nombre Practica       Eliminado ");
        while (fread(&a,sizeof(practicas),1,archi)>0)
        {
            if(a.eliminado==1)
            {

                muestra_individual_archivo(a,i);
                i++;
            }
        }
        fclose(archi);
    }
    else
        printf("ERROR EN EL ARCHIVO PRACTICAS EN FUNCTION MOSTRAR PRACTICAS DESDE ARCHIVO \n");

}
int pasar_archivo_practicas_a_arreglo(practicas * arreglo_practicas, int *dimension)  ///pasa practicas a un arreglo
{
    FILE *archi = fopen(nombrePracticas, "rb");
    practicas a;
    int i = 0;

    if (archi)
    {
        while (fread(&a, sizeof(practicas), 1, archi) > 0)
        {
            if (i >= *dimension)
            {
                (*dimension) *= 2;
                arreglo_practicas = (practicas *)realloc(arreglo_practicas, sizeof(practicas) * (*dimension));
                if (arreglo_practicas == NULL)
                {
                    printf("Error al realojar memoria. No se han guardado todas las prácticas.\n");
                    fclose(archi);
                    return i;
                }
            }

            arreglo_practicas[i] = a;
            i++;
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR EN EL ARCHIVO PRACTICAS\n");
    }

    return i;
}

void mostrar_arreglo(practicas* arreglo_practicas, int validos)   ///muestro del arreglo
{
    int i=0;

    while (i<validos)
    {
        if (arreglo_practicas[i].eliminado==0)
            muestra_individual_practica(arreglo_practicas[i]);
        i++;
    }

}


void dar_baja_practica(int nro_de_practica_a_validar) /// da de baja practica validando que no este en uso sino no se puede dar de baja
{
    FILE *archi=fopen(nombrePracticas,"r+b");

    practicas practica;
    char o=0;

    if(archi)
    {
        while(fread(&practica,sizeof(practicas),1,archi)>0)
        {
            if(practica.nroPractica==nro_de_practica_a_validar)
            {

                if(validacion_practica_uso(practica)== 0 )
                {
                    if(practica.eliminado==0)
                    {
                        printf("\nIngreso el numero: %d ----> que corresponde a la practica: %s. Esta de acuerdo con darla de baja? Presione ENTER si lo esta. cualquier otra tecla si no. \n",practica.nroPractica,practica.nombrePractica);
                        fflush(stdin);
                        o=getch();

                        if (o==13)
                        {
                            practica.eliminado=1;

                            fseek(archi,-1*sizeof(practicas),SEEK_CUR);
                            fwrite(&practica,sizeof(practicas),1,archi);
                            fclose(archi);
                            return;
                        }
                    }
                    else
                    {
                        printf("\nEsa practica ya esta dada de baja.\n");
                        fclose(archi);
                        system("pause");
                    }
                }
                else
                {

                    system("cls");
                    printf("La practica no se puede dar de baja porque se encuentra en uso \n");
                    system("pause");
                }
            }
        }

    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR BAJA PRACTICA\n");


}

void dar_alta_practica(int nro_de_practica_a_validar)  ///da de alta una practica
{
    FILE *archi=fopen(nombrePracticas,"r+b");

    practicas practica;
    char o=0;

    if(archi)
    {
        while(fread(&practica,sizeof(practicas),1,archi)>0)
        {
            if(practica.nroPractica==nro_de_practica_a_validar)
            {
                if(practica.eliminado==1)
                {
                    printf("\nIngreso el numero: %d ----> que corresponde a la practica: %s. Esta de acuerdo con darla de alta? ENTER si lo esta. cualquier otra tecla si no. \n",practica.nroPractica,practica.nombrePractica);
                    fflush(stdin);
                    o=getch();

                    if (o==13)
                    {
                        practica.eliminado=0;

                        fseek(archi,-1*sizeof(practicas),SEEK_CUR);
                        fwrite(&practica,sizeof(practicas),1,archi);
                        fclose(archi);
                        return;
                    }
                }
                else
                {
                    printf("\nEsa practica ya esta dada de alta.\n");
                    fclose(archi);
                }
            }
        }


    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR BAJA PRACTICA\n");

}

void buscar_practica_por_nombre (char practica_a_buscar[], practicas * arreglo_de_practicas,int validos,int indices [], int * cant_resultados)
{                            ///busqueda por coincidencias
    int i=0;
    char busqueda[strlen(practica_a_buscar)];
    strcpy(busqueda,practica_a_buscar);

    for (int j=0; j<strlen(busqueda); j++)
    {
        busqueda[j]=tolower(busqueda[j]);
    }
    printf("\n BUSQUEDA:   %s",busqueda);

    *cant_resultados=0;

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
            ///  muestra_individual_practica(arreglo_de_practicas[i]);
            indices[(*cant_resultados)++]=i;
        }
        i++;
    }
}

void buscar_practica_por_numero (int numero_practica_a_buscar, practicas * arreglo_de_practicas,int validos) ///Busqueda por numero de practica
{
    int i=0;

    printf("\n BUSQUEDA:   %i \n",numero_practica_a_buscar);

    while (i<validos)
    {
        int aux= arreglo_de_practicas[i].nroPractica;
        if (aux==numero_practica_a_buscar)
        {
            printf("\nPRACTICA ENCONTRADA: %i ",aux);
            muestra_individual_practica(arreglo_de_practicas[i]);
        }

        i++;
    }
    i++;
    if (i>validos)
    {
        printf("\n Ese numero de practica no se encontro\n");
    }
}

//void dar_baja_todas_practicas
// void dar alta todas las practicas

///MODIFICACION DE PRACTICA - SOLO SU NOMBRE


void modificar_nombre_practica(char nombre_buscar[], practicas * arreglo_practicas, int validos, char opcion) ///funcion de modificar y contenedora de buscar por coincidencias
{
    int indices[validos];
    int cant_resultados = 0;
    char nuevo_nombre[100];
    int i=0;

    if (opcion=='4')///modificar
    {
        buscar_practica_por_nombre(nombre_buscar, arreglo_practicas, validos, indices, &cant_resultados);

        if (cant_resultados == 0)
        {
            printf("\nLa practica no se encontro.\n");
            system("pause");
        }
        else if (cant_resultados == 1)
        {
            modificar_nombre_practica_archivo(nuevo_nombre,arreglo_practicas,indices[0]);
        }
        else
        {

            printf("Se encontraron multiples practicas. Por favor, seleccione una.\n");
            for (int i = 0; i < cant_resultados; i++)
            {
                printf("%d. ", i + 1);
                muestra_individual_practica(arreglo_practicas[indices[i]]);
            }
            int seleccion;
            printf("Seleccione el numero correspondiente a la practica que desea modificar: ");
            scanf("%d", &seleccion);
            if (seleccion > 0 && seleccion <= cant_resultados)
            {
                modificar_nombre_practica_archivo(nuevo_nombre,arreglo_practicas, indices[seleccion-1]);
            }
            else
            {

                printf("Selección invalida.\n");
                system("pause");
            }
        }
    }
    if (opcion == '5')///buscar

    {
        buscar_practica_por_nombre(nombre_buscar, arreglo_practicas, validos, indices, &cant_resultados);
        if (cant_resultados == 0)
        {
            printf("\nLa practica no se encontro.\n");
        }
        if (cant_resultados==1)
            muestra_individual_practica(arreglo_practicas[indices[i]]);
        if (cant_resultados>1)
        {
            for (int i = 0; i < cant_resultados; i++)
            {
                printf("%d. ", i + 1);
                muestra_individual_practica(arreglo_practicas[indices[i]]);
            }
        }
        system("pause");
    }
}


void modificar_nombre_practica_archivo (char nuevo_nombre[], practicas * arreglo_practicas, int i)  ///modifica practica al archivo
{
    FILE * archi = fopen(nombrePracticas,"r+b");
    if (archi)
    {
        printf("Ingrese el nuevo nombre para la practica: ");
        fflush(stdin);
        gets(nuevo_nombre);
        if (strlen(nuevo_nombre) > 100)
        {
            printf("¡Error! El nombre ingresado es demasiado largo.\n");
        }
        else
        {
            strcpy(arreglo_practicas[i].nombrePractica,nuevo_nombre);
            fseek(archi,i*sizeof(practicas),SEEK_SET);
            fwrite(&arreglo_practicas[i],sizeof(practicas),1,archi);

        }
        fclose(archi);
    }
}


int cantidad_de_ingresos ()///cuento la cantidad de ingresos para despues poder saber el numero de ingreso de la proxima persona
{
    FILE *archi =fopen(nombrePracticas,"r+b");///abro el archivo en modo lectura
    int cant=0;
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);///me paro al final del archivo
        cant=ftell(archi)/sizeof(practicas);///con esa division encuentro la cantidad de registros dentro del archivo
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
    return cant;///retorno la cantidad de registros encontrados
}

/// validacion de que la misma practica no exista dos veces
int validacion_nombre_practica(practicas practica_a_validar) ///no se repita
{
    FILE *archi=fopen(nombrePracticas,"r+b");
    practicas prac;
    int flag=0;
    if(archi)
    {

        while(fread(&prac,sizeof(practicas),1,archi)>0)
        {

            if(strcmpi(prac.nombrePractica,practica_a_validar.nombrePractica)==0)
            {
                //gets(practica_a_validar.nombrePractica);
                //rewind(archi);
                flag=1;
            }

        }
    }
    else
        printf("ERROR EN EL ARCHIVO DE PRACTICAS EN FUNCION VALIDACION NOMBRE PRACTICA \n");

    fclose(archi);

    return flag;
}



///VALIDAR PRACTICAS
practicas validar_nro_practica_exista(practicas *arr,int validos,int nroPractica) /// DEVUELVE NULL SI NO EXISTE SINO LA ESTRUCTURA
{
    int i=0;
    practicas prac=practica_nula();

    while(i<validos)
    {
        if(arr[i].nroPractica==nroPractica)
        {
            {
                strcpy(prac.nombrePractica,arr[i].nombrePractica);
                prac.nroPractica=nroPractica;
                prac.eliminado=arr[i].eliminado;
            }
        }
        i++;
    }

    return prac;


}
   ///Valida si la practica se encuentra en uso por alguna practica por ingreso desde el archivo
int validacion_practica_uso( practicas a)
{
    FILE *archi = fopen("practicas.bin","r+b");
   pracXingreso prac;
    int encontrado=0;
    if(archi)
    {

        while(fread(&prac,sizeof(pracXingreso),1,archi)>0)
        {

            if(prac.nroPractica == a.nroPractica)
            {
                encontrado =1;

            }
        }



    }
    else
        printf("ERROR EN EL ARCHIVO \n");

 return encontrado;
}





void menu_practicas() ///Menu para Admin con funciones de practicas
{


    char o=0;
    do
    {
        int nroPractica=0;
        char nombrePractica[30];
        char nombrePractica2[30];


        int cantidad= 50;
        practicas * arreglo_practicas = (practicas*)malloc(sizeof(practicas)*cantidad);
        int validos=pasar_archivo_practicas_a_arreglo(arreglo_practicas,&cantidad);

        system("cls");
        consola_vacia();
        gotoxy(2,7);
        printf("1- Cargar una practica nueva ");
        gotoxy(2,8);
        printf("2- Dar de baja una practica");
        gotoxy(2,9);
        printf("3- Dar de alta una practica");
        gotoxy(2,10);
        printf("4- Modificar nombre de practica ");
        gotoxy(2,11);
        printf("5- Buscar practica por nombre");
        gotoxy(2,12);
        printf("6- Buscar practica por numero ");
        gotoxy(2,13);
        printf("7- Mostrar practicas activas ");
        gotoxy(2,14);
        printf("8- Mostrar practicas inactivas ");
        gotoxy(2,15);

        fflush(stdin);
        o=getch();
        switch(o)
        {

        case '1':
            system("cls");
            cargar_archivo();
            break;

        case '2':
            system("cls");
            mostrarArchivo_todos();
            printf("\n");
            printf("Ingrese numero de practica a dar de baja");
            scanf("%d",&nroPractica);
            dar_baja_practica(nroPractica);
            break;
        case '3':
            system("cls");
            mostrarArchivo_todos();
            printf("\n");
            printf("Ingrese numero de practica a dar de alta");
            scanf("%d",&nroPractica);
            dar_alta_practica(nroPractica);
            break;
        case '4':
            system("cls");
            mostrarArchivo_todos();
            printf("\n");
            printf("Ingrese nombre de la practica a modificar \n");
            fflush(stdin);
            gets(nombrePractica);
            modificar_nombre_practica(nombrePractica,arreglo_practicas,validos,o);
            break;
        case '5':
            system("cls");
            printf("Ingrese practica a buscar por nombre");
            fflush(stdin);
            gets(nombrePractica2);
            modificar_nombre_practica(nombrePractica2,arreglo_practicas,validos,o);

            break;
        case '6':
            system("cls");
            printf("Ingrese practica a buscar por numero");
            scanf("%d",&nroPractica);
            buscar_practica_por_numero(nroPractica,arreglo_practicas,validos);
            system("pause");
            break;
        case '7':
            system("cls");
            mostrarArchivo();
            printf("\n");
            system("pause");
            break;
        case '8':
            system("cls");
            mostrarArchivoInactivas();
            printf("\n");
            system("pause");
            break;
        case 27:
            break;
        default:
            system("cls");
            printf("Selecciono opcion invalida. Presione cualquier tecla para continuar");
            fflush(stdin);
            o=getch();
            break;
        }

    }
    while(o!=27);
}


