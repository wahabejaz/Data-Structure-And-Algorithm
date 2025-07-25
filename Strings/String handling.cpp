//stringManagementSystem
//The program takes the string input and display statistics according to operations
//Programmer Name: Wahab Ejaz
//Compiler: gcc
//Date: 17-NOV-2024
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class myString{
	private:
		string str;
	public:
		//constructor
		myString(string s = ""):str(s){}
		//member functions
		void setString();
		void getString();
		void concatenation();
		void deletion();
		void search();
		void comparison();
		void length();
		void statistics();
		void toUpperCase();
		void toLowerCase();
};
void myString::setString() {
	cout << "Enter new string: " ;
	cin.ignore();
	getline(cin, str);
}
void myString::getString() {
	if(str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else
	cout << " Current string: " << str << endl;
	
}
void myString::concatenation() {
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
    char choice;
    string toAppend;
    cout << endl;
    cout << " ---CONCATENATE--- \n";
    cout << " 1. At Beginning \n";
    cout << " 2. At End \n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == '1') {
        cout << "Enter string to prepend: ";
        getline(cin, toAppend);
        str = toAppend + str;
    } else if (choice == '2') {
        cout << "Enter string to append: ";
        getline(cin, toAppend);
        str += toAppend;
    } else {
        cout << "Invalid Input!" << endl;
    }
	}
}

void myString::deletion() {
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
    string subString;
    cout << "Enter substring to delete: ";
    cin.ignore();
    getline(cin, subString);
    size_t pos = str.find(subString);
    if (pos != string::npos) {
        str.erase(pos, subString.length());
        cout << "String after deletion: " << str << endl;
    } else {
        cout << "Substring not found!" << endl;
    }
	}
}
void myString::search() {
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
	string subString;
	cout << "Enter substring to search: ";
	cin.ignore();
	getline(cin,subString);
	size_t pos = str.find(subString);
	if (pos != string::npos){
	cout << "Substring found!. Starting from letter: " << pos+1 << endl;
	}
	else
	cout << "Substring not found!" << endl;
	}
}
void myString::comparison() {
	string ss;
	if (str.empty()){
	cout << "First store string using option 1 in order to compare with another!"<< endl;
	return ;
	}else{
	cout << "Enter string to Compare with: ";
	cin.ignore();
	getline(cin,ss);
	if (ss == str)
	cout << "Strings are equal."<< endl;
	else if (ss < str)
	cout << "Current string is less than the input."<< endl;
	else
	cout << "Current string is greater than the input."<< endl;
	}
}
void myString::length(){
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
	int length;
	length= str.length();
	cout << "Length of the string: " << length << endl;
	}
}
void myString::statistics() {
	if (str.empty()){
	return ;
	}else{
	int upper = 0, lower = 0, digits = 0, special = 0;
	for(int i=0; i< str.length(); i++)
	{
		if (isupper(str[i]))
		upper++;
		else if (islower(str[i]))
		lower++;
		else if (isdigit(str[i]))
		digits++;
		else if (ispunct(str[i]))
		special++;	
	}
	cout << "Uppercase letters: " << upper << endl;
	cout << "Lowercase letters: " << lower << endl;
	cout << "Digits: " << digits << endl;
	cout << "Special characters: " << special << endl;
	}
}
void myString::toUpperCase() {
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
	for(size_t i=0; i<str.length(); i++)
	{
		str[i]=toupper(str[i]);
	}
	cout << "string in uppercase: " << str << endl;
	}
}
void myString::toLowerCase() {
	if (str.empty()){
	cout << "First store string using option 1."<< endl;
	return ;
	}else{
	for(size_t i=0; i<str.length(); i++)
	{
		str[i]=tolower(str[i]);
	}
	cout << "string in lowerecase: " << str << endl;
	}
}
int main() {
    myString str;
    int choice;
    do {
        cout << endl;
		cout << " |----MENU----|" << endl;
		cout << "1. Store String." << endl;
		cout << "2. Concatenate String." << endl;
		cout << "3. Delete string/substring." << endl;
		cout << "4. Search string." << endl;
		cout << "5. Compare string." << endl;
		cout << "6. Display Length." << endl;
		cout << "7. Display statistics." << endl;
		cout << "8. Convert to uppercase." << endl;
		cout << "9. Convert to lowercase." << endl;
		cout << "10. Display String." << endl;
		cout << "11. EXIT " << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			str.setString();
			break;
            case 2:
			str.concatenation();
			break;
            case 3:
			str.deletion();
			break;
            case 4:
			str.search();
			break;
            case 5:
			str.comparison(); 
			break;
            case 6:
			str.length();
			break;
            case 7:
			str.statistics(); 
			break;
            case 8:
			str.toUpperCase();
			break; 
            case 9:
			str.toLowerCase(); 
			break;
            case 10: 
			str.getString();  
			break;
            case 11: 
			cout << "Exiting break;Program..." << endl; 
			return 0;
            default: 
			cout << "INVALID INPUT!" << endl; 
			break;
        }
    } while (choice != 11);
system("pause");
    return 0;
}