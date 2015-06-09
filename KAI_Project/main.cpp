#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <stdlib.h>     //srand, rand
#include <time.h>       //time
#include "List.h"
#include "Heap.h"
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void listChoice()
{

    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new list or load it from a file ?" << endl << "1. create new list" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        //create a new list
        List list;
        if (choice == 1)
        {
            for(int i = 0; i < 7; i++)
            {
                //add elements to the list with random values
                list.addElement(rand() % 500 + 1);
                //display the list
                list.displayList();
            }
            list.writeInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/List.txt");
        }
        if (choice == 2)
        {
            list.readInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/List.txt");
        }
    }while (choice != 1 && choice != 2);
}

void readVectorInFile(string filePath)
{
    ifstream myStream(filePath.c_str());
    //create a new vector
    vector<int> vect;

    if(myStream)
    {
        string line;


                while(getline(myStream, line))  // as long as there is content
                {
                    if (line != "vector")
                    {
                        vect.push_back(atoi(line.c_str()));//add a new element in the vector for each line of the file except for the last one

                        for(std::size_t j=0;j<vect.size();++j) //then display the vector
                        {
                            cout << vect[j] << " --> ";
                        }
                        cout << "vector" << endl;
                    }
                }

        myStream.close();
    }
    else
    {
        cerr << "ERROR: cannot open the file." << endl;
    }
}

void writeVectorInFile(string filePath, vector<int> myVector)
{
    ofstream myStream(filePath.c_str()/*, ios::out | ios::app*/);


    if(myStream)
    {
        //if the vector is empty
        if (myVector[0] == NULL)
        {
            myStream << "vector" << endl;
        }
        //else go through the vector and write each element in the file
        else
        {
            for(std::size_t j=0;j<myVector.size();++j)
            {
                myStream << myVector[j] << endl;
            }

            myStream << "vector" << endl;
        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}

void vectorChoice()
{

    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new vector or load it from a file ?" << endl << "1. create new vector" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        //create a new vector
        if (choice == 1)
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
            //write vector in file
            writeVectorInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Vector.txt", vect);
        }
        if (choice == 2)
        {
            //read vector from a file
            readVectorInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Vector.txt");
        }
    }while (choice != 1 && choice != 2);
}

void writeSetInFile(string filePath, set<int> mySet)
{
    ofstream myStream(filePath.c_str()/*, ios::out | ios::app*/);


    if(myStream)
    {
        //if the set is empty
        if (*mySet.begin() == NULL)
        {
            myStream << "set" << endl;
        }
        //else go through the set and write each element in the file
        else
        {
            std::set<int>::const_iterator mySetIt (mySet.begin()), mySetEnd(mySet.end());
            for(;mySetIt!=mySetEnd;++mySetIt)
            {
              myStream << *mySetIt << endl;
            }
            myStream << "set" << endl;
        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}

void readSetFromFile(string filePath)
{
    ifstream myStream(filePath.c_str());
    //create a new set
    set<int> mySet;

    if(myStream)
    {
        string line;

        while(getline(myStream, line))  // as long as there is content
        {
            if (line != "set")
            {
                mySet.insert(atoi(line.c_str()));//add a new element in the set for each line of the file except for the last one

                std::set<int>::const_iterator mySetIt (mySet.begin()), mySetEnd(mySet.end());
                for(;mySetIt!=mySetEnd;++mySetIt)
                {
                  cout << *mySetIt << " --> ";
                }
                cout << "set" << endl;
            }
        }

        myStream.close();
    }
    else
    {
        cerr << "ERROR: cannot open the file." << endl;
    }
}

void setChoice()
{
    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new set or load it from a file ?" << endl << "1. create new set" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1)
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
            //write set in file
            writeSetInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Set.txt", setOfValue);
        }
        if (choice == 2)
        {
            //read set from a file
            readSetFromFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Set.txt");
        }
    }while (choice != 1 && choice != 2);
}

void heapChoice()
{
    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new heap or load it from a file ?" << endl << "1. create new heap" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        //create a new heap
        Heap heap;
        if (choice == 1)
        {
            for(int i = 0; i < 7; i++)
            {
                //add elements to the heap with random values
                heap.addElement(rand() % 500 + 1);
                heap.displayHeap();//display the heap

            }
            heap.writeInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Heap.txt");
        }
        if (choice == 2)
        {
            heap.readInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Heap.txt");
        }
    }while (choice != 1 && choice != 2);

}

