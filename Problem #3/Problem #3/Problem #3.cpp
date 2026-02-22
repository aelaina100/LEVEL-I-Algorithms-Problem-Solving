// Problem #3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

/*
Problem #3

 Write a program to ask the user to enter a positive number,
 then print "Odd" if it is odd, or "Even" if it is even.


*/


/* Solution:
   If the remainder is 0, then the number is even.
   If the remainder is 1, then the number is odd.
   This means that we start writing this program utilizing enums, as 0 and 1 signify Even and Odd respectively.

   Note: Will eventually discover that this example will NOT follow the conventional enum mental model workflow.
         Think of it as a "forced" exercise by the instructor.
		 This is why declaring a variable of the enum type which is the next natural step was not utilized.
 
*/


enum enNumberType {Even = 0, Odd =1};
// so far, an enum user-defined data type has been created. That's all.
// The next natural step is to create a variable of this enum user-defined data type.


int ReadNumber()
{
	int number;
	do
	{
		cout << "Enter a positive number: ";                            // future follow-up: entering negative decimal.
		cin >> number;

	} while(number <= 0);  //👉 condition written so that it evaluates to true when the range is invalid.

	return number;
}   

// this should be a UTILITY that is implemented in an external file (We'll learn more about that soon);
enNumberType CheckNumberType(int number) // passing by value  //parameter name can be named anything.
{
	 if (number % 2 == 0)
	 {
		 return enNumberType::Even;
	 }
	 else
	 {
		 return enNumberType::Odd;
	 }
}

void PrintNumberType(const enNumberType &NumberType) // passing by constant reference.
{
	if (NumberType == enNumberType::Even)
	{
		cout << "Number is Even \n";
	}
	else
	{
		cout << "Number is Odd \n";
	}
}

int main()
{
	//enNumberType NumberType;  // proven not to be needed.

	PrintNumberType(CheckNumberType(ReadNumber()));

	return 0;
}





























