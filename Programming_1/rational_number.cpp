#include <iostream>

using namespace std;

class Racional{
    private:
    int numerador, denominador;
    void Reduce();
    public:
    void setNumber(int, int);
    void suma(int, int);
    void resta(int, int);
    void division(int, int);
    void multiplicacion(int, int);
    int getNumber();
    void print();
    void printDecimal();
};

void Racional::Reduce(){
    int i = numerador*denominador;

    while(i > 1){
        if ((numerador%i == 0) && (denominador%i == 0)){
            numerador = numerador/i;
            denominador = denominador/i;
        }
        i--;
    }
       
}

void Racional::setNumber(int numerator, int denominator){
    numerador = numerator;
    denominador = denominator;
    Reduce();
}

void Racional::suma(int numerator, int denominator){
    numerador += numerator;
    denominador += denominator;
    Reduce();

}

void Racional::resta(int numerator, int denominator){
    numerador -= numerator;
    denominador -= denominator;
    Reduce();

}

void Racional::multiplicacion(int numerator, int denominator){
    numerador *= numerator;
    denominador *= denominator;
    Reduce();

}

void Racional::division(int numerator, int denominator){
    numerador *= denominator;
    denominador *= numerator;
    Reduce();

}

int Racional::getNumber(){
    return numerador, denominador;
}

void Racional::print(){
    cout << numerador << "/" << denominador << endl;
}

void Racional::printDecimal(){
    float total = static_cast<float>(numerador)/denominador;
    cout << total << endl;
}


int main(){
    Racional numero_1;

    numero_1.setNumber(2,4);
    numero_1.suma(1,5);
    numero_1.print();
    numero_1.printDecimal();
    return 0;
}