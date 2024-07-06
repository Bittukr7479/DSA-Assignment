#include <stdio.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int item;
    Node *next;
};
class CLL
{
private:
    Node *last;

public:
    CLL();
    void insertAtStart(int);
    void insertAtLast(int);
    Node *search(int);
    void insertAtAfter(Node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);

    ~CLL();
};

CLL::CLL()
{
    last = NULL;
}

void CLL::insertAtStart(int data)
{
    Node *n;
    if (last != NULL)
        last->next->next = n->next;
    last->next = n;
}

void CLL::insertAtLast(int data)
{
    Node *n;
    if (last != NULL)
    {
        last->next = n->next;
        n->next = last->next;
    }
    n = last;
}

Node *CLL::search(int data)
{
    Node *t;
    t = last;
    if (last)
    {
        while (t)
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        }
    }
}

void CLL::insertAtAfter(Node *t, int data)
{
    Node *n = new Node;
    n->item = data;
    if (last)
    {
        last->next = n;
        last->next->next = n->next;
    }
    else
    {
        last->next = n;
    }
}

void CLL::deleteFirst()
{
    Node *n;
    if (last)
    {
        n = last->next;
        last->next = last->next->next;
        delete n;
    }
}

void CLL::deleteLast()
{
    Node *n;
    if (last)
    {
        n = last;
        last = last->next;
        delete n;
    }
}

void CLL::deleteNode(int data)
{
    Node *t1;
    Node *t2;
    if (last)
    {
        t1 = last;
        t2 = NULL;
        while (t1 != NULL && t1->item != data)
        {
            t2 = t1;
            t1 = t1->next;
        }
        if (t2 = NULL)
        {
            last->next = t1;
            delete t1;
        }
        else
        {
            t2->next = t1->next;
            delete t1;
        }
    }
}

CLL::~CLL()
{
    while (last)
    {
        deleteFirst();
    }
    
}

int main()
{
}