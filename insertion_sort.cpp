#include<iostream>
#include "insertion_sort.h"

int main() {
    ListNode<int>* head = new ListNode<int>(5);
    head->next = new ListNode<int>(1);
    head->next->next = new ListNode<int>(3);
    head->next->next->next = new ListNode<int>(11);

    std::cout << "oryginalna lista:\n";
    ListNode<int>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";

    insertion_sort(head);

    std::cout << "po sortowaniu:\n";
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";

    while (head != nullptr) {
        ListNode<int>* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
