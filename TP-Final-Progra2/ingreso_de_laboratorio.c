
#include "ingreso_laboratorio_nuevo.h"

nodoLab * crear_nodo_lab(ingresosLaboratorio laboratorio)
{
    nodoLab * aux = (nodoLab *)malloc(sizeof(nodoLab));///genero la variable aux para cargarle los datos me llegan por parametro
    aux->labo = laboratorio;
    aux->siguiente=NULL;///como el nodo esta recien creado,el siguiente debe apuntar a NULL
    aux->listaIngresoPrac = NULL;
    return aux;///retorno el nodo creado para luego insertalo
}

nodoLab * agregar_al_principio (nodoLab * listaLab,nodoLab *nuevo)
{
    if (listaLab==NULL)///pregunto si la lista esta vacia
    {
        listaLab=nuevo;
    }
    else
    {
        ///en caso de no estar vacia,inserto el nodo y la luego pasa a ser la cabecera de la lista
        nuevo->siguiente = listaLab;
        listaLab=nuevo;
    }
    return listaLab;///retorno la cabecera de la lista
}

ingresosLaboratorio carga_un_ingreso_laboratorio(int dni)///completo los datos del laboratorio y lo retorno
{
    ingresosLaboratorio laboratorio;
    printf("\nIngrese los datos del ingreso\n");

    laboratorio= asignacion_de_numero_de_ingreso(laboratorio);///le asigna el numero de ingreso correspondiente

    laboratorio.matriculaProfesional = validacion_matricula();///valida que la matricula del profesional no sea negativa

    laboratorio = validacion_fecha_ingreso(laboratorio);///valido que la fecha que se tome es la de el dia actual

    laboratorio = validacion_fecha_retiro(laboratorio);///ver fecha de retiro

    laboratorio.dni=dni;///pone el dni que se le pasa por parametro,que previamente fue cargado en el arbol

    laboratorio.eliminado=0;///comienza en 0 porque se esta creando(1 es que esta eliminado)

    return laboratorio;

}

void muestra_un_laboratorio(ingresosLaboratorio laboratorio)///muestro un solo laboratorio
{
    if(laboratorio.eliminado == 1)///si es igual a 1 es que esta eliminado
    {
        printf("\n LABORATORIO INACTIVO");
    }
    else
    {
        printf("\n LABORATORIO ACTIVO");
    }
    ///muestro los demas datos
    printf("\n Numero de ingreso : %d",laboratorio.numeroIngreso);
    printf("\n Dni : %d",laboratorio.dni);
    printf("\n  Fecha de ingreso: %s",laboratorio.fechaIngreso);
    printf("\n Fecha de retiro : %s",laboratorio.fechaRetiro);
    printf("\n Matricula del profesional : %d\n",laboratorio.matriculaProfesional);
}

ingresosLaboratorio asignacion_de_numero_de_ingreso (ingresosLaboratorio laboratorio)
{
    int cant=validacion_para_cantidad_de_ingresos();/// igualo cant a la cantidad de ingresos que ya se hicieron
    laboratorio.numeroIngreso=cant+1;///al campo de numeroIngreso lo igualo a cant+1 para que se maneje de forma autoincremental
    return laboratorio;
}

int validacion_matricula()
{
    char matricula_char[20];
    int matriculaprofesional;

    do
    {  system("cls");
        printf("\n Numero de matricula del profesional : ");
        fflush(stdin);
        gets(matricula_char);
        if(atoi(matricula_char) < 0)///VALIDA QUE EL NUMERO NO SEA NEGATIVO
        {
            printf("\n El numero de la matricula no puede ser negativo,ingrese un numero correcto");
        }
    }
    while( atoi(matricula_char) < 0 || validar_edad(matricula_char));
    matriculaprofesional = atoi(matricula_char);

    return matriculaprofesional;
}

