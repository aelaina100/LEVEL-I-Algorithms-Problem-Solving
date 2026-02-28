
#include <iostream>
using namespace std;

/*
 Problem:

 Write a program to ask the user to enter:
 - Mark1, Mark2, Mark3

 Then print the Average of entered Marks

 Example Inputs:
 90
 80
 70

 Outputs:
 80
*/




// solving it the primitive way without arrays:

struct stMarks
{
	float Mark1;
	float Mark2;
	float Mark3;
};
// so far only a structure user-defined data type has been created.
// The next natural step is to declare a variable of this structure user-defined data type.
// The question is, WHERE to create this varible?
//
//   -Is this variable going to be initialized directly ? (Then declare the variable in main())
//   -Or is this variable going to be initialized via reading user-input ? (Then declare it inside the reading function of type structure, 
//    since this structure user-defined data type variable is what will be returned).
//     [ .. and inside that function- we will ask whether it is going to be a normal variable or an array variable]
// 
// so immediately (100 percent correct !! and do it this way ALWAYS) start with the below immediate lines:
stMarks ReadMarks()
{
	// Are we going to declare a normal variable (one record) or an array variable (more than one record) ? where each element of the array represents an entire record ?
	stMarks marks; // what is returned

	cout << "Enter First Mark: ";
	cin >> marks.Mark1;
	cout << endl;

	cout << "Enter Second Mark: ";
	cin >> marks.Mark2;
	cout << endl;

	cout << "Enter Third Mark: ";
	cin >> marks.Mark3;
	cout << endl;

	return marks;
	// When 'marks' is returned, it will by fully initialized with all the member variables inside it.
}


float CalculateAverage(float SumResult) // passing by value
{
	return SumResult / 3;   // No int division happens becasue SumResult is of type float.
}

float CalculateSum(stMarks marks) // passing by value
{
	return (marks.Mark1 + marks.Mark2 + marks.Mark3);
}

void PrintAverageMark(const stMarks& marks)   // passing by const reference.
{
	cout << "The average of the marks: " << marks.Mark1 << " & " << marks.Mark2 << " & " << marks.Mark3 << " = " << CalculateAverage(CalculateSum(marks)) << endl;
}

int main()
{
	// Since these variables are related amongst each other,
	// then declare them as member variables inside a structure.
     

	// second immediate step:
	PrintAverageMark(ReadMarks());

	/* Instead of :
	* 
	PrintAverageMarks(CalculateAverage(ReadMarks())); // Excellent but doesn't give the printing procedure access to the marks the user entered (= they can't be referenced).

	 */
	 // and if its to be used then the printin procedure parameters is to change to: const float &average
	return 0;
}


/* So let us start with a general mental model that is to be refined very soon:

   
   PrintAverageMark(CalculateAverageMark(ReadMarks())

   The nested CalculateAverageMark & ReadMarks,    both HAVE to be functions. Because an argument can never equate to void = compiler error.

   The problem with the current line of nested functions:

   PrintAverageMark(CalculateAverageMark(ReadMarks())
   is that, the original marks that the user enters can NOT be referenced inside the printing procedure so
   that, for example, one can not output a message such as " For Mark1 = 80, Mark2 = 90, Mark3 = 100, the average is = ".

   To overcome this issue, we have 2 possible solution:

   PrintAverageMark(ReadMarks())         
   where inside the Printing Procedure, we could call the function CalculateAverageMark() that is yet to be implemented
   for example:    cout << "The average for the marks " << marks.Mark1 << "," << marks.Mark2 << "," << marks.Mark3 << " = " << CalculateAverageMark() << endl;


   OR 

   The unoptimized solution of:

   stMarks marks = ReadMarks();  // The right operand is written at last ( and this is NOT the declaration of the structure user-defined data type; as this is simply
                                 // to catch the value returned by the function so it could be used later.

 PrintAverageMarks(CalculateAverage(ReadMarks()), marks);


*/