#ifndef TDA_COLA_H
#define TDA_COLA_H

#include "estructura.h"

void pushBack(Cola* cola, Ticket* nuevo);
Ticket* popFront(Cola* cola);
Ticket* buscarPorID(Cola* cola, int id);
Ticket* eliminarPorID(Cola* cola, int id);
void liberarCola(Cola* cola);

#endif