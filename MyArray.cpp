/*
 *  MyArray.cpp
 *  ENSF 614 Lab 4, Exercise A
 *  Class implemenatation for MyArray.
 *  Completed by: Hassaan Ahmed Zuberi
 *  Submitted on: Oct 17, 2022
 */

#include "MyArray.h"

MyArray::MyArray()
{
    sizeM = 0;
    storageM = new EType[sizeM];
}

MyArray::MyArray(const EType *builtin, int sizeA)
{
    sizeM = sizeA;
    storageM = new EType[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = *(builtin + i);
    }
}

MyArray::MyArray(const MyArray &source)
{
    sizeM = source.size();
    storageM = new EType[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = source.at(i);
    }
}

EType MyArray::at(int i) const
{
    return storageM[i];
}

int MyArray::size() const
{
    return sizeM;
}

void MyArray::set(int i, EType new_value)
{
    storageM[i] = new_value;
}

void MyArray::resize(int new_size)
{
    EType *temp = new EType[new_size];

    for (int i = 0; i < new_size; i++)
    {
        temp[i] = *(storageM + i);
    }
    sizeM = new_size;

    delete[] storageM;
    storageM = temp;
}

MyArray &MyArray::operator=(const MyArray &rhs)
{
    if (this != &rhs)
    {
        delete[] storageM;
        sizeM = rhs.size();
        storageM = new EType[sizeM];
        for (int i = 0; i < sizeM; i++)
        {
            storageM[i] = rhs.at(i);
        }
    }

    return *this;
}

MyArray::~MyArray()
{
    delete[] storageM;
}
