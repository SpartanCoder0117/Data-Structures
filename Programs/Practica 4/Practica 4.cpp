/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSIÓN: 1.0

DESCRIPCIÓN: Programa solución al problema: "Se necesita realizar un programa que muestre la serie de Fibonacci hasta el termino n, el cual es recibido 
al inicio y debe ser mayor a 2. Al mostrar la serie se deberá mostrar termino a termino a la salida con un retraso de 0.5 segundos". 

OBSERVACIONES: 
El programa recibe en el programa principal el termino n por medio de la entrada estandar, los 2 primeros numeros deben ser 0 y 1 el resto se calcula como la suma
de los 2 numeros inmediatos 

COMPILACIÓN: gcc programa.c -o programa 
EJECUCIÓN: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo
#include<windows.h> //Contiene declaraciones de todas las funciones en el API de Windows


//PROGRAMA PRINCIPAL
int main()
{
	int n, primero, segundo, siguiente, elemento; //Almacena los datos proporcionados
	
	do
	{
		printf("Dame un numero: "); //Pide al usuario el valor de n
		scanf("%d",&n);   //Lee el valor de n
		
	}while(!(n > 2));  //Cuando se cumple la condicion sale del do - while
	primero = 0;   //Inicializa a primero que sea igual a cero
	printf("%d,",primero); //Imprime primero
	Sleep(500);   //Hace un delay de medio segundo
	segundo = 1;  //Inicializa a segundo con uno
	printf("%d,",segundo); //Imprime segundo
	Sleep(500);   //Hace un delay de medio segundo
	elemento = 3;  //Inicializa a elemento con 3
	do      //Entrada al bucle
	{
		siguiente = primero + segundo;  //Hace la suma de primero y segundo y lo guarda en siguiente
		printf("%d,",siguiente);    //Imprime siguiente
		Sleep(500);   //Hace un delay de medio segundo
		primero = segundo;  //A primero le da el valor de segundo
	    segundo = siguiente;  //A segundo le da el valor de siguiente
		elemento++;   //Incrementa a elemento
		
	}while(!(elemento > n));  //Fin del bucle
	
    getch();
}
