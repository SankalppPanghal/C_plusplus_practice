#include <iostream>
#include <memory>

class Sensor {
    public:
        void readData(){
            std::cout<< "Sensor reading: Normal" << std::endl;
        }
};

int main(){

    //Using modern C++ smart pointers instead of raw malloc/new
    std::unique_ptr<Sensor> mySensor = std::make_unique<Sensor>();
    mySensor->readData();
}

// Topics left to cover
// Bitwise
// BST - post order calculator
// strign frequency
// heap
// Sorting**
// Array vs vector vs List