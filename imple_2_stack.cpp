#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
 
class Stack
{
    int *arr;
    int capacity;
    int top1, top2;
 
public:
 
    // Constructor
    Stack(int n)
    {
        capacity = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
 
    // Function to insert a given element into the first stack
    void pushFirst(int key)
    {
        // check if the array is full
        if (top1 + 1 == top2)
        {
            cout << "Stack Overflow";
            exit(EXIT_FAILURE);
        }
 
        top1++;
        arr[top1] = key;
    }
 
    // Function to insert a given element into the second stack
    void pushSecond(int key)
    {
        // check if the array is full
        if (top1 + 1 == top2)
        {
            cout << "Stack Overflow";
            exit(EXIT_FAILURE);
        }
 
        top2--;
        arr[top2] = key;
    }
 
    // Function to pop an element from the first stack
    int popFirst()
    {
        // if no elements are left in the array
        if (top1 < 0)
        {
            cout << "Stack Underflow";
            exit(EXIT_FAILURE);
        }
 
        int top = arr[top1];
        top1--;
        return top;
    }
 
    // Function to pop an element from the second stack
    int popSecond()
    {
        // if no elements are left in the array
        if (top2 >= capacity)
        {
            cout << "Stack Underflow";
            exit(EXIT_FAILURE);
        }
 
        int top = arr[top2];
        top2++;
        return top;
    }
};
 
int main()
{
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 6, 7, 8, 9, 10 };
 
    Stack stack(arr1.size() + arr2.size());
 
    for (int i: arr1) {
        stack.pushFirst(i);
    }
 
    for (int j: arr2) {
        stack.pushSecond(j);
    }
 
    cout << "Popping element from the first stack: " << stack.popFirst() << endl;
    cout << "Popping element from the second stack: " << stack.popSecond() << endl;
 
    return 0;
}