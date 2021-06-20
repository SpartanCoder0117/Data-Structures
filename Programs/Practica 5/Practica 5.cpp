/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSI�N: 1.2

DESCRIPCI�N: Programa soluci�n al problema: "Se necesita realizar un programa que sea capaz de recibir y generar 2 matrices din�micas de tama�o m x n, 
el program realiza una operaci�n de suma y resta de matrices que se muestra por la salida estandar". 

OBSERVACIONES: 
El programa recibe en el programa principal todas las funciones que generan las matrices y los datos por medio de la entrada estandar para saber 
de cuantas columnas y filas es cada matriz  

COMPILACI�N: gcc programa.c -o programa 
EJECUCI�N: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo
#include<stdlib.h>  //Incluye las funciones de asignaci�n dinamica

#define Limpiar system("cls") //Define system("cls") como limpiar para hacerlo mas practico en el codigo

//DECLARACI�N DE FUNCIONES
//Aparta el espacio de memoria para la primer matriz din�mica
int **Aparta_Matriz(int m, int n);
//Aparta el espacio de memoria para la segunda matriz din�mica
int **Aparta_Matriz_2(int m, int n);
//Captura la primer matriz din�mica
void Capturar_Matriz(int **matriz, int m, int n);
//Captura la segunda matriz din�mica
void Capturar_Matriz_2(int **matriz_2, int m, int n);
//Imprime la primer matriz din�mica
void Imprime_Matriz(int **matriz, int m, int n);
//Imprime la segunda matriz din�mica
void Imprime_Matriz_2(int **matriz_2,int m, int n);
//Suma las matrices
void Suma_Matrices(int **matriz, int **matriz_2, int m, int n);
//Resta las matrices
void Resta_Matrices(int **matriz, int **matriz_2, int m, int n);


//PROGRAMA PRINCIPAL
int main(void)
{
	int i, j, m, n, **matriz, **matriz_2, Suma, Resta;  
	//Leer m y n
	printf("Introduce m y n separados por espacio:[   ]\b\b\b\b");
	scanf("%d %d",&m,&n);   
	//Aparta memoria para la primer matriz din�mica
	matriz = Aparta_Matriz(m,n);
	//Captura la primera matriz din�mica 
	Capturar_Matriz(matriz,m,n);
	//Leer m y n para la segunda matriz
	printf("Introduce m y n separados por espacio:[   ]\b\b\b\b");
	scanf("%d %d",&m,&n);
	//Aparta memoria para la segunda matriz din�mica
	matriz_2 = Aparta_Matriz_2(m,n);
	//Captura la segunda matriz din�mica
	Capturar_Matriz_2(matriz_2,m,n);
	Limpiar; //Limpia la pantalla para mostrar los resultados
	//Muestra la primer matriz
	printf("\n******Matriz Original 1******");
	Imprime_Matriz(matriz, m, n);
	//Muestra la segunda matriz
	printf("\n******Matriz Original 2******");
	Imprime_Matriz(matriz_2, m, n);
	//Muestra la suma de las matrices
	printf("\n*****Suma de las matrices*****");
	Suma_Matrices(matriz,matriz_2,m,n);  
	//Muestra la resta de las matrices
	printf("\n*****Resta de las matrices*****");
	Resta_Matrices(matriz,matriz_2,m,n); 
    
 getch();
}

