/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSIÓN: 1.0

DESCRIPCIÓN: Programa solución al problema: "Dados 3 números enteros de entrada a, b y c, mostrarlos a la salida ordenados de forma descendente". 

OBSERVACIONES: 
El programa recibe en el programa principal 3 numeros por medio de la entrada estandar y se verifica que sea cual es el mayor al menor
para ordenarlos de forma descendente 

COMPILACIÓN: gcc programa.c -o programa 
EJECUCIÓN: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo

//PROGRAMA PRINCIPAL
int main()
{
	int a,b,c; //Almacenan los 3 numeros
	
	printf("a: "); //Pide el primer numero
	scanf("%i",&a);                    //Lee el primer numero
	printf("b: "); //Pide el segundo numero
	scanf("%i",&b);                     //Lee el segundo numero
	printf("c: "); //Pide el tercer numero
	scanf("%i",&c);                    //Lee el tercer numero
	
	//Si "a" es mayor que "b" 
    if(a > b)
    {
         if(a > c)   //Compara si "a" es mayor a "c"
         {
         	if(b > c)  //Compara si "b" es mayor a "c"
			 {
			 	printf("Respuesta: %i,%i,%i",a,b,c); //Imprime los valores en el orden indicado
			 }
			 else                                    
			 {
			 	printf("Respuesta: %i,%i,%i",a,c,b); //En caso contrario los imprime en diferente orden
			 }
		 }
		 else
		 {
		  printf("Respuesta: %i,%i,%i",c,a,b);	 //En caso contrario los imprime en diferente orden
		 }    	
	}
	else          //En caso contrario de la primera comparación se ejecutan estos if
	    if(b > c)
	    {
	    	if(a > c)
	    	{
	    	  printf("Respuesta: %i,%i,%i",b,a,c);	//Hace comparaciones en caso de ser verdad imprime en el orden dado	
			}
			else
			{
				printf("Respuesta: %i,%i,%i",b,c,a);	 //En caso contrario los imprime en diferente orden
			}
	      
	    }
	    else      //En caso contrario los imprime en diferente orden
	    {
	    	printf("Respuesta: %i,%i,%i",c,b,a);
		}
		
		//Finalizan los if	
		
	getch();
	return 0;
}
