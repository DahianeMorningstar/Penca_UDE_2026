#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum { MAX = 80 };
typedef char cadena[MAX];

int main() {

    cadena usuario;
    cadena paises[4];
    int M[4][4];
    int R[4][4];
    char grupo;
    int i, j;

    srand(time(NULL));

    // Parte usuario
    printf("Ingrese su nombre de usuario: ");
    scanf(" %[^\n]", usuario);

    printf("Usuario: %s\n", usuario);

    // Grupo
    printf("\nIngrese el grupo (A-L): ");
    scanf(" %c", &grupo);

    printf("Grupo: %c\n", grupo);

    // Ingreso de paises
    printf("\nIngrese los paises:\n");

    for(i = 0; i < 4; i++)
    {
        printf("Ingrese el pais: ");
        scanf(" %[^\n]", paises[i]);
    }

    // Carga de apuestas
    printf("\nIngrese las apuestas:\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(i == j)
            {
                M[i][j] = -1;
            }
            else
            {
                printf("\nCuantos goles hara %s a %s: ", paises[i], paises[j]);
                scanf("%d", &M[i][j]);
            }
        }
    }

    // Resultados reales
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(i == j)
                R[i][j] = -1;
            else
                R[i][j] = rand() % 10;
        }
    }

    // Mostrar matriz de apuestas
    printf("\nMATRIZ DE APUESTAS\n\n");

    printf("%12s", "");

    for(i = 0; i < 4; i++)
        printf("%12s", paises[i]);

    printf("\n");

    for(i = 0; i < 4; i++)
    {
        printf("%12s", paises[i]);

        for(j = 0; j < 4; j++)
        {
            if(M[i][j] == -1)
                printf("%12s", "X");
            else
                printf("%12d", M[i][j]);
        }

        printf("\n");
    }

    // Mostrar resultados reales
    printf("\nRESULTADOS REALES SIMULADOS\n\n");

    printf("%12s", "");

    for(i = 0; i < 4; i++)
        printf("%12s", paises[i]);

    printf("\n");

    for(i = 0; i < 4; i++)
    {
        printf("%12s", paises[i]);

        for(j = 0; j < 4; j++)
        {
            if(R[i][j] == -1)
                printf("%12s", "X");
            else
                printf("%12d", R[i][j]);
        }
        printf("\n");

    }
}