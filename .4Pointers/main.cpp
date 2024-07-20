#include <iostream>
#include <string>

void TestingPointers(){
    
    //declaring and initializing pointer
    int* pNumber {}; //by putting the curly braces with nothing, that initializes the pointer with nullptr
    double* pFractionalNumber {nullptr}; //intializing with nullptr yet it's the same
    
    //testing
    int* pNumber1 {}, number1 {};
    
    std::cout << "Size of (pNumber1): " << sizeof(pNumber1) << std::endl; //also pointers always have a 8 byte size
    std::cout << "Size of (number1): " << sizeof(number1) << std::endl; // meanwhile this one only has 4 bytes
    //with this we conclude, if I put a pointer variable like I did, the second one wont be a pointer, but a intenger by itself
        
    //better to do it like this imo
    int* pNumber2 {};
    int number2 {};
    
    //testing now how to save the adress of a variable
    int number3 {3543};
    int* pNumber3 {&number3};
    
    std::cout << "Int var: " << number3 << std::endl;
    std::cout << "Adress of int var: " << pNumber3 << std::endl;
    
    int number4 {22334};
    
    pNumber3 = &number4;
    
    std::cout << "Adress of new int var: " << pNumber3 << std::endl;
    
    //as it's obvious, a int pointer cant store a double adress, as cant a double pointer store a int adress
    
    //Getting the value directly from the adress, I'm sure this will come in handy
    int* pNumber5 {};
    int number5 {2249};
    pNumber5 = &number5;
    
    std::cout << "Number 5 value: " << *pNumber5 << std::endl; //ah, just, putting the pointer thingy before...     
}

void CharacterPointers(){
    
    const char* pMessage { "Hello World"};
    
    std::cout << pMessage << std::endl;
    
    std::cout << *pMessage << std::endl;
}

void HeapPointers1(){
    
    //so in here Im creating a pointer to a variable in the heap instead of the stack (REMEMBER THESE TERMS), im doing this directly woth a value of 25
    int* pNumber = new int(25);
    
    std::cout << pNumber << std::endl; //then Im getting the adress of that number in the heap
    
    std::cout << sizeof(pNumber) << std::endl; //getting it's size, it's 8, as pointers ocuppy 8 bytes
    
    std::cout << *pNumber << std::endl; //then Im getting the value in that adress, that gives me 25
    
    std::cout << sizeof(*pNumber) << std::endl; //and getting the size of the variable in that adress, and because its a int, it ocuppies 4 bytes
    
    delete pNumber; //finally delete that variable from the heap memory
    pNumber = nullptr; //and set the pointer to nullptr just to be safe and not shoot myself on the foot
}

void CrashingPointers(){
    
    //this pointer has no adress initialized, JUNK, testing for testing purposes
    int* pointer;
    
    std::cout << "Adress: " << pointer << std::endl;
    
    std::cout << "Value in that Adress: " << *pointer << std::endl;
    
    //in this example, where I create space in the Heap, delete it and then check the value, it's something completely random, giving me -1227969632
    int* pointer2 = new int(22);
    
    delete pointer2;
    
    std::cout << "Adress: " << pointer2 << std::endl;
    
    std::cout << "Value in that Adress: " << *pointer2 << std::endl;
}

void OutOfMemory(){
    
    //this doesn't end well, not at all, so basically out of memory!
    int* data = new int[10000000000000];
    
    //same thing yet with a for cycle
    for (size_t i = 0; i < 10000000; ++i){
        int* data = new int[10000000000000];
    }
    
    //using a try catch, so that the program wont crash, havent used one in ages, good to remind me of some basics
    for (size_t i = 0; i < 10000000; ++i){
        
        try{
            int* data = new int[10000000000];
        }
        catch(std::exception& ex){
            std::cout << "Something went wrong: " << ex.what() << std::endl;
            break;
        }
    }
    
    //creating an expcetion using std::nothrow, is nice, yet I do feel like if I pay attention to my code this wont happen ever... Yet in a team enviroment I can see why this is useful
    for (size_t i = 0; i < 100; ++i){
        
        int* data = new(std::nothrow) int[100000000000000000];
        
        if (data != nullptr){
            std::cout << "Data allocated" << std::endl;
        }
        else {
            std::cout << "Data allocation failed" << std::endl;
        }
    }
    
    std::cout << "Program Ending Well" << std::endl;
}

