//
// Created by Roselyne on 04/11/2024.
//
#include <limits.h>
#include <stdio.h>

int main(void)
{
    /*El usuario ingresara numeros del teclado aleatoriamente hasta que escriba el 0
     *en ese momento el programa finaliza y se mencionara el numero mayor y el numero
     *menor de todos los que se escribieron sin contar el 0 */

    //Declarar variables
    int numero;
    int numero_mayor = INT_MIN;
    int numero_menor = INT_MAX;

    //Inicio.
    do
    {
        printf("Ingrese un numero:");
        scanf("%d", &numero);

        //Solo procesar si el numero no es 0
        if (numero !=0)
        {
            if (numero > numero_mayor)
            {
                numero_mayor = numero;
            }
            if (numero < numero_menor)
            {
                numero_menor = numero;
            }
        }
    }while(numero != 0);
    if (numero_mayor == INT_MIN && numero_menor == INT_MAX)
    {
        printf("No se ingresaron numeros.\n");
    }
    else
    {
        printf("Numero mayor es: %d\n", numero_mayor);
        printf("Numero menor es: %d\n", numero_menor);
    }
    printf("Fin del programa, Hasta luego R. xP");
}