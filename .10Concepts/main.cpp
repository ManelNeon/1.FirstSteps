#include <iostream>
#include <type_traits>
//about concepts, ask Tom firstly why can I use them without using #include <concepts>, also that it seems a bit convolucted and repetitive, seeing great use-case scenarios yet it seems confusing and leaves me head scratching


//Syntax 1
template <typename T>
requires std::integral<T>
T add(T a, T b){
    return a + b;
}

//Syntax 2
template <std::integral T>
T subtract(T a, T b){
    return a - b;
}

//new way to make function templates, Syntax 3
auto divide(std::integral auto a, std::integral auto b){
    return a / b;
}

//Syntax 4
template <typename T>
T multiply(T a, T b) requires std::integral<T>{
    return a * b;
}

//https://en.cppreference.com/w/cpp/concepts

//custom Concepts

template <typename T>
concept MyIntegral = std::is_integral_v<T>;

//with the custom concept created, we can create a function template using that concept

template <typename T>
requires MyIntegral<T>
T AddingNumbers(T a, T b){
    return a + b;
}

//differnt ways we could use concepts before can be used using custom concepts too
template <MyIntegral T>
T SubtractingNumbers(T a, T b){
    return a - b;
}

//what this code does and is very useful is, it verifies if the syntax is valid, if we put in strings, we cannot multiply strings so it would give us a compiler error, but if we put in doubles ou integers it would work
template <typename T>
concept Multipliable = requires (T a, T b){
    a * b;
};

template <typename T>
requires Multipliable<T>
T MultplyingNumbers(T a, T b){
    return a * b;
}

//this verifies if the variable put into a function that requires Incrementable, will have to be well... incrementable, that it can add upon itself
template <typename T>
concept Incrementable = requires (T a){
    a+=1;
    ++a;
    a++;
};

template <typename T>
requires Incrementable<T>
T AnotherAddingNumbers(T a, T b){
    return a + b;
}

int main(){
    
    std::cout << add(25, 35) << std::endl;
    
    std::cout << MultplyingNumbers(24.22, 2213.23) << std::endl;
    
    //std::cout << MultplyingNumbers("XXX", "XXX") << std::endl; // Because we're verifying if its possible to multiply numbers this gives us an error
    
    return 0;
}