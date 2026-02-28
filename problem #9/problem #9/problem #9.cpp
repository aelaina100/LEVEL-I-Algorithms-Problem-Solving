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
//const int NumberOfElements = 3; // as we progressed in this program, this line has proven the need to render it global.
//
//void ReadNumbers(float numbers[NumberOfElements]) // arrays are ALWAYS passed by reference. 
//{
//    for (int i = 0; i < NumberOfElements; i++)
//    {
//        cout << "Enter Number " << i + 1 << " : ";
//        cin >> numbers[i];
//        cout << endl;
//    }
//}
//
//float SumOfNumbers(float numbers[NumberOfElements])
//{
//    float sum = 0;
//    for (int i = 0; i < NumberOfElements;  i++)
//    {
//        sum += numbers[i];
//    }
//    return sum;
//}
//
//void PrintSum(float numbers[NumberOfElements]) // ALWAYS passed by ref. Including the & symbol will render an exception.
//{
//    cout << "The entered numbers: "; 
//    for (int i = 0; i < NumberOfElements; i++)
//    {
//        cout << numbers[i] << "  "; 
//    }
//    cout << endl;
//    cout << "Have the sum of " << SumOfNumbers(numbers) << endl;
//}
//
//int main()
//{
//    float numbers[NumberOfElements];
//    // initializing the array variable via reading user-input:
//
//    ReadNumbers(numbers);// passing the array variable as an argument. It's passed along with its memory address. hence, it is always passed by reference in the implementing
//                         // function. Including & will render an exception.
//     // The array variable 'numbers' is now fully initialized.
//
//    PrintSum(numbers);    
//
//
//   // PrintSum(CalculateSum(numbers)); // also valid. BUT- the printing procedure will not have access to the three numbers entered by the user.
//                                           // Hence, referencing them in the printing procedure will require adding additional lines of code in main = unoptimized approach. 
//    return 0;
//}





/* Primitive solutions 3 variables instead of an array:
 
*/


void ReadNumbers(float& Num1, float& Num2, float& Num3) // Passing by reference. So that the variables declared in main are initialized so that we continue
                                                        // writing our code in main(). Otherwise, we have to continue coding inside this procedure which
                                                        // violates the SRP.
{
    cout << "Enter First Number: ";
    cin >> Num1;
    cout << endl;

    cout << "Enter Second Number: ";
    cin >> Num2;
    cout << endl;

    cout << "Enter Third Number: ";
    cin >> Num3;
    cout << endl;
}

float CalculateSum(float Num1, float Num2, float Num3) // passing by value.
{
    return (Num1 + Num2 + Num3);
}

void PrintResult(const float& Num1, const float& Num2, const float& Num3)
{
    cout << "The sum of the numbers: " << Num1 << " & " << Num2 << " & " << Num3 << " = " << CalculateSum(Num1, Num2, Num3) << endl;
}

int main()
{
    // Three variables are to declare and initialize via reading user input- 
    // This can only be done utilizing a procedure that will have 3 cin statements. A function can only return ONE value.
    float Num1, Num2, Num3;
    // Initializing these variables via reading user input:

    ReadNumbers(Num1, Num2, Num3);
    // the variables Num1, Num2, & Num3 are now initialized.

    // Now:
    /*
    
    PrintResult(CalculateSum(Num1, Num2, Num3)); // works but the printing proced. won't have reference to Num1, Num2, & Num3 (Ex: the sum of Num1, Numb2,.. is =) wont be possible.
    //unless you state:
    PrintResult(CalculateSum(Num1, Num2, Num3),  Num1, Num2, Num3); // works ! BUT- don't you think it looks hard to read? 

    */

    // so instead, try:
    PrintResult(Num1, Num2, Num3);

    return 0;







    /* Any of the following is NOT going to work because ReadNumbers can only be a procedure that initialized 3 numbers.If it was to initialize one number only
    / then that one number is to be returned using a function instead.


    PrintSum(CalculateSum(ReadNumbers())); 
    PrintSum(ReadNumber());
    */

   







    /* 
     

      // I must correct the below notes that somehow assumes that the nested ReadNumbers procedure is somehow a function.

     PrintSum(CalculateSum(ReadNumbers(num1, num2, num3)));   // Works but the printing procedure will not have access to the 3 variables entered by user
                                                              // Hence, referencing these 3 variables in the printing procedure is not possible unless we
                                                               // add more lines of code in main which results in an unoptimized approach to solving this problem.
     //where we would have:

     float Num1, Num2, Num3;

     ReadNumbers(Num1, Num2, Num3);
        // Num1, Num2, & Num3 are now fully initialized.

     PrintSum(CalculateSum(Num1, Num2, Num3), Num1, Num2, Num3)
    */

}