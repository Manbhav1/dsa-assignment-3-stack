#include <iostream>
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
            top++;
            arr[top] = c;
        }
    }

    char topElement() {
        if (top == -1) {
            return '\0';
        }
        return arr[top];
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            top--;
        }
    }

    bool empty() {
        return (top == -1);
    }
};

string reverseString(string str) {
    Stack s;

   
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string rev = "";

   
    while (!s.empty()) {
        rev += s.topElement();
        s.pop();
    }

    return rev;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString(str) << endl;

    return 0;
}
