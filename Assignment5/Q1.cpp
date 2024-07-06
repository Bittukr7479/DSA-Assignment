#include <stdio.h>
#include <iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    int item;
    Node *next;
};
class DLL
{
private:
    Node *start;

public:
    DLL();
    void insertAtStart(int);
    void insertAtLast(int);
    Node *search(int);
    void insertAtAfter(Node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~DLL();
    void printDLL();
};

DLL::DLL()
{
    start = NULL;
}

void DLL::insertAtStart(int data)
{
    Node *r = new Node();
    r->prev = NULL;
    r->item = data;
    r->next = start;
    if (start != NULL)
        start->prev = r;
    start = r;
}

void DLL::insertAtLast(int data)
{
    Node *t;
    Node *n = new Node();
    n->item = data;
    n->next = NULL;
    if (start == NULL)
    {
        n->prev = NULL;
        start = n;
    }
    else
    {
        t = start;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
        n->prev = t;
    }
}

Node* DLL::search(int data)
{
    Node *t;
    t = start;
    while (t)
    {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return NULL;
}

void DLL::insertAtAfter(Node *t, int data)
{
    if (t)
    {
        Node *a = new Node();
        a->item = data;
        a->prev = t;
        a->next = t->next;
        if (t->next)
            t->next->prev = a;
        t->next = a;
    }
}

void DLL::deleteFirst()
{
    if (start)
    {
        if (start->next)
        {
            start = start->next;
            delete start->prev;
            start->prev = NULL;
        }
        else
        {
            delete start;
            start = NULL;
        }
    }
}

void DLL::deleteLast()
{
    Node *t;
    if (start)
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            t = start;
            while (t->next->next != NULL)
                t = t->next;
            delete t->next;
            t->next = NULL;
        }
    }
}

void DLL::deleteNode(int data)
{
    Node *t;
    if (start)
    {
        t = start;
        while (t != NULL && t->item != data)
        {
            t = t->next;
        }
        if (t == NULL)
        {
            return;
        }

        if (t == start)
            deleteFirst();
        else
        {
            if (t->next)
            {
                t->next->prev = t->prev;
                t->prev->next = t->next;
                delete t;
            }
        }
    }
}

DLL::~DLL()
{
    while (start)
        deleteFirst();
}

void DLL::printDLL()
{
    Node *t;
    t = start;
    while (t)
    {
        cout << " " << t->item;
        t = t->next;
    }
}

int main()
{
    DLL d;
    d.insertAtStart(10);
    d.insertAtLast(20);
    d.insertAtAfter(d.search(20), 30);
    d.printDLL();
    cout<<endl;
    return 0;
}