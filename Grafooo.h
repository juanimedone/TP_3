//
// Created by Nwcore on 23/2/2021.
//

#ifndef UNTITLED1_GRAFO_H
#define UNTITLED1_GRAFO_H
#include<string>


using namespace std;
class Arista;

class Vertice{
    Vertice *siguiente;
    Arista *adyacente;
    string nombre;
    friend class Grafo;
};

class Arista{
    Arista *siguiente;
    Vertice *adyacente;
    int costo;
    friend class Grafo;
};

class Grafo{
    Vertice *h;
public:
    void Inicializa();
    bool Vacio();
    int Tamaño();
    Vertice *ObtenerVertice(string nombre);
    void InsertaArista(Vertice *origen, Vertice *destino, int costo);
    void InsertaVertice(string nombre);
    void ListaAdyacencia();
    void EliminarArista(Vertice *origen, Vertice *destino);
    void Anular();
};



#endif //UNTITLED1_GRAFO_H
