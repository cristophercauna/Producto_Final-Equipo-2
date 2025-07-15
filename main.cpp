#include <iostream>
#include<string>
#include "datosAcademia.h"
#include "GestorAcademia.h"
using namespace std;

int main() {
    Postulante postulantes[100];
    Simulacro simulacros[100];

    int numPostulantes = 0;
    int numSimulacros = 0;
    Examen examenes[100];
    int numExamenes = 0;

    int op;
    do {
        system("cls");
        cout << "\n*********** BIENVENIDO A LA ACADEMIA BASADRE ***********\n";
        cout << "1. Postulante Nuevo\n";
        cout << "2. Mostrar Postulantes\n";
        cout << "3. Registrar Simulacro\n";
        cout << "4. Mostrar Simulacros\n";
        cout << "5. Registrar nota\n";
        cout << "6. Mostrar notas\n";
        cout << "7. Modificar Ciclo y Canal\n";
        cout << "0. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1: {
                Postulante nuevo;
                system("cls");
                cout << "\n ********* Ingrese los datos del nuevo postulante *********\n";
                cout << "Ingrese el DNI: ";
                cin >> nuevo.DNI;
                cin.ignore();
                cout << "Ingrese el nombre del Postulante: ";
                getline(cin, nuevo.nomCompletos);
                cout << "Ingrese el ciclo que ira el Postulante (cepu o fase): ";
                getline(cin, nuevo.ciclo);
                cout << "Ingrese el canal que el postulante seguira (1-4): ";
                cin >> nuevo.canal;   //cambiamos la entrada
                agregarPostulante(postulantes, numPostulantes, nuevo);
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                mostrarPostulante(postulantes, numPostulantes);
                system("pause");
                break;
            }
            case 3: {
                Simulacro nuevoSim;
                system("cls");
                cout << "\n ********* Ingrese los datos del nuevo simulacro *********\n";
                cout << "Ingrese el ID del simulacro: ";
                cin >> nuevoSim.id_simulacro;
                cin.ignore();
                cout << "Ingrese la fecha del simulacro (dd/mm/aaaa): ";
                getline(cin, nuevoSim.fecha);
                agregarSimulacro(simulacros, numSimulacros, nuevoSim);
                system("pause");
                break;
            }
            case 4: {
                system("cls");
                mostrarSimulacros(simulacros, numSimulacros);
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                cout << "\n ********** Registro de notas del examen simulacro *************\n";
                int dniBuscar;
                float notaNueva;
                int idSimulacro;
                cout << "Ingrese el DNI del postulante: ";
                cin >> dniBuscar;
                int i;
                for (i = 0; i < numPostulantes; i++) {
                    if (postulantes[i].DNI == dniBuscar) {
                        cout<< "Ingrese el ID del simulacro: ";
                        cin>> idSimulacro;
                        cout<< "Ingrese la nota obtenida (0 a 600): ";
                        cin>> notaNueva;
                        if (notaNueva >= 0 && notaNueva <= 600) {
                            leerExamen(examenes[numExamenes], dniBuscar, idSimulacro, notaNueva);
                            numExamenes=numExamenes+1;
                            cout<<"Nota registrada correctamente.\n";
                        } else {
                            cout<<"Nota invalida. Debe estar entre 0 y 600 puntos.\n";
                        }
                        break;
                    }
                }
                if (i==numPostulantes) {
                    cout <<"DNI no encontrado entre los postulantes.\n";
                }
                system("pause");
                break;
            }
            case 6: { // se agrega el nuevo case 6 MOSTRAR
                system("cls");
                mostrarNotasPorSimulacro(postulantes, numPostulantes, examenes, numExamenes);
                system("pause");
                break;
            }    
            case 7:{
                system("cls");
                int dniBuscar,i;
                cout<<"\n ************* CAMBIO DE CICLO Y CANAL *************"<<endl;
                cout<<"Ingrese el DNI del postulante a cambiar: "; cin>>dniBuscar;
                for(i=0 ; i<numPostulantes ; i++){
                    if(postulantes[i].DNI == dniBuscar){
                        cout<<"\n -----Los Datos actuales del postulante son: -----\n ";
                        cout<<"Nombre | "<<postulantes[i].nomCompletos<<endl;
                        cout<<"Ciclo | "<<postulantes[i].ciclo<<endl;
                        cout<<"Canal | "<<postulantes[i].canal<<endl;
                        string confirmar;
                            cout<<"Desea seguir con el cambio de canal y ciclo ? (S / N)"<<endl;
                            cin>>confirmar;
                            if(confirmar == "S" || confirmar =="s"){
                            cin.ignore();
                            cout<<"Ingrese el nuevo Ciclo (cepu o fase): "; getline(cin,postulantes[i].ciclo);
                            cout<<"Ingrese el nuevo Canal (1-4): "; cin>>postulantes[i].canal;
                            cout<<"Datos Actualizados correctamente. \n";
                            }
                            else{
                            cout<<"Operacion cancelada por el usuario \n";
                            }
                            break;
                    }
                }
                if(i == numPostulantes){
                    cout<<"No se encontro ningun postulante con ese DNI \n";
                }
                system("pause");
                break;
             }
            
            case 0: {
                cout << "Finalizando Programa" << endl;
                system("pause");
                break;
            }
            default:
                cout << "Opcion invalida, intente nuevamente.\n";
                system("pause");
                break;
        }
    }while(op != 0);
    
   return 0;
}

void agregarPostulante(Postulante lista[], int& cantidad, Postulante nuevo) {
    if(cantidad < 100) {
        lista[cantidad] = nuevo;
        cantidad++;
        cout << "Los datos del Postulante fueron agregados correctamente!!" << endl;
    } else {
        cout << "Ya no se pueden agregar más postulantes" << endl;
    }
}

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

void agregarSimulacro(Simulacro lista[], int& cantidad, Simulacro nuevo) {
    if(cantidad < 100) {
        lista[cantidad] = nuevo;
        cantidad++;
        cout << "Simulacro agregado correctamente!" << endl;
    } else {
        cout << "Ya no se pueden agregar más simulacros." << endl;
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