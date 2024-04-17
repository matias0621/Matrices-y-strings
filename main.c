#include <stdio.h>
#include <stdlib.h>

void cargarMatriz (int dimF, int dimC, int M[dimF][dimC]);
void mostrarMatriz (int dimF, int dimC, int M[dimF][dimC]);
void sumarMatriz (int dimF, int dimC, int M[dimF][dimC]);
float promedioDeMatriz(int dimF, int dimC, int matriz[dimF][dimC]);
void cargarMatrizConNumerosAleatorios (int dimF, int dimC, int M[dimF][dimC]);
void buscarEnMatriz(int dimF, int dimC, int M[dimF][dimC]);
//void buscarEnMatriz(int dimF, int dimC, int M[dimF][dimC], int datoABuscar);
void cargarArregloDeStrings(int dimF, int dimC, char stringsArrays[dimF][dimC]);
void mostrarArregleDeString(int dimF, int dimC, char stringsArrays[dimF][dimC]);
int buscarPalabraEnArreglo(char arreglo[][100], int cantidad, char palabra[]);
int buscarPalabraEnArregloOrdenado(char arreglo[][100], int cantidad, char palabra[]);
void ordenarArregloAlfabeticamente(char arreglo[][100], int cantidad);

int main()
{
    /*
    int dimC = 2, dimF = 2;
    int datoABuscar = 0;
    int matriz[dimF][dimC];
    */
    int dimF = 5, dimC = 5;
    char arrayString[dimF][dimC];
    cargarArregloDeStrings(dimF, dimC, arrayString);

    mostrarArregleDeString(dimF, dimC, arrayString);

    return 0;
}
void cargarMatriz (int dimF, int dimC, int M[dimF][dimC]){
    int f = 0;
    int c = 0;

    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            printf("Tienes que cargar toda la matriz, ingrese el dato: \n");
            scanf("%d", &M[f][c]);
        }
    }

}

void mostrarMatriz (int dimF, int dimC, int M[dimF][dimC]){
    int f = 0;
    int c = 0;

    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            printf("|%d|", M[f][c]);
        }
        printf("\n");
    }

}

void sumarMatriz (int dimF, int dimC, int M[dimF][dimC]){
    int f = 0;
    int c = 0;
    int suma = 0;

    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            suma += M[f][c];
        }
    }

}


void cargarMatrizConNumerosAleatorios (int dimF, int dimC, int M[dimF][dimC]){
    int f = 0;
    int c = 0;

    printf("Cargando la matriz...");
    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            M[f][c] = rand () % 11 + 90;
        }
    }

}


float promedioDeMatriz(int dimF, int dimC, int matriz[dimF][dimC]){
    int f = 0;
    int c = 0;
    int sumaParaPromedio = 0;
    int sumaLosNumero = 0;
    float promedio = 0;

    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            sumaParaPromedio++;
            sumaLosNumero += matriz[f][c];
        }
    }
    promedio = (float)sumaLosNumero/(float)sumaParaPromedio;
    printf("El promedio de la matriz es de: %.2f", promedio);
    return promedio;
}

/*
void buscarEnMatriz(int dimF, int dimC, int M[dimF][dimC], int datoABuscar){
    int f = 0;
    int c = 0;

    for (f = 0; f < dimF; f++){
        for(c = 0; c < dimC; c++){
            if (M[f][c] == datoABuscar){
                printf("Si el dato %d esta en la matriz", datoABuscar);
                break;
            }
            else {

            }
        }
    }
}
*/

void cargarArregloDeStrings(int dimF, int dimC, char stringsArrays[dimF][dimC]) {
    printf("Ingrese valores para la matriz\n");
    for(int i = 0; i < dimF; i++) {
        gets(stringsArrays[i]);
    }
}

void mostrarArregleDeString(int dimF, int dimC, char stringsArrays[dimF][dimC]) {
    printf("Contenido del arreglo:\n");
    for(int i = 0; i < dimF; i++) {
        puts(stringsArrays[i]);
    }
}

int buscarPalabraEnArreglo(char arreglo[][100], int cantidad, char palabra[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(arreglo[i], palabra) == 0) {
            return i; // Se encontró la palabra, retorna el índice de la fila
        }
    }
    return -1; // La palabra no se encontró en el arreglo
}

int buscarPalabraEnArregloOrdenado(char arreglo[][100], int cantidad, char palabra[]) {
    int izquierda = 0;
    int derecha = cantidad - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        int comparacion = strcmp(arreglo[medio], palabra);

        // Si la palabra está en la posición media
        if (comparacion == 0) {
            return medio;
        }

        // Si la palabra está en la mitad izquierda
        if (comparacion > 0) {
            derecha = medio - 1;
        }
        // Si la palabra está en la mitad derecha
        else {
            izquierda = medio + 1;
        }
    }

    return -1; // La palabra no se encontró en el arreglo
}

void ordenarArregloAlfabeticamente(char arreglo[][100], int cantidad) {
    for (int i = 1; i < cantidad; i++) {
        char palabraActual[100];
        strcpy(palabraActual, arreglo[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(arreglo[j], palabraActual) > 0) {
            strcpy(arreglo[j + 1], arreglo[j]);
            j--;
        }
        strcpy(arreglo[j + 1], palabraActual);
    }
}
