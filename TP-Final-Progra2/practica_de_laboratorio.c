#include "practica_de_laboratorio.h"




///practicas se abre el archivo y se guardan en arreglos
///practicas por ingreso en lista simple

///VALIDAR QUE LOS STRINGS NO SEAN MAS LARGOS DE LO PERMITIDO, QUE DE UN MENSAJE DE ALERTA.
/*if (strlen(palabra) > 100) {
       printf("¡Error! El nombre ingresado es demasiado largo.\n");
       return; // Sale de la función si el nombre es demasiado largo
   }*/
///HACER VALIDACIONES REGEX QUE NO ACEPTE CARACTERES EN FUNCIONES DE NUMEROS

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

practicas practica_nula()
{
    practicas nula;
    nula.nroPractica = 0; // O cualquier valor que no sea válido para nroPractica
    nula.nombrePractica[0] = '\0'; // Nombre vacío
    nula.eliminado = 0; // Indicador por defecto
    return nula;
}

void inicializar_practicas_cargadas(int practicas_cargadas [], int max_practicas)
{
    for (int i = 0; i < max_practicas; i++)
    {
        practicas_cargadas[i] = -1;
    }
}


practicas cargar_practica_individual_validacion_archivo ()
{
    FILE * archi = fopen(nombrePracticas, "rb");
    practicas practica;
    practicas a;
    int rta=1;

    if (archi)
    {
        printf("\n NUMERO DE PRACTICA:\n");
        scanf("%d",&practica.nroPractica);
        printf("\n NOMBRE DE PRACTICA:\n");
        fflush(stdin);
        gets(practica.nombrePractica);
        fseek(archi,0,SEEK_SET);
        while (fread(&a,sizeof(practicas),1,archi)>0)
        {
            if (a.nroPractica==practica.nroPractica)
            {
                printf("Disculpe. Ese numero de practica ya existe");
                rta=0;
                break;
            }

        }
        if (rta==1)
        {
            practica.eliminado=0;
        }
        fclose(archi);
    }
    return (rta==1) ? practica: practica_nula();
}


void cargar_archivo ()
{
    FILE * archi = fopen(nombrePracticas, "ab");
    char opcion=0;
    practicas a;// practica a cargar
    int max_practicas =100;
    int practicas_cargadas[max_practicas];
    int cantidad_practicas_cargadas=0;

    if (archi)
    {
        inicializar_practicas_cargadas(practicas_cargadas,max_practicas);
        while (opcion!=27)
        {
            a=cargar_practica_individual_validacion_archivo();
            int ya_cargada=0;

            for (int i = 0; i < cantidad_practicas_cargadas; i++)
            {
                if (practicas_cargadas[i] == a.nroPractica)
                {
                    printf("\n Disculpe. Ese numero de practica ya fue cargado en esta sesion\n");
                    ya_cargada=1;
                    break;
                }
            }
            if (!ya_cargada && a.nroPractica!=0)
            {
                fwrite(&a,sizeof(practicas),1,archi);
                practicas_cargadas[cantidad_practicas_cargadas] = a.nroPractica;
                cantidad_practicas_cargadas++;
            }
            else if (a.nroPractica==0)
            {
                printf("\n No se cargo esa practica en esta sesion.\n");
            }
            printf("\nPRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n ");
            fflush(stdin);
            opcion=getch();
        }
    }
    fclose(archi);
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
                    printf("\nIngreso el numero: %d ----> que corresponde a la practica: %s. Esta de acuerdo con darla de baja? 's' o 'S' si lo esta. cualquier otra tecla si no. \n",practica.nroPractica,practica.nombrePractica);
                    scanf("%c",&respuesta);

                    if (respuesta=='s'|| respuesta=='S')
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

                    if (respuesta=='s'|| respuesta=='S')
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

void buscar_practica_por_nombre (char practica_a_buscar[], practicas * arreglo_de_practicas,int validos,int indices [], int * cant_resultados)
{
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
            printf("\nPRACTICA: %s ",aux);
            muestra_individual_practica(arreglo_de_practicas[i]);
            indices[(*cant_resultados)++]=i;
        }
        i++;
    }
}

void buscar_practica_por_numero (int numero_practica_a_buscar, practicas * arreglo_de_practicas,int validos)
{
    int i=0;

    printf("\n BUSQUEDA:   %i",numero_practica_a_buscar);

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
}

//void dar_baja_todas_practicas
// void dar alta todas las practicas

///MODIFICACION DE PRACTICA - SOLO SU NOMBRE


void modificar_nombre_practica(char nombre_buscar[], practicas * arreglo_practicas, int validos)
{
    int indices[validos];
    int cant_resultados = 0;
    char nuevo_nombre[100];

    buscar_practica_por_nombre(nombre_buscar, arreglo_practicas, validos, indices, &cant_resultados);

    if (cant_resultados == 0)
    {
        printf("La practica no se encontro.\n");
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
        }
    }
}

void modificar_nombre_practica_archivo (char nuevo_nombre[], practicas * arreglo_practicas, int i)
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

///VALIDAR PRACTICAS
practicas validar_nro_practica_exista(practicas *arr,int validos,int nroPractica)
{
    int i=0;
    practicas prac;
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

practicas validacion_nombre_practica(practicas practicaAvalidar){///no se repita
FILE *archi=fopen(nombrePracticas,"r+b");
practicas prac;
if(archi){

while(fread(&prac,sizeof(practicas),1,archi)>0){

if(strcmpi(prac.nombrePractica,practicaAvalidar.nombrePractica)==0){

    printf("ESE NOMBRE DE PRACTICA YA EXISTE \n");

    printf("Ingrese otro nombre de practica\n");

    fflush(stdin);
    gets(practicaAvalidar.nombrePractica);
    rewind(archi);
}

}
fwrite(&practicaAvalidar,sizeof(practicas),1,archi);

}
else
    printf("ERRROR EN EL ARCHIVO DE PRACTICAS EN FUNCION VALIDACION NOMBRE PRACTICA \n");

fclose(archi);

return practicaAvalidar;
}
