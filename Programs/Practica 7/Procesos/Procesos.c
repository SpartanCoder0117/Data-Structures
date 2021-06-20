/*
AUTOR: Josue Macias Castillo; Daniel Aguilar Gonzales; Agustin Galindo Reyes (C) Octubre 2016
VERSION: 1.0

DESCRIPCION: Programa que simula los procesos que se ejecutan en un sistema operativo con ayuda de sus tiempos sin tomar en cuenta su prioridad

OBSERVACIONES: El programa requerira de la libreria "TADColaEst.h", "TADColaEstCir.h" y "TADColaDin.h" las cuales tienen las implementaciones
para hacer uso de las funciones del TAD cola

COMPILACION:
gcc -o Procesos.c TADPila(Din|Est).o Procesos.exe (Si se tiene el objeto de la implementacion)
gcc -o Procesos.c TADPila(Din|Est).c Procesos.exe (Si se tiene el fuente de la implementacion)

EJECUCION: Procesos.exe (En Windows) - ./Procesos.exe (En Linux)
*/
//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include "TADColaDin.h"
//#include "TADColaEst.h" 
#include "presentacion.h" //Librería con las funcioes de sistema de limpiado de pantalla y posicionamiento del cursor en coordenadas

//Definicion de constantes
#define Quantum 1000 //Tiempo en milisegundos de espera del procesador
#define PAUSA system("pause") //Generar una pausa en Windows (cambiar por getchar en Linux)
#define numProc 100 //numero maáximo de procesos permitidos

//DEFINICION DE FUNCIONES
/*Procedimiento para capturar los procesos que se van a simular
(Recibe la referencia del elemento procesos, recibe la referencia de un entero numP)*/
void Captura_Procesos(elemento *procesos, int *numP); 
/*Procedimiento para mostrar los procesos que se van a simular
(Recibe la referencia del elemento procesos, recibe un entero numP)*/
void Imprime_Procesos(elemento *procesos, int numP);
/*Procedimiento para simular los procesos que se van a simular
(Recibe la referencia del elemento procesos, recibe un entero numP)*/
void Simulacion(elemento *procesos, int numP);
/*Procedimiento para dibujar el marco 
(No recibe nada)*/
void Marco();

//PROGRAMA PRINCIPAL
void main(void)
{
	elemento Procesos[numProc];
	int numP = 0;
	int op;
	do
	{
		//Despliega las opciones para operar con el programa
		printf("Simulacion de procesos en el sistema\n");
		printf("Elije una opcion:\n");
		printf("1.- Cargar procesos\n");
		printf("2.- Ver procesos registrados\n");
		printf("3.- Iniciar la simulacion\n");
		printf("4.- Salir\n");
		printf("\nIngrese la opcion que desea:[   ]\b\b\b");
		scanf("%d", &op);
		BorrarPantalla();
		switch (op)
		{
		case 1:
			Captura_Procesos(Procesos, &numP);
			break;
		case 2:
			Imprime_Procesos(Procesos, numP);
			break;
		case 3:
			Simulacion(Procesos, numP);
			break;
		case 4:
			printf("\nPrograma finalizado");
			printf("\n\n");
		}
	}while (op != 4);
	exit(0);
}

/*
void Captura_Procesos(elemento *procesos, int *numP);
Descripción: Procedimiento para capturar por medio de la entrada estandar los procesos a simular
Recibe: elemento *procesos (Referencia al elemento de procesos), int *numP (Referencia a un entero)
Devuelve: 
Observaciones:
*/
void Captura_Procesos(elemento *procesos, int *numP)
{
	int i;
	printf("Captura de procesos\n");
	printf("Cuantos procesos deseas capturar: ");
	scanf("%d", numP);
	//Captura de procesos
	for (i = 0; i < *numP; i++) 
	{
		fflush(stdin);
		printf("Informacion del proceso %d.\n", i + 1);
		puts("Ingresa el nombre del proceso: ");
		gets(procesos[i].nombreProceso);
		puts("Ingresa la actividad del proceso: ");
		gets(procesos[i].actividad);
		puts("Ingresa el ID del proceso: ");
		gets(procesos[i].ID);
		puts("Ingresa el tiempo del proceso (segundos): ");
		scanf("%d", &procesos[i].tiempo);
		puts("\n");
	}
	PAUSA;
	BorrarPantalla();
	return;
}

