/* Movimientos de la Reina de Ajedrez */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int x = 0, y = 0;

/* Las estructuras que almacenan los estados y la de control -------------------------------------------*/
typedef struct nodo{
 int n;
 int m;
 struct nodo *sig;
} LISTA;

/* Estructuras para los movimientos  de la reina -----------------------------------*/
LISTA *movDer = NULL, *movIzq = NULL;
LISTA *movArr = NULL, *movAba = NULL;

/*Agrega elementos a la lista de posiciones -------------------------*/
void insertar(LISTA **ptr, int elemento1, int elemento2){
LISTA *p1, *p2;
p1 = *ptr;


if(p1 == NULL){
	p1 = new(LISTA);
	if (p1 != NULL){
		p1->n = elemento1;
		p1->m = elemento2;
		p1->sig = NULL;
		*ptr = p1;
	}
}
else{
	while(p1->sig != NULL)
		p1 = p1->sig;
		p2 = new(LISTA);
		if(p2 != NULL){
			p2->n = elemento1;
			p2->m = elemento2;
			p2->sig = NULL;
			p1->sig = p2;
		}
	}
}

/* Muestra los valorees de las posiciones -----------------------------------------------------*/
void mostrar_lista(LISTA *ptr){
	while(ptr != NULL){
		    cout<<"("<<ptr->n<<","<<ptr->m<<") -";
            ptr = ptr->sig;
        }
}

/* Movimiento Derecha-Arriba del Caballo -----------------------------------*/
DerechaArribaCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x+k)<8 && (y+1)<8)
        {
            insertar(&movDer, x+k, y+1);
        }
    }

}

/* Movimiento Derecha-Abajo del Caballo -----------------------------------*/
DerechaAbajoCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
       if((y-1)>=0 && (x+k)<8)
       {
           insertar(&movDer, x+k, y-1);
       }
    }
}

/* Movimiento Izquierda-Arriba del Caballo -----------------------------------*/
IzqAbrribaCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x-k)>=0 && (y+1)<8)
        {
            insertar(&movIzq, x-k, y+1);
        }

    }
}

/* Movimiento Izquierda-Abajo del Caballo -----------------------------------*/
IzqAbajoCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x-k>=0 && (y-1)>=0))
        {
            insertar(&movIzq, x-k, y-1);
        }
    }
}

/* Movimiento Arriba-Izquierda del Caballo -----------------------------------*/
AbrribaIzqCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x-1)>=0 && (y+k)<8)
        {
            insertar(&movArr, x-1, k+y);
        }
    }
}

/* Movimiento Abajo-Izquierda del Caballo -----------------------------------*/
AbajoIzqCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x-1)>=0 && (y-k)>=0)
        {
            insertar(&movAba, x-1, y-k);
        }
    }
}

/* Movimiento Arriba-Derecha del Caballo -----------------------------------*/
AbrribaDerCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((x+1)<8 && (y+k)<8)
        {
            insertar(&movArr, x+1, k+y);
        }
    }
}

/* Movimiento Abajo-Derecha del Caballo -----------------------------------*/
AbajoDerCaballo(){
	int k=0;
	while(k!=2)
    {
        k++;
    }

    if(k==2)
    {
        if((y-k)>=0 && (x+1)<8)
        {
            insertar(&movAba, x+1, y-k);
        }
    }
}

Caballo(){
	DerechaArribaCaballo();
	DerechaAbajoCaballo();
    IzqAbrribaCaballo();
    IzqAbajoCaballo();
    AbrribaIzqCaballo();
    AbajoIzqCaballo();
    AbrribaDerCaballo();
    AbajoDerCaballo();
}

main(){

 	cout <<"\nVamos a obtener los movimientos posibles del Caballo de Ajedrez"<< endl;
	cout <<"Cuales son los valores x e y (separados por un espacio '  '): ";
	cin >> x >> y;

 	Caballo();

 	cout <<"\n\nLa posicion del Caballo es: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones es: "<< endl;
	cout <<"Arriba"<< endl;
	mostrar_lista(movArr);
	cout <<"\n\nAbajo"<< endl;
	mostrar_lista(movAba);
	cout <<"\n\nIzquierda"<< endl;
	mostrar_lista(movIzq);
	cout << "\n\nHDerecha"<< endl;
	mostrar_lista(movDer);
}
