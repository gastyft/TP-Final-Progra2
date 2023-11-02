
#include "practicas_x_ingreso.h"


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
void muestra_individual (pracXingreso a)
{
    printf("\n NUMERO DE PRACTICA: %d\n",a.nroPractica);
    printf("\n NUMERO DE INGRESO %d\n",a.nroIngreso);
    printf("\n RESULTADO %s\n",a.resultado);
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

nodo_simple_pxi * cargar_lista (nodo_simple_pxi * lista)
{
    pracXingreso dato;
    nodo_simple_pxi * aux;
    char opcion = 0;

    while (opcion!=27)
    {
        dato=cargar_individual();
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
