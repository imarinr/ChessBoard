/**
* ochoReinas_Ivan_Marin.cpp
*/
#include <iostream>
#include <list>
using namespace std;

bool comprobacionCruz(int tablero[]) {
	bool result;
	int val;
	for (int i = 0; i < 8; ++i) {
		val = tablero[i];
		for (int j = 1; j < 8; ++j)
		{
			if(i == j) {
				++j;
			}
			result = tablero[j] == val;
			if(result) {
				return !result;
			}
		}
	}
	return result;
}

bool comprobacionEquis(int tablero[]) {
	bool result;
	for (int i = 0; i < 7; ++i) {
		if((tablero[i] + 1) != tablero[i+1]){
			result = true;
		} else {
			result = false;
		}
	}
	return result;
}
bool esIgualAlInicial(int tableroInicial[], int tableroActual[]){
	for (int i = 0; i < 8; ++i) {
		if (tableroActual[i] == tableroInicial[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int tablero[8] = {0,0,0,0,0,0,0,0};
	int i = 1;
	int j = 1;
        int tableroInicial[8] = {0,0,0,0,0,0,0,0};
	do {
		if (comprobacionCruz(tablero) && comprobacionEquis(tablero) == true) {
			for (int i = 0; i < 8; ++i)
			{
				cout << tablero[i];
			}
		}
		tablero[i] = j;
		i++;
		j++;
		if(i == 7) { i = 0; }
		if(j == 7) { j = 1; }

	} while (!esIgualAlInicial(tableroInicial, tablero));
	return 0;
}