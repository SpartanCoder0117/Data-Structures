/*
AUTOR: Josue Macias Castillo; Daniel Aguilar Gonzales; Agustin Galindo Reyes (C) Septiembre 2016
VERSION: 1.7

DESCRIPCION: Ejemplo de la aplicacion de la pila, el cual resuelve el problema de las evaluaciones de los parentesis ademas de convertir
una expresion de infijo a posfijo y evaluarla.

OBSERVACIONES: El programa requerira de la libreria "TADPilaEst.h", la cuÃ¡l tiene las implementaciones 
para hacer uso de las funciones del TAD Pila

COMPILACION: 	gcc -o Practica01.c TADPila(Din|Est).o Practica_1.exe (Si se tiene el objeto de la implementacion)
				gcc -o Practica01.c TADPila(Din|Est).c Practica_1.exe (Si se tiene el fuente de la implementacion)

EJECUCION: Practica01.exe (En Windows) - ./Practica01.exe (En Linux)
*/

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>	//Para usar exit()
#include <string.h> //Para usar strlen()
#include <math.h>
#include "TADPilaEst.h" //Inclusion de la libreria del TAD Pila Estatica (Si se desea usar una pila estatica)
//#include "TADPilaDin.h" //Inclusion de la libreria del TAD Pila Dinamica (Si se desea usar una pila dinamica)

//Tamaño maximo de la cadena
#define TAM_CAD 100
//Limpia la pantalla
#define Limpiar system("cls");

//DECLARACIÓN DE FUNCIONES
/*Procedimiento para capturar la expresion infija
(Recibe la referencia a la cadena infija)*/
int Capturar(char *infija);
/*Procedimiento para validar los parentesis de la expresion infija
(Recibe la referencia a la cadena infija)*/
int Valida(char *infija);
/*Procedimiento para convertir la expresion infija a posfija
(Recibe la referencia a la cadena infija y la posfija)*/
int Conversion(char *infija, char *posfija);
/*Procedimiento para hacer la evaluacion de la expresion posfija
(Recibe la referencia a la cadena posfija)*/
int Evalua(char *posfija);


//PROGRAMA PRINCIPAL
void main(void)
{
	char exp_infija[TAM_CAD];
	char exp_posfija[TAM_CAD];
	int op;

	do
	{
		//Despliega las opciones para operar con el programa
		op = 0;
		printf("\nElige una opcion:\n");
		printf("\n1.- Validacion de la expresion");
		printf("\n2.- Conversion de la expresion");
		printf("\n3.- Evaluacion de la expresion");
		printf("\n4.- Salir");
		fflush(stdin);
		printf("\nIngrese la opcion que desea:[   ]\b\b\b");
		scanf("%d",&op);
		Limpiar;
		
		switch(op)
		{
			case 1:
				Capturar(exp_infija);
				break;
			case 2:
			    Conversion(exp_infija,exp_posfija);
				break;
			case 3:
				Evalua(exp_posfija);
			    break;
			default:
				break;    
		}
	}while(op!=4);	
	
	exit(0);
}

/*
int Capturar(char *infija);
Descripción: Procedimiento para capturar por medio de la entrada estandar la expresion infija
Recibe: char *infija (Referencia a la cadena infija)
Devuelve: Expresion infija
Observaciones: 
*/
int Capturar(char *infija)
{
	do
	{
		printf("El programa solo acepta letras en mayuscula\n");
		printf("ingresa la expresion: ");
		scanf("%s",infija);
		
	}while(Valida(infija)==(-1));
	
	printf("\n");
	system("pause");
	Limpiar;	
	return 0;
}

