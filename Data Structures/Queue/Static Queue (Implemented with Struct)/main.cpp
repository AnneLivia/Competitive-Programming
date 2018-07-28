#include <iostream>
#include "static_queue.h"

using namespace std;

int main()
{
    Queue *q = create_queue(10);
    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    cout << "Size: " << size_queue(q) << endl;
    for ( int i = 1; i <= 10; i++) {
        push(q,i);
    }

    cout << "Size: " << size_queue(q) << endl;
    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    if(isFull(q))
        cout << "The queue is full\n";
    else
        cout << "The queue is not full\n";

    while(!isEmpty(q)) {
        cout << "Front: " << get_front(q) << ", size: " << size_queue(q) << endl;
        pop(q);
    }

    cout << "Size: " << size_queue(q) << endl;
    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    delete_queue(q);
    return 0;
}
