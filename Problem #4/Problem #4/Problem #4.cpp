
#include <iostream>
using namespace std;

/*
 Problem #4:

 Write a program to ask the user to enter his/her:
 - Age
 - Driver license

 Then print "Hired" if his/her age is greater than 21 and he/she has a driver license,
 otherwise print "Rejected".

*/


struct stPersonalInfo
{
	unsigned short age;
	bool HasDriverLicense;
};
// so far only a structure user-defined data type has been created. That's all.
// The next natural step is declaring a variable of this structure user-defined data type.
// It's going to be either a normal variable (one record)  or  an array variable (more than one record).
//
// But the question is, where should this variable be declared ?
//   if it's going to be initialized directly, then declare it in main()
//   it it's going to be initialized via reading user input, then declare it in a reading function of type structure that returns this declared variable.
 // since it's the former, then start by implementing this function IMMEDIATELY NOW:

stPersonalInfo ReadPersonalInfo()
{
	stPersonalInfo PersonalInfo; // The next natural step of declaring a variable of the structure user-defined data type // What's returned.
	// (you SHOULD immediately envision that personalInfo has access to all member variables inside this stPersonalInfo structure user-defined data type
	// as in PersonalInfo.age,     PersonalInfo.HasDriverLicense   ANYWHERE in the program when you encounter such a line)
	
	cout << "Enter your age: ";
	cin >> PersonalInfo.age;
	cout << endl;

	cout << "Do you have a driver license ? ( Enter 1 for Yes  /  0 for No): ";
	cin >> PersonalInfo.HasDriverLicense;
	cout << endl;

	return PersonalInfo;
	// The variable 'PersonalInfo' WAS initialized with all member variables (PersonalInfo.age   &   PersonalInfo.HasDriverLicense) and THEN returned to the calling function.
	// The called function, ReadPersonalInfo(), evaluates to produce a value of type stPersonalInfo (which initializes the object in the called function).
	//
	// The lifetime of the local variable 'PersonalInfo' ends when the program exists the curly functions of this function.
	// 🔥🔥🔥 correct !
	// Now is the time to construct the nested functions line in main()
}


     //  فَرِّقْ تَسُدْDivide & Conquer 
bool IsHired(stPersonalInfo PersonalInfo) // pass by value. // the name of the variable PersonalInfo could've been anything.
{
	return (PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense);   // Divide & conquer / فَرِّقْ تَسُدْ -you ALWAYS put this inside a function even if it is a tinier line ! 
}

void PrintHiringDecision(const bool &HiredOrNot) // pass by const ref.  // avoid naming the variable 'IsHired' as this is the name of an existing function in this program.
{                                                                       // this is not ideal and may cause confusion even though our program will still work.
	if (HiredOrNot)
	{
		cout << "Hired! \n";
	}
	else
	{
		cout << "Not Hired... \n";
	}
}


int main()
{
 // These variables will not be declared in main(),
 // but instead, they will be declared as member variables in a structure since they are related amongst each other.


	PrintHiringDecision(IsHired(ReadPersonalInfo())); // The arguments have to be functions. As procedures return void which can NEVER be the argument of a function/procedure.

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////S

/* Now- what if I replace the above line in main():

  PrintHiringDecision(IsHired(ReadPersonalInfo()));

  with 

   PrintHiringDecision(ReadPersonalInfo());    ?    // This is what the instructor used and this should move to the top of the program with all of the comments.
   // so let us design this program according to this new 'requirement'.   

*/



struct stPersonalInfo
{
	unsigned int age;
	bool HasDriverLicense;
};


stPersonalInfo ReadPersonalInfo()
{
	stPersonalInfo PersonalInfo;

	cout << "Enter age: ";
	cin >> PersonalInfo.age;
	cout << endl;

	cout << "Do you have a driver liscense ? ( Enter 1 for Yes / Enter 0 for No): ";
	cin >> PersonalInfo.HasDriverLicense;
	cout << endl;

	return PersonalInfo;
}

bool IsHired(stPersonalInfo PersonalInfo) // pass by value
{
	return (PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense);
}

void PrintHiredOrNot(const stPersonalInfo &PersonalInfo) // pass by const reference
{
	if (IsHired(PersonalInfo))
	{
		cout << "Hired !... \n";
    }
	else
	{
		cout << "Not Hired... \n";
	}
}

int main()
{


	PrintHiredOrNot(ReadPersonalInfo());

	return 0;
}
















































