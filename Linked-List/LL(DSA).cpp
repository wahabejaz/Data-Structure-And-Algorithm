#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    string name;
    string fName;
    string education;
    int empID;
    node * nna; //nna means next node address
    node(string n,string f,string edu,int ID):name(n),fName(f),education(edu),empID(ID),nna(NULL){}
    void setter() 
    {
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter father name: ";
        getline(cin, fName);
        cout << "Enter education: ";
        getline(cin, education);
        cout << "Enter ID: ";
        cin >> empID;
        cin.ignore(); 
    }
    
    void getter()
    {
        cout << "Name: " << name << endl;
        cout << "Father name: "<< fName << endl;
        cout << "Education: " << education << endl;
        cout << "ID: " << empID << endl;
    }
};
class linkedList {
    node*first =NULL;
    node*prev=NULL;
    node*curr=NULL;
public:
    void createDB();
    void insertAtBeg();
    void insertAtMid();
    void insertAtLast();
    void search();
    void deletion();
    void display();
};
void linkedList::createDB()
{
    char ch;
    do{
        curr = new node("", "", "", 0); // Initialize with default values
        curr->setter();
        if (first==NULL)
        first=prev=curr;
        else
        {
        prev->nna =curr;
        prev=curr;
        }
        cout << "Do you have another data(Y/N)? : ";
        cin >> ch;
    }while(ch=='Y'||ch=='y');
}

void linkedList::insertAtBeg()
{
    curr= new node("", "", "", 0);
    curr->setter();
    curr->nna=first;
    first=curr;
}

void linkedList::insertAtMid()
{
    int IDD;
    cout << "Enter employ ID where you want to insert: ";
    cin >> IDD;
    curr=prev=first;
    if(first==NULL){
        cout << "List is empty." << endl;
        return;
    }
    while(curr!=NULL)
    {
        if(curr->empID==IDD)
        {
            node* nwnode = new node("", "", "", 0);
            nwnode->setter();
            nwnode->nna=curr->nna;
            curr->nna=nwnode;
            return;
        }
        if(curr->nna==NULL){
            cout << "ID not found." << endl;
            return;
        }
        curr=curr->nna;
    }
}

void linkedList::insertAtLast()
{
    node* nwnode = new node("", "", "", 0);
    nwnode->nna=NULL;
    nwnode->setter();
    if(first==NULL){
        first=nwnode;
        return;
    }
    curr=first;
    while(curr->nna!=NULL)
    {
        curr=curr->nna;
    }
    curr->nna=nwnode;
}

void linkedList::deletion()
{
    int idd;
    cout << "Enter employ Id you want to delete: ";
    cin >> idd;
    curr=prev=first;
    if(first==NULL){
        cout << "List is empty" << endl;
        return;
    }
    if(first->empID==idd)
    {
        first=first->nna;
        delete curr;
        return;
    }
    while(curr!=NULL)
    {
        if(curr->empID==idd)
        {
            prev->nna=curr->nna;
            delete curr;
            return;
        }
        prev=curr;
        curr=curr->nna;
    }
    cout << "ID not found" << endl;
}
void linkedList::display()
{
    curr=first;
    while(curr!=NULL)
    {
        curr->getter();
        curr=curr->nna;
    }
}
int main()
{
    linkedList obj;
    char choice;
    do{
    cout << endl;
    cout << "---Employ Management---" << endl;
    cout << "---------------------" << endl;
    cout << "1.create data" << endl;
    cout << "2.insert data at beginning" << endl;
    cout << "3.insert data at middle" << endl;
    cout << "4.insert data at Last" << endl;
    cout << "5.Delete " << endl;
    cout << "6.Display" << endl;
    cout << "7.Exit" << endl;
    cout << "----------------------" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case '1' :
            obj.createDB();
            break;

            case '2' :
            obj.insertAtBeg();
            break;

            case '3' :
            obj.insertAtMid();
            break;

            case '4' :
            obj.insertAtLast();
            break;

            case '5' :
            obj.deletion();
            break;
            case '6':
                obj.display();
                break;
            case '7' :
            return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }while(true);
    return 0;
}