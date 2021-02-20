#ifndef TP_3_GRAFO_H
#define TP_3_GRAFO_H


class Grafo {

    // atributos
private:
    Matriz<int>* agua, *aire, *fuego, *tierra;     // matrices de costos
    Casillero* vertices[MAX_FILA][MAX_COLUMNA];

    // metodos
public:
    Recorrido dijkstra(array<int,2> origen, array<int,2> destino);

};


#endif //TP_3_GRAFO_H
