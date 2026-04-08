#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
    private:
        T m_Array[N];
    public:
        int GetSize() const{return N;}

};

//Will be created at compile time according to when Print is used
template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Array<std::string, 55> array;
    Print(array.GetSize());
    std::cin.get();
}