#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Infix {
public:
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    string infixToPostfix(string s) {
        stack<char>st;
        string result;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;
            else if (c == '(')
                st.push('(');
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }

    string reverse(string a) {
        int n = a.length();
        string result1;
        for (int i = n - 1; i >= 0; i--) {
            char c = a[i];
            result1 += c;
        }
        return result1;
    }

    string infixToPrefix(string c) {
        string reversedInfix = reverse(c);
      
          string postfixResult=infixToPostfix(reversedInfix);
         
        return reverse(postfixResult);
    }
};

int main() {
    string ch;
    int choice;
    char d;
    Infix s;


        cout << "Enter the expression: ";
        cin >> ch;
            do {
        cout << "Enter your choice: \n";
        cout << "1. Infix to postfix \n";
        cout << "2. Infix to prefix\n";
        cin >> choice;

        switch (choice) {
            case 1:
             cout << "Infix to Postfix: " <<s.infixToPostfix(ch)<< endl;

                break;

            case 2:
                cout << "Infix to Prefix " << s.infixToPrefix(ch) << endl;
                break;

            default:
                cout << "Invalid choice ";
                break;
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> d;
    } while (d == 'y' || d == 'Y');

    return 0;
}
