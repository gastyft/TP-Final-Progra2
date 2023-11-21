#include "practicas_x_ingreso.h"


pracXingreso cargar_individual_x_ingreso (int nroIngreso)
{
    pracXingreso a;
    do {
          printf("Ingrese nro de practica \n");
        scanf("%d",&a.nroPractica);
        }while( buscarid_practica(a.nroPractica)==0);

    a.nroIngreso=nroIngreso;
    printf("\nIngrese resultado\n");
    fflush(stdin);
    gets(a.resultado);


    return a;
}
void muestra_individual (pracXingreso a)
{
    printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
    printf(" NUMERO DE INGRESO %d\n",a.nroIngreso);
    printf(" RESULTADO %s\n",a.resultado);
}

void muestra_individual_con_nombre (pracXingreso a)
{
    FILE *archi=fopen(nombrePracticas,"rb");

    if(archi)
    {
        practicas prac;
        while(fread(&prac,sizeof(practicas),1,archi)>0)
        {

            if(prac.nroPractica==a.nroPractica)
            {
                setConsoleColor(15,5);
                printf("NOMBRE PRACTICA:"),
                       setConsoleColor(11,0);
                       printf(" %s",prac.nombrePractica);

                printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
                printf("\n NUMERO DE INGRESO %d\n",a.nroIngreso);
                printf("\n RESULTADO %s\n",a.resultado);

            }
        }


    }
    else
        printf("ERROR EN ABRIR EL ARCHIVO EN FUNCION MUESTRA INDIVIDUAL EN PRAC X INGRESO \n");


    fclose(archi);
}




///listas para practicas por ingreso
nodo_simple_pxi * inic_lista ()
{
    return NULL;
}

nodo_simple_pxi * agregar_ppio(nodo_simple_pxi * lista, nodo_simple_pxi * nuevo)
{
    if (lista!=NULL)
    {
        nuevo->siguiente=lista;
    }
    return nuevo;
}

nodo_simple_pxi * crear_nodo_pxi (pracXingreso dato)
{
    nodo_simple_pxi * nuevo = (nodo_simple_pxi*)malloc(sizeof(nodo_simple_pxi));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodo_simple_pxi* buscar_ultimo_nodo_recursivo (nodo_simple_pxi * lista)
{
    nodo_simple_pxi * ultimo;

    if (lista==NULL)
    {
        ultimo=NULL;
    }
    else if (lista->siguiente!=NULL)
    {
        ultimo= buscar_ultimo_nodo_recursivo(lista->siguiente);
    }
    else
    {
        ultimo=lista;
    }
    return ultimo;
}

nodo_simple_pxi * agregar_final (nodo_simple_pxi * lista, nodo_simple_pxi * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo_simple_pxi * ultimo=buscar_ultimo_nodo_recursivo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}

nodo_simple_pxi * agregar_orden (nodo_simple_pxi * lista, nodo_simple_pxi * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if (lista->dato.nroIngreso>nuevo->dato.nroIngreso)
        {
            lista=agregar_ppio(lista,nuevo);
        }
        else
        {
            nodo_simple_pxi * ante=lista;
            nodo_simple_pxi * seguidora=lista->siguiente;

            while (seguidora!=NULL && seguidora->dato.nroIngreso<nuevo->dato.nroIngreso)
            {
                ante=seguidora;
                seguidora=seguidora->siguiente;
            }

            ante->siguiente=nuevo;
            nuevo->siguiente=seguidora;
        }
    }
    return lista;
}

nodo_simple_pxi * cargar_lista (nodo_simple_pxi * lista, int nroIngreso)
{
    pracXingreso dato;
    nodo_simple_pxi * aux;
    char opcion = 0;

    while (opcion!=27)
    {
        dato=cargar_individual(nroIngreso);
        aux=crear_nodo_pxi(dato);
        lista=agregar_ppio(lista,aux);
        printf("PRESS ANY KEY TO CONTINUE OR ESC TO EXIT \n ");
        fflush(stdin);
        opcion=getch();
    }
    return lista;
}



