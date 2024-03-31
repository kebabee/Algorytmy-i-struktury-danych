/*
Krótkie implementacje stosu za pomocą tablicy oraz listy jednokierunkowej. 
Implementacja jest klasą zawierającą w części publicznej metody void push(T x), T pop() oraz bool isEmpty() wykonujące się w czasie stałym.
*/

template <typename T, int maxSize>
class ArrayStack // first in last out
{
private:
    T arr[maxSize];
    int topIndex;

public:
    ArrayStack() 
    {
        topIndex = -1;
    }

    void push(T x) 
    {
        if (topIndex == maxSize - 1) 
        {
            throw std::out_of_range("stack overflow");
        }
        arr[++topIndex] = x;
    }

    T pop() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("stos pusty");
        }
        return arr[topIndex--];
    }

    bool isEmpty() 
    {
        return (topIndex == -1);
    }
};

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
class ListStack 
{
private:
    ListNode<T>* topNode;

public:
    ListStack() 
    {
        topNode = nullptr;
    }

    void push(T x) 
    {
        ListNode<T>* newNode = new ListNode(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("stos pusty");
        }
        T poppedValue = topNode->data;
        ListNode<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() 
    {
        return (topNode == nullptr);
    }
};
