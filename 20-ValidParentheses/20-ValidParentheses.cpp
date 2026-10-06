// Last updated: 10/6/2026, 4:29:28 PM
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // closing brackets
            else {

                if(st.empty())
                    return false;

                char top = st.top();

                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '['))
                {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};