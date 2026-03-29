// Problem #3.cpp :
//

#include <iostream>
using namespace std;

/*
Problem #3

 Write a program to ask the user to enter a number,
 then print "Odd" if it is odd, or "Even" if it is even.


*/

/*
 Solution:
 We will start this program by creating an enum user-defined data type.
 Reason is that:

 A number is even if its remainder = 0.
 A number is odd if its remainder is NOT 0 ( 1 for positive numbers  and  -1 for negative numbers).

 so the 0 and 1 here signify an even or add. They will also not be used arithmetically.

    // In this example, we will not do any input validation for range as of yet. 
   // As we are focussing on the logic.
  // This will be done in the upcoming lectures where we will modify this specific example so that the solution is final.
*/

 
// If an enum is to be used in a program, then it's the first thing that is coded.
enum enEvenOrOdd {Even = 0, Odd = 1};

int ReadNumber()
{
    int number; // what's returned.

    cout << "Enter number: ";
    cin >> number;
    cout << endl;

    return number; 
    // The variable 'number' was initialized & then returned.
    // The calling function, ReadNumber(), in main() evaluates to produce a value of type int (that initializes an object in the calling function).
    //
    // The lifetime of the local variable 'number' ends when the program exists the curly brackets of this function.
    // 🔥🔥🔥 correct !
}

enEvenOrOdd NumberType(const int& number) // passing by const reference
{
    if (number % 2 == 0)
    {
        return enEvenOrOdd::Even; // returns 0 of type    enEvenOrOdd
    }
    else  // could be 1 for positive numbers...or... -1 for negative numbers
    {
        return enEvenOrOdd::Odd; // returns 1 of type   enEvenOrOdd 
    }
}

void PrintNumberType(const enEvenOrOdd &EvenOrOdd)  // pass by const reference.
{
    if (enEvenOrOdd::Even == EvenOrOdd)  // to the left of the operand (from the data type creation step)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
}



int main()
{
    //enEvenOrOdd EvenOrOdd;   // discovered that it is NOT needed.

    PrintNumberType(NumberType(ReadNumber()));

    return 0;
}





























//
//enum enEvenOrOdd { Even = 0, Odd = 1};
//      
//
//int ReadNumber()
//{
//	int number;
//
//	cout << "Enter a number: ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//
//enEvenOrOdd CheckNumberType(const int &number) // passing by constant reference.
//{
//	if (number % 2 == 0)
//	{
//		return enEvenOrOdd::Even;  //  = 0
//	}
//	else // could be 1 for positive numbers   or   -1 for negative numbers.
//	{
//		return enEvenOrOdd::Odd;   // = 1
//	}
//}
//
//
//void PrintEvenOrOdd(const enEvenOrOdd &EvenOrOdd)  // passing by constant reference.
//{
//	if (EvenOrOdd == enEvenOrOdd::Even)
//	{
//		cout << " It is even" << endl;
//	}
//	else
//	{
//		cout << " It is odd" << endl;
//	}
//}
//
//int main()
//{
//	enEvenOrOdd EvenOrOdd;
//
//
//
//
//	PrintEvenOrOdd(CheckNumberType(ReadNumber()));  // let's start with this line.
//
//	return 0;
//}























/* Solution:
   If the remainder is 0, then the number is even.
   If the remainder is 1, then the number is odd.
   This means that we start writing this program utilizing enums, as 0 and 1 signify Even and Odd respectively.

   Note: Will eventually discover that this example will NOT follow the conventional enum mental model workflow.
         Think of it as a "forced" exercise by the instructor.
		 This is why declaring a variable of the enum type which is the next natural step was not utilized.
 
*/


//enum enNumberType {Even = 0, Odd =1};
//// so far, an enum user-defined data type has been created. That's all.
//// The next natural step is to create a variable of this enum user-defined data type.
//
//
//int ReadNumber()
//{
//	int number;
//	do
//	{
//		cout << "Enter a positive number: ";                            // future follow-up: entering negative decimal.
//		cin >> number;
//
//	} while(number <= 0);  //👉 condition written so that it evaluates to true when the range is invalid.
//
//	return number;
//}   
//
//// this should be a UTILITY that is implemented in an external file (We'll learn more about that soon);
//enNumberType CheckNumberType(int number) // passing by value  //parameter name can be named anything.
//{
//	 if (number % 2 == 0)
//	 {
//		 return enNumberType::Even;
//	 }
//	 else
//	 {
//		 return enNumberType::Odd;
//	 }
//}
//
//void PrintNumberType(const enNumberType &NumberType) // passing by constant reference.
//{
//	if (NumberType == enNumberType::Even)
//	{
//		cout << "Number is Even \n";
//	}
//	else
//	{
//		cout << "Number is Odd \n";
//	}
//}
//
//int main()
//{
//	//enNumberType NumberType;  // proven not to be needed.
//
//	PrintNumberType(CheckNumberType(ReadNumber()));
//
//	return 0;
//}





























