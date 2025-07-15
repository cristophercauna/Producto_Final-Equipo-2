#ifndef GESTOR_ACADEMIA_H
#define GESTOR_ACADEMA_H
#include "datosAcademia.h"

void agregarPostulante(Postulante[], int&, Postulante);
void mostrarPostulante(Postulante[], int);
void agregarSimulacro(Simulacro[], int&, Simulacro);
void mostrarSimulacros(Simulacro[], int);
void leerExamen(Examen &, int, int, float);
void mostrarNotasPorSimulacro(Postulante[], int, Examen[], int);

#endif