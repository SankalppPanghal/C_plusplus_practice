#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Back: " << q.back() << "\n";

    std::cout << "q.size(): "<<q.size() << std::endl;

    q.pop();

    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}