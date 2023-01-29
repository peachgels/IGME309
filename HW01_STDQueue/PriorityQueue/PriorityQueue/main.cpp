#include <iostream>
#include "queue.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

void wrapper()
{
    MyQueue<int> queue;

    //isEmpty is used in the pop method, but just to be safe
    cout << queue.IsEmpty();
    cout << endl;

    //pushing some unsorted ints
    queue.Push(59);
    queue.Push(4);
    queue.Push(27);
    queue.Push(3);
    queue.Push(16);
    //print it out using Print(), demonstrating the sort
    queue.Print();
    cout << endl;

    //showing size of the queue
    cout << queue.GetSize();
    cout << endl;

    //popping some elements from it
    queue.Pop();
    queue.Pop();

    //print and get size again, showing bottom two elements were removed
    queue.Print();
    cout << endl;

    //showing size of the queue
    cout << queue.GetSize();
    cout << endl;

    //showing the queue now has data
    cout << queue.IsEmpty();
    cout << endl;

}

int main() {
    wrapper();
}
