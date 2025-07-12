#include<iostream>
#include<string>
using namespace std;
struct Postulante{
        int DNI;
        string nomCompletos;
        string ciclo;
        string canal;
    };
    void agregarPostulante(Postulante[], int&, Postulante);

int main(){
    Postulante postulantes[100];
    int n,op,i;
    int numPostulantes = 0;
    do{
        system("cls");
        cout<<"\n*********** BIENVENIDO A LA ACADEMIA BASADRE ***********\n";
        cout<<"1. Postulante Nuevo\n";
        cout<<"0. Salir\n";
        cout<<"Ingrese el operador: "; cin>>op;
        switch(op){
            case 1:{
                Postulante nuevo;
                cout<<"\n ********* Ingrese los datos del nuevo postulante *********\n";
                cout<<"Ingrese el DNI: "; cin>>nuevo.DNI;
                cin.ignore();
                cout<<"Ingrese el nombre del Postulante: "; getline(cin , nuevo.nomCompletos);
                cout<<"Ingrese el ciclo que ira el Postulante (cepu o fase): "; getline(cin , nuevo.ciclo);
                cout<<"Ingrese el canal que el postulante seguira: "; getline(cin , nuevo.canal);
                agregarPostulante(postulantes , numPostulantes , nuevo);
                system("pause");
                break;
            }
            case 0:{
                cout<<"Finalizando Programa"<<endl;
                system("pause");
                break;
            }
        }
    }while(op!=0);
    return 0;
}
void agregarPostulante(Postulante lista[], int& cantidad, Postulante nuevo){
    if(cantidad<100){
        lista[cantidad]=nuevo;
        cantidad++;
        cout<<"Los datos del Postualante fueron agregados correctamente!!"<<endl;
    }else{
        cout<<"Ya nos se pueden agregar mas postulantes"<<endl;
    }
}