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
    void mostrarPostulante(Postulante[],int);
int main(){
    Postulante postulantes[100];
    int n,op,i;
    int numPostulantes = 0;
    do{
        system("cls");
        cout<<"\n*********** BIENVENIDO A LA ACADEMIA BASADRE ***********\n";
        cout<<"1. Postulante Nuevo\n";
        cout<<"2. Mostrar Postulantes\n";
        cout<<"0. Salir\n";
        cout<<"Ingrese el operador: "; cin>>op;
        switch(op){
            case 1:{
                Postulante nuevo;
                system("cls");
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
            case 2:{
                system("cls");
                mostrarPostulante(postulantes,numPostulantes);
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
void mostrarPostulante(Postulante lista[],int cantidad){
    string ciclo[]={"cepu","fase"} ;
    string canales[]={"1","2","3","4"};
    for(int i=0; i<2 ; i++){ //ESTO ES PARA QUE LOS CICLOS AVANCEN
        for(int j=0 ; j<4 ; j++){ //ESTO ES PARA QUE LOS CANALES AVANCEN
            cout<<"Ciclo: "<<ciclo[i]<<" | "<<"Canal :"<<canales[j]<<endl;
            cout<<"--------------------------------------------------"<<endl;
            int encontrado=0;
            for(int k=0 ; k < cantidad ; k++){
                if(lista[k].ciclo == ciclo[i] && lista[k].canal == canales[j]){
                    cout<<"DNI: "<<lista[k].DNI<<"  ";
                    cout<<"Nombres: "<<lista[k].nomCompletos<<"  "<<endl;
                    cout<<"----------------------------------------"<<endl;
                    encontrado=1;
                }
            }
            if(encontrado==0){
                cout<<"Sin postulantes en este grupo"<<endl;
                cout<<"----------------------------------------"<<endl;
            }
        }
        
    }
    if(cantidad == 0){
        cout<<"No hay postulantes"<<endl;
    }
}