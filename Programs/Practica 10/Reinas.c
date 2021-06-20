/*
AUTOR: Josue Macias Castillo; Daniel Aguilar Gonzales; Agustin Galindo Reyes (C) Noviembre 2016
VERSION: 1.0

DESCRIPCION: 

OBSERVACIONES: 

COMPILACION:
gcc -o Reinas.c Reinas.exe 
gcc -o Reinas.c Reinas.exe 

EJECUCION: Reinas.exe (En Windows) - ./Reinas.exe (En Linux)
*/

//Librerias 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "presentacion.h"

//Definiciones
#define Pausa system("pause");
#define Limpiar system("cls");

static int Nreinas = 0;
static int *posicion = 0;

//Definicion de funciones
int resolver(int Ireinas);
int check(int tablero);

//PROGRAMA PRINCIPAL
int main()
{
	int resultado = 1;
	int i, k, l, j = 0;
	clock_t t0, t1;

	while (Nreinas <= 0 || resultado == 0)
	{
		printf("Ingrese numero de reinas: ");
		resultado = scanf("%d", &Nreinas);
		Limpiar;
	}
	for (k = 1; k <= Nreinas; k++)
	{
		for (l = 1; l <= Nreinas; l++)
		{
			MoverCursor(l, k);
			printf("#");
		}
	}
	posicion = (int*)malloc(sizeof(int) * Nreinas);
	t0 = clock();
	resultado = resolver(0);
	t1 = clock();
	if (resultado)
	{
		MoverCursor(0, Nreinas + 2);
		for (i = 0; i < Nreinas; i++)
		{
			printf("Reina %d: Columna %d, fila %d\n", i + 1, j, posicion[i] + 1);
			j++;
		}
	}
	else
	{
		MoverCursor(0, Nreinas + 2);
		printf("Se resolvio el problema\n");
	}

	free(posicion);
	Pausa;
	BorrarPantalla();
	exit(0);
}

int resolver(int Ireinas)
{
	int k, y, prevy = 0;
	for (k = 0; k < Nreinas; k++, prevy++)
	{
		//Se coloca una reina hasta llegar a una posicion valida
		posicion[Ireinas] = k;
		if (prevy)
		{
			MoverCursor(Ireinas + 1, prevy);
			printf("#");
		}
		MoverCursor(Ireinas + 1, k + 1);
		printf("&");
		y = k + 1;
		EsperarMiliSeg(500);
		if (check(Ireinas))
		{
			if (Ireinas == Nreinas - 1)
			{
				return 1;
			}
			else if (resolver(Ireinas + 1))
			{
				return 1;
			}
		}
		else
		{
			if (y == Nreinas)
			{
				MoverCursor(Ireinas + 1, y);
				printf("#");
			}
		}
	}
	return 0;
}

int check(int tablero)
{
	int i;

	for (i = 0; i < tablero; i++)
	{
		if (posicion[i] == posicion[tablero])
		{
			return 0;
		}
		else if (abs(posicion[tablero] - posicion[i]) == tablero - i)
		{
			return 0;
		}
	}
	return 1;
}

