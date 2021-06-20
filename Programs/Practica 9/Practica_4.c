/*
AUTOR: Josue Macias Castillo; Daniel Aguilar Gonzales; Agustin Galindo Reyes (C) Noviembre 2016
VERSION: 1.0

DESCRIPCION: Programa que simula una serie de Fibonacci y su variante Tribonacci, ademas de la torre de Hanoi con ayuda de 
la recursividad. 

OBSERVACIONES: El programa no requiere una libreria externa a las proporcionadas por el compilador

COMPILACION:
gcc -o Practica_4.c Practica_4.exe 
gcc -o Practica_4.c Practica_4.exe

EJECUCION: Practica_4.exe (En Windows) - ./Practica_4.exe (En Linux)
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>

//Definiciones
#define Limpiar system("cls");
#define Pausa system("pause");

//Declaracion de funciones
/*Procedimiento para la serie de fibonacci (Recibe un entero largo)*/
long Fibonacci(long n);
/*Procedimiento para la variante tribonacci (Recibe un entero largo)*/
long Tribonacci(long m);
/*Procedimiento para la torre de hanoi (Recibe 4 enteros)*/
void Hanoi(int n, int com, int aux, int fin);

//Programa principal
int main()
{
	int op, num, y, tam, i;
	char com ='A';
	char aux ='B';
    char fin ='C';
	
	do
	{
		
		printf("\t\tRecursividad");
		printf("\nEscoge una opcion:\n");
		printf("1.- Fibonacci\n");
		printf("2.- Tribonacci\n");
		printf("3.- Torre de Hanoi\n");
		printf("0.- Salir\n");
		printf("Ingrese la opcion que desea:[   ]\b\b\b");
		scanf("%d", &op);
		Limpiar;

		switch(op)
		{
			case 1:
				printf("Introduce un numero de terminos: ");
				scanf_s("%ld", &tam);

				for (i = 0; i < tam; i++)
				{
					printf("%ld", Fibonacci(i));
					printf(",");
				}
				
				printf("\n\n");
				Pausa;
				Limpiar;
				break;
			case 2:
				printf("Introduce un numero de terminos: ");
				scanf_s("%ld", &tam);

				for (num = 0; num < tam; num++)
				{
					printf("%ld", Tribonacci(num));
					printf(",");
				}
				
				printf("\n\n");
				Pausa;
				Limpiar;
				break;
			case 3:
				printf("\nNumero de discos: ");
				scanf("%d",&y);
				fflush(stdin);
 
				printf("\n\nLos movimientos a realizar son: \n");
				Hanoi(y,com,aux,fin);	
				
				printf("\n\n");
				Pausa;
				Limpiar;
				break;		
		}
    }while(op!=0);
    
	printf("\n\n");
	exit(0);
}

/*
long Fibonacci(long numero);
Descripción: Procedimiento para hacer la operacion de fibonacci
Recibe: long numero (entero largo) 
Devuelve: Una serie de numeros
Observaciones: 
*/
long Fibonacci(long numero)
{
	if (numero > 2)
		return Fibonacci(numero - 1) + Fibonacci(numero - 2);
	else if (numero == 2)
		return 1;
	else if (numero == 1)
		return 1;
	else if (numero == 0)
		return 0;
}

/*
long Fibonacci(long n);
Descripción: Procedimiento para hacer la operacion de tribonacci
Recibe: long n (entero largo)
Devuelve: Una serie de numeros
Observaciones: 
*/
long Tribonacci(long n)
{
	if (n > 3)
		return Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
	else if (n == 0 || n == 1)
		return 0;
	else if (n == 2 || n == 3)
		return 1;
}

/*
void Hanoi(int n, int com, int aux, int fin);
Descripción: Procedimiento para 
Recibe: int n, com, aux, fin; (4 enteros)
Devuelve: 
Observaciones: 
*/
void Hanoi(int n, int com, int aux, int fin){
 
	if(n == 1)
		printf("%c->%c",com,fin);
	else
	{
		Hanoi(n-1,com,fin,aux);
		printf("\n%c->%c\n",com,fin);
		Hanoi(n-1,aux,com,fin);
	}
}
