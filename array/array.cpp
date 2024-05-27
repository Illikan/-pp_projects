#include "array.h"
#include <iostream>
using namespace std;

Array::Array(int startCapacity)
{
    if (startCapacity <= 0)
        capacity = DEFAULT_CAPACITY;
    else
        capacity = startCapacity;
    pointer = new int[capacity];
    size = 0;
}

Array::~Array() { delete[] pointer; }

Array::Array(const Array &arr)
{
    pointer = new int[arr.capacity];
    size = arr.size;
    capacity = arr.capacity;
    for (int i = 0; i < size; i++)
    {
        pointer[i] = arr.pointer[i];
    }
}

Array &Array::operator=(const Array &arr)
{
    if (this == &arr)
    {
        return *this;
    }
    if (capacity != arr.capacity)
    {
        delete[] pointer;
        pointer = new int[arr.capacity];
        capacity = arr.capacity;
    }
    size = arr.size;
    for (int i = 0; i < size; i++)
    {
        pointer[i] = arr.pointer[i];
    }

    return *this;
}

int &Array::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw ArrayException();
    }
    else
    {
        return pointer[index];
    }
}

void Array::add(int elem, int index)
{
    if (index < 0 || index > size)
    {
        throw ArrayException();
    }
    if (size == capacity)
    {
        increaseCapacity(size + 1);
    }
    for (int i = size - 1; i >= index; i--)
    {
        pointer[i + 1] = pointer[i];
    }
    size++;
    pointer[index] = elem;
}

void Array::add(int elem) { add(elem, size); }

void Array::increaseCapacity(int newCapacity)
{
    capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
    int *newpointer = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        newpointer[i] = pointer[i];
    }
    delete[] pointer;
    pointer = newpointer;
}

void Array::del(int index)
{
    if (index < 0 || index >= size)
    {
        throw ArrayException();
    }

    for (int i = index; i < size - 1; i++)
    {
        pointer[i] = pointer[i + 1];
    }
    pointer[size - 1] = 0;
    size--;
}

int Array::getSize() const { return size; }

ostream &operator<<(ostream &out, const Array &arr)
{
    out << "Total size: " << arr.size << endl;
    for (int i = 0; i < arr.size; i++)
    {
        out << arr.pointer[i] << endl;
    }
    return out;
}