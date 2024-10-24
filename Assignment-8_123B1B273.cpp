/*Name: Dhanashree Sikandar Sul
Roll No: SYCOD273
PRN No:123B1B273  Div:D3
Assignment No. 8

Title:Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of postfix and prefix expression.
 */

#include <iostream>
#include <cstring>
#include <cmath> 
#include <cctype>
using namespace std;

// Custom Stack Class with Array Implementation
class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char val) {
        if (top < 99) {
            top++;
            arr[top] = val;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            char val = arr[top];
            top--;
            return val;
        }
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return '\0';
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Infix to Postfix Conversion
void infixToPostfix(char* infix, char* postfix) {
    Stack st;
    int k = 0; 

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        
        if (isalnum(c)) {
            postfix[k++] = c;
        }
       
        else if (c == '(') {
            st.push(c);
        }
     
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[k++] = st.pop();
            }
            st.pop(); // Pop '('
        }
      
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix[k++] = st.pop();
            }
            st.push(c);
        }
    }

    
    while (!st.isEmpty()) {
        postfix[k++] = st.pop();
    }

    postfix[k] = '\0'; 
}

// Infix to Prefix Conversion
void infixToPrefix(char* infix, char* prefix) {
    int len = strlen(infix);

    // Step 1
    reverseString(infix);

    // Step 2
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3
    char postfix[100];
    infixToPostfix(infix, postfix);

    // Step 4
    reverseString(postfix);

    // Step 5
    strcpy(prefix, postfix);

    // Step 6
    reverseString(infix); 
}


// Function to evaluate Postfix expression
int evaluatePostfix(char* postfix) {
    Stack st;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

       
        if (isdigit(c)) {
            st.push(c - '0'); 
        }
     
        else {
            int val2 = st.pop(); 
            int val1 = st.pop();

            switch (c) {
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
                case '^':
                    st.push(pow(val1, val2));
                    break;
            }
        }
    }

    return st.pop(); 
}

// Function to evaluate Prefix expression
int evaluatePrefix(char* prefix) {
    Stack st;
    int n = strlen(prefix);

    
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        
        if (isdigit(c)) {
            st.push(c - '0'); 
        }
        
        else {
            int val1 = st.pop(); 
            int val2 = st.pop();

            switch (c) {
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
                case '^':
                    st.push(pow(val1, val2));
                    break;
            }
        }
    }

    return st.pop(); 
}

// Main function with menu
int main() {
    int choice;
    char infix[100], postfix[100], prefix[100];

    do {
        cout << "\nMenu:\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Evaluate Prefix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                infixToPostfix(infix, postfix);
                cout << "Postfix Expression: " << postfix << endl;
                break;

            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                infixToPrefix(infix, prefix);
                cout << "Prefix Expression: " << prefix << endl;
                break;

            case 3:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                cout << "Postfix Evaluation Result: " << evaluatePostfix(postfix) << endl;
                break;

            case 4:
                cout << "Enter prefix expression: ";
                cin >> prefix;
                cout << "Prefix Evaluation Result: " << evaluatePrefix(prefix) << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
