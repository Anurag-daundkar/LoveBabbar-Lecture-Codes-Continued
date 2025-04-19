bool isValidParenthesis(string s)
{
    stack<char> stck;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch == '(' || ch =='{' || ch=='['){
            stck.push(ch);
        }

        else{
            if (!stck.empty()) {
                char topelement = stck.top();
                if ((ch == ')' && topelement == '(') ||
                    (ch == '}' && topelement=='{') ||
                    (ch==']' && topelement=='[')){
                        stck.pop();
                    }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }  
    }
    if(stck.empty()){
        return true;
    }
    else{
        return false;
    }
}