//Programmer Name: Wahab Ejaz
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class node {
public:
    int courseID;
    string courseNm;
    int crHrs;
    node* left;
    node* right;

    node(int cID = 0, string cNam = "", int cHrs = 0)
        : courseID(cID), courseNm(cNam), crHrs(cHrs), left(NULL), right(NULL) {}

    void setter() {
        cout << "Enter course ID: ";
        cin >> courseID;
        cout << "Enter course Name: ";
        cin >> courseNm;
        cout << "Enter Credit hours: ";
        cin >> crHrs;
    }

    void getter() {
        cout << "Course ID: " << courseID << " | ";
        cout << "Course Name: " << courseNm << " | ";
        cout << "Credit Hours: " << crHrs << endl;
    }
};

class course
{
    node* root = NULL;

public:
    void insertion() {
        node* cur = new node();
        cur->setter();

        if (root == NULL) {
            root = cur;
            return;
        }

        node* temp = root;
        node* parent = NULL;

        while (temp != NULL) {
            parent = temp;
            if (cur->courseID < temp->courseID)
                temp = temp->left;
            else if (cur->courseID > temp->courseID)
                temp = temp->right;
            else {
                cout << "Course ID " << cur->courseID << " already exists. Skipping insertion." << endl;
                delete cur;
                return;
            }
        }

        if (cur->courseID < parent->courseID)
            parent->left = cur;
        else
            parent->right = cur;
    }

    void search() {
        if (root == NULL) {
            cout << "No record entered yet!" << endl;
            return;
        }

        int ID;
        cout << "Enter course ID you want to search: ";
        cin >> ID;
        node* temp = root;
        bool found = false;

        while (temp != NULL) {
            if (ID < temp->courseID)
                temp = temp->left;
            else if (ID > temp->courseID)
                temp = temp->right;
            else {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Course ID found!" << endl;
            temp->getter();
        } else {
            cout << "Course ID not found!" << endl;
        }
    }

    void deletion() {
        if (root == NULL) {
            cout << "No record entered yet!" << endl;
            return;
        }

        int id;
        cout << "Enter courseID for course you wanna delete: ";
        cin >> id;

        node* temp = root;
        node* parent = NULL;

        while (temp != NULL && temp->courseID != id) {
            parent = temp;
            if (id < temp->courseID)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (temp == NULL) {
            cout << "Course ID not found!" << endl;
            return;
        }

        // Case 1: Leaf node
        if (temp->left == NULL && temp->right == NULL) {
            if (parent == NULL)
                root = NULL;
            else if (parent->left == temp)
                parent->left = NULL;
            else
                parent->right = NULL;
            delete temp;
        }
        // Case 2: One child
        else if (temp->left == NULL || temp->right == NULL) {
            node* child = (temp->left != NULL) ? temp->left : temp->right;

            if (parent == NULL)
                root = child;
            else if (parent->left == temp)
                parent->left = child;
            else
                parent->right = child;

            delete temp;
        }
        // Case 3: Two children
        else {
            node* succParent = temp;
            node* succ = temp->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Copy successor’s data to temp
            temp->courseID = succ->courseID;
            temp->courseNm = succ->courseNm;
            temp->crHrs = succ->crHrs;

            // Delete successor node
            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            delete succ;
        }

        cout << "Course deleted successfully!" << endl;
    }

    void display() {
        if (root == NULL) {
            cout << "No courses available.\n";
            return;
        }

        node* stack[100];
        int top = -1;
        node* current = root;

        cout << "Courses in ascending order of Course ID:\n";

        while (current != NULL || top != -1) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }

            current = stack[top--];
            current->getter();
            current = current->right;
        }
    }

    void totalCourses() {
        int count = 0;
        node* stack[100];
        int top = -1;
        node* current = root;

        while (current != NULL || top != -1) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->left;
            }

            current = stack[top--];
            count++;
            current = current->right;
        }

        cout << "Total number of courses: " << count << endl;
    }

    void findMin() {
        if (root == NULL) {
            cout << "No courses available.\n";
            return;
        }

        node* temp = root;
        while (temp->left != NULL)
            temp = temp->left;

        cout << "Course with Minimum Course ID:\n";
        temp->getter();
    }

    void findMax() {
        if (root == NULL) {
            cout << "No courses available.\n";
            return;
        }

        node* temp = root;
        while (temp->right != NULL)
            temp = temp->right;

        cout << "Course with Maximum Course ID:\n";
        temp->getter();
    }
};

int main() {
    char ch;
    course C1;
    char choice;

    do {
        cout << "\n     ============MAIN MENU============ " << endl;
        cout << "      ---COURSE ENROLLMENT SYSTEM---  " << endl;
        cout << "             1. ADD NEW COURSE             " << endl;
        cout << "             2. DELETE COURSE              " << endl;
        cout << "             3. SEARCH COURSE              " << endl;
        cout << "             4. DISPLAY ALL COURSES        " << endl;
        cout << "             5. TOTAL COURSES              " << endl;
        cout << "             6. MAX/MIN COURSE             " << endl;
        cout << "             7. EXIT                       " << endl;
        cout << "_________________________________" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                do {
                    C1.insertion();
                    cout << "Do you have another course (Y/N)? : ";
                    cin >> ch;
                } while (tolower(ch) == 'y');
                break;

            case '2':
                C1.deletion();
                break;

            case '3':
                do {
                    C1.search();
                    cout << "Do you want to search another course (Y/N)? : ";
                    cin >> ch;
                } while (tolower(ch) == 'y');
                break;

            case '4':
                C1.display();
                break;

            case '5':
                C1.totalCourses();
                break;

            case '6':
                C1.findMin();
                C1.findMax();
                break;

            case '7':
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '7');

    return 0;
}
