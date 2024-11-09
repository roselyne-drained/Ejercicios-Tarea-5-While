//
// Created by Roselyne on 19/10/2024.
//
#include <stdio.h>

int main(void)
{

    char character;
    printf("\nEnter a character: ");
    scanf(" %c", &character);

    while (character != '*')
    {
        printf("\nIngrese un caracter: ");
        scanf(" %c", &character);

    }

    printf("\nFin del programa hasta luego, R. :P");
}