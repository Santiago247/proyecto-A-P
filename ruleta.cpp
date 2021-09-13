#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define DIM 20

using namespace std;
 
char presentacion();
 
void espera(int segundos);
 
int main ()
{
 char c;
 int n=0,m[DIM],i,premio,k=4;
 
srand(time(NULL));
 
c=presentacion ();
 
switch (c) {
 case 'A' :
 do {
 printf ("1 - Apostar a los pares \t 2 - Apostar a los impares\n");
 scanf ("%d",&n);}while(n!=1 && n!=2);
 break;
 
case 'B' :
 do {
 printf ("1 - Apostar a la primera columna \t 1-4-7-10-13-16-19-22-25-28-31-34\n");
 printf ("2 - Apostar a la segunda columna \t 2-5-8-11-14-17-20-23-26-29-32-35\n");
 printf ("3 - Apostar a la tercera columna \t 3-6-9-12-15-18-21-24-27-30-33-36\n");
 scanf ("%d",&n);}while(n!=1 && n!=2 && n!=3);
 break;
 
case 'C' :
 do {
 printf ("Dime a los tres numeros que quieres apostar \n(Comprendidos entre 1 y 36):\n");
 for (i=0;i<3;i++)
 scanf ("%d",&m[i]);
 }
 while((m[0]<=0 || m[0]>36) || (m[1]<=0 || m[1]>36) || (m[2]<=0 || m[2]>36));
 break;
 
case 'D' :
 do {
 printf ("Dime el numero al que quieres apostar \n(Comprendido entre 1 y 36):\n");
 
scanf ("%d",&n);
 }
 while(n<=0 || n>36); break;
 }
 
system("cls");
 
printf ("\nUna vez hecha la apuesta, toca ver que numero sale en la ruleta :\n\n");
 
for(i=1;i<=100;i++) rand();  //descartamos los 100 primeros números aleatorios
premio = rand() % 37;      //almacenamos el número premiado 
 
espera (k);  //simulación de la bola moviéndose en la ruleta
 
system("cls");
 
printf ("\nUna vez hecha la apuesta, toca ver que numero sale en la ruleta :\n\n");
 
printf ("\t%d\n\n",premio);
 
if (premio==0) {
 printf ("Gana la banca!");
 system ("pause");
 return 0;}
 
switch ( c ) {
 case 'A' :
 if ((n==1 && premio%2 == 0) || (n==2 && premio%2 == 1))
 printf ("Has ganado! \n");
 else printf ("Lo siento! Otra vez sera \n");
 break;
 
case 'B' :
 if ((n==1 && premio%3 == 1) || (n==2 && premio%3 == 2) || (n==3 && premio%2 == 0))
 printf ("Has ganado! \n");
 else printf ("Lo siento! Otra vez sera \n");
 break;
 
case 'C' :
 if ((m[0]==premio) || (m[1]==premio) || (m[2]==premio))
 printf ("Has ganado! \n");
 else printf ("Lo siento! Otra vez sera \n");
 break;
 
case 'D' :
 if (n==premio)
 printf ("Has ganado! \n");
 else printf ("Lo siento! Otra vez sera \n");
 break;
 
}
 system ("pause");
 return 0;
}
 
char presentacion()
 
{
 char c;
do {
printf ("\nintegrantes:");
printf ("\nSantiago Londono:");
printf ("\nJuan Jiguel Jaramillo:\n");
 
printf ("\n           Bienvenido al juego de la ruleta.\n\n");
 
printf ("   Que tipo de apuesta quieres realizar?\n  (Para elegir escribe la mayuscula correspondiente: )\n\n");
 
printf ("A - Pares o Impares \t B - Columna \t C - Terna \t D - Pleno (un numero)\n");
 
scanf ("%c",&c);
 
system("cls"); } while (c!='A' && c!='B' && c!='C' && c!='D');
 return c;
}
 
void espera(int segundos)
{
 //srand(time(NULL));  
 int Seg1,Seg2;
 Seg1=(int)clock()/CLOCKS_PER_SEC;
 Seg2=Seg1;
 while((Seg2-Seg1) < segundos){
 if(clock()%400<10){
 system("cls");
 printf ("\n\t Apuesta realizada\n\t EL NUMERO GANADOR ES:\n\n\t%d",rand() % 37);
 }
 Seg2=(int)clock()/CLOCKS_PER_SEC;
 }
}