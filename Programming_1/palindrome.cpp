/* Autor: Ian Flores
Entrada: Palabra
Salida: Determinacion sobre la palabra
Descripcion: Este programa verifica si la palabra que el usuario escribe, 
es en efecto una palabra palindrome o no */

#include <iostream>

using namespace std;


int main(){
    cout << "Saludos, este programa verificara" <<
            " si la palabra que usted entre, es" <<
            " o no palindrome." << endl;
    cout << endl;

    char word_array[5];
    cout << "Por favor, escriba una palabra: " << endl;
    cout << " " << endl; 

    cin >> word_array;
    cout << " " << endl; 

    int palindrome; 
    for (int i = 0; i <= 2; i++){
        if(word_array[i] != word_array[4-i]){
            palindrome = 0;
        } else {
            palindrome = 1;
        }
    }

    if (palindrome == 1){
        cout << "La palabra es palindrome." << endl; 
    } else{ 
        cout << "La palabra no es palindrome" << endl; 
    }
    return 0;
}
   