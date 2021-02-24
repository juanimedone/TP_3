//
// Created by Nwcore on 23/2/2021.
//
#include<iostream>
#include "Grafooo.h"

using namespace std;

void Grafo::Inicializa(){
    h = NULL;
}
bool Grafo::Vacio() {
    if(h == NULL){
        return true;
    }
    return false;
}

int Grafo::Tamaño() {

    int cont = 0;
    Vertice *aux;
    aux = h;
    while (aux == NULL){

        cont ++;
        aux = aux->siguiente;
    }
    return cont;
}

Vertice *Grafo::ObtenerVertice(string nombre) {
    Vertice *aux;
    aux = h;
    while(aux != NULL){
        if(aux->nombre == nombre){
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

void Grafo::InsertaVertice(string nombre) {
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->siguiente = NULL;
    nuevo->adyacente = NULL;
    if(Vacio()){
        h = nuevo;
    } else {
        Vertice *aux;
        aux = h;
        while(aux->siguiente == NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int costo) {

    Arista *nueva = new Arista;
    nueva->costo = costo;
    nueva->siguiente = NULL;
    nueva->adyacente = NULL;

    Arista *aux;
    aux = origen->adyacente;
    if(aux == NULL){
       origen->adyacente = nueva;
       nueva->adyacente = destino;
    } else {
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nueva;
        nueva->adyacente = destino;
    }
}

void Grafo::ListaAdyacencia() {
    Vertice *VertAux;
    Arista *ArisAux;

    VertAux = h;
    while(VertAux != NULL) {
        cout<<VertAux->nombre<< "->";
        ArisAux = VertAux->adyacente;
        while (ArisAux != NULL) {
            cout<< ArisAux->adyacente->nombre<<"->";
            ArisAux = ArisAux->siguiente;
        }
        VertAux = VertAux->siguiente;
        cout<<endl;
    }
}

void Grafo::Anular() {

    Vertice *aux;
    while(h != NULL){
        aux = h;
        h = h->siguiente;
        delete(aux);
    }
}

void Grafo::EliminarArista(Vertice *origen, Vertice *destino) {
    Arista *actual, *anterior;
    actual = origen->adyacente;

    if(actual == NULL){
        cout<<"El vertice Origen no tiene Arista"<<endl;
    } else if(actual->adyacente == destino) {
        origen->adyacente = actual->siguiente;
        delete(actual);
    } else {
        while(actual->adyacente != destino){
            anterior = actual;
            actual = actual->siguiente;
        }
        anterior->siguiente = actual->siguiente;
        delete(actual);
    }
}








