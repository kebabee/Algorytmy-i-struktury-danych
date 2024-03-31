#include<iostream>
#include "nonstd_linked_queue.h"

int main() {
    ArrayQueue<char, 3> queue;

    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');
    // queue.enqueue('d'); // error - queue overflow

    std::cout << "zwrócony element: " << queue.dequeue() << std::endl;
    std::cout << "zwrócony element: " << queue.dequeue() << std::endl;
    std::cout << "zwrócony element: " << queue.dequeue() << std::endl;
    // std::cout << "zwrócony element: " << queue.dequeue() << std::endl; // error - pusta kolejka

    std::cout << "czy pusta? " << queue.isEmpty() << std::endl;

    ListQueue<char> queue2;

    queue2.enqueue('a');
    queue2.enqueue('b');
    queue2.enqueue('c');

    std::cout << "zwrócony element: " << queue2.dequeue() << std::endl;
    std::cout << "zwrócony element: " << queue2.dequeue() << std::endl;
    std::cout << "czy pusta? " << queue2.isEmpty() << std::endl;

    return 0;
}
