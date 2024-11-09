#include <stdio.h>

int main(void) {
    /* Una central distribuye cal hacia diferentes sucursales. Disponen de un muelle de carga a donde van
       llegando costales de cal entre 3000 y 9000 Kgs, con pesos variables. La empresa dispone de una flota de
       camiones con capacidades de carga de entre 18000 y 28000 Kgs.
       Se pretende establecer un protocolo consistente en cargar 10 camiones diarios. Cada camión se quiere
       cargar como máximo a su límite de capacidad debiendo salir a reparto si con el siguiente saco en la línea
       de producción fuera a exceder su capacidad. (NUNCA SE DEBE EXCEDER LA CAPACIDAD DE CARGA DEL
       CAMION y se va cargando uno a uno conforme van saliendo los costales).*/

    // Declarar variables
    int capacidad_camion;
    int peso_saco;
    int total_carga;
    int camiones_cargados = 0;
    int camiones = 10;

    // Inicio.
    printf("\nBienvenido, por favor ingrese los siguientes datos:\n");

    // While para cargar los camiones
    while (camiones_cargados < camiones) {
        printf("\nIngrese la capacidad del camion: (Entre 18,000 y 28,000 kg)\n");
        scanf(" %d", &capacidad_camion);

        /*Realizamos un if por si la cantidad es invalida que lo vuelva a  y la funcion continue lo que nos permite
         *Es que el codigo no termine ahi, si no que pueda volver a pedir el peso del camion.
         */
        if (capacidad_camion < 18000 || capacidad_camion > 28000) {
            printf("\nCapacidad invalida. Por favor ingrese una capacidad valida.\n");
            continue;
        }

        //Volvemos a poner la carga en 0 para el nuevo camion
        total_carga = 0;

        while (1) {
            //Pedimos el peso del saco para cargarlo en el camion
            printf("Ingrese el peso del saco (El peso debe ser entre 3000 y 9000 kg o -1 para dar salida):\n");
            scanf(" %d", &peso_saco);
            //Cargamos el camion y lo dejamos con la carga que tenga.
            if (peso_saco == -1) {
                printf("\nEl camion ha sido cargado con %d kg.\n", total_carga);
                camiones_cargados++;
                break;
            }
            //Si no, ponemos los sacos en el camion correspondiente
            if (peso_saco < 3000 || peso_saco > 9000) {
                printf("Peso del saco invalido. Por favor ingrese un peso valido entre 3000 y 9000 kg.\n");
                continue;
            }

            if (total_carga + peso_saco > capacidad_camion) {
                printf("No se puede cargar el saco de %d kg. Excede la capacidad maxima alcanzada.\n", peso_saco);
                printf("Saldra el camion con %d kg cargados.\n", total_carga);
                camiones_cargados++;
                break;
            }

            //Confirmamos el total de la carga.
            total_carga = total_carga + peso_saco;
            printf("Saco de %d kg cargado. Total cargado: %d kg.\n", peso_saco, total_carga);
        }
    }

    printf("Se han cargado %d camiones. No quedan mas camiones.\n", camiones_cargados);
    printf("Fin del programa. Hasta luego... R. XP");
}