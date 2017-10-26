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

/* Estructuras para los movimientos  del rey -----------------------------------*/
LISTA *movDiag = NULL,*movDiagdos = NULL, *movDiagInv = NULL, *movDiagInvdos = NULL;
LISTA *movVert = NULL, *movVerta = NULL, *movHori = NULL, *movHoriI = NULL;;

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

/* Movimiento Horizontal derecha del rey -----------------------------------*/
void horizontalDerechaRey(){
	int cont;
	for(cont = x; cont <= 7; cont++) insertar(&movHori, cont, y);
}


/* Movimiento Horizontal izquierda del rey -----------------------------------*/
void horizontalIzquierdaRey(){
	int cont;
	for(cont = x; cont >= 0; cont--) insertar(&movHoriI, cont, y);
}

/* Movimiento Vertical arriba del rey -----------------------------------*/
void verticalArribaRey(){
	int cont;
	for(cont = y; cont <= 7; cont++){
		insertar(&movVert, x, cont);
		
	}
}

/* Movimiento Vertical abajo del rey -----------------------------------*/
void verticalAbajoRey(){
	int cont;
	for(cont = y; cont >= 0; cont--){
		insertar(&movVerta, x, cont);
		
	}
}

/* Movimiento diagonal invertida del rey -----------------------------------*/
void diagonalInvertidaRey(){
	int dif = 0;
	int cont, tempX, tempY, auxY;
	
	auxY = 7 - y;
	if((x + auxY) < 7){
		dif = x;
		tempY = y - dif;
		for(cont = dif; tempY < 7; cont++){
 			tempX = x - dif + cont;
 			tempY = y - dif + cont;
 			insertar(&movDiagInv, tempX, tempY);
		}
		
	 }
	 else{
	 	dif = 7 - x;
	 	tempY = y + dif;
	 	for(cont = dif; tempY > 0; cont++){
 			tempX = x + dif - cont;
 			tempY = y + dif - cont;
 			insertar(&movDiagInv, tempX, tempY);
		}
	 }
	
}
	

/* Movimiento diagonal invertida del rey -----------------------------------*/
void diagonalInvertidaReydos(){
	int dif = 0;
	int cont, tempX, tempY, auxY;
	
	auxY = 7 - y;
	if((x + auxY) < 7){
		dif = x;
		tempY = y - dif;
			for(cont = dif; tempY > 0; cont--){
 			tempX = x - dif + cont;
 			tempY = y - dif + cont;
 			insertar(&movDiagInvdos, tempX, tempY);
		}
		
	 }
	 else{
	 	dif = 7 - x;
	 	tempY = y + dif;
	 			for(cont = dif; tempY < 7; cont--){
 			tempX = x + dif - cont;
 			tempY = y + dif - cont;
 			insertar(&movDiagInvdos, tempX, tempY);
		}
	 }
	
}

/* Movimiento diagonal del rey -----------------------------------*/
void diagonalRey(){
	int dif = 0;
	int cont, tempX, tempY;
	
	if((x + y) < 7){
 		dif = x;
 		tempY = y + dif;
 		for(cont = dif; tempY > 0; cont++){
 			tempX = x - dif + cont;
 			tempY = y + dif - cont;
 			insertar(&movDiag, tempX, tempY);
		 }
	 }
	 else{
	 	dif = 7 - x;
 		tempY = y - dif;
 		for(cont = dif; tempY < 7; cont++){
 			tempX = x + dif - cont;
 			tempY = y - dif + cont;
 			insertar(&movDiag, tempX, tempY);
		}
	 }
}

/* Movimiento diagonal del rey -----------------------------------*/
void diagonalReydos(){
	int dif = 0;
	int cont, tempX, tempY;
	
	if((x + y) < 7){
 		dif = x;
 		tempY = y + dif;
 		for(cont = dif; tempY < 7; cont--){
 			tempX = x - dif + cont;
 			tempY = y + dif - cont;
 			insertar(&movDiagdos, tempX, tempY);
		 }
	 }
	 else{
	 	dif = 7 - x;
 		tempY = y - dif;
 		for(cont = dif; tempY > 0; cont--){
 			tempX = x + dif - cont;
 			tempY = y - dif + cont;
 			insertar(&movDiagdos, tempX, tempY);
		}
	 }
}

void rey(){
	diagonalRey();
	diagonalReydos();
	diagonalInvertidaRey();
	diagonalInvertidaReydos();
	verticalArribaRey();
	verticalAbajoRey();
	horizontalDerechaRey();
	horizontalIzquierdaRey();
}

main(){
	
 	cout <<"\nVamos a obtener los movimientos posibles de la reina de Ajedrez"<< endl;
	cout <<"Cuales son los valores x e y (separados por un espacio '  '): ";
	cin >> x >> y;
 	
 	rey();
 	
 	cout <<"\n\nLa posicion de la reina es: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones es: "<< endl;
	cout <<"Diagonal"<< endl;
	mostrar_lista(movDiagdos);
	mostrar_lista(movDiag);
	cout <<"\n\nDiagonal Invertida"<< endl;
	mostrar_lista(movDiagInv);
	mostrar_lista(movDiagInvdos);
	cout <<"\n\nVertical"<< endl;
	mostrar_lista(movVerta);
	mostrar_lista(movVert);
	
	cout << "\n\nHorizontal"<< endl;
	mostrar_lista(movHoriI);
	mostrar_lista(movHori);
	
}
	
