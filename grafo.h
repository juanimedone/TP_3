#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "casillero.h"
#include "recorrido.h"

class Grafo {

    // atributos
private:
    int agua[CANT_VERTICES][CANT_VERTICES];                      // matrices de costos
    int aire[CANT_VERTICES][CANT_VERTICES];
    int fuego[CANT_VERTICES][CANT_VERTICES];
    int tierra[CANT_VERTICES][CANT_VERTICES];
    array<Casillero*,CANT_VERTICES> vertices;

    // metodos
public:
    // PRE: -
    // POS: carga las 4 matrices de adyacencias con los pesos (una por cada elemento)
    void inicializarMatrices();

    // PRE: la posicion debe ser valida
    // POS: asigna el nuevo casillero a su posicion correspondiente en el vector de vertices
    void asignarVertice(Casillero* vertice, array<int,2> posicion);

    // PRE: -
    // POS: devuelve el personaje que se encuentra en tal posicion del tablero
    Personaje* obtenerPersonaje(array<int,2> posicion);

    // PRE: -
    // POS: devuelve true si no hay ningun personaje en tal posicion del tablero
    bool estaVacio(array<int,2> posicion);

    // PRE: -
    // POS: mueve el personaje de posInicial a posFinal en el tablero
    void moverPersonaje(Personaje* personaje, array<int,2> posInicial, array<int,2> posFinal);

    // PRE: -
    // POS: asigna nullptr como personaje al casillero con la posicion correspondiente
    void eliminarPersonaje(array<int,2> posicion);

    // PRE: -
    // POS: imprime por pantalla el tablero
    void mostrar();

    // PRE: -
    // POS: devuelve el camino minimo que corresponda segun el elemento del personaje
    Recorrido caminoMinimo(array<int,2> posInicial, array<int,2> posFinal, string elemento);

private:
    // PRE: -
    // POS: carga la matriz de adyacencias con los pesos correspondientes segun el elemento
    void inicializarMatriz(int matrizPesos[CANT_VERTICES][CANT_VERTICES], const string& elemento);

    // PRE: -
    // POS: llena la matriz con valores invalidos
    void rellenarMatriz(int matriz[CANT_VERTICES][CANT_VERTICES]);

    // PRE: -
    // POS: calcula y devuelve el camino minimo para ir desde el origen hasta el destino
    Recorrido dijkstra(int origen, int destino, int matrizPesos[CANT_VERTICES][CANT_VERTICES]);

    // PRE: -
    // POS: da los valores iniciales a los vectores para poder hacer el dijkstra
    void inicializarVectores(array<int,CANT_VERTICES>& pesosMinimos, array<int,CANT_VERTICES>& rutaMinima,
                             array<bool,CANT_VERTICES>& visitados);

    // PRE: -
    // POS: devuelve el indice del array en el cual se encuentra el menor peso no visitado hasta el momento
    int buscarPesoMinimo(array<int,CANT_VERTICES> pesosMinimos, array<bool,CANT_VERTICES> visitados);

    // PRE: -
    // POS: devuelve el indice del vector (numero de casillero) correspondiente a una posicion
    int calcularIndice(array<int,2> posicion);

};


#endif //TP_3_GRAFO_H
