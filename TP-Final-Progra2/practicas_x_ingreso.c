#include "practicas_x_ingreso.h"


pracXingreso cargar_individual_x_ingreso (int nroIngreso)
{
    pracXingreso a;
    ///  FILE *archi=fopen(nombrePracticas,"r+b"); ///NRO INGRESO SE DE TRAER DE INGRESO X LABORATORIO
//    int cant=0;
//    if(archi){
//    fseek(archi,0,SEEK_END);
//cant=ftell(archi)/sizeof(pracXingreso);    ///AUTOINCREMENTAL: CUENTO CANTIDAD QUE SE ENCUENTRAN EN ARCHIVO Y LE SUMO 1
//    }
//    else
//        printf("ERROR EN CARGAR INDIVIDUAL\n");

    a.nroIngreso=nroIngreso;
    printf("\nIngrese resultado\n");
    fflush(stdin);
    gets(a.resultado);
    /// esto no es asi, se hace autoincremental

    printf("\nIngrese numero de practica\n");
    scanf("%d",&a.nroPractica);

    return a;
}

void muestra_individual (pracXingreso a)
{
    FILE *archi=fopen(nombrePracticas,"r+b");
    int flag=0;
    if(archi)
    {
        practicas prac;
        while(fread(&prac,sizeof(practicas),1,archi)>0 && flag)
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
        muestra_individual(lista->dato);
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
        while (seg!=NULL &&seg->dato.nroIngreso!=dato)
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

    nodo_simple_pxi* aux=inic_lista();

    int nroAbuscar;
    int flag=0;
    printf("Ingrese el numero de ingreso para modificar \n");
    scanf("%d",&nroAbuscar);
    char o=0;
    while(flag || o!=27)
    {
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
    printf("Ingrese el numero de ingreso a cargar resultado \n");
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
            ///Verificar si al devolver esta funcion te devuelve el nodo editado conectado a la lista o hay que conectarlo
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


nodo_simple_pxi *baja_de_pxi(nodo_simple_pxi *lista,int nroIngreso)
{

    FILE *archi=fopen(nombrePracticasxIngreso,"r+b");
    pracXingreso prac;
    int flag=0;
    if(archi)
    {
        while(flag && fread(&prac,sizeof(pracXingreso),1,archi)>0)
        {
            if(nroIngreso==prac.nroIngreso)
            {
                prac.eliminado=1;
                fseek(archi,-1*sizeof(pracXingreso),SEEK_CUR);
                fwrite(&prac,sizeof(pracXingreso),1,archi);
                flag=1;
            }
        }

        if(flag)
        {
            printf("No se encontro el nro de ingreso\n");
            lista=NULL;
        }

    }
    else
        printf("ERROR  EN EL ARCHIVO EN FUNCION BAJA DE PXI\n");

    return lista;
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






//void menu_practicas_x_ingreso(){
//
//char o=0;
//practicas *prac=NULL;
//int dimension=0;
// int validos= pasar_archivo_practicas_a_arreglo(prac,&dimension);
//
//
//
//do{
//system("cls");
//consola_vacia();
//gotoxy(2,7);
//printf("1- Cargar un ingreso de practica nuevo ");
//gotoxy(2,8);
//printf("2- Dar de baja un ingreso de practica");
//gotoxy(2,9);
//
//
//switch(o){
//
//case '1':
//    int num=0;
//    int nroIngreso=0;
//    printf("Ingrese nro de ingreso ");
//    scanf("%d",&nroIngreso);
//    ///VALIDACION NRO INGRESO EXISTA
//    printf("Ingrese nro de practica a cargar \n");
//    scanf("%d",&num);
//    prac=validar_nro_practica_exista(arr,validos,nroPractica);
//
//    cargar
//    break;

//}

//}while(o!=27);

//}
