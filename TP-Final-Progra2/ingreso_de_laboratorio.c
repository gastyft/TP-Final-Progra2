
#include "ingreso_de_laboratorio.h"


nodoLab * inic_lista()
{
    return NULL;
}

nodoLab * crear_nodo_lab(ingresosLaboratorio laboratorio)
{
    nodoLab * aux = (nodoLab *)malloc(sizeof(nodoLab));///genero la variable aux para cargarle los datos me llegan por parametro
    aux->labo.dni=laboratorio.dni;
    aux->labo.eliminado=laboratorio.eliminado;
    strcpy(aux->labo.fechaIngreso,laboratorio.fechaIngreso);
    strcpy(aux->labo.fechaRetiro,laboratorio.fechaRetiro);
    aux->labo.matriculaProfesional=laboratorio.matriculaProfesional;
    aux->labo.numeroIngreso=laboratorio.numeroIngreso;
    aux->siguiente=NULL;///como el nodo esta recien creado,el siguiente debe apuntar a NULL
    return aux;///retorno el nodo creado para luego insertalo
}

nodoLab * agregar_al_principio (ingresosLaboratorio laboratorio,nodoLab * listaLab)
{
    nodoLab * nuevo = crear_nodo_lab(laboratorio); ///creo el nodo
    if (listaLab==NULL)///pregunto si la lista esta vacia
    {
        listaLab=nuevo;
    }
    else
    {
        ///en caso de no estar vacia,inserto el nodo y la luego pasa a ser la cabecera de la lista
        nuevo=listaLab;
        listaLab=nuevo;
    }
    return listaLab;///retorno la cabecera de la lista
}


ingresosLaboratorio carga_un_ingreso_laboratorio(char nombrearchivo[])///completo los datos del laboratorio y lo retorno
{
    ingresosLaboratorio laboratorio;
    printf("\nIngrese los datos del ingreso \n");

    printf("\n Numero de matricula del profesional: ");
    scanf("%d",&laboratorio.matriculaProfesional);

    printf("\n Fecha de ingreso : ");
    fflush(stdin);
    gets(laboratorio.fechaIngreso);

    printf("\n Fecha de retiro : ");
    fflush(stdin);
    gets(laboratorio.fechaRetiro);


    laboratorio.eliminado=0;

    return laboratorio;
}

void cargar_archivo_laboratorio(char nombrearchivo[])
{
    FILE * archivo =fopen(nombrearchivo,"a+b");
    ingresosLaboratorio laboratorio;
    if(archivo!=NULL)
    {
        laboratorio=carga_un_ingreso_laboratorio(nombrearchivo);
        fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archivo);
    }
    else
    {
        printf("ERROR EN LA APARTURA DEL ARCHIVO \n");
    }
}

void baja_laboratorio_por_dni (char nombrearchivo[])
{
    FILE * archivo = fopen(nombrearchivo,"r+b");///abrimos el archivo de laboratorio en modo lectura
    ingresosLaboratorio laboratorio;
    int flag=1;
    int dniaborrar;
    if(archivo != NULL)
    {
        printf("Ingrese dni  \n");///preguntamos por el dni que luego comparemos para eliminar el laboratorio
        scanf("%d",&dniaborrar);

        while(flag && fread(&laboratorio,sizeof(ingresosLaboratorio),1,archivo)>0) ///corroboramos si encontro el dato mediante el flag y despues leemos del archivo
        {
            if(dniaborrar==laboratorio.dni)///comparo el dni que se quiere borrar con el dni del archivo
            {
                if(laboratorio.eliminado == 1)///si entra aca es porque ya estaba dado de baja dado de baja
                {
                    printf("El laboratorio de la persona con el DNI %d ya estaba dado de baja \n",laboratorio.dni);
                    flag=0;
                }
                else
                {
                    fseek(archivo,(-1)*sizeof(ingresosLaboratorio),SEEK_CUR);///retrocedemos el cursor un registro
                    laboratorio.eliminado=1;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archivo);///escribimos en el archivo,cambiando el campo ELIMINADO a 1
                    flag=0;///cambiamos el flag a 0 para que salga del while y no siga leyendo el archivo
                    printf("Baja exitosa \n");
                }
            }
        }
        if(flag == 1)
        {
            printf("No se encontro pacientes con ese DNI. Intente nuevamente. \n");
        }
        fclose(archivo);
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
}

