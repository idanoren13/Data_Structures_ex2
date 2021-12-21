#pragma once
#include "minHeap.h"
#include "maxHeap.h"
class FourHeapADT
{
private:
    const int SIZE = 10;
    maxHeap total_max_a;
    maxHeap median_max_b;
    minHeap total_min_b;
    minHeap median_min_a;
    /*  total_max and median_min are twins
    *   total_min and median_max are twins
    */
    int ADT_size;
    void fix_move();
    
public:
    dataType Max();
    dataType Min();
    dataType median();
    void CreateEmpty();
    void insert(int priority, std::string value);
    dataType deleteMax();
    dataType deleteMin();

};
