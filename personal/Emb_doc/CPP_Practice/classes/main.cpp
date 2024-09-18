#include <iostream>

// Example 1: Function returning a const int
const int getConstInt() {
    return 10;
}

// Example 2: Function returning a const reference
const int& getConstReference() {
    static int x = 5;
    return x;
}

// Example 3: Function taking a const reference parameter
void printConstReference(const int& x) {
    std::cout << "Value of x: " << x << std::endl;
}

int main() {
    // Example 1: Using function returning a const int
    const int a = getConstInt();
    std::cout << "Value of a: " << a << std::endl;

    // Example 2: Using function returning a const reference
    const int& b = getConstReference();
    std::cout << "Value of b: " << b << std::endl;

    // Example 3: Using function taking a const reference parameter
    int c = 20;
    printConstReference(c);

    return 0;
}
