/*UNIVERSIDAD DEL VALLE DE GUATEMALA
 *ALGORITMOS Y ESTRUCTURAS DE DATOS
 *LYNETTE GARCIA 
 *
 *PROYECTO ADT, LABERINTO 
 *ALGORITMO DE LA MANO DERECHA
 *
 *INTEGRANTES: 
 *-Paulina Cano 15053
 *-Andres Giron 15174
 *-Brandon Hernandez 15326 
 *-Marlon Hernandez 15177
 */



//Librerias utilizadas
#include "simpletools.h"                     
#include "ping.h"                             
#include "abdrive.h"


//Variables a Utilizar 
int frente;                                 
int derecha;
int cont;


#define capacity 100

//Stacks 
struct Stack{
	int top;	
	int data[capacity];
} stack;

void push(int value){
	stack.top++;
	stack.data[stack.top] = value;
}

int pop(){
	int value;
	value = stack.data[stack.top];
	stack.top--;
	return (value);
}


//Main
int main()                   
{
  cont=0;
  //Ciclo Infinito 
  while(1)                                   
  {
    
    //Indicacion de los pines a utilizar
    frente= ping_cm(8);                    
    derecha = ping_cm(9);
    
    //Si se detecta pared a la derecha
    if(derecha<25){
      //Si se detecta pared a la derecha y pared enfrente
      if(frente<10){
        cont=0;
        //Parar
        drive_speed(0, 0);
        //Girar a la izquierda
        drive_goto(-25, 26);
        pause(200);
      }
      //Si no detecta pared enfrente, seguir avanzando
      else{
        drive_speed(64, 64);
        pause(100);
      }                
    }
    //Si no se detecta pared a la derecha
    else{
      //Parar
      drive_speed(0, 0);
      //Acelerar
      drive_goto(18, 18);
      pause(200);
      //Girar a la derecha 
      drive_goto(26, -25);
      cont=cont+1;
      pause(200);
      //Avanzar
      drive_goto(35, 35);
      pause(200); 
      
      //Si gira 5 veces a derecha que siga recto hasta encontrar una pared
      if (cont==5){
        while (frente>10){ 
        drive_goto(30,30);
        pause(200);
        }       
        //Si encuentra una pared, que gire dos veces a la izquierda 
        cont=0;
        drive_goto(-25, 26);
        pause(200);
      }        
    }                     
  } 
}  
