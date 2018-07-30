#include <iostream>
#include "dynamic_queue.h"

using namespace std;

int main()
{
    Queue *q = create_queue();

    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    for ( int i = 1; i <= 10; i++) {
        push(q,i);
    }

    cout << "Queue size: " << size_queue(q) << endl;
    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";

    while(!isEmpty(q)) {
        cout << "Front: " << get_front(q) << ", size: " << size_queue(q) << endl;
        pop(q);
    }

    cout << "Queue size: " << size_queue(q) << endl;
    if(isEmpty(q))
        cout << "The queue is empty\n";
    else
        cout << "The queue is not empty\n";


    delete_queue(q);
    return 0;
}
