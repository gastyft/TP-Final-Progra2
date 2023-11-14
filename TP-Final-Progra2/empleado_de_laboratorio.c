#include "empleado_de_laboratorio.h"

void crear_usuario()
{
    FILE *archi=fopen(ARCH_EMPLEADO,"a+b");
    empleado_de_laboratorio empleado;
    gotoxy(2,10);
    printf("Ingrese Nombre y apellido\n");
    fflush(stdin);
    gotoxy(29,10);
    gets(empleado.apellido_y_nombre);
    system("cls");
    consola_vacia();
    gotoxy(2,10);
    printf("Ingrese nombre de usuario\n");
    fflush(stdin);
    gotoxy(29,10);
    gets(empleado.usuario);
    empleado=validaciones_nombre_usuario(empleado);                ///ACA MODIFICANDO EL EMPLEADO.PERFIL=1 CREO UN ADMIN
    ///validacion de que no exista otro usuario con el mismo nombre de user
    int num;
    int flag_num=1;
    while(flag_num)
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        printf("Ingrese Rol de usuario. ");
        gotoxy(2,11);
        printf("Ingrese 2 para Tecnico de laboratorio o");
        gotoxy(2,12);
        printf("3 para empleado administrativo  ");
        scanf("%d",&num);
        if(num==2)
        {
            strcpy(empleado.perfil,"tecnico");
            flag_num=0;
        }
        if(num==3)
        {
            strcpy(empleado.perfil,"empleado");
            flag_num=0;
        }

    }
    ///DAR ALTA UN NUEVO ADMIN; Descomentar linea 47 y comentar de la 24 a la 45
    /// strcpy(empleado.perfil,"admin");


    /// Mientras se presione Enter o la longitud máxima no se alcance
    int contrasenia_valida = 0;

    while (!contrasenia_valida)
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        printf("Ingrese la contrasenia:");
        gotoxy(27,10);
        int i = 0;
        char ch;
        int tiene_mayuscula = 0;
        int tiene_caracter_especial = 0;

        while (i < 20 && (ch = _getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                empleado.contrasenia[i] = ch;
                printf("*");
                i++;

                if (isupper(ch))
                {
                    tiene_mayuscula = 1;
                }
                else if (!isalnum(ch))
                {
                    tiene_caracter_especial = 1;
                }
            }
        }

        empleado.contrasenia[i] = '\0';

        if (i < 8 || !tiene_mayuscula || !tiene_caracter_especial)
        {
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("La contrasenia debe tener al menos 8 caracteres,");
            gotoxy(2,11);
            printf("una mayuscula y un caracter especial.");
            int contame2=0;
            while(contame2<300)
            {
                usleep(10000);
                contame2++;
            }
        }
        else
        {
            contrasenia_valida = 1;
        }
    }

    /// Verifica la contraseña ingresada (en este caso, simplemente la muestra)

    int flag=1;
    system("cls");
    consola_vacia();
    gotoxy(2,10);
    printf("Ingrese DNI:");
    char dni_aux[9]; ///SE PIDE COMO CHAR PARA VALIDAR PERO SE PERSISTE DE TIPO INT COMO SOLICITAN EN EL DESARROLLO
    fflush(stdin);
    gotoxy(16,10);
    gets(dni_aux);

    empleado = validaciones(empleado,dni_aux,&flag);  ///validacion de DNI
    empleado.eliminado=0;
    if (flag==0)
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        setConsoleColor(0,64); ///ROJO DE ERROR
        printf("No se cargara el usuario.\n");
        int contame3=0;
        while(contame3<300)
        {
            usleep(10000);
            contame3++;
        }
    }
    else
    {
        if(archi)
        {
            fwrite(&empleado, sizeof(empleado_de_laboratorio), 1, archi);
            system("cls");
            consola_login();
            gotoxy(18,8);
            setConsoleColor(0,10);  /// LETRA NEGRA FONDO VERDE
            printf("USUARIO CARGADO CORRECTAMENTE.");
            int contame4=0;
            while(contame4<300)
            {
                usleep(10000);
                contame4++;
            }
        }
        else
            setConsoleColor(15,4);  ///LETRA BLANCA FONDO ROJO
        printf("ERROR EN EL ARCHIVO \n");
    }

/// para acceder segun perfil a las funcionalidades de cada estructura.Limitadas por 3 if preguntando que perfil es.
/// if(empleado.perfil=="tecnico"){
///
///    menu
///   modificar
///  alta Labo
///   baja
///
/// }
/// empleado.perfil="empleado"{
/// menu
/// modificar
/// }
/// empleado.perfil="admin"{
///
/// crear usario
/// alta
/// modificar
///
///
///
/// }

///empleado.perfil      TIPO DE PERFIL 1 2 o 3

