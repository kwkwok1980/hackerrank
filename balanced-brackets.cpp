// https://www.hackerrank.com/challenges/balanced-brackets/problem?isFullScreen=true

std::string isBalanced(std::string s) {
    std::stack<char> values{};
    for (char c : s) {
        if (c == '{') {
            values.push(c);
        } else if (c == '(') {
            values.push(c);
        } else if (c == '[') {
            values.push(c);
        } else if (c == '}') {
            if (!values.empty()) {
                if (values.top() == '{') {
                    values.pop();
                } else {
                    return "NO";
                }    
            } else {
                return "NO";
            }
            
        } else if (c == ')') {
            if (!values.empty()) {
                if (values.top() == '(') {
                values.pop();
                } else {
                    return "NO";
                }
            } else {
                return "NO";
            }
            
        } else if (c == ']') {
            if (!values.empty()) {
                if (values.top() == '[') {
                    values.pop();
                } else {
                    return "NO";
                }
            } else {
                return "NO";
            }
        }
    }
    if (values.empty()) {
        return "YES";
    } else {
        return "NO";
    }
}
