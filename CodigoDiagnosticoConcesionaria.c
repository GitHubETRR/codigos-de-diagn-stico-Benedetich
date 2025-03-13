#include <stdio.h>
#define MAX 100
#define MAX_CHAR 100

typedef struct {
    char marca[MAX_CHAR];
    char modelo[MAX_CHAR];
    char patente[MAX_CHAR];
    int precio;
} concesionariaBene_t;

int ingresarAuto(concesionariaBene_t autos[], int numAutos);
void verAutos(concesionariaBene_t autos[], int numAutos);

int ingresarAuto(concesionariaBene_t autos[], int numAutos) {
    if (numAutos >= MAX) {
        printf("Máximo de autos alcanzado\n");
        return numAutos;
    }
    
    printf("Ingrese la marca de su auto:\n");
    scanf("%s", autos[numAutos].marca);

    printf("Ingrese el modelo de su auto:\n");
    scanf("%s", autos[numAutos].modelo);

    printf("Ingrese la patente de su auto:\n");
    scanf("%s", autos[numAutos].patente);

    printf("Ingrese el precio de su auto:\n");
    scanf("%d", &autos[numAutos].precio);

    return numAutos + 1;
}

void verAutos(concesionariaBene_t autos[], int numAutos) {
    if (numAutos == 0) {
        printf("No se han ingresado autos.\n\n");
        return;
    }

    printf("Lista de autos disponibles:\n");
    for (int i = 0; i < numAutos; i++) {
        printf("Auto número: %d\n", i + 1);
        printf("Marca: %s \n", autos[i].marca);
        printf("Modelo: %s \n", autos[i].modelo);
        printf("Patente: %s \n", autos[i].patente);
        printf("Precio: %d \n", autos[i].precio);
    }
}

int main() {
    concesionariaBene_t autos[MAX];
    int numAutos = 0;
    int opcion;

    do {
        printf("Bienvenido a la concesionaria Benedetich, este es un programa para ingresar los autos que tenemos disponibles. \n");
        printf("1: Ingresar un auto \n");
        printf("2: Ver autos \n");
        printf("3: Salir del programa \n");
        printf("Ingrese su opción:");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                numAutos = ingresarAuto(autos, numAutos);
                break;
            case 2:
                verAutos(autos, numAutos);
                break;
            case 3:
                printf("Saliendo del programa\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
