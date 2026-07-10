#include <iostream>
#include <stdio.h>
using namespace std;

//const int MAX=80;
enum {MAX=80};
typedef char string[MAX];

int main() {

string usuario;
int i,j;
string paises[4];
int M[4][4];
char grupo;

    //parte usuario
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", usuario);
        while (usuario[i] != '\0') {
            printf("%c", usuario[i]);
            i++;
        }
        printf("\n");
    //grupi
    printf("Ingrese el grupo (A-L): ");
    scanf(" %c", &grupo);
    printf("Grupo: %c\n", grupo);

    //ingresa paises
    for(i=0; i<4; i++){
        printf("Ingrese el pais: ");
        scanf("%s", paises[i]);
    }
    //muestra paises
    printf("Paises:\n");
    for (i = 0; i < 4; i++) {
    int j = 0;
        while (paises[i][j] !='\0') {
            printf("%c ", paises[i][j]);
            j++;
        }
        printf("\n");
    }
    //parte dos
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){

            if(i==j){
                M[i][j]=-1;
            } else {
                printf("Cuantos goles hara %s a %s\n", paises[i], paises[j]);
                scanf("%d", &M[i][j]);
            }
        }
    }
}