/*
int **Aparta_Matriz(int m,int n);
Descripci�n: Aparta el espacio de memoria para la primera matriz din�mica
Recibe: int m (N�mero de filas), int n (N�mero de columnas)
Devuelve: int **matriz (Referencia a la matriz apartada), 
Observaciones: m y n deberan ser mayor a 0
*/
int **Aparta_Matriz(int m, int n)
{ 
   int i, **matriz;
   //Aparta memoria para la primera matriz
   matriz = (int **)malloc(m*sizeof(int)); //m apuntadores simples a enteros, ademas de que se le aplico un cast
   for(i = 0; i < m;i++)
   {
   	 matriz[i] = (int *)malloc(n*sizeof(int)); //El apuntador simple matriz[i] apunta a n enteros, ademas de que se le aplico un cast
   }
  return matriz;	//Regresa la referencia al apuntador principal a la matriz din�mica	
}
/*
int **Aparta_Matriz_2(int m,int n);
Descripci�n: Aparta el espacio de memoria para la segunda matriz din�mica
Recibe: int m (N�mero de filas), int n (N�mero de columnas)
Devuelve: int **matriz_2 (Referencia a la matriz apartada), 
Observaciones: m y n deberan ser mayor a 0
*/
int **Aparta_Matriz_2(int m, int n)
{
	int i, **matriz_2;
	//Aparta memoria para la segunda matriz
	matriz_2 = (int **)malloc(m*sizeof(int)); //m apuntadores simples a enteros, ademas de que se le aplico un cast
	for(i = 0;i < m;i++)
	{
		matriz_2[i] = (int *)malloc(n*sizeof(int)); //El apuntador simple matriz[i] apunta a n enteros, ademas de que se le aplico un cast
	}	
  return matriz_2;	//Regresa la referencia al apuntador principal a la matriz dinamica
}
/*
void Capturar_Matriz(int **matriz,int m,int n);
Descripci�n: Capturar la primer matriz din�mica
Recibe: int **matriz (Referencia a la matriz), int m (N�mero de filas), int n (N�mero de columnas)
Devuelve: 
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Capturar_Matriz(int **matriz, int m, int n)
{
	int i, j;
	
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("Introduce el elemento[%d][%d]: ",i,j);
			scanf("%d",&matriz[i][j]);			
		}
	}
}
/*
void Capturar_Matriz_2(int **matriz_2,int m,int n);
Descripci�n: Capturar la segunda matriz din�mica
Recibe: int **matriz_2 (Referencia a la matriz), int m (N�mero de filas), int n (N�mero de columnas)
Devuelve:
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Capturar_Matriz_2(int **matriz_2, int m, int n)
{
	int i, j;
	
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("Introduce el elemento[%d][%d]: ",i,j);
			scanf("%d",&matriz_2[i][j]);			
		}
	}
}
/*
void Imprime_Matriz(int **matriz,int m,int n);
Descripci�n: Procedimiento para imprimir la primer matriz
Recibe: int **matriz (Referencia a la matriz), int m (N�mero de filas), int n (N�mero de columnas)
Devuelve:
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Imprime_Matriz(int **matriz, int m, int n)
{
	int i, j;
	
	for(i = 0; i < m; i++)
	{
		printf("\n");
		for(j = 0; j < n;j++)
		{
			printf("\t%d",matriz[i][j]);
		}
	}
}
/*
void Imprime_Matriz_2(int **matriz_2,int m,int n);
Descripci�n: Procedimiento para imprimir la segunda matriz
Recibe: int **matriz_2 (Referencia a la matriz), int m (N�mero de filas), int n (N�mero de columnas)
Devuelve:
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Imprime_Matriz_2(int **matriz_2, int m, int n)
{
	int i, j;
	
	for(i = 0; i < m; i++)
	{
		printf("\n");
		for(j = 0; j < n;j++)
		{
			printf("\t%d",matriz_2[i][j]);
		}
	}
}
/*
void Suma_Matrices(int **Matriz, int **Matriz_2, int Suma, int m, int n)
Descripci�n: Procedimiento para sumar las 2 matrices
Recibe: int **matriz (Referencia a la primer matriz), int **matriz_2 (Referencia a la segunda matriz),
int m (N�mero de filas), int n (N�mero de columnas), int suma (Guarda el resultado)
Devuelve: El resultado de la suma
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Suma_Matrices(int **matriz, int **matriz_2, int m, int n)
{
	int i, j;
	
	for(i = 0;i < m;i++)
	{
		printf("\n");
		for(j = 0;j < n;j++)
		{
			printf("\t%d",matriz[i][j] + matriz_2[i][j]); //Aqui se hace la suma de las matrices 
		}
	}	
	
}
/*
void Resta_Matrices(int **matriz, int **matriz_2, int m, int n)
Descripci�n: Procedimiento para sumar las 2 matrices
Recibe: int **matriz (Referencia a la primer matriz), int **matriz_2 (Referencia a la segunda matriz),
int m (N�mero de filas), int n (N�mero de columnas), int suma (Guarda el resultado)
Devuelve: El resultado de la suma
Observaciones: La matriz fue reservada previamente de tama�o m por n
*/
void Resta_Matrices(int **matriz, int **matriz_2, int m, int n)
{
	int i, j;
	
	for(i = 0;i < m;i++)
	{
		printf("\n");
		for(j = 0;j < n;j++)
		{
			printf("\t%d",matriz[i][j] - matriz_2[i][j]); //Aqui se hace la resta de las matrices 
		}
	}
}
