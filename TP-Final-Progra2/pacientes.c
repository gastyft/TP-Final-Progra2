#include "pacientes.h"

arbolPaciente* cargar_arbol_pacientes(char nombre_paciente[],arbolPaciente *arbol){
    FILE *archi = fopen(nombre_paciente,"rb");
    stPaciente paciente;

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

    paciente.dni = crear_dni(arbol);
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
       gotoxy(1,7);
      printf("\n\t No corresponde a un nombre \n ");
      printf("\n\t ingrese Apellido y Nombre del paciente: ");
      fflush(stdin);
      gets(paciente.Apellido_nombre);

      }

      paciente.edad = crear_edad();

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
         gotoxy(1,7);
         printf(" \t ingrese el numero de telefono \n\t");
         gets(paciente.telefono);

      } while(validar_edad(paciente.telefono) || strlen(paciente.telefono) < 9);
      system("cls");
      consola_vacia();
       gotoxy(1,7);
      mostrar_paciente(paciente);

  char opc = 0;

  printf("\n\t Son correctos los datos ? s/n \n");
  fflush(stdin);
  opc = getch();

  if(opc == 's' || opc == 'S')      /// se preciona s para cargar los datos
    {
          system("cls");
       consola_vacia();
         gotoxy(1,7);
    printf(" \n \t*DATOS CARGADOS   . . . \n \t*");

   cargar_Archivo_paciente(nombre_paciente,paciente);
   arbol = agregar_paciente(arbol,crear_nodo_arbol(paciente));


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
   arbolPaciente *aux = buscar_paciente(arbol,dni);

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

            aux->paciente = modificar_paciente(aux->paciente,arbol);
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
       printf("\t presione cualquier tecla para continuar, ESC para salir \n");
       opc = getch();
       if(opc != ESC){

             if(aux->ingreso == NULL){

                 aux->paciente.eliminado = 1;
             modificar_archivo_pacientes(nombre_paciente,dni,aux->paciente);
              printf("\t el paciente fue dado de baja \n");


             }else{

                printf("\t el paciente tiene un ingreso asociado \n");
                printf("\t no se le puede dar de baja \n");


             }


       }


   }else{
     system("cls");
     printf("\n\t no se encontro el DNI del paciente \n ");



   }

 return arbol;

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
   aux->ingreso = NULL;

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
    if(strlen(numero)> 8 || strlen(numero)< 8){

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
                flag = 1; // Más de dos espacios consecutivos, establecer la bandera en 1
                break;     // Salir del bucle
            }
        } else {
            espacioConteo = 0; // Reiniciar el contador cuando no hay un espacio
        }

        if (!isalpha(Letras[i]) && !isspace(Letras[i])) {
            flag = 1; // Se encontró un carácter que no es una letra ni espacio
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
            flag = 1; /// Se encontró un carácter que no es una letra, establecer la bandera en 1
            break;    /// Salir del bucle
        }
    }

    return flag;
}

int contar_pacientes(char nombre_paciente[]){

 FILE *archi = fopen(nombre_paciente,"rb");
 stPaciente a;
   int i = 0;

    if(archi){

         while(fread(&a,sizeof(stPaciente),1,archi) > 0){

            i++;

         }

        fclose(archi);

    }


return i;

}
void mostrar_paciente_porapellido(char nombre[]){
  int validos = contar_pacientes(nombre); /// se busca los validos con los id
  stPaciente a[validos]; /// se crea un arreglo con la dimension del archivo

  FILE *archi = fopen(nombre,"rb");

  if (archi != NULL){
      int i = 0;
      while(fread(&a[i],sizeof(stPaciente),1,archi) > 0){   /// se carga el arreglo

               i++;
      }
     fclose(archi);



     ordenar_seleccion(a,validos);   ///se ordena el arreglo

       system("cls");
        setConsoleColor(15,5);
        gotoxy(1,1);
 printf("       DNI       APELLIDO Y NOMBRE           EDAD     TELEFONO       DIRECCION       ELIMINADO  ");
  for(int i = 0 ; i < validos; i++){

       mostrar_pacientes(a[i],i+2);  /// se muestra ordenado el arreglo


  }

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
   printf("\n");
   setConsoleColor(15,5);
   gotoxy(1,i); printf("  %-20i ",a.dni);
   gotoxy(15,i); printf("  %-30s ",a.Apellido_nombre);
   gotoxy(43,i); printf("  %-15i ",a.edad);
   gotoxy(50,i); printf("  %-20s ",a.telefono);
   gotoxy(65,i); printf("  %-20s ",a.direccion);
   gotoxy(85,i);
    if (a.eliminado == 0) {
            setConsoleColor(15,10); // Verde
            printf("  %-10s", "No");
    } else {

       setConsoleColor(15,4);// Rojo
          printf("  %-10s", "Si");
    }

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

                system("pause");
                break;
       case 53:
                 system("cls");

                system("pause");
                break;
       case 54:
                 system("cls");

                system("pause");
                break;
       case 55:
                 system("cls");

                 mostrar_paciente_porapellido(nombre_pacientes);
                 printf("\n");
                 setConsoleColor(11,0);
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
