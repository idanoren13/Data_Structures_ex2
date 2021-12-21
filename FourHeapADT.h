#pragma once
#include "minHeap.h"
#include "maxHeap.h"
class FourHeapADT
{
private:
    const int SIZE = 100;
    maxHeap total_max_a, median_max_b;
    minHeap total_min_b, median_min_a;
    /*  total_max and median_min are twins
    *   total_min and median_max are twins
    */
    int ADT_size;
    void fix_move();
    
public:
    dataType Max(){ return *(total_max_a.max());   }
    dataType Min(){ return *(total_min_b.min());   }
    dataType median(){ return *(median_max_b.max()); }
    void CreateEmpty();
    void insert(int priority, std::string value);
    dataType deleteMax();
    dataType deleteMin();

};

/* PASTE HEAR!!!

dataType FourHeapADT::Max()
{
    return (total_max.max());
}
dataType FourHeapADT::Min()
{
    return (total_min.max());
}
dataType FourHeapADT::Median()
{
    return (total_max.max());
}
#include <iostream>
using namespace std;
class MyClass
{
public:
    MyClass();
    int Max();
    int Min();
    int median(); 
    void CreateEmpty();
    void Insert(int priority, String value);
    void fix_move();
    Data_type DeleteMax();
    Data_type DeleteMin();
    ~MyClass();

private:
    Heapabs[2] Max_heaps;
    Heapabs[2] Min_heaps;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
} 

int Max()
{
    return (max_heaps[1].head());
}
int Min()
{
    return (min_heaps[0].head());
}
int Median()
{
    return (min_heaps[1].head());
}
void CreateEmpty(){
    int i;
    for (i = 0; i < 2; i++) {
        max_heaps[i].make_empty();
        min_heaps[i].make_empty();
    }

}
Data_type DeleteMax()
{
    int max=Max();
    Max_heaps[1].delete(head);


    fix_move();

    return max;
}
Data_type DeleteMin()
{
    int min = Min();
    Max_heaps[1].delete(head);
    //TODO  FIX WITH LEFT SON-idan

    fix_move();


    return min;
}
void Insert(int priority, String value)
{
    Data_dype data = Data_type(priority, value);
    if (data.priority > Median()/max value/) { 
        max_heaps[0].insert(data);
        max_heaps[1].insert(data);

    }
    else
    {
        min_heaps[0].insert(data);
        min_heaps[0].insert(data);
    }
    fix_move();

}
void fix_move()
{
    if ((min_heaps.size - max_heaps.size) > 1)
    {
        max_hip[0].insert(min_heaps[1].delete(head));

    }
    else if ((max_heaps.size - min_heaps.size) > 1)
    {
        min_hip[1].insert(max_hip[0].delete(head));
    }
}
*/

