#include <iostream>

/// Adds two integers and returns the result.
/**
 * \param a The first number.
 * \param b The second number.
 * \return The sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

int main()
{
    add(1, 2);
    std::cout << "Hello World!\n";
}
