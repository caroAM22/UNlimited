#include <iostream>
using namespace std;

int main() {
    // Para probarlo comenta estas lineas, para enviarlo las descomentas
    // freopen("cowsignal.in", "r", stdin);
    // freopen("cowsignal.out", "w", stdout);
    int filas, columnas, incremento;
    //lee los datos directamente y todos, te faltaba leer uno, el incremento, no siempre va a ser 2
    cin >> filas;
    cin >> columnas;
    cin >> incremento;
    // bien 
    char matriz[filas][columnas];
    
    // muy bien
    for(int i = 0; i < filas; i++){
        for(int j =0; j<columnas; j++){
            cin >> matriz[i][j];
        }
    }
    // lo del incremento, lo tenias con 2 y hacer una operacion entre 2 y char da error. es mejor hacer dobles for 
    for(int i = 0; i < filas; i++){
        for(int k=0; k<incremento; k++){
            for(int j =0; j<columnas; j++){
                for(int l=0; l<incremento;l++){
                    cout << matriz[i][j];
                }
            }
            // salto de linea es así 
            cout << "\n";
        }
    }
    return 0;
}