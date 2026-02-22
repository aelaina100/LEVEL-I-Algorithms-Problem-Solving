// problem #9.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
using namespace std;

/*
Problem #9:

 Write a program to ask the user to enter:
 - Number1, Number2, Number3

 Then print the Sum of entered numbers.

 Example Inputs:
 10
 20
 30

 Output:
 60

*/
       

/* Solution:

   Only having:

   #include <iostream>
   using namespace std;

   while using the array fixed-length data structure,
   means that an array can NEVER be returned by a function.
   


*/
const int NumberOfElements = 3;

void ReadNumbers(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference. 
{
    for (int i = 0; i < NumberOfElements; i++)
    {
        cout << "Enter Number " << i + 1 << " : ";
        cin >> numbers[i];
        cout << endl;
    }
}

float SumOfNumbers(float numbers[NumberOfElements])
{
    float sum = 0;
    for (int i = 0; i < NumberOfElements;  i++)
    {
        sum += numbers[i];
    }
    return sum;
}

void PrintSum(float numbers[NumberOfElements]) // ALWAYS passed by ref. Including the & symbol will render an exception.
{
    cout << "The entered numbers: "; 
    for (int i = 0; i < NumberOfElements; i++)
    {
        cout << numbers[i] << "  "; 
    }
    cout << endl;
    cout << "Have the sum of " << SumOfNumbers(numbers) << endl;
}

int main()
{
    float numbers[NumberOfElements];
    // initializing the array variable via reading user-input:

    ReadNumbers(numbers);// passing the array variable as an argument. It's passed along with its memory address. hence, it is always passed by reference in the implementing
                         // function. Including & will render an exception.
     // The array variable 'numbers' is now fully initialized.

    PrintSum(numbers);    


   // PrintSum(CalculateSum(numbers)); // also valid. BUT- the printing procedure will not have access to the three numbers entered by the user.
                                           // Hence, referencing them in main will require adding additional lines of code in main = unoptimized approach. 

    return 0;
}


