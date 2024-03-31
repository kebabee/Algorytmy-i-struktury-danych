#include <iostream>
#include "header.h"

int main() {
    ArrayStack<char, 2> stack1;

    stack1.push('a');
    stack1.push('b');
    // stack1.push('c'); // error - stack overflow
    std::cout << "czy pusta? " << stack1.isEmpty() << std::endl;

    std::cout << "zwrócony element: " << stack1.pop() << "\n";
    std::cout << "zwrócony element: " << stack1.pop() << "\n";
    // std::cout << "zwrócony element: " << stack1.pop() << "\n"; // error - pusty stos
    std::cout << "czy pusta? " << stack1.isEmpty() << std::endl;

    ListStack<char> stack2;

    stack2.push('a');
    stack2.push('b');
    std::cout << "czy pusta? " << stack2.isEmpty() << std::endl;

    std::cout << "zwrócony element: " << stack2.pop() << "\n";
    std::cout << "zwrócony element: " << stack2.pop() << "\n";
    // std::cout << "zwrócony element: " << stack2.pop() << "\n"; // error - pusty stos
    std::cout << "czy pusta? " << stack2.isEmpty() << std::endl;


    return 0;
}
