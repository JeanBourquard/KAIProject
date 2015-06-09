#include "ElementHeap.h"

ElementHeap::ElementHeap()
{

}

void ElementHeap::setValue(int value)
{
    m_value = value;
}

void ElementHeap::setParent(ElementHeap *parent)
{
    m_parent = parent;
}

void ElementHeap::setLeftChild(ElementHeap *leftChild)
{
    m_leftChild = leftChild;
}

void ElementHeap::setRightChild(ElementHeap *rightChild)
{
    m_rightChild = rightChild;
}

int ElementHeap::getValue()
{
    return m_value;
}

ElementHeap* ElementHeap::getLeftChild()
{
    return m_leftChild;
}

ElementHeap* ElementHeap::getRightChild()
{
    return m_rightChild;
}

ElementHeap* ElementHeap::getParent()
{
    return m_parent;
}