///MUESTREO

    fclose(archi);

}

void mostrar_1_empleado(empleado_de_laboratorio empleado)
{
    setConsoleColor(11,0);
    printf("\n---------------------------------------------\n");
    setConsoleColor(15,5);
    printf("Apellido y nombre: ");
    setConsoleColor(11,0);
    printf("%s\n",empleado.apellido_y_nombre);
    setConsoleColor(15,5);
    printf("Nombre de usuario: ");
    setConsoleColor(11,0);
    printf("%s \n",empleado.usuario);
    setConsoleColor(15,5);
    printf("DNI: ");
    setConsoleColor(11,0);
    printf("%d \n",empleado.DNI);
    setConsoleColor(15,5);
    printf("Perfil de tipo: ");
    setConsoleColor(11,0);
    printf("%s \n",empleado.perfil);
    if(empleado.eliminado==1)
    {
        setConsoleColor(15,4);
        printf("El empleado esta dado de baja");
        setConsoleColor(11,0);
    }
    else
    {
        setConsoleColor(15,10);
        printf("El empleado esta activo");
        setConsoleColor(11,0);
    }
}



int validar_dni_empleado(char numero[])
{

    int flag = 0;

    for (int i = 0; numero[i] != '\0'; i++)
    {
        if (isspace(numero[i]))
        {
            flag = 1;
        }  /// detecta un escpacio
        if (isdigit(numero[i]))   /// si es un numero no continua verificando
        {
        }
        else if (isalpha(numero[i]))      /// detecta si es una letra
        {
            flag = 1;
        }
        else if (ispunct(numero[i]))      /// detecta si es un simbolo
        {
            flag = 1;
        }
    }
    if(atoi(numero)<1000000 || atoi(numero)>100000000)
    {

        flag = 1;         /// detecta que sean 8 caracteres correctos

    }

    return flag;
}


empleado_de_laboratorio validaciones(empleado_de_laboratorio empleado,char num[],int *flag) /// VALIDACIONES DE EMPLEADOS POR DNI (que no exista otro DNI repetido)
{
///dni,nombre,apellido vienen como parametros de la funcion alta y modificacion
    empleado_de_laboratorio empleado_valido;
    char o=0;
    FILE *archivo=fopen(ARCH_EMPLEADO,"r+b");
    if(archivo)
    {

        if(fread(&empleado_valido,sizeof(empleado_valido),1,archivo)==0 )  ///SI NO HAY DATOS EN EL ARCHIVO
        {
            while( validar_dni_empleado(num)==1)
            {
                system("cls");
                consola_vacia();
                gotoxy(2,10);
                printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros... \n");
                fflush(stdin);
                gets(num);
            }
        }
        else
        {
            while( *flag && fread(&empleado_valido,sizeof(empleado_valido),1,archivo)>0 )
            {
                int aux=atoi(num);

                if(aux == empleado_valido.DNI)
                {
                    system("cls");
                    consola_vacia();
                    gotoxy(2,10);
                    printf("El dni ya existe,presione cualquier tecla para cargar un nuevo DNI o ESCAPE para salir");
                    fflush(stdin);
                    o=getch();
                    if(o==ESC)
                    {
                        *flag=0;
                    }
                    else
                    {
                        system("cls");
                        consola_vacia();
                        gotoxy(2,10);
                        printf("Ingrese DNI nuevo: ");
                        fflush(stdin);
                        gotoxy(22,10);
                        gets(num);
                        rewind(archivo);
                    }
                    system("cls");
                }
                else
                {
                    while( validar_dni_empleado(num)==1)
                    {
                        system("cls");
                        consola_vacia();
                        gotoxy(2,10);
                        printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
                        fflush(stdin);
                        gotoxy(2,11);
                        gets(num);
                        rewind(archivo);

                    }

                }
            }
        }
    }
    else
        printf("ERROR AL ABRIR EL ARCHIVO \n");
    empleado.DNI=atoi(num);


    system("cls");
    fclose(archivo);
    return empleado;
}



void mostrar_empleados()
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");

    empleado_de_laboratorio empleado;

    if(archi)
    {

        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {

            mostrar_1_empleado(empleado);

        }

    }
    else
        printf("ERROR EN EL ARCHIVO EMPLEADOS EN FUNCTION MOSTRAR EMPLEADOS \n");


    fclose(archi);
}


void mostrar_empleados_activos()
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");

    empleado_de_laboratorio empleado;
    int i=0;
    if(archi)
    {

        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if(empleado.eliminado==0)
                mostrar_1_empleado(empleado);
            i++;
        }

    }
    else
        printf("ERROR EN EL ARCHIVO EMPLEADOS EN FUNCTION MOSTRAR EMPLEADOS \n");


    fclose(archi);
}

