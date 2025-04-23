#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
        size = n;
        front = rear = -1;
        arr = new int[size];
    }

    bool enqueue(int value){
        //if queue is full
        if((front == 0 && rear == size - 1) || (rear == (front-1) % (size-1)))
            return false;

        //single element
        else if(front == -1)
        {
            rear = front = 0;
            arr[rear] = value;
        }

        // rear is at last but queue is not full as front is not 0
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }

        // basic queue filling
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    int dequeue(){
        // if queue is empty return -1
        if(front == -1)
            return -1;

        //if Single element is their
        else if(front == rear)
        {
            int d = arr[front];
            arr[front] = -1;
            front = rear = -1;
            return d;
        }    

        //if delete first element and here front is above rear
        else if(front == size-1)
        {
            int d = arr[front];
            arr[front] = -1;
            front = 0;
            return d;
        }
        else
        {
            int d = arr[front];
            arr[front] = -1;
            front++;
            return d;
        }
    }
};