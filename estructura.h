#ifndef estructura_h
#define estructura_h

#include<time.h>

typedef enum{
    BAJO = 0, MEDIO = 1, ALTO = 2
}prioridad;

typedef struct Ticket{
    int id;
    char descripcion[256];
    prioridad Prioridad;
    time_t horaRegistro;
    struct Ticket* siguiente;
    
} Ticket;

typedef struct Cola
{
    Ticket*frente;
    Ticket*final;
}Cola;

#endif