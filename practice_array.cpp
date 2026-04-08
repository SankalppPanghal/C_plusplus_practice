#include <iostream>
#include <array>

int main()
{
    std::array<int,5> scores = {90, 85, 95, 100, 80};

    int a = scores[0]; 
    int b = scores.at(1);
    
    std::cout << "Size of array scores is " << scores.size() << std::endl;

    scores[0] = 99;

    for(int score: scores)
    {
        std::cout << score << " ";
    }   
    std::cout << std::endl;

    scores.fill(0);


    return 0;
}