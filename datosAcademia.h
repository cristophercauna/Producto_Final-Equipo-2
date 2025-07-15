#ifndef DATOS_ACADEMIA_H
#define DATOS_ACADEMIA_H
#include<string>
using namespace std;

struct Postulante {
    int DNI;
    string nomCompletos;
    string ciclo;
    int canal; //cambio de tipo de variable
};

struct Simulacro {
    int id_simulacro;     
    string fecha;
};

struct Examen {
    int DNI;
    int id_simulacro;
    float nota; // El puntaje sera de 0 a 600 
}; 

#endif