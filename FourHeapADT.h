#pragma once
#include "minHeap.h"
#include "maxHeap.h"
class FourHeapADT
{
private:
    const int SIZE = 10;
    maxHeap total_max_a, median_max_b;
    minHeap total_min_b, median_min_a;
    bool is_first_insert = true;
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
    ~FourHeapADT()
    {
        total_max_a.remove();
        median_max_b.remove();
        median_min_a.remove();
        total_min_b.remove();
    }
};