///validaciones
/*stpaciente validacion_dni_existente(char nombreArchivo[],stpaciente paciente,int *flag) ///validar si el dni ya se encuentra en el archivo para que no existan 2 personas con un mismo dni
{
    stPaciente pacienteValido;
    char o=0;
    FILE *archivo=fopen(nombreArchivo,"r+b");
    rewind(archivo);///no se si va
    if(archivo!=NULL)
    {
        while(*flag && fread(&pacienteValido,sizeof(stPaciente),1,archivo)>0)///corroboramos si encontro el dato mediante el flag y despues leemos del archivo
        {
            if(paciente.dni==pacienteValido.dni)///pregunta si los dni son iguales
            {
                printf("El dni ya existe,presione cualquier tecla para cargar un nuevo DNI o ESCAPE para salir\n");///
                fflush(stdin);
                o=getch();
                if(o==ESC)///fijate que hacria que poner a ESC como constante
                {
                    *flag=0;///forzamos la condicion de corte porque el usuario quiere salir
                }
                else
                {
                    ///sino pulsa escape le preguntamos nuevamente por el dni a buscar
                    system("cls");
                    printf("Ingrese nuevo DNI\n");
                    scanf("%d",&paciente.dni);
                    rewind(archivo);///ponemos el archivo al principio para que vuelva a hacer las comparaciones
                }
                system("cls");
            }
        }
        system("cls");
        fclose(archivo);
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
    return paciente;
}*/

int cantidad_de_ingresos (char nombrearchivo[])///cuento la cantidad de ingresos para despues poder saber el numero de ingreso de la proxima persona
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
    return cant;///retorno la cantidad de registros encontrados
}

void muestraArchivoLaboratorios(char nombreArchivo[]) ///MUESTRA ARCHIVO LABORATORIOS
{
    ingresosLaboratorio laboratorio;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo!=NULL)
    {
        while(fread(&laboratorio, sizeof(ingresosLaboratorio), 1, archivo) > 0)
        {
            muestra_un_laboratorio(laboratorio);
        }
        fclose(archivo);
    }
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO \n");
    }
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
    printf("\n Matricula del profesional : %d",laboratorio.matriculaProfesional);


}
/*
void carga_puntos()
{
    int i,j;
    int num_puntos = 2;
    for (i = 0; i < 8; i++)
    {
        // Imprimir los puntos con movimiento

        for (j = 0; j < num_puntos; j++)
        {
            printf(".");
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
    system("cls");
}
*/

ingresosLaboratorio  asignacion_de_numero_de_ingreso (ingresosLaboratorio laboratorio,char nombrearchivo [])
{
    int cant=cantidad_de_ingresos(nombrearchivo);/// igualo cant a la cantidad de ingresos que ya se hicieron
    laboratorio.numeroIngreso=cant+1;///al campo de numeroIngreso lo igualo a cant+1 para que se maneje de forma autoincremental
    return laboratorio;
}

void menu_baja_laboratorio(char nombrearchivo[])
{
    char o=0;
    printf("1) Eliminarlo por DNI \n 2)Eliminarlo por Numero de ingreso al laboratorio");
    fflush(stdin);
    o=getch();
    system("cls");
    while(o!=ESC)
    {
        switch(o)
        {
        case '1':
            baja_laboratorio_por_dni(nombrearchivo);
            system("cls");
            break;

        case '2':

            baja_laboratorio_por_ingreso(nombrearchivo);
            system("pause");

            break;
        case 27:

            break;
        default:

            printf("Ingrese una de las opciones o ESC para volver hacia atras\n");
            fflush(stdin);
            o=getch();
        }
    }
}

