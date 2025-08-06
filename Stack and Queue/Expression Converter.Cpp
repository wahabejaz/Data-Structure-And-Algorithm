//programmer Name : Wahab Ejaz
//Compiler : gcc/g++
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) : data(val), next(NULL) {}
};

class StackLinkedList {
private:
    Node* top;
public:
    StackLinkedList() : top(NULL) {}

    void push(string value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = top;
        string val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    string peek() {
        if (isEmpty()) return "";
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '^') 
    return 3;
    if (op == '*' || op == '/') 
    return 2;
    if (op == '+' || op == '-') 
    return 1;
    return 0;
}


void infixToPostfix(const string& infix, string& postfix) {
    StackLinkedList stack;
    for (int i = 0; i < infix.length(); ++i) {
        if (isalnum(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            stack.push("(");
        } else if (infix[i] == ')') {
            while (!stack.isEmpty() && stack.peek() != "(") {
                postfix += stack.pop();
            }
            stack.pop();
        } else if (isOperator(infix[i])) {
            while (!stack.isEmpty() && precedence(infix[i]) <= precedence(stack.peek()[0])) {
                postfix += stack.pop();
            }
            stack.push(string(1, infix[i]));
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
}

void postfixToInfix(const string& postfix, string& infix) {
    StackLinkedList stack;
    for (int i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isalnum(ch)) 
        stack.push(string(1, ch));
        else {
            string op2 = stack.pop();
            string op1 = stack.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            stack.push(expr);
        }
    }
    infix = stack.pop();
}

string reverseString(const string& str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}

void infixToPrefix(const string& infix, string& prefix) {
    string revInfix = reverseString(infix);
    for (int i = 0; i < revInfix.length(); ++i) {
        if (revInfix[i] == '(') 
        revInfix[i] = ')';
        else if (revInfix[i] == ')') 
        revInfix[i] = '(';
    }
    string postfix;
    infixToPostfix(revInfix, postfix);
    prefix = reverseString(postfix);
}

void prefixToInfix(const string& prefix, string& infix) {
    StackLinkedList stack;
    for (int i = prefix.length() - 1; i >= 0; --i) {
        char ch = prefix[i];
        if (isalnum(ch)) 
        stack.push(string(1, ch));
        else {
            string op1 = stack.pop();
            string op2 = stack.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            stack.push(expr);
        }
    }
    infix = stack.pop();
}

void readFromFile(const string& filename, string& content) {
    ifstream inFile(filename);
    getline(inFile, content);
    inFile.close();
}

void writeToFile(const string& filename, const string& content) {
    ofstream outFile(filename);
    outFile << content;
    outFile.close();
}

int main() {
    int choice;
    string infix, postfix, prefix;

    do {
        cout << "\n===== Expression Converter Menu =====\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Postfix to Infix\n";
        cout << "3. Infix to Prefix\n";
        cout << "4. Prefix to Infix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readFromFile("infix.txt", infix);
                infixToPostfix(infix, postfix);
                writeToFile("postfix.txt", postfix);
                cout << "Postfix written to postfix.txt: " << postfix << endl;
                break;
            case 2:
                readFromFile("postfix.txt", postfix);
                postfixToInfix(postfix, infix);
                writeToFile("infix1.txt", infix);
                cout << "Infix written to infix1.txt: " << infix << endl;
                break;
            case 3:
                readFromFile("infix.txt", infix);
                infixToPrefix(infix, prefix);
                writeToFile("prefix.txt", prefix);
                cout << "Prefix written to prefix.txt: " << prefix << endl;
                break;
            case 4:
                readFromFile("prefix.txt", prefix);
                prefixToInfix(prefix, infix);
                writeToFile("infix2.txt", infix);
                cout << "Infix written to infix2.txt: " << infix << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}