#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
   int size = N/2;

   stack<int> temp;
   for(int i = 0 ; i < size ; i++)
   {
      temp.push(inputStack.top());
      inputStack.pop();
   }
   inputStack.pop();
   while(!temp.empty())
   {
      inputStack.push(temp.top());
      temp.pop();
   }
}