/*
GRUPO:
COMPONENTES DEL GRUPO:

*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  

*/
bool es_sobrado(int n); 

/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte 
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
  
  
  (2) Postcondici�n
    
    
 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo
 
 PASO 1. Variables
 
 
 PASO 2. Invariante
	 

 PASO 3. Inicializaci�n:
 
 
 PASO 4: Continuaci�n y finalizaci�n: 
 	  
 
 PASO 5: Cuerpo del bucle
 
 
PASO 6: Terminaci�n		  

 
*/
 
 
 bool es_sobrado(int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo


*/ 
	 

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
   int n_casos;
   cin >> n_casos;
   while (n_casos > 0) {
	   int n;
	   cin >> n;
	   if (es_sobrado(n)) {
		  cout << "SI" << endl;  
	   }
	   else {
		  cout << "NO" << endl; 
	   }
	   n_casos--;
   }
   return 0;
}