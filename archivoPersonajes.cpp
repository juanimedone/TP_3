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

        nuevoPersonaje = crearPersonaje(elemento, nombre, escudo, vida);
        diccionario.insertar(nombre, nuevoPersonaje);

    }

    nuevoPersonaje = nullptr;
    delete nuevoPersonaje;

}


ArchivoPersonajes::~ArchivoPersonajes() {

    archivo.close();

}


Personaje* ArchivoPersonajes::crearPersonaje(const string& elemento, const string& nombre, const string& escudo, const string& vida) {

    Personaje* nuevoPersonaje;

    if (elemento == COD_AGUA)
        nuevoPersonaje = new Agua(nombre);

    else if (elemento == COD_FUEGO)
        nuevoPersonaje = new Fuego(nombre);

    else if (elemento == COD_TIERRA)
        nuevoPersonaje = new Tierra(nombre);

    else
        nuevoPersonaje = new Aire(nombre);

    nuevoPersonaje->asignarEscudo( (short) stoi(escudo) );
    nuevoPersonaje->asignarVida( stoi(vida) );

    return nuevoPersonaje;

}
