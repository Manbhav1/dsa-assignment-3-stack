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
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    return false;
}

bool AreParanthesesBalanced(string exp)
{
    Stack S;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            S.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty() || !ArePair(S.Top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }

    return S.empty();
}

int main()
{
    string expr = "{()}";

    if (AreParanthesesBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
