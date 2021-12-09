/*

NUMERO DE GRUPO: D03

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	JAVIER G�MEZ MORALEDA
	MARIO ALCOLEA ALCOLEA

*/

#include <iostream>

using namespace std;

/*
	Introducci�n: Este problema nos ha dado muchos quebraderos de cabeza y tr�s probar varios m�todos hemos logrado llegar al m�s �ptimo:
		En un primer instante, intentamos obtener el primer n�mero a partir de los datos de entrada (p.e. 1, 2 => num = 10, 11, ... , 19), pero al llegar al �ltimo
		caso era un n�mero muy grande y nos dimos cuenta de que no era viable.
		Luego intentamos estudiar un caso usando arrays (para poder introducir valores grandes), pero al final hemos llegado a la conclusi�n de que no es necesario,
		ya que vamos a ir d�gito por d�gito y lo que nos va a interesar es su suma.
		Por lo tanto, la manera de abordar el problema ha cambiado y en vez de empezar por el n�mero con todos los d�gitos (k) e ir restando, vamos a partir desde
		2 (ya que cualquier n�mero de un d�gito es sumdivisible).

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos
	
	calcula_sumdivisibles:
		- resultado: variable de salida pasada por referencia. Act�a como contador de todos los n�meros que cumplen dicha propiedad.
		- k: n�mero de d�gitos que contiene el n�mero (que no vamos a tener almacenado en ning�n sitio)
		- cifraActual: cifra del n�mero que evaluaremos para ver si cumple la propiedad. En el fondo, actuar�a como un �ndice en un array, que va recorriendo los distintos
		d�gitos del n�mero.
		- suma: suma acumulada de d�gitos, que utilizaremos para dividir con cifraActual para calcular si su m�dulo es 0.

(2) �C�mo son las soluciones parciales de este problema?

	Las soluciones parciales son calculadas utilizando la variable suma, en la que iremos almacenando la suma de los d�gitos. Seg�n vayamos incrementando cifraActual, nos iremos
	"desplazando" a trav�s de las cifras del n�mero de menos a m�s.

(3) �Cu�ndo una soluci�n parcial es viable?

	Teniendo en cuenta que suma + i es equivalente a sumar la suma acumulada m�s la cifra actual (que SIEMPRE oscilar� entre el 0 y el 9, al tratarse de un d�gito) es la
	suma de los digitos que llevamos y cifraActual + 1 es el n�mero de d�gitos actuales (+1 porque lo trataremos como una posici�n de un array):
		Una soluci�n parcial es viable siempre que la suma acumulada m�s la cifra actual m�dulo n�mero de digitos actuales (cifraActual + 1) es igual a 0.
		Es decir, que si la suma de digitos es divisible entre el n�mero de d�gitos, continuar� recurriendo.

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

	Una soluci�n parcial es una soluci�n final cuando he llegado a colocar el �ltimo digito y se cumple dicha propiedad.

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?
	
	Dada una soluci�n parcial correcta con la suma actualizada y n digitos, obtengo la siguiente soluci�n parcial viable:
		- Se ejecutar� un bucle for en el que i ser� el siguiente valor que tomar� el d�gito

		- Ahora compruebo si la suma acumulada m�s ese valor m�dulo del n�mero de digitos actual es igual a 0
			- Si se cumple, sigo avanzando en la recursi�n, es decir, "coloco" el siguiente d�gito.
			- Si no, corto la recursi�n.

(6) An�lisis de casos

(6.1) Caso(s) base

	Si cifraActual = k - 1, es decir, estoy en el �ltimo d�gito:
		- resultado++
	(Llegados al �ltimo d�gito y habiendo comprobado que cumple la propiedad, no puedo avanzar m�s en la recursi�n)


(6.2) Caso(s) recursivos

	- Si se cumple que la suma de los digitos es divisible entre el n�mero de d�gitos:
		- Compruebo que no sea el �ltimo d�gito y hago una llamada recursiva aumentando el n�mero de d�gitos en 1 y actualizando la suma acumulada con el d�gito actual.

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.
	
	En resumen, el algoritmo va a empezar con el d�gito inicial (d) y empezar� a evaluar desde el segundo d�gito si se cumple la propiedad colocando cualquier d�gito posible (del 0 al 9)
	y si se cumple para esos d�gitos, a�adiremos uno mas y volveremos a comprobar hasta llegar a k d�gitos.

*/


void calcula_sumdivisibles(int& resultado, int k, int cifraActual, int suma) {
	for (int i = 0; i < 10; i++) {
	
		if (((suma + i) % (cifraActual + 1)) == 0) {
			if (cifraActual == k - 1) {
				resultado++;
			}

			else {
				calcula_sumdivisibles(resultado, k, cifraActual + 1, suma + i);
			}
		}
	}
}

int num_sumdivisibles(int d, int k) {
	int resultado = 0;
	calcula_sumdivisibles(resultado, k, 1, d);
	return resultado;
}


int main() {
	int d;
	do {
		cin >> d;
		if (d > 0) {
			int k;
			cin >> k;
			cout << num_sumdivisibles(d, k) << endl;
		}
	} while (d > 0);
}