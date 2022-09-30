
#include <iostream>
#include <queue>
#include <stack>
#include "QueueArray.cpp"
#include "QueueStack.cpp"
using std::cout, std::endl, std::queue, std::stack;
static void reverse(std::queue<int> &queue);
int main()
{
    QueueArray queue{};
    queue.enqueue(10);
    cout << queue.dequeue() << endl;
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);
    queue.enqueue(90);
    queue.enqueue(100);
    queue.enqueue(110);
    queue.enqueue(120);
    queue.enqueue(120);
    queue.enqueue(130);
    queue.enqueue(140);
    queue.enqueue(150);
    queue.enqueue(160);

    cout << "QueueArray: " << queue.print() << endl;


    QueueStack queue2{};
    queue2.enqueue(10);
    cout << queue2.dequeue() << endl;
    queue2.enqueue(20);
    queue2.enqueue(30);
    queue2.enqueue(40);
    queue2.enqueue(50);
    queue2.enqueue(60);
    queue2.enqueue(70);
    queue2.enqueue(80);
    queue2.enqueue(90);
    queue2.enqueue(100);
    queue2.enqueue(110);
    queue2.enqueue(120);
    queue2.enqueue(120);
    queue2.enqueue(130);
    queue2.enqueue(140);
    queue2.enqueue(150);
    queue2.enqueue(160);
    //cout << queue2.dequeue() << "\n";
    cout << "QueueStack: " << queue2.print() << endl << endl << endl << endl << endl;


    std::queue<int> queueCpp{};
    queueCpp.push(10);
    queueCpp.push(20);
    queueCpp.push(30);
    queueCpp.push(40);

    reverse(queueCpp);
    //print
    while(!queueCpp.empty())  { cout << queueCpp.front() << " "; queueCpp.pop(); }


    return EXIT_SUCCESS;
}

static void reverse(std::queue<int> &queue)
{
    std::stack<int> stack{};
    while (!queue.empty()) {stack.push(queue.front()); queue.pop();}
    while (!stack.empty()) {queue.push(stack.top()); stack.pop();}
}