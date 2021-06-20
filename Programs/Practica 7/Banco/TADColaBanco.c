/*
Autor: Edgardo Adrián Franco Martínez
Versión 1.1 (02 de Octubre de 2013)
Descripción: Cabecera de la libreria para recrear presentaciones más agradables al usuario en el modo consola bajo Windows
Observaciones: Esta implementación de la libreria solo es compatible con Windows y el compilador MinGW ya que utiliza la libreria "windows.h", la cuál no es estandar.
Compilación de la libreria: Windows (gcc -c presentacionWin.c)
*/
//LIBRERIAS
#include <windows.h>
#include"TADColaBanco.h"

//DEFINICIÓN DE FUNCIONES

//Función para mover el cursor de escritura de pantalla, simulación de la función gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void MoverCursor( int x, int y ) 
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y }; 
	SetConsoleCursorPosition( hStdout, position );
	return;
};

//Función para esperar un tiempo en milisegundos, simulación de la función delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t)
{
	Sleep(t);
	return;
}


void Initialize(cola *c)
{
	c->frente=-1;
	c->final=-1;
	return;
}	

void Queue(cola *c, elemento e)
{
	c->final++;
	c->arreglo[c->final]=e;
	if(c->frente==-1) c->frente++;
	return;
}

elemento Dequeue(cola *c)
{
	int i;
	elemento aux;
	aux=c->arreglo[c->frente];
	//si al desencolar solo hay un elemento
	if(c->final==c->frente)
	{
		c->frente--;
	}
	//si hay mas de 1
	else
	{
		for(i=c->frente;i<c->final;i++)
		{
			c->arreglo[i]=c->arreglo[i+1];
		}	
	}
	c->final--;
	return aux;
}

booleano Empty(cola *c)
{
	if(c->frente==-1&&c->final==-1)
		return TRUE;
	else 	
		return FALSE;
}

elemento Front(cola *c)
{
	return c->arreglo[c->frente];
}

elemento Final(cola *c)
{
	return c->arreglo[c->final];
}

int Size(cola *c)
{
	return c->final+1;
}

void Destroy (cola *c)
{
	c->frente=-1;
	c->final=-1;
	return;
}


//Función para borrar la pantalla de la consola, simulación de la función clrscr() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void)
{
	system("cls");
	return;
}
