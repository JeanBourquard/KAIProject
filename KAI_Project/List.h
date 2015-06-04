#ifndef LIST_H
#define LIST_H
#include "ElementList.h"
#include <iostream>

class List
{
public:
    List();
    void addElement(int value);
    void displayList();

private:
        ElementList* first;
        ElementList* last;
};

#endif // LIST_H
