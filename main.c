#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tda_cola.h"
#include "estructura.h"
#include "funciones.h"

extern Cola colaAlta;
extern Cola colaMedia;
extern Cola colaBaja;

void menu() {
    int opcion;
    do {
        limpiarPantalla();
        printf("===============================\n");
        printf("       SISTEMA DE TICKETS      \n");
        printf("===============================\n");
        printf("1. Registrar nuevo ticket\n");
        printf("2. Buscar por ID\n");
        printf("3. Cambiar prioridad\n");
        printf("4. Mostrar tickets pendientes\n");
        printf("5. Procesar siguiente ticket\n");
        printf("0. Salir\n");
        printf("===============================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        char input[256];
        int id;
        int prioridad;
        char descripcion[256];

        switch (opcion) {
            case 1:
                printf("Ingrese ID del ticket: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (!esNumero(input)) {
                    printf("El ID debe ser un numero.\n");
                    break;
                }

                id = atoi(input);
                if (idExiste(id)) {
                    printf("El ID %d ya esta registrado.\n", id);
                    break;
                }

                printf("Ingrese descripcion del problema: ");
                fgets(descripcion, sizeof(descripcion), stdin);
                descripcion[strcspn(descripcion, "\n")] = 0;

                registrarTicket(id, descripcion);
                presioneTeclaParaContinuar(); 
                break;

            case 2:
                printf("Ingrese ID a buscar: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (!esNumero(input)) {
                    printf("El ID debe ser un numero.\n");
                    break;
                }

                id = atoi(input);
                buscarTicket(id);
                presioneTeclaParaContinuar();
                break;

            case 3:
                printf("ID a cambiar: \n");
                scanf("%d", &id);getchar();
                if (!idExiste(id)) {
                    printf("El ID %d no esta registrado.\n", id);
                    presioneTeclaParaContinuar();
                    break;
                }
                printf("Prioridad nueva (0 = BAJO, 1 = MEDIO, 2 = ALTO): \n");
                scanf("%d", &prioridad);getchar();
            
                if (prioridad < 0 || prioridad > 2) {
                    printf("Prioridad invalida, solo acepta 0, 1 o 2.\n");
                } else {
                    cambiarPrioridad(id, prioridad);
                }
                presioneTeclaParaContinuar(); 
                break;
        
            case 4:
                mostrarTicketsPendientes();
                presioneTeclaParaContinuar();
                break;

            case 5:
                procesarSiguienteTicket();
                presioneTeclaParaContinuar();  
                break;

            case 0:
                printf("Saliendo del sistema...\n");
                presioneTeclaParaContinuar(); 
                break;

            default:
                printf("Opcion no valida.\n");
                presioneTeclaParaContinuar();  
        }

    } while (opcion != 0);
}

int main() {
    menu();

    liberarCola(&colaAlta);
    liberarCola(&colaMedia);
    liberarCola(&colaBaja);
    return 0;
}