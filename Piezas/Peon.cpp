/* Movimientos del Peón de Ajedrez */
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

/* Estructuras para los movimientos  del peón -----------------------------------*/
LISTA *movVert = NULL;

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
	
		ptr = ptr->sig;
		cout<<"("<<ptr->n<<","<<ptr->m<<") - ";	
	
}

/* Movimiento Vertical del peon -----------------------------------*/
void verticalpeon(){
	
int cont;
for(cont = y; cont <= 7; cont++){
		insertar(&movVert, x, cont);
									}

}
void peon(){
	verticalpeon();
	
}

main(){
	
 	cout <<"\nVamos a obtener los movimientos posibles del peon de Ajedrez"<< endl;
	cout <<"Cuales son los valores x e y (separados por un espacio '  '): ";
	cin >> x >> y;
 	if (y <= 7){
 		peon();
		cout <<"\n\nLa posicion del peon es: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones (le recordamos que el peon solo se mueve un espacio en vertical): "<< endl;
	mostrar_lista(movVert);

}
else{
	cout <<"\nNo es posible poner el peon en ese espacio"<< endl;
	}
	
}	
