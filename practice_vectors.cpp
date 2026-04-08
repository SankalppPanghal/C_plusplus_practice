#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1; // v1 -> []
    std::vector<int> v2(5,10); // (size, value) | v2 -> [10,10,10,10,10]
    std::vector<int> v3(4); // (size) | will fill default value of type | 0 int false bool
    std::vector<int> v2_subcopy(v2.begin(),v2.begin()+2); 

    // From a standard array:
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> v5(arr, arr + n); 
    // Result: [10, 20, 30, 40]

    // From a slice of another vector (grab the first two elements):
    std::vector<int> source = {100, 200, 300, 400};
    std::vector<int> v6(source.begin(), source.begin() + 2);
    // Result: [100, 200]
    // std::cout << source.begin() << std::endl;
    
    std::cout << "v1 -> ";
    for(int n: v1)
        std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "v2 -> ";
    for(int n: v2)
        std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "v3 -> ";
    for(int n: v3)
        std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "v2_subcopy -> ";
    for(int n: v2_subcopy)
        std::cout << n << " ";
    std::cout << std::endl;

    std::vector<int> nums = {10,20,30,40,50};
    std::cout << "nums -> ";
    for(int n: nums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << nums.capacity() << std::endl;
    std::cout << nums.back() << std::endl;
    nums.push_back(40);

    for(int num: nums)
        std::cout << num << " ";
    std::cout << std::endl;

    int a = nums[0];
    int l = nums[nums.size()-1];

    nums.pop_back();
    
    nums.insert(nums.begin()+6, 99);

    //nums.erase(nums.begin()+10);

    for(int num: nums)
        std::cout << num << " ";

        std::vector<int> v = {10, 20, 30};

// .rbegin() starts at the LAST element (30).
// .rend() is the void immediately BEFORE the first element.
// Notice we still use ++it, because moving "forward" on a reverse iterator means moving left!
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " "; 
}

    return 0;
}