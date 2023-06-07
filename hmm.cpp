#include <iostream>

template <typename T1, typename T2> // function template with multiple parameter
void display(T1 value1, T2 value2){
    std::cout << "Display two values: "<< value1 << " and " << value2 << std::endl;
}

template <typename T1, typename T2, typename T3> //template overloaded
void display(T1 value1, T2 value2, T3 value3){
    std::cout << "Display three values: "<< value1 << ", "<< value2 << ", and "<< value3 << std::endl;
}

template <typename T1, typename T2> //class template with multiple parameter
class Pair{
    private:
    T1 first;
    T2 second;
    
    public:
    Pair(T1 first, T2 second) : first(first), second(second){}
    
    void display(){
        std::cout << "First: "<< first << ", Second: "<< second << std::endl;
    }
};

int main(){
    display(10,20);
    display("Hello", 3.14, true);
    
    Pair<int,double> p1(5,3.14);
    p1.display();
    
    Pair<std::string, bool> p2("Hmmm",true);
    p2.display();
    
    return 0;
}