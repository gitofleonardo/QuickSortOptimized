//
// Created by huangchengxi on 2021/8/27.
//

#include "quick_sort.h"
#include <cmath>
#include <iostream>

void quick_sort::sort(std::vector<int> &origin) {
    sort1(origin,0,origin.size()-1);
}
void quick_sort::sort1(std::vector<int> &origin, int start_index, int end_index) {
    if(start_index>=end_index) return;
    int middle= partition(origin,start_index,end_index);
    sort1(origin,start_index,middle-1);
    sort1(origin,middle+1,end_index);
}
void quick_sort::sort1_optimized(std::vector<int> &origin, int start_index, int end_index,int &divide_size) {
    if (start_index>=end_index) return;
    if (end_index-start_index< divide_size){
        insert_sort(origin,start_index,end_index);
        ++insert_sort_cnt;
    }else{
        int middle= partition_optimized(origin,start_index,end_index);
        int middle_left=middle;
        int middle_right=middle;
        while(origin[middle_left]==origin[middle]) --middle_left;
        while(origin[middle_right]==origin[middle]) ++middle_right;
        sort1_optimized(origin,start_index,middle_left,divide_size);
        sort1_optimized(origin,middle_right,end_index,divide_size);
    }
}
void quick_sort::sort_optimized(std::vector<int> &origin) {
    int div=int (log2(origin.size()));
    sort1_optimized(origin,0,origin.size()-1,div);
}
void quick_sort::insert_sort(std::vector<int> &origin, int start_index, int end_index) {
    if (end_index-start_index<1) return;
    for (int s=start_index+1,e=end_index;s<=e;++s){
        int cur=s;
        int val=origin[cur];
        for (;cur>0;--cur){
            if (val<origin[cur-1]){
                origin[cur]=origin[cur-1];
            }else{
                break;
            }
        }
        origin[cur]=val;
    }
}
int quick_sort::partition(std::vector<int> &origin, int start_index, int end_index) {
    if (start_index>=end_index) return start_index;
    int slow=start_index-1;
    int fast=start_index;
    int pivot=origin[end_index];
    while (fast<end_index){
        if (origin[fast]<=pivot){
            ++slow;
            if (slow!=fast){
                swap(origin[fast],origin[slow]);
            }
        }
        ++fast;
    }
    ++slow;
    origin[end_index]=origin[slow];
    origin[slow]=pivot;
    return slow;
}
int quick_sort::partition_optimized(std::vector<int> &origin, int start_index, int end_index) {
    if (start_index>=end_index) return start_index;
    int middle=start_index+(end_index-start_index)/2;
    swap(origin[middle],origin[end_index]);
    int pivot=origin[end_index];
    int slow=start_index-1,fast=start_index;
    while (fast<end_index){
        if (origin[fast]<=pivot){
            ++slow;
            if(slow!=fast){
                swap(origin[slow],origin[fast]);
            }
        }
        ++fast;
    }
    ++slow;
    origin[end_index]=origin[slow];
    origin[slow]=pivot;
    return slow;
}
void quick_sort::swap(int &a, int &b) {
    int tmp=a;
    a=b;
    b=tmp;
}