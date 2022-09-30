
#include <iostream>
#include <stack>
#include "LinearSearch.cpp"
#include "BinarySearch.cpp"
#include "TernarySearch.cpp"
#include "JumpSearch.cpp"
#include "ExponentialSearch.cpp"
using std::string, std::cout, std::endl;

static string print(int&& result) { return (result >= 0 ? to_string(result + 1 ) + " true" : to_string(result) + " false"); }

int main()
{
    int target = 4;
    int arrayLength = 7;
    int* array = new int[arrayLength] { 7, 3, 1, 4, 6, 2, 3};
    int* arraySorted = new int[arrayLength] { 1, 2, 3, 3, 4, 6, 7};

    cout <<"Linear Search: " << print( linearSearch(array, arrayLength, target) ) << endl;

    //using sorted array !

    cout <<"Binary Search: " << print( binarySearch(arraySorted, arrayLength, target) ) << endl;
    cout <<"Binary Search Recursion: " << print( binarySearch_Recursion(arraySorted, arrayLength, target) ) << endl;

    cout <<"Ternary Search: " << print(ternarySearch(arraySorted, arrayLength, target) ) << endl;

    cout <<"Jump Search: " << print(jumpSearch(arraySorted, arrayLength, target) ) << endl;

    cout <<"Exponential Search: " << print(exponentialSearch(arraySorted, arrayLength, target) ) << endl;


    delete[](array);
    delete[](arraySorted);
    return EXIT_SUCCESS;
}
