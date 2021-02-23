#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H

#include "matriz.h"
#include "casillero.h"

class Grafo {

    // atributos
private:
    Matriz<int>* agua, *aire, *fuego, *tierra;     // matrices de costos
    Casillero* vertices[MAX_FILA][MAX_COLUMNA];

    // metodos
public:
    // PRE:
    // POS:
    Recorrido dijkstra(array<int,2> origen, array<int,2> destino);

    // PRE:
    // POS:
    void posicionarPersonaje(Personaje* personaje, array<int,2> posicion);

};


#endif //TP_3_GRAFO_H
