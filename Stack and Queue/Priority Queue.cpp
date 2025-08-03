#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class airTime {
    private:
    int hrs,mins,sec;
    public:
    airTime(int hh=0,int mm=0,int ss=0):hrs(hh),mins(mm),sec(ss){}
    void setter();
    void getter();
    
};

void airTime :: setter(){
    cout << "Enter hours: " << endl;
    cin >> hrs;
    cout << "Enter mins: " << endl;
    cin >> mins;
    cout << "Enter sec: " << endl;
    cin >> sec;
    
}

struct Node {
    string processName;
    int priority;
    airTime date;
    Node* next;
    Node* prev;

    Node(const string& name, int pri)
        : processName(name), priority(pri), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* first;
    Node* last;

public:
    PriorityQueue() : first(nullptr), last(nullptr) {}

    void enqueue(const string& name, int priority) {
        Node* newNode = new Node(name, priority);

        if (!first) {
            first = last = newNode;
            return;
        }

        if (newNode->priority < first->priority) {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
            return;
        }

        Node* cur = first;
        while (cur->next && newNode->priority >= cur->next->priority) {
            cur = cur->next;
        }

        if (!cur->next) {
            cur->next = newNode;
            newNode->prev = cur;
            last = newNode;
        } else {
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next->prev = newNode;
            cur->next = newNode;
        }
    }

    string dequeue() {
        if (!first) {
            cout << "Queue is empty.\n";
            return "";
        }

        Node* temp = first;
        string data = temp->processName;
        first = first->next;

        if (first)
            first->prev = nullptr;
        else
            last = nullptr;

        delete temp;
        return data;
    }

    string peek() const {
        if (!first) {
            cout << "Queue is empty.\n";
            return "";
        }
        return first->processName;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    void display() const {
        if (!first) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = first;
        cout << "\nProcess Name\tPriority\n";
        cout << "-----------------------------\n";
        while (current) {
            cout << current->processName << "\t\t" << current->priority << "\n";
            current = current->next;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Cannot open file " << filename << "\n";
            return;
        }

        string name;
        int pri;
        while (file >> name >> pri) {
            enqueue(name, pri);
        }

        file.close();
        cout << "Data loaded from file successfully.\n";
    }

};

int main() {
    PriorityQueue pq;
    int choice;
    string name, filename;
    int pri;

    do {
        cout << "\n==== Priority Queue Menu ====\n";
        cout << "1. Enqueue Process\n";
        cout << "2. Dequeue Process\n";
        cout << "3. Peek (View Next Process)\n";
        cout << "4. Display All Processes\n";
        cout << "5. Load Processes from File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter process name: ";
            cin >> name;
            cout << "Enter priority (lower value = higher priority): ";
            cin >> pri;
            pq.enqueue(name, pri);
            break;

        case 2:
            cout << "Dequeued process: " << pq.dequeue() << "\n";
            break;

        case 3:
            cout << "Next process: " << pq.peek() << "\n";
            break;

        case 4:
            pq.display();
            break;

        case 5:
            cout << "Enter filename: ";
            cin >> filename;
            pq.loadFromFile(filename);
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
