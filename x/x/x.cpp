
#include <iostream>
using namespace std;


/*Problem #11:

 Write a program to ask the user to enter :
 -Mark1, Mark2, Mark3

 Then print the Average of the entered Marks, and print "PASS" if average >= 50,
 otherwise print "FAIL".

 Example Inputs :
 90
 80
 70

 Outputs :
	80
	PASS

 * /
 

 /* Solution:
	   This problem is solved utilizing arrays. The utilization of structures would be considered primitive in comparison.
	   For practice purposes, I'll incorporate enums in solving this problem. Thus, the workflow might not reflect the enums mental model documented in the C++ course.

 */

// Nonetheless- I will start solving this problem utilizing mere variables instead of the correct solution with arrays.
// If enums are to be utilized in any program, then ALWAYS code them first.

enum enPassOrFail {Pass = 1, Fail = 0}; //Enumeration constants (enumerators) acting as labels for the integral raw numbers they represent.
                                        // so from now and on, forget about these raw numbers.
// so far, nothing has been created but an enum user-defined data type. The next natural step is declaring a variable of it.


void ReadMarks(float& Mark1, float& Mark2, float& Mark3) // pass by reference.
{
	cout << "Enter the first mark: ";
	cin >> Mark1;
	cout << endl;

	cout << "Enter the second mark: ";
	cin >> Mark2;
	cout << endl;

	cout << "Enter the third mark: ";
	cin >> Mark3;
	cout << endl;
}

float CalculateMarksSum(float Mark1, float Mark2, float Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverageMark(float Mark1, float Mark2, float Mark3) // pass by value.
{
	return CalculateMarksSum(Mark1, Mark2, Mark3) / 3;   // NOT an integer divisions as marks are floats.
}

enPassOrFail PassOrFail(const float& average)  // pass by constant reference.
{
	if (average >= 50)
	{
		return enPassOrFail::Pass;  // 1 of data type enPassOrFail is what's returned.
	}
	else
	{
		return enPassOrFail::Fail;  // 0 of data type enPassOrFail is what's returned.
	}
}

string DetermineResult(const enPassOrFail &result) // pass by const reference.
{
	if (result == enPassOrFail::Pass)
	{
		return "PASS";
	}
	else
	{
		return "FAIL";
	}
}

void PrintResult(const float& average) // pass by constant reference.
{
	cout << "The average is " << average << " . The result is: " << DetermineResult(PassOrFail(average));
}

int main()
{
	//enPassOrFail PassorFail; // the natural step of declaring a variable of this enum user-defined data type. // commented out as it turned out it's not needed.

	float Mark1, Mark2, Mark3;
	// Initializing these 3 variables via reading user input:

	ReadMarks(Mark1, Mark2, Mark3);
	// theese 3 variables are now initialized


	PrintResult(CalculateAverageMark(Mark1, Mark2, Mark3)); // as the CalculateAverageMark() function contains CalculateSum()/3. Hence, Mark1, Mark2, Mark3 are passed as arguments.

	return 0;
}