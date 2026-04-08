#include <iostream>
#include <string>

template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print(5);
    Print<std::string>("Sankalp");
    Print(5.5f);
    return 0;
}