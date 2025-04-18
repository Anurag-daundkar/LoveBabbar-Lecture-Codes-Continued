#include<iostream>
using namespace std;

class Stack
{
    public:
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack Overflow" << endl;
    }

    void pop()
    {
        if(top > -1)
        {
            top--;
        }
        else
            cout << "Stack is Underflow" << endl;
    }

    int peek()
    {
        if(top > -1)
        {
            return arr[top];
        }

        else
        {
            cout << "Stack is Empty So returning -1 in output ";
            return -1;
        }  
    }

    bool isempty()
    {
        if(top == -1)
            return true;
        else 
            return false;
    }
};

int main()
{
    Stack s(5);
  
    cout << s.peek() << endl;
    s.pop();
    if(s.isempty())
        cout << "Yes it is empty " << endl;

    else
        cout << "No not empty " << endl;

    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    cout << s.peek() << endl;


}