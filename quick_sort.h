//
// Created by huangchengxi on 2021/8/27.
//

#include <vector>

#ifndef QUICK_SORT_QUICK_SORT_H
#define QUICK_SORT_QUICK_SORT_H


class quick_sort {
private:
    int partition(std::vector<int> &origin,int start_index,int end_index);
    void insert_sort(std::vector<int> &origin,int start_index,int end_index);
    void sort1(std::vector<int> &origin,int start_index,int end_index);
    void sort1_optimized(std::vector<int> &origin,int start_index,int end_index,int &divide_size);
    int partition_optimized(std::vector<int> &origin,int start_index,int end_index);
    void swap(int &a,int &b);
public:
    unsigned int insert_sort_cnt=0;
    void sort(std::vector<int> &origin);
    void sort_optimized(std::vector<int> &origin);
};

#endif //QUICK_SORT_QUICK_SORT_H
