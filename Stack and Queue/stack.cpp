#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}

    void setter() {
        cout << "Enter data: ";
        cin >> data;
    }
};

class StackLinkedList {
private:
    Node* top; // Pointer to the top of the stack

public:
    StackLinkedList() : top(NULL) {}

    // Push operation
    void push() {
        char ch;
        do {
            Node* newNode = new Node;
            newNode->setter();
            newNode->next = top; // New node points to the old top
            top = newNode;       // Update top to the new node

            cout << "Do you have another data (Y/N)? : ";
            cin >> ch;
        } while (ch == 'Y' || ch == 'y');
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top; // Store the current top
        top = top->next;  // Move top to the next node
        delete temp;      // Delete the old top node
        cout << "Element popped successfully." << endl;
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "TOP element: " << top->data << endl;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList s1;
    int choice;
    
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s1.push();
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.peek();
                break;
            case 4:
                s1.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
