#include "GestorAcademia.h"
#include<iostream>

void agregarPostulante(Postulante lista[], int& cantidad, Postulante nuevo) {
    if(cantidad < 100) {
        lista[cantidad] = nuevo;
        cantidad++;
        cout << "Los datos del Postulante fueron agregados correctamente!!" << endl;
    } else {
        cout << "Ya no se pueden agregar más postulantes" << endl;
    }
}

void agregarSimulacro(Simulacro lista[], int& cantidad, Simulacro nuevo) {
    for (int i = 0; i < cantidad; i++) {  
        if (lista[i].id_simulacro == nuevo.id_simulacro) {
            cout<< "Error: El ID de simulacro " << nuevo.id_simulacro << " ya existe y no se puede duplicar.\n";
            return; 
        }
    }
    if(cantidad < 100) {
        lista[cantidad] = nuevo;
        cantidad++;
        cout << "Simulacro agregado correctamente!" << endl;
    } else {
        cout << "Ya no se pueden agregar más simulacros." << endl;
    }
}

void leerExamen(Examen &e, int dni, int idSimulacro, float nota) {
    e.DNI = dni;
    e.id_simulacro = idSimulacro;
    e.nota = nota;
}