#include "GestorAcademia.h"
#include<iostream>

void mostrarPostulante(Postulante lista[], int cantidad) {
    string ciclo[] = {"cepu", "fase"};
    int canales[] = {1, 2, 3, 4}; // aqui tmb se cambia el tipo de variable

    for(int i = 0; i < 2; i++) { 
        for(int j = 0; j < 4; j++) { 
            cout << "\nCiclo: " << ciclo[i] << " | Canal: " << canales[j] << endl;
            cout << "---------------------------------------------" << endl;
            int encontrado = 0;
            for(int k = 0; k < cantidad; k++) {
                if(lista[k].ciclo == ciclo[i] && lista[k].canal == canales[j]) {
                    cout << "DNI: " << lista[k].DNI << "  ";
                    cout << "Nombres: " << lista[k].nomCompletos << endl;
                    cout << "----------------------------------------" << endl;
                    encontrado = 1;
                }
            }
            if(encontrado == 0) {
                cout << "Sin postulantes en este grupo" << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }
    if(cantidad == 0) {
        cout << "No hay postulantes registrados." << endl;
    }
}

void mostrarSimulacros(Simulacro lista[], int cantidad) {
    if(cantidad == 0) {
        cout << "No hay simulacros registrados." << endl;
    } else {
        cout << "\n ********** Lista de Simulacros Registrados **********\n";
        for(int i = 0; i < cantidad; i++) {
            cout << "ID del Simulacro: " << lista[i].id_simulacro << endl;
            cout << "Fecha: " << lista[i].fecha << endl;
            cout << "----------------------------------------" << endl;
        }
    }
}

void mostrarNotasPorSimulacro(Postulante postulantes[], int numPostulantes, Examen examenes[], int numExamenes) { // se agrega la nueva funcion
    int idSimulacro;
    cout << "\n******************** NOTAS DEL EXAMEN SIMULACRO ***************************\n";
    cout << "Ingrese el ID del simulacro: ";
    cin >> idSimulacro;

    string cicloEsco;
    cout << "\nIngrese el ciclo (cepu o fase): ";
    cin >> cicloEsco;

    cout << "\nSeleccione el canal que desea visualizar:\n"<<endl;
    cout << "canal 1: CIENCIAS DE LA SALUD Y BIOMEDICAS\n";
    cout << "canal 2: CIENCIAS EXACTAS E INGENIERIA\n";
    cout << "canal 3: ARQUITECTURA, CIENCIAS SOCIALES Y HUMANIDADES\n";
    cout << "canal 4: CIENCIAS ACTUALES Y EMPRESARIALES\n";

    int canal;
    cout << "\nIngrese el numero de canal (1 al 4): ";
    cin >> canal;

    cout<<"\n******************** EXAMEN SIMULACRO (ID : " << idSimulacro << ") ***************************\n";
    cout<<"CICLO "<<cicloEsco<<" --------------------------------------------------------------\n";
    cout<<"    CANAL "<< canal<<" -------------------------------------------------------------\n";
    cout<<"\n    NOMBRE\t\tDNI\t\tNOTA\n";

    int contador = 1;
    for (int i = 0; i < numPostulantes; i++) {
        if (postulantes[i].ciclo == cicloEsco && postulantes[i].canal == canal) {
            for (int j = 0; j < numExamenes; j++) {
                if (examenes[j].DNI == postulantes[i].DNI && examenes[j].id_simulacro == idSimulacro) {
                    cout << "    " << contador << ". " << postulantes[i].nomCompletos << "\t" 
                    << postulantes[i].DNI << "\t" << examenes[j].nota << endl;
                    contador=contador +1; 
                }
            }
        }
    }

    if (contador == 1) {
        cout<<"\n    No se encontraron notas registradas para ese filtro.\n";
    }
}