#include <iostream>
#include <cstring>

template <typename T> T maximum(T a, T b); //declaring the function template 

template<>
const char* maximum<const char*> (const char* a, const char* b); //BY DOING THIS WE'RE ESSENTIALLY OVERLOADING CORRECTLY THE FUNCTION, this is called template specializations that is when we specify what this function will do when this happens, in this case we're declaring it here and defining it later, but everytime we do the maximum function and send in const char*, the function will play this specific version of it instead of the normal maximum function

//there's some curious facts to note about this, because T is the type of variable, for this example, both variables we put onto that function must be of the same type, also DONT USE POINTERS, can give a lot of erros, because if we send in a pointer, T will be recognized as a pointer so it will return the adress or compare the adress, that is no good as when we use pointer we dont wanna mess with the adress but yes with the value in that adress

template <typename T> T minimum(T a, T b){ //we can also declare and define function templates like so
    return (a < b)? a : b;
}

//this is us declaring a template function but with references, this is better as it uses the same adress and doenst create new memory, I have a little bug in here, dont know why, ask Tom when you get the chance, it works with Clang, but not with GCC
template <typename T> const T& sum(const T& a, const T& b){ 
    std::cout << "In Adress: " << &a << std::endl;
    T result = a + b;
    return result;
}

//by doing this we're essentially overloading the function which bugs the hell out of the compiler and even gives you an error in visual studio code
/*template <typename T> T sum(T a, T b){
    return (a + b);
}*/

int main(){
    
    std::cout << maximum(25, 35) << std::endl; //deduces its a int type
    
    std::cout << maximum<double>(25,353) << std::endl; //because we put in the <double>, the compiler will turn 25 and 353 to double values, if we put in a string the compiler will get an error as a string cannot be converted to a double
    
    const char* one {"Hello"};
    const char* two {"World"};
    
    std::cout << maximum(one, two) << std::endl;
    
    
    int a = 112;
    int b = 8;
    
    std::cout << "Out Adress: " << &a << std::endl;
    
    auto result = sum(a,b);
    
    std::cout << "Calculation: " << result << std::endl;
        
    return 0;
}

template <typename T> T maximum(T a, T b){ //defining it
    return (a > b)? a : b; //returns a if true, b if false
}

template<>
const char* maximum<const char*> (const char* a, const char* b){ //in here we declare and specify what this function will actually do, in contrast to the previous one
    return (std::strcmp(a,b) > 0)? a: b;
}