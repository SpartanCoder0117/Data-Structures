//Librerias
#include <stdio.h>
#include "TADColaBanco.h"
#include <stdio.h>
#include <windows.h>
#define TIEMPO_BASE 300
#define TIEMPO_CLIENTE 20
#define TIEMPO_ATENCION 30
#define TIEMPO_USUARIO 50
#define TIEMPO_PREFERENTES 45

void AltEnter(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    return;
    }

void cliente_entra(int x, int y){
    elemento e;
    MoverCursor(x,y+8);
    printf("Cliente\n");
    }

void cliente_preferente(int x, int y){
    MoverCursor(x,y+8);
    printf("Preferente\n");
    }

void usuario(int x, int y){
    MoverCursor(x,y+2);
    printf("usuario\n");
    }

void borrar_cliente(int x, int y){
    MoverCursor(x,y+8);
	printf("        \n");
    }

void cliente(int num_cajas){
    int fila,acu, x=4, y=10, cierre=0, cierre1=0, x1=19, y1=10, x2=34, y2=10, i;
    int z=10, x3=49 ,y3=10, x4=64, y4=10, x5=79, y5=10, x6=94, y6=10, x7=109, y7=10; 
    unsigned int tiempo = 0;
    unsigned int personas = 0;
    unsigned int preferentes = 0;
    elemento e;
    //Inicializar la función rand
	srand(time(NULL));    
	//Creacion de colas
	cola caja[10];
	//Inicializar ambas colas
	Initialize(&caja[0]);
	Initialize(&caja[1]);
	Initialize(&caja[2]);
    Initialize(&caja[3]);
    Initialize(&caja[4]);
    Initialize(&caja[5]);
    Initialize(&caja[6]);
    Initialize(&caja[7]);
    Initialize(&caja[8]);
    Initialize(&caja[9]);
    while (1){
        Sleep(TIEMPO_BASE);		//Esperar el tiempo base
		tiempo++;	//Incrementar el contador de tiempo	
		         //Numero de cajas disponibles 1
        if( num_cajas==1 ){
                      MoverCursor(70,8);
                      printf(" Clientes atendidos %d ",cierre);
                      MoverCursor(2,3);
		              printf("%d en caja 0",Size(&caja[0]));
                      MoverCursor(15,8);
                      printf(" Clientes preferentes atendidos %d ",cierre1);
                            //Si la cola esta vacia se quita el mensaje de "No hay nadie en la fila"
                      if(Size(&caja[0])>0){
                                  MoverCursor(2,5);
                                  printf("                        ");                          
                                  }
                      
                      if (tiempo % TIEMPO_ATENCION == 0){
			                //Caja 0
			                 if (!Empty(&caja[0])){         
				                     e = Dequeue(&caja[0]);
                                     MoverCursor(2,4);
			                         printf("Atendi:%d caja 0\n", e.n);
                                     y = y-2;
                                     borrar_cliente(x,y);
                                     printf("Atendi:%d caja 0\n", e.pref);
                                     z = z-2;
                                     borrar_cliente(x,z);
                                     cierre++;
                                     cierre1++;
                                     }
                             printf("                  ");
                             if(Empty(&caja[0])){
                                     MoverCursor(2,5);
				                     printf("No hay nadie");}			
                                     }
                       
                       if (tiempo % TIEMPO_CLIENTE == 0)
               	       {
                   	         personas++;				//Incrementar el numero de clientes
			                 e.n = personas;			//Dar el numero que identifica al cliente
                             e.pref = preferentes;      //Dar el numero que identifica al cliente preferente
                             fila = rand()%1;       	//Escoger la fila para formarse aleatoriamente					
		                     acu = rand()%1;
                             Queue(&caja[fila],e);      //Formarse en la fila seleccionada
                             Queue(&caja[acu],e);      //Formarse en la fila seleccionada
                             MoverCursor(27,1);  
			                 if(fila==0)
                             {   
                                     cliente_entra(x,y);
		                             y=y+2;         
			                 }
			                 if(acu==0)
                             {   
                                     cliente_preferente(x,z);
		                             z=z+2;         
			                 }
                        }	
        }
		
          //Numero de cajas disponibles 2
        if( num_cajas==2 )
        {
                      MoverCursor(22,6);
                      printf("Clientes atendidos %d ",cierre);
        	             	//Mostrar el número de clientes en cada cola
                      MoverCursor(2,3);
		              printf("%d en caja 0",Size(&caja[0]));
		              
	                  MoverCursor(20,3);
	                  printf("%d en caja 1",Size(&caja[1]));
	                     //Tamaño Caja 2
                      if(Size(&caja[0])>0){
                             MoverCursor(2,5);
                             printf("                        ");}
                         //Tamaño Caja 1
                      if(Size(&caja[1])>0)
                      {
			             	 MoverCursor(20,5);
				             printf("                        ");
                      }	
		              
                      if (tiempo % TIEMPO_ATENCION == 0)
                      {
			                //Caja 0
			                 if (!Empty(&caja[0]))
                             {
				                     e = Dequeue(&caja[0]);
				                     MoverCursor(2,4);
			                         printf("Atendi:%d caja 0", e.n);
                                     y=y-2;
                                     borrar_cliente(x,y);
				                     cierre++;
                             }
                             MoverCursor(2,5);
                             printf("                  ");
			                 if(Empty(&caja[0]))
                             {
                                     MoverCursor(2,5);
				                     printf("No hay nadie");
                             }
                       }  
                       
                       if (tiempo % TIEMPO_ATENCION == 0)
                       {
                              //Cajera 1
			                 if (!Empty(&caja[1]))
                             {
				                     e = Dequeue(&caja[1]);
				                     MoverCursor(20,4);
				                     printf("Atendi:%d caja 1", e.n);
                                     y1=y1-2;
                                     borrar_cliente(x1,y1);
				                     cierre++;
                             }
                             MoverCursor(27,5);
                             printf("                        ");
			                 if(Empty(&caja[1]))
                             {
                                     MoverCursor(20,5);
				                     printf("No hay nadie");
                             }
                        }
		
                        if (tiempo % TIEMPO_CLIENTE == 0)
                        {
                              personas++;				//Incrementar el numero de clientes
			                  e.n = personas;			//Dar el numero que identifica al cliente
			                  fila=rand()%2;			//Escoger la fila para formarse aleatoriamente					
			                  Queue(&caja[fila],e);     //Formarse en la fila seleccionada
			                  MoverCursor(27,1);
			                  if(fila==0)
                              {
                                     cliente_entra(x,y);
                                     y=y+2;
			                  }
			                  if(fila==1)
		 	                  {
			                         cliente_entra(x1,y1);
			                         y1=y1+2;
			                  }
                         }                 
        }
        
             //Numero de cajas disponibles 3
        if(num_cajas==3)
        {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(20,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(35,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                       //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(20,5);
				               printf("                ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(34,5);
				               printf("                ");
                         }	
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Caja 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(20,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(20,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(20,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(35,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
	                            MoverCursor(35,5);
                                printf("                        ");
			                    if(Empty(&caja[2]))
			                    {
			                          MoverCursor(35,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		
		
                           if (tiempo % TIEMPO_CLIENTE == 0)
                           {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%3;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
                                if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
                           }
           }
           
           //Numero de cajas disponibles 4
           if(num_cajas==4)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(20,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(35,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(50,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                       //Tamaño Caja 0
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                        ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(20,5);
				               printf("                        ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(35,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(50,5);
				               printf("                        ");
                         }	
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 1
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);                             
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 2
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(20,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
			                   MoverCursor(20,5);
			                   printf("                        ");
                               if(Empty(&caja[1]))
                               {
                                       MoverCursor(20,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(35,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
		                        MoverCursor(35,5);
		                        printf("                        ");
			                    if(Empty(&caja[2]))
			                    {
			                          MoverCursor(35,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(50,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
	                            MoverCursor(50,5);
                                printf("                        ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(50,5);
			  	                      printf("No hay nadie");
			                    }
	                      }
		
                          if (tiempo % TIEMPO_CLIENTE == 0)
                          {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%4;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
                           }
           }
           
           if(num_cajas==5)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(20,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(35,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(50,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                     
                         MoverCursor(65,3);
	                     printf("%d en caja 4",Size(&caja[4]));
	                     
                           //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                        ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(20,5);
				               printf("                        ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(35,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(50,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[4])>0)
                         {
			             	   MoverCursor(65,5);
				               printf("                        ");
                         }	
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(20,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(20,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(20,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 2
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(35,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
                                MoverCursor(35,5);
                                printf("                        ");
			                    if(Empty(&caja[2]))
			                    {
			                          MoverCursor(35,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(50,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
		                        MoverCursor(50,5);
	                            printf("                        ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(50,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[4]))
			                    { 
                                      e = Dequeue(&caja[4]);
				                      MoverCursor(65,4);
				                      printf("Atendi:%d caja 4", e.n);
				                      y4=y4-2;
		                              borrar_cliente(x4,y4);
				                      cierre++;		
		                        }
                                MoverCursor(65,5);
	                            printf("                        ");
			                    if(Empty(&caja[4]))
			                    {
			                          MoverCursor(65,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		
		
                          if (tiempo % TIEMPO_CLIENTE == 0)
                          {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%5;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
			                    if(fila==4)
		 	                    {
			                           cliente_entra(x4,y4);
			                           y4=y4+2;
			                    }
                           }
           }
           
           
           if(num_cajas==6)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(20,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(35,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(50,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                     
                         MoverCursor(65,3);
	                     printf("%d en caja 4",Size(&caja[4]));
	                     
	                     MoverCursor(80,3);
	                     printf("%d en caja 5",Size(&caja[5]));
	                     
                           //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                        ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(20,5);
				               printf("                        ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(35,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(50,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[4])>0)
                         {
			             	   MoverCursor(65,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[5])>0)
                         {
			             	   MoverCursor(80,5);
				               printf("                        ");
                         }	
                         
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(20,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(20,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(20,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 2
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(35,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
		                        MoverCursor(35,5);
                                printf("                        ");
		                        if(Empty(&caja[2]))
			                    {
			                          MoverCursor(35,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(50,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
		                        MoverCursor(50,5);
	                            printf("                        ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(50,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[4]))
			                    { 
                                      e = Dequeue(&caja[4]);
				                      MoverCursor(65,4);
				                      printf("Atendi:%d caja 4", e.n);
                                      y4=y4-2;
                                      borrar_cliente(x4,y4);
				                      cierre++;		
		                        }
                                MoverCursor(65,5);
	                            printf("                        ");
			                    if(Empty(&caja[4]))
			                    {
			                          MoverCursor(65,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
                           if (tiempo % TIEMPO_ATENCION == 0)
	                       {
		                        //Caja 5
			                    if (!Empty(&caja[5]))
			                    { 
                                      e = Dequeue(&caja[5]);
				                      MoverCursor(80,4);
				                      printf("Atendi:%d caja 5", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(80,5);
	                            printf("                        ");
			                    if(Empty(&caja[5]))
			                    {
			                          MoverCursor(80,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                          
                            if (tiempo % TIEMPO_CLIENTE == 0)
                            {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%6;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
			                    if(fila==4)
		 	                    {
			                           cliente_entra(x4,y4);
			                           y4=y4+2;
			                    }
			                    if(fila==5)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
                           }
           }
           
           if(num_cajas==7)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(20,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(35,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(50,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                     
                         MoverCursor(65,3);
	                     printf("%d en caja 4",Size(&caja[4]));
	                     
	                     MoverCursor(80,3);
	                     printf("%d en caja 5",Size(&caja[5]));
	                     
                         MoverCursor(95,3);
	                     printf("%d en caja 6",Size(&caja[6]));
	                     
                           //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                  ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(20,5);
				               printf("                  ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(35,5);
				               printf("                  ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(50,5);
				               printf("                  ");
                         }	
                         if(Size(&caja[4])>0)
                         {
			             	   MoverCursor(65,5);
				               printf("                  ");
                         }	
                         if(Size(&caja[5])>0)
                         {
			             	   MoverCursor(80,5);
				               printf("                  ");
                         }	
                         if(Size(&caja[6])>0)
                         {
			             	   MoverCursor(95,5);
				               printf("                  ");
                         }	
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(20,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(20,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(20,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 2
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(35,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
		                        MoverCursor(35,5);
                                printf("                        ");
		                        if(Empty(&caja[2]))
			                    {
			                          MoverCursor(35,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(50,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
		                        MoverCursor(50,5);
	                            printf("                    ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(50,5);
			  	                      printf("No hay nadie ");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[4]))
			                    { 
                                      e = Dequeue(&caja[4]);
				                      MoverCursor(65,4);
				                      printf("Atendi:%d caja 4", e.n);
                                      y4=y4-2;
                                      borrar_cliente(x4,y4);
				                      cierre++;		
		                        }
                                MoverCursor(65,5);
	                            printf("                    ");
			                    if(Empty(&caja[4]))
			                    {
			                          MoverCursor(65,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
                           if (tiempo % TIEMPO_ATENCION == 0)
	                       {
		                        //Caja 5
			                    if (!Empty(&caja[5]))
			                    { 
                                      e = Dequeue(&caja[5]);
				                      MoverCursor(80,4);
				                      printf("Atendi:%d caja 5", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(80,5);
	                            printf("                        ");
			                    if(Empty(&caja[5]))
			                    {
			                          MoverCursor(80,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 6
			                    if (!Empty(&caja[6]))
			                    { 
                                      e = Dequeue(&caja[6]);
				                      MoverCursor(95,4);
				                      printf("Atendi:%d caja 6", e.n);
                                      y6=y6-2;
                                      borrar_cliente(x6,y6);
				                      cierre++;		
		                        }
                                MoverCursor(95,5);
	                            printf("                        ");
			                    if(Empty(&caja[6]))
			                    {
			                          MoverCursor(95,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                          
                            if (tiempo % TIEMPO_CLIENTE == 0)
                            {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%7;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
			                    if(fila==4)
		 	                    {
			                           cliente_entra(x4,y4);
			                           y4=y4+2;
			                    }
			                    if(fila==5)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
			                    if(fila==6)
		 	                    {
			                           cliente_entra(x6,y6);
			                           y6=y6+2;
			                    }
                           }
           }
           
           if(num_cajas==8)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(27,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(49,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(60,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                     
                         MoverCursor(75,3);
	                     printf("%d en caja 4",Size(&caja[4]));
	                     
                         MoverCursor(105,3);
	                     printf("%d en caja 5",Size(&caja[5]));
	                     
	                     MoverCursor(115,3);
	                     printf("%d en caja 6",Size(&caja[6]));
	                     
	                     MoverCursor(115,3);
	                     printf("%d en caja 7",Size(&caja[7]));
	                     
                           //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                        ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(27,5);
				               printf("                        ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(49,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(60,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[4])>0)
                         {
			             	   MoverCursor(75,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[5])>0)
                         {
			             	   MoverCursor(105,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[6])>0)
                         {
			             	   MoverCursor(115,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[7])>0)
                         {
			             	   MoverCursor(130,5);
				               printf("                        ");
                         }	
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(27,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(27,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(27,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 2
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(53,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
		                        MoverCursor(53,5);
                                printf("                        ");
		                        if(Empty(&caja[2]))
			                    {
			                          MoverCursor(53,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(70,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
		                        MoverCursor(70,5);
	                            printf("                        ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(70,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[4]))
			                    { 
                                      e = Dequeue(&caja[4]);
				                      MoverCursor(85,4);
				                      printf("Atendi:%d caja 4", e.n);
                                      y4=y4-2;
                                      borrar_cliente(x4,y4);
				                      cierre++;		
		                        }
                                MoverCursor(85,5);
	                            printf("                        ");
			                    if(Empty(&caja[4]))
			                    {
			                          MoverCursor(85,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
                           if (tiempo % TIEMPO_ATENCION == 0)
	                       {
		                        //Caja 5
			                    if (!Empty(&caja[5]))
			                    { 
                                      e = Dequeue(&caja[5]);
				                      MoverCursor(105,4);
				                      printf("Atendi:%d caja 5", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(105,5);
	                            printf("                        ");
			                    if(Empty(&caja[5]))
			                    {
			                          MoverCursor(105,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 6
			                    if (!Empty(&caja[6]))
			                    { 
                                      e = Dequeue(&caja[6]);
				                      MoverCursor(115,4);
				                      printf("Atendi:%d caja 6", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(105,5);
	                            printf("                        ");
			                    if(Empty(&caja[6]))
			                    {
			                          MoverCursor(115,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                           
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 7
			                    if (!Empty(&caja[7]))
			                    { 
                                      e = Dequeue(&caja[7]);
				                      MoverCursor(130,4);
				                      printf("Atendi:%d caja 7", e.n);
                                      y6=y6-2;
                                      borrar_cliente(x6,y6);
				                      cierre++;		
		                        }
                                MoverCursor(130,5);
	                            printf("                        ");
			                    if(Empty(&caja[7]))
			                    {
			                          MoverCursor(130,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                          
                            if (tiempo % TIEMPO_CLIENTE == 0)
                            {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%8;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
			                    if(fila==4)
		 	                    {
			                           cliente_entra(x4,y4);
			                           y4=y4+2;
			                    }
			                    if(fila==5)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
			                    if(fila==6)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
			                    if(fila==7)
		 	                    {
			                           cliente_entra(x6,y6);
			                           y6=y6+2;
			                    }
                           }
           }
           
           if(num_cajas==9)
           {
                         MoverCursor(22,6);
                         printf(" Clientes atendidos %d ",cierre);
		                       //Mostrar el número de clientes en cada cola
                         MoverCursor(2,3);
		                 printf("%d en caja 0",Size(&caja[0]));
		              
	                     MoverCursor(27,3);
	                     printf("%d en caja 1",Size(&caja[1]));
	                     
                         MoverCursor(49,3);
	                     printf("%d en caja 2",Size(&caja[2]));
	                     
                         MoverCursor(60,3);
	                     printf("%d en caja 3",Size(&caja[3]));
	                     
                         MoverCursor(75,3);
	                     printf("%d en caja 4",Size(&caja[4]));
	                     
                         MoverCursor(105,3);
	                     printf("%d en caja 5",Size(&caja[5]));
	                     
	                     MoverCursor(115,3);
	                     printf("%d en caja 6",Size(&caja[6]));
	                     
	                     MoverCursor(130,3);
	                     printf("%d en caja 7",Size(&caja[7]));
	                     
	                     MoverCursor(145,3);
	                     printf("%d en caja 8",Size(&caja[8]));
	                     
                           //Tamaño Caja 2
                         if(Size(&caja[0])>0)
                         {
                               MoverCursor(2,5);
                               printf("                        ");
                         }
                           //Tamaño Caja 1
                         if(Size(&caja[1])>0)
                         {
			             	   MoverCursor(27,5);
				               printf("                        ");
                         }	
		                 if(Size(&caja[2])>0)
                         {
			             	   MoverCursor(49,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[3])>0)
                         {
			             	   MoverCursor(60,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[4])>0)
                         {
			             	   MoverCursor(75,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[5])>0)
                         {
			             	   MoverCursor(105,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[6])>0)
                         {
			             	   MoverCursor(115,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[7])>0)
                         {
			             	   MoverCursor(130,5);
				               printf("                        ");
                         }	
                         if(Size(&caja[8])>0)
                         {
			             	   MoverCursor(130,5);
				               printf("                        ");
                         }	
                         
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
			                      //Caja 0
			                   if (!Empty(&caja[0]))
                               {
				                       e = Dequeue(&caja[0]);
				                       MoverCursor(2,4);
			                           printf("Atendi:%d caja 0", e.n);
                                       y=y-2;
                                       borrar_cliente(x,y);
				                       cierre++;
                               }
                               MoverCursor(2,5);
                               printf("                        ");
			                   if(Empty(&caja[0]))
                               {
                                       MoverCursor(2,5);
				                       printf("No hay nadie");
                               }
                         }  
                       
                         if (tiempo % TIEMPO_ATENCION == 0)
                         {
                                //Cajera 1
			                   if (!Empty(&caja[1]))
                               {
				                       e = Dequeue(&caja[1]);
				                       MoverCursor(27,4);
				                       printf("Atendi:%d caja 1", e.n);
                                       y1=y1-2;
                                       borrar_cliente(x1,y1);
				                       cierre++;
                               }
                               MoverCursor(27,5);
                               printf("                        ");
			                   if(Empty(&caja[1]))
                               {
                                       MoverCursor(27,5);
				                       printf("No hay nadie");
                               }
                          }
		
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 2
			                    if (!Empty(&caja[2]))
			                    { 
                                      e = Dequeue(&caja[2]);
				                      MoverCursor(53,4);
				                      printf("Atendi:%d caja 2", e.n);
                                      y2=y2-2;
                                      borrar_cliente(x2,y2);
				                      cierre++;		
		                        }
		                        MoverCursor(53,5);
                                printf("                        ");
		                        if(Empty(&caja[2]))
			                    {
			                          MoverCursor(53,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 3
			                    if (!Empty(&caja[3]))
			                    { 
                                      e = Dequeue(&caja[3]);
				                      MoverCursor(70,4);
				                      printf("Atendi:%d caja 3", e.n);
                                      y3=y3-2;
                                      borrar_cliente(x3,y3);
				                      cierre++;		
		                        }
		                        MoverCursor(70,5);
	                            printf("                        ");
			                    if(Empty(&caja[3]))
			                    {
			                          MoverCursor(70,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
		                  
		                  if (tiempo % TIEMPO_ATENCION == 0)
	                      {
		                        //Caja 4
			                    if (!Empty(&caja[4]))
			                    { 
                                      e = Dequeue(&caja[4]);
				                      MoverCursor(85,4);
				                      printf("Atendi:%d caja 4", e.n);
                                      y4=y4-2;
                                      borrar_cliente(x4,y4);
				                      cierre++;		
		                        }
                                MoverCursor(85,5);
	                            printf("                        ");
			                    if(Empty(&caja[4]))
			                    {
			                          MoverCursor(85,5);
			  	                      printf("No hay nadie");
			                    }
		                   }
                           if (tiempo % TIEMPO_ATENCION == 0)
	                       {
		                        //Caja 5
			                    if (!Empty(&caja[5]))
			                    { 
                                      e = Dequeue(&caja[5]);
				                      MoverCursor(105,4);
				                      printf("Atendi:%d caja 5", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(105,5);
	                            printf("                        ");
			                    if(Empty(&caja[5]))
			                    {
			                          MoverCursor(105,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 6
			                    if (!Empty(&caja[6]))
			                    { 
                                      e = Dequeue(&caja[6]);
				                      MoverCursor(115,4);
				                      printf("Atendi:%d caja 6", e.n);
                                      y5=y5-2;
                                      borrar_cliente(x5,y5);
				                      cierre++;		
		                        }
                                MoverCursor(105,5);
	                            printf("                        ");
			                    if(Empty(&caja[6]))
			                    {
			                          MoverCursor(115,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                           
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 7
			                    if (!Empty(&caja[7]))
			                    { 
                                      e = Dequeue(&caja[7]);
				                      MoverCursor(130,4);
				                      printf("Atendi:%d caja 7", e.n);
                                      y6=y6-2;
                                      borrar_cliente(x6,y6);
				                      cierre++;		
		                        }
                                MoverCursor(130,5);
	                            printf("                        ");
			                    if(Empty(&caja[7]))
			                    {
			                          MoverCursor(130,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                          
                            if (tiempo % TIEMPO_ATENCION == 0)
	                        {
		                        //Caja 8
			                    if (!Empty(&caja[8]))
			                    { 
                                      e = Dequeue(&caja[8]);
				                      MoverCursor(145,4);
				                      printf("Atendi:%d caja 8", e.n);
                                      y7=y7-2;
                                      borrar_cliente(x7,y7);
				                      cierre++;		
		                        }
                                MoverCursor(130,5);
	                            printf("                        ");
			                    if(Empty(&caja[8]))
			                    {
			                          MoverCursor(130,5);
			  	                      printf("No hay nadie");
			                    }
		                    }
                          
                            if (tiempo % TIEMPO_CLIENTE == 0)
                            {
                                personas++;				//Incrementar el numero de clientes
			                    e.n = personas;			//Dar el numero que identifica al cliente
			                    fila=rand()%9;			//Escoger la fila para formarse aleatoriamente					
			                    Queue(&caja[fila],e);    //Formarse en la fila seleccionada
			                    MoverCursor(27,1);
			                    if(fila==0)
                                {
                                       cliente_entra(x,y);
                                       y=y+2;
			                    }
			                    if(fila==1)
		 	                    {
			                           cliente_entra(x1,y1);
			                           y1=y1+2;
			                    }
			                    if(fila==2)
		 	                    {
			                           cliente_entra(x2,y2);
			                           y2=y2+2;
			                    }
			                    if(fila==3)
		 	                    {
			                           cliente_entra(x3,y3);
			                           y3=y3+2;
			                    }
			                    if(fila==4)
		 	                    {
			                           cliente_entra(x4,y4);
			                           y4=y4+2;
			                    }
			                    if(fila==5)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
			                    if(fila==6)
		 	                    {
			                           cliente_entra(x5,y5);
			                           y5=y5+2;
			                    }
			                    if(fila==7)
		 	                    {
			                           cliente_entra(x6,y6);
			                           y6=y6+2;
			                    }
			                    if(fila==8)
		 	                    {
			                           cliente_entra(x7,y7);
			                           y7=y7+2;
			                    }
                           }
           }
      }        
}      
       
int graficos(void)
{
	int x,y;
	//Borrar la pantalla
	BorrarPantalla();
	//Recorrer cada columna
	for(x=0; x<=150; x++) 
	{ 
	//Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
			MoverCursor(x,0);
			printf("%c",205);
			MoverCursor(x,14);
			printf("%c",205);
			
            for(y=0; y<=50; y++) 
			{ 
			     MoverCursor(0,y);
			     printf("%c",186);  
			     MoverCursor(150,y);
			     printf("%c",186);
            }
	}
	
	MoverCursor(70,0);
	printf("BANCO\n");
	MoverCursor(4,16);
    printf("|_CAJA 1_|\n");	
	MoverCursor(19,16);
	printf("|_CAJA 2_|\n");	
	MoverCursor(34,16);
	printf("|_CAJA 3_|\n");
	MoverCursor(49,16);
	printf("|_CAJA 4_|\n");
	MoverCursor(64,16);
	printf("|_CAJA 5_|\n");
    MoverCursor(79,16);
	printf("|_CAJA 6_|\n");
	MoverCursor(94,16);
	printf("|_CAJA 7_|\n");
    MoverCursor(109,16);
	printf("|_CAJA 8_|\n");
	MoverCursor(124,16);
	printf("|_CAJA 9_|\n");	            
    Sleep(3000);
	MoverCursor(2,25);
	return 0;
}

int main()
{
    system("cls");
    int num_cajas;
    MoverCursor(25,25);
    printf("¿Cuantos cajas quieres que atiendan?: ");
    scanf("%d",&num_cajas);
    if(num_cajas>0 && num_cajas<10)
    {
         graficos();
         cliente(num_cajas);
    }
    if(num_cajas<0 && num_cajas>10)
    {
         printf("Lo siento solo hay cajas del 1 al 9");
    }
}
