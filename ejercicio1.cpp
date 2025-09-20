#include <iostream>
using namespace std;

const int N = 20;

// Leer arreglo desde teclado
void leerArreglo(int arr[]) {
    cout << "Introduce " << N << " numeros enteros:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

// Mostrar arreglo
void mostrarArreglo(int arr[]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Contar pares e impares
void contarParesImpares(int arr[], int &pares, int &impares) {
    pares = 0;
    impares = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
}

// Encontrar segundo mayor y segundo menor
void segundoMayorMenor(int arr[], int &segMayor, int &segMenor) {
    int mayor = arr[0], menor = arr[0];

    // encontrar mayor y menor
    for (int i = 1; i < N; i++) {
        if (arr[i] > mayor) mayor = arr[i];
        if (arr[i] < menor) menor = arr[i];
    }

    // inicializamos
    segMayor = menor; 
    segMenor = mayor;

    // buscar segundo mayor
    for (int i = 0; i < N; i++) {
        if (arr[i] < mayor && arr[i] > segMayor) {
            segMayor = arr[i];
        }
    }

    // buscar segundo menor
    for (int i = 0; i < N; i++) {
        if (arr[i] > menor && arr[i] < segMenor) {
            segMenor = arr[i];
        }
    }
}

// Invertir arreglo
void invertirArreglo(int arr[]) {
    for (int i = 0; i < N / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }
}

int main() {
    int arr[N];
    leerArreglo(arr);

    cout << "Arreglo original: ";
    mostrarArreglo(arr);

    int pares, impares;
    contarParesImpares(arr, pares, impares);
    cout << "Pares: " << pares << ", Impares: " << impares << endl;

    int segMayor, segMenor;
    segundoMayorMenor(arr, segMayor, segMenor);
    cout << "Segundo mayor: " << segMayor << endl;
    cout << "Segundo menor: " << segMenor << endl;

    invertirArreglo(arr);
    cout << "Arreglo invertido: ";
    mostrarArreglo(arr);

    return 0;
}