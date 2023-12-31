#include "pacientes.h"

arbolPaciente* cargar_arbol_pacientes(char nombre_paciente[],arbolPaciente *arbol)
{
    FILE *archi = fopen(nombre_paciente,"rb");
    stPaciente paciente;
                                                 /// CARGA EL ARBOL AL INICIO DEL PROGRAMA
    if(archi){

         while(fread(&paciente,sizeof(stPaciente),1,archi) > 0){

            arbol = agregar_paciente(arbol,crear_nodo_arbol(paciente));


         }

        fclose(archi);

    }


return arbol;

}

arbolPaciente* crear_paciente(char nombre_paciente[],arbolPaciente *arbol){

    stPaciente paciente;

    paciente.dni = crear_dni(arbol); /// FUNCION VALIDA TAMA�O DNI Y QUE NO EXISTA EN EL ARBOL
    paciente.eliminado = 0;

       system("cls");
       consola_vacia();
       gotoxy(1,7);
      printf("\n\t ingrese Apellido y Nombre del paciente: \n\n\t");
      fflush(stdin);
      gets(paciente.Apellido_nombre);


   while(validar_nombre(paciente.Apellido_nombre)){
      system("cls");
      consola_vacia();
       gotoxy(1,7);                                  /// VALIDA QUE NO TENGA NUMEROS Y QUE NO TENGA ESPACIOS
      printf("\n\t No corresponde a un nombre \n ");
      printf("\n\t ingrese Apellido y Nombre del paciente: ");
      fflush(stdin);
      gets(paciente.Apellido_nombre);

      }

      paciente.edad = crear_edad();  /// VALIDA EDAD QUE NO SEAN LETRAS Y QUE ESA DE 1 A 100

      do{
            system("cls");
            consola_vacia();
             gotoxy(1,7);
      printf(" \t ingrese la direccion \n\t");
      gets(paciente.direccion);


      }while(strlen(paciente.direccion) < 5);

      do{
         system("cls");
         consola_vacia();
         gotoxy(1,7);                                       /// VALIDA QUE SEAN NUMEROS Y QUE SEAN TENGA MAS DE 8 CARACTERES
         printf(" \t ingrese el numero de telefono \n\t");
         gets(paciente.telefono);

      }while(validar_edad(paciente.telefono) || strlen(paciente.telefono) < 9);
      system("cls");
      consola_vacia();
       gotoxy(1,7);
      mostrar_paciente(paciente);

  char opc = 0;

  printf("\n\t Son correctos los datos ? s/n \n");    /// MUESTRA EL PACIENTE Y PODES CARGARLO O NO
  fflush(stdin);
  opc = getch();

  if(opc == 's' || opc == 'S')      /// se preciona s para cargar los datos
    {
          system("cls");
       consola_vacia();
         gotoxy(1,7);
    printf(" \n \t*DATOS CARGADOS   . . . \n \t*");

   cargar_Archivo_paciente(nombre_paciente,paciente);
   arbol = agregar_paciente(arbol,crear_nodo_arbol(paciente)); /// CARGA NUEVO PACIENTE AL ARBOL


    system("pause");


  }else{
     system("cls");
     consola_vacia();
       gotoxy(1,7);
   printf(" \t NO fueron cargados los datos... \n \t");
   system("pause");


  }


return arbol;



}

