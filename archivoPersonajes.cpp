#include "archivoPersonajes.h"

ArchivoPersonajes::ArchivoPersonajes() {

    archivo.open(PATH_ARCHIVO_PERSONAJES);

}


bool ArchivoPersonajes::estaAbierto() {

    return archivo.is_open();

}


void ArchivoPersonajes::procesarArchivo(DiccionarioABB<string, Personaje*>& diccionario) {

    Personaje* nuevoPersonaje;
    string elemento, nombre, escudo, vida;

    while ( getline(archivo, elemento, ',' ) ) {

        getline(archivo, nombre, ',');
        getline(archivo, escudo, ',');
        getline(archivo, vida);

        nuevoPersonaje = crearPersonaje(elemento, nombre);

        nuevoPersonaje->asignarEscudo( (short) stoi(escudo) );
        nuevoPersonaje->asignarVida( stoi(vida) );

        diccionario.insertar(nombre, nuevoPersonaje);

    }

    nuevoPersonaje = nullptr;
    delete nuevoPersonaje;

}


ArchivoPersonajes::~ArchivoPersonajes() {

    archivo.close();

}


Personaje* ArchivoPersonajes::crearPersonaje(const string& elemento, const string& nombre) {

    Personaje* nuevo;

    if (elemento == "agua")
        nuevo = new Agua(nombre);

    else if (elemento == "fuego")
        nuevo = new Fuego(nombre);

    else if (elemento == "tierra")
        nuevo = new Tierra(nombre);

    else
        nuevo = new Aire(nombre);


    return nuevo;

}
