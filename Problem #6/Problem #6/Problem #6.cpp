
#include <iostream>
#include <string>; // for using the getline(cin, )
using namespace std;

/*
 Problem:

 Write a program to ask the user to enter:
 - First Name
 - Last Name

 Then print Full Name on screen.

 Example Input:
 Mohammed
 Abu Hadhoud

 Output:
 Mohammed Abu-Hadhoud
*/


// Not only a structure is warranted from the get-go (immediate 1 st thing to create in the program),
// 
// but also because, the argument ReadUserInput() has to be a function, 
// where inside it, there will be two cin statements
// and these two aspects are reconciled by returning a structure user-defined data type.
// 

struct stFullName
{
	string FirstName;
	string LastName;
};
// so far we have only created a user-defined data type that is a structure. That's all.
// The next natural step is to declare a variable of this structure user-defined data type.
// so declare a normal variable (for one record) or an array variable (more than one record).

// Now, WHERE this variable is going to be declared depends on how it is initialized.
// If it's initialized directly, then declare it in main().
// If it's initialized via reading user-input, then declare it inside the reading function that returns
// this variable, which means that this function has a structure user-defined data type.



stFullName ReadUserInput()
{
	stFullName FullName; // ONLY declare a variable of the nesting structure (not the nested one(s)) and/or independent structure(s).
	                     // the variable 'FullName' has access to all member variables in the structure.
	                     // where they will be initialized by typing: FullName.FirstName;  FullName.LastName whether directly
	                     // or via reading user input.

	cout << "Enter First Name: ";
	getline(cin, FullName.FirstName);
	cout << endl;

	cout << "Enter Last Name: ";
	getline(cin, FullName.LastName);
	cout << endl;

	return  FullName;
	// When the variable FullName is returned,
	// It will be fully initialized.

	//Lifetime of this variable ends when the function finishes executing.
}

string ConcatenatedName(stFullName FullName) // passing by value.  // Now I can use this function not only for printing as needed in the example. But also in the future in a function and many other different scenario when I want to expand on this code.
{
	return FullName.FirstName + " " + FullName.LastName;
}

void PrintFullName(const stFullName &FullName) // passing by constant reference.
{
	cout << "The full name is: " << ConcatenatedName(FullName) << endl;  // فرّق تسد/ Divide & conquer. Why not including line(s) of code in a function when it is possible !
}

int main()
{
   
	PrintFullName(ReadUserInput());

	return 0;
}