arbolPaciente * modificar_paciente_buscar(char nombre_paciente[],arbolPaciente * arbol){
     char dni_char[15];
     int dni;

    printf("\t ingrese el dni del paciente que desea modificar \n");
    printf("\t ingrese DNI: ");
    gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
         system("cls");
     consola_vacia();
       gotoxy(1,7);
     printf("\t no corresponde a un DNI \n");
     printf("\t ingrese un DNI: ");
     gets(dni_char);

   }
   dni = atoi(dni_char);
   arbolPaciente *aux = buscar_paciente(arbol,dni);  /// BUSCA PACIENTE EN EL ARBOL

   if(aux != NULL){
         system("cls");
         consola_vacia();
          gotoxy(1,7);
        mostrar_paciente(aux->paciente);
        char opc;
       printf(" \n\t desea modificar el paciente ? \n");
       printf("\t presione cualquier tecla para continuar, ESC para salir \n");
       opc = getch();
       if(opc != ESC){

            aux->paciente = modificar_paciente(aux->paciente,arbol);        /// ENTRAS AL MENU PARA MODIFICAR LOS CAMPOS Y LO RETORNA
            modificar_archivo_pacientes(nombre_paciente,dni,aux->paciente);





       }





   }else{
     system("cls");
     printf("\n\t no se encontro el DNI del paciente \n ");



   }

 return arbol;

}
stPaciente modificar_paciente(stPaciente a,arbolPaciente *arbol){  /// funcion que modifica un paciente
        system("cls");                                               /// recible a un paciente y lo devuelve modificado
        consola_vacia();
         gotoxy(1,7);

     printf("\n \tQue dato desea modificar?");

     printf("\n\t[1]   - MODIFICAR NOMBRE Y APELLIDO");
     printf("\n \t[2]   - MODIFICAR EDAD");
     printf("\n \t[3]   - MODIFICAR DIRECCION");
     printf("\n\t[4]   - MODIFICAR TELEFONO");
     printf("\n\t[5]   - DAR DE ALTA");
     printf("\n\t[6]   - MODIFICAR DNI");


   char opcion;
   fflush(stdin);
   opcion = getch();
    switch(opcion)
    {
      case 49:
                     system("cls");
                     consola_vacia();
                      gotoxy(1,7);
                     printf("\n\t ingrese Apellido y Nombre del paciente: ");
                     fflush(stdin);
                     gets(a.Apellido_nombre);


             while(validar_nombre(a.Apellido_nombre))
                {
                       system("cls");
                       consola_vacia();
                        gotoxy(1,7);
                  printf("\n\t No corresponde a un nombre \n ");
                  printf("\n\t ingrese Apellido y Nombre del paciente: ");
                  fflush(stdin);
                  gets(a.Apellido_nombre);

                 }



          break;
      case 50:

                          a.edad = crear_edad();


         break;
      case 51:
                   do{
                      system("cls");
                      consola_vacia();
                       gotoxy(1,7);
                      printf(" \t ingrese la direccion \n");
                      gets(a.direccion);


                       }while(strlen(a.direccion) < 5);

        break;
         case 52:

                       do{
                       system("cls");
                       consola_vacia();
                       gotoxy(1,7);
                       printf(" \t ingrese el numero de telefono \n");
                       gets(a.telefono);

                     }while(validar_edad(a.telefono) || strlen(a.telefono) < 9);


            break;

         case 53:

            a.eliminado = 0;



        break;

         case 54:

                 a.dni = crear_dni(arbol);




          break;

         case ESC:



            break;

      default:
                printf("\n\t Opcion incorrecta");
                system("pause");
            break;



    }

return a;

}

arbolPaciente* baja_paciente(char nombre_paciente[],arbolPaciente *arbol){
    char dni_char[15];
     int dni;
    printf("\t ingrese el dni del paciente que desea dar de baja \n");
    printf("\t ingrese DNI: ");
    gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
         system("cls");
     printf("\t no corresponde a un DNI \n");
     printf("\t ingrese un DNI: ");
     gets(dni_char);

   }
   dni = atoi(dni_char);
   arbolPaciente *aux = buscar_paciente(arbol,dni);

   if(aux != NULL){
         system("cls");
        mostrar_paciente(aux->paciente);
        char opc;
       printf(" \n\t desea dar de baja el paciente ? \n");
       printf("\n\t presione cualquier tecla para dar de baja\n");
    printf("\t ESC para no dar de baja \n");
       opc = getch();
       if(opc != ESC){

             if(aux->ingresos == NULL){

                 aux->paciente.eliminado = 1;
             modificar_archivo_pacientes(nombre_paciente,dni,aux->paciente);
              printf("\t el paciente fue dado de baja \n");


             }else{
                     system("cls");
                     consola_vacia();
                      gotoxy(1,7);
                printf("\t el paciente tiene un ingreso asociado \n");
                printf("\t no se le puede dar de baja \n \t");
                system("pause");


             }


       }


   }else{
     system("cls");
     printf("\n\t no se encontro el DNI del paciente \n ");



   }

 return arbol;

}

