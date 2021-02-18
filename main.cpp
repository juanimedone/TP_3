#include "archivoPersonajes.h"
#include "menuPrincipal.h"


int main() {

    ArchivoPersonajes archivoPersonajes;
    DiccionarioABB<string, Personaje*> diccionario;
    MenuPrincipal menuPrincipal;
    Juego juego;

    menuPrincipal.iniciar();

    if (archivoPersonajes.estaAbierto()) {

        archivoPersonajes.procesarArchivo(diccionario);
        cout << "\n El archivo de personajes se ha cargado correctamente" << endl;
    }
    else
        cout << "\n Error al abrir el archivo de personajes" << endl;

    menuPrincipal.pausar();

    menuPrincipal.interfazPrincipal(juego, diccionario);


    return 0;
}