void NullPointerSafety(){
    
    int* pointer {};
    
    //delete pointer; IT IS SAFE TO DO THIS, you can delete a nullptr, no problem in that, so no need to do a if(pointer != nullptr)
    
    //Checking if it's a nullptr... basic
    if (!(pointer == nullptr)){
        std::cout << "This pointer has a valid adress!" << std::endl;
    }
    else {
        std::cout << "This pointer doest not have a valid adress!" << std::endl;
    }
    
    //we can use the pointer directly, has if it does have a valid adress it will serve as a true bool, if not a false bool
    if (pointer){
        std::cout << "This pointer has a valid adress!" << std::endl;
    }
    else {
        std::cout << "This pointer does not have a valid adress!" << std::endl;
    }
}

void MemoryLeaks(){
    
    int* pointer = new int{65}; // points to some adress in the heap
    
    //Should be deleted here
    
    int number = 32;
    
    pointer = &number; //by doing this, we're doing a memory leak, as we lose the adress to the variable in the heap THIS IS A NO NO
    
    int* pointer2 = new int{2112}; //points to some adress in the heap
    
    //should be deleted here;
    
    pointer2 = new int{11221}; //points to a new adress in the heap, losing the previous one, causing a memory leak
    
    {
        int* pointer = new int{12211312};
    }//by doing this inside the braces and not deleting the pointer, we will have a memory leak, as that adress will still contain the data but with no way to access it
    
    //This is a problem because, we will be occupying memory in the heap with no way to access it **that i know off right now**, the thing is, the program will still be running, but the heap memory will be fuller than if we didn't delete that variable
}

void DynamicArrays(){
    
    //USE SIZE_T WHEN USING SIZES IN ARRAYS, THATS WHAT I UNDERSTOOD, BUT ASK TOM
    size_t size = 10;
    
    double* pSalaries = new double[size]; //salaries array will contain junk values from 0 to 9
    
    int* pStudents = new(std::nothrow) int[size]{}; //students will contain 0 in all values from 0 to 9
    
    double* pScores = new(std::nothrow) double[size]{1,2,3,4,5};//scores will contain 0 from 5 to 9
    
    //checking if pscores is not a nullptr
    if (pScores){
        std::cout << "Successfully allocated memory for scores!" << std::endl;
        
        //in here we cannot use Auto like we learnt before because array pointers do not have the same properties than "normal" arrays
        for (size_t i = 0; i < size; ++i){
            //in here we can see that we can check the value in the memory allocated array using the first or the second version, prefer the first one though
            std::cout << "Value: " << pScores[i] << " or " << *(pScores + i) << std::endl;
        }
    }
    
    //USE THE [] WHEN DELETING A POINTER ARRAY, OR WE WILL ONLY BE DELETING THE FIRST ONE OF THE ARRAY I THINK OR MAYBE NOT EVEN THAT, JUST USE THE []
    delete[] pSalaries;
    pSalaries = nullptr;
    
    delete[] pStudents;
    pStudents = nullptr;
    
    delete[] pScores;
    pScores = nullptr;
    
    //Static arrays vs Dynamic arrays
    
    int scores[10] {1,2,3,4,5,6,7,8,9,10};
    
    std::cout << "Scores size: " << std::size(scores) << std::endl;
    
    for (auto s : scores){
        std::cout << "Value: " << s << std::endl;
    }
    
    int* pScores1 = new int[10] {1,2,3,4,5,6,7,8,9,10};
    
    //std::cout << "PScores size: " std::size(pScores1) << std::endl; This doesnt work, as array pointers do not have the sam properties 
    
    /*
    This wont work too, for the same reason
    for (auto s : pScores1){
        std::cout << "Value: " << s << std::endl;
    }
    */
   
   delete pScores1;
   pScores1 = nullptr; 
}

int main(){
        
    return 0;
}