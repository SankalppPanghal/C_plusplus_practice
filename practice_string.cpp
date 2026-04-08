#include <iostream>
#include <string>

int main()
{
    std::string greeting = "Hello World ";
    std::string name(5,'a');

    std::string message = greeting + "and universe";
    message += "!";

    char first = message[0];
    char second = message.at(1);
    std:: cout << "message -> " << message << std::endl;
    std::cout<< "message.length() -> " << message.length() << std::endl;

    // (starting_index, length_of_chunk) ~Can go out of scope 
    message = message + "World";
    std:: cout << "message -> " << message << std::endl;
    std::string sub = message.substr(1,1000);
    std::cout << "sub -> " << sub << std::endl;
    
    size_t pos = message.find("World");

    if (pos != std::string::npos)
    {
        std::cout << "Found 'World' at index: " << pos << std::endl;
    }

    pos = message.find("World", pos+26);
    
    if (pos != std::string::npos)
    {
        std::cout << "Found 'World' at index: " << pos << std::endl;
    }

    return 0;
}