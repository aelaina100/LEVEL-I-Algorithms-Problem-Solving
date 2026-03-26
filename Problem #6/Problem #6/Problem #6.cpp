
#include <iostream>
#include <string>
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


struct stFullName
{
	string FirstName;
	string LastName;
};
// so far, only a structure user-defined data type has been created. Nothing else.
// the next natural step is to create a variable of this structure user-defined data type.
// it's going to be either a normal variable (for one record)  or  an array variable (for more than one record)
//
//But the main question remains- WHERE to declare this variable ?
	// If it's to be initialized directly, then declare this variable in main().
	// If it is to be initialized via reading user-input, then declare this variable in a reading function of the structure type, that returns this declared variable
		// since it's the former, then begin IMMEDIATELY by implementing this function below NOW:

stFullName ReadFullName()
{
	stFullName FullName;  // ONLY declare a variable of the nesting structure(not the nested one(s)) and /or independent structure(s).    // what's returned.
	                     // the variable 'FullName' has access to all member variables in the structure. (ALWAYS envision this, when reading this line ANYWHERE in the program)
	
		
	cout << "Enter First Name: ";
	getline(cin, FullName.FirstName); //ALWAYS use for strings ONLY [instead of cin >> ] as cin >> for strings will not take into sonsideration any space(s) present in the string.
	cout << endl;

	cout << "Enter Last Name: ";
	getline(cin, FullName.LastName);
	cout << endl;

	return FullName;
	// The variable 'FullName' WAS fully initialized with all memeber variables, and THEN returned.
	// It is returned to the calling function that evaluates to produce a value of type 'stFullName' (which initializes the object in the calling function)
	// (it is returned to the calling function that evaluates to it ? is this a better way of wording it ?)

	// The lifetime of the local variable 'FullName' ends when the program exists the curly brackets of this function).
	// Now it is the time to compose the nested functions line in main()
}

string ConcatenateNames(stFullName FullName)  // pass by value
{
	return (FullName.FirstName + " " + FullName.LastName);
}

void PrintFullName(const stFullName &FullName) // passing by const ref.
{
	cout << "Your full name is: " << ConcatenateNames(FullName) << endl; // فرّق تسد/ Divide & conquer. Why not including line(s) of code in a function when it is possible !

	//cout << "Your full name is: " << FullName.FirstName << " " << FullName.LastName << endl;  // ❌ WRONG- you are not applying the strategy:  Divide & Conquer / فَرِّقْ تَسُدْ
}                                                                                                // as we could utiélze concatenation inside a function.

int main()
{
	/*
	 since these 2 variables are related amongst each other, I will not declare them in main().
	 Instead, I will declare them as member variables inside a structure.
	
	*/
	PrintFullName(ReadFullName());

	return 0;
}











