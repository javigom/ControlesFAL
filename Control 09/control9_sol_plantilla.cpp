/*
N� Grupo: D03

Nombre y apellidos de los miembros del grupo:
	JAVIER G�MEZ MORALEDA
	MARIO ALCOLEA ALCOLEA
*/

#define DOM_JUDGE

#include <iostream>

#ifdef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;


/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

	En un primer intento de resolver el algoritmo devolviendo un entero, nos ha sido imposible hallar el resultado ya que necesit�bamos m�s par�metros.
	Por lo tanto, hemos decidido crear un struct, en el que, a parte de la longitud, tengamos el n�mero al que corresponde dicha longitud, un valor
	m�nimo que corresponde con el primer elemento de la "subcadena" y un valor m�ximo que corresponde con el �ltimo, debido a que el array est� ordenado.
	De esta forma, podremos determinar si la longitud se encuentra al principio, en medio o al final de dicha subcadena y operar en consecuencia.

	Par�metros de entrada:
		- a[]: array con los elementos
		- inicio: posicion inicial de la subcadena
		- final: posicion final de la subcadena

(2) An�lisis de casos

	 (2.1) Caso(s) base

	 - Si n = 1, no llamo a la generalizaci�n ya que la longitud de un array con un �ncio elemento es uno
	 - En otro caso, llamo a la generalizaci�n:
		- Dentro de la generalizaci�n, mi caso base se dar� cuando inicio = fin, es decir, que la subcadena tenga un �nico elemento
		En este caso, devolver� longitud 1, numero = a [inicio] (valor del �nico elemento) y lo mismo con el maximo y minimo.
	
	 (2.2) Caso(s) recursivos

	 - Si inicio es distinto a fin, haremos dos llamadas recursivas "dividiendo" el array en dos.
		- La primera ir� desde inicio a mitad
		- La segunda ir� desde mitad + 1 a fin


(3) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
	a partir de la misma, por inmersi�n.

	Una vez hemos salido del caso base de la generalizacion, "uniremos" las dos subcadenas para devolver un struct con la longitud mas larga, actualizando
	el n�mero que aparece en dicha longitud y el valor m�nimo y m�ximo.
	El struct devuelto siempre ser�, por defecto, res1

	1. Si el �ltimo elemento (m�ximo) de la primera subcadena coincide con el primero de la segunda (m�nimo):
		
		- Si coincide que el n�mero de la cadena mas larga del primero coincide con el m�ximo y la cadena m�s larga del segundo coincide con el m�nimo, 
		quiere decir que debemos unir las dos longitudes, ya que la cadena m�s larga de estas subcadenas estaban divididas. Bastar�a con actualizar la longitud
		del primero, que es el que devolvemos.

		- Si coincide el n�mero de la cadena m�s larga del primero con el m�ximo, es que se encuentra al final, por lo tanto tendremos que ver si existe
		alg�n otro valor igual que este n�mero en la otra parte del array. Nos situaremos con el indice en mitad + 1 e iremos recorriendo el array hacia
		delante hasta que el valor sea distinto.

		- Si coincide el n�mero de la cadena m�s larga del segundo con el m�nimo, es que se encuentra al principio, por lo tanto tendremos que ver si existe
		alg�n otro valor igual que este n�mero en la otra parte del array. Nos situaremos con el indice en mitad e iremos recorriendo el array hacia atr�s
		hasta que el valor sea distinto.

		- Por �ltimo, si no se cumple ninguna condici�n, ninguna longitud tiene sus elementos al final en el caso del primero, o al principio en el caso
		del segundo. Tendr�amos que comprobar si existe alguna subcadena por el medio que pueda ser mayor de las que ya tengo. Para ello hago uso de una variable
		local aux, que nos servir� para almacenar ese resultado.
		Puesto que el maximo del primero y el m�nimo del segundo son iguales, como m�nimo existir� una cadena de longitud 2. Como se ha descrito antes, con dos
		bucles while recorreremos esos elementos hasta que sean distintos, hacia atr�s en el caso del primero y hacia delante en el segundo.
		Si al final aux es mayor que las dos longitudes que ten�a, actualizare la longitud de res1.

	2. Si no coinciden, significa que no puede existir una longitud mayor entre los dos resultados.

	En todos los casos comparo si la longitud del primer resultado es menor que la del segundo, y si se cumple, actualizo la longitud y el numero de res1,
	ya que es la que voy a devolver.

	En todos los casos asigno el valor maximo de res2 a res1, ya que ahora el resultado devuelto es la "suma" de ambos.

