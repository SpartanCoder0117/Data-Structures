/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSIÓN: 1.0

DESCRIPCIÓN: Programa solución al problema: "Realizar un programa que calcule el cubo de una serie de números positivos
introducidos uno a uno, si se introduce un número negativo se deberá terminar el programa". 

OBSERVACIONES: 
El programa recibe en el programa principal una serie de numeros por medio de la entrada estandar y se obtendra el cubo de cada uno,
el primer numero nunca será negativo. 

COMPILACIÓN: gcc programa.c -o programa 
EJECUCIÓN: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo

//PROGRAMA PRINCIPAL
int main()
{
	int numero, cubo; //Son los datos donde se almacenan los numeros y la operación
	
	do
	{
	    printf("Introduce numeros: "); //Pide los numeros al usuario
        scanf("%d",&numero); //Lee los numeros 
        cubo= numero*numero*numero; //Hace la operación para obtener el cubo
        printf("La respuesta es: %d \n",cubo); //Imprime la respuesta

		
	}while(!(numero < 0)); //Al cumplirse la condición se acaba el bucle
	
	getch();
	return 0;
}
