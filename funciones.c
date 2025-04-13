#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estructura.h"
#include "tda_cola.h"

Cola colaAlta = {NULL, NULL};
Cola colaMedia = {NULL, NULL};
Cola colaBaja = {NULL, NULL};

int esNumero(const char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int idExiste(int id) {
    Cola* colas[] = {&colaAlta, &colaMedia, &colaBaja};
    for (int i = 0; i < 3; i++) {
        Ticket* actual = colas[i]->frente;
        while (actual) {
            if (actual->id == id) return 1;
            actual = actual->siguiente;
        }
    }
    return 0;
}

const char* obtenerPrioridadStr(prioridad p) {
    switch (p) {
        case ALTO: return "ALTO";
        case MEDIO: return "MEDIO";
        case BAJO: return "BAJO";
        default: return "DESCONOCIDA";
    }
}

void registrarTicket(int id, const char* descripcion) {
    if (idExiste(id)) {
        printf("El ID %d ya está registrado.\n", id);
        return;
    }

    Ticket* nuevo = malloc(sizeof(Ticket));
    nuevo->id = id;
    strncpy(nuevo->descripcion, descripcion, sizeof(nuevo->descripcion));
    nuevo->Prioridad = BAJO;
    nuevo->horaRegistro = time(NULL);
    nuevo->siguiente = NULL;

    pushBack(&colaBaja, nuevo);
    printf("Ticket %d registrado con prioridad BAJO.\n", id);
}

void cambiarPrioridad(int id, prioridad nueva) {
    Ticket* ticket = eliminarPorID(&colaAlta, id);
    if (!ticket) ticket = eliminarPorID(&colaMedia, id);
    if (!ticket) ticket = eliminarPorID(&colaBaja, id);

    if (!ticket) {
        printf("Ticket con ID %d no encontrado.\n", id);
        return;
    }

    ticket->Prioridad = nueva;
    ticket->siguiente = NULL;

    switch (nueva) {
        case ALTO: pushBack(&colaAlta, ticket); break;
        case MEDIO: pushBack(&colaMedia, ticket); break;
        case BAJO: pushBack(&colaBaja, ticket); break;
        default: printf("Error: Prioridad invalida.\n"); break;
    }

    printf("Prioridad del ticket %d cambiada a %s.\n", id, obtenerPrioridadStr(nueva));
}

void mostrarTicket(const Ticket* t) {
    if (!t) return;
    const char* textoPrioridad = t->Prioridad == ALTO ? "ALTO" : t->Prioridad == MEDIO ? "MEDIO" : "BAJO";

    char tiempoStr[26];
    strftime(tiempoStr, sizeof(tiempoStr), "%Y-%m-%d %H:%M:%S", localtime(&t->horaRegistro));
    
    printf("==================================================\n");
    printf("ID: %d | Prioridad: %s | Hora: %s\nDescripcion: %s\n", t->id, textoPrioridad, tiempoStr, t->descripcion);
    printf("==================================================\n");
}

void buscarTicket(int id) {
    Ticket* ticket = buscarPorID(&colaAlta, id);
    if (!ticket) ticket = buscarPorID(&colaMedia, id);
    if (!ticket) ticket = buscarPorID(&colaBaja, id);

    if (ticket) {
        printf("\nTicket encontrado:\n");
        mostrarTicket(ticket);
    } else {
        printf("Ticket con ID %d no encontrado.\n", id);
    }
}

void mostrarCola(Cola* cola) {
    Ticket* actual = cola->frente;
    if (!actual) {
        printf(" (vacia)\n");
        return;
    }
    while (actual) {
        printf("- ID: %d | Descripcion: %s | Hora: %s", actual->id, actual->descripcion, ctime(&actual->horaRegistro));
        actual = actual->siguiente;
    }
}

void mostrarTicketsPendientes() {
    if (!colaAlta.frente && !colaMedia.frente && !colaBaja.frente) {
        printf("No hay tickets pendientes.\n");
        return;
    }

    printf("\n--- Lista de Tickets Pendientes ---\n");
    printf("\nPrioridad ALTA:\n");
    mostrarCola(&colaAlta);

    printf("\nPrioridad MEDIA:\n");
    mostrarCola(&colaMedia);

    printf("\nPrioridad BAJA:\n");
    mostrarCola(&colaBaja);
}

void procesarSiguienteTicket() {
    Cola* cola = NULL;

    if (colaAlta.frente) cola = &colaAlta;
    else if (colaMedia.frente) cola = &colaMedia;
    else if (colaBaja.frente) cola = &colaBaja;

    if (!cola) {
        printf("No hay tickets pendientes.\n");
        return;
    }

    Ticket* ticket = cola->frente;
    cola->frente = ticket->siguiente;
    if (!cola->frente) cola->final = NULL;

    printf("\nProcesando Ticket:\n");
    mostrarTicket(ticket);

    free(ticket);
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void presioneTeclaParaContinuar() {
    puts("Presione ENTER para continuar...");
    getchar();                 
}