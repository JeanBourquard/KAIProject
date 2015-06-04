#ifndef LIST_H
#define LIST_H
#include "ElementList.h"
#include <string>

class List
{
public:
    List();
    void addElement(int value);
    void displayList();
    void writeInFile(std::string filePath);

private:
        ElementList* first;
        //ElementList* last;
};

#endif // LIST_H
