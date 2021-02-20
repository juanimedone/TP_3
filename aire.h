#ifndef TP_3_AIRE_H
#define TP_3_AIRE_H

#include "personaje.h"

class Aire: public Personaje {

    // metodos
public:
    // constructor
    // PRE: -
    // POS: crea un personaje de aire con el nombre ingresado por el usuario y el resto de atributos aleatorios
    Aire(string nombre) : Personaje(nombre) {};

    // PRE: -
    // POS: suma 5 puntos de energia
    void energiaPorTurno();

    // PRE: -
    // POS: devuelve COD_AIRE
    string obtenerElemento() override;

    // PRE: -
    // POS: muestra el elemento y los atributos del personaje
    void mostrar() override;

    // PRE: -
    // POS: imprime un mensaje por pantalla
    void alimentar() override;

    // PRE: el arreglo enemigos esta lleno
    // POS: si tiene 8 energia o mas, reduce la vida de todos los personajes en enemigos por un valor dependiendo de su elemento.
    //      por 20 puntos a los personajes de tierra, por 10 a los de fuego, 15 a los demas.
    void atacar(array<Personaje*, 3> enemigos) override;

    // PRE: -
    // POS: si tiene 15 energia o mas, se posiciona al personaje en las coordenadas ingresadas por el usuario.
    //      de ser invalidas las coordenadas o no tener energia suficiente, se imprime un mensaje
    void defender(array<Personaje*, 3> aliados) override;

    // PRE: -
    // POS:
    int calcularAtkEntrante(Personaje* enemigo) override;

private:
    // PRE: -
    // POS: devuelve una coordenada valida ingresada por el usuario, o COORD_INVALIDA en caso de un ingreso invalido
    //      (si el usuario ingresa no enteros, o enteros mayores a 8/menores a 0)
    array<int,2> pedirPosicionDefensa();

};


#endif //TP_3_AIRE_H
