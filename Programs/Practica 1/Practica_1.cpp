/*
AUTOR: Josue Macias Castillo (C) Agosto 2016
VERSIÓN: 1.0

DESCRIPCIÓN: Programa solución al problema: "Se necesita realizar un programa que calcule el sueldo neto de un trabajador, 
el programa recibirá el sueldo base del empleado y le descontara el impuesto sobre la renta". 

OBSERVACIONES: 
El programa recibe en el programa principal el sueldo del empleado por medio de la entrada estandar y se verifica que sea mayor que 0 

COMPILACIÓN: gcc programa.c -o programa 
EJECUCIÓN: programa.exe (En Windows) - ./programa (En Linux)
*/

//LIBRERIAS
#include<stdio.h> //Incluye las funciones estandar de entrada y salida
#include<conio.h> //Incluye el getch para que el programa al ejecutarse no se cierre solo

//PROGRAMA PRINCIPAL
int main()
{
	int sueldo_base; //Almacena el sueldo base
	int sueldo_neto; //Almacena el sueldo neto
	
	//Repite las instrucciones hasta que se cumpla la condición 
	do
	{
		printf("Ingresa tu sueldo: "); //Pide el sueldo al usuario
	    scanf("%d",&sueldo_base); //Lee el sueldo 
	            
	    //Si el sueldo se encuentra entre 0 y 1000   
	  	if(sueldo_base >= 0 &&sueldo_base <= 1000) 
	    {
	      sueldo_neto = sueldo_base - sueldo_base*0.05; //Operación para obtener el sueldo neto con 5%
    	}
    	else
	       if(sueldo_base >= 1001 && sueldo_base <= 5000) //Si el sueldo se encuentra entre 1001 y 5000
	       {
	   	     sueldo_neto = sueldo_base - sueldo_base*0.15; //Operación para obtener el sueldo neto con 15%
	       }
	       else  //Si el sueldo es superior a 5000
	       {			
		     sueldo_neto = sueldo_base - sueldo_base*0.30; //Operación para obtener el sueldo neto con 30%				
		   }
	}while(!(sueldo_base >= 0)); //Finaliza el ciclo 
	
	//Se imprime el sueldo neto	
    printf("Tu sueldo neto es: %d",sueldo_neto);
    
    printf("\n\n");
    getch();
}
