#include <iostream>
#include <vector>

class P
{
    public:
        P()
        {
            std::cout << "P created" << std::endl;
        }
        P(const std::string& n)
        {
            std::cout << "P created with "<< n << std::endl;
        }
};

class Person
{   
    public:
    P p;
    int no;

    public:
        Person(std::string na, int n): p(na),no(n){
        }
        Person():p("default"), no(0){}

};

int main()
{
    std::vector<std::vector<int>> v1 = {{1,2},{3,5}};
    
    std::vector<int> temp;
    temp = v1[0];
    std::cout << temp[0] << " " << temp[1];
    std::cout << std::endl;

    
    std::string s = "Sankalp is a C++ developer";
    std::string sub_s = s.substr(6,1500);

    std::cout << s<< std::endl;
    std::cout << sub_s<< std::endl;

    Person p("Aditya",3);
    Person p2;
    //std::cout<< p.name << " " << p.no << std::endl;
    return 0;

}