void baja_laboratorio_por_ingreso(char nombrearchivo [])
{
    FILE * archivo = fopen(nombrearchivo,"r+b");///abrimos el archivo de laboratorio en modo lectura
    ingresosLaboratorio laboratorio;
    int flag=1;
    int numeroingreso;
    if(archivo != NULL)
    {
        printf("Ingrese el numero de ingreso del paciente  \n");///preguntamos por el numero de ingreso del paciente que luego comparemos para eliminar el laboratorio
        scanf("%d",&numeroingreso);

        while(flag && fread(&laboratorio,sizeof(ingresosLaboratorio),1,archivo)>0) ///corroboramos si encontro el dato mediante el flag y despues leemos del archivo
        {
            if(numeroingreso==laboratorio.numeroIngreso)///comparamos el numero de ingreso que se quiere borrar con el los numeros de ingreso del archivo
            {
                if(laboratorio.eliminado == 1)///si entra aca es porque ya estaba dado de baja dado de baja
                {
                    printf("El laboratorio de la persona que ingreso con el numero %d ya estaba dado de baja \n",laboratorio.numeroIngreso);
                    flag=0;
                }
                else
                {
                    fseek(archivo,(-1)*sizeof(ingresosLaboratorio),SEEK_CUR);///retrocedemos el cursor un registro
                    laboratorio.eliminado=1;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archivo);///escribimos en el archivo,cambiando el campo ELIMINADO a 1
                    flag=0;///cambiamos el flag a 0 para que salga del while y no siga leyendo el archivo
                    printf("Baja exitosa \n");
                }
            }
        }
        if(flag == 1)
        {
            printf("El paciente con ingreso %d no existe. Intente nuevamente. \n", numeroingreso);
        }
        fclose(archivo);
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
}

void menu_alta_laboratorio(char nombrearchivo[])
{
    char o=0;
    printf("1) Alta por DNI \n 2)Alta por numero de ingreso al laboratorio");
    fflush(stdin);
    o=getch();
    system("cls");
    while(o!=ESC)
    {
        switch(o)
        {
        case '1':
            alta_laboratorio_por_dni(nombrearchivo);
            system("cls");
            break;

        case '2':

            alta_laboratorio_por_ingreso(nombrearchivo);
            system("pause");

            break;
        case 27:

            break;
        default:

            printf("Ingrese una de las opciones o ESC para volver hacia atras\n");
            fflush(stdin);
            o=getch();
        }
    }
}

void alta_laboratorio_por_ingreso(char nombrearchivo [])
{
    FILE * archivo = fopen(nombrearchivo,"r+b");///abrimos el archivo de laboratorio en modo lectura
    ingresosLaboratorio laboratorio;
    int flag=1;
    int numeroingreso;
    if(archivo != NULL)
    {
        printf("Ingrese el numero de ingreso del paciente  \n");///preguntamos por el numero de ingreso del paciente que luego comparemos para eliminar el laboratorio
        scanf("%d",&numeroingreso);

        while(flag && fread(&laboratorio,sizeof(ingresosLaboratorio),1,archivo)>0) ///corroboramos si encontro el dato mediante el flag y despues leemos del archivo
        {
            if(numeroingreso==laboratorio.numeroIngreso)///comparamos el numero de ingreso que se quiere borrar con el los numeros de ingreso del archivo
            {
                if(laboratorio.eliminado == 0)///si entra aca es porque ya estaba dado de baja dado de baja
                {
                    printf("El laboratorio de la persona que ingreso con el numero %d ya estaba dado de baja \n",laboratorio.numeroIngreso);
                    flag=0;
                }
                else
                {
                    fseek(archivo,(-1)*sizeof(ingresosLaboratorio),SEEK_CUR);///retrocedemos el cursor un registro
                    laboratorio.eliminado=0;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archivo);///escribimos en el archivo,cambiando el campo ELIMINADO a 0
                    flag=0;///cambiamos el flag a 0 para que salga del while y no siga leyendo el archivo
                    printf("Alta exitosa \n");
                }
            }
        }
        if(flag == 1)
        {
            printf("El paciente con ingreso %d no existe. Intente nuevamente. \n", numeroingreso);
        }
        fclose(archivo);
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
}

