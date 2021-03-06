#ifndef TABLERO_H
#define TABLERO_
#include "Piezas/Alfil.cpp"

class Tablero{
    public:
        int tabla[8][8];
        int tablaTempo[8][8];
         Tablero() {
            int tabla[8][8];
            int tablaTempo[8][8];
        }
        void iniciaTablas();
        void imprimeTabla ();
        void pintaMovimientosPosibles(int *X, int *Y, int tam, char pieza);
        bool isInCoord(int i, int j, int *coordR, int *coordC, int tam);
        void muevePieza(int beforeX, int beforeY, int afterX, int afterY, char pieza);
        bool movimientoValido(int beforeX, int beforeY, int afterX, int afterY, char pieza);
};


/* Inicializa el tablero y el tablero temporal */
void Tablero::iniciaTablas(){
    int i,j;
    for (i=0;i<8;i++)
        for(j=0;j<8;j++)
            tabla[i][j]=0;
    

    for (i=0;i<8;i++)
        for(j=0;j<8;j++)
            tablaTempo[i][j]=0;
}

/* Imprime el estado actual del tablero */
void Tablero::imprimeTabla (){
    int i, j;
    printf("\n\n");

    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            printf("%i\t", tabla[i][j]);
        }
        printf("\n");
        puts("");
    }
}

/* Muestra los movimientos posibles dada una pieza. La muestra en tabla temporal, y no modifica
el estado de la tabla. Imprime la tabla temporal. El numero corresponde a:
    Rey     1
    Dama    2
    Alfil   3
    Caballo 4
    Torre   5
    Peon    6
*/
void Tablero::pintaMovimientosPosibles(int col[], int fila[], int tam, char pieza){
    int i, j;
    printf("\n\n");

    // Sea el tamanio del array a pintar (col o fila), se pinta la coordenada en la tabla.
    for (i=0;i<tam;i++)
            switch(pieza){
                case 'R'://rey
                case 'r':
                    tablaTempo[fila[i]][col[i]]=1;
                    break;                    
                case 'D'://dama
                case 'd':
                    tablaTempo[fila[i]][col[i]]=2;
                    break;
                case 'A'://alfil
                case 'a':
                    tablaTempo[fila[i]][col[i]]=3;
                    break;
                case 'C'://caballo
                case 'c':
                    tablaTempo[fila[i]][col[i]]=4;
                    break;
                case 'T'://torre
                case 't':    
                    tablaTempo[fila[i]][col[i]]=5;
                    break;
                case 'P'://peon
                case 'p':
                    tablaTempo[fila[i]][col[i]]=6;
            }

    // Imprime movimientos posibles
    printf("\n\n");
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            printf("%i\t", tablaTempo[i][j]);
        }
        printf("\n");
        puts("");
    }

}

void Tablero::muevePieza(int beforeX, int beforeY, int afterX, int afterY, char pieza){
    // Vacia la casilla donde se encontraba la pieza 
    // Si las coordenadas anteriores son negativas, significa que la pieza es nueva
    // y apenas se esta agregando al tablero.

    // Solo si es un movimiento valido, movera la pieza
    if(Tablero::movimientoValido(beforeX, beforeY, afterX, afterY, pieza)){
        if(!(beforeX == -1) && !(beforeY == -1)){
            tabla[beforeX][beforeY]=0; 
        }   

        // Asigna la pieza a su nueva posicion
        switch(pieza){
            case 'R'://rey
            case 'r':
                tabla[afterX][afterY]=1;
                break;                    
            case 'D'://dama
            case 'd':
                tabla[afterX][afterY]=2;
                break;
            case 'A'://alfil
            case 'a':
                tabla[afterX][afterY]=3;
                break;
            case 'C'://caballo
            case 'c':
                tabla[afterX][afterY]=4;
                break;
            case 'T'://torre
            case 't':    
                tabla[afterX][afterY]=5;
                break;
            case 'P'://peon
            case 'p':
                tablaTempo[afterX][afterY]=6;
        }
    }
}

bool Tablero::isInCoord(int i, int j, int coordR[], int coordC[], int tam){
    for(int pos = 0; pos < tam; pos++){
        if( (j == coordR[pos]) && ( i == coordC[pos])){
            return true;
        }
    }

    return false;
}

/* Aqui se realizan las reglas caracteristicas de cada pieza, para saber si el nuevo movimiento es permitido */
bool Tablero::movimientoValido(int beforeX, int beforeY, int afterX, int afterY, char pieza){
    switch(pieza){
        case 'R'://rey
        case 'r':
            return true;
            break;                    
        case 'D'://dama
        case 'd':
            return true;
            break;
        case 'A'://alfil
        case 'a':
            return true;
            break;
        case 'C'://caballo
        case 'c':
            return true;
            break;
        case 'T'://torre
        case 't':   
            return true; 
            break;
        case 'P'://peon
        case 'p':
            return true;
    }
    return false;
}

#endif // TABLERO_H
