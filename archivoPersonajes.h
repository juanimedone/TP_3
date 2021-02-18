#ifndef TP_3_ARCHIVOPERSONAJES_H
#define TP_3_ARCHIVOPERSONAJES_H

#include "diccionarioABB.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

class ArchivoPersonajes {

    //atributos
private:
    ifstream archivo;

    //metodos
public:
    // constructor
    // PRE: -
    // POS: abre el archivo con PATH_ARCHIVO
    ArchivoPersonajes();

    // PRE: -
    // POS: devuelve true si se abrio correctamente, false de lo contrario
    bool estaAbierto();

    // PRE: archivo con el formato correspondiente (elemento,nombre,escudo,vida)
    // POS: lee y carga los personajes del archivo en el diccionario
    void procesarArchivo(DiccionarioABB<string, Personaje*>& diccionario);

    // destructor
    // PRE: -
    // POS: cierra el archivo
    ~ArchivoPersonajes();

private:
    // PRE: -
    // POS: reserva espacio para el elemento correspondiente en el heap y lo devuelve como puntero a Personaje
    Personaje* crearPersonaje(const string& elemento, const string& nombre);

};


#endif //TP_3_ARCHIVOPERSONAJES_H
