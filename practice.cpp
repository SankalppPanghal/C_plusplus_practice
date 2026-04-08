#include <iostream>
#include <string>
#include "print.cpp"

template<typename T>
void print(T val);

class player
{
    private:
        std::string name{""};
        int kit_no{0};
        int overall{0};
    
    public:
        player() = default;

        player(std::string n, int kno, int ovr)
        {
            name = n; kit_no = kno; overall = ovr;
        }

        std::string getName ()
        {
            return name;
        }
};

int main()
{
    int a{5};
    print(a);


    player p("Sankalp", 5, 85);
    print(p.getName());

    return 0;
}