void muestra_lista (nodo_simple_pxi * lista)
{
    if (lista)
    {
        muestra_individual_con_nombre(lista->dato);
        muestra_lista(lista->siguiente);
    }
}

nodo_simple_pxi * borrar_nodo_doble (nodo_simple_pxi * lista, int dato)
{
    nodo_simple_pxi * aux;
    if (lista!=NULL)
    {
        if (lista->dato.nroPractica==dato)
        {
            aux=lista;
            aux->siguiente=NULL;
            if (lista!=NULL)
                lista=lista->siguiente;
            free(aux);
        }
        else
        {
            nodo_simple_pxi * ante= lista;
            nodo_simple_pxi * seg= lista->siguiente;

            while (seg!=NULL && seg->dato.nroPractica!=dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            if (seg!=NULL)
            {
                ante->siguiente=seg->siguiente;
                free(seg);
            }
        }
    }
    return lista;
}

/*int CantRegistros ()
{
    FILE * arch;
    arch= fopen(nombreArch,"rb");
    int cant;

    if (arch!=NULL)
    {
        fseek(arch,0,SEEK_END);
        cant=ftell(arch)/sizeof(alumno);
    }
    fclose(arch);
    return cant;
}*/

nodo_simple_pxi * buscar_nodo (nodo_simple_pxi * lista, int dato)
{
    nodo_simple_pxi * seg=lista;

    if (seg==NULL)
    {
        return NULL;
    }
    else
    {
        while (seg!=NULL &&seg->dato.nroPractica!=dato)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodo_simple_pxi * eliminarPrimerNodo (nodo_simple_pxi * lista)
{
    nodo_simple_pxi * aux=lista;

    if (lista!=NULL)
    {
        aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    return lista;
}

nodo_simple_pxi * borrarLista (nodo_simple_pxi * lista)
{
    nodo_simple_pxi * aux=lista;

    while (lista!=NULL)
    {
        lista=lista->siguiente;
        aux->siguiente=NULL;
        free(aux);
        aux=lista;
    }
    return lista;
}
/// ACA EMPIEZAN FUNCIONES CRUD
/**
Alta_de_pxi: verificar que existan el nro  de ingreso y de practica LISTO
• Modificacio_de_pxi:puede afectar a un nro de practica y al resultado solamente LISTO
• Baja_de_pxi  LISTO
FALTAN VALIDACIONES TODAS PREGUNTAR A SOFI SI QUIERE QUE LAS HAGA
*/




nodo_simple_pxi *alta_logica_archivo(nodo_simple_pxi *lista,int nroIngreso)
{

    FILE *archi=fopen(nombrePracticasxIngreso,"r+b");
    pracXingreso prac;
    if(archi)
    {
        while(fread(&prac,sizeof(pracXingreso),1,archi)>0)
        {
            if(nroIngreso == prac.nroIngreso)
            {

                prac.eliminado=0;
                fseek(archi,-1*sizeof(pracXingreso),SEEK_CUR);
                fwrite(&prac,sizeof(pracXingreso),1,archi);
                nodo_simple_pxi *aux=buscar_nodo(lista,nroIngreso);
                aux->dato.eliminado=0;
            }
        }
    }
    return lista;
}

nodo_simple_pxi *alta_fisica(nodo_simple_pxi*lista,int nroIngreso)
{

    FILE*archi=fopen(nombrePracticasxIngreso,"a+b");
    if(archi)
    {
        pracXingreso prac=cargar_individual(nroIngreso);
        ///Luego de validar la carga
        lista=agregar_final(lista,crear_nodo_pxi(prac));
        fwrite(&prac,sizeof(pracXingreso),1,archi);


    }
    else
        printf("ERROR EN EL ARCHIVO EN FUNCION ALTA FISICA\n");

    return lista;
}


nodo_simple_pxi *modifica_un_nodo_prac_x_ingreso_admin(nodo_simple_pxi *aModificar)  ///CASO  ROL ADMIN menu para editar nroPractica o resultado
{

    char o=0;

    muestra_individual(aModificar->dato);

    while(o!=27)
    {
        printf("Ingrese opcion \n");
        printf("1-Cambiar numero de practica\n");
        printf("2-cambiar resultado\n");
        printf("ESC to return \n");
        switch (o)
        {
        case '1':
            printf("Ingrese nuevo resultado\n ");
            fflush(stdin);
            gets(aModificar->dato.resultado);
            break;
        case '2':
            printf("Ingrese nuevo numero de practica\n");
            ///mostrar lista practicas para que elija

            scanf("%d",&aModificar->dato.nroPractica);
/// funcion validacion nroPrctica que abre archivo practicas
            break;

        case 27:

            break;
        default:
            printf("Ingreso una opcion incorrecta \n");
            printf("Presione escape para salir o una tecla cualquiera para elegir que cambiar\n");
            fflush(stdin);
            o=getch();
            if(o==ESC)
                break;
            break;
        }
    }
    muestra_individual(aModificar->dato);
    return aModificar;        ///DEVUELVE NODO MODIFICADO
}



nodo_simple_pxi *modificar_practicas_x_ingreso_contenedora_admin(nodo_simple_pxi *lista)
{


    int nroAbuscar;
    int flag=0;
    printf("Ingrese el numero de practica para modificar \n");
    scanf("%d",&nroAbuscar);
    char o=0;
    while(flag || o!=27)
    {
    nodo_simple_pxi* aux;
        aux= buscar_nodo(lista,nroAbuscar);
        if(aux)
        {

            aux= modifica_un_nodo_prac_x_ingreso_admin(aux);

            flag=1;
        }
        else
        {
            printf("Ingreso un nro de ingreso incorrecto \n");
            printf("Presione una tecla para volver a cargar el nro de ingreso o ESC para volver atras(menu) \n");
            fflush(stdin);
            o=getch();
            printf("Ingrese el numero de ingreso para modificar \n");
            scanf("%d",&nroAbuscar);
        }


    }
    if(flag==1)
    {

        printf("No se encuentra el nro de ingreso en la base de datos \n");

    }

    return lista;
}

nodo_simple_pxi *modifica_un_nodo_prac_x_ingreso_tecnico(nodo_simple_pxi *aModificar)
{

    printf("PRACTICA QUE QUIERE MODIFICAR EL RESULTADO \n");
    muestra_individual(aModificar->dato);

    printf("Ingrese nuevo resultado\n");
    fflush(stdin);

    gets(aModificar->dato.resultado);

    return aModificar;
}


nodo_simple_pxi *cargar_practicas_x_ingreso_tecnico(nodo_simple_pxi *lista) ///Carga del resultado por parte del tecnico o bioquimico ROL 2
{

    nodo_simple_pxi* aux=inic_lista();

    int nroAbuscar;
    int flag=0;
    printf("Ingrese el numero de practica a cargar resultado \n");
    scanf("%d",&nroAbuscar);
    char o=0;
    while(flag || o!=27)
    {
        aux= buscar_nodo(lista,nroAbuscar);
        if(aux)
        {
            muestra_individual(aux->dato);
            printf("Ingrese Resultado \n");
            fflush(stdin);
            gets(aux->dato.resultado);
            flag=1;
        }
        else
        {
            printf("Ingreso un nro de ingreso incorrecto \n");
            printf("Presione una tecla para volver a cargar el nro de ingreso o ESC para volver atras(menu) \n");
            fflush(stdin);
            o=getch();
            printf("Ingrese el numero de ingreso para modificar \n");
            scanf("%d",&nroAbuscar);
        }


    }
    if(flag==1)
    {

        printf("No se encuentra el nro de ingreso en la base de datos \n");

    }

    return aux;
}


nodo_simple_pxi *baja_de_pxi(nodo_simple_pxi *nodo,int nroPractica)
{

    FILE *archi=fopen(nombrePracticasxIngreso,"r+b");
    pracXingreso prac;
    int flag=0;
    if(archi)
    {
        while(flag && fread(&prac,sizeof(pracXingreso),1,archi)>0)
        {
            if( nodo->dato.nroPractica == prac.nroIngreso){
            if(nroPractica==prac.nroPractica)
            {
                prac.eliminado=1;
                nodo->dato.eliminado=1;
                fseek(archi,-1*sizeof(pracXingreso),SEEK_CUR);
                fwrite(&prac,sizeof(pracXingreso),1,archi);
                flag=1;
            }
            }
        }
        if(flag)
        {
            printf("No se encontro el nro de ingreso\n");

        }
    }
    else
        printf("ERROR  EN EL ARCHIVO EN FUNCION BAJA DE PXI\n");

    return nodo;
}


pracXingreso cargar_individual ()
{
    pracXingreso a;
    printf("\nIngrese resultado\n");
    fflush(stdin);
    gets(a.resultado);
    printf("Ingrese numero de ingreso \n");
    scanf("%d",&a.nroIngreso);/// esto no es asi, se hace autoincremental
    printf("\nIngrese numero de practica\n");
    scanf("%d",&a.nroPractica);

    return a;
}

pracXingreso cargar_individual_administrativo (int nroIngreso)
{
    pracXingreso a;
    strcpy(a.resultado,"Ninguno");
    a.nroIngreso=nroIngreso;
    printf("\nIngrese numero de practica\n");
    scanf("%d",&a.nroPractica);

    return a;
}

void muestra_individual_prac_x_ingreso (pracXingreso a)
{
    FILE *archi=fopen(nombrePracticas,"r+b");
    practicas prac;
    int flag=0;
    if(archi)
    {

        while(fread(&prac,sizeof(practicas),1,archi)>0 &&flag)
        {
            if(prac.nroPractica==a.nroPractica)
            {

                printf("NOMBRE PRACTICA: %s \n",prac.nombrePractica);
                printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
                printf("\n NUMERO DE INGRESO %d\n",a.nroIngreso);
                printf("\n RESULTADO %s\n",a.resultado);
                flag=1;

            }

        }

    }

}



arbolPaciente* cargar_arbol_nuevo_practica_x_ingreso(arbolPaciente *arbol)
{




    FILE *archi_practicas = fopen(nombrePracticasxIngreso,"ab");
        int nroIngreso;

    if(archi_practicas)
    {
        mostrar_ingresos();
         printf("Ingrese nro de ingreso \n");
        scanf("%d",&nroIngreso);

        nodoLab * aux= buscar_ingreso_porNumero(arbol,nroIngreso);

                mostrarArchivo();

        if(aux!= NULL)
        { pracXingreso a;
                a=cargar_individual_x_ingreso(nroIngreso);

                nodo_simple_pxi *practica = crear_nodo_pxi(a);
                printf("CARGUE PRAC \n");
                   aux->listaIngresoPrac  = agregar_ppio(aux->listaIngresoPrac,practica);
                printf("CARGUE LISTA \n");
                     fwrite(&a,sizeof(pracXingreso),1,archi_practicas);
                     printf("GUARDE ARCHIVO");
                     system("pause");
        }
    }
    else
    {
        printf("\n");
        printf("no se encontro numero de ingreso solicitado\n");
        system("pause");
    }
    fclose(archi_practicas);


    return arbol;

}

arbolPaciente *modificar_practicas_x_ingreso_incorpora_arbol(arbolPaciente*arbol){

 pracXingreso practicaa;

    FILE *archi_practicas = fopen("practicas.bin","rb");

    if(archi_practicas)
    {

        int nroPractica;
         int nroIngreso;
         mostrar_ingresos();
         printf("Ingrese nro de ingreso \n");
        scanf("%d",&nroIngreso);
       nodoLab * aux = buscar_ingreso_porNumero(arbol,nroIngreso);
       nodo_simple_pxi *aux1=aux->listaIngresoPrac;

        printf("Ingrese nro de practica \n");
        scanf("%d",&nroPractica);
            aux1=buscar_nodo(aux1,nroPractica);
        if(aux1 != NULL)
        {
            rewind(archi_practicas);
            while(fread(&practicaa,sizeof(pracXingreso),1,archi_practicas) > 0)
            {
                if(practicaa.nroPractica == aux1->dato.nroPractica)
                {
                  aux1=modificar_practicas_x_ingreso_contenedora_admin(aux1);

                  fseek(archi_practicas,-1*sizeof(pracXingreso),SEEK_CUR);
                  fwrite(&practicaa,sizeof(pracXingreso),1,archi_practicas);
                }
            }
        }
    }
    else
    {
        printf("no se encontro numero de ingreso solicitado\n");
    }
    fclose(archi_practicas);


return arbol;
}

arbolPaciente *cargar_resultado_practicas_x_ingreso_incorpora_arbol_tecnico(arbolPaciente*arbol){

 pracXingreso practicaa;

    FILE *archi_practicas = fopen("practicas.bin","rb");

    if(archi_practicas)
    {

        int nroPractica;
         int nroIngreso;
         printf("Ingrese nro de ingreso \n");
        scanf("%d",&nroIngreso);
       nodoLab * aux = buscar_ingreso_porNumero(arbol,nroIngreso);
        printf("Ingrese nro de practica \n");
        scanf("%d",&nroPractica);
        nodo_simple_pxi *aux1=buscar_nodo(aux->listaIngresoPrac,nroPractica);
        if(aux1 != NULL)
        {
            rewind(archi_practicas);
            while(fread(&practicaa,sizeof(pracXingreso),1,archi_practicas) > 0)
            {
                if(practicaa.nroPractica == aux1->dato.nroPractica)
                {
                  aux1=cargar_practicas_x_ingreso_tecnico(aux1);
                  fseek(archi_practicas,-1*sizeof(pracXingreso),SEEK_CUR);
                  fwrite(&practicaa,sizeof(pracXingreso),1,archi_practicas);
                }
            }
        }
    }
    else
    {
        printf("no se encontro numero de ingreso solicitado\n");
    }
    fclose(archi_practicas);


return arbol;
}


arbolPaciente * menu_practicas_x_ingreso(arbolPaciente *arbol)
{

    char o=0;
    do
    {
            int nroIngreso=0;
        system("cls");
        consola_vacia();
        gotoxy(2,7);
        printf("1- Cargar un ingreso de practica nuevo ");
        gotoxy(2,8);
        printf("2- Dar de baja un ingreso de practica");
        gotoxy(2,9);
        printf("3- Modificar practica por ingreso ");
        fflush(stdin);
        o=getch();
        switch(o)
        {

        case '1':

            arbol =cargar_arbol_nuevo_practica_x_ingreso(arbol);
            break;

        case '2':

            printf("Ingrese numero de ingreso para dar de baja");
            scanf("%d",&nroIngreso);
           nodoLab *aux = buscar_ingreso_porNumero(arbol,nroIngreso);
           nodo_simple_pxi *aux1=aux->listaIngresoPrac;
           int nroPractica;
           do{
           printf("Ingrese nro de practica a dar de baja \n");
           scanf("%d",&nroPractica);

           }while(buscarid_practica(nroPractica)!=1);

           aux1=buscar_nodo(aux->listaIngresoPrac,nroPractica);
                      aux1= baja_de_pxi(aux1,nroPractica);
            break;
        case '3':
           arbol= modificar_practicas_x_ingreso_incorpora_arbol(arbol);
            break;



        }

    }
    while(o!=27);

    return arbol;
}


