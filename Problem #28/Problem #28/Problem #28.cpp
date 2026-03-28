
#include <iostream>
using namespace std;

/*
 Problem #28:
 Write a program to sum odd numbers from 1 to N.

 Input
 10

 Outputs →
 25

*/


//int ReadNumber()
//{
//	int number; // what's returned
//
//	cout << "Enter a positive integer: ";
//	cin >> number;
//	cout << endl;
//
//	return number;
//}
//
//bool ValidatePositiveInteger(int number) // passing by value.
//{
//	return (number > 0);
//}
//
//int ReadPositiveInteger()
//{
//	int number;   // what's returned.
//	do
//	{
//		number = ReadNumber(); // to be IMMEDIATELY validated in the while condition against the range.
//
//	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence the !)
//
//	return number;
//}
//
//// the best and cleanest approach:
//int CalculateSumOfOddNumbers(int number) // passing by value.
//{
//	int sum = 0;
//
//	for (int i = 1; i <= number; i += 2)   
//	{
//		sum = sum + i;
//	}
//	return sum;
//}
//
////int CalculateSumOfOddNumbers(int number) // passing by value.
////{
////	int sum = 0;
////	
////	int i = 1;            // 1st step to write.
////	while (i <= number)   // 2nd step to write.
////	{
////		sum = sum + i;   // LAST step 
////		i += 2;         // 3rd step.
////	}
////	
////	return sum;
////}
//
////int CalculateSumOfOddNumbers(int number) // passing by value.
////{
////	int sum = 0;
////	
////	int i = 1;
////	do
////	{
////		sum = sum + i;
////		i += 2;
////
////	} while (i <= number);
////
////	return sum;
////}
//
//void PrintSumOfOddNumbers(const int &sum) // passing by constant reference.
//{
//	cout << "The sum of the odd numbers is: " << sum << endl;
//}

//int main()
//{
//   
//	PrintSumOfOddNumbers(CalculateSumOfOddNumbers(ReadPositiveInteger()));
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// again: The cleanest and the most optimized approach is utilizing the for-loops:


// Below- A solution showcasing the utilization of the 3 loops types: The for-loops, the while-loop, & the do..while() loop
// BAD FORMATTING- IMPROVE IT.


int ReadNumber()
{
	int number; // what's returned

	cout << "Enter a positive integer: ";
	cin >> number;
	cout << endl;

	return number;
}

bool ValidatePositiveInteger(int number) // passing by value.
{
	return (number > 0);
}

int ReadPositiveInteger()
{
	int number;   // what's returned.
	do
	{
		number = ReadNumber(); // to be IMMEDIATELY validated in the while condition against the range.

	} while (!ValidatePositiveInteger(number)); // the argument is written so that it evaluates to TRUE when the condition is invalid (hence the !)

	return number;
}

// the best and cleanest approach:
int CalculateSumOfOddNumbers_UsingForLoops(int N) // passing by value.
{
	cout << "Solving via For-Loops: \n";


	int sum = 0;

	for (int i = 1; i <= N; i += 2)
	{
		sum = sum + i;
	}
	return sum;

}

int CalculateSumOfOddNumbers_UsingWhileLoop(int N) // passing by value.
{
	cout << "Solving via While-Loops: \n";


	int sum = 0;
	
	int i = 1;            // 1st step to write.
	while (i <= N)   // 2nd step to write.
	{
		sum = sum + i;   // LAST step 
		i += 2;         // 3rd step.
	}
	
	return sum;

}

int CalculateSumOfOddNumbers_UsingDoWhileLoop(int N) // passing by value.
{
	cout << "Solving via Do..While loop: \n";


	int sum = 0;
	
	int i = 1;
	do
	{
		sum = sum + i;
		i += 2;

	} while (i <= N);

	return sum;

}

void PrintSumOfOddNumbers(const int& sum) // passing by constant reference.
{
	cout << " \nThe sum of the odd numbers is: " << sum << endl;
}

int main()
{

	int N = ReadPositiveInteger();

	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingForLoops(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingWhileLoop(N));
	PrintSumOfOddNumbers(CalculateSumOfOddNumbers_UsingDoWhileLoop(N));
	
	

	return 0;
}






//// the NON-optimized solution that iterates over ALL numbers (discouraged)
//int CalculateSumOfOddNumbers(int number) // passing by value.
//{
//	int sum = 0;
//
//	for (int i = 1; i <= number; i++)   // the optimized solution instead of utilizing the remainder where i increments by 1.
//	{
//		if (i % 2 != 0)
//		{
//			sum = sum + i;
//		}
//	}
//	return sum;
//}
