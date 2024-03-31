/*
Sortowanie przez wstawianie działające na liście jednokierunkowej + odwracanie listy jednokierunkowej.
*/

template <typename T>
struct ListNode {
    T data;
    ListNode* next;

    ListNode(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
void reverse(ListNode<T>*& head) {
    ListNode<T>* prev = nullptr;
    ListNode<T>* current = head;
    ListNode<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next; // wskaźnik do następnego węzła
        current->next = prev; // odwracamy wskaźnik na następny węzeł

        // przesuwamy wskaźniki do następnych węzłów
        prev = current;
        current = next;
    }

    // nadpisanie wskaźnik do head listy
    head = prev;
}

template <typename T>
void insertion_sort(ListNode<T>*& head) {

    ListNode<T>* sorted = nullptr;
    ListNode<T>* current = head;

    while (current != nullptr) {
        ListNode<T>* nextNode = current->next; // zapamiętujemy następny węzeł przed zmianą
        if (sorted == nullptr || current->data <= sorted->data) { // pusta lub wartość current <= wartość pierwszego węzła sorted
            current->next = sorted; // węzeł current na początek sorted
            sorted = current; // current staje się początkiem sorted
        } else {
            ListNode<T>* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next; // przechodzimy dopóki nie spełni mniejszości
            }
            current->next = temp->next; // węzeł current na odpowiednie miejsce
            temp->next = current; 
        }
        current = nextNode; // przechodzimy do następnego węzła w nieposortowanej liście
    }

    reverse(sorted);
    head = sorted;
}
