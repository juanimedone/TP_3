#include "grafo.h"


void Grafo::inicializarMatrices() {

    inicializarMatriz(agua, COD_AGUA);
    inicializarMatriz(aire, COD_AIRE);
    inicializarMatriz(tierra, COD_TIERRA);
    inicializarMatriz(fuego, COD_FUEGO);

}


void Grafo::asignarVertice(Casillero* vertice, array<int,2> posicion) {

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

    if (posInicial != COORD_INVALIDA)

        eliminarPersonaje(posInicial);


    vertices[indiceFinal]->asignarPersonaje(personaje);

}


void Grafo::eliminarPersonaje(array<int,2> posicion) {

    int indice = calcularIndice(posicion);

    vertices[indice]->asignarPersonaje(nullptr);

}


void Grafo::mostrar() {



}


Recorrido Grafo::caminoMinimo(array<int,2> posInicial, array<int,2> posFinal, string elemento) {

    int indiceInicial, indiceFinal;
    Recorrido recorridoMin;

    indiceInicial = calcularIndice(posInicial);
    indiceFinal = calcularIndice(posFinal);

    if (elemento == COD_AGUA)
        recorridoMin = dijkstra(indiceInicial, indiceFinal, agua);

    else if (elemento == COD_TIERRA)
        recorridoMin = dijkstra(indiceInicial, indiceFinal, tierra);

    else if (elemento == COD_FUEGO)
        recorridoMin = dijkstra(indiceInicial, indiceFinal, fuego);

    else
        recorridoMin = dijkstra(indiceInicial, indiceFinal, aire);

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

            matriz[i][j] = INFINITO;

}


Recorrido Grafo::dijkstra(int origen, int destino, int matrizPesos[CANT_VERTICES][CANT_VERTICES]) {

    Recorrido recorridoMin;
    array<int,CANT_VERTICES> pesosMinimos{}, rutaMinima{};
    array<bool,CANT_VERTICES> visitados{};

    inicializarVectores(pesosMinimos, rutaMinima, visitados);

    pesosMinimos[origen] = 0;

    for (int i = 0; i < CANT_VERTICES - 1; i++) {

        int posMin = buscarPesoMinimo(pesosMinimos, visitados);
        visitados[posMin] = true;

        for (int j = 0; j < CANT_VERTICES; j++) {

            int minDist = pesosMinimos[posMin] + matrizPesos[posMin][j];

            if ( !visitados[j] && pesosMinimos[posMin] != INFINITO && minDist < pesosMinimos[j] ) {

                pesosMinimos[j] = minDist;
                rutaMinima[j] = posMin;
            }
        }
    }

    recorridoMin.asignarEnergiaGastada(pesosMinimos[destino]);

    int aux = destino;

    while (aux != origen) {

        recorridoMin.agregarPosicion(aux);
        aux = rutaMinima[aux];
    }

    recorridoMin.agregarPosicion(aux);
    
    return recorridoMin;

}


void Grafo::inicializarVectores(array<int,CANT_VERTICES>& pesosMinimos, array<int,CANT_VERTICES>& rutaMinima,
                                array<bool,CANT_VERTICES>& visitados) {

    for (int i = 0; i < CANT_VERTICES; i++) {

        pesosMinimos[i] = INFINITO;
        rutaMinima[i] = VACIO;
        visitados[i] = false;
    }

}


int Grafo::buscarPesoMinimo(array<int,CANT_VERTICES> pesosMinimos, array<bool,CANT_VERTICES> visitados) {

    int min = INFINITO;
    int indiceMin = 0;

    for (int i = 0; i < CANT_VERTICES; i++)

        if ( !visitados[i] && pesosMinimos[i] <= min ) {

            min = pesosMinimos[i];
            indiceMin = i;
        }


    return indiceMin;

}


int Grafo::calcularIndice(array<int,2> posicion) {

    int fila, columna, indice;

    fila = posicion[0];
    columna = posicion[1];

    indice = (fila * MAX_FILA) + columna;

    return indice;

}
