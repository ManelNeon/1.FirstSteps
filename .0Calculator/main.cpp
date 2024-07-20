#include <iostream>
#include "calculations.h"

using namespace std;

void InvalidResponse(){
    cout << "Invalid... Restarting..." << endl;
    StartUp();
}

void EndingApp(){
    cout << "Ending the app." << endl;
    return;
}

void StartUp(){
    
    string calculationDevice = "";
    
    cout << "Welcome to Calculator 3000!" << endl;
    cout << "You can quit anytime by inputing NN";
    cout << "What type of calculation do you want to make? (+, -, * or x, /)" << endl;
    
    cin >> calculationDevice;
    
    if (calculationDevice == "+"){
        string numberOne = "";
        string numberTwo = "";
        cout << "Great! Now input the first number!";
        cin >> numberOne;
        for (size_t i = 0; i < size(numberOne); ++i){
            if (!isdigit(numberOne[i])){
                InvalidResponse();
                //check if the application bugs;
                return;
            }
        }
        cout << "Great! Now input the second number!";
        cin >> numberTwo;
        for (size_t i = 0; i < size(numberOne); ++i){
            if (!isdigit(numberOne[i])){
                InvalidResponse();
                //check if the application bugs;
                return;
            }
        }
    }
    else if (calculationDevice == "-"){
        //minus
    }
    else if (calculationDevice == "*" || calculationDevice == "x"){
        //multiply
    }
    else if (calculationDevice == "/"){
        //divide
    }
    else if (calculationDevice == "NN"){
        EndingApp();   
    }
    else {
        InvalidResponse();
    }
}

//for funsies I'll make a calculator on the console
int main(){
    
    StartUp();
    
    return 0;
}