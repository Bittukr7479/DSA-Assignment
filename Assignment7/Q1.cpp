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
class CDLL
{
private:
    Node *start;

public:
    CDLL();
    void insertAtStart(int);
    void insertAtLast(int);
    Node *search(int);
    void insertAtAfter(Node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~CDLL();
    void printCLL();
};

CDLL::CDLL()
{
    start = NULL;
}

void CDLL::insertAtStart(int data)
{
    Node *n = new Node();
    n->item = data;
    if (start == NULL)
    {
        n->next = n;
        n->prev = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
}

void CDLL::insertAtLast(int data)
{
    Node *n = new Node;
    n->item = data;
    if (start == NULL)
    {
        n = n->next;
        n = n->prev;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
    }
}

Node *CDLL::search(int data)
{
    Node *t;
    t = start;
    if (start)
    {

        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != start);
    }
    return NULL;
}

void CDLL::insertAtAfter(Node *n, int data)
{
    if (n)
    {
        Node *t = new Node;
        t->item = data;
        t->prev = n;
        t->next = n->next;
        n->next->prev = t;
        n->next = t;
    }
}

void CDLL::deleteFirst()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = NULL;
        }
        else
        {
            Node *t;
            t = start;
            start->prev->next = start->next;
            start->next->prev = start->prev;
            delete t;
        }
    }
}

void CDLL::deleteLast()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = NULL;
        }
        else
        {
            Node *t;
            t = start->prev;
            start->prev->next = start; // Is it necessary?
            start->prev = t->prev;
            delete t;
        }
    }
}

void CDLL::deleteNode(int data)
{
    if (start)
    {
        if (start->next == NULL)
        {
            if (start->item == data)
            {
                delete start;
                start = NULL;
            }
        }
        else
        {
            Node *t = start;
            do
            {
                if (t->item == data)
                {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    if (t == start)
                        start = t->next;
                    delete t;
                }
                t = t->next;
            } while (t != start);
        }
    }
}

CDLL::~CDLL()
{
    while (start)
    {
        deleteFirst();
    }
}

void CDLL::printCLL()
{
    if (start)
    {
        Node *t = start;
        do
        {

            cout << " " << t->item;
            t = t->next;
        } while (t != start);
    }
    else
    {
        cout << "List is empty.";
    }
}

int main()
{
    CDLL d;
    d.insertAtStart(10);
    d.insertAtLast(20);
    d.insertAtAfter(d.search(20), 30);
    d.printCLL();
    cout << endl;
    return 0;
}