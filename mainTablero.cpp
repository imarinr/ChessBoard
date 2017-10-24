#include <stdio.h>
#include <stdlib.h>
#include "Tablero.h"

int main(){

    int i,j;
    int tam;

    // Alfil
    int ejAlfilRenglon[15]={3,  0,1,2,4,5,6,   7,6,5,4,2,1,0};
    int ejAlfilColumna[15]={4,  1,2,3,5,6,7,   0,1,2,3,5,6,7};

    // Torre
    int ejTorreRenglon[15]={3,  0,1,2,4,5,6,7,  3,3,3,3,3,3,3};
    int ejTorreColumna[15]={4,  4,4,4,4,4,4,4,  0,1,2,3,5,6,7};

    // Ejemplo de como usar el tablero. Agregaremos una dama, veremos donde se puede mover, 
    // La moveremos.

    // 1.- Iniciamos el juego
    Tablero tablero;
    tablero.iniciaTablas(); // Se inicializan el tablero y tabla temporal en ceros.

    printf("Iniciamos a jugar! Estado actual del tablero:\n");
    tablero.imprimeTabla();


    // 2.- Es necesario tener las coordenadas donde puede avanzar la dama para ver movimientos posibles
    printf("\nPosiciones de una dama");
    int ejDamaRenglon[28]={3,  0,1,2,4,5,6,7,  3,3,3,3,3,3,3,  0,1,2,4,5,6,   7,6,5,4,2,1,0};
    int ejDamaColumna[28]={4,  4,4,4,4,4,4,4,  0,1,2,3,5,6,7,  1,2,3,5,6,7,   0,1,2,3,5,6,7};

    // 3.- Obtenemos el numero de coordenadas a mostrar (dimension del array anterior)
    tam = sizeof(ejDamaRenglon)/sizeof(*ejDamaRenglon);

    // 4.- Llamamos al metodo pintaMovimientosPosibles, recibe los array, su tamanio y el tipo de pieza.
    //     Esto imprimira los movimientos posibles.
    tablero.pintaMovimientosPosibles(ejDamaColumna,ejDamaRenglon, tam, 'D');


    // 5.- Agregando una pieza
    printf("Agregando una dama");
    tablero.muevePieza(-1, -1, 0, 0, 'D');
    tablero.imprimeTabla();

    // 6.- Moviendo la pieza
    printf("Moviendo a una dama");
    tablero.muevePieza(0, 0, 3, 3, 'D');
    tablero.imprimeTabla();


    return 0;
}
