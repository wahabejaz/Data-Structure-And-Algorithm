//programmer Name : Wahab Ejaz
//Compiler : gcc/g++
#include <iostream>
#include <string>
using namespace std;

const int tableSize = 10;

class Student {
public:
    int rollNumber;
    string name;
    string department;
    float cgpa;
    Student* next;

    Student(int roll, string n, string dept, float c) {
        rollNumber = roll;
        name = n;
        department = dept;
        cgpa = c;
        next = nullptr;
    }
};

class HashTable {
private:
    Student* table[tableSize];

    int hashFunction(int rollNumber) {
        return rollNumber % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }

    void insertStudent(int roll, string name, string dept, float cgpa) {
        int index = hashFunction(roll);
        Student* newStudent = new Student(roll, name, dept, cgpa);
        newStudent->next = table[index];
        table[index] = newStudent;
    }

    void searchStudent(int roll) {
        int index = hashFunction(roll);
        Student* temp = table[index];
        while (temp != nullptr) {
            if (temp->rollNumber == roll) {
                cout << "Roll Number: " << temp->rollNumber << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Department: " << temp->department << endl;
                cout << "CGPA: " << temp->cgpa << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found." << endl;
    }

    void deleteStudent(int roll) {
        int index = hashFunction(roll);
        Student* temp = table[index];
        Student* prev = nullptr;
        while (temp != nullptr) {
            if (temp->rollNumber == roll) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Student record deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Student not found." << endl;
    }

    void displayAll() {
        for (int i = 0; i < tableSize; i++) {
            Student* temp = table[i];
            if (temp != nullptr) {
                cout << "Index " << i << ":" << endl;
                while (temp != nullptr) {
                    cout << "  Roll Number: " << temp->rollNumber << ", Name: " << temp->name
                         << ", Dept: " << temp->department << ", CGPA: " << temp->cgpa << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, roll;
    string name, dept;
    float cgpa;

    do {
        cout << "===========MAIN MENU===========" << endl;
        cout << "---Student Record Management---" << endl;
        cout << "      1. Insert Student        " << endl;
        cout << "      2. Search Student        " << endl;
        cout << "      3. Delete Student        " << endl;
        cout << "      4. Display All           " << endl;
        cout << "      5. Exit                  " << endl;
        cout << "___________________________" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter CGPA: ";
            cin >> cgpa;
            ht.insertStudent(roll, name, dept, cgpa);
            break;
        case 2:
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            ht.searchStudent(roll);
            break;
        case 3:
            cout << "Enter Roll Number to Delete: ";
            cin >> roll;
            ht.deleteStudent(roll);
            break;
        case 4:
            ht.displayAll();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
