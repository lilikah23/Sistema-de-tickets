# 🛠️ Sistema de Gestión de Tickets

Este programa en lenguaje C permite gestionar tickets de soporte técnico con distintos niveles de prioridad: **BAJO**, **MEDIO** y **ALTO**.

---------------------------------------------------------------------------------

## Estructura del Proyecto

├── estructura.h  **Definiciones de Ticket y prioridad**
├── funciones.c/h  **Funciones principales del sistema**
├── main.c     **Menú principal**  
├── README.md  **Este archivo**
└── tda_cola.c/h **Funciones TDA de cola**

---------------------------------------------------------------------------------

## ¿Cómo compilar y ejecutar?
* Requisitos: Tener gcc instalado en tu sistema (puedes usar MinGW en Windows o gcc en Linux/macOS).*

Se compila el programa ejecutando el siguiente comando en la terminal (cmd o bash):

gcc main.c funciones.c tda_cola.c -o sistema_tickets

**Esto creara un ejecutable**
*Luego ejecuta el programa así:*

./sistema_tickets

---------------------------------------------------------------------------------

# Funcionalidades implementadas

1) Registrar ticket:
Permite ingresar un ID único *(de tipo numerico)* y una descripción. Se guarda con prioridad baja por defecto.

2) Buscar por ID:
Muestra la información completa del ticket si existe.

3) Cambiar prioridad:
Permite cambiar la prioridad a 0 (BAJO), 1 (MEDIO) o 2 (ALTO).
Solo acepta esos números y valida si el ticket existe.

4) Mostrar tickets pendientes:
Lista todos los tickets agrupados por prioridad.

5) Procesar siguiente ticket:
Atiende el ticket más urgente (de prioridad más alta disponible) y lo elimina de la cola.

6) Liberación de memoria al salir:
Las colas se liberan correctamente antes de finalizar el programa para evitar fugas de memoria.

---------------------------------------------------------------------------------

## Funcionalidades con detalles o mejoras pendientes

-⚠️ Validación de entrada me se puede mejorar (por ejemplo, si se ingresa letras donde se espera un números, el programa puede fallar).

-⚠️ También no se valida, cuando queremos cambiar de prioridad, confirmar si la prioridad que queremos cambiar ya esta asignada al ticket(el ticket 123, es prioridad *baja*, y lo quiero cambiar a *baja*, no me confirma si ya estaba antes en baja) **aunque esto no afecta el funcionamiento del programa, solo podría ser una futura mejora**.

-⚠️ El sistema no utiliza Makefile, por lo que se requiere compilar de forma manual como se indica arriba.

-⚠️ Interfaz de consola básica, sin colores ni navegación mejorada. (aun no se hacerlo de otra manera :c ) 

-⚠️ No se guarda en archivos, todos los tickets se pierden al cerrar el programa.

---------------------------------------------------------------------------------

# 💡 Ejemplo de uso:

===============================
--- SISTEMA DE TICKETS ---
1. Registrar nuevo ticket
2. Buscar por id 
3. Cambiar prioridad 
4. Mostrar tickets pendientes
5. Procesar siguiente ticket
0. Salir
===============================
Seleccione una opción: 1

ID del ticket: 101
Descripción del problema: No puedo acceder al sistema
Ticket 101 registrado con prioridad BAJO.

Seleccione una opción: 2

ID a buscar: 101
Ticket encontrado:
ID: 101
Descripción: No puedo acceder al sistema
Prioridad: BAJO
Hora de registro: Sun Apr 13 18:32:11 2025

Seleccione una opción: 3

ID a cambiar: 101
Prioridad nueva: 2
Prioridad del ticket 101 cambiada a ALTO.

Seleccione una opción: 4

Prioridad ALTA:
- ID: 101 | Descripción: No puedo acceder al sistema | Hora: 2025-04-13 18:32:11

Seleccione una opción: 5

Procesando ticket:
ID: 101
Descripción: No puedo acceder al sistema
Prioridad: ALTO
Hora de registro: Sun Apr 13 18:32:11 2025

Seleccione una opción: 2

ID a buscar: 999
Ticket con ID 999 no encontrado.

Seleccione una opción: 0

Saliendo del sistema...

---------------------------------------------------------------------------------