#include <iostream>
#include "CircularLinkedList.h"

int main(){
    std::cout << "hello world";
    CircularLinkedList<int> c;
    c.insert_back(1);
    c.insert_back(2);
    c.insert_back(3);
    c.insert_back(4);
    c.print();
    return 0;
}