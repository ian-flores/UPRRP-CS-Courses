/* Author: Ian Flores Siaca
Input: Instructions
Output: A drawing of an array */

#include <iostream>
#include <string>

using namespace std;

int main(){
    const int SIZE = 20;
    char piso [SIZE][SIZE] = {}; 

    char input[6]; 

    int movimiento, pluma, direccion, row, column = 0;
    // pluma 0 = up; 1 = down;
    // direccion 0 = right; 1 = down; 2 = left; 3 = up;

    // Instrucciones
    cout << "These program is a simple implementation" << endl;
    cout << "of the Logo programming language\n\n" << endl;
    cout << "\t\tInstructions\n\n" << endl;
    cout << "\t1: Pen Up" << endl;
    cout << "\t2: Pen Down" << endl;
    cout << "\t3: Turn Right" << endl;
    cout << "\t4: Turn Left" << endl;
    cout << "\t5, X: Move X spaces" << endl;
    cout << "\t6: Show The Figure" << endl;
    cout << "\t7: Reset the array" << endl;
    cout << "\t8, X: Print a Triangle of height X"<< endl;
    cout << "\t9: Quit" << endl;
    cout << endl;

    //Input 
    cout << "Enter the instructions" << endl;
    cin.getline(input, 6);
    cout << endl;

    while (input[0] != '9'){

    // Extracts the instruction command
    int instruccion = int(input[0]) - '0';

    string temp;    
    
    if (instruccion == 1){         // Sees if pen is up or down
        pluma = 0;
    } else if (instruccion == 2){
        pluma = 1;
    } else if (instruccion == 3){ // Direction of the turtle
        direccion = (direccion + 1)%4;
    } else if (instruccion == 4){
        direccion = (direccion - 1)%4;
    } else if (instruccion == 5){   // Extracts the movements number if the instruction is 5.
            temp += input[3];
            temp += input[4];
            movimiento = atoi(temp.c_str());
            if (direccion == 1){
                for (int i = 0; i < movimiento; i++){
                    if (pluma) {
                        piso[i + row][column] = '1';
                    }
                } row = row + movimiento;
            } else if (direccion == 3){
            for (int i = 0; i < movimiento; i++){
                if (pluma) {
                    piso[row - i][column] = '1';
                } 
            } row = row - movimiento;
            } else if (direccion == 0){
            for (int i = 0; i < movimiento; i++){
                if (pluma) {
                    piso[row][i + column] = '1';
                }
            } column = column + movimiento;           
            } else if (direccion == 2){
            for (int i = 0; i < movimiento; i++){
                if (pluma) {
                    piso[row][column - i] = '1';
                } 
            } column = column - movimiento;
            }
    } else if (instruccion == 6){   // Prints the array
        cout << endl;
        for (int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                if (piso[i][j] == '1'){
                    cout << "* ";
                } else {
                    cout << "  " ;
                } 
            } cout << endl;
        } //cout << endl;
    } else if (instruccion == 7){ // resets the array
        memset(piso, '0', 400);
    } else if (instruccion == 8){ // Prints Triangle
        if (pluma){
            temp += input[3];
            temp += input[4];
            int height = atoi(temp.c_str());
            string ast;
            for (int i=0; i < height; i++){
                for (int j = 0; j <= i; j++){
                    cout << "* ";
                } cout << endl;
            } cout << endl; 
        }
    }     
    
    // Display instructions
    cout << "\n\t\tInstructions\n\n" << endl;
    cout << "\t1: Pen Up" << endl;
    cout << "\t2: Pen Down" << endl;
    cout << "\t3: Turn Right" << endl;
    cout << "\t4: Turn Left" << endl;
    cout << "\t5, X: Move X spaces" << endl;
    cout << "\t6: Show The Figure" << endl;
    cout << "\t7: Reset the array" << endl;
    cout << "\t8, X: Print a Triangle of height X"<< endl;
    cout << "\t9: Quit" << endl;
    cout << endl;
    
    // Get the following input
    cout << "Enter the instructions" << endl;
    cin.getline(input, 6);
    cout << endl;
    }
    return 0;
}
