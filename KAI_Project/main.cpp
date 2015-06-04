#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <stdlib.h>     //srand, rand
#include <time.h>       //time
#include "List.h"
#include <set>

using namespace std;

void listChoice()
{
    //create a new list
    List list;

    for(int i = 0; i < 7; i++)
    {
        //add elements to the list with random values
        list.addElement(rand() % 500 + 1);
        //display the list
        list.displayList();
    }
    list.writeInFile("C:/Users/K/Documents/GitHub/KAIProject/KAI_Project/test.txt");
}

void vectorChoice()
{
    //create a new vector
    vector<int> vect;

    for(int i = 0; i < 7; i++)
    {
        //add elements to the vector with random values
        vect.push_back(rand() % 500 + 1);
        //display the vector
        for(std::size_t j=0;j<vect.size();++j)
        {
            cout << vect[j] << " --> ";
        }
        cout << "vector" << endl;
    }
}

void setChoice()
{
    //create a new set
    set<int> setOfValue;

    for(int i = 0; i < 7; i++)
    {
        setOfValue.insert(rand() % 500 + 1);

        std::set<int>::const_iterator setOfValueIt (setOfValue.begin()), setOfValueEnd(setOfValue.end());
          for(;setOfValueIt!=setOfValueEnd;++setOfValueIt)
          {
              cout << *setOfValueIt << " --> ";
          }
          cout << "set" << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // initialize random seed
    srand (time(NULL));
    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "what kind of data structure do you want to create ? " << endl << "1. linked list" << endl << "2. vector" << endl << "3. set" << endl << "4. exit" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            listChoice();
        }
        if (choice == 2)
        {
            vectorChoice();
        }
        if (choice == 3)
        {
            setChoice();
        }
        cout << endl;
    } while (choice != 4);

      return a.exit(0);

}


