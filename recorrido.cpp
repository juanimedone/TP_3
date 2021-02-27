#include "recorrido.h"

void Recorrido::mostrar() {

    cout << "\n\n Energia gastada: " << energiaMinima <<
            "\n\n Recorrido: \n" ;

    posiciones.imprimir();

}
