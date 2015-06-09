#ifndef HEAP_H
#define HEAP_H
#include "elementheap.h"
#include <string>
#include <vector>

class Heap
{
public:
    Heap();
    void addElement(int value);
    void displayHeap();
    void reorganizeHeap();
    void readInFile(std::string filePath);
    void writeInFile(std::string filePath);

private:
    std::vector<int> m_heapElements;
    int m_size;
};

#endif // HEAP_H
