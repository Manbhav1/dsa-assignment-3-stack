#include <iostream>
#include <string>
using namespace std;


class Stack {
public:
    char arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = c;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            top--;
        }
    }

    char Top() {
        if (top == -1) {
            return '\0';  
        }
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};


int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '-' || c == '+') return 1;
    return 0;
}

int main() {
    string infix, postfix;

    cout << "\nEnter Infix Expression : ";
    cin >> infix;

    postfix = "";
    Stack s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

       
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||  
            (c >= '0' && c <= '9')) {
            postfix += c;
        }
        
        else if (c == '(') {
            s.push(c);
        }
     
        else if (c == ')') {
            while (!s.empty() && s.Top() != '(') {
                postfix += s.Top();
                s.pop();
            }
            s.pop();
        }
       
        else {
            while (!s.empty() && prec(s.Top()) >= prec(c)) {
                postfix += s.Top();
                s.pop();
            }
            s.push(c);
        }
    }

   
    while (!s.empty()) {
        postfix += s.Top();
        s.pop();
    }

    cout << "\nPostfix expression is : " << postfix << endl;

    return 0;
}
