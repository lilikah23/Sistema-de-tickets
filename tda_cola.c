#include <stdlib.h>
#include "tda_cola.h"

void pushBack(Cola* cola, Ticket* nuevo) {
    nuevo->siguiente = NULL;
    if (!cola->frente) {
        cola->frente = cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
}

Ticket* popFront(Cola* cola) {
    if (!cola->frente) return NULL;
    Ticket* temp = cola->frente;
    cola->frente = temp->siguiente;
    if (!cola->frente) cola->final = NULL;
    return temp;
}

Ticket* buscarPorID(Cola* cola, int id) {
    Ticket* actual = cola->frente;
    while (actual) {
        if (actual->id == id) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}

Ticket* eliminarPorID(Cola* cola, int id) {
    Ticket* actual = cola->frente;
    Ticket* anterior = NULL;

    while (actual != NULL) {
        if (actual->id == id) {
            if (anterior == NULL) {
                cola->frente = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }

            if (cola->final == actual) {
                cola->final = anterior;
            }

            actual->siguiente = NULL; 
            return actual;  
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    return NULL;
}

void liberarCola(Cola* cola) {
    Ticket* actual = cola->frente;
    while (actual != NULL) {
        Ticket* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    cola->frente = NULL;
    cola->final = NULL;
}