#include "ElementList.h"

ElementList::ElementList()
{

}

void ElementList::setValue(int value)
{
    m_value = value;
}

void ElementList::setNext(ElementList* next)
{
    m_next = next;
}


int ElementList::getValue()
{
    return m_value;
}

ElementList* ElementList::getNext()
{
    return m_next;
}
