#include <iostream>
#include <string_view>

//in classes, members are private by default
class Dog{
    public:
        Dog() = default;
        Dog(std::string_view nameParam, std::string_view breedParam, int ageParam);
        ~Dog(); //syntax to declare a destructor
        
        void PrintInfo(){
            std::cout << name << " " << breed << " " << *pAge << std::endl;
        }
        
        //Setters
        /*void SetDogName(std::string_view name){
            this->name = name;
            //just like C#, yet in C++, due to this being a pointer, we need to do the -> that we usually do with pointers
        }
        
        void SetDogBreed(std::string_view breed){
            this->breed = breed;
        }
        
        void SetDogAge(int age){
            *(this->pAge) = age;
        }this is one way of doing the setters*/
        
        /*Dog* SetDogName(std::string_view name){
            this->name = name;
            return this;
            //we can then return this as a pointer and that gives us a cool little trick we'll see in the main
        }
        
        Dog* SetDogBreed(std::string_view breed){
            this->breed = breed;
            return this;
        }
        
        Dog* SetDogAge(int age){
            *(this->pAge) = age;
            return this;
        }*/
       
        Dog& SetDogName(std::string_view name){
            this->name = name;
            return *this;
            //we can also return a reference by dereferencing the this pointer, and this gives us a similar trick to the pointer one
        }
        
        Dog& SetDogBreed(std::string_view breed){
            this->breed = breed;
            return *this;
        }
        
        Dog& SetDogAge(int age){
            *(this->pAge) = age;
            return *this;
        }
        
    private:
        std::string name = "None";
        std::string breed = "None";
        int* pAge {nullptr};
};

Dog::Dog(std::string_view nameParam, std::string_view breedParam, int ageParam){
    name = nameParam;
    breed = breedParam;
    pAge = new int{ageParam};
    std::cout << "Created memory for the age in the heap for " << name << " at " << this << std::endl;
    //in this case "this" will print out the adress of this constructor
}

Dog::~Dog(){
    delete pAge;
    std::cout << "Deleted age memory in the heap for " << name << " at " << this <<std::endl;
}

//in structs members are public by default
struct Cat{
    int age {};
};

int main(){
    Dog dog("Jose", "Cavalo", 2);
    dog.PrintInfo();
    
    dog.SetDogName("Antonio");
    dog.SetDogBreed("Cao");
    dog.SetDogAge(5);
    
    dog.PrintInfo();
    
    //dog.SetDogName("Lisboa")->SetDogBreed("Xanax")->SetDogAge(4); this is how you do it when the setters return a pointer
    
    dog.SetDogName("Lisboa").SetDogBreed("Xanax").SetDogAge(4); //this is how you do it when the stters return a reference
    
    dog.PrintInfo();
    
    std::cout << sizeof(dog) << std::endl;
    
    Cat cat;
    
    cat.age = 25;
    
    std::cout << cat.age << std::endl;
    
    std::cout << sizeof(cat) << std::endl;
    
    return 0;
}