    #include "FourHeapADT.h"

//private

void FourHeapADT::fix_move() {
    dataType* res;
    dataType* res_twin;
    if ((total_min_b.getHeapSize() - total_max_a.getHeapSize()) > 1)   {
        res = new dataType();
        res = median_max_b.deleteMax();
        total_min_b.deleteLeaf(res->getTwin());
        //res->setTwin(nullptr);
        res_twin = new dataType(res);
        res->setTwin(res_twin);
        res_twin->setTwin(res);
        total_max_a.insert(res);
        median_min_a.insert(res_twin);

    }
    else if ((total_max_a.getHeapSize() - total_min_b.getHeapSize()) > 1)  {
        res = new dataType();
        res = median_min_a.deleteMin();
        total_max_a.deleteLeaf(res->getTwin());
       // res->setTwin(nullptr);
        res_twin = new dataType(res);
        res->setTwin(res_twin);
        res_twin->setTwin(res);
        total_min_b.insert(res);
        median_max_b.insert(res_twin);
    }
}

//public

void FourHeapADT::CreateEmpty() {
    total_max_a.init(SIZE);
    median_max_b.init(SIZE);
    total_min_b.init(SIZE);
    median_min_a.init(SIZE);
    ADT_size = 0;
}
dataType FourHeapADT::deleteMax() {
    dataType max=Max();
    total_max_a.deleteMax();
    median_min_a.deleteLeaf(max.getTwin());
    fix_move();
    ADT_size--;
    return max;
}
dataType FourHeapADT::deleteMin() {
    dataType min=Min();
    total_min_b.deleteMin();
    median_max_b.deleteLeaf(min.getTwin());
    fix_move();
    ADT_size--;
    return min;
}
void FourHeapADT::insert(int priority, std::string value) {
    /*creates data and twin*/
    dataType* data = new dataType(priority, value);
    dataType* data_twin = new dataType(data);
    data->setTwin(data_twin);
    data_twin->setTwin(data);
    if (ADT_size < 0)
        throw 4;
    else if (ADT_size <= 1) {
        total_max_a.insert(data);
        median_min_a.insert(data_twin);
    }
    //check priority
    else {
        if (data->getPriority() > median().getPriority()) {
            total_max_a.insert(data);
            median_min_a.insert(data_twin);
        }
        else {
            total_min_b.insert(data);
            median_max_b.insert(data_twin);
        }
    }
    ADT_size++;
    fix_move();
}


