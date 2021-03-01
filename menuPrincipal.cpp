#include "menuPrincipal.h"


void MenuPrincipal::iniciar() {

    limpiarPantalla();

    cout << "\n\t\tTrabajo Practico 3\n\n"
            "\tLa batalla de los elementos\n\n"
            " Grupo 3\n\n"
            " Algoritmos y Programacion II - 2C 2020 \n\n\n\n\n"
            " Se procedera a cargar el archivo de personajes.. \n\n" ;

    pausar();

}


void MenuPrincipal::pausar() {

    cout << "\n\n Presione una tecla para continuar..." ;

    cin.get();
    cin.ignore();

    limpiarPantalla();

}


void MenuPrincipal::interfazPrincipal(Juego& juego, DiccionarioABB<string,Personaje*>& diccionario) {

    while (opcion != SALIR) {

        mostrarOpciones();
        pedirOpcion();

        limpiarPantalla();

        switch (opcion) {

            case AGREGAR_PERSONAJE:
                cout << "\n\n\t\t AGREGAR PERSONAJE \n\n\n" ;
                agregarPersonaje(diccionario);
                break;

            case ELIMINAR_PERSONAJE:
                cout << "\n\n\t\t ELIMINAR PERSONAJE \n\n\n" ;
                eliminarPersonaje(diccionario);
                break;

            case MOSTRAR_PERSONAJES:
                cout << "\n\n\t\t MOSTRAR PERSONAJES \n\n\n" ;
                mostrarPersonajes(diccionario);
                break;

            case DETALLE_PERSONAJE:
                cout << "\n\n\t\t DETALLE DEL PERSONAJE \n\n\n" ;
                detallePersonaje(diccionario);
                break;

            case COMENZAR_JUEGO:
                cout << "\n Preparando el juego.."
                        "\n\n\t\t CARGAR PERSONAJES \n\n\n" ;
                cargarPersonajes(juego.obtenerJugador1(), juego.obtenerJugador2(), diccionario);
                if (opcion != SALIR_JUEGO)
                    juego.iniciarPartida();
                opcion = SALIR;
                break;

            case SALIR:
                break;

            default: cout << " Ingreso una opcion invalida" << endl;

        }

        pausar();

    }

    cout << "\n\n El programa ha finalizado\n\n" ;

}


void MenuPrincipal::limpiarPantalla() {

    #ifdef linux
        system("clear");
    #else
        system ("cls");
    #endif

}


void MenuPrincipal::mostrarOpciones() {

    cout << "\n\t\t\tMENU PRINCIPAL\n\n\n"
            " 1) Agregar un nuevo personaje \n"
            " 2) Eliminar un personaje \n"
            " 3) Mostrar todos los nombres de los personajes \n"
            " 4) Buscar por nombre los detalles de un personaje en particular \n"
            " 5) Comenzar juego \n"
            " 6) Salir \n\n\n" ;

}


void MenuPrincipal::pedirOpcion() {

    cout << " Ingrese una opcion: ";
    cin >> opcion;

}


void MenuPrincipal::agregarPersonaje(DiccionarioABB<string,Personaje*>& diccionario) {

    string elemento, nombre;

    mostrarPersonajes(diccionario);

    pedirElemento(elemento);
    validarElemento(elemento);

    pedirNombre(nombre);
    pasarAMinuscula(nombre);

    if ( diccionario.contiene(nombre) )

        cout << "\n\n El personaje '" << nombre << "' ya se encuentra cargado en el diccionario" << endl;

    else {

        Personaje* nuevoPersonaje;

        nuevoPersonaje = crearPersonaje(elemento, nombre);
        diccionario.insertar(nombre, nuevoPersonaje);

        cout << "\n\n Se ha agregado correctamente el personaje";
        nuevoPersonaje->mostrar();

        nuevoPersonaje = nullptr;
        delete nuevoPersonaje;

    }

    cout << endl;

}


void MenuPrincipal::eliminarPersonaje(DiccionarioABB<string,Personaje*>& diccionario) {

    string nombre;

    mostrarPersonajes(diccionario);

    if ( diccionario.estaVacio() )

        cout << "\n No hay personajes para eliminar" ;

    else {

        pedirNombre(nombre);
        pasarAMinuscula(nombre);

        if ( diccionario.contiene(nombre) ) {

            diccionario.eliminar(nombre);
            cout << "\n Se ha eliminado correctamente el personaje '" << nombre << "'";

        }
        else
            cout << "\n El personaje '" << nombre << "' no se encuentra en el diccionario" ;

    }

    cout << "\n\n" ;

}


void MenuPrincipal::mostrarPersonajes(DiccionarioABB<string,Personaje*>& diccionario) {

    if ( diccionario.estaVacio() )

        cout << "\n El diccionario de personajes esta vacio\n\n" << endl;

    else {

        cout << " Diccionario de personajes: " << endl << endl;

        diccionario.imprimirEnOrden();

        cout << endl;

    }

}


