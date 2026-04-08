#include <iostream>
#include <unordered_map>
#include <string>

int main()
{

    std::unordered_map<std::string, int> ages = {{"Sankalp",28}, {"Rohan",27} , {"Yash", 30}};

    ages["Kartik"] = 20;

    ages["Sankalp"] = 29;

    std::cout << ages.size() << std::endl;
    std::cout << "Kartik age is: " << ages["Kartik"] << std::endl;
    std::cout << "Sankalp age is: " << ages["Sankalp"] << std::endl;

    if (ages.find("Yash") != ages.end())
    {
        std::cout << "Yash age is: " << ages["Yash"] << std::endl;
    }

    if (ages.find("Charlie") == ages.end())
    {
        std::cout << "Charlie not in map" << std::endl;
    }

    //1. 
    // auto automatically figures out the type is std::unordered_map<std::string, int>::iterator
    auto it = ages.find("Yash"); 

    if (it != ages.end()) {
        // it->first is the key ("Yash")
        // it->second is the value
        std::cout << "Yash age is: " << it->second << "\n"; 
    } else {
        std::cout << "Yash is not in the map.\n";
    }

    //2.
    // try catch block
    try{
        std::cout << "Yash age is: " << ages.at("Yash") << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Yash is not in map" << std::endl;
    }

    ages.erase("Yash");

    for(const auto& [name,age] : ages)
    {
        std::cout << name << ": " << age << std::endl; 
    }

    for(const auto& it2 : ages)
    {
        std::cout << it2.first << ": " << it2.second << std::endl; 
    }

    return 0;
}