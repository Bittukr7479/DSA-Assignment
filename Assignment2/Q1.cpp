#include <iostream>
#include <stdio.h>
using namespace std;
#define INVALID_CAPACITY 1;
#define EMPTY_ARRAY 2;
#define INVALID_INDEX 3;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    void createArray(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void delElement(int);
    int getElement(int);
    int count();
    int find(int);
    ~Array();
    Array(Array &);
    Array &operator=(Array &);
};

Array::Array(int cap)
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

void Array::createArray(int cap)
{
    if (ptr == NULL)
    {
        if (cap < 1)
            throw INVALID_CAPACITY;
        capacity = cap;
        lastIndex = -1;
        ptr = new int[capacity];
    }
    else
    {
        if (cap < 1)
            throw INVALID_CAPACITY;
        delete[] ptr;
        capacity = cap;
        lastIndex = -1;
        ptr = new int[capacity];
    }
}

bool Array::isEmpty()
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;

        return lastIndex == -1;
    }
    catch (int e)
    {
        cout << "\nInvalid Array";
    }
}

bool Array::isFull()
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;

        return (capacity == lastIndex + 1);
    }
    catch (int e)
    {
        cout << "\nInvalid Array";
    }
}

void Array::append(int data)
{
    try
    {
        if (ptr == NULL)
            throw INVALID_CAPACITY;
        if (isFull())
            cout << "\nArray Overflow";
        else
        {
            lastIndex++;
            ptr[lastIndex] = data;
        }
    }
    catch (int e)
    {
        cout << "\nInvalid Array";
    }
}

void Array::insert(int index, int data)
{

    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "\nInvalid Index";
    }
    else if (isFull())
    {
        cout << "\nArray Overflow";
    }
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void Array::edit(int index, int newData)
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

void Array::delElement(int index)
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index or Empty Array";
    else
    {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
    }
}

int Array::getElement(int index)
{

    if (ptr == NULL)
        throw INVALID_CAPACITY;
    if (lastIndex == -1)
        throw EMPTY_ARRAY;

    if (index < 0 || index > lastIndex + 1)
        throw INVALID_INDEX;
    return ptr[index];
}

int Array::count()
{
    if (ptr == NULL)
        throw INVALID_CAPACITY;
    return (lastIndex + 1);
}

int Array::find(int data)
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
        cout << "\nInvalid Array";
    }
}

Array::~Array()
{
    if (ptr != NULL)
        delete[] ptr;
}

Array::Array(Array &arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if (arr.ptr == NULL)
        ptr == NULL;
    ptr = new int[capacity];
    for (int i = 0; i < lastIndex; i++)
    {
        ptr[i] = arr.ptr[i];
    }
}

Array &Array::operator=(Array &arr)
{
    if (ptr != NULL)
        delete[] ptr;
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if (arr.ptr == NULL)
        ptr = NULL;
    ptr = new int[capacity];
    for (int i = 0; i < arr.lastIndex; i++)
        ptr[i] = arr.ptr[i];
}

int main()
{
    Array obj(3);
    obj.append(10);
    obj.insert(0, 20);
    obj.insert(0, 30);
    // obj.delElement(1);
    for (int i = 0; i < obj.count(); i++)
    {
        cout << obj.getElement(i) << " ";
    }
    cout << obj.isEmpty();

    cout << obj.isFull();

    return 0;
}