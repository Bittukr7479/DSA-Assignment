#include <iostream>
#include <stdio.h>
using namespace std;
#define INVALID_CAPACITY 1;
#define EMPTY_DynArray 2;
#define INVALID_INDEX 3;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void doubleArray();
    void halfArray();

public:
    DynArray(int);
    int getCapacity();
    // void createDynArray(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void delElement(int);
    int getElement(int);
    int count();
    int find(int);
    ~DynArray();
};

DynArray::DynArray(int cap)
{
    try
    {
        if (cap < 1)
            throw INVALID_CAPACITY;
        capacity = cap;
        lastIndex = -1;
        ptr = new int[capacity];
    }
    catch (int e)
    {
        cout << "\nInvalid capacity";
        ptr = NULL;
    }
}

void DynArray::doubleArray()
{
    int *temp;
    temp = new int[capacity * 2];
    for (int i = 0; i < lastIndex; i++)
        temp[i] = ptr[i];
    capacity *= 2;
    delete[] ptr;
    ptr = temp;
}

void DynArray::halfArray()
{
    int *temp;
    temp = new int[capacity / 2];
    for (int i = 0; i < lastIndex; i++)
        temp[i] = ptr[i];
    capacity /= 2;
    delete[] ptr;
    ptr = temp;
}

int DynArray::getCapacity()
{
    return capacity;
}

// void DynArray::createDynArray(int cap)
// {
//     if (ptr == NULL)
//     {
//         if (cap < 1)
//             throw INVALID_CAPACITY;
//         capacity = cap;
//         lastIndex = -1;
//         ptr = new int[capacity];
//     }
//     else
//     {
//         if (cap < 1)
//             throw INVALID_CAPACITY;
//         delete[] ptr;
//         capacity = cap;
//         lastIndex = -1;
//         ptr = new int[capacity];
//     }
// }

bool DynArray::isEmpty()
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;
        return lastIndex == -1;
    }
    catch (int e)
    {
        cout << "\nInvalid DynArray";
    }
}

bool DynArray::isFull()
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;

        return (capacity == lastIndex + 1);
    }
    catch (int e)
    {
        cout << "\nInvalid DynArray";
    }
}

void DynArray::append(int data)
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;
        if (isFull())
            doubleArray();
        lastIndex++;
        ptr[lastIndex] = data;
    }
    catch (int e)
    {
        cout << "\nInvalid DynArray";
    }
}

void DynArray::insert(int index, int data)
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "\nInvalid Index";
    }
    else if (isFull())
        doubleArray();

    for (int i = lastIndex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index] = data;
    lastIndex++;
}

void DynArray::edit(int index, int newData)
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index";
    }
    else
    {
        ptr[index] = newData;
    }
}

void DynArray::delElement(int index)
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index or Empty DynArray";
    else
    {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
        if (capacity > 1 && lastIndex < capacity / 2)
            halfArray();
    }
}

int DynArray::getElement(int index)
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (lastIndex == -1)
        throw EMPTY_DynArray;
    if (index < 0 || index > lastIndex + 1)
        throw INVALID_INDEX;
    return ptr[index];
}

int DynArray::count()
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    return (lastIndex + 1);
}

int DynArray::find(int data)
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;
        for (int i = 0; i < lastIndex + 1; i++)
        {
            if (ptr[i] == data)
                return i;
        }
        return -1;
    }
    catch (int e)
    {
        cout << "\nInvalid DynArray";
    }
}

DynArray::~DynArray()
{
    if (ptr != NULL)
        delete[] ptr;
}

int main()
{
    DynArray obj(3);
    obj.append(10);
    obj.insert(0, 20);
    obj.insert(0,30);
    obj.delElement(1);
    for (int i = 0; i < obj.count(); i++)
    {
       cout<<obj.getElement(i)<<" ";
    }
    cout<<obj.isEmpty();

    cout<<obj.isFull();

    return 0;
}