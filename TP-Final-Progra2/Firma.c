#include <stdio.h>
#include<stdlib.h>
#include"Firma.h"

void firma(){

            system("COLOR B");

    char firmaT[100][100] = {
    {"#######  #  #######  #     #######  #######  #     #  \n"},
    {"   #             #         #        #     #  #     #  \n"},
    {"   #     #      #    #     #        #     #  #     #  \n"},
    {"   #     #     #     #     #        #     #  #     #  \n"},
    {"   #     #    #      #     #        #     #  #     #  \n"},
    {"   #     #   #       #     #        #     #  #     #  \n"},
    {"   #     #  #######  #     #######  #######  #######  \n"}
  };
  // Imprimir la firma digital en grande
  for (int i = 0; i < 7; i++) {
    printf("%s", firmaT[i]);
  }
  printf("\n\n");
 char firmaM[100][100] = {
    {"#     #    ###    #     #  #######  #     #     #  #######         \n"},
    {"##   ##   #   #   #     #  #     #        ##   ##       #          \n"},
    {"# # # #  #     #  #     #  #     #  #     # # # #      #           \n"},
    {"#  #  #  #######  #     #  ######   #     #  #  #     #            \n"},
    {"#     #  #     #  #     #  #   #    #     #     #    #             \n"},
    {"#     #  #     #  #     #  #    #   #     #     #   #              \n"},
    {"#     #  #     #  #######  #     #  #     #     #  #######         \n"}
  };
  // Imprimir la firma digital en grande
  for (int i = 0; i < 7; i++) {
    printf("%s", firmaM[i]);
  }
  printf("\n\n");
  char firmaS[100][100] = {
    {"#######  #######  #######  #     #######  #######     \n"},
    {"#        #     #  #              #           #        \n"},
    {"#        #     #  #        #     #           #        \n"},
    {"#######  #     #  #######  #     #######     #        \n"},
    {"      #  #     #  #        #           #     #        \n"},
    {"      #  #     #  #        #           #     #        \n"},
    {"#######  #######  #        #     #######     #        \n"}
  };
  // Imprimir la firma digital en grande
  for (int i = 0; i < 7; i++) {
    printf("%s", firmaS[i]);
  }

   printf("\n\n");
  char firma[100][100] = {
    {"#######    ###    #######  #######  #     #     #######  #######   \n"},
    {"#         #   #   #           #      #   #      #           #      \n"},
    {"#        #     #  #           #       # #       #           #      \n"},
    {"#   ###  #######  #######     #        #        #######     #      \n"},
    {"#     #  #     #        #     #        #        #           #      \n"},
    {"#     #  #     #        #     #        #        #           #      \n"},
    {"#######  #     #  #######     #        #        #           #      \n"}

  };

  // Imprimir la firma digital en grande
  for (int i = 0; i < 7; i++) {

    printf("%s", firma[i]);
  }

}

void cierre_firma(){



firma();
   int i = 0;
   while (!kbhit())
    {
    if (!i)
        {
        system("COLOR B0");
        i =1;
        usleep(100000);
        usleep(100000);
         usleep(100000);
        usleep(100000);
        system("COLOR D0");
         usleep(100000);
        usleep(100000); usleep(100000);
        usleep(100000);
        system("COLOR E0");
         usleep(100000);
        usleep(100000); usleep(100000);
        usleep(100000);
        }
    else
        {
        system("COLOR A0");
         usleep(100000);
        usleep(100000);
        usleep(100000);
        usleep(100000);
        system("COLOR C0");
         usleep(100000);
        usleep(100000); usleep(100000);
        usleep(100000);
system("COLOR D0");
         usleep(100000);
        usleep(100000);
        usleep(100000);
        usleep(100000);
        i = 0;
        }
    }

}

///TOPSECRET




