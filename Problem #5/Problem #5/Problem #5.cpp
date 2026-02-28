// Problem #5.cpp

#include <iostream>
using namespace std;

/*
 Problem:

 Write a program to ask the user to enter his/her:
 • Age
 • Driver license
 • Has Recommendation!

 Then Print "Hired" if his\her age is grater than 21 and s/he has a driver license, otherwise Print "Rejected"

 Or If they have recommendation, thenm Hire him\her without conditions! (regardless of age and whether they have a driver license)
*/



/* Solution:
   Instead of declaring these 3 as variables in main(), I will declare them as member variables
   inside a structure since they are related amongst each other.
 
 */

struct stUserInfo
{
    unsigned short age;
    bool HasDriverLicense;
    bool HasRecommendation;
};
// so far we have created a structure user-defined data type and that's all.
// the next natural step is to declare a variable of this structure user-defined data type.
// that is either a normal variable (for one record) or an array variable (for more than one record).
//
// but the question is, how is it going to be initialized ?
// directly ?, then declare this variable in main()
// or via reading user input ?, then declare this variable in a reading function of this structure data type
// that returns this variable.

// now, we start by creating a nested function line in main().



stUserInfo ReadUserInput()
{
    stUserInfo UserInfo; // ONLY declare a variable of the nesting structure (never the nested one(s))   and/or   independent structure(s).

    cout << "Enter Age: ";
    cin >> UserInfo.age;
    cout << endl;

    cout << "Do you have a Driver License (Enter 1 for Yes / Enter 0 for No): ";
    cin >> UserInfo.HasDriverLicense;
    cout << endl;

    cout << "Do you have a recommendation (Enter 1 for Yes / Enter 0 for No): ";
    cin >> UserInfo.HasRecommendation;
    cout << endl;

    return UserInfo;
    // The variable 'UserInfo' will be returned FULLY initialized with: 
    // age, HasDriverLisence, & HasRecommendation.
    // 
    // Note: The lifetime of this variable ends when the function scope ends.
}

bool IsHired(const stUserInfo& UserInfo)  //فَرِّق تسُد / Divide & conquor   // Also useful because the returned value can be reused in other functions if needed.

{
    return ((UserInfo.age > 21 && UserInfo.HasDriverLicense) || UserInfo.HasRecommendation);
}

void PrintHiringDecision(const stUserInfo& UserInfo) // passing by constant reference : means the procedure receives a reference to the existing object rather than copying it into a new memory space within the function’s scope.
{
    if (IsHired(UserInfo)) // فَرِّق تسُد  / Divide & conquor  ( why write the code here while you can apply divided & conquer as much as you can ?)
    {
        cout << "Hired  \n";
    }
    else
    {
        cout << "Rejected ! \n";    
    }
}


int main()
{
    
    PrintHiringDecision(ReadUserInput());

 /*
  ReadUserInput() evaluates to a fully initialized object of type stUserInfo
  that contains the values of:
  - UserInfo.age
  - UserInfo.HasDriverLicense
  - UserInfo.HasRecommendation.

  The fully initialized object is then passed directly to PrintHiringDecision().
*/


    return 0;
}

