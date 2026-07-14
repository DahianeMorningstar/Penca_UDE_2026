
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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


//comparacion de matrices, calculo de puntos etc
int puntos=0, puntospartido;
int resultadoapuesta,resultadoreal; //para llevar cuenta de los resultados

printf("\n****************************************\n");
printf("Penca Mundial 2026");
printf("\n****************************************\n");
printf("Apuesta de %s - GRUPO: %c",usuario,grupo);
printf("\n============================================= \n");
printf("PARTIDO - RESULTADO APOSTADO - RESULTADO REAL - PUNTOS OBTENIDOS \n");

//comparacion, calculo e impresion de puntos
for(i=0;i<4;i++)
{
    for(j=i+1;j<4;j++) //se pone i+1 para no repetir los partidos de la misma columna
    {
        puntospartido=0;
         if(M[i][j]>M[j][i])
                    resultadoapuesta=1;//gana el primer equipo
                else if(M[i][j]<M[j][i])
                    resultadoapuesta=2;//gana el segundo equipo
                else
                    resultadoapuesta=0;

        if(R[i][j]>R[j][i])
                    resultadoreal=1;//gana el primer equipo
                else if(R[i][j]<R[j][i])
                    resultadoreal=2;//gana el segundo equipo
                else
                    resultadoreal=0;//empate

        if(M[i][j]==R[i][j] && M[j][i]==R[j][i]){//se comparan los goles de cada lado
            puntos=puntos+5; puntospartido=5;
    }
        else if(resultadoapuesta==resultadoreal && resultadoreal>0){//se descartan los empates
            puntos=puntos+3; puntospartido=3;
    }
        printf("%s, %s - Apostado: %d, %d - Real: %d, %d -Ptos obtenidos: %d\n",paises[i],paises[j],M[i][j],M[j][i],R[i][j],R[j][i],puntospartido);
    }
}

printf("\nEn total obtuviste %d puntos",puntos);







}