*/

typedef struct resultado {
	int longitud;
	int numero;
	int maximo;
	int minimo;
};

resultado mayorLongitud(int a[], int inicio, int fin) {

	resultado res1, res2;
	int mitad, i, aux;

	if (fin == inicio) {
		res1.longitud = (fin - inicio) + 1;
		res1.numero = a[inicio];
		res1.maximo = a[inicio];
		res1.minimo = a[inicio];
	}

	else {
		mitad = (inicio + fin) / 2;
		res1 = mayorLongitud(a, inicio, mitad);
		res2 = mayorLongitud(a, mitad + 1, fin);


		if (res1.maximo == res2.minimo) {
			if (res1.maximo == res1.numero && res2.minimo == res2.numero) {
				res1.longitud = res1.longitud + res2.longitud;
			}

			else if (res1.maximo == res1.numero) {
				i = mitad + 1;
				while (a[i] == res1.numero) {
					res1.longitud++;
					i++;
				}
			}

			else if (res2.minimo == res2.numero) {
				i = mitad;
				while (a[i] == res2.numero) {
					res2.longitud++;
					i--;
				}
			}

			else {
				aux = 0;
				i = mitad + 1;
				while (a[i] == res2.minimo) {
					aux++;
					i++;
				}

				i = mitad;
				while (a[i] == res1.maximo) {
					aux++;
					i--;
				}

				if (aux > res1.longitud&& aux > res2.longitud) {
					res1.longitud = aux;
					res1.numero = res1.maximo;
				}
			}
		}

		if (res2.longitud > res1.longitud) {
			res1.longitud = res2.longitud;
			res1.numero = res2.numero;
		}

		res1.maximo = res2.maximo;

	}

	return res1;
}

//pre: a est� ordenado. n > 0
int lon_tramo_cte_max(int a[], int n) {

	if (n == 1) {
		return 1;
	}

	else {
		resultado res = mayorLongitud(a, 0, n - 1);
		return res.longitud;
	}
	
	// Punto de entrada al algoritmo. A implementar
}


/*
(1) Ecuaciones de recurrencia

(2) Resoluci�n de las ecuaciones (aplicaci�n de los patrones de resouluci�n)

(3) Complejidad final del algoritmo.

(4) Posibles ventajas y desventajas de tu algoritmo frente a una soluci�n iterativa de coste
	 lineal


*/


#ifndef DOM_JUDGE
int lon_tramo_cte_max_it(int a[], int n) {
	int lon = 1;
	int pos = 1;
	int lon_max = 1;
	while (pos != n) {
		if (a[pos] == a[pos - 1]) {
			lon++;
		}
		else {
			lon = 1;
		}
		if (lon > lon_max) {
			lon_max = lon;
		}
		pos++;
	}
	return lon_max;
}


const int MAX_LON = 40;
const int MAX_INIT = 20;
const int MAX_INC = 10;


void genera_caso(int a[], int& n) {
	n = (rand() % MAX_LON) + 1;
	a[0] = rand() % MAX_INIT;
	for (int i = 1; i < n; i++) {
		if (rand() % 2 == 0) {
			a[i] = a[i - 1];
		}
		else {
			a[i] = a[i - 1] + (rand() % MAX_INC);
		}
	}

}

const int MAX_PRUEBAS = 1000;
#endif

#ifdef DOM_JUDGE 
const int MAX_LON = 10000;

bool ejecuta_caso() {
	int a[MAX_LON];
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lon_tramo_cte_max(a, n) << endl;
		return true;
	}
}

#endif

int main() {
#ifndef DOM_JUDGE 
	int a[MAX_LON];
	int n;
	srand(time(NULL));
	int i = 0;
	int ok = true;
	while (i < MAX_PRUEBAS && ok) {
		genera_caso(a, n);
		if (lon_tramo_cte_max_it(a, n) != lon_tramo_cte_max(a, n)) {
			cout << "NO FUNCIONA PARA: ";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			ok = false;
		}
		i++;
	}
	if (ok) {
		cout << "OK" << endl;
	}
	system("pause");
#endif

#ifdef DOM_JUDGE 
	while (ejecuta_caso());
#endif

}