int validacion_para_cantidad_de_ingresos ()
{
    FILE *archivo =fopen(nombrearchivo,"r+b");///abro el archivo en modo lectura
    int cant=0;
    if(archivo!=NULL)
    {
        fseek(archivo,0,SEEK_END);///me paro al final del archivo
        cant=ftell(archivo)/sizeof(ingresosLaboratorio);///con esa division encuentro la cantidad de registros dentro del archivo
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
    fclose(archivo);
    return cant;///retorno la cantidad de registros encontrados
}

ingresosLaboratorio validacion_fecha_ingreso(ingresosLaboratorio laboratorio) ///VALIDACION DE UNA FECHA MENOR A LA ACTUAL
{
    time_t tiempo_actual;

//Fin estructura TM
    struct tm *info_tiempo;
    char dia[3];
    char mes[3];
    char anio[5];

    /// Obtenemos el tiempo actual
    tiempo_actual = time(NULL);

    /// Convertimos el tiempo a una estructura de tm
    info_tiempo = localtime(&tiempo_actual);

    // Obtenemos el día del mes como cadena
    strftime(dia, sizeof(dia), "%d", info_tiempo);
    strftime(mes, sizeof(mes),"%m",info_tiempo);
    strftime(anio, sizeof(anio),"%Y",info_tiempo);

    sprintf(laboratorio.fechaIngreso,"%s/%s/%s", dia,mes,anio);

    return laboratorio;
}

ingresosLaboratorio validacion_fecha_retiro(ingresosLaboratorio laboratorio) ///VALIDACION DE UNA FECHA MENOR A LA ACTUAL
{

    stFecha fecha;
    time_t tiempo_actual;

//Fin estructura TM
    struct tm *info_tiempo;
    char dia[3];
    char mes[3];
    char anio[5];
    int diaActual,mesActual,anioActual,diasMaximos=0;

    /// Obtenemos el tiempo actual
    tiempo_actual = time(NULL);

    /// Convertimos el tiempo a una estructura de tm
    info_tiempo = localtime(&tiempo_actual);

    // Obtenemos el día del mes como cadena
    strftime(dia, sizeof(dia), "%d", info_tiempo);
    strftime(mes, sizeof(mes),"%m",info_tiempo);
    strftime(anio, sizeof(anio),"%Y",info_tiempo);

    // Convertimos la cadena a entero
    diaActual = atoi(dia);
    mesActual = atoi(mes);
    anioActual =atoi(anio);

    do
    {
        printf("Ingrese anio\n");
        fecha.anio = retorna_dni();

    }
    while(fecha.anio<2023);       ///PIDE AÑO MAYOR O IGUAL A 2023

    if(fecha.anio == anioActual)  /// SI ES AÑO ACTUAL ENTONCES PIDE MES MAYOR O IGUAL AL ACTUAL
    {
        do
        {
            printf("Ingrese mes ><<<<<<<<<<<<<\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes<1 || mesActual > fecha.mes || fecha.mes > 12); ///COMPRUEBA QUE EL MES NO SEA MENOR A 1 Y QUE SEA MAYOR O IGUAL AL MES ACTUAL

        if(fecha.mes == mesActual) /// SI EL MES ES ACTUAL ENTONCES VALIDA QUE MES ES PARA ASIGNARLE LE MAXIMO DE DIAS DE ESE MES
        {
            do    /// si es mayor al dia actual no habria porque validar en el switch
            {
                printf("Ingrese dia\n");   /// PIDE UN DIA MENOR O IGUAL AL ACTUAL
                fecha.dia = retorna_dni();
            }
            while(fecha.dia<1 || diaActual>fecha.dia); ///VALIDA QUE NO SEA MENOR A 1 Y QUE SUPERE EL O IGUALE EL DIA ACTUAL
        }
        else
        {
            switch (fecha.mes)
            {
            case 2:
                /// Verificar si el año es bisiesto para febrero
                if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                    diasMaximos = 29;
                else
                    diasMaximos = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diasMaximos = 30;
                break;
            default:
                diasMaximos = 31;
                break;
            }
            do
            {
                printf("Ingrese dia\n");
                fecha.dia = retorna_dni();
            }
            while(fecha.dia > diasMaximos);
        }
    }
    else /// si no es anio actual
    {
        do
        {
            printf("Ingrese mes\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes>12 || fecha.mes<1 ); ///VALID QUE EL MES QUE PONGA SEA ENTRE 1 Y 12

        switch (fecha.mes)
        {
        case 2:
            /// Verificar si el año es bisiesto para febrero
            if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                diasMaximos = 29;
            else
                diasMaximos = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMaximos = 30;
            break;
        default:
            diasMaximos = 31;
            break;
        }
        do
        {
            printf("Ingrese dia \n");
            fecha.dia = retorna_dni();
        }
        while( fecha.dia<1  || fecha.dia >diasMaximos);

    }
    sprintf(laboratorio.fechaRetiro,"%d/%d/%d", fecha.dia,fecha.mes,fecha.anio);
    return laboratorio;
}

ingresosLaboratorio validacion_modificacion_retiro(ingresosLaboratorio laboratorio){

    stFecha fecha;



    int diaActual = 0,mesActual = 0,anioActual = 0,diasMaximos=0;

  for (int j = 0; j < 10; j++) {
        if (j < 2) {
            diaActual = diaActual * 10 + atoi(&laboratorio.fechaIngreso[j]);
        } else if (j > 2 && j < 5) {
            mesActual = mesActual * 10 + atoi(&laboratorio.fechaIngreso[j]);
        } else if (j > 5 && j < 10) {
            anioActual = anioActual * 10 + atoi(&laboratorio.fechaIngreso[j]);
        }
    }

    do
    {
        printf("Ingrese anio\n");
        fecha.anio = retorna_dni();

    }
    while(fecha.anio<2023);       ///PIDE AÑO MAYOR O IGUAL A 2023

    if(fecha.anio == anioActual)  /// SI ES AÑO ACTUAL ENTONCES PIDE MES MAYOR O IGUAL AL ACTUAL
    {
        do
        {
            printf("Ingrese mes\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes<1 || mesActual>=fecha.mes); ///COMPRUEBA QUE EL MES NO SEA MENOR A 1 Y QUE SEA MAYOR O IGUAL AL MES ACTUAL

        if(fecha.mes == mesActual) /// SI EL MES ES ACTUAL ENTONCES VALIDA QUE MES ES PARA ASIGNARLE LE MAXIMO DE DIAS DE ESE MES
        {
            do    /// si es mayor al dia actual no habria porque validar en el switch
            {
                printf("Ingrese dia\n");   /// PIDE UN DIA MENOR O IGUAL AL ACTUAL
                fecha.dia = retorna_dni();
            }
            while(fecha.dia<1 || diaActual>=fecha.dia); ///VALIDA QUE NO SEA MENOR A 1 Y QUE SUPERE EL O IGUALE EL DIA ACTUAL
        }
        else
        {
            switch (fecha.mes)
            {
            case 2:
                /// Verificar si el año es bisiesto para febrero
                if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                    diasMaximos = 29;
                else
                    diasMaximos = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diasMaximos = 30;
                break;
            default:
                diasMaximos = 31;
                break;
            }
            do
            {
                printf("Ingrese dia\n");
                fecha.dia = retorna_dni();
            }
            while(fecha.dia > diasMaximos);
        }
    }
    else /// si no es anio actual
    {
        do
        {
            printf("Ingrese mes\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes>12 || fecha.mes<1 ); ///VALID QUE EL MES QUE PONGA SEA ENTRE 1 Y 12

        switch (fecha.mes)
        {
        case 2:
            /// Verificar si el año es bisiesto para febrero
            if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                diasMaximos = 29;
            else
                diasMaximos = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMaximos = 30;
            break;
        default:
            diasMaximos = 31;
            break;
        }
        do
        {
            printf("Ingrese dia \n");
            fecha.dia = retorna_dni();
        }
        while( fecha.dia<1   || fecha.dia >diasMaximos);

    }
    sprintf(laboratorio.fechaRetiro,"%d/%d/%d", fecha.dia,fecha.mes,fecha.anio);
    return laboratorio;
}


ingresosLaboratorio validacion_modificacion_ingreso(ingresosLaboratorio laboratorio){

    stFecha fecha;



    int diaRetiro = 0,mesRetiro = 0,anioRetiro = 0,diasMaximos=0;

  for (int j = 0; j < 10; j++) {
        if (j < 2) {
            diaRetiro = diaRetiro * 10 + atoi(&laboratorio.fechaRetiro[j]);
        } else if (j > 2 && j < 5) {
            mesRetiro = mesRetiro * 10 + atoi(&laboratorio.fechaRetiro[j]);
        } else if (j > 5 && j < 10) {
            anioRetiro = anioRetiro * 10 + atoi(&laboratorio.fechaRetiro[j]);
        }
    }

    do
    {
        printf("Ingrese anio\n");
        fecha.anio = retorna_dni();

    }
    while(fecha.anio>anioRetiro);       ///PIDE AÑO MAYOR O IGUAL A 2023

    if(fecha.anio == anioRetiro)  /// SI ES AÑO ACTUAL ENTONCES PIDE MES MAYOR O IGUAL AL ACTUAL
    {
        do
        {
            printf("Ingrese mes\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes<1 || mesRetiro<fecha.mes); ///COMPRUEBA QUE EL MES NO SEA MENOR A 1 Y QUE SEA MENOR O IGUAL AL MES RETIRO

        if(fecha.mes == mesRetiro) /// SI EL MES ES ACTUAL ENTONCES VALIDA QUE MES ES PARA ASIGNARLE LE MAXIMO DE DIAS DE ESE MES
        {
            do    /// si es mayor al dia actual no habria porque validar en el switch
            {
                printf("Ingrese dia\n");   /// PIDE UN DIA MENOR O IGUAL AL ACTUAL
                fecha.dia = retorna_dni();
            }
            while(fecha.dia<1 || diaRetiro<fecha.dia); ///VALIDA QUE NO SEA MENOR A 1 Y QUE SUPERE EL O IGUALE EL DIA ACTUAL
        }
        else
        {
            switch (fecha.mes)
            {
            case 2:
                /// Verificar si el año es bisiesto para febrero
                if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                    diasMaximos = 29;
                else
                    diasMaximos = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diasMaximos = 30;
                break;
            default:
                diasMaximos = 31;
                break;
            }
            do
            {
                printf("Ingrese dia\n");
                fecha.dia = retorna_dni();
            }
            while(fecha.dia > diasMaximos);
        }
    }
    else /// si no es anio actual
    {
        do
        {
            printf("Ingrese mes\n");
            fecha.mes = retorna_dni();
        }
        while(fecha.mes>12 || fecha.mes<1 ); ///VALID QUE EL MES QUE PONGA SEA ENTRE 1 Y 12

        switch (fecha.mes)
        {
        case 2:
            /// Verificar si el año es bisiesto para febrero
            if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
                diasMaximos = 29;
            else
                diasMaximos = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMaximos = 30;
            break;
        default:
            diasMaximos = 31;
            break;
        }
        do
        {
            printf("Ingrese dia \n");
            fecha.dia = retorna_dni();
        }
        while( fecha.dia<1   || fecha.dia >diasMaximos);

    }
    sprintf(laboratorio.fechaIngreso,"%d/%d/%d", fecha.dia,fecha.mes,fecha.anio);
    return laboratorio;
}

arbolPaciente * modificar_fecha_ingreso(arbolPaciente * arbol)
{
    int nroingreso=0,flag=0;

    printf("Ingrese el numero de ingreso\n");///le pide el numero de ingreso para ir a buscar al archivo
    nroingreso = retorna_dni();
    nodoLab* aux=buscar_ingreso_porNumero(arbol,nroingreso);
        FILE * archi=fopen(nombrearchivo,"r+b");
    if(aux){
    aux->labo = validacion_modificacion_ingreso(aux->labo);
    ingresosLaboratorio laboratorio;
    if(archi!=NULL)
    {

        while(flag==0 && fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0)///lee el archivo y verifica que el flag siga en 0
        {
            if(laboratorio.numeroIngreso==aux->labo.numeroIngreso)///compara los numeros de ingreso
            {
                fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                fwrite(&aux->labo,sizeof(ingresosLaboratorio),1,archi);
                flag=1;

            }
        }
    }
    else
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO\n");
    }

    }
    if(flag==0 || !aux)
    {
        printf("El numero de ingreso %d no existe\n",nroingreso);
    }
    else
    {
        printf("La fecha de ingreso ha sido modificada con exito\n");
    }


fclose(archi);
    return arbol;
}

arbolPaciente * modificar_fecha_retiro(arbolPaciente * arbol)
{
    int nroingreso=0,flag=0;

    printf("Ingrese el numero de ingreso\n");///le pide el numero de ingreso para ir a buscar al archivo
    nroingreso = retorna_dni();
    nodoLab* aux=buscar_ingreso_porNumero(arbol,nroingreso);
    if(aux){
    aux->labo= validacion_modificacion_retiro(aux->labo);
        FILE * archi=fopen(nombrearchivo,"r+b");
    ingresosLaboratorio laboratorio;
    if(archi!=NULL)
    {
        rewind(archi);
        while(fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0 && flag==0)///lee el archivo y verifica que el flag siga en 0
        {
            if(laboratorio.numeroIngreso==aux->labo.numeroIngreso)///compara los numeros de ingreso
            {
                fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                fwrite(&aux->labo,sizeof(ingresosLaboratorio),1,archi);
                flag=1;
            }
        }
    }
    else
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO\n");
    }
     fclose(archi);
    }
    if(flag==0 || !aux)
    {
        printf("El numero de ingreso %d no existe\n",nroingreso);
    }
    else
    {
        printf("La fecha de ingreso ha sido modificada con exito\n");
    }

    return arbol;
}



int retorna_dni()
{
   char dni_char[15];
     int dni;

    gets(dni_char);
   while( validar_edad(dni_char)){           /// valida si es un numero
         system("cls");
        consola_vacia();
         gotoxy(1,7);
     printf("\t no corresponde a un NUMERO \n");
     gets(dni_char);

   }
   dni = atoi(dni_char);
    return dni;
}

arbolPaciente * modificar_matricula_profesional (arbolPaciente * arbol)
{
    int nroingreso=0,matriculanueva=0,flag=0;
    arbolPaciente *arbolaux=arbol;
    printf("Ingrese el numero de ingreso\n");///le pide el numero de ingreso para ir a buscar al archivo
    scanf("%d",&nroingreso);
    FILE * archi=fopen(nombrearchivo,"r+b");
    ingresosLaboratorio laboratorio;
    int dni;
    if(archi!=NULL)
    {
        rewind(archi);
        while(fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0 && flag==0)///lee el archivo y verifica que el flag siga en 0
        {
            if(nroingreso==laboratorio.numeroIngreso)///compara los numeros de ingreso
            {
                laboratorio.matriculaProfesional=validacion_matricula(); ///al laboratorio le asignamos la nueva matricula
                dni=laboratorio.dni;
                fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archi);
                arbolaux = buscar_paciente(arbolaux,dni);
                nodoLab * seg = arbolaux->ingresos;
                while(seg)
                {
                    if(seg->labo.numeroIngreso==nroingreso)
                    {
                        seg->labo.matriculaProfesional=matriculanueva;
                    }
                    seg=seg->siguiente;
                }
                flag=1;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO\n");
    }
    if(flag==0)
    {
        printf("El numero de ingreso %d no existe\n",nroingreso);
    }
    else
    {
        printf("La matricula del profesional ha sido modificada con exito\n");
    }
    return arbol;
}

//arbolPaciente *modificacion_fecha_ingreso(arbol){
//    ingresosLaboratorio laboratorio;
// int dni=retorna_dni();
//        arbolPaciente * arbolaux = buscar(arbol,dni);
//        int flag=0;
//
//    if(arbolaux!=NULL){
//          nodoLab * seg= arbolaux->ingreso;
//          nodoLab * aux= arbolaux->ingreso;
//             while(flag &&seg){
//
//                if(nroingreso==seg->labo.numeroIngreso){
//
//                        aux=seg;
//
//                    flag=1;
//                }
//
//                seg=seg->siguiente;
//             }
//
//            printf("La fecha es %s\n",aux->labo.fechaIngreso);
//            ///PEDIR DIA MES Y ANIO
//
//
//    }
//
//return arbolaux;
//}


nodoLab * cambiar_estado_eliminado_lista(arbolPaciente *arbol,int nroingreso,int dni,int flag)
{
    arbolPaciente * arbolaux = buscar_paciente(arbol,dni);
    nodoLab * seg = arbolaux->ingresos;
    while(seg!=NULL)
    {
        if(nroingreso==seg->labo.numeroIngreso)
        {
            if(flag==0)
            {
                seg->labo.eliminado=1;
            }
            else
            {
                seg->labo.eliminado=0;
            }
        }
        seg=seg->siguiente;
    }
    return arbol->ingresos;
}

void cambiar_estado_eliminado (int dniabuscar, int flag)
{
    ingresosLaboratorio laboratorio;
    FILE * archi = fopen(nombrearchivo,"r+b");
    if(archi!=NULL)
    {
        rewind(archi);
        while(fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0)
        {
            if(dniabuscar==laboratorio.dni)
            {
                if(flag==0)
                {
                    fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                    laboratorio.eliminado=0;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archi);
                }
                else
                {
                    fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                    laboratorio.eliminado=1;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archi);
                }
            }
        }
        fclose(archi);
    }
}

arbolPaciente * alta_ingresos_laboratorio(arbolPaciente * arbol)
{
    ingresosLaboratorio laboratorio;
    FILE * archi= fopen("ingresos.bin","a+b");
    if(archi)
    {      int dni;

            printf("\t ingrese un DNI \n");
            dni = retorna_dni();



        arbolPaciente * arbolaux = buscar_paciente(arbol,dni);
        if(arbolaux!=NULL)
        {
            laboratorio=carga_un_ingreso_laboratorio(dni);
            nodoLab *nuevo = crear_nodo_lab(laboratorio);  /// creo el ingreso nuevo

            pracXingreso aux;
            aux.nroIngreso = laboratorio.numeroIngreso;
            aux.eliminado = 0;
            strcpy(aux.resultado,"sin resultado");
            int  num;

            do{
                printf(" \t ingrese el numero de practica \n");
                num = retorna_dni();

            }while(buscarid_practica(num)== 0);
            aux.nroPractica = num;
            carga_alta_pracXingreso(aux);
            nodo_simple_pxi *practica = crear_nodo_pxi(aux); /// creo el nodo de la practica

            nuevo->listaIngresoPrac = agregar_ppio(nuevo->listaIngresoPrac,practica);

            arbolaux->ingresos=agregar_al_principio(arbolaux->ingresos,nuevo); /// Agrego la practica al ingreso


            fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archi);
        }

        else
        {   system("cls");
            printf("\t No existe el paciente con el DNI %d \n\t",dni);
            system("pause");
        }
    }
    else
        printf("ERROR EN EL ARCHIVO\n");
    fclose(archi);
    return arbol;
}

arbolPaciente * baja_ingresos_laboratorio(arbolPaciente * arbol)
{

  char ingreso[15];
     int ingreso_num;
     mostrar_ingresos();
     printf("\n\t ingrese el numero de ingreso a dar de Baja \n");
       fflush(stdin);
        gets(ingreso);
   while( validar_edad(ingreso)){           /// valida si es un numero
     system("cls");
     consola_vacia();
     gotoxy(1,7);
     printf("\t no corresponde a un Numero \n");
     printf("\t ingrese un numero de ingreso ");
     fflush(stdin);
     gets(ingreso);

   }

   ingreso_num = atoi(ingreso);

   nodoLab *buscar = buscar_ingreso_porNumero(arbol,ingreso_num);

   if(buscar){

        if(buscar->labo.eliminado == 1){


            printf("\t el ingreso ya fue dado de baja \n \t");
            system("pause");

        }
        else{
         buscar->labo.eliminado = 1;
         nodo_simple_pxi *encontrado = buscar->listaIngresoPrac;

         while(encontrado != NULL){
            encontrado->dato.eliminado = 1;
            encontrado = encontrado->siguiente;


         }


            FILE *archi =fopen("ingresos.bin","r+b");
            FILE *arch = fopen("practicas.bin","r+b");
            int flag = 0;

            ingresosLaboratorio laboratorio;
            pracXingreso prac;

    if(archi!=NULL)
    {
        rewind(archi);
        while(fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0 && flag == 0)
        {
            if(ingreso_num ==laboratorio.numeroIngreso)
            {

                    laboratorio.eliminado=1;
                    fseek(archi,-1*sizeof(ingresosLaboratorio),SEEK_CUR);
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archi);
                    flag = 1;


            }
        }
        fclose(archi);
    }
    if(arch!=NULL)
    {
        rewind(arch);
    while(fread(&prac,sizeof(pracXingreso),1,arch)> 0)
    {
            if(prac.nroIngreso == ingreso_num)
            {
                    prac.eliminado = 1;
                    fseek(archi,-1*sizeof(pracXingreso),SEEK_CUR);
                    fwrite(&laboratorio,sizeof(pracXingreso),1,archi);

            }


    }

      fclose(arch);

    }


        }

    }
    return arbol;
}

void consulta_por_numero_de_ingreso(arbolPaciente *arbol)
{
    int nrodeingreso=0,flag=0;
    ingresosLaboratorio laboratorio;
    printf("Ingrese el numero de ingreso del paciente que quiere consultar");
    scanf("%d",&nrodeingreso);
   nodoLab *aux= buscar_ingreso_porNumero(arbol,nrodeingreso);
    FILE * archi =fopen(nombrearchivo,"r+b");
    if(archi!=NULL)
    {
        rewind(archi);
        while(fread(&laboratorio,sizeof(ingresosLaboratorio),1,archi)>0)
        {
            if(laboratorio.numeroIngreso==nrodeingreso)
            {
                flag=1;
                muestra_un_laboratorio(laboratorio);


                        muestra_lista(aux->listaIngresoPrac);

            }
        }
        if(flag==0)
        {
            printf("El nro de ingreso %d no se encuentra en el sistema",nrodeingreso);
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
    }
}

void consulta_por_dni(arbolPaciente * arbol)
{
    int dni=retorna_dni();


    arbolPaciente * arbolaux = buscar_paciente(arbol,dni);
    if(arbolaux!=NULL)
    {
        nodoLab * seg =arbolaux->ingresos;
        while(seg)
        {
            muestra_un_laboratorio(seg->labo);
            muestra_lista(seg->listaIngresoPrac);
            seg = seg->siguiente;
        }
    }
    else
    {
        printf("El DNI %d no se encuentra en el sistema",dni);
    }
}


///MENUS INGRESO LABORATORIOS
arbolPaciente * menu_ingresos_laboratorio (arbolPaciente * arbol)
{

    char o=0;

  do  {
    system("cls");

    printf("\n\t    [1] Alta \n");
    printf("\t    [2] Baja \n");
    printf("\t    [3] Modificacion \n");
    printf("\t    [4]Consulta \n");

    fflush(stdin);
    o=getch();
    system("cls");
        switch(o)
        {
        case '1':
            arbol=alta_ingresos_laboratorio(arbol);
            break;

        case '2':
            arbol=baja_ingresos_laboratorio(arbol);
            break;

        case '3':
            menu_modificacion_ingresos_laboratorio(arbol);
            break;

        case '4':
            menu_consulta_ingresos_laboratorio(arbol);
            break;

        case 27:

            break;
        default:
            printf("Ingrese una de las opciones o ESC para volver hacia atras\n");
            fflush(stdin);
            o=getch();
        }
    }while(o!=ESC);
    return arbol;
}


void menu_modificacion_ingresos_laboratorio(arbolPaciente * arbol)
{
    char o=0;

    do{
    printf("Desea modificar : \n[1] Fecha Ingreso \n [2] Fecha Retiro \n [3] Matricula del profesional \n [ESC] ESCAPE");
    fflush(stdin);
    o=getch();
    system("cls");
        switch(o)
        {
        case '1':
            mostrar_ingresos();

          arbol= modificar_fecha_ingreso(arbol);
            break;

        case '2':
            mostrar_ingresos();
       arbol = modificar_fecha_retiro(arbol);
            break;
        case '3':
            mostrar_ingresos();
          arbol=  modificar_matricula_profesional(arbol);
            break;

        case 27:

            break;
        default:
            printf("Ingrese una de las opciones o ESC para volver hacia atras\n");
            fflush(stdin);
            o=getch();
        }
    }  while(o!=ESC);
}

void menu_consulta_ingresos_laboratorio(arbolPaciente * arbol)
{
    char o=0;


    do{
    printf("Desea consultar : \n[1] Ingreso especifico \n [2] Todos los ingresos de un paciente \n [ESC] ESCAPE");
    fflush(stdin);
    o=getch();
    system("cls");
        switch(o)
        {
        case '1':
            consulta_por_numero_de_ingreso(arbol);
            break;

        case '2':
            consulta_por_dni(arbol);
            break;

        case 27:

            break;
        default:
            printf("Ingrese una de las opciones o ESC para volver hacia atras\n");
            fflush(stdin);
            o=getch();
        }
    }  while(o!=ESC);
}

nodoLab* buscar_ingreso_recorrer(nodoLab *ingreso, int dato){

     nodoLab *rta = NULL;

     if(ingreso != NULL){
            if(ingreso->labo.numeroIngreso == dato){

                return ingreso;
            }else{

             rta = buscar_ingreso_recorrer(ingreso->siguiente,dato);

            }
     }

  return rta;

}


nodoLab* buscar_ingreso_porNumero(arbolPaciente *arbol,int dato)
{

    nodoLab *rta = NULL;

    if (arbol != NULL) {

        if (arbol->ingresos != NULL) {

          rta =  buscar_ingreso_recorrer(arbol->ingresos,dato);

          if(rta != NULL){
           printf("entro \n");
            return rta;
          }
        }

        // Buscar en el subárbol derecho
        rta = buscar_ingreso_porNumero(arbol->der, dato);

        // Si no se encuentra en el subárbol derecho, buscar en el subárbol izquierdo
        if (rta == NULL) {
            rta = buscar_ingreso_porNumero(arbol->izq, dato);
        }
    }

    return rta;
}

 void mostrar_ingreso (ingresosLaboratorio a, int i){ /// BUSCAR CABECERA

 setConsoleColor(15,5);
   gotoxy(3,i);  printf("    %-23i ",a.numeroIngreso);

   gotoxy(15,i); printf("  %-15s ",a.fechaIngreso);

   gotoxy(30,i); printf("  %-15s ",a.fechaRetiro);
   gotoxy(46,i); printf("  %-15i ",a.dni);
   gotoxy(62,i); printf("  %-15i ",a.matriculaProfesional);
   gotoxy(80,i); if (a.eliminado == 0)
    {
        setConsoleColor(15,10); // Verde
        printf("  %-14s", "No");
    }
    else
    {

        setConsoleColor(15,4);// Rojo
        printf("  %-14s", "Si");
    }
    setConsoleColor(11,0);
   }