void consulta_paciente(arbolPaciente *arbol){

   char dni_char[15];
     int dni;
        system("cls");
        consola_vacia();
         gotoxy(1,7);
    printf("\t ingrese el dni del paciente que desea consultar \n");
    printf("\t ingrese DNI: ");
    gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
         system("cls");
        consola_vacia();
         gotoxy(1,7);
     printf("\t no corresponde a un DNI \n");
     printf("\t ingrese un DNI: ");
     gets(dni_char);

   }
   dni = atoi(dni_char);
    arbolPaciente *aux = buscar_paciente(arbol,dni);

    if(aux != NULL){
         system("cls");
         printf("\n");
        mostrar_paciente(aux->paciente);
        printf("\n \t");
        system("pause");

   }else{

      system("cls");
        consola_vacia();
         gotoxy(1,7);
     printf("\t el DNI no existe  \n");
        printf("\n \t");
        system("pause");

   }



}

void listado_ingresos_dePaciente(arbolPaciente *arbol){

    char dni_char[15];
     int dni;
    mostrar_paciente_porapellido(arbol);
    printf(" \n\n\t ingrese el dni del paciente \n");
    printf("\t ingrese DNI: ");
    fflush(stdin);
    gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
        system("cls");
     mostrar_paciente_porapellido(arbol);
     printf("\n\n\t no corresponde a un DNI \n");
     printf("\t ingrese un DNI: ");
     fflush(stdin);
     gets(dni_char);

   }
   dni = atoi(dni_char);

   arbolPaciente *aux = buscar_paciente(arbol,dni);
  if(aux){
   if(aux->ingresos == NULL){
    system("cls");
    printf("\n\t no tiene ingresos \n");
    system("pause");

   }else{

   struct nodoLab *lab = aux->ingresos;

   system("cls");
   int i = 0;
 setConsoleColor(15,5);
   gotoxy(3,1);
  printf("INGRESO     FECHA INGRESO   FECHA RETIRO        DNI         MATRICULA       ELIMINADO        ");
  while (lab != NULL){

       mostrar_ingreso(lab->labo,i+2);
       i++;
       lab = lab->siguiente;

  }
  printf("\n");
  system("pause");
   }

 }else{
     system("cls");
    printf("\n\t no existe el paciente \n");
    system("pause");


 }

}

void cargar_Archivo_paciente(char nombre[],stPaciente a){
  FILE *archi = fopen(nombre,"ab");
  if(archi !=NULL){

      fwrite(&a,sizeof(stPaciente),1,archi);

      fclose(archi);


  }


}
void modificar_archivo_pacientes(char nombre[],int dni_buscar,stPaciente paciente)
{
    FILE *archi = fopen(nombre, "r+b");

    if (archi!= NULL)
    {
        stPaciente a;
        int encontrado = 0;


           while (!encontrado && fread(&a, sizeof(stPaciente), 1, archi) > 0)
             {

                    if (a.dni == dni_buscar)  /// encuentra el paciente
                    {
                        fseek(archi, -sizeof(stPaciente), SEEK_CUR);
                        fwrite(&paciente, sizeof(stPaciente), 1, archi); /// sobreescribe el paciente
                        encontrado = 1;

                    }

               }


        fclose(archi);

     }

 }

int crear_dni(arbolPaciente *arbol){

 char dni_char[15];
    int dni;

   do{
         system("cls");
     consola_vacia();
       gotoxy(1,7);
   printf("\t ingrese nuevo DNI: ");
   gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
          system("cls");
        consola_vacia();
         gotoxy(1,7);
     printf("\t no corresponde a un DNI \n");
     printf("\t ingrese un DNI: ");
     gets(dni_char);

   }
   dni = atoi(dni_char);
       system("cls");
 }while(buscar_paciente(arbol,dni)!= NULL); /// valida si existe el dni

 return dni;

}

int crear_edad(){

    char edad_char[15];
    int edad;
    system("cls");
     consola_vacia();
       gotoxy(2,7);
    printf("\t ingrese una edad \n \t");
    gets(edad_char);
    edad = atoi(edad_char);

    while(validar_edad(edad_char) || edad > 100 || edad < 1){
             system("cls");
          consola_vacia();
           gotoxy(2,7);
        printf("\t no corresponde a una edad \n");
        printf("\t ingrese una edad \n \t");
        gets(edad_char);
        edad = atoi(edad_char);
    }


   return edad;

}



arbolPaciente* inic_arbol(){

 return NULL;

}

