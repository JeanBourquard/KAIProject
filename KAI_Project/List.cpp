#include "List.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>


using namespace std;

List::List()
{
    first = NULL;
    //last = NULL;
}

void List::addElement(int value)
{
    //create the new element to add to the list
    ElementList *newElement = new ElementList();
    newElement->setValue(value);
    newElement->setNext(NULL);

    //if the list is not empty we add the new element at the end of the list
    if (first != NULL)
    {
        ElementList *tmp = first;
        while (tmp->getNext() != NULL)
        {
            tmp = tmp->getNext();
        }
        tmp->setNext(newElement);
//        last = newElement;
    }
    //if the list is empty we set the new element as the first and last element of the list
    else
    {
        first = newElement;
//        last = newElement;
    }
}

void List::displayList()
{
    ElementList *tmp = first;

    //if the list is empty
    if (tmp == NULL)
    {
        cout << "the list is empty" << endl;
    }
    //else go through the list and display each element
    else
    {
        do
        {
            cout << tmp->getValue() << " --> ";
            tmp = tmp->getNext();
        } while (tmp != NULL);

        cout << "list" << endl;
    }
}

void List::writeInFile(string filePath)
{
    ofstream myStream(filePath.c_str()/*, ios::out | ios::app*/);


    if(myStream)
    {
        ElementList *tmp = first;

        //if the list is empty
        if (tmp == NULL)
        {
            myStream << "list" << endl;
        }
        //else go through the list and write each element in the file
        else
        {
            do
            {
                myStream << tmp->getValue() << endl;
                tmp = tmp->getNext();
            } while (tmp != NULL);

            myStream << "list" << endl;
        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}

void List::readInFile(string filePath)
{
    ifstream myStream(filePath.c_str());

    if(myStream)
    {
        //int i=0;
        string line;
                while(getline(myStream, line))  // as long as there is content
                {
                    if (line != "list")
                    {
                        addElement(atoi(line.c_str())); //each line corresponds to an element of the list so for each line we create a new element and we add it to the list
                        displayList(); //then we display the list
                    }

                }

        myStream.close(); //close the stream used to read the file
    }
    else //if the stream does not work then display an Error message
    {
        cerr << "ERROR: cannot open the file." << endl;
    }

}
