#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "goto_xy.h"


void gotoxy(int X,int Y){                             /// Cambia las coordenadas del cursor
      HANDLE hcon; /// ventana
      hcon = GetStdHandle(STD_OUTPUT_HANDLE); /// manipulacion de la consola
      COORD dwPos;  /// se crea una estructura de las cordenadas

      /// redideccion de la estructura a nuestras variables
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);   /// primer parametro la consola a manupular
                                              /// segundo parametro estructura de las cordenadas
}