/*
int Valida(char *infija);
Descripción: Procedimiento para validar los parentesis de la expresion infija por medio de la entrada estandar 
Recibe: char *infija (Referencia a la cadena infija)
Devuelve: 
Observaciones: Si la pila se modifica, también se modificará esta función
*/
int Valida(char *infija)
{
	int tam_cadena;
	int i;
	
	//Se declara una pila 
	pila p;
	//Se declara un elemento e
	elemento e;
	//Se inicializa la pila
	Initialize(&p);
	
	//Mide el tamaño de la cadena
	tam_cadena = strlen(infija);
	//Recorre cada caracter de la cadena
	for(i=0;i<tam_cadena;i++)
	{
		if(infija[i]=='(')
		{
			e.c = '(';
			Push(&p,e);
		}
		//Si el caracter es ) realiza un pop a la pila
		else if(infija[i]==')')
		{
			//Si se intenta extraer un elemento y la pila es vacia
			if(Empty(&p))
			{
				printf("ERROR: Existen mas parentesis de cierre que de apertura");
				//Salir del programa con error
				exit(1); 
			}
			e = Pop(&p);
		}
	}
	//Si al terminar de revisar la expresion aun hay elementos en la pila 
	if(!Empty(&p))
	{
		printf("ERROR: Existen mas parentesis de apertura que de cierre ");
		
		exit(1);
	}
	//Si la ejecucion es correcta
	printf("EXCELENTE: Expresion correcta");
	
	//Destruir elementos de la pila
	Destroy(&p);
	//Termina el programa sin errores
	return 0;
}

