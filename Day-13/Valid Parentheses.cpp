bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(auto ch:expression) {
        switch(ch) {
            case '(':
            case '{':
            case '[': st.push(ch);
                break;
            case ')': if(!st.empty() and st.top()=='(') st.pop();
                      else return false;
                      break;
            case '}': if(!st.empty() and st.top()=='{') st.pop();
                      else return false;
                      break;
            case ']': if(!st.empty() and st.top()=='[') st.pop();
                      else return false;
                      break;
            default: continue;
        }
    }
    if(st.empty()) return true;
    else return false;
}