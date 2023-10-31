#include "empleado_de_laboratorio.h"



void crear_usuario( )
{
    FILE *archi=fopen(ARCH_EMPLEADO,"a+b");
    empleado_de_laboratorio empleado;

    printf("Ingrese Nombre y apellido\n");
    fflush(stdin);
    gets(empleado.apellido_y_nombre);

    printf("Ingrese nombre de usuario\n");
    fflush(stdin); ///COMENTARIO
    gets(empleado.usuario);
    empleado=validaciones_nombre_usuario(empleado);                ///ACA MODIFICANDO EL EMPLEADO.PERFIL=1 CREO UN ADMIN
    ///validacion de que no exista otro usuario con el mismo nombre de user
    int num;
    int flag_num=1;
//    while(flag_num)
//    {
//        printf("Ingrese Rol de usuario. ");
//        printf("Ingrese 2 para Tecnico de laboratorio o 3 para empleado administrativo \n");
//        scanf("%d",&num);
//        if(num==2)
//        {
//            strcpy(empleado.perfil,"tecnico");
//            flag_num=0;
//        }
//        if(num==3)
//        {
//            strcpy(empleado.perfil,"empleado");
//            flag_num=0;
//        }
//
//    }
    ///DAR ALTA UN NUEVO ADMIN;
    strcpy(empleado.perfil,"admin");


    /// Mientras se presione Enter o la longitud máxima no se alcance
    int contrasenia_valida = 0;

    while (!contrasenia_valida)
    {
        printf("Ingrese la contrasenia:  \n");

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
            printf("\nLa contraseña debe tener al menos 8 caracteres, una mayuscula y un caracter especial.\n");
        }
        else
        {
            contrasenia_valida = 1;
        }
    }

    /// Verifica la contraseña ingresada (en este caso, simplemente la muestra)

    int flag=1;
    printf(" \nIngrese DNI \n");
    char dni_aux[9]; ///SE PIDE COMO CHAR PARA VALIDAR PERO SE PERSISTE DE TIPO INT COMO SOLICITAN EN EL DESARROLLO
    fflush(stdin);
    gets(dni_aux);

    empleado = validaciones(empleado,dni_aux,&flag);  ///validacion de DNI
    empleado.eliminado=0;
    if (flag==0)
    {
        printf("No se cargara el usuario.\n");
    }
    else
    {
        fwrite(&empleado, sizeof(empleado_de_laboratorio), 1, archi);
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

    printf("Apellido y nombre: %s\n",empleado.apellido_y_nombre);
    printf("Nombre de usuario %s \n",empleado.usuario);
    printf("DNI:%d \n",empleado.DNI);
    printf("Perfil de tipo: %s \n",empleado.perfil);
    if(empleado.eliminado==1)
        printf("El empleado esta dado de baja \n");
    else
        printf("El empleado esta activo \n");

}



int validar(char numero[])
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
    if(strlen(numero)> 8 || strlen(numero)< 7)
    {

        flag = 1;         /// detecta que sean 8 caracteres correctos

    }
    return flag;
}


