/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSI�N: 1.0

DESCRIPCI�N: Programa soluci�n al problema: "Realizar un programa que calcule el cubo de una serie de n�meros positivos
introducidos uno a uno, si se introduce un n�mero negativo se deber� terminar el programa". 

OBSERVACIONES: 
El programa recibe en el programa principal una serie de numeros por medio de la entrada estandar y se obtendra el cubo de cada uno,
el primer numero nunca ser� negativo. 

COMPILACI�N: gcc programa.c -o programa 
EJECUCI�N: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo

//PROGRAMA PRINCIPAL
int main()
{
	int numero, cubo; //Son los datos donde se almacenan los numeros y la operaci�n
	
	do
	{
	    printf("Introduce numeros: "); //Pide los numeros al usuario
        scanf("%d",&numero); //Lee los numeros 
        cubo= numero*numero*numero; //Hace la operaci�n para obtener el cubo
        printf("La respuesta es: %d \n",cubo); //Imprime la respuesta

		
	}while(!(numero < 0)); //Al cumplirse la condici�n se acaba el bucle
	
	getch();
	return 0;
}
