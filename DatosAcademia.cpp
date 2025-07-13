#include<iostream>
#include<string>
using namespace std;

struct Postulante {
    int DNI;
    string nomCompletos;
    string ciclo;
    string canal;
};

struct Simulacro {
    int DNI;      
    string fecha;
};

void agregarPostulante(Postulante[], int&, Postulante);
void mostrarPostulante(Postulante[], int);
void agregarSimulacro(Simulacro[], int&, Simulacro);
void mostrarSimulacros(Simulacro[], int);

int main() {
    Postulante postulantes[100];
    Simulacro simulacros[100];

    int numPostulantes = 0;
    int numSimulacros = 0;

    int op;
    do {
        system("cls");
        cout << "\n*********** BIENVENIDO A LA ACADEMIA BASADRE ***********\n";
        cout << "1. Postulante Nuevo\n";
        cout << "2. Mostrar Postulantes\n";
        cout << "3. Registrar Simulacro\n";
        cout << "4. Mostrar Simulacros\n";
        cout << "0. Salir\n";
        cout << "Ingrese el operador: ";
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
                getline(cin, nuevo.canal);
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
                cout << "Ingrese el DNI del simulacro: ";
                cin >> nuevoSim.DNI;
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
    } while(op != 0);

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
    string canales[] = {"1", "2", "3", "4"};

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
            cout << "DNI del Simulacro: " << lista[i].DNI << endl;
            cout << "Fecha: " << lista[i].fecha << endl;
            cout << "----------------------------------------" << endl;
        }
    }
}