arbolPaciente* crear_nodo_arbol(stPaciente dato){

   arbolPaciente *aux = (arbolPaciente*)malloc(sizeof(arbolPaciente));
   aux->paciente = dato;
   aux->izq = NULL;
   aux->der = NULL;
   aux->ingresos = NULL;

   return aux;

}

arbolPaciente *agregar_paciente(arbolPaciente *lista,arbolPaciente *nuevo){
    if(lista == NULL){
        lista = nuevo;

    }else{

        if(lista->paciente.dni < nuevo->paciente.dni){

            lista->der = agregar_paciente(lista->der,nuevo);

        }else{

          lista->izq = agregar_paciente(lista->izq,nuevo);

        }

    }

    return lista;

}
arbolPaciente *buscar_paciente(arbolPaciente *arbol,int dato)
{
     arbolPaciente *rta = NULL;

    if(arbol != NULL)
    {

      if(arbol->paciente.dni == dato){
            return arbol;
      }
      else
         {
            if(arbol->paciente.dni < dato)
            {
              rta = buscar_paciente(arbol->der,dato);
            }
            else
            {
              rta = buscar_paciente(arbol->izq,dato);
            }

         }
       }

    return rta;
}


arbolPaciente* cargar_arbol_ingresos(arbolPaciente *arbol){

    ingresosLaboratorio ingresos;
    pracXingreso practicas;

    FILE *archi = fopen("ingresos.bin","rb");

    FILE *archi_practicas = fopen("practicas.bin","rb");

    if(archi){

        while(fread(&ingresos,sizeof(ingresosLaboratorio),1,archi) > 0 ){

           struct nodoLab *nuevo = crear_nodo_lab(ingresos);


            arbolPaciente *buscar = buscar_paciente(arbol,ingresos.dni);


            if(buscar != NULL){

                       buscar->ingresos = agregar_al_principio(buscar->ingresos,nuevo);

                     if(archi_practicas)
                      {

                            rewind(archi_practicas);

                            while(fread(&practicas,sizeof(pracXingreso),1,archi_practicas) > 0)
                                {

                                    if(practicas.nroIngreso == buscar->ingresos->labo.numeroIngreso){

                                         nodo_simple_pxi *practica = crear_nodo_pxi(practicas);
                                           buscar->ingresos->listaIngresoPrac  = agregar_ppio(buscar->ingresos->listaIngresoPrac,practica);

                                        }

                                }

                     }
                 }
        }
     fclose(archi);
    fclose(archi_practicas);
    }

    return arbol;

}

void consulta_ingreso_particular(arbolPaciente *arbol)
{
     char ingreso[15];
     int ingreso_num;
     mostrar_ingresos();
     printf("\n\t ingrese el numero de ingreso a consultar \n");
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

   if(buscar != NULL){
        system("cls");

 printf(" \n   INGRESO     FECHA INGRESO   FECHA RETIRO        DNI         MATRICULA       ELIMINADO ");

      mostrar_ingreso(buscar->labo,2);

      if(buscar->listaIngresoPrac != NULL){
        printf("\n");
        muestra_lista(buscar->listaIngresoPrac);

        system("pause");
      }
      else{

         printf("\n\n\t <<<<<<< No tiene practicas >>>>>>>>> \n\n ");

      system("pause");

      }




   }
   else
   {

     system("cls");
     consola_vacia();
     gotoxy(1,7);
     printf("\t el ingreso no existe \n");
     system("pause");

   }




}

int validar(char numero[]){

    int flag = 0;

    for (int i = 0; numero[i] != '\0'; i++) {
        if (isspace(numero[i])) {
        flag = 1; }  /// detecta un escpacio
        if (isdigit(numero[i])) { /// si es un numero no continua verificando
        } else if (isalpha(numero[i])) {  /// detecta si es una letra
            flag = 1;
        }else if (ispunct(numero[i])) {   /// detecta si es un simbolo
            flag = 1;
        }
    }
    int num = atoi(numero);
    if(  num < 1000000 || num > 99999999 ){

       flag = 1;         /// detecta que sean 8 caracteres correctos

    }
   return flag;
}
int validar_edad(char numero[]){

    int flag = 0;

    for (int i = 0; numero[i] != '\0'; i++) {
        if (isspace(numero[i])) {
        flag = 1; }  /// detecta un escpacio
        if (isdigit(numero[i])) { /// si es un numero no continua verificando
        } else if (isalpha(numero[i])) {  /// detecta si es una letra
            flag = 1;
        }else if (ispunct(numero[i])) {   /// detecta si es un simbolo
            flag = 1;
        }
    }

   return flag;
}

