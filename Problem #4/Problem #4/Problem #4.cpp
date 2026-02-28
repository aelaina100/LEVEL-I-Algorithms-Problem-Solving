
#include <iostream>
using namespace std;

/*
 Problem:

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

/* 
 So far, only a structure user-defined data type has been created. Nothing else.
 The next natural step is declaring a variable of this type.
 It's either going to be a normal variable (one record) or an array variable (more than one record).

 But the question is- Where to declare this variable ?
 - If it's to be initialized directly, then declare in it main().
 - If it's to be intialized via reading user input, then declare it a function of type structure that returns this variable
	so implement this function now immediately: 100!
  
*/
stPersonalInfo ReadPersonalInfo()
{
	stPersonalInfo PersonalInfo; // what will be returned.

	cout << "Enter age: ";
	cin >> PersonalInfo.age;
	cout << endl;

	cout << "Do you have a driver License (Enter 1 for yes / 0 for no) : ";
	cin >> PersonalInfo.HasDriverLicense;
	cout << endl;

	return  PersonalInfo;
	// The variable PersonalInfo is now initialized with the member variables 'age' and 'HasDriverLicense' and returned.
	// The calling function evaluates to produce a value of type stPersonalInfo (initialized in an object of the calling function).
	// 
	// The lifetime of the local variable PersonalInfo ends when the programs exists the curly brackets of this function.
	// 
	// Now, the next step is writing the nested functions line in main()
}

bool HiringDecision(stPersonalInfo PersonalInfo) // return by value
{
	return (PersonalInfo.age > 21 && PersonalInfo.HasDriverLicense);
}

void PrintHiringDecision(const bool &HiredOrNot)
{
	if (HiredOrNot)
	{
		cout << " Hired !" << endl;
	}
	else
	{
		cout << "Not Hired.." << endl;
	}
}


int main()
{
	// Instead of declaring variables in main(),
	// I will declare them as member variables inside a structure since they're related amongst each other,

	PrintHiringDecision(HiringDecision(ReadPersonalInfo()));
	return 0;
}
























//
//
//
//
//struct stApplicantInfo
//{
//	unsigned short age;
//	bool HasDriverLicense;
//};
//// so far we have created a structure user-defined data type and that's all.
//// the next natural step is to declare a variable of this structure user-defined data type.
//// that is either a normal variable (for one record) or an array variable (for more than one record).
////
//// but the question is, how is it going to be initialized ?
//// directly ?, then declare this variable in main()
//// or via reading user input ?, then declare this variable in a reading function of this structure data type
//// that returns this variable.
//
//// now, we start by creating a nested function line in main().
//
//
//
//
//
//
//stApplicantInfo ReadUserInput() // immediately start by typing the function data type, then the name.
//{
//	stApplicantInfo ApplicantInfo; // only declare the nesting variable (not the nested one(s)) and/ or the independent ones.
//
//	cout << "Enter Age: ";
//	cin >> ApplicantInfo.age;
//	cout << endl;
//
//	cout << "Do you have a Driver License (Enter 1 for Yes / Enter 0 for No): \n";
//	cin >> ApplicantInfo.HasDriverLicense;
//	cout << endl;
//
//	return ApplicantInfo;
//}
//
//bool IsHired(const stApplicantInfo &ApplicantInfo)  // passing by constant reference.
//{
//	return (ApplicantInfo.age > 21 && ApplicantInfo.HasDriverLicense);
//}
//
//void PrintDecision(const stApplicantInfo &ApplicantInfo) // passing by constant referecne.
//{
//	if (IsHired(ApplicantInfo))
//	{
//		cout << "Hired ! \n";
//	}
//	else
//	{
//		cout << "Rejected \n";
//	}
//}
//
//int main()
//{
//
//	PrintDecision(ReadUserInput());       // No more than 2 nested functions for the purpose of readiability.
//
//	return 0; 
//}










//
// old solution:
//
//struct stUserInfo
//{
//    unsigned short int age;
//    bool HasDriverLicense;
//};
// New up-to-date mental model:
// 
// so far a structure user-defined data type has been created. That is all.
// The next natural step is to create a variable of this structure user-defined data type
// The question is: Should I declare a normal variable (One record) or an array variable (more than one record).
//
// and then, WHERE should I declare it ?
//
//will this variable be initialized directly ? then, do that inside main()
// or will it be intitialized via reading user input ? then, declare it inside a reading function where it is what is returned
//
//void ReadUserInput(stUserInfo &UserInfo) // passing by reference // each structure nested or not will have its own reading procedure.
//{
//    cout << "Enter Age: \n";
//    cin >> UserInfo.age;
//    cout << endl;
//
//    cout << "Has a Driver License ? (1 for Yes / 0 for No): \n";
//    cin >> UserInfo.HasDriverLicense;
//    cout << endl;
//
//
//}
//
//bool IsHiredOrNot(const stUserInfo &UserInfo) // passing by constant reference.
//{
//    return (UserInfo.age > 21 && UserInfo.HasDriverLicense);
//    
//    
//}
//
//void PrintResultHiredOrNot(const bool &ResultHiredOrNot) // passing by constant reference
//{
//    if (ResultHiredOrNot)
//    {
//        cout << "Hired !" << endl;
//    }
//    else
//    {
//        cout << "Not hired.." << endl;
//    }
//}
//
//int main()
//{
//    stUserInfo UserInfo;
//     Initializing the variable 'UserInfo' via reading user input:
//
//    ReadUserInput(UserInfo);
//     The variable UserInfo is now fully initialized.
//
//    bool ResultHiredOrNot = IsHiredOrNot(UserInfo);
//
//    PrintResultHiredOrNot(ResultHiredOrNot);
//
//
//    return 0;
//}



