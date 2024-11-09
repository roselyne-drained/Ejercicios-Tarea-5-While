//
// Created by Roselyne on 19/10/2024.
//
#include <stdio.h>
#include <string.h>


int main(void)
{
    //Ahora haremos una cuenta de ahorro.
    //Tenemos que pedir un monto objetivo y permtir
    //que el usuario pueda guardar o retirar dinero hasta alcanzar su monto objetivo.

    //Declarar variables:
    float ahorros = 0;
    float Objetivo = 1000;
    float Cantidad;
    int opcion1;
    //Utilizamos [] para ayudarnos a que el usuario pueda escribir una password tipo cadena ya que char solo se puede un caracter
    //Esto debido a que nos daba muchos errores a la hora de correr el codigo, lo que hace esto es que limita
    //Al usuario a que solo se almacenaran en la variable char el numero de caracteres que nosotros pongamos.
    //Ojo este numero incluye al 0 por lo que si nosotros por ejemplo pusimos que sean 9 caracteres.
    //En realidad solo se van a almacenar 4 caracteres en la variable.
    char password1[5];
    char password2[5];
    int intentos = 0;

    //Inicio
    printf("\nBienvenido a tu cuenta de ahorros.");

    //pedimos el password del usuario para su cuenta de ahorros.
    printf("\nIngrese un password por favor: (Maximo 4 caracteres.)\n");
    //Investigando descubrimos que existen tres opciones para capturar nuestra password,
    //ya sea con un scanf, lo cual no es recomendable pues contiene limitaciones para la lectura
    //de caracteres pero tambien existe fgets que es el que usaremos y este lo que nos permite es que
    //sea mas dificil que ocurra algun error en la compilacion de nuestro codigo y que a la hora de capturar
    //la password pueda capturar incluso los espacios si el usuario lo desea, pero investigando mas tambien descubri
    //que existe una funcion llamada getpass, esta es generalmente usada en c para contrasenias por el mismo hecho
    //de que cuando el usuario la ingresa esta no muestra los caracteres permitiendo que sea una opcion con mas seguridad.
    fgets(password1, sizeof(password1), stdin);
    printf("Password ingresada: %s\n", password1);
    //Esto lo que permite es eliminar un salto de linea y evitar errores.
    password1[strcspn(password1, "\n")] = 0;


    do
    {
        printf("\nTe recomendamos tener al menos 1000$ en tu cuenta de ahorros");
        printf("\nTus ahorros actuales son: %.2f$", ahorros);
        printf("\nIngrese una opcion:");
        printf("\n1):Guardar.");
        printf("\n2):Retirar.");
        printf("\n3):Salir.\n");
        scanf(" %d", &opcion1);




        //Una vez ingresada la opcion utilicemos un switch para facilitar el menu de opciones.
        switch (opcion1)
        {
        case 1:
            printf("\nIngrese la cantidad a guardar:");
            scanf("%f", &Cantidad);
            ahorros = ahorros + Cantidad;
            printf("\nIngresaste: %.2f$ a tu cuenta.\n", Cantidad);
            break;

        case 2:
            printf("\nIngrese la cantidad a retirar:");
            scanf("%f", &Cantidad);
            getchar(); //Con esto eliminamos cualquier dato almacenado que es como hacer el espacio en el %c pero para fgets.
            if (Cantidad > 0)
            {
                intentos = 0; //Reiniciamos los intentos para evitar bugs o cualquier error
                while (intentos < 3) //Aqui es donde validaremos la password
                {
                    printf("\nPor favor valide un password para su cuenta: ");
                    //Al colocar un 4 antes de la s, la s es como el c pero para tipo cadenas, osea strings.
                    //Lo que hacemos es limitar el numero a 4 caracteres.
                    fgets(password2, sizeof(password2), stdin);
                    getchar();
                    //Elimino el salto de linea ya que me estaba provocando un error.
                    password2[strcspn(password2, "\n")] = 0;
                    if (strcmp(password1, password2) == 0)
                    {
                        if (Cantidad > ahorros)
                        {
                            printf("\nLo sentimos, no cuentas con el saldo suficiente.");
                        }
                        else
                        {
                            ahorros = ahorros - Cantidad;
                            printf("\nUsted ha retirado: %.2f", Cantidad);
                            printf("\nSu saldo actual es: %.2f", ahorros);
                        }
                        break;
                    }
                    intentos++;
                    printf("\nLa password es incorrecta, tiene 3 intentos restantes %d\n", 3 - intentos);
                }
                if (intentos == 3)
                {
                    printf("\nDemasiados intentos fallidos. Saliendo del programa.\n");
                }
            }
            break;

        case 3:
                printf("\nGracias, vuelva pronto.");
                break;

            default:
                printf("\nOpcion no valida.");
            }
        } while (opcion1 != 3 && ahorros < Objetivo);
        {
            if (ahorros >= Objetivo)
            {
                printf("\nFelicidades has llegado al minimo objetivo de ahorros.");
                printf("\nSigue ahorrando para que tu dinero crezca con el tiempo.");
                printf("\nTu saldo actual es:%.2f$", ahorros);
            }

            printf("\nFin del programa hasta luego, R. :P");

        }
    }
