#include <iostream>
#include "static_stack.h"

// FILO - First in Last out

using namespace std;

int main()
{
    Stack* s = create_stack(10);
    for ( int i = 1; i <= 9; i++) {
        push(s,i);
    }

    cout << "Stack Size: " << stack_size(s) << endl;
    if(isFull(s))
        cout << "It's full\n";
    else
        cout << "It's not full\n";

    while(!isEmpty(s)) {
        cout << "Value at the top: " << get_top(s) << ", Size: " << stack_size(s) << endl;
        pop(s);
    }

    cout << "\n\nStack size: " << stack_size(s) << "\n\n";

    if(isEmpty(s))
        cout << "It's empty\n";
    else
        cout << "It's not empty\n";

    delete_stack(s);
    return 0;
}
