#ifndef ELEMENTHEAP_H
#define ELEMENTHEAP_H

class ElementHeap
{
public:
    ElementHeap();
    void setValue(int value);
    void setParent(ElementHeap *parent);
    void setLeftChild(ElementHeap *leftChild);
    void setRightChild(ElementHeap *rightChild);
    int getValue();
    ElementHeap* getLeftChild();
    ElementHeap* getRightChild();
    ElementHeap* getParent();

private:
    ElementHeap *m_parent;
    ElementHeap *m_leftChild;
    ElementHeap *m_rightChild;
    int m_value;

};

#endif // ELEMENTHEAP_H
