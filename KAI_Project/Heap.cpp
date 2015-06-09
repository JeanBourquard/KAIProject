#include "Heap.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

Heap::Heap()
{
    m_size = 0;
}

//this function add an element at the end of the heap and then reorganize it according to the value of the nez element
void Heap::addElement(int value)
{
    if (m_size == NULL)
    {
        m_size = 0;
    }
    m_heapElements.push_back(value);
    m_size ++;

    reorganizeHeap();

}

//this function reorganize the heap by looking if the last element is greater than his parent
void Heap::reorganizeHeap()
{
    int tmp;
    int size = m_size - 1;
    int index = (size - 1) / 2;

    while(m_heapElements[index] < m_heapElements[size] && size > 0)
    {
        tmp = m_heapElements.at(size);
        m_heapElements[size] = m_heapElements[index];
        m_heapElements.at(index) = tmp;
        //then after applying the switch, we need to check if the new parent is greater than the value or not
        size = index;
        index = (size - 1) / 2;
    }
}

//this function display the heap
void Heap::displayHeap()
{
    for(int j = 0; j < m_size; ++j)
    {
        cout << m_heapElements.at(j) << " --> ";
    }
    cout << "heap" << endl;
}

//this function fill the heap with the values contained in the indicated file
void Heap::readInFile(std::string filePath)
{
    ifstream myStream(filePath.c_str());

    if(myStream)
    {
        string line;
                while(getline(myStream, line))  // as long as there is content
                {
                    if (line != "heap")
                    {
                        addElement(atoi(line.c_str())); //each line corresponds to an element of the heap so for each line we create a new element and we add it to the list
                        displayHeap(); //then we display the heap
                    }

                }

        myStream.close(); //close the stream used to read the file
    }
    else //if the stream does not work then display an Error message
    {
        cerr << "ERROR: cannot open the file." << endl;
    }
}

//this function write the heap in the indicated file
void Heap::writeInFile(std::string filePath)
{
    ofstream myStream(filePath.c_str()/*, ios::out | ios::app*/);


    if(myStream)
    {
        //if the heap is empty
        if (m_heapElements.at(0) == NULL)
        {
            myStream << "heap" << endl;
        }
        //else go through the heap and write each element in the file
        else
        {
            for(int j = 0; j < m_size; ++j)
            {
                myStream << m_heapElements.at(j) << endl;
            }
            myStream << "heap" << endl;

        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}



