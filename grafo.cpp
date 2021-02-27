#include "grafo.h"


void Grafo::inicializarMatrices() {

    inicializarMatriz(this->agua, COD_AGUA);
    inicializarMatriz(this->aire, COD_AIRE);
    inicializarMatriz(this->tierra, COD_TIERRA);
    inicializarMatriz(this->fuego, COD_FUEGO);

}


void Grafo::asignarVertice(Casillero* vertice, array<int, 2> posicion) {

    int indice;

    indice = calcularIndice(posicion);

    vertices[indice] = vertice;

}


Personaje* Grafo::obtenerPersonaje(array<int, 2> posicion) {

    int indice;

    indice = calcularIndice(posicion);

    return vertices[indice]->obtenerPersonaje();

}


bool Grafo::estaVacio(array<int,2> posicion) {

    int indice;

    indice = calcularIndice(posicion);

    return vertices[indice]->estaVacio();

}


void Grafo::moverPersonaje(Personaje* personaje, array<int,2> posInicial, array<int,2> posFinal) {

    int indiceFinal;

    indiceFinal = calcularIndice(posFinal);

    if (posInicial != COORD_INVALIDA) {

        int indiceInicial;

        indiceInicial = calcularIndice(posInicial);

        vertices[indiceInicial]->asignarPersonaje(nullptr);

    }

    vertices[indiceFinal]->asignarPersonaje(personaje);

}


void Grafo::mostrar() {



}


Recorrido Grafo::dijkstra(int origen, int destino, int matrizPesos[CANT_VERTICES][CANT_VERTICES]) {

    Recorrido recorridoMin;
    array<int, CANT_VERTICES> pesosMinimos{}, rutaMinima{};
    array<bool, CANT_VERTICES> visitados{};

    for (int i = 0; i < CANT_VERTICES; i++) {

        pesosMinimos[i] = INFINITO;
        rutaMinima[i] = VACIO;
        visitados[i] = false;
    }

    pesosMinimos[origen] = 0;

    for (int i = 0; i < CANT_VERTICES - 1; i++) {

        int posMin = distanciaMinima(pesosMinimos, visitados);
        visitados[posMin] = true;

        for (int j = 0; j < CANT_VERTICES; j++) {

            int minDist = pesosMinimos[posMin] + matrizPesos[posMin][j];

            if (!visitados[j] && pesosMinimos[posMin] != INFINITO && minDist < pesosMinimos[j]) {

                pesosMinimos[j] = minDist;
                rutaMinima[j] = vertices->obtenerPeso(posMin);
            }
        }
    }

    recorridoMin.energiaGastada = pesosMinimos[destino];

    int aux = destino;

    while (aux != origen) {

        recorridoMin.caminoTomado.push_back(aux);
        aux = rutaMinima[aux];
    }

    recorridoMin.caminoTomado.push_back(aux);
    reverse(recorridoMin.caminoTomado.begin(), recorridoMin.caminoTomado.end());

    return recorridoMin;

}


void Grafo::inicializarMatriz(int matrizPesos[CANT_VERTICES][CANT_VERTICES], const string& elemento) {

    rellenarMatriz(matrizPesos);

    for (int i = 0; i < MAX_FILA - 1; i++)

        for (int j = 0; j < MAX_COLUMNA - 1; j++) {

            int pesoActual = vertices[i * MAX_FILA + j]->obtenerCosto(elemento);
            int pesoSiguiente = vertices[i * MAX_FILA + j+1]->obtenerCosto(elemento);

            matrizPesos[i * MAX_FILA + j][j+1] = pesoSiguiente;
            matrizPesos[i * MAX_FILA + j+1][j] = pesoActual;

        }

    for (int i = 0; i < MAX_COLUMNA - 1; i++)

        for (int j = 0; j < MAX_FILA - 1; j++) {

            int pesoActual = vertices[i + j*8]->obtenerCosto(elemento);
            int pesoSiguiente = vertices[i + (j+1)*8]->obtenerCosto(elemento);

            matrizPesos[i*MAX_FILA+j+8][j] = pesoSiguiente;
            matrizPesos[i*MAX_FILA+j][j+8] = pesoActual;

        }

}


void Grafo::rellenarMatriz(int matriz[CANT_VERTICES][CANT_VERTICES]) {

    for (int i = 0; i < CANT_VERTICES; i++)

        for (int j = 0; j < CANT_VERTICES; j++)

            matriz[i][j] = -1;

}


int Grafo::distanciaMinima(array<int,CANT_VERTICES> distancias, array<bool,CANT_VERTICES> visitados) {

    int min = INFINITO;
    int indiceMin = 0;

    for (int i = 0; i < CANT_VERTICES; i++)

        if (!visitados[i] && distancias[i] <= min) {

            min = distancias[i];
            indiceMin = i;
        }


    return indiceMin;

}


int Grafo::calcularIndice(array<int, 2> posicion) {

    int fila, columna, indice;

    fila = posicion[0];
    columna = posicion[1];

    indice = (fila * MAX_FILA) + columna;

    return indice;

}
