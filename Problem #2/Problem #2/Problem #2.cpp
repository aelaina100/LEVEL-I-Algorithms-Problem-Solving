

#include <iostream>
#include <string>;
using namespace std;


/*
Problem #2

Write a program to ask the user to enter his/her name and
print it on screen.

*/


string ReadName(unsigned short MaxNumOfCharacter)  // ranges are ALWAYS passed by value.
{
    string name;  // must be declared in the function scope so it can be returned (not 'do' scope)

    do
    {
        cout << "Enter your name [A maximum of 14 characters are allowed]: ";
        getline(cin,name); // value entered by user should be immediately validated in the while condition.

    } while (name.length() > MaxNumOfCharacter);   // condition written so that it evaluates to true when it is invalid
    
    return name;  // IMMEDIATELY validated in the condition against the range.
}

void PrintName(const string &name) // passing by constant reference.
{
    cout << "Entered name is: " << name << endl;
}


int main()
{
    unsigned short MaxNumOfCharacters = 14; // instead of hardcoding it.
    PrintName(ReadName(MaxNumOfCharacters)); // passing a range argument since its value is NOT intrinsic.
                                             // It will be compared in the do..while condition against the user input.

	return 0;
}






//// My old solution: 
//string ReadUserName()
//{
//    string name;
//    do
//    {
//        cout << "Enter your name [Maximum of 14 digits]: ";
//        getline(cin,name);
//
//    } while (name.length() > 14);
//
//    return name;
//}
//
//int main()
//{
//    // Initializing the below variable, via reading user input (using a function)  // since there is one user input
//    string name = ReadUserName(); 
//
//    cout << "Your name is: " << name << endl;
//
//
//    return 0;
//}