int validar_nombre(const char Letras[]) {
    int flag = 0;
    int tam = strlen(Letras);
    int espacioConteo = 0; // Contador de espacios

    if (tam < 7) {
        flag = 1; // Nombre demasiado corto
    }

    for (int i = 0; i < tam; i++) {
        if (isspace(Letras[i])) {
            espacioConteo++; // Incrementar el contador de espacios
            if (espacioConteo > 2) {
                flag = 1; // M�s de dos espacios consecutivos, establecer la bandera en 1
                break;     // Salir del bucle
            }
        } else {
            espacioConteo = 0; // Reiniciar el contador cuando no hay un espacio
        }

        if (!isalpha(Letras[i]) && !isspace(Letras[i])) {
            flag = 1; // Se encontr� un car�cter que no es una letra ni espacio
            break;    // Salir del bucle
        }
    }

    return flag;
}
int validar_char(char Letras[]) {
    int flag = 0;

     if(strlen(Letras)== 0 ){
            flag = 1;                /// detecta enter, ya que la cadena con el strlen no tiene extencion.
            return flag;
        }

    for (int i = 0; Letras[i] != '\0'; i++) {
        if (!isalpha(Letras[i])) {
            flag = 1; /// Se encontr� un car�cter que no es una letra, establecer la bandera en 1
            break;    /// Salir del bucle
        }
    }

    return flag;
}

int contar_nodos(arbolPaciente *arbol)
{
    int rsp;

    if(arbol == NULL)
    {
      rsp = 0;
    }
    else
    {
      rsp = 1 + contar_nodos(arbol->izq) + contar_nodos(arbol->der);
    }

  return rsp;

}
void copiar_arbol_arreglo(stPaciente a[] ,arbolPaciente *arbol, int *i, int validos){

  if(arbol != NULL && (*i) < validos){

     a[*i] = arbol->paciente;
     (*i)++;
     copiar_arbol_arreglo(a,arbol->izq,i,validos);
     copiar_arbol_arreglo(a,arbol->der, i,validos);

  }

}

void mostrar_paciente_porapellido(arbolPaciente *arbol){

  int validos = contar_nodos(arbol); /// se busca los validos con los id
  stPaciente a[validos]; /// se crea un arreglo con la dimension del archivo

   int index = 0;
   copiar_arbol_arreglo(a,arbol,&index,validos);

    ordenar_seleccion(a,validos);   ///se ordena el arreglo

       system("cls");
 printf(" \n      DNI       APELLIDO Y NOMBRE           EDAD     TELEFONO       DIRECCION       ELIMINADO ");
  for(int i = 0 ; i < validos; i++){

       mostrar_pacientes(a[i],i+2);  /// se muestra ordenado el arreglo


  }

}

int posmenor(stPaciente a[],int validos,int pos){
    char menor[40];
     strcpy(menor,a[pos].Apellido_nombre);
    int pos_menor = pos;
    int i = pos + 1;
    while(i < validos){

        if(strcmpi(menor,a[i].Apellido_nombre) > 0){
            pos_menor = i;
            strcpy(menor, a[i].Apellido_nombre);
        }
        i++;

    }
    return pos_menor;


}
void ordenar_seleccion(stPaciente a[],int validos){
   int i = 0;
   int posMenor;
   stPaciente aux;
   while(i < validos -1){

      posMenor = posmenor(a,validos,i);
      aux = a[posMenor];
      a[posMenor]= a[i];
      a[i] = aux;
      i++;
   }



}
  void mostrar_pacientes(stPaciente a, int i){

   setConsoleColor(15,5);
   gotoxy(1,i); printf("  %-10i ",a.dni);
   gotoxy(15,i); printf("  %-21s ",a.Apellido_nombre);
   gotoxy(43,i); printf("  %-20i ",a.edad);
   gotoxy(50,i); printf("  %-30s ",a.telefono);
   gotoxy(65,i); printf("  %-30s ",a.direccion);
   gotoxy(85,i);
 if (a.eliminado == 0)
    {
        setConsoleColor(15,10); // Verde
        printf("  %-15s", "No");
    }
    else
    {

        setConsoleColor(15,4);// Rojo
        printf("  %-15s", "Si");
    }
    setConsoleColor(11,0);
   }