void mostrar_empleados_inactivos()
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");

    empleado_de_laboratorio empleado;
    int flag=1;
    if(archi)
    {

        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if(empleado.eliminado==1)
            {
                mostrar_1_empleado(empleado);
                flag=0;
            }

        }

    }
    else
        printf("ERROR EN EL ARCHIVO EMPLEADOS EN FUNCTION MOSTRAR EMPLEADOS \n");
    if(flag==1)
        printf("NO HAY EMPLEADOS DADOS DE BAJA \n");

    fclose(archi);
}

empleado_de_laboratorio validaciones_nombre_usuario(empleado_de_laboratorio empleado) ///VALIDACIONES PRACTICA PARA QUE NO SE REPITAN DATOS
{
    empleado_de_laboratorio empleado_valido;
    FILE *archivo=fopen(ARCH_EMPLEADO,"r+b");
    rewind(archivo);
    while( fread(&empleado_valido,sizeof(empleado_de_laboratorio),1,archivo)>0 )
    {
        if(strcmpi(empleado.usuario,empleado_valido.usuario)==0)
        {
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("El nombre de usuario ya existe,");
            gotoxy(2,11);
            printf("ingrese un nombre de usuario distinto");
            gotoxy(2,12);
            printf("Ingrese nombre de usuario:  ");
            fflush(stdin);
            gets(empleado.usuario);
            rewind(archivo);
        }
    }
    fclose(archivo);
    return empleado;
}


void dar_baja_empleado()
{
    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado_a_validar;
    int flag=1;
    char DNI1[10];
    char o=0;
    if(archi != NULL)
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        printf("Ingrese Dni del Empleado: \n");
        fflush(stdin);
        gotoxy(27,10);
        gets(DNI1);
        while( validar_dni_empleado(DNI1)==1)
        {
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("SI DESEA SALIR PRESIONE ESCAPE O CUALQUIER TECLA");
            gotoxy(2,11);
            printf("PARA CARGAR NUEVAMENTE EL DNI");
            fflush(stdin);
            o=getch();
            if(o==ESC)
                return;
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
            fflush(stdin);
            gotoxy(2,11);
            gets(DNI1);
        }
        int aux=atoi(DNI1);
        while(flag && fread(&empleado_a_validar,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if( aux == empleado_a_validar.DNI)
            {
                if(empleado_a_validar.eliminado == 1)
                {
                    system("cls");
                    consola_vacia();
                    gotoxy(2,10);
                    printf("Ya esta dado de baja el empleado %s \n",empleado_a_validar.apellido_y_nombre);
                    flag=0;
                }
                else
                {
                    fseek(archi,(-1)*sizeof(empleado_de_laboratorio),SEEK_CUR);
                    empleado_a_validar.eliminado= 1;
                    fwrite(&empleado_a_validar,sizeof(empleado_de_laboratorio),1,archi);
                    flag=0;
                    system("cls");
                    consola_vacia();
                    gotoxy(2,10);
                    setConsoleColor(15,10);
                    printf("Baja exitosa \n");
                    int contame=0;
                    while(contame<200)
                    {
                        usleep(10000);
                        contame++;
                    }
                    setConsoleColor(11,0);
                }
            }
        }
        if(flag)
        {
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("No se encontro empleado con ese DNI.\n");
        }
    }
    else
    {
        printf("ERROR EN EL ARCHIVO \n");
    }
    fclose(archi);

}

void dar_alta_empleado_logico( empleado_de_laboratorio empleado)
{
    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado_a_validar;

    if(archi)
    {

        while(fread(&empleado_a_validar,sizeof(empleado_a_validar),1,archi)>0)
        {
            if(empleado.DNI==empleado_a_validar.DNI)
            {
                if(empleado.eliminado==0){
                    printf("El usuario ya se encuentra activo");
                      int contame1=0;
                      while(contame1<200)
                {
                    usleep(10000);
                    contame1++;
                }
                }
                else
                {


                empleado.eliminado=0;

                fseek(archi,-1*sizeof(empleado_de_laboratorio),SEEK_CUR);

                fwrite(&empleado,sizeof(empleado_de_laboratorio),1,archi);
                system("cls");
                consola_vacia();
                gotoxy(2,10);
                setConsoleColor(15,10);
                printf("Usuario dado de alta nuevamente \n");
                int contame=0;
                while(contame<200)
                {
                    usleep(10000);
                    contame++;
                }
                system("cls");
                setConsoleColor(11,0);
                mostrar_1_empleado(empleado);

                }
                system("pause");

                fclose(archi);
                return;
            }
        }
    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR ALTA EMPLEADO LOGICO \n");

}

empleado_de_laboratorio busqueda_empleado(  char dni_a_buscar[10])
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado;
    while( validar_dni_empleado(dni_a_buscar)==1) ///AGREGAR CONDICION DE CORTE POR SI NO QUIERE CARGAR
    {

        printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
        fflush(stdin);
        gets(dni_a_buscar);
    }
    int aux=atoi(dni_a_buscar);
    int flag=1;
    if(archi)
    {

        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi )>0)
        {
            if(aux==empleado.DNI)
            {
                return empleado;
                flag=0;
            }
        }
    }
    else
        printf("ERROR AL ABRIR EL ARCHIVO EN BUSQUEDA EMPLEADO \n");
    fclose(archi);

    if(flag==1)
        empleado.DNI=-1;
    return empleado;
}

