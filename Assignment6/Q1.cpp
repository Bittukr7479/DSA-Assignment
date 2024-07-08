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
    void printCLL();
};

CLL::CLL()
{
    last = NULL;
}

void CLL::insertAtStart(int data)
{
    Node *n = new Node;
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}

void CLL::insertAtLast(int data)
{
    Node *n = new Node();
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}

Node *CLL::search(int data)
{
    Node *t;
    t = last;
    if (last == NULL)
        return NULL;
    t = last->next;
    do
    {
        if (t->item == data)
            return t;
        t = t->next;
    } while (t != last->next);
    return NULL;
}

void CLL::insertAtAfter(Node *t, int data)
{
    if (t)
    {

        Node *n = new Node;
        n->item = data;
        n->next = t->next;
        t->next = n;
        if (t == last)
            last = n;
    }
}

void CLL::deleteFirst()
{
    Node *n;
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            n = last->next;
            last->next = last->next->next;
            delete n;
        }
    }
}

void CLL::deleteLast()
{
    Node *temp;
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            temp = last->next;
            while (temp->next != last)
            {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }
}

void CLL::deleteNode(int data)
{
    Node *t1;
    Node *t2;
    if (last)
    {
        if (last->next == last)
        {
            if (last->item = data)
            {
                delete last;
                last = NULL;
            }
        }
        else
        {
            t1 = last;
            do
            {
                if (t1->next->item == data)
                {
                    t2 = t1->next;
                    t1->next = t2->next;
                    if (t2 == last)
                        last = t1;
                    delete t2;
                    break;
                }
                t1 = t1->next;
            } while (t1 != last);
        }
    }
}

void CLL::printCLL() {
    if (last) {
        Node *t = last->next;
        do {
            cout << " " << t->item;
            t = t->next;
        } while (t != last->next);
    } else {
        cout << "List is empty.";
    }
}

CLL::~CLL()
{
    while (last)
        deleteFirst();
}

int main()
{
    CLL d;
    d.insertAtStart(10);
    d.insertAtLast(20);
    d.insertAtAfter(d.search(20), 30);
    d.printCLL();
    cout << endl;
    return 0;
}