void mostrar_paciente(stPaciente a){

    printf(" \t DNI                %i \n",a.dni);
    printf(" \t Apellido y Nombre: %s \n",a.Apellido_nombre);
    printf(" \t EDAD               %i \n",a.edad);
    printf(" \t direcion           %s \n",a.direccion);
    printf(" \t telefono           %s \n",a.telefono);
    printf(" \t Eliminado:         %s \n", (a.eliminado == 0) ? "No" : "Si");

}
void mostrar_pacientes_arbol(arbolPaciente *arbol)
{

    if(arbol)
    {
        mostrar_pacientes_arbol(arbol->izq);
        mostrar_paciente(arbol->paciente);
        mostrar_pacientes_arbol(arbol->der);
    }

}

void mostrar_ingresos(){

    ingresosLaboratorio aux;
  FILE *archi = fopen("ingresos.bin","rb");
  int i = 2;
   if(archi){
        setConsoleColor(15,5);
   gotoxy(3,1);
  printf("INGRESO     FECHA INGRESO   FECHA RETIRO        DNI         MATRICULA       ELIMINADO        ");
      while( fread(&aux,sizeof(ingresosLaboratorio),1,archi)> 0){
         mostrar_ingreso(aux,i);
         i++;

         }
      fclose(archi);

   }
   printf("\n");


}

int buscarid_practica(int dato) /// busco si existe la practica para cargar y si no se dio de baja
{                                               /// devuelve falso si la practica existe y no esta dada de baja
    FILE *archi = fopen("estudios.bin","rb");
    practicas a;
    int flag = 0;

    if (archi != NULL)
    {
        while(!flag && fread(&a,sizeof(practicas),1,archi) > 0)
        {

            if(a.nroPractica == dato && a.eliminado == 0)
            {
                flag = 1;


            }

        }

       fclose(archi);

    }

   return flag;

}
void carga_alta_pracXingreso(pracXingreso a)
{
  FILE *archi = fopen("practicas.bin","ab");


  if(archi){

    fwrite(&a,sizeof(pracXingreso),1,archi);

    fclose(archi);

  }

}

arbolPaciente *menu_pacientes(char nombre_pacientes[],arbolPaciente *arbol)
{   char opc;
    do{
  system("cls");
  consola_pacientes();
  printf("\n");
  fflush(stdin);
  opc = getch();
  switch(opc)
  {
       case 49:    system("cls");
                consola_vacia();
                gotoxy(0,7);
                arbol = crear_paciente(nombre_pacientes,arbol);
                break;
       case 50:
                  system("cls");
                consola_vacia();
                gotoxy(0,7);
                arbol = modificar_paciente_buscar(nombre_pacientes,arbol);

                break;
       case 51:
                 system("cls");
                 consola_vacia();
                gotoxy(0,7);
               arbol = baja_paciente(nombre_pacientes,arbol);
                break;
       case 52:
                 system("cls");
                 consulta_paciente(arbol);

          break;
       case 53:
                 system("cls");
              listado_ingresos_dePaciente(arbol);

                break;
       case 54:
                 system("cls");
                consulta_ingreso_particular(arbol);
                break;
       case 55:
                 system("cls");
                 mostrar_paciente_porapellido(arbol);
                 printf("\n");
                system("pause");
                break;



       case ESC:

                break;
       default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                system("pause");
                break;

    }
  } while( opc != ESC);

   return arbol;
}
arbolPaciente *menu_pacientes_labo(char nombre_pacientes[],arbolPaciente *arbol)
{   char opc;
    do{
  system("cls");
  consola_pacientes_labo();
  printf("\n");
  fflush(stdin);
  opc = getch();
  switch(opc)
  {
       case 49:    system("cls");
                consola_vacia();
                gotoxy(0,7);
                consulta_paciente(arbol);
                break;
       case 50:
                  system("cls");
                 listado_ingresos_dePaciente(arbol);

                break;
       case 51:
               system("cls");
                consulta_ingreso_particular(arbol);

                break;
       case 52:
                  system("cls");
                 mostrar_paciente_porapellido(arbol);
                 printf("\n");
                system("pause");

          break;


       case ESC:

                break;
       default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                system("pause");
                break;

    }
  } while( opc != ESC);

   return arbol;
}
