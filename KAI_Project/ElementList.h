#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H


class ElementList
{
public:
    ElementList();
    void setValue(int value);
    void setNext(ElementList* next);
    int getValue();
    ElementList* getNext();

private:
    int m_value; //value of the data
    ElementList *m_next;	//pointer on next element

};

#endif // ELEMENTLIST_H