void writeQueueInFile(string filePath, std::queue<int> myQueue)
{
    ofstream myStream(filePath.c_str()/*, ios::out | ios::app*/);


    if(myStream)
    {
        //if the set is empty
        if (myQueue.empty())
        {
            myStream << "queue" << endl;
        }
        //else go through the queue and write each element in the file
        else
        {
            //display the queue at the same time because it will be destroyed as we copy it in the file
            while (!myQueue.empty())
            {
                myStream << myQueue.front() << endl;
                cout <<  myQueue.front() << " --> ";
                myQueue.pop();

            }
            myStream << "queue" << endl;
            cout << "queue" << endl;

        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}

void readQueueFromFile(string filePath)
{
    ifstream myStream(filePath.c_str());
    //create a new set
    queue<int> myQueue;

    if(myStream)
    {
        string line;

        while(getline(myStream, line))  // as long as there is content
        {
            if (line != "queue")
            {
                myQueue.push(atoi(line.c_str()));//add a new element in the queue for each line of the file except for the last one

//                std::set<int>::const_iterator mySetIt (mySet.begin()), mySetEnd(mySet.end());
//                for(;mySetIt!=mySetEnd;++mySetIt)
//                {
//                  cout << *mySetIt << " --> ";
//                }
//                cout << "set" << endl;
            }
        }
        while (!myQueue.empty())
        {
            cout <<  myQueue.front() << " --> ";
            myQueue.pop();

        }
        cout << "queue" << endl;

        myStream.close();
    }
    else
    {
        cerr << "ERROR: cannot open the file." << endl;
    }
}

void queueChoice()
{
    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new queue or load it from a file ?" << endl << "1. create new queue" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            //create a new queue
            std::queue<int> myQueue;

            for(int i = 0; i < 7; i++)
            {
                myQueue.push(rand() % 500 + 1);
            }

            //write queue in file
            writeQueueInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Queue.txt", myQueue);

        }
        if (choice == 2)
        {
            //read queue from a file
            readQueueFromFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Queue.txt");
        }
    }while (choice != 1 && choice != 2);

}

void writeMapInFile(string filePath, std::map<int, int> myMap)
{
    ofstream myStream(filePath.c_str());


    if(myStream)
    {
        //if the map is empty
        if (myMap[0] == NULL)
        {
            myStream << "map" << endl;
        }
        //else go through the map and write each element in the file
        else
        {
            for(int j = 0; j < myMap.size(); j++)
            {
                myStream << myMap[j] << endl;
            }
            myStream << "map" << endl;

        }
        myStream.close();
    }
    else
    {
        cout << "ERROR: cannot open the file." << endl;
    }
}

void readMapInFile(string filePath)
{
    ifstream myStream(filePath.c_str());
    //create a new map
    map<int, int> myMap;

    if(myStream)
    {
        string line;
        int index = 0;

                while(getline(myStream, line))  // as long as there is content
                {
                    if (line != "map")
                    {
                        myMap[index] = atoi(line.c_str());//add a new element in the map for each line of the file except for the last one
//                        vect.push_back(atoi(line.c_str()));//add a new element in the vector for each line of the file except for the last one

                    }

                    for(int j = 0; j < myMap.size(); j++)//then display the map
                    {
                        cout << myMap[j] << " --> ";
                    }
                    cout << "map" << endl;

                    index++;
                }



        myStream.close();
    }
    else
    {
        cerr << "ERROR: cannot open the file." << endl;
    }
}

void mapChoice()
{

    int choice;
    do
    {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Do you want to create a new map or load it from a file ?" << endl << "1. create new map" << endl << "2. load from file" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            //create a new map
            std::map<int, int> myMap;

            for(int i = 0; i < 7; i++)
            {
                myMap[i] = rand() % 500 + 1;

                for(int j = 0; j < myMap.size(); j++)
                {
                    cout << myMap[j] << " --> ";
                }
                cout << "map" << endl;
            }

            //write map in file
            writeMapInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Map.txt", myMap);
        }
        if (choice == 2)
        {
            //read map from a file
            readMapInFile("C:/Users/Jean/Documents/GitHub/KAIProject/KAI_Project/Map.txt");
        }
    }while (choice != 1 && choice != 2);

//    std::map<int, int> myMap;

//    for(int i = 0; i < 7; i++)
//    {
//        myMap[i] = rand() % 500 + 1;
//    }

//    for(int j = 0; j < myMap.size(); j++)
//    {
//        cout << myMap[j] << " --> ";
//    }
//    cout << "map" << endl;

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
        cout << "what kind of data structure do you want to create ? " << endl << "1. linked list" << endl << "2. vector" << endl << "3. set" << endl << "4. heap" << endl << "5. queue" << endl << "6. map" << endl << "7. exit" << endl;
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
        if (choice == 4)
        {
            heapChoice();
        }
        if (choice == 5)
        {
            queueChoice();
        }
        if (choice == 6)
        {
            mapChoice();
        }
        cout << endl;
    } while (choice != 7);

      //return a.exit(0);

}


