/*
Krótkie implementacje kolejki za pomocą tablicy oraz listy jednokierunkowej.
Implementacja jest klasą zawierającą w części publicznej metody void enqueue(T x), T dequeue() oraz bool isEmpty() wykonujące się w czasie stałym.
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

template <typename T, int maxSize>
class ArrayQueue 
{
private:
    T arr[maxSize];
    int frontIndex;
    int rearIndex;

public:
    ArrayQueue() 
    {
        frontIndex = -1;
        rearIndex = -1;
    }

    void enqueue(T x) 
    {
        if (rearIndex + 1 >= maxSize) 
        {
            throw std::out_of_range("queue overfloc");
        }
        if (isEmpty()) 
        {
            frontIndex = 0;
            rearIndex = 0;
        } 
        else 
        {
            rearIndex++;
        }
        arr[rearIndex] = x;
        // std::cout << rearIndex << ", " << frontIndex << "\n";
    }

    T dequeue() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("kolejka pusta");
        }
        T dequeuedValue = arr[frontIndex];
        if (frontIndex == rearIndex) 
        {
            frontIndex = -1;
            rearIndex = -1;
        } 
        else 
        {
            frontIndex++;
        }
        // std::cout << rearIndex << ", " << frontIndex << "\n";
        return dequeuedValue;
    }

    bool isEmpty() 
    {
        return (frontIndex == -1 && rearIndex == -1);
    }
};

template <typename T>
class ListQueue 
{
private:
    ListNode<T>* frontNode;
    ListNode<T>* rearNode;

public:
    ListQueue() 
    {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    void enqueue(T x) 
    {
        ListNode<T>* newNode = new ListNode(x);
        if (isEmpty()) 
        {
            frontNode = newNode;
            rearNode = newNode;
        } 
        else 
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    T dequeue() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("kolejka pusta");
        }
        T dequeuedValue = frontNode->data;
        ListNode<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr) 
        {
            rearNode = nullptr;
        }
        return dequeuedValue;
    }

    bool isEmpty() 
    {
        return (frontNode == nullptr);
    }
};
