#include <iostream>
using namespace std;

struct SequentialList
{
    int *elements;
    int size;
    int capacity;
};

void initList(SequentialList *list, int capacity)
{
    list->elements = new int[capacity];
    list->size = 0;
    list->capacity = capacity;
}

void destroyList(SequentialList *list)
{
    delete[] list->elements;
}

int getSize(SequentialList *list)
{
    return list->size;
}

int getCapacity(SequentialList *list)
{
    return list->capacity;
}
bool isEmpty(SequentialList *list)
{
    return list->size == 0;
}

void insertMy(SequentialList *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        return;
    }
    if (list->size == list->capacity)
    {
        int newCapacity = list->capacity * 2;
        int *newElements = new int[newCapacity];
        for (int i = 0; i < list->size; i++)
        {
            newElements[i] = list->elements[i];
        }
        delete[] list->elements;
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index; i--)
    {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = value;
    list->size++;
}

void deleMy(SequentialList *list, int index)
{
    if (index < 0 || index > list->size)
    {
        return;
    }

    if (index == list->size)
    {
        list->size--;
        return;
    }
    for (int i = index; i < list->size; i++)
    {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

int find(SequentialList *list, int value)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->elements[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int getElement(SequentialList *list, int index)
{
    if (index < 0 || index > list->size)
    {
        return -1;
    }
    return list->elements[index];
}

void updateElement(SequentialList *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        return;
    }
    list->elements[index] = value;
}

void printList(SequentialList *list){
    for (int i = 0; i < list->size; i++)
    {
        cout << list->elements[i] << " ";
    }
    cout << endl;
}

int main()
{
    SequentialList listmy;
    // init sequence
    initList(&listmy, 10);
    // insert sequence
    for (int i = 0; i < listmy.capacity; i++)
    {
        insertMy(&listmy, i, i);
        /* code */
    }
    //delete
    deleMy(&listmy,1);
    //modify
    updateElement(&listmy,0,100);
    //find
    int pos = find(&listmy,111);
    if(pos == -1){
        cout<<"don't have this value"<<endl;
    }else{
        cout<<"have this value pos :"<<pos<<endl;
    }
    //get index element 
    int value = getElement(&listmy,0);
    cout<<"value :"<<value<<endl;
    
    printList(&listmy);
    return 0;
}