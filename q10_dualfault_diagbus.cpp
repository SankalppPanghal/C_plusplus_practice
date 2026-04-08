/*
Problem 10: The Dual-Fault Diagnostic Bus
Scenario: The diagnostic bus experienced a large power spike. This time, two completely different components dropped their second ping.

You are given a vector of integer IDs where every ID appears exactly twice, except for two distinct IDs that appear exactly once.

Requirements:

Write a function findTwoMissing(const std::vector<int>& ids).

It must return a std::vector<int> containing the two missing IDs (in any order).

Optimization: You must solve this in O(N) time and O(1) auxiliary space.
*/

#include <iostream>
#include <vector>

std::vector<int> findTwoMissing(const std::vector<int>& ids) {
    // TODO: Implement your solution here.
    int t = 0;
    for(int no: ids)
        t = t^no;
    
    // Finding the bit
    int bit = t & -static_cast<unsigned int>(t);

    int g1=0, g2=0;
    int r1=0, r2=0;
    
    for(int no: ids)
    {    
        if ( (no&bit) == bit)
            {
                g1 = g1^no;
            }
        else 
            {
                g2 = g2^no;
            }
    }
    return {g1,g2};
}

// --- Helper function to print results ---
void printResult(const std::vector<int>& result) {
    if (result.size() == 2) {
        std::cout << "[" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "Invalid result size.\n";
    }
}

int main() {
    // Test Case 1
    std::vector<int> stream1 = {1, 2, 1, 3, 2, 5};
    std::cout << "Test 1 (Expected [3, 5] or [5, 3]): ";
    printResult(findTwoMissing(stream1));

    // Test Case 2
    std::vector<int> stream2 = {14, 8, 22, 14, 9, 22, 8, 100};
    std::cout << "Test 2 (Expected [9, 100] or [100, 9]): ";
    printResult(findTwoMissing(stream2));

    return 0;
}

/*
The Math of Zero
1. Start with 0
t = 0  (Binary: 0000 0000)

2. Invert the bits (~t)
Every 0 becomes a 1. You get the largest possible number.
~t = 255 (Binary: 1111 1111)

3. Add 1
Now, the CPU adds 1. Let's do the binary addition:

Plaintext
  (Carries) 1111 1111
            1111 1111  (~t)
          + 0000 0001  (Add 1)
          -----------
          1 0000 0000 
Notice the result is 9 bits long (1 0000 0000).

The Hardware Reality
In an 8-bit system, the CPU register physically only has 8 slots to hold data. The 9th bit (the 1 on the far left) has nowhere to go.

The CPU completely discards it. It just falls off the end of the memory register.

What are the 8 bits left in the register?
0000 0000

The Result
By allowing the hardware to overflow and discard the extra bit, the Two's Complement process guarantees that -0 becomes 0000 0000.

This was a massive breakthrough in the 1970s. Older computers used to have a "Positive Zero" (0000 0000) and a "Negative Zero" (1111 1111), which caused endless software bugs. Two's complement perfectly unifies them.

So, back to our algorithm t & -t:
If the array is completely empty, or the missing pairs somehow evaluate to 0, t = 0.
-t = 0.
0 & 0 = 0.

The bitmask safely evaluates to 0 without crashing.
In C++, worrying about signed vs. unsigned is critical because of a terrifying concept called Undefined Behavior (UB).

Here is exactly why that cast is there, and why a senior engineer would look for it.

The INT_MIN Trap
In a 32-bit signed integer, the values you can store range from:

Max Positive: 2,147,483,647

Min Negative: -2,147,483,648 (Notice it goes one number further into the negatives).

Let's say your XOR loop finishes, and purely by chance, the t variable happens to hold exactly -2,147,483,648 (Binary: 1000 0000 ... 0000).

Now, your code executes: int bit = t & -t;

The CPU tries to calculate -t. It tries to turn -2,147,483,648 into +2,147,483,648.
But wait—the maximum positive number allowed is 2,147,483,647. It doesn't fit!

The C++ Standard on Overflow
Here is where C++ is uniquely dangerous compared to Python or Java:

Unsigned Integer Overflow: If an unsigned integer overflows, the C++ standard says it must safely wrap around like a car odometer. It is 100% legal and predictable.

Signed Integer Overflow: If a signed integer overflows, the C++ standard classifies it as Undefined Behavior.

When Undefined Behavior happens, the compiler is legally allowed to do whatever it wants. It might crash. It might return 0. The optimizer might look at -t, realize it could cause UB, and literally delete your entire if/else block from the final compiled code to "protect" the program.

The Fix
By writing -(unsigned int)t, you are doing a brilliant hardware trick:

(unsigned int)t takes the exact binary bits of t and tells the compiler, "Treat these bits as unsigned."

The - operator is applied. Because the number is now unsigned, the CPU does the Two's Complement inversion and addition, but because it is an unsigned operation, overflow is perfectly legal.

The compiler happily flips the bits, safely wraps around if necessary, and gives you the exact bitmask you need without triggering Undefined Behavior.

When you write if (no & bit) where no is a signed int and bit is an unsigned int, the C++ compiler follows a strict set of rules called Usual Arithmetic Conversions.

Here is exactly what happens under the hood:

1. Type Promotion (Signed to Unsigned)
C++ does not allow operations between mismatched types. When the compiler sees a binary operator (like &, +, *) combining a signed int and an unsigned int, it automatically promotes the signed int to an unsigned int before doing the math.

So, no & bit becomes (unsigned int)no & bit.

2. The Bits Do Not Change
This is the most crucial part for bit manipulation: casting a signed integer to an unsigned integer does not alter a single bit in memory.

If no is -5 (Binary 1111 1111 ... 1111 1011), casting it to an unsigned int keeps the exact same binary string. It just tells the compiler to read that string as a massive positive number (4,294,967,291) instead of -5.

Because bitwise operators (&, |, ^) only care about the raw 1s and 0s—not what decimal number they represent—the masking operation works perfectly.

3. The if Statement Evaluation
After the compiler does the & operation, the result is an unsigned int.

If the bits did not match, the result is 0.

If the bit matched, the result is some positive number (e.g., 4, 128, etc.).

In C++, an if() statement implicitly checks if the value is not zero.
It doesn't matter if the number inside the if is signed, unsigned, a pointer, or a boolean. The compiler simply translates it to:
if ( (unsigned int)no & bit != 0 )

Summary
no is temporarily treated as unsigned.

The bits remain identical, so the & mask finds exactly what it's looking for.

The if statement correctly routes to true if any bits matched (non-zero) and false if they didn't (zero).

*/