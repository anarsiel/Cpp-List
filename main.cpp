#include <iostream>
#include "list.h"

int main() {
    list<int> c;
    list<int>::iterator i = c.end();
    c.push_back(5);
    --i;
    return 0;
}