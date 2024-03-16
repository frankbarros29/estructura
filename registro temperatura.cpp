#include<iostream>


using namespace std;

struct Temperatura {
    float valor;
    char momento[50];
};

struct capturaTemperatura {
    char fecha[50];
    Temperatura manana;
    Temperatura tarde;
    Temperatura noche;
};

int main() {
    int opcion;
    int numDias;
    capturaTemperatura* registros = NULL;
    float promedio;

    do {
        cout<<"\nMenu:\n";
        cout<<"1. capturar temperatura\n";
        cout<<"2. Mostrar registros capturados\n";
        cout<<"3. Calcular promedio de temperatura del dia\n";
        cout<<"4. Calcular promedio de todas las temperaturas registradas\n";
        cout<<"0. Salir\n";
        cout<<"precione una opcion: ";
        cin>>opcion;
        cout<<endl; 

        switch (opcion) {
            case 1:
                cout<<"Inserte el numero de dias a registrar: ";
                cin>>numDias;
                registros = (capturaTemperatura*)malloc(numDias * sizeof(capturaTemperatura));
                for (int i= 0; i < numDias; ++i) {
                    cout<<"Dia " << i+1 << endl;
                    cout<<"Fecha (D/M/A): ";
                    cin>>registros[i].fecha;
                    cout<<"Temperatura de la manana: ";
                    cin>>registros[i].manana.valor;
                    cout<<"Momento de la manana: ";
                    cin>>registros[i].manana.momento;
                    cout<<"Temperatura de la tarde: ";
                    cin>>registros[i].tarde.valor;
                    cout<<"Momento de la tarde: ";
                    cin>>registros[i].tarde.momento;
                    cout<<"Temperatura de la noche: ";
                    cin>>registros[i].noche.valor;
                    cout<<"Momento de la noche: ";
                    cin>> registros[i].noche.momento;
                    cout<< endl; 
                }
                break;
            case 2:
                if (registros==NULL) {
                    cout<<"No existe registros disponibles.\n";
                } else {
                    cout<<"\nRegistros de temperatura:\n";
                    for (int i= 0; i < numDias; ++i) {
                        cout<<"Dia " << i+1 << ": " << registros[i].fecha << endl;
                        cout<<"   manana:"<< registros[i].manana.valor<<" grados, "<<registros[i].manana.momento<<endl;
                        cout<<"   Tarde: "<<registros[i].tarde.valor<<" grados, "<<registros[i].tarde.momento<<endl;
                        cout<<"   Noche: "<<registros[i].noche.valor<<" grados, "<<registros[i].noche.momento<<endl;
                    }
                }
                break;
            case 3:
                if (registros==NULL) {
                    cout<<"No existe registros disponibles.\n";
                }else {
                    cout<<"\nPromedio de temperatura del dia:\n";
                    for(int i= 0; i < numDias; ++i) {
                        float promedioDia= (registros[i].manana.valor + registros[i].tarde.valor + registros[i].noche.valor) / 3.0;
                        cout<<"Dia "<< i+1 <<": "<<promedioDia<<" grados\n";
                    }
                }
                break;
            case 4:
                if (registros== NULL) {
                    cout<<"No existe registros disponibles.\n";
                } else {
                    float sumaTotal = 0;
                    for (int i = 0; i < numDias; ++i) {
                        sumaTotal += (registros[i].manana.valor + registros[i].tarde.valor + registros[i].noche.valor);
                    }
                    promedio= sumaTotal/(numDias * 3);
                    cout<<"\nPromedio de todas las temperaturas registradas o capturadas: "<<promedio<<" grados\n";
                }
                break;
            case 0:
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Opcion no valida. Por favor seleccione una opcion valida.\n";
                break;
        }
    } while (opcion!=0);

    free(registros);

    return 0;
}