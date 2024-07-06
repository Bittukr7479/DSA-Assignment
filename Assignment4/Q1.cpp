#include <stdio.h>
#include <iostream>
using namespace std;
#define ERROR 1;
class Node
{
public:
    int item;
    Node *next;
};
class SLL
{
private:
    Node *start;

public:
    SLL();
    void insertAtStart(int);
    void insertAtLast(int);
    Node *search(int);
    void insertAfter(Node *, int);
    void deletFirst();
    void deleteLast();
    void deleteNode(int);
    ~SLL();
};

SLL::SLL()
{
    start = NULL;
}

void SLL::insertAtStart(int data)
{
    Node *n = new Node();
    n->item = data;
    n->next = start;
    start = n;
}

void SLL::insertAtLast(int data)
{
    Node *t;
    Node *n = new Node();
    n->item = data;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        t = start;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

Node *SLL::search(int data)
{
    Node *t;
    t = start;
    while (t)
    {
        if (t->item = data)
            return t;
        t = t->next;
    }
    return NULL;
}

void SLL::insertAfter(Node *temp, int data)
{
    Node *n = new Node();
    if (temp)
    {
        Node *temp;
        n->item = data;
        n->next = temp->next;
        temp->next = n;
    }
}

void SLL::deletFirst()
{
    Node *r;
    if (start)
    {
        r = start;
        start = start->next;
        delete r;
    }
}

void SLL::deleteLast()
{
    Node *temp;
    if (start)
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            temp = start;
            while (start->next->next = NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}

void SLL::deleteNode(int data)
{
    Node *t1;
    Node *t2;
    if (start)
    {
        t1 = start;
        t2 = NULL;
        while (t1)
        {
            if (t1->item == data)
                break;
            t2 = t1;
            t1 = t1->next;
        }
        if (t1)
        {
            if (t2==NULL)
            {
                start = t1->next;
                delete t1;
            }
            else
            {
                t2->next = t1->next;
                delete t1;
            }
        }
    }
}

SLL::~SLL()
{
    while (start)
    {
        deletFirst();
    }
}

int main()
{
    return 0;
}