void modificar_empleado()
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");

    empleado_de_laboratorio empleado;
    char dni_a_buscar[9];
    char o=0;
    int num;
    int flag_num=1;
    int flag=0;
    int contrasenia_valida = 0;
    gotoxy(2,10);
    printf("DESEA MODIFICAR UN EMPLEADO?");
    gotoxy(2,11);
    printf("PRESS ENTER PARA SI CUALQUIER TECLA PARA NO ");
    fflush(stdin);
    o=getch();
    if(o==ENTER)
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        printf("Ingrese DNI de empleado a modificar\n");
        fflush(stdin);
        gotoxy(2,11);
        gets(dni_a_buscar);

        while(  validar_dni_empleado(dni_a_buscar)==1 )
        {
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("dni mal puesto. Si desea cargar nuevamente presione ENTER");
            gotoxy(2,11);
            printf(" sino cualquier tecla para salir ");
            fflush(stdin);
            o=getch();
            if(o!=13)
                break;
            system("cls");
            consola_login();
            gotoxy(2,12);
            printf("Ingrese un DNI para modificar.Sin espacios, sin puntos. Solo numeros \n");
            fflush(stdin);
            gotoxy(2,13);
            gets(dni_a_buscar);
        }
    }
    if(archi)
    {

        int aux=atoi(dni_a_buscar);
        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {

            if( aux==empleado.DNI)
            {

                do
                {
                    flag=0;
                    system("cls");
                    consola_vacia();
                    gotoxy(2,7);
                    printf("---Ingrese una opcion--- \n");
                    gotoxy(2,8);
                    printf("1- Cambiar Nombre y apellido\n");
                    gotoxy(2,9);
                    printf("2- Cambiar nombre de usuario \n");
                    gotoxy(2,10);
                    printf("3- Cambiar contrasenia \n");
                    gotoxy(2,11);
                    printf("4- Cambiar Rol de usuario \n");
                    gotoxy(2,12);
                    printf("5- Cambiar el estado del empleado \n");
                    gotoxy(2,13);
                    printf("ESC para salir ");
                    fflush(stdin);
                    o=getch();
                    system("cls");
                    switch(o)
                    {

                    case '1':
                        system("cls");
                        consola_vacia();
                        gotoxy(2,10);
                        printf("Ingrese Nombre y apellido:  ");
                        fflush(stdin);
                        gets(empleado.apellido_y_nombre);
                        flag=1;
                        break;


                    case '2':
                        system("cls");
                        consola_vacia();
                        gotoxy(2,10);
                        printf("Ingrese nombre de usuario  ");
                        fflush(stdin);
                        gets(empleado.usuario);
                        empleado=validaciones_nombre_usuario( empleado);
                        flag=1;
                        break;

                    case'3':


                            while (!contrasenia_valida)
                            {
                                system("cls");
                                consola_vacia();
                                gotoxy(2,10);
                                printf("Ingrese la contrasenia:  ");

                                int i = 0;
                                char ch;
                                int tiene_mayuscula = 0;
                                int tiene_caracter_especial = 0;

                                while (i < 20 && (ch = _getch()) != '\r')
                                {
                                    if (ch == '\b')
                                    {
                                        if (i > 0)
                                        {
                                            i--;
                                            printf("\b \b");
                                        }
                                    }
                                    else
                                    {
                                        empleado.contrasenia[i] = ch;
                                        printf("*");
                                        i++;

                                        if (isupper(ch))
                                        {
                                            tiene_mayuscula = 1;
                                        }
                                        else if (!isalnum(ch))
                                        {
                                            tiene_caracter_especial = 1;
                                        }
                                    }
                                }

                                empleado.contrasenia[i] = '\0';

                                if (i < 8 || !tiene_mayuscula || !tiene_caracter_especial)
                                {
                                    system("cls");
                                    consola_vacia();
                                    gotoxy(2,10);
                                    printf("\nLa contraseña debe tener al menos 8 caracteres, una mayuscula y un caracter especial.");
                                }
                                else
                                {
                                    contrasenia_valida = 1;
                                }
                            }
                            flag=1;
                        break;

                    case '4':


                        while(flag_num==1)
                        {
                            system("cls");
                            consola_vacia();
                            gotoxy(2,7);
                            printf("Ingrese Rol de usuario. ");
                            gotoxy(2,11);
                            printf("Ingrese 2 para Tecnico de laboratorio o 3 para empleado administrativo \n");
                            scanf("%d",&num);
                            if(num==2)
                            {
                                strcpy(empleado.perfil,"tecnico");
                                flag_num=0;
                            }
                            if(num==3)
                            {
                                strcpy(empleado.perfil,"empleado");
                                flag_num=0;
                            }

                        }
                        flag=1;
                        break;

                    case '5':

                        if(empleado.eliminado==1)
                        {
                            system("cls");
                            consola_vacia();
                            gotoxy(2,10);
                            printf("EL EMPLEADO ESTA DADO DE BAJA. Desea darlo de alta?");
                            gotoxy(2,11);
                            printf("Presione enter para Si\n");
                            char o1=0;
                            fflush(stdin);
                            o1=getch();
                            if(o1==13) /// EN ASCII 13 es el retorno de carro (ENTER para los mortales)
                                empleado.eliminado=0;
                        }
                        else if(empleado.eliminado==0)
                        {
                            printf("EL EMPLEADO ESTA ACTIVO. Desea darlo de baja? Presione enter para Si\n");
                            char o2=0;
                            fflush(stdin);
                            o2=getch();
                            if(o2==13) /// EN ASCII 13 es el retorno de carro (ENTER para los mortales)
                                empleado.eliminado=1;

                        }
                        flag=1;
                        break;

                    case 27:

                        break;

                    default:
                        system("cls");
                        consola_vacia();
                        gotoxy(2,10);
                        printf("Ingreso una opcion incorrecta elija nuevamente");
                        gotoxy(2,11);
                        printf("o presione ESC para volver atras");
                        fflush(stdin);
                        o=getch();
                        break;

                    }
                if(flag==0){
                    fseek(archi,-1*sizeof(empleado_de_laboratorio),SEEK_CUR);
                    fwrite(&empleado,sizeof(empleado_de_laboratorio),1,archi);
                    system("cls");
                    consola_login();
                    setConsoleColor(15,10);
                    gotoxy(8,8);
                    printf("EMPLEADO MODIFICADO\n");
                    setConsoleColor(11,0);
                    int contame=0;
                    while(contame<200)
                    {
                        usleep(10000);
                        contame++;

                    }
                    system("cls");
                    gotoxy(2,0);
                    mostrar_1_empleado(empleado);
                    setConsoleColor(15,5);
                    printf("\nContrasenia: ");
                    setConsoleColor(11,0);
                    printf("%s",empleado.contrasenia);
                    printf("\n");
                    system("pause");
                }
                }
                while(o != 27);
                fclose(archi);
                return;
            }
        }
    }
    else
        printf("ERROR EN ABRIR EL ARCHIVO EN MODIFICAR EMPLEADO \n");




}

