/*
Procedury inorder wypisujące klucze drzewa BST kolejności rosnącej. Z rekurencją i bez.
*/

#include<iostream>

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

struct tree_node
{
   int key;
   tree_node *left = nullptr;
   tree_node *right = nullptr;
   tree_node(int x0): key(x0){}
};

void insert_recursive(tree_node *&t, int x)
{
   if(t == nullptr) // jeśli drzewo puste
      t= new tree_node(x); // stwórz nowy korzeń zawierający x
   else if(x < t->key) // a jak niepuste i x < key
      insert_recursive(t->left, x); // wstaw x do lewego poddrzewa
   else // w przeciwnym wypadku
      insert_recursive(t->right, x); // wstaw x do prawego poddrzewa
}

void inorder(tree_node *t) // wypisanie kluczy w porządku "in order"
{
   if (t){
      inorder(t->left);
      std::cout << t->key << " ";
      inorder(t->right);
   }
}

void inorder2(tree_node *t) {
   ArrayStack<tree_node*, 100> stack; // stos wskaźników na węzły
   tree_node* current = t; // początkowy węzeł w korzeniu drzewa

   while (current != nullptr || !stack.isEmpty()) {
      while (current != nullptr) { // idziemy najbardziej w lewo i każdy element po drodze na stos
         stack.push(current);
         current = current->left;
      }
      // nie da się iśc bardziej w lewo

      current = stack.pop(); // nowy aktualny węzeł wzięty ze stosu
      std::cout << current->key << " ";

      current = current->right; // potencjalnie większy będzie w prawo
   }
}

int main()
{
   tree_node tree = tree_node(12);
   tree_node *p1 = &tree;

   for (int i = 19; i > 0; i-=2)
      insert_recursive(p1, i);

   std::cout << "rekurencyjne inOrder z wykładu:\n";
   inorder(&tree);
   std::cout << "\ninOrder bez rekurencji:\n";
   inorder2(&tree);
   std::cout << "\n";
}
