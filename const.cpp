#include <iostream>
#include <string>

class Entity
{
    private:
        int m_x{0}, m_y{0};
    public:
        // Entity(){}; one way
        Entity() = default;
        Entity(int x, int y)
        {
            m_x = x; m_y = y;
        }

        ~Entity(){std::cout << "entity object " << m_x << " deleted" << std::endl;}

        int getX() const // This method is not going to modify any class 
        {
            // m_x = 2; ILLEGAL
            return m_x;
        }

        int getX() // Cannot be called by const reference, because no guarantee here unless function is const
        {
            return m_x;
        }

};

void PrintEntityX(const Entity& e)
{
    std::cout << e.getX() << std::endl;
}

int main()
{
    std::unique_ptr<Entity> e = std::make_unique<Entity>(10,5);
    Entity* e2 = new Entity(5,0);
    Entity e3{7,-1};
    std::cout << e->getX() << std::endl;
    std::cout << e2->getX() << std::endl;
    PrintEntityX(e3);

    std::cout << std::cin.get() << std::endl;

    delete e2;
    return 0;
}