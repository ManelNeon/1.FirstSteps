#include <iostream>

template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; //Simple requirement : Only enforces syntax, so in a case where it is a double, this syntax is false, so it will just skip it, the compiler will still work
    requires sizeof(T) <= 4; //now with this nested requirement, this will not compile unless it is less than 4
};

TinyType auto add(TinyType auto a, TinyType auto b){
    return a + b;
}

//Compound requirement
template <typename T>
concept Addable = requires(T a, T b){
    //{a + b} noexcept -> std::convertible_to<int>; We can put noexcept here, yet I dont know what it does or means, ask Tom
    {a + b} -> std::convertible_to<int>; //Checks if a + b is valid syntax and that the result is convertible to int
};

Addable auto NewAdd(Addable auto a, Addable auto b){
    return a + b;
}

//we can use the && and || operators to put various concepts in the same function template, for example

template <typename T>
//T func(T t) requires Addable<T> && TinyType<T>; //using &&
//T func(T t) requires Addable<T> || TinyType<T>; //using ||
T func(T t) requires std::integral<T> &&
                                        requires(T t){
                                            sizeof(T) <= 4;
                                            requires sizeof(T) <= 4;
                                        }; //last way we can use the various requirements, more complicated, didnt like it, ugly, very ugly, Although I only did this with declarations and not defining the functions, we can also after this define the function no problem, I just think it's very ugly


int main(){
    
    int x{67};
    int y{56};
    
    add(x,y);
    
    char a{45};
    char b{145};
    
    NewAdd(a,b);//in the compound requirement we're checking if the result is convertible to int, in case we put strings here, while strings are addable, the result wont be convertible so it will give us an error
    
    std::integral auto b = add(x,y); //we can also use concepts with auto variables! lIKE the instructor said, this doenst seem to be that useful, but it is good to know we can put this extra layer of protection to our code!
    
    return 0;
}