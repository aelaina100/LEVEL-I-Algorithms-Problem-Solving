
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
 

/* Solution:
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

// If enums are to be used in a program, then it SHOULD be the first to EVER code in the program:

enum enPassOrFail { Pass = 1, Fail = 0}; // the enumeration constants (enumerators) act as labels for the raw integral values they represent.
// so from now and on, FORGET about these raw integral values

// So far only an enum user-definded data type has been created. Nothing else
// the next natural step is declaring a variable of this enum user-defined data type.


float ReadMark()
{
	float mark; // what's returned.

	cout << "Enter mark: ";
	cin >> mark;
	cout << endl;

	return mark;
	// The variable 'mark' WAS initialized, and THEN returned.
	// It was returned to the called function that evaluates to produce a value of float type (which initializes the object in the called function).
	//
	// The lifetime of the local variable 'mark' ends when the program exists the curly brackets of this function.
}


enPassOrFail DeterminePassOrFail(float mark) // pass by value    //  فَرِّقْ تَسُدْ/Divide & conquer:   Passing by constant reference as we're just comparing.
{                                                                // I can now use this function anywhere in my code- for ex: to be an argument for a future function/procedure etc.
	if (mark >= 50)
	{
		return enPassOrFail::Pass;     // = 1 ( of data type enPassOrFail)
	}
	else
	{
		return enPassOrFail::Fail;   // = 0 ( of data type enPassOrFail)
	}
}

void PrintPassOrFail(const float &mark)   // passing by const ref.      // فَرِّقْ تَسُدْ  / Dive & conquer.
{
	if (enPassOrFail::Pass == DeterminePassOrFail(mark))  // "enPassOrFail::Pass" is in and by itself of type enPassOrFail  // فَرِّقْ تَسُدْ  / Dive & conquer.
	
	{
		cout << mark << " is " << "Pass \n";
	}
	else
	{
		cout << mark << " is " << "Fail \n";
	}
}



int main()
{
	//enPassOrFail PassOrFail; // declaring a variable of the enum user-defined data type. // commented out as it turned out that we never needed it.
	// let us start by composing the nested functions line.

	PrintPassOrFail(ReadMark()); // Nesting this way, enables the printing procedure to reference the original mark the user enters.

	/* whereas:
	 
	 PrintPassOrFail(DeterminePassOrFail(Readmark))); 
	// will not enable the printing procedure to reference the mark the user entered unless we complicate this line further by having:
	   
	   PrintPassOrFail(DeterminePassOrFail(Readmark), mark));  
	   // which is unoptimized.

	
	*/

	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