/*
void Imprime_Procesos(elemento *procesos, int *numP);
Descripción: Procedimiento para imprimir los procesos a simular
Recibe: elemento *procesos (Referencia al elemento de procesos), int numP (Un entero)
Devuelve:
Observaciones:
*/
void Imprime_Procesos(elemento *procesos, int numP)
{
	int i;
	printf("Procesos registrados para la simulacion\n\n");
	//Comprueba que se hayan capturado
	if (numP != 0)
	{
		for (i = 0; i < numP; i++)
		{
			printf("Informacion del proceso: %d\n", i + 1);
			printf("Nombre: %s\n", procesos[i].nombreProceso);
			printf("Actividad: %s\n", procesos[i].actividad);
			printf("ID: %s\n", procesos[i].ID);
			printf("Tiempo: %d segundos\n", procesos[i].tiempo);
			printf("\n");
		}
	}
	else if (numP == 0)
	{
		//Comunica al usuario que no hay procesos 
		printf("No hay procesos registrados\n");
	}
	PAUSA;
	BorrarPantalla();
	return;
}

/*
void Simulacion(elemento *procesos, int *numP);
Descripción: Procedimiento para simular los procesos
Recibe: elemento *procesos (Referencia al elemento de procesos), int numP (Un entero)
Devuelve:
Observaciones:
*/
void Simulacion(elemento *procesos, int numP)
{
	int i, time = 0, j = 0;
	//Elementos auxiliares para los datos temporales
	elemento e, f, sig;
	//Declaracion de colas
	cola listos, ejecucion, terminados;
	//Comprueba que hayan sido capturados los procesos
	if (numP != 0)
	{
		//Se inicializan las colas
		Initialize(&listos);
		Initialize(&ejecucion);
		Initialize(&terminados);
		for (i = 0; i < numP; i++)
		{
			//Igualacion de los tiempos totales de los procesos a cero
			procesos[i].tiempoTotal = 0;
			//Forma los procesos en la cola
			Queue(&listos, procesos[i]);
		}
		Marco();
		MoverCursor(25, 0);
		printf("Simulacion de procesos del sistema\n");
		MoverCursor(2, 2);
		printf("ID:");
		MoverCursor(2, 4);
		printf("Nombre:");
		MoverCursor(2, 6);
		printf("Actividad:");
		MoverCursor(2, 8);
		printf("Tiempo de ejecucion:");
		MoverCursor(2, 14);
		printf("Ultimo Proceso:");
		MoverCursor(2, 17);
		printf("Proximo proceso:");
		//Seccion principal de la simulacion
		do
		{
			//Toma un proceso de los que estan listos a ejecutar
			e = Dequeue(&listos);
			//Aumento del tiempo de ejecucion
			e.tiempoTotal = e.tiempoTotal + time;
			//Muestra en pantalla los datos del proceso actual
			MoverCursor(6, 2);
			printf("%s", e.ID);
			MoverCursor(10, 4);
			printf("%s", e.nombreProceso);
			MoverCursor(13, 6);
			printf("%s", e.actividad);
			MoverCursor(23, 8);
			printf("%i segundos", e.tiempoTotal);
			//Inicio de ejecucion del proceso
			Queue(&ejecucion, e);
			//Simulacion de un ciclo de reloj del procesador transcurrido
			EsperarMiliSeg(Quantum);
			//Vaciado de los datos en pantalla
			MoverCursor(6, 2);
			printf("                                                   ");
			MoverCursor(10, 4);
			printf("                                               ");
			MoverCursor(13, 6);
			printf("                                                              ");
			MoverCursor(23, 8);
			printf("                                  ");
			MoverCursor(18, 14);
			printf("                                                       ");
			MoverCursor(19, 17);
			printf("                                                       ");
			//Finalizacion del proceso en el nucleo
			e = Dequeue(&ejecucion);
			//Disminucion del tiempo transcurrido
			e.tiempo = e.tiempo - 1;
			//Aumento de un segundo ejecutado
			e.tiempoTotal++;
			//Si hay un proceso en espera, se aumentan sus tiempos totales de ejecucion 
			if (Empty(&listos) == FALSE)
			{
				for (i = 0; i < Size(&listos); i++)
				{
					f = Dequeue(&listos);
					f.tiempoTotal++;
					Queue(&listos, f);
				}
			}
			//Si ha terminado el tiempo de ejecucion del proceso actual, se envia a los procesos terminados
			if (e.tiempo == 0)
			{
				MoverCursor(18, 14);
				printf("%s, Tiempo restante: Proceso terminado", e.nombreProceso);
				Queue(&terminados, e);
			}
			//Si aun no termina el tiempo de ejecucion del proceso actual, se vuelve a coloca a la cola de procesos listos
			else
			{
				MoverCursor(18, 14);
				printf("%s, Tiempo restante: %i", e.nombreProceso, e.tiempo);
				Queue(&listos, e);
			}
			//Impresion en pantalla del siguiente proceso a ejecutar
			if (Empty(&listos) == FALSE)
			{
				sig = Front(&listos);
				MoverCursor(19, 17);
				printf("%s, Tiempo restante: %i", sig.nombreProceso, sig.tiempo);
			}
		}while (Empty(&listos) == FALSE);
		//Vaciado de todos los datos 
		MoverCursor(6, 2);
		printf("                                                       ");
		MoverCursor(2, 2);
		printf("                                                   ");
		MoverCursor(10, 4);
		printf("                                                       ");
		MoverCursor(2, 4);
		printf("                                                       ");
		MoverCursor(13, 6);
		printf("                                                                         ");
		MoverCursor(2, 6);
		printf("                                                                         ");
		MoverCursor(23, 8);
		printf("                                                       ");
		MoverCursor(2, 8);
		printf("                                                       ");
		MoverCursor(18, 14);
		printf("                                                       ");
		MoverCursor(2, 14);
		printf("                                                       ");
		MoverCursor(19, 17);
		printf("                                                       ");
		MoverCursor(2, 17);
		printf("                                                       ");
		MoverCursor(2, 8);
		printf("Procesos finalizados");
		//Una vez terminados los procesos, se vacian los datos temporales de pantalla
		MoverCursor(2, 9);
		printf("Generando reporte...");
		//Espera 3 segundos antes de pasar a la muestra de procesos terminados
		EsperarMiliSeg(3000);
		BorrarPantalla();
		printf("\t\t\tProcesos finalizados\n\n\n");
		printf("\tNombre\t\t\t\t\t\tTiempo total\n\n");
		//Muestra de los procesos terminados en ejecutar por el procesador
		do
		{
			e = Dequeue(&terminados);
			MoverCursor(8, j + 6);
			printf("%s", e.nombreProceso);
			MoverCursor(56, j + 6);
			printf("%i segundos", e.tiempoTotal);
			j++;
		}while (Empty(&terminados) == FALSE);
		printf("\n");
	}
	//Si aun no hay procesos capturados
	else
	{
		printf("No hay procesos para ejecutar\n");
	}
	//Destruccion de las colas utilizadas
	Destroy(&listos);
	Destroy(&ejecucion);
	Destroy(&terminados);
	PAUSA;
	BorrarPantalla();
	return;
}

/*
void Marco();
Descripción: Procedimiento para dibujar un marco
Recibe: 
Devuelve:
Observaciones: Necesita la libreria de presentacion.h
*/
void Marco()
{
	int x, y;
	BorrarPantalla();

	for (x = 0; x <= 84 ; x++)
	{
		MoverCursor(x, 0);
		printf("%c", 205);
		MoverCursor(x, 12);
		printf("%c", 205);
		for (y = 0; y <= 12; y++)
		{
			MoverCursor(0, y);
			printf("%c", 186);
			MoverCursor(84, y);
			printf("%c", 186);
		}
	}
}