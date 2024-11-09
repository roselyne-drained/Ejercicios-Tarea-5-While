//
// Created by Roselyne on 19/10/2024.
//
#include <stdio.h>

int main(void) {

    //Queremos mostrar los numeros impares que se encuentren dese el 100 hasta -100.
    //Como siempre primero las variables.

    int a = 100;

    do
    {
        //Verificamos que el valor es impar
        //Esto lo podemos saber de forma facil aplicando lo mismo que en ejercicios pasados.
        //Usamos modulo para dividir la cantidad entre 2 y cuando el residuo es distinto de 0.
        //Entonces nuestro numero es impar.
        if (a % 2 != 0) {
            printf("El valor de a es: %d\n", a);

        //Utilizamos a--; para que con cada interaccion el valor vaya disminuyendo.
    } a--;
    }while (a >= -100);

    }