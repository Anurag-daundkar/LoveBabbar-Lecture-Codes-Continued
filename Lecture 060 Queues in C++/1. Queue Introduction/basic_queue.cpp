#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //Queue Creation
    queue<int> q;

    //Pushing Operations 
    q.push(1);
    q.push(2);
    q.push(3);

    //Displaying size of the queue
    cout << "Queue size : "  << q.size() << endl;

    //Displaying front of the queue
    cout << "Queue Front : " << q.front() << endl;

    //Poping front element of the queue
    q.pop();
    cout << "Queue Front after poping element : " << q.front() << endl;
    
    //Is the queue empty
    if(q.empty())
        cout << "Queue is empty " << endl;
    else    
        cout << "Queue is not Empty " << endl;

    q.pop();
    q.pop();

    if(q.empty())
        cout << "Queue is empty " << endl;
    else    
        cout << "Queue is not Empty " << endl;

    cout << endl << endl;


    cout << "Focusing on Deque" << endl;

    // Deque Creation
    deque<int> d;

    //we can Insert from front and back
    d.push_front(12);
    d.push_back(13);

    cout << "Front Element : " << d.front() << endl;
    cout << "Back Element : " << d.back() << endl;

    d.pop_back();
    d.pop_front();

    if(d.empty())
        cout << "Deque is Empty " << endl;
    else
        cout << "Deque is Not Empty" << endl;

}