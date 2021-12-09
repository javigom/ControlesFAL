/*

NUMERO DE GRUPO: D03

NOMBRE Y APELLIDOS DE LOS AUTORES:

	JAVIER G�MEZ MORALEDA
	MARIO ALCOLEA ALCOLEA

*/


#include <iostream>

using namespace std;

const int MAXN = 10;


/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

	Par�metros de entrada: 
		- coleccion[]: array con la coleccion de numeros a elegir (constante, no se modifica)
		- n: n�mero total de elementos en dicho array (constante, no se modifica)
		- sumaTotal: suma total que debemos obtener con las sumas parciales del array (constante, no se modifica)
		- sumaParcial: suma parcial que se va acumulando para obtener la suma total
		- indice: par�metro que indica la posicion del array
	Par�metros de salida:
		- resultado: devolveremos a trav�s de �l el n�mero de sumas posibles que den sumaTotal

(2) �C�mo son las soluciones parciales de este problema?
	
	Las soluciones parciales son de la forma suma parcial (entero) siempre y cuando se cumpla que sea menor que suma total.

(3) ¿Cuándo una solución parcial es viable?

	Una soluci�n parcial es viable siempre y cuando su suma parcial sea menor que la suma total y cuyo �ndice es
	menor que n.

(4) ¿Cuándo una solución parcial es una solución final al problema?

	Unsa soluci�n parcial es una soluci�n final cuando suma parcial = suma total.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
	parciales viables?

	Tenemos dos caminos a seguir: sumar el elemento coleccion[i] o no sumarlo
	
		- Si se suma: Primero compruebo que la suma parcial + el elemento sea menor o igual que suma total
		y una vez dentro compruebo si estoy en el �ltimo elemento o no para hacer la llamada recursiva.

		- Si no se suma: Compruebo si estoy en el ultimo elemento o no para hacer la llamada recursiva.

(6) Análisis de casos

	 (6.1) Caso(s) base

	 - Si estoy en el �ltimo elemento del array y lo sumo,
		- Si sumaParcial + ese elemento es igual a sumaTotal, entonces resultado++

	 - Si estoy en el �ltimo elemento del array pero no lo sumo,
		- Si sumaParcial es igual a sumaTotal, entonces resultado++


	 (6.2) Caso(s) recursivos

	 Considerando indice la posicion del array:
		
		- Si sumaParcial + coleccion[indice] es menor o igual que suma total (Es decir, si sumo el elemento):
			- Compruebo que no estoy en el �ltimo elemento del array:
				- Hago una llamada recursiva a calculaModulos cambiando el valor de sumaParcial a sumaParcial + coleccion[indice]
				e indice a indice + 1 (avanzo una posicion en el array).

		- Si no estoy en el �ltimo elemento del array y no he sumado el elemento:
			- Hago una llamada recursiva a calculaModulos cambiando el valor de indice a indice + 1.


(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
	a partir de la misma, por inmersión.

	Almacenamos el resultado en la variable res declarado la funcion modulo y pasada por referencia a la funcion calculaModulos.

*/

void calculaModulos(int coleccion[], int n, int sumaTotal, int sumaParcial, int indice, int& resultado) {

	if (sumaParcial + coleccion[indice] <= sumaTotal) {

		if ((indice + 1) == n) {

			if ((sumaParcial + coleccion[indice]) == sumaTotal)
				resultado++;
		}

		else
			calculaModulos(coleccion, n, sumaTotal, sumaParcial + coleccion[indice], indice + 1, resultado);
	}

	if ((indice + 1) == n) {
		if (sumaParcial == sumaTotal)
			resultado++;
	}

	else
		calculaModulos(coleccion, n, sumaTotal, sumaParcial, indice + 1, resultado);
}


int modulo(int coleccion[], int n, int k) {
	int res = 0;
	calculaModulos(coleccion, n, k, 0, 0, res);
	return res;
		
}


void lee_datos(int& n, int coleccion[], int& k) {
	cin >> n;
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> coleccion[i];
		}
		cin >> k;
	}
}

bool ejecuta_caso() {
	int coleccion[MAXN];
	int n;
	int k;
	lee_datos(n, coleccion, k);
	if (n != 0) {
		cout << modulo(coleccion, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}
