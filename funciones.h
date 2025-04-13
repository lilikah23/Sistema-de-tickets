#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructura.h"


void limpiarPantalla();
void presioneTeclaParaContinuar();
int esNumero(const char* cadena);
int idExiste(int id);


void registrarTicket();
void cambiarPrioridad(int id, prioridad nuevaPrioridad);
void mostrarTicketsPendientes();
void procesarSiguienteTicket();
void buscarTicket(int id);


const char* obtenerPrioridadStr(prioridad p);
void mostrarTicket(const Ticket* t);
void mostrarCola(Cola* cola);

#endif