void alta_laboratorio_por_dni(char nombrearchivo [])
{
    FILE * archivo = fopen(nombrearchivo,"r+b");///abrimos el archivo de laboratorio en modo lectura
    ingresosLaboratorio laboratorio;
    int flag=1;
    int dniaborrar;
    if(archivo != NULL)
    {
        printf("Ingrese el numero de ingreso del paciente  \n");///preguntamos por el numero de ingreso del paciente que luego comparemos para eliminar el laboratorio
        scanf("%d",&dniaborrar);

        while(flag && fread(&laboratorio,sizeof(ingresosLaboratorio),1,archivo)>0) ///corroboramos si encontro el dato mediante el flag y despues leemos del archivo
        {
            if(dniaborrar==laboratorio.dni)///comparamos el numero de ingreso que se quiere borrar con el los numeros de ingreso del archivo
            {
                if(laboratorio.eliminado == 0)///si entra aca es porque ya estaba dado de baja dado de baja
                {
                    printf("El laboratorio de la persona con dni %d ya estaba dado de baja \n",laboratorio.dni);
                    flag=0;
                }
                else
                {
                    fseek(archivo,(-1)*sizeof(ingresosLaboratorio),SEEK_CUR);///retrocedemos el cursor un registro
                    laboratorio.eliminado=0;
                    fwrite(&laboratorio,sizeof(ingresosLaboratorio),1,archivo);///escribimos en el archivo,cambiando el campo ELIMINADO a 0
                    flag=0;///cambiamos el flag a 0 para que salga del while y no siga leyendo el archivo
                    printf("Alta exitosa \n");
                }
            }
        }
        if(flag == 1)
        {
            printf("El paciente con el dni %d no existe. Intente nuevamente. \n", dniaborrar);
        }
        fclose(archivo);
    }
    else
    {
        printf("ERROR LA APERTURA DEL  ARCHIVO \n");
    }
}

stLaboratorios validacionFecha(stLaboratorios laboratorio) ///VALIDACION DE UNA FECHA MENOR A LA ACTUAL
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
            scanf("%d",&fecha.anio);

        }
        while(fecha.anio<2020 || anioActual<fecha.anio);      ///PIDE AÑO MENOR O IGUAL A 2023



        if(fecha.anio == anioActual)  /// SI ES AÑO ACTUAL ENTONCES PIDE MES MENOR O IGUAL AL ACTUAL
        {
            do
            {
                printf("Ingrese mes\n");
                scanf("%d",&fecha.mes);
            }
            while(fecha.mes<1 || mesActual<fecha.mes);

            if(fecha.mes == mesActual) /// SI EL MES ES ACTUAL ENTONCES VALIDA QUE MES ES PARA ASIGNARLE LE MAXIMO DE DIAS DE ESE MES
            {

                do    /// si es menor al dia actual no habria porque validar en el switch
                {
                    printf("Ingrese dia\n");   /// PIDE UN DIA MENOR O IGUAL AL ACTUAL
                    scanf("%d",&fecha.dia);
                }
                while(fecha.dia<1 || diaActual<fecha.dia );

            }
            else
            {
                switch (fecha.mes)
                {
                case 2:
                    // Verificar si el año es bisiesto para febrero
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
                    scanf("%d",&fecha.dia);
                }
                while(fecha.dia > diasMaximos);
            }
        }
        else /// si no es anio actual
        {
            do
            {
                printf("Ingrese mes\n");
                scanf("%d",&fecha.mes);
            }
            while(fecha.mes>12 || fecha.mes<1 );

            switch (fecha.mes)
            {
            case 2:
                // Verificar si el año es bisiesto para febrero
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
                scanf("%d",&fecha.dia);
            }while( fecha.dia<1   || fecha.dia >diasMaximos);
        }
    }
    laboratorio.dia=fecha.dia;
    laboratorio.anio=fecha.anio;
    laboratorio.mes=fecha.mes;
    return laboratorio;
}

arbolPaciente buscar_paciente (arbolPaciente * arbol, int dni)
{
    arbolPaciente * rta=NULL;
    if(arbol !=NULL)
    {
        if (arbolPaciente->paciente.dni == dni)
        {
            return arbol;
        }
        else
        {
            if(arbol->paciente.dni<dni)
            {
                rta= buscar_paciente (arbol->der,dni);
            }
            else
            {
                rta= buscar_paciente (arbol->izq,dni);
            }
        }
    }
    return rta;
}

ingresosLaboratorio validacion_existencia_dni(char nombrearchivo [],arbolPaciente * arbol)
{
    ingresolaboratorio laboratorio;
    int dniabuscar;
    do
    {
    printf("\n Dni: ");
    scanf("%d",&dniabuscar);
    arbolPaciente * arbolrespuesta = buscar_paciente(arbol,dni);
    }while(arbolrespuesta!=NULL);
    laboratorio.dni=dniabuscar;
    return laboratorio;
}

ingresosLaboratorio validacion_matricula(ingresosLaboratorio laboratorio)
{
    printf("\n Numero de matricula del profesional: ");
    scanf("%d",&laboratorio.matriculaProfesional);


    return laboratorio;
}