void MenuPrincipal::detallePersonaje(DiccionarioABB<string,Personaje*>& diccionario) {

    string nombre;

    mostrarPersonajes(diccionario);

    if ( ! diccionario.estaVacio() ) {

        pedirNombre(nombre);
        pasarAMinuscula(nombre);

        if ( diccionario.contiene(nombre) )

            diccionario.obtenerValor(nombre)->mostrar();

        else
            cout << "\n El personaje '" << nombre << "' no se encuentra en el diccionario" << endl << endl;

    }

    cout << endl;

}


void MenuPrincipal::pedirElemento(string& elemento) {

    cout << "\n Ingrese el elemento (agua, fuego, tierra o aire): " ;
    cin >> elemento;

}


void MenuPrincipal::pedirNombre(string& nombre) {

    cin.ignore();

    cout << "\n Ingrese el nombre del personaje: " ;
    getline(cin, nombre);

}


void MenuPrincipal::validarElemento(string& elemento) {

    pasarAMinuscula(elemento);

    while (elemento != "agua" && elemento != "fuego" && elemento != "tierra" && elemento != "aire" ) {

        cout << "\n Elemento invalido. \n Ingrese el elemento (agua, fuego, tierra o aire): " ;
        cin >> elemento;
        pasarAMinuscula(elemento);

    }

}


void MenuPrincipal::pasarAMinuscula(string& cadena) {

    int j = 0;

    for (char i : cadena) {

        cadena[j] = tolower(i);
        j++;

    }

}


Personaje* MenuPrincipal::crearPersonaje(const string& elemento, const string& nombre) {

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


void MenuPrincipal::cargarPersonajes(Jugador jugador1, Jugador jugador2, DiccionarioABB<string,Personaje*>& diccionario) {

    int numPersonaje = 1;

    while (opcion != SALIR_JUEGO && !jugador1.personajesCargados() && !jugador2.personajesCargados()) {

        if (opcion != SALIR_JUEGO)
            opcion = 0;

        while (opcion != SALIR_JUEGO && opcion != SELECCIONAR_PERSONAJE) {

            cout << " Jugador 1 \n" ;
            menuJuego(jugador1, diccionario, numPersonaje);

            numPersonaje++;
        }

        if (opcion != SALIR_JUEGO)
            opcion = 0;

        while (opcion != SALIR_JUEGO && opcion != SELECCIONAR_PERSONAJE) {

            cout << " Jugador 2 \n" ;
            menuJuego(jugador2, diccionario, numPersonaje);

            numPersonaje++;
        }

    }

}


void MenuPrincipal::menuJuego(Jugador jugador, DiccionarioABB<string,Personaje*>& diccionario, int numPersonaje) {

    mostrarOpcionesJuego();
    pedirOpcion();

    limpiarPantalla();

    switch (opcion) {

        case MOSTRAR_DETALLE:
            cout << "\n\n\t\t DETALLE DEL PERSONAJE \n\n\n" ;
            detallePersonaje(diccionario);
            break;

        case MOSTRAR_TODOS:
            cout << "\n\n\t\t MOSTRAR PERSONAJES \n\n\n" ;
            mostrarPersonajes(diccionario);
            break;

        case SELECCIONAR_PERSONAJE:
            cout << "\n\n\t\t SELECCIONAR PERSONAJE \n\n\n" ;
            seleccionarPersonaje(jugador, diccionario, numPersonaje);
            break;

        case SALIR_JUEGO:
            break;

        default: cout << " Ingreso una opcion invalida" << endl;

    }

    pausar();

}


void MenuPrincipal::mostrarOpcionesJuego() {

    cout << "\n\n\n 1) Buscar por nombre los detalles de un personaje en particular \n"
            " 2) Mostrar todos los nombres de los personajes \n"
            " 3) Seleccionar personaje \n"
            " 4) Salir \n\n\n" ;

}


void MenuPrincipal::seleccionarPersonaje(Jugador jugador, DiccionarioABB<string,Personaje*>& diccionario,
                                         int numPersonaje) {

    string nombre;
    Personaje* nuevoPersonaje;

    mostrarPersonajes(diccionario);

    pedirNombre(nombre);
    pasarAMinuscula(nombre);

    while ( !diccionario.contiene(nombre) ) {

        cout << "\n El personaje '" << nombre << "' no se encuentra en el diccionario, vuelva a ingresarlo" << endl << endl;
        pedirNombre(nombre);
        pasarAMinuscula(nombre);
    }

    nuevoPersonaje = diccionario.obtenerValor(nombre);

    asignarCodigo(nuevoPersonaje, numPersonaje);

    jugador.asignarPersonaje(nuevoPersonaje);
    cout << "\n Se ha agregado correctamente el personaje '" << nombre << "' " ;

    diccionario.eliminar(nombre);

}


void MenuPrincipal::asignarCodigo(Personaje* personaje, int numPersonaje) {

    switch (numPersonaje) {

        case PERSONAJE_1:
            personaje->asignarCodigo('*');
            break;

        case PERSONAJE_2:
            personaje->asignarCodigo('&');
            break;

        case PERSONAJE_3:
            personaje->asignarCodigo('$');
            break;

        case PERSONAJE_4:
            personaje->asignarCodigo('+');
            break;

        case PERSONAJE_5:
            personaje->asignarCodigo('~');
            break;

        case PERSONAJE_6:
            personaje->asignarCodigo('#');
            break;
    }

}

