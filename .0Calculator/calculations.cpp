#include <iostream>

using namespace std;

void Multiplication(double a, double b){
    cout << "The result of the multiplication is: " << a * b << endl;
}

void Division(double a, double b){
    if (b == 0){
        cout << "Can't divide numbers by 0";  
        return;     
    }
    cout << "The result of the division is: " << a / b << endl;
}

void Sum(double a, double b){
    cout << "The result of the addition is: " << a + b << endl;
}

void Subtraction(double a, double b){
    cout << "The result of the subtraction is: " << a - b << endl;
}