
#include <iostream>
using namespace std;

/*
 Problem #8:

  Write a program to ask the user to enter:
  - Mark

  Then print the "PASS" if mark >= 50, otherwise print "Fail"



  Example Inputs:

  45

  Outputs ➔

  Fail


*/
 
/*  Solution:
    I will START this program by creating an enum user-defined data type.
	The enum workflow will not be the regular standard one according to the mental model.
		where the common theme in this case is:

		- No variable declared of this enum user-defined data type.
			Meaning, the variable is neither initialized directly.
			nor initialized via reading user input, so that it is compared
			in a switch statement against the existing enumration constants (enumerators)
			present in the enum data type creation step.


	This is intentional in order to hon in your skill utilizing enums.
	PLUS we are going to improve on this program as we proceed- where the use
	of enum will be realized as necessary.

*/


enum enPassFail { Fail = 0, Pass = 1 };
// so far, I've only created an enum user-defined data type.That's all.



float ReadGrade()
{
	float grade;

	cout << "Enter the grade: ";
	cin >> grade;
	cout << endl;

	return grade;
}

enPassFail DeterminePassOrFail(const float& grade) //  فَرِّقْ تَسُدْ / Divide & conquer:   Passing by cons reference as we're just comparing.
{                                                    // I can now use this function anywhere in my code- for ex: to be an argument for a future function/procedure etc.
	if (grade >= 50)
		return enPassFail::Pass;  // 1
	
	else
		return enPassFail::Fail;  // 0
	
}

void PrintResult(const float& grade) // passing by const reference
{
	if (DeterminePassOrFail(grade) == enPassFail::Pass)
	{
		cout << grade << " is " << "Pass" << endl;
	}
	else
	{
		cout << grade << " is " << "Fail" << endl;
	}
}


int main()
{


	PrintResult(ReadGrade()); // so that the printed line can reference the original mark the user entered. 
	// PrintResult(DeterminePassOrFail(ReadGrade()));  will result in a printed line stating passing or failing without ability to mention(reference) the original entered mark.
	// 
	// Unless, we structure it in the following way:

	/*
	int grade = ReadGrade();
	PrintResult(DeterminePassOrFail(), grade)

	// which is unoptimized.
	*/

	return 0;
}


















//
//// My first solution:
//float ReadGrade()
//{
//	float grade; // what is returned
//
//	cout << "Enter a grade: ";
//	cin >> grade;
//	cout << endl;
//
//	return grade;
//
//}
//
//string GradingResult(const float &grade) // passing by const reference 
//{
//	if (grade >= 50)
//	{
//		return "Pass";   // always try to return something instead of printing. As printing (= a procedure) would make the use of this procedure limited.
//	}                    // Instead, make this function returns a value and then we could do MANY things with this returned value such as printing 
//	
//	else 
//	{
//		return "Fail";
//	}
//}
//
//void PrintResult(const float &grade) // pass by constant reference (creating an alias to the value existing in main())
//{
//	cout << grade << " is " << GradingResult(grade) << endl;
//}
//
//
//int main()
//{
//  
//	PrintResult(ReadGrade()); // the argument must be a function that returns ONE value. a procedure returns void which can never be an argument of  this procedure.
//
//	return 0;
//}
//
//

