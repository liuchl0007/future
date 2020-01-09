#ifndef _DYNAMICLIST_H_
#define _DYNAMICLIST_H_
#include "SeqList.h"

namespace WLLib {

template<typename T>
class DynamicList : public SeqList<T>
{
    int m_capacity;
public:
    DynamicList(int capacity);
    int capacity() const;
    void resize(const int capacity);
    ~DynamicList();
};

template<typename T>
DynamicList<T>::DynamicList(int capacity)
{
    this->m_array = new T(capacity);

    if( this->m_array != NULL )
    {
        m_capacity = capacity;
        this->m_length = 0;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList Object ...");
    }
}

template<typename T>
int DynamicList<T>::capacity() const
{
    return m_capacity;
}

template<typename T>
void DynamicList<T>::resize(const int capacity)
{
    if( m_capacity != capacity )
    {
        T* array = new T[capacity];

        int length = m_capacity < capacity ? m_capacity : capacity;

        for(int i=0; i<length; i++)
        {
            array[i] = this->m_array[i];
        }

        T* temp = this->m_array;

        this->m_array = array;
        m_capacity = capacity;

        delete[] temp;
    }
}

template<typename T>
DynamicList<T>::~DynamicList()
{
    delete[] this->m_array;
}

}


#endif // _DYNAMICLIST_H_
