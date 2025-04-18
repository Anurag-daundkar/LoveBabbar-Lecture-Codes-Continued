#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> st;

    // cout << "Top Element of Stack initially before Pushing elements in the stack " << st.top() << endl;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element : " << st.top() << endl;

    st.pop();
    cout << "New Top element : " << st.top() << endl;

    st.pop();
    st.pop();
    st.pop();

    int a;
    cout << a;


}