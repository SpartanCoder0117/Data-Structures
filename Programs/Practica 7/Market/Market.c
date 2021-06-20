/*
AUTOR: Josue Macias Castillo; Daniel Aguilar Gonzales; Agustin Galindo Reyes (C) Octubre 2016
VERSION: 1.0

DESCRIPCION: Programa que simula los tiempos de atencion en las cajas de un supermercado, toma en cuenta los tiempos que tardan en llegar los clientes, ademas de
mostrar su posicion de una forma muy grafica

OBSERVACIONES: El programa requerira de la libreria "TADColaEst.h", "TADColaEstCir.h" y "TADColaDin.h" las cuales tienen las implementaciones
para hacer uso de las funciones del TAD cola

COMPILACION:
gcc -o Market.c TADPila(Din|Est).o Market.exe (Si se tiene el objeto de la implementacion)
gcc -o Market.c TADPila(Din|Est).c Market.exe (Si se tiene el fuente de la implementacion)

EJECUCION: Market.exe (En Windows) - ./Market.exe (En Linux)
*/

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
//#include "TADColaEst.h"
#include "TADColaDin.h"
#include "presentacion.h"

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE 200
#define espera 600

//DEFINICION DE FUNCIONES
/*Procedimiento para dibujar las cajas 
(Recibe 2 enteros)*/
void Dibujar_Caja(int x, int y);
/*Procedimiento para borrar a los empleados
(Recibe 2 enteros)*/
void Borrar(int x, int y);
/*Procedimiento para dibujar a los clientes enfrente de las cajas
(Recibe 2 enteros)*/
void Ingresa_Cliente(int x, int y);
/*Procedimiento para dibujar un marco alrededor de los datos 
(No recibe nada)*/
void Marco();

