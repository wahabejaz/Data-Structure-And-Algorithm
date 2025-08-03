//isPalindrome
//The program checks whether the gien string is palindrome or not
//Programmer Name : Wahab Ejaz
//compiler : gcc
//Date : 24 May 2024
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    // Convert the string to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Create a reversed version of the string
    string p = s;
    reverse(p.begin(), p.end());

    // Check if the original and reversed strings are the same
    return s == p;
}

int main() {
    // Declaration
    string name;
    
    // Input
    cout << "Enter string to check palindrome: ";
    cin >> name;
    
    // Output
    if (isPalindrome(name))
        cout << name << " is a Palindrome." << endl;
    else
        cout << name << " is not a Palindrome." << endl;

    return 0;
}
