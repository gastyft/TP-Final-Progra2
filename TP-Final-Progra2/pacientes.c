
#include "pacientes.h"







arbolPaciente* cargar_arbol_pacientes(char nombre_paciente[],arbolPaciente *arbol){
    FILE *archi = fopen(nombre_paciente,"rb");
    stPaciente paciente;

    if(archi){

         while(fread(&paciente,sizeof(paciente),1,archi) > 0){

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
      printf("\n\t ingrese Apellido y Nombre del paciente: ");
      fflush(stdin);
      gets(paciente.Apellido_nombre);


   while(validar_nombre(paciente.Apellido_nombre)){
      system("cls");
      printf("\n\t No corresponde a un nombre \n ");
      printf("\n\t ingrese Apellido y Nombre del paciente: ");
      fflush(stdin);
      gets(paciente.Apellido_nombre);

      }

      paciente.edad = crear_edad();

      do{
            system("cls");
      printf(" \t ingrese la direccion \n");
      gets(paciente.direccion);


      }while(strlen(paciente.direccion) < 5);

      do{
         system("cls");
         printf(" \t ingrese el numero de telefono \n");
         gets(paciente.telefono);

      }while(validar_edad(paciente.telefono) || strlen(paciente.telefono) < 9);

      mostrar_paciente(paciente);

  char opc = 0;
  printf("\n\t Son correctos los datos ? s/n \n");
  fflush(stdin);
  opc = getch();
  if(opc == 's' || opc == 'S')      /// se preciona s para cargar los datos
    {
    printf(" \n \t*DATOS CARGADOS   . . . \n \t*");
   cargar_Archivo_paciente(nombre_paciente,paciente);
   arbol = agregar_paciente(arbol,crear_nodo_arbol(paciente));


    system("pause");


  }else{
    system("cls");
   printf("NO fueron cargados los datos... \n");
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
      mostrar_paciente(a);

     printf("\n \tQue dato desea modificar?");

     printf("\n\t[1]   - MODIFICAR NOMBRE Y APELLIDO");
     printf("\n \t[2]   - MODIFICAR EDAD");
     printf("\n \t[3]   - MODIFICAR DIRECCION");
     printf("\n\t[4]   - MODIFICAR TELEFONO");
     printf("\n\t[5]   - DAR DE ALTA");
     printf("\n\t[6]   - MODIFICAR DNI");
     printf("\n\t[ESC]   - SALIR");


   char opcion;
   fflush(stdin);
   opcion = getch();
    switch(opcion)
    {
      case 49:
                     system("cls");
                     printf("\n\t ingrese Apellido y Nombre del paciente: ");
                     fflush(stdin);
                     gets(a.Apellido_nombre);


             while(validar_nombre(a.Apellido_nombre))
                {
                       system("cls");
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
                      printf(" \t ingrese la direccion \n");
                      gets(a.direccion);


                       }while(strlen(a.direccion) < 5);

        break;
         case 52:

                       do{
                       system("cls");
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
   printf("\t ingrese nuevo DNI: ");
   gets(dni_char);
   while( validar(dni_char)){           /// valida si es un numero
         system("cls");
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
    printf("\t ingrese una edad \n \t");
    gets(edad_char);
    edad = atoi(edad_char);

    while(validar_edad(edad_char) || edad > 100 || edad < 1){
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

void mostrar_paciente(stPaciente a){
    printf(" \t ___________________ \n");
    printf(" \t DNI                %i \n",a.dni);
    printf(" \t Apellido y Nombre: %s \n",a.Apellido_nombre);
    printf(" \t EDAD               %i \n",a.edad);
    printf(" \t direcion           %s \n",a.direccion);
    printf(" \t telefono           %s \n",a.telefono);
    printf(" \t Eliminado:         %s \n", (a.eliminado == 0) ? "No" : "Si");

}

void mostrar_pacientes(arbolPaciente *arbol)
{

    if(arbol)
    {
        mostrar_pacientes(arbol->izq);
        mostrar_paciente(arbol->paciente);
        mostrar_pacientes(arbol->der);
    }

}