//PROGRAMA PRINCIPAL
int main()
{
	unsigned int tiempo = 0;
	unsigned int cliente = 0;
	int num_caja, tiempo_cajas[10], tiempo_cliente, fila, cierre = 0;
	int xcaja = 2, ycaja = 8, i, letrero = 0;
	int x = 12, y = 11;
	int x1 = 12, y1 = 16;
	int x2 = 12, y2 = 21;
	int x3 = 12, y3 = 26;
	int x4 = 12, y4 = 31;
	int x5 = 12, y5 = 36;
	int x6 = 12, y6 = 41;
	int x7 = 12, y7 = 46;
	int x8 = 12, y8 = 51;
	elemento e;

	//Inicializar la funcion rand
	srand(time(NULL));
	printf("\nCuantas cajas deseas abrir: ");
	scanf("%d", &num_caja);

	switch (num_caja)
	{
	case 1:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja: ");
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola caja[1];
		//Se inicializa la cola
		Initialize(&caja[0]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		//Ciclo que espera a minimo 100 clientes y que las cajas esten vacias
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			//Mostrar el numero de clientes en cada cola
			MoverCursor(1, 2);
			printf("%d clientes en caja 0", Size(&caja[0]));
			if (Size(&caja[0]) > 0)
			{
				MoverCursor(1, 6);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Si la caja no esta vacia se atiende al proximo cliente
				if (!Empty(&caja[0]))
				{
					e = Dequeue(&caja[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 6);
					printf("No hat nadie en la caja 0");
				}
			}
			//Si el tiempo es multiplo del de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 1;
				Queue(&caja[fila], e);
				MoverCursor(1, 4);
				printf("Cliente %d a caja %d ", e.n, fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
			}
			//Complemento de la condicion para que se pueda cerrar la tienda
			if (cierre > 100)
			{
				MoverCursor(1, 5);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&caja[0]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 2:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas[2];
		//Se inicializan las colas
		Initialize(&cajas[0]);
		Initialize(&cajas[1]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);

		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			//Si el tamaño de la cadena es mayor a 0 hace invisible el letrero de no hay nadie en caja
			if (Size(&cajas[0]) > 0 || Size(&cajas[1]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas[0]))
				{
					e = Dequeue(&cajas[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				if (Empty(&cajas[0]) == TRUE)
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas[1]))
				{
					e = Dequeue(&cajas[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				if (Empty(&cajas[1]) == TRUE)
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 2;
				Queue(&cajas[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d ", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d ", Size(&cajas[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d ", Size(&cajas[1]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas[0]) == 0 && Size(&cajas[1]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 3:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas1[3];
		//Se inicializan las colas
		Initialize(&cajas1[0]);
		Initialize(&cajas1[1]);
		Initialize(&cajas1[2]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas1[0]) > 0 || Size(&cajas1[1]) > 0 || Size(&cajas1[2]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas1[0]))
				{
					e = Dequeue(&cajas1[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				if (Empty(&cajas1[0]) == TRUE)
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas1[1]))
				{
					e = Dequeue(&cajas1[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				if (Empty(&cajas1[1]) == TRUE)
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas1[2]))
				{
					e = Dequeue(&cajas1[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				if (Empty(&cajas1[2]) == TRUE)
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 3;
				Queue(&cajas1[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas1[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas1[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas1[2]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas1[0]) == 0 && Size(&cajas1[1]) == 0 && Size(&cajas1[2]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 4:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas2[4];
		//Se inicializan las colas
		Initialize(&cajas2[0]);
		Initialize(&cajas2[1]);
		Initialize(&cajas2[2]);
		Initialize(&cajas2[3]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas2[0]) > 0 || Size(&cajas2[1]) > 0 || Size(&cajas2[2]) > 0 || Size(&cajas2[3]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas2[0]))
				{
					e = Dequeue(&cajas2[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas2[1]))
				{
					e = Dequeue(&cajas2[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas2[2]))
				{
					e = Dequeue(&cajas2[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas2[3]))
				{
					e = Dequeue(&cajas2[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 4;
				Queue(&cajas2[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas2[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas2[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas2[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas2[3]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas2[0]) == 0 && Size(&cajas2[1]) == 0 && Size(&cajas2[2]) == 0 && Size(&cajas2[3]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 5:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas3[5];
		//Se inicializan las colas
		Initialize(&cajas3[0]);
		Initialize(&cajas3[1]);
		Initialize(&cajas3[2]);
		Initialize(&cajas3[3]);
		Initialize(&cajas3[4]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		Dibujar_Caja(xcaja, ycaja + 20);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas3[0]) > 0 || Size(&cajas3[1]) > 0 || Size(&cajas3[2]) > 0 || Size(&cajas3[3]) > 0 || Size(&cajas3[4]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas3[0]))
				{
					e = Dequeue(&cajas3[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas3[1]))
				{
					e = Dequeue(&cajas3[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas3[2]))
				{
					e = Dequeue(&cajas3[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas3[3]))
				{
					e = Dequeue(&cajas3[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[4] == 0)
			{
				//Caja 4
				if (!Empty(&cajas3[4]))
				{
					e = Dequeue(&cajas3[4]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x4 = x4 - 5;
					Borrar(x4, y4);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 5;
				Queue(&cajas3[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas3[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas3[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas3[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas3[3]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas3[4]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
				if (fila == 4)
				{
					Ingresa_Cliente(x4, y4);
					x4 = x4 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas3[0]) == 0 && Size(&cajas3[1]) == 0 && Size(&cajas3[2]) == 0 && Size(&cajas3[3]) == 0 && Size(&cajas3[4]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 6:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas4[6];
		//Se inicializan las colas
		Initialize(&cajas4[0]);
		Initialize(&cajas4[1]);
		Initialize(&cajas4[2]);
		Initialize(&cajas4[3]);
		Initialize(&cajas4[4]);
		Initialize(&cajas4[5]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		Dibujar_Caja(xcaja, ycaja + 20);
		Dibujar_Caja(xcaja, ycaja + 25);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas4[0]) > 0 || Size(&cajas4[1]) > 0 || Size(&cajas4[2]) > 0 || Size(&cajas4[3]) > 0 || Size(&cajas4[4]) > 0 || Size(&cajas4[5]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas4[0]))
				{
					e = Dequeue(&cajas4[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas4[1]))
				{
					e = Dequeue(&cajas4[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas4[2]))
				{
					e = Dequeue(&cajas4[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas4[3]))
				{
					e = Dequeue(&cajas4[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[4] == 0)
			{
				//Caja 4
				if (!Empty(&cajas4[4]))
				{
					e = Dequeue(&cajas4[4]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x4 = x4 - 5;
					Borrar(x4, y4);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[5] == 0)
			{
				//Caja 5
				if (!Empty(&cajas4[5]))
				{
					e = Dequeue(&cajas4[5]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x5 = x5 - 5;
					Borrar(x5, y5);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 6;
				Queue(&cajas4[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[3]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[4]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas4[5]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
				if (fila == 4)
				{
					Ingresa_Cliente(x4, y4);
					x4 = x4 + 5;
				}
				if (fila == 5)
				{
					Ingresa_Cliente(x5, y5);
					x5 = x5 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas4[0]) == 0 && Size(&cajas4[1]) == 0 && Size(&cajas4[2]) == 0 && Size(&cajas4[3]) == 0 && Size(&cajas4[4]) == 0 && Size(&cajas4[5]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 7:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas5[7];
		//Se inicializan las colas
		Initialize(&cajas5[0]);
		Initialize(&cajas5[1]);
		Initialize(&cajas5[2]);
		Initialize(&cajas5[3]);
		Initialize(&cajas5[4]);
		Initialize(&cajas5[5]);
		Initialize(&cajas5[6]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		Dibujar_Caja(xcaja, ycaja + 20);
		Dibujar_Caja(xcaja, ycaja + 25);
		Dibujar_Caja(xcaja, ycaja + 30);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas5[0]) > 0 || Size(&cajas5[1]) > 0 || Size(&cajas5[2]) > 0 || Size(&cajas5[3]) > 0 || Size(&cajas5[4]) > 0 || Size(&cajas5[5]) > 0 || Size(&cajas5[6]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas5[0]))
				{
					e = Dequeue(&cajas5[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas5[1]))
				{
					e = Dequeue(&cajas5[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas5[2]))
				{
					e = Dequeue(&cajas5[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas5[3]))
				{
					e = Dequeue(&cajas5[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[4] == 0)
			{
				//Caja 4
				if (!Empty(&cajas5[4]))
				{
					e = Dequeue(&cajas5[4]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x4 = x4 - 5;
					Borrar(x4, y4);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[5] == 0)
			{
				//Caja 5
				if (!Empty(&cajas5[5]))
				{
					e = Dequeue(&cajas5[5]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x5 = x5 - 5;
					Borrar(x5, y5);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[6] == 0)
			{
				//Caja 6
				if (!Empty(&cajas5[6]))
				{
					e = Dequeue(&cajas5[6]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x6 = x6 - 5;
					Borrar(x6, y6);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 7;
				Queue(&cajas5[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[3]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[4]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[5]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas5[6]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
				if (fila == 4)
				{
					Ingresa_Cliente(x4, y4);
					x4 = x4 + 5;
				}
				if (fila == 5)
				{
					Ingresa_Cliente(x5, y5);
					x5 = x5 + 5;
				}
				if (fila == 6)
				{
					Ingresa_Cliente(x6, y6);
					x6 = x6 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas5[0]) == 0 && Size(&cajas5[1]) == 0 && Size(&cajas5[2]) == 0 && Size(&cajas5[3]) == 0 && Size(&cajas5[4]) == 0 && Size(&cajas5[5]) == 0 && Size(&cajas5[6]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 8:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas6[8];
		//Se inicializan las colas
		Initialize(&cajas6[0]);
		Initialize(&cajas6[1]);
		Initialize(&cajas6[2]);
		Initialize(&cajas6[3]);
		Initialize(&cajas6[4]);
		Initialize(&cajas6[5]);
		Initialize(&cajas6[6]);
		Initialize(&cajas6[7]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		Dibujar_Caja(xcaja, ycaja + 20);
		Dibujar_Caja(xcaja, ycaja + 25);
		Dibujar_Caja(xcaja, ycaja + 30);
		Dibujar_Caja(xcaja, ycaja + 35);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas6[0]) > 0 || Size(&cajas6[1]) > 0 || Size(&cajas6[2]) > 0 || Size(&cajas6[3]) > 0 || Size(&cajas6[4]) > 0 || Size(&cajas6[5]) > 0 || Size(&cajas6[6]) > 0 || Size(&cajas6[7]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas6[0]))
				{
					e = Dequeue(&cajas6[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas6[1]))
				{
					e = Dequeue(&cajas6[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas6[2]))
				{
					e = Dequeue(&cajas6[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas6[3]))
				{
					e = Dequeue(&cajas6[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[4] == 0)
			{
				//Caja 4
				if (!Empty(&cajas6[4]))
				{
					e = Dequeue(&cajas6[4]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x4 = x4 - 5;
					Borrar(x4, y4);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[5] == 0)
			{
				//Caja 5
				if (!Empty(&cajas6[5]))
				{
					e = Dequeue(&cajas6[5]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x5 = x5 - 5;
					Borrar(x5, y5);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[6] == 0)
			{
				//Caja 6
				if (!Empty(&cajas6[6]))
				{
					e = Dequeue(&cajas6[6]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x6 = x6 - 5;
					Borrar(x6, y6);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[7] == 0)
			{
				//Caja 7
				if (!Empty(&cajas6[7]))
				{
					e = Dequeue(&cajas6[7]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x7 = x7 - 5;
					Borrar(x7, y7);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 8;
				Queue(&cajas6[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[3]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[4]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[5]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[6]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas6[7]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
				if (fila == 4)
				{
					Ingresa_Cliente(x4, y4);
					x4 = x4 + 5;
				}
				if (fila == 5)
				{
					Ingresa_Cliente(x5, y5);
					x5 = x5 + 5;
				}
				if (fila == 6)
				{
					Ingresa_Cliente(x6, y6);
					x6 = x6 + 5;
				}
				if (fila == 7)
				{
					Ingresa_Cliente(x7, y7);
					x7 = x7 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas6[0]) == 0 && Size(&cajas6[1]) == 0 && Size(&cajas6[2]) == 0 && Size(&cajas6[3]) == 0 && Size(&cajas6[4]) == 0 && Size(&cajas6[5]) == 0 && Size(&cajas6[6]) == 0 && Size(&cajas6[7]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	case 9:
		//Se llena el arreglo de cajas para atender
		for (i = 0; i < num_caja; i++)
		{
			printf("Cuanto tiempo necesitas para la caja %d: ", i);
			scanf("%d", &tiempo_cajas[i]);
		}
		//Se pregunta el tiempo que tardara el cliente en llegar
		printf("Cuanto tiempo tardaran en llegar los clientes: ");
		scanf("%d", &tiempo_cliente);
		//Se crea una cola
		cola cajas7[9];
		//Se inicializan las colas
		Initialize(&cajas7[0]);
		Initialize(&cajas7[1]);
		Initialize(&cajas7[2]);
		Initialize(&cajas7[3]);
		Initialize(&cajas7[4]);
		Initialize(&cajas7[5]);
		Initialize(&cajas7[6]);
		Initialize(&cajas7[7]);
		Initialize(&cajas7[8]);
		//Se limpia la pantalla
		BorrarPantalla();
		//Dibuja un marco en la pantalla
		Marco();
		MoverCursor(50, 0);
		printf("ESCOM MARKET\n");
		//Se dibuja la caja
		Dibujar_Caja(xcaja, ycaja);
		Dibujar_Caja(xcaja, ycaja + 5);
		Dibujar_Caja(xcaja, ycaja + 10);
		Dibujar_Caja(xcaja, ycaja + 15);
		Dibujar_Caja(xcaja, ycaja + 20);
		Dibujar_Caja(xcaja, ycaja + 25);
		Dibujar_Caja(xcaja, ycaja + 30);
		Dibujar_Caja(xcaja, ycaja + 35);
		Dibujar_Caja(xcaja, ycaja + 40);
		do
		{
			Sleep(TIEMPO_BASE);
			tiempo++;
			MoverCursor(1, 1);
			printf("Clientes atendidos %d: ", cierre);
			if (Size(&cajas7[0]) > 0 || Size(&cajas7[1]) > 0 || Size(&cajas7[2]) > 0 || Size(&cajas7[3]) > 0 || Size(&cajas7[4]) > 0 || Size(&cajas7[5]) > 0 || Size(&cajas7[6]) > 0 || Size(&cajas7[7]) > 0 || Size(&cajas7[8]) > 0)
			{
				MoverCursor(1, 5);
				printf("                         ");
			}
			//Si el tiempo es multiplo del tiempo de atencion 
			if (tiempo % tiempo_cajas[0] == 0)
			{
				//Caja 0
				if (!Empty(&cajas7[0]))
				{
					e = Dequeue(&cajas7[0]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 0 ", e.n);
					x = x - 5;
					Borrar(x, y);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 0");
				}
			}
			if (tiempo % tiempo_cajas[1] == 0)
			{
				//Caja 1
				if (!Empty(&cajas7[1]))
				{
					e = Dequeue(&cajas7[1]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 1 ", e.n);
					x1 = x1 - 5;
					Borrar(x1, y1);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 1");
				}
			}
			if (tiempo % tiempo_cajas[2] == 0)
			{
				//Caja 2
				if (!Empty(&cajas7[2]))
				{
					e = Dequeue(&cajas7[2]);
					MoverCursor(1, 3);
					printf("Se atiendio a: %d en caja 2 ", e.n);
					x2 = x2 - 5;
					Borrar(x2, y2);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 2");
				}
			}
			if (tiempo % tiempo_cajas[3] == 0)
			{
				//Caja 3
				if (!Empty(&cajas7[3]))
				{
					e = Dequeue(&cajas7[3]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x3 = x3 - 5;
					Borrar(x3, y3);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[4] == 0)
			{
				//Caja 4
				if (!Empty(&cajas7[4]))
				{
					e = Dequeue(&cajas7[4]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x4 = x4 - 5;
					Borrar(x4, y4);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[5] == 0)
			{
				//Caja 5
				if (!Empty(&cajas7[5]))
				{
					e = Dequeue(&cajas7[5]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x5 = x5 - 5;
					Borrar(x5, y5);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[6] == 0)
			{
				//Caja 6
				if (!Empty(&cajas7[6]))
				{
					e = Dequeue(&cajas7[6]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x6 = x6 - 5;
					Borrar(x6, y6);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[7] == 0)
			{
				//Caja 7
				if (!Empty(&cajas7[7]))
				{
					e = Dequeue(&cajas7[7]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x7 = x7 - 5;
					Borrar(x7, y7);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			if (tiempo % tiempo_cajas[8] == 0)
			{
				//Caja 8
				if (!Empty(&cajas7[8]))
				{
					e = Dequeue(&cajas7[8]);
					MoverCursor(1, 3);
					printf("Se atendio a: %d en caja 3", e.n);
					x8 = x8 - 5;
					Borrar(x8, y8);
					cierre++;
				}
				else
				{
					MoverCursor(1, 5);
					printf("No hay nadie en la caja 3");
				}
			}
			//Si el tiempo es multiplo del tiempo de llegada de los clientes
			if (tiempo % tiempo_cliente == 0)
			{
				cliente++;
				e.n = cliente;
				fila = rand() % 9;
				Queue(&cajas7[fila], e);
				MoverCursor(1, 2);
				printf("Cliente %d a caja %d", e.n, fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[0]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[1]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[2]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[3]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[4]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[5]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[6]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[7]), fila);
				Sleep(espera);
				MoverCursor(1, 4);
				printf("%d clientes en caja %d", Size(&cajas7[8]), fila);
				if (fila == 0)
				{
					Ingresa_Cliente(x, y);
					x = x + 5;
				}
				if (fila == 1)
				{
					Ingresa_Cliente(x1, y1);
					x1 = x1 + 5;
				}
				if (fila == 2)
				{
					Ingresa_Cliente(x2, y2);
					x2 = x2 + 5;
				}
				if (fila == 3)
				{
					Ingresa_Cliente(x3, y3);
					x3 = x3 + 5;
				}
				if (fila == 4)
				{
					Ingresa_Cliente(x4, y4);
					x4 = x4 + 5;
				}
				if (fila == 5)
				{
					Ingresa_Cliente(x5, y5);
					x5 = x5 + 5;
				}
				if (fila == 6)
				{
					Ingresa_Cliente(x6, y6);
					x6 = x6 + 5;
				}
				if (fila == 7)
				{
					Ingresa_Cliente(x7, y7);
					x7 = x7 + 5;
				}
				if (fila == 8)
				{
					Ingresa_Cliente(x8, y8);
					x8 = x8 + 5;
				}
			}
			if (cierre > 100)
			{
				MoverCursor(1, 6);
				printf("La tienda cerrara en unos momentos");
				Sleep(espera + 500);
				if (Size(&cajas7[0]) == 0 && Size(&cajas7[1]) == 0 && Size(&cajas7[2]) == 0 && Size(&cajas7[3]) == 0 && Size(&cajas7[4]) == 0 && Size(&cajas7[5]) == 0 && Size(&cajas7[6]) == 0 && Size(&cajas7[7]) == 0 && Size(&cajas7[8]) == 0)
				{
					letrero = 1;
				}
				else
				{
					letrero = 0;
				}
			}
		} while (letrero == 0);
		break;
	default:
		printf("Numero minimo de cajas de 1 a 9");
		break;
	}
}

/*
void Dibujar_Caja(int x,int y);
Descripción: Procedimiento para dibujar las cajas del supermercado 
Recibe: int x (Un entero para las coordenadas en x), int y (Un entero para las coordenadas en y)
Devuelve: 
Observaciones:
*/
void Dibujar_Caja(int x, int y)
{
	MoverCursor(x, y);
	printf("_|Caja|_\n");
	MoverCursor(x, y + 1);
	printf("|(*o*)/|\n");
	MoverCursor(x, y + 2);
	printf("|------|\n");

}

/*
void Borrar(int x,int y);
Descripción: Procedimiento para borrar a los clientes de las cajas
Recibe: int x (Un entero para las coordenadas en x), int y (Un entero para las coordenadas en y)
Devuelve: 
Observaciones:
*/
void Borrar(int x, int y)
{
	MoverCursor(x, y);
	printf("        \n");
}

/*
void Ingresa_Cliente(int x,int y);
Descripción: Procedimiento para dibujar a los clientes enfrente de las cajas
Recibe: int x (Un entero para las coordenadas en x), int y (Un entero para las coordenadas en y)
Devuelve: 
Observaciones:
*/
void Ingresa_Cliente(int x, int y)
{
	MoverCursor(x, y);
	printf("(O.O)");
}

/*
void Marco();
Descripción: Procedimiento para dibujar un marco alrededor de los datos que se muestran en pantalla
Recibe:
Devuelve: 
Observaciones:
*/
void Marco()
{
	int x, y;
	BorrarPantalla();

	for (x = 0; x <= 121; x++)
	{
		MoverCursor(x, 0);
		printf("%c", 205);
		MoverCursor(x, 7);
		printf("%c", 205);
		for (y = 0; y <= 7; y++)
		{
			MoverCursor(0, y);
			printf("%c", 186);
			MoverCursor(121, y);
			printf("%c", 186);
		}
	}
}