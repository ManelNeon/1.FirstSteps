#include <iostream>

void BeginningTheStudy(){
    
    auto func = [](){
    std::cout << "Hello World" << std::endl;
    }; //assigning a lambda function directly to a variable
    
    [](){
        std::cout << "Hello Mom" << std::endl;
    }(); //doing that lambda function immeaditly
    
    func(); // calling the variable calls the function
    
    int one = 15;
    int two = 25;
    
    [](int a, int b){
        std::cout << a + b << std::endl;
    }(one,two); //this is where you put the parameters in a lambda function
    
    auto result = [](int a, int b){
        return a + b;
    }(one, two); //this is a lambda function where we will store a result, because we returned it
    
    std::cout << result << std::endl; //you can also put a lambda function directly on the out stream, yet that does not seem efective at all
    
    auto resultt = [](double a, double b)->double{
        return a + b;
    }(15.23,12.23); //by puttint the "->double" we're specifying that we return a double, so resultt will be a double variable
    
    std::cout << resultt << std::endl;
    
    auto funcc = [](double a, double b)->double{
        return a + b;
    };
    
    auto resulttt = funcc(12.23, 13.24); //we can also do this, and resulttt will be there result of that function
    
}

void CaptureList(){
    
    int a = 23;
    
    auto func = [a](){ //the capture list makes it possible to send variables to inside the lambda function
        std::cout << "Inner Value: " << a << std::endl;
    };
    
    for (size_t i = 0 ; i < 5; ++i){
        ++a;
        std::cout << "Outer Value: " << a << std::endl;
        func(); //by doing this test, we can see that the a inside the lambda function is a copy, so the value will always be 23, if we do the exat same thing but with a reference, then the value will change, references are op
    }
}

void CaptureAll(){
    
    int a = 23;
    int b = 14;
    
    auto func = [&](){ //by putting the = sign, it will capture every single variable by value (a copy), if we put &, we're capturing everything BY REFERENCE, op op 
        std::cout << "Inner Value: " << a  + b << std::endl;
    };
    
    for (size_t i = 0 ; i < 5; ++i){
        ++a;
        std::cout << "Outer Value: " << a  + b << std::endl;
        func();
    }
}

int main(){
    
    int a = 23;
    
    int* aPointer = &a;
    
    auto func = [aPointer](){
        std::cout << "Inner Value: " << *aPointer << std::endl;
    };
    
    for (size_t i = 0 ; i < 5; ++i){
        ++*aPointer;
        std::cout << "Outer Value: " << *aPointer << std::endl;
        func();
    }
        
    //just testing and playint with pointers as they are still a little fresh on my mind
    
    return 0;
}