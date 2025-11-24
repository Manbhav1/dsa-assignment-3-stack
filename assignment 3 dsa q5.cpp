#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            top--;
        }
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};

int main() {
    string postfix;
    cout << "Enter the postfix expression you want to Evaluate : ";
    cin >> postfix;

    Stack s;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');          
        } else {
            int val2 = s.Top();
            s.pop();
            int val1 = s.Top();
            s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(val1 ^ val2); break; 
            }
        }
    }

    cout << "\nRESULT OF EVALUATED POSTFIX EXPRESSION IS : ";
    cout << s.Top();

    return 0;
}