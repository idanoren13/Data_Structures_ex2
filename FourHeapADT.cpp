    #include "FourHeapADT.h"

//private

void FourHeapADT::fix_move() {
    dataType* res;
    dataType* res_twin;
    if ((total_min_b.getHeapSize() - total_max_a.getHeapSize()) > 1){
        res = median_max_b.deleteMax();
        total_min_b.deleteLeaf(res->getTwin()->getIndex());
        //res->setTwin(nullptr);
        res_twin = res->getTwin();
        total_max_a.insert(res);
        median_min_a.insert(res_twin);

    }
    else if ((total_max_a.getHeapSize() - total_min_b.getHeapSize()) >= 1)  {
        res = median_min_a.deleteMin();
        total_max_a.deleteLeaf(res->getTwin()->getIndex());
       // res->setTwin(nullptr);
        res_twin = res->getTwin();
        total_min_b.insert(res);
        median_max_b.insert(res_twin);
    }
}

//public

dataType FourHeapADT::Max() {
    if ((ADT_size >= 1 && total_max_a.getHeapSize() >= 1))
        return *(total_max_a.max());
    else if (ADT_size == 1 && median_max_b.getHeapSize() == 1)
        return *(median_max_b.max());
    else
        throw 105;//error: corrupt ADT
}
dataType FourHeapADT::Min() {
    if ((ADT_size >= 1 && total_min_b.getHeapSize() >= 1))
        return *(total_min_b.min());     
    else if (ADT_size == 1 && median_min_a.getHeapSize() == 1)
        return *(median_min_a.min());
    else
        throw 105;//error: corrupt ADT
}
dataType FourHeapADT::median() { 
    if ((ADT_size >= 1 && median_max_b.getHeapSize() >= 1))
        return *(median_max_b.max());
    else if (ADT_size == 1 && total_max_a.getHeapSize() == 1)
        return *(total_max_a.max());
    else
        throw 105;//error: corrupt ADT
}


void FourHeapADT::CreateEmpty() {
    total_max_a.init(SIZE);
    median_max_b.init(SIZE);
    median_min_a.init(SIZE);
    total_min_b.init(SIZE);
    ADT_size = 0;
}
dataType FourHeapADT::deleteMax() {
    dataType max=Max();
    total_max_a.deleteMax();
    median_min_a.deleteLeaf(max.getTwin()->getIndex());
    fix_move();
    ADT_size--;
    return max;
}
dataType FourHeapADT::deleteMin() {
    dataType min=Min();
    total_min_b.deleteMin();
    median_max_b.deleteLeaf(min.getTwin()->getIndex());
    fix_move();
    ADT_size--;
    return min;
}
void FourHeapADT::insert(int priority, std::string value) {
    /*creates data and twin*/
    dataType* node = new dataType(priority, value);
    dataType* node_twin = new dataType(node);
    node->setTwin(node_twin);
    node_twin->setTwin(node);
    if (ADT_size < 0)
        throw 4;
    else if (ADT_size <= 1) {
        total_max_a.insert(node);
        median_min_a.insert(node_twin);
    }
    //check priority
    else {
        if (node->getPriority() > median().getPriority()) {
            total_max_a.insert(node);
            median_min_a.insert(node_twin);
        }
        else {
            total_min_b.insert(node);
            median_max_b.insert(node_twin);
        }
    }
    ADT_size++;
    fix_move();
}