/*
int Conversion(char *infija, char *posfija);
Descripción: Procedimiento para convertir la expresion infija a posfija por medio de la entrada estandar 
Recibe: char *infija (Referencia a la cadena infija), char *posfija (Referencia a la cadena posfija)
Devuelve: La expresion en posfijo
Observaciones: Si la pila se modifica, también se modificará esta función
*/
int Conversion(char *infija, char *posfija)
{
	int tam_cadena;
	int i,j=0,k;
	
	if(infija[0] !='\0')
	{
		//Se declara una pila
		pila p;
		//Se declaran un elemento
		elemento e;
		//Se inicializa la pila
		Initialize(&p);
		
		//Mide el tamaño de la cadena
		tam_cadena = strlen(infija);
		
		printf("Expresion en posfijo: ");
		
		//Recorrer cada caracter de la cadena
		for(i=0;i<tam_cadena;i++)
		{
			//Si el caracter es ( introducirlo a la pila
			if(infija[i]=='(')
			{
				e.c = '(';
				Push(&p,e);
			}
			//Si el caracter es ) realizar pop a la pila
			if(infija[i]==')')
			{
				for(k=0;k<TAM_CAD;k++)
				{
					e = Pop(&p);
					if(e.c == '+' || e.c == '-' || e.c == '*' || e.c == '/' || e.c == '^')
					{
						strcpy(&posfija[j],&e.c);
						j++;
					}
					else if(e.c == '(')
					        k = TAM_CAD;					
				}	
			}
			//Si la cadena esta entre los intervalos de la "A" a la "Z"
			if(infija[i] >= 'A' && infija[i] <= 'Z')
			{
				strcpy(&posfija[j],&infija[i]);
				j++;
			}
			//Si el operador es "+" devuelve el operador que esta encima de la pila
			if(infija[i]=='+')
			{
				//Se verifica si la pila esta vacia
				if(!Empty(&p))
				{
					for(k=0;k<TAM_CAD;k++)
					{
						e = Top(&p);
						//Si el operador es de mayor prioridad se hace un pop
						if(e.c == '+' || e.c == '-' || e.c == '*' || e.c == '/' || e.c == '^')
						{
							e = Pop(&p);
							strcpy(&posfija[j],&e.c);
							j++;
						}
						//Si el caracter es ( o la pila no esta vacia devuelve el tamaño de la cadena
						if(e.c=='(' || Empty(&p)==TRUE)
							k = TAM_CAD;						
					}
					e.c = '+';
					Push(&p,e);
				}
				if(Empty(&p))
				{
					e.c = '+';
					Push(&p,e);
				}
			}
			//Si el operador es "-" devuelve el operador que esta encima de la pila
			if(infija[i]=='-')
			{
				//Se verifica si la pila esta vacia
				if(!Empty(&p))
				{
					for(k=0;k<TAM_CAD;k++)
					{
						e = Top(&p);
						//Si el operador es de mayor precedencia que "-" se hace pop en la pila
						if(e.c == '-' || e.c == '*' || e.c == '/' || e.c == '^')
						{
							e = Pop(&p);
							strcpy(&posfija[j],&e.c);
							j++;
						}
						//Si son de menor precedencia solo se ingresa el "-"
						if(e.c=='(' || e.c == '+' || Empty(&p) == TRUE)
							k = TAM_CAD;
					}
					e.c = '-';
					Push(&p,e);
				}
				if(Empty(&p))
				{
					e.c = '-';
					Push(&p,e);
				}
			}
			//Si el operador es "*" devuelve el operador que esta encima de la pila
			if(infija[i]=='*')
			{
				//Se verifica si la pila esta vacia 
				if(!Empty(&p))
				{
					for(k=0;k<TAM_CAD;k++)
					{
						e = Top(&p);
				    	//Si los elementos igual o mayor precedencia
						if(e.c == '*' || e.c == '/' || e.c == '^')
						{
							e = Pop(&p);
							strcpy(&posfija[j],&e.c);
							j++;						
						} 
						//Si el elemento es diferente se ingresa el "*"
						if(e.c == '(' || e.c == '+' || e.c == '-' || Empty(&p) == TRUE)
							k = TAM_CAD;
					}
					e.c = '*';
					Push(&p,e);
				}
				//Si la pila esta vacia solo se devuelve el operando
				if(Empty(&p))
				{
					e.c = '*';
					Push(&p,e);
				}
			}
			//Si el operador es "/" devuelve el operador que esta encima de la pila
			if(infija[i]=='/')
			{
				//Se verifica si la pila esta vacia 
				if(!Empty(&p))
				{
					//Recorrido de la cadena para encontrar operandos de mayor precedencia 
					for(k=0;k<TAM_CAD;k++)
					{
						e = Top(&p);
						//Si son de mayor o igual precedencia se saca el elemento
						if(e.c == '/' || e.c == '^')
						{
							e = Pop(&p);
							strcpy(&posfija[j],&e.c);
							j++;
						}
						//Si es de menor precedencia se queda en la pila el operador de mayor precedencia.
						if(e.c == '(' || e.c == '+' || e.c == '-' || e.c == '*' || Empty(&p) == TRUE)
							k = TAM_CAD;
					}
					e.c = '/';
					Push(&p,e);
				}
				//Si solo hay un operando se devuelve el mismo
				if(Empty(&p))
				{
					e.c = '/';
					Push(&p,e);
				}
			}
			//Si el operador es "^" devuelve el operador que esta encima de la pila
			else if(infija[i]=='^')
			{
				//Se verifica si la pila esta vacia 
				if(!Empty(&p))
				{
					for(k=0;k<TAM_CAD;k++)
					{
						e = Top(&p);
						//Si "^" es igual a su mismo operador
						if(e.c == '^')
						{
							e = Pop(&p);
							strcpy(&posfija[j],&e.c);
							j++;							
						}
						//Si es de menor precedencia se ingresa a la pila "^"
						if(e.c == '(' || e.c == '+' || e.c == '-' || e.c == '*' || e.c == '/' || Empty(&p) == TRUE)
							k = TAM_CAD;	
					}
					e.c = '^';
					Push(&p,e);
				}
				//Si es el unico operando se devuelve el mismo
				if(Empty(&p))
				{
					e.c = '^';
					Push(&p,e); 
				}
			}
		}
		if(!Empty(&p))
		{
			k = Value_Top(&p) + 1;
			for(i=0;i<k;i++)
			{
				e = Pop(&p);
				strcpy(&posfija[j],&e.c);
				j++;
			}
		}
		//Destruir los elementos de la pila 
		Destroy(&p);
		for(i=0;i<j;i++)
			printf("%c",posfija[i]);
		printf("\n");		
	}
	else 
		printf("Aun no se ha capturado una expresion.\n");
	fflush(stdin);
	system("pause");
	Limpiar;
	return 0;
}

