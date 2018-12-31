/*Autor: Ian Flores
Entrada: Numero cifrado
Salida: Numero sin cifrar
Descripcion: Este programa descifrara el numero 
que el usuario escriba. */

#include <iostream>
using namespace std;

int main(){

    char entrada[4]; 
    cout << "Este programa le proveera el numero sin cifrar de 4 digitos que usted escriba" << endl;
    cout << endl;
    cout << "Ingrese el entero de 4 digitos: ";
    cout << endl;
    cin >> entrada;

    int numeros[4];
    int num; 

    for (int i = 0; i < 4; i++){
        num = int(entrada[i]) - '0';
        num = (num - 7 + 10)%10;
        numeros[i] = num;
    }

    int out[4];

    out[0] = numeros[2];
    out[1] = numeros[3];
    out[2] = numeros[0];
    out[3] = numeros[1];

    cout << " " << endl; 
    cout << "Su numero sin cifrado es: " << endl;
    for(int i = 0; i < 4; i++){
        cout << out[i]; 
    }
    
    cout << " " << endl;

    return 0; 
}