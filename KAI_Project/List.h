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
    void readInFile(std::string filePath);
    void createListFromFile(std::string fileLine);

private:
        ElementList* first;
        std::string data;
        //ElementList* last;
};

#endif // LIST_H