/*
int Evalua(char *posfija);
Descripción: Procedimiento para evaluar la expresion posfija por medio de la entrada estandar 
Recibe: char *posfija (Referencia a la cadena posfija)
Devuelve: La evaluacion de la cadena posfija
Observaciones: Si la pila se modifica, también se modificará esta función
*/
int Evalua(char *posfija)
{
	int tam_cadena;
	int i,j,k,var1,var2,res;
	char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char exp_ev[26];
	char pos_ev[TAM_CAD];
	
	//Si la posicion 0 de la cadena es diferente de nulo
	if(posfija[0] != '\0')
	{
		//Se declara la pila
		pila p;
		//Se declaran tres elementos
		elemento e,e2,e3;
		//Inicializamos la pila
		Initialize(&p);
		//Se mide el tamaño de la cadena
		tam_cadena = strlen(posfija);
		
		//Un recorrido de la exp_ev de tamaño 26 (tamaño del abecedario en mayusculas)
		for(i=0;i<26;i++)
			exp_ev[i] = '\0';
		
		printf("Asignacion de valores:\n");
		
		//Asignacion de valores a las letras correspondientes
		for(i=0;i<tam_cadena;i++)
		{
			if(posfija[i] >= 'A' && posfija[i] <= 'Z')
			{
				for(j=0;j<26;j++)
				{
					if(letras[j] == posfija[i] && exp_ev[j] == '\0')
					{
						printf("\nIngresa el valor de %c (Solo un digito): ",letras[j]);
						scanf("%s",&exp_ev[j]);						
					}
				}
			}	
		}
		//Recorrido de la cadena 
		for(i=0;i<tam_cadena;i++)
		{
			//Si esta en el intervalo de 'A' a la 'Z' 
			if(posfija[i] >= 'A' && posfija[i] <= 'Z')
			{
				for(j=0;j<26;j++)
				{
					//Si alguna letra es encontrada, se copia en la posicion 0 de letras[j]
					if(letras[j]==posfija[i])
					{
						strcpy(&pos_ev[i],&exp_ev[j]);
					}
				}
			}
			else 
				strcpy(&pos_ev[i],&posfija[i]);
		}
		//Mientras pos_ev sea diferente de nulo
		i = 0;
		while(pos_ev[i] != '\0')
		{
			//Si la evaluacion tiene un rango de numeros ingresados del 0 al 9
			if(pos_ev[i] >= '0' && pos_ev[i] <= '9')
			{
				//Lo que se almacena en pos_ev se le quita el '0' en ASCII
				e.d = pos_ev[i] - '0';
				Push(&p,e);
			}
			else switch(pos_ev[i])
			{
					//caso que  si el operando es "+" hay dos elementos de caracter entero que se van a sumar.
                case '+': 
					  e = Pop(&p);
                      e2= Pop(&p);
					  res = e2.d + e.d;
                      e2.d = res;
					  Push(&p,e2);
                      break;

                //caso que  si el operando es "-" hay dos elementos de caracter entero que se van a restar.
				case '-' :
				      e = Pop(&p);
                      e2= Pop(&p);
					  res = e2.d - e.d;
                      e2.d = res;
					  Push(&p,e2);
                       break;

                //caso que  si el operando es "*" hay dos elementos de caracter entero que se van a multiplicar.
				case '*' : 
					  e = Pop(&p);
                      e2= Pop(&p);
					  res = e2.d * e.d;
                      e2.d = res;
					  Push(&p,e2);
                       break;

                //caso que  si el operando es "/" hay dos elementos de caracter entero que se van a dividir.
				case '/' : 
					  e = Pop(&p);
                      e2= Pop(&p);
					  res = e2.d / e.d;
                      e2.d = res;
					  Push(&p,e2);
                       break;

                //caso que  si el operando es "^" hay dos elementos de caracter entero que se le aplica la potecia de uno.
				case '^' : 
					  e = Pop(&p);
                      e2= Pop(&p);
					  e3.d = 1;
					  //Sumatoria de las multiplicaciones de elemento 3 
					  for(j=0;j<e.d;j++)	
					  	e3.d = e3.d * e2.d;
					  Push(&p,e3);
                      break;
			}
			i++;
		}
		e2 = Pop(&p);
		printf("\n\nEl resultado de la expresion es %i \n", e2.d);			
	}	
	//Si no se ha ingresado nada muestra un mensaje
	else
		printf("Aun no se ha evaluado una expresion en posfijo \n");
	system("pause");
	Limpiar;
	return 0;	
}

