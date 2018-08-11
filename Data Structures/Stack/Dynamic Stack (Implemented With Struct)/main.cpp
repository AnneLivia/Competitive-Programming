#include <iostream>
#include "dynamic_stack.h"

using namespace std;

int main()
{
    Stack* s = create_stack();
    cout << "Size: " << stack_size(s) << endl;
    if(isEmpty(s))
        cout << "It's empty\n";
    else
        cout << "It's not empty\n";

    for(int i = 1; i <= 15; i++)
        push(s,i);

    cout << "Size: " << stack_size(s) << endl;
    if(isEmpty(s))
        cout << "It's empty\n";
    else
        cout << "It's not empty\n";



    while(!isEmpty(s)) {

        cout << "Top: " << get_top(s) << ", size: " << stack_size(s) << endl;
        pop(s);
    }

    cout << "Size: " << stack_size(s) << endl;
    if(isEmpty(s))
        cout << "It's empty\n";
    else
        cout << "It's not empty\n";

    delete_stack(s);

    return 0;
}
