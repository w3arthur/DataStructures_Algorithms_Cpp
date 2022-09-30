
#include <iostream>
#include "Array1.cpp"
#include "Array2.cpp"
#include "Array3.cpp"
#include <array>
using std::cout, std::boolalpha, std::endl, std::array;
int main()
{
    cout << "Array1" << endl;
    Array1 array1{ 5 };
    array1.add(5);
    array1.add(2);
    array1.add(1);
    array1.add(3);
    array1.add(7);
    array1.add(3);
    array1.add(7);

    cout << boolalpha << array1.contains(5) << endl;
    array1.print();
    array1.remove(2);
    array1.print();
    cout << endl;


    cout << "Array2" << endl;
    Array2<int> array2{ 5 };
    array2.add(5);
    array2.add(2);
    array2.add(1);
    array2.add(3);
    array2.add(7);
    array2.add(3);
    array2.add(7);

    cout << boolalpha << array2.contains(5) << endl;
    array2.print();
    array2.remove(2);
    array2.print();
    cout << endl;

    std::array<int, 5> array{};
    //for (int i = 0; i < array.size(); ++i) {
    //	cout << array[i] << endl;
    //}
    Array3<int, 5> array3;

//    memset(array3.Data() /*&array3[0]*/, 0, array3.Size() * sizeof(int));

    array3[2] = 5;
    array3[4] = 8;

    for (size_t i = 0; i < array3.Size(); ++i)
    {
        //array3[i] = 2;
        //arr[i] = 2;
        cout << array3[i] << endl;
    }

    //for(auto& a : array3 ) finish Iterator

    return EXIT_SUCCESS;
}