int login( )
{
    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado_a_loguearse;
    empleado_de_laboratorio empleado;
    int flag=1;
    int num;
    consola_login();
    gotoxy(7,8);
    printf("USUARIO:\n");
    gotoxy(16,8);
    gets(empleado_a_loguearse.usuario);
    gotoxy(3,11);
    printf("CONTRASENIA: \n");
    int i = 0;
    char ch;
    gotoxy(16,11);
    while (i < 20 && (ch = _getch()) != '\r')  ///SE LEE CARACTER A CARACTER CON _GETCH()  QUE CAPTURA EL CARACTER SIN NECESIDAD DE ENTER
    {
        ///gotoxy(11+i,16);                     /// LEERA HASTA QUE SE OPRIMA ENTER(\r)
        if (ch == '\b')                        ///SI   ES BACKSPACE,ES DECIR, SI RETROCEDIO EL PUNTERO DEL TECLADO, ENTONCES ENTRA
        {
            if (i > 0)                         ///PREGUNTA SI LA I ES MAYOR A CERO SI LO ES ENTONCES HACE 2 BACKSPACE
            {
                i--;
                printf("\b \b");
            }
        }
        else                                   /// SI NO ES UN BACKSPACE ENTONCES SUMA EL CARACTER LEIDO A CONTRASENIA Y EN LUGAR DE QUE APAREZCA
        {
            /// LA LETRA APARECE  * PARA EVITAR LA LECTURA DEL CARACTER INGRESADO.
            empleado_a_loguearse.contrasenia[i] = ch;
            printf("*");///SE PUEDE REEMPLAZAR POR CUALQUIER CARACTER
            i++;
        }
    }
    empleado_a_loguearse.contrasenia[i] = '\0';
    if(archi)
    {
        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)  ///COMPARA USUARIO CON GRADO DE LIBERTAD POR SI EN USUARIO PONE ALGUNA MAYUSCULA QUE NO IBA
        {
            if(strcmpi(empleado_a_loguearse.usuario,empleado.usuario)==0)
            {

                if(strcmp(empleado_a_loguearse.contrasenia,empleado.contrasenia)==0) ///COMPARA RESTRICTAMENTE QUE SEAN IGUALES LAS CONTRASENIAS
                {

                    if(empleado.eliminado==1) ///CASO DE QUE EL USUARIO ESTE DADO DE BAJA, SE IFORMA Y NO SE LE PERMITE EL ACCESO.
                    {
                        system("cls");
                        consola_vacia();
                        gotoxy(12,11);
                        printf("USTED HA SIDO DADO DE BAJA SOLICITE UN NUEVO USUARIO CON EL ADMIN O PROGRAMADOR \n");

                    }
                    else
                    {
                        system("cls");
                        consola_vacia();

                        gotoxy(19,9);
                        printf("Bienvenido/a %s \n",empleado.apellido_y_nombre); ///CASO QUE LOGUEE BIEN, SE LO RECIBE Y ASIGNA EL ROL QUE TIENE
                        int salid1=0;
                        while(salid1<200)
                        {
                            usleep(10000);
                            salid1++;
                        }
                        system("cls");

                        if(strcmpi(empleado.perfil,"admin")==0)
                        {
                            num=1;
                        }
                        if(strcmpi(empleado.perfil,"tecnico")==0)
                        {
                            num=2;
                        }
                        if(strcmpi(empleado.perfil,"empleado")==0)
                        {
                            num=3;
                        }
                        flag=0;


                    }
                }
                else
                    flag=1;
            }
        }
        if(flag==1)  ///SE INFORMA SI NO INGRESO CORRECTAMENTE
        {
            num=-1;

            printf("\n");
            system("cls");
            consola_vacia();
            gotoxy(9,7);
            printf(COLOR_RED);
            printf("NOMBRE DE USUARIO O CONTRASENIA INCORRECTA \n");
            printf(COLOR_RESET);
        }

    }
    else
        printf("ERROR AL ABRIR EL ARCHIVO EN EL LOGIN \n");

    fclose(archi);

    return num;     ///RETORNA -1 SI NO INGRESO CORRECTAMENTE SINO ROL 1,2 O 3.
}
int log_out()
{
    return -1; ///DESLOGUEA. SOLAMENTE CAMBIA DE ESTADO A -1.
}


void menu_empleados(int isLoggedin) ///MENU EMPLEADOS
{

    printf("EL USUARIO ES EL ADMIN \n");
    char o=0;

    do
    {

        system("cls");
        consola_vacia();
        gotoxy(21,7);
        printf("Seleccione una opcion:\n");
        gotoxy(21,8);
        printf("1)Crear y dar altas usuarios");
        gotoxy(21,9);
        printf("2)Dar de baja un empleado");
        gotoxy(21,10);
        printf("3)Modificacion");
        gotoxy(21,11);
        printf("4)Consulta"); ///Probar con switchs
        gotoxy(21,12);
        printf("5)Lista empleados");
        gotoxy(21,13);
        printf("ESC Para volver atras \n");

        fflush(stdin);
        o=getch();
        switch(o)
        {
        case '1':
            menu_altas_usuarios();
            break;
        case '2':
            system("cls");
            consola_vacia();
            dar_baja_empleado();
            system("cls");
            printf("EMPLEADOS DADOS DE BAJA \n");
            mostrar_empleados_inactivos();
            system("pause");
            system("cls");
            break;
        case '3':
            system("cls");
            consola_vacia();
            modificar_empleado();
            break;
        case '4':
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("INGRESE DNI A BUSCAR: \n");
            char busqueda[10];
            fflush(stdin);
            gotoxy(24,10);
            gets(busqueda);
            empleado_de_laboratorio emp;
            emp= busqueda_empleado(busqueda);
            if(emp.DNI==-1)
            {
                system("cls");
                consola_vacia();
                gotoxy(2,10);
                printf("NO SE ENCONTRO EL EMPLEADO \n");
            }
            else
            {
                system("cls");
                consola_vacia();
                gotoxy(2,10);
                printf("ATENCION!!!\n");
                gotoxy(2,11);
                printf("DESEA REVELAR LA CONTRASENIA?\n");
                gotoxy(3,12);
                printf("Pulse enter para mostrar sino cualquier tecla\n");
                char o=0;
                fflush(stdin);
                o=getch();
                if(o==13)
                {
                    system("cls");
                    mostrar_1_empleado(emp);
                    printf("\n");
                    setConsoleColor(15,3);
                    printf("Contrasenia: %s\n",emp.contrasenia);
                    setConsoleColor(11,0);
                    system("pause");
                }
                else
                {
                    system("cls");
                    mostrar_1_empleado(emp);
                    system("pause");
                }
            }

            break;
        case '5':
            menu_muestra_empleados();
            break;

        case 27:

            break;
        default:
            printf("\n\tHa seleccionado una opcion invalida.\n\tPor favor, presione cualquier tecla para continuar\n\n");
            fflush(stdin);
            o=getch();
            system("cls");
            break;
        }

    }
    while(o!=ESC);
}
void setConsoleColor(int text, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}

void funcion_about_us()
{
    consola_vacia();
    gotoxy(2,8);
    printf(COLOR_YELLOW);
    imprimir_con_puntos("Quienes somos?");

    gotoxy(2,9);
    imprimir_con_puntos("Somos estudiantes universitarios en programacion ");

    gotoxy(2,10);
    imprimir_con_puntos("de la facultad UTN de Mar del Plata");

    printf(COLOR_RESET);
    int contame=0;
    while(contame<200)
    {
        usleep(10000);
        contame++;
    }
    system("cls");
    consola_vacia();
    setConsoleColor(15,0);
    gotoxy(2,8);
    imprimir_con_puntos("Proyecto realizado para la materia Programacion");

    gotoxy(2,9);
    imprimir_con_puntos("y laboratorio II");

    imprimir_con_puntos(" para el docente ");

    setConsoleColor(4,0);
    imprimir_con_puntos("Adrian Arocca");

    setConsoleColor(3,0);
    gotoxy(2,10);
    setConsoleColor(15,0);
    imprimir_con_puntos("Y sus ayudantes ");
    setConsoleColor(6,0);
    imprimir_con_puntos("Magdalena Martins ");
    setConsoleColor(15,0);
    printf("y ");
    setConsoleColor(2,0);
    imprimir_con_puntos("Mariano Blanco");
    int contame2=0;
    while(contame2<100)
    {
        usleep(10000);
        contame2++;
    }

}

void imprimir_con_puntos(const char *parrafo)
{
    int i;
    int longitud = strlen(parrafo);

    for (i = 0; i < longitud; i++)
    {
        // Imprimir el carácter con un punto
        printf("%c.", parrafo[i]);
        fflush(stdout); // Asegurar que el buffer se vacíe y se muestre inmediatamente

        usleep(30000); // Retraso de 300 milisegundos (0.3 segundos)

        // Borrar el carácter y el punto anterior mediante caracteres de escape
        printf("\b \b");
        fflush(stdout);

        // Si no estás en el último carácter, espera un poco antes de imprimir el siguiente
        if (i < longitud - 1)
        {
            usleep(30000); // Retraso adicional entre caracteres para mayor claridad
        }
    }
}

void menu_altas_usuarios()
{
    char op=0;

    do
    {
        system("cls");
        consola_vacia();
        gotoxy(2,10);
        printf("1- Crear usuario");
        gotoxy(2,11);
        printf("2- Dar alta un usuario que este dado de baja por DNI");
        gotoxy(2,12);
        printf("ESC PARA SALIR");
        fflush(stdin);
        op=getch();
        switch(op)
        {
        case '1':
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            crear_usuario();
            break;
        case '2':
            system("cls");
            consola_vacia();
            gotoxy(2,10);
            printf("INGRESE DNI A BUSCAR: \n");
            char busqueda1[10];
            fflush(stdin);
            gotoxy(24,10);
            gets(busqueda1);
            empleado_de_laboratorio emp;
            emp= busqueda_empleado(busqueda1);
            if(emp.DNI==-1)
            {
                system("cls");
                consola_vacia();
                gotoxy(2,10);
                printf("NO SE ENCONTRO EL EMPLEADO \n");
            }
            else
                dar_alta_empleado_logico(emp);
            break;
        case 27:

            break;

        default:
            system("cls");
            consola_vacia();

            gotoxy(2,10);
            printf("1- Crear usuario");
            gotoxy(2,11);
            printf("2- Dar alta un usuario que este dado de baja por DNI");
            fflush(stdin);
            op=getch();
            break;

        }
    }
    while(op!=27);



}

