// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> sp;
    int ret = true;
    for (int i = 0; (i < s.length()) && (ret); ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            sp.push(s[i]);
        } else if (s[i] == '}') {
            if ((!sp.empty()) && (sp.top() == '{')) {
                sp.pop();
            } else {
                ret = false;
            }
        } else if (s[i] == ']') {
            if ((!sp.empty()) && sp.top() == '[') {
                sp.pop();
            } else {
                ret = false;
            }
        } else if (s[i] == ')') {
            if ((!sp.empty()) && sp.top() == '(') {
                sp.pop();
            } else {
                ret = false;
            }
        } else {
            ret = false;
        }
    }

    return ((sp.empty()) && (ret)) ? string("YES") : string("NO");
}
