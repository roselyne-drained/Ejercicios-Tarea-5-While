//
// Created by Roselyne on 04/11/2024.
//
#include <ctype.h>
#include <stdio.h>

int main(void)
{
 /*En este programa realizaremos de nuevo lo de los promedios pero esta vez haremos que el usuario
 *constantemente pueda poner materias, no pondremos un limite si no que el usuario escogera cuando parar*/

 /*Como siempre primero declaramos nuestras variables*/
 float calificacion = 0;
 char continuar;
 int ingresos = 0;
 float suma_calificaciones = 0;
 int menu = 0;

 //Inicio.
 /*Le damos la bienvenida al alumno y le desplegamos el menu con el cual podra escoger si quiere ingresar
  *calificaciones, promediar sus calificaciones o salir del programa.*/
 printf("\nBienvenido alumno,\nPor favor ingrese alguna de las siguientes opciones para continuar:\n");
 do
 {
  printf("1. Ingresar calificaiones\n");
  printf("2. Promediar\n");
  printf("3. Salir\n");
  scanf(" %d", &menu);

  /*Una vez el alumno ha seleccionado la operacion que desea realizar lo mandamos al switch donde podra ingresar
   *calificaciones o promediar las que ya tiene.*/
  switch (menu)
  {
   //Ingresar calificaciones.
  case 1:
   do
   {
    printf("Ingrese la calificacion por favor:\n");
    scanf(" %f", &calificacion);
    suma_calificaciones = suma_calificaciones + calificacion;
    ingresos ++;
    printf("Desea ingresar otra calificacion? S/N\n");
    scanf(" %c", &continuar);
   } while (continuar == 's' || continuar == 'S');
   break;
   //Promediar sus calificaciones en base a cuantas veces ingreso alguna calificacion.
  case 2:
   if (ingresos > 0)
   {
    float promedio = suma_calificaciones / ingresos;
    printf("Usted ingreso %d materias:\n", ingresos);
    printf("Por lo que su promedio es de %.2f\n", promedio);
   } else
   {
    printf("No se encontra el ingreso\n");
   }
   break;

  case 3:
   printf("Saliendo...................\n");
   break;
   //Operacion fuera del menu de opciones.
  default:
   printf("Opcion incorrecta\n");
   break;
  }
 } while (menu != 3); //Esto es para que se repita el menu hasta que el usuario seleccione salir

  //Despedida.
  printf("Fin del programa, Hasta luego R. :P");

 }