///FUNCIONES DE MAURI PARA MUESTRA ORDENADA POR APELLIDO
int contar_empleados()
{

    FILE *archi = fopen(ARCH_EMPLEADO,"rb");
    empleado_de_laboratorio emp;
    int i = 0;

    if(archi)
    {

        while(fread(&emp,sizeof(stPaciente),1,archi) > 0)
        {

            i++;

        }

        fclose(archi);

    }


    return i;

}
void mostrar_empleado_por_apellido()
{
    int validos = contar_empleados(); /// se busca los validos con los id
    empleado_de_laboratorio emp[validos]; /// se crea un arreglo con la dimension del archivo

    FILE *archi = fopen(ARCH_EMPLEADO,"rb");

    if (archi != NULL)
    {
        int i = 0;
        while(fread(&emp[i],sizeof(empleado_de_laboratorio),1,archi) > 0)    /// se carga el arreglo
        {

            i++;
        }
        fclose(archi);



        ordenar_seleccion_empleado(emp,validos);   ///se ordena el arreglo

        system("cls");
        setConsoleColor(15,5);
        gotoxy(1,1);
        printf("      DNI       APELLIDO Y NOMBRE           USUARIO       ELIMINADO         ");
        for(int i = 0 ; i < validos; i++)
        {

            mostrar_empleados_lista(emp[i],i+2);  /// se muestra ordenado el arreglo


        }

    }
}
int posmenor_empleado(empleado_de_laboratorio emp[],int validos,int pos)
{
    char menor[40];
    strcpy(menor,emp[pos].apellido_y_nombre);
    int pos_menor = pos;
    int i = pos + 1;
    while(i < validos)
    {

        if(strcmpi(menor,emp[i].apellido_y_nombre) > 0)
        {
            pos_menor = i;
            strcpy(menor, emp[i].apellido_y_nombre);
        }
        i++;

    }
    return pos_menor;


}
void ordenar_seleccion_empleado(empleado_de_laboratorio emp[],int validos)
{
    int i = 0;
    int posMenor;
    empleado_de_laboratorio aux;
    while(i < validos -1)
    {

        posMenor = posmenor_empleado(emp,validos,i);
        aux = emp[posMenor];
        emp[posMenor]= emp[i];
        emp[i] = aux;
        i++;
    }



}
void mostrar_empleados_lista(empleado_de_laboratorio emp, int i)
{
    setConsoleColor(15,5);
    gotoxy(1,i);
    printf("   %-20i ",emp.DNI);
    gotoxy(15,i);
    printf("  %-30s ",emp.apellido_y_nombre);
    gotoxy(43,i);
    printf("  %-15s ",emp.usuario);
    gotoxy(60,i);
    if (emp.eliminado == 0)
    {
        setConsoleColor(15,10); // Verde
        printf("  %-15s", "No");
    }
    else
    {

        setConsoleColor(15,4);// Rojo
        printf("  %-15s", "Si");
    }

}

///FIN FUNCIONES DE MAURI PARA MUESTRA ORDENADA POR APELLIDO

void menu_muestra_empleados()
{
    char o=0;

    do
    {
        system("cls");
        consola_vacia();
        gotoxy(2,7);
        printf("1- Muestra ordenados por apellido");
        gotoxy(2,8);
        printf("2- Muestra activos e inactivos sin orden");
        gotoxy(2,9);
        printf("3- Muestra activos");
        gotoxy(2,10);
        printf("4- Muestra inactivos");
        gotoxy(2,11);
        printf("ESC SALIR");
        fflush(stdin);
        o=getch();
        switch(o)
        {
        case '1':
            system("cls");
            mostrar_empleado_por_apellido();
            printf("\n");
            setConsoleColor(11,0);
            system("pause");
            break;
        case '2':
            system("cls");
            printf("EMPLEADOS ACTIVOS \n");
            mostrar_empleados_activos();
            printf(" \n");
            printf("----------------------------------\n");
            printf("EMPLEADOS INACTIVOS \n");
            mostrar_empleados_inactivos();
            setConsoleColor(11,0);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '3':
            system("cls");
            printf("EMPLEADOS ACTIVOS\n");
            mostrar_empleados_activos();
            setConsoleColor(11,0);
            printf("\n");
            system("pause");
            break;
        case '4':
            system("cls");
            printf("EMPLEADOS INACTIVOS\n");
            mostrar_empleados_inactivos();
            setConsoleColor(11,0);
            printf("\n");
            system("pause");
            break;
        case 27:

            break;
        default:
            system("cls");
            consola_vacia();
            gotoxy(2,7);
            printf("1- Muestra ordenados por apellido");
            gotoxy(2,8);
            printf("2- Muestra activos e inactivos sin orden");
            gotoxy(2,9);
            printf("3- Muestra activos");
            gotoxy(2,10);
            printf("4- Muestra inactivos");
            gotoxy(2,11);
            printf("ESC SALIR");
            fflush(stdin);
            o=getch();

            break;
        }
    }
    while(o!=27);
}
