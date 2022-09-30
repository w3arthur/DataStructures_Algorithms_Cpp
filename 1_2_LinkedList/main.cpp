

#include <iostream>
#include "LinkedList.cpp"
using  std::cout, std::endl;
int main()
{
    cout << "LinkedList" << endl;
    List list{};
    list.insertLast(10);
    cout << "after10";
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);
    list.insertLast(50);
    list.insertLast(60);
    list.insertLast(70);
    list.insertLast(80);
    list.insertLast(90);
    list.insertLast(100);

    cout << endl << "end" << endl;


    //list.removeFirst();
    //list.removeLast();

    cout << "KTH " <<list.kth(3) << endl;
    cout << list.print();
    list.reverse();
    cout << list.print();

    return EXIT_SUCCESS;
}