empleado_de_laboratorio validaciones(empleado_de_laboratorio empleado,char num[9],int *flag) /// VALIDACIONES DE EMPLEADOS POR DNI (que no exista otro DNI repetido)
{
///dni,nombre,apellido vienen como parametros de la funcion alta y modificacion
    empleado_de_laboratorio empleado_valido;
    char o=0;
    FILE *archivo=fopen(ARCH_EMPLEADO,"r+b");
    if(archivo)
    {

        if(fread(&empleado_valido,sizeof(empleado_valido),1,archivo)==0 )  ///SI NO HAY DATOS EN EL ARCHIVO
        {
            while( validar(num)==1)
            {
                system("cls");
                printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
                fflush(stdin);
                gets(num);
            }
        }
        while( *flag && fread(&empleado_valido,sizeof(empleado_valido),1,archivo)>0 )
        {
            int aux=atoi(num);

            if(aux == empleado_valido.DNI)
            {
                printf("El dni ya existe,presione cualquier tecla para cargar un nuevo DNI o ESCAPE para salir\n");
                fflush(stdin);
                o=getch();
                if(o==ESC)
                {
                    *flag=0;
                }
                else
                {
                    printf("Ingrese DNI nuevo \n");
                    fflush(stdin);
                    gets(num);
                    rewind(archivo);
                }
                system("cls");
            }
            else
            {
                while( validar(num)==1)
                {
                    system("cls");
                    printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
                    fflush(stdin);
                    gets(num);


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

    if(archi)
    {

        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if(empleado.eliminado==0)
                mostrar_1_empleado(empleado);

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
            printf("El nombre de usuario ya existe, ingrese un nombre de usuario distinto\n");
            printf("Ingrese nombre de usuario\n");
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
    if(archi != NULL)
    {
        printf("Ingrese Dni del Empleado \n");
        fflush(stdin);
        gets(DNI1);
        while( validar(DNI1)==1)
        {
            system("cls");
            printf("Ingrese nuevo DNI sin espacios, sin puntos. Solo numeros \n");
            fflush(stdin);
            gets(DNI1);
        }
        int aux=atoi(DNI1);
        while(flag && fread(&empleado_a_validar,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if( aux == empleado_a_validar.DNI)
            {
                if(empleado_a_validar.eliminado == 1)
                {
                    printf("Ya esta dado de baja el empleado %s \n",empleado_a_validar.apellido_y_nombre);
                    flag=0;
                }
                else
                {
                    fseek(archi,(-1)*sizeof(empleado_de_laboratorio),SEEK_CUR);
                    empleado_a_validar.eliminado= 1;
                    fwrite(&empleado_a_validar,sizeof(empleado_de_laboratorio),1,archi);
                    flag=0;
                    printf("Baja exitosa \n");
                }
            }
        }
        if(flag)
        {
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

                empleado.eliminado=0;

                fseek(archi,-1*sizeof(empleado_de_laboratorio),SEEK_CUR);

                fwrite(&empleado,sizeof(empleado_de_laboratorio),1,archi);
                printf("Usuario dado de alta nuevamente \n");
                return;
            }
        }
    }
    else
        printf("ERROR AL ABRIR ARCHIVO EMPLEADOS EN DAR ALTA EMPLEADO LOGICO \n");
    fclose(archi);
}

empleado_de_laboratorio busqueda_empleado(  char dni_a_buscar[10])
{

    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado;
    while( validar(dni_a_buscar)==1)
    {
        system("cls");
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
int contrasenia_valida = 0;

    printf("DESEA MODIFICAR UN PACIENTE? PRESS ENTER PARA SI CUALQUIER TECLA PARA NO \n");
    fflush(stdin);
    o=getch();
    while( validar(dni_a_buscar)==1)
    {

        system("cls");
        printf("Ingrese un DNI para modificar.Sin espacios, sin puntos. Solo numeros \n");
        fflush(stdin);
        gets(dni_a_buscar);
    }

    if(archi)
    {

        int aux=atoi(dni_a_buscar);
        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {

            if( aux==empleado.DNI )
            {

               do {

                    printf("---Ingrese una opcion--- \n");
                    printf("1- Cambiar Nombre y apellido\n");
                    printf("2- Cambiar nombre de usuario \n");
                    printf("3- Cambiar contraseña \n");
                    printf("4- Cambiar Rol de usuario \n");
                    printf("5- Cambiar el estado del empleado \n");
                    printf("ESC para salir \n");
                    fflush(stdin);
                    o=getch();
                    system("cls");
                    switch(o)
                    {

                    case '1':

                        printf("Ingrese Nombre y apellido\n");
                        fflush(stdin);
                        gets(empleado.apellido_y_nombre);
                        break;


                    case '2':

                        printf("Ingrese nombre de usuario\n");
                        fflush(stdin);
                        gets(empleado.usuario);
                        empleado=validaciones_nombre_usuario( empleado);
                        break;

                    case'3':


                            while (!contrasenia_valida)
                    {
                        printf("Ingrese la contrasenia:  \n");

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
                                printf("\nLa contraseña debe tener al menos 8 caracteres, una mayuscula y un caracter especial.\n");
                            }
                            else
                            {
                                contrasenia_valida = 1;
                            }
                        }
                    break;

                    case '4':


                        while(flag_num==1)
                        {
                            printf("Ingrese Rol de usuario. ");
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
                        break;

                    case '5':

                        if(empleado.eliminado==1)

                            printf("EL EMPLEADO ESTA DADO DE BAJA. Desea darlo de alta? Presione enter para Si\n");
                            char o1=0;
                            fflush(stdin);
                            o1=getch();
                            if(o1==13) /// EN ASCII 13 es el retorno de carro (ENTER para los mortales)
                                empleado.eliminado=0;

                        else

                            printf("EL EMPLEADO ESTA ACTIVO. Desea darlo de baja? Presione enter para Si\n");
                            char o2=0;
                            fflush(stdin);
                            o2=getch();
                            if(o2==13) /// EN ASCII 13 es el retorno de carro (ENTER para los mortales)
                                empleado.eliminado=1;


                        break;

                    case 27:

                        break;

                    default:

                        printf("Ingreso una opcion incorrecta elija nuevamente o presione ESC para volver atras\n");
                        fflush(stdin);
                        o=getch();
                        break;

                    }
                } while(o != 27);

            fseek(archi,-1*sizeof(empleado_de_laboratorio),SEEK_CUR);
            fwrite(&empleado,sizeof(empleado_de_laboratorio),1,archi);
            printf("EMPLEADO MODIFICADO\n");
            mostrar_1_empleado(empleado);
            system("pause");
            return;
            }
        }
    }
    else
        printf("ERROR EN ABRIR EL ARCHIVO EN MODIFICAR EMPLEADO \n");



    fclose(archi);
}

int login( )
{
    FILE *archi=fopen(ARCH_EMPLEADO,"r+b");
    empleado_de_laboratorio empleado_a_loguearse;
    empleado_de_laboratorio empleado;
    int flag=1;
    int num;
    printf("USUARIO\n");
    gets(empleado_a_loguearse.usuario);

    printf("CONTRASENIA \n");
    int i = 0;
    char ch;
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
            empleado_a_loguearse.contrasenia[i] = ch;
            printf("*");
            i++;
        }
    }
    empleado_a_loguearse.contrasenia[i] = '\0';
    if(archi)
    {
        while(fread(&empleado,sizeof(empleado_de_laboratorio),1,archi)>0)
        {
            if(strcmpi(empleado_a_loguearse.usuario,empleado.usuario)==0)
            {

                if(strcmp(empleado_a_loguearse.contrasenia,empleado.contrasenia)==0)
                {

                    if(empleado.eliminado==1)
                    {
                        printf("USTED HA SIDO DADO DE BAJA SOLICITE UN NUEVO USUARIO CON EL ADMIN O PROGRAMADOR \n");

                    }
                    else
                    {
                        printf("\nBienvenido %s \n",empleado.apellido_y_nombre);
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
        if(flag==1)
        {
            num=-1;

            printf("\n");
            printf("NOMBRE DE USUARIO O CONTRASENIA INCORRECTA \n");
        }

    }
    else
        printf("ERROR AL ABRIR EL ARCHIVO EN EL LOGIN \n");

    fclose(archi);

    return num;
}
int log_out()
{
    return -1;
}


void menu_empleados(int isLoggedin) ///MENU EMPLEADOS
{


    printf("EL USUARIO ES EL ADMIN \n");
    char o=0;

    do
    {
        printf("\n Seleccione una opcion:\n");
        printf("\n 1)Crear nuevo usuario");
        printf("\n 2)Dar de baja un empleado");
        printf("\n 3)Modificacion");
        printf("\n 4)Consulta"); ///Probar con switchs
        printf("\n 5)Lista empleados");
        printf("\n ESC Para salir de la sesion \n");

        fflush(stdin);
        o=getch();
        switch(o)
        {
            {
            case '1':
                crear_usuario();
                system("cls");
                break;
            case '2':


                dar_baja_empleado( );
                printf("EMPLEADOS DADOS DE BAJA \n");
                mostrar_empleados_inactivos();
                system("pause");
                system("cls");
                break;
            case '3':
                modificar_empleado();
                break;
            case '4':
                printf("INGRESE DNI A BUSCAAR \n");
                char busqueda[10];
                fflush(stdin);
                gets(busqueda);
                empleado_de_laboratorio emp;
                emp= busqueda_empleado(busqueda);
                if(emp.DNI==-1)
                    printf("NO SE ENCONTRO EL EMPLEADO \n");
                else
                {
                    printf("ATENCION!!!\n");
                    printf("DESEA REVELAR LA CONTRASEÑA?\n");
                    printf("Pulse enter para mostrar sino cualquier tecla\n");
                    char o=0;
                    fflush(stdin);
                    o=getch();
                    if(o==13)
                    {
                        mostrar_1_empleado(emp);;
                        printf("Contrasenia: %s\n",emp.contrasenia);
                        system("pause");
                    }
                    else
                    {
                        mostrar_1_empleado(emp);
                        system("pause");
                    }
                }

                break;
            case '5':
                system("cls");
                printf("EMPLEADOS ACTIVOS \n");
                mostrar_empleados_activos();
                printf(" \n");
                printf("----------------------------------");
                printf("EMPLEADOS INACTIVOS \n");
                mostrar_empleados_inactivos();
                system("pause");
                system("cls");
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
    }
    while(o!=ESC);


}
