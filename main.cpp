#include <iostream>
#include <random>
#include <ctime>
#include <sys/time.h>
#include <memory>
#include "quick_sort.h"

using namespace std;

ulong get_time_stamp(){
    timeval tv;
    gettimeofday(&tv, nullptr);
    return tv.tv_sec*1000+tv.tv_usec/1000;
}

int main() {
    default_random_engine e;
    uniform_int_distribution<int> uid(INT32_MIN,INT32_MAX);
    vector<int> origin;
    origin.reserve(100000);
    for (int i=100000;i>=0;--i){
        origin.push_back(i);
    }
    vector<int> for_optimized=origin;
    quick_sort q;
    ulong sort_start=get_time_stamp();
    q.sort(origin);
    cout<<"sort costs:"<<get_time_stamp()-sort_start<<endl;
    ulong sort_opt_start=get_time_stamp();
    q.sort_optimized(for_optimized);
    cout<<"sort optimized costs:"<<get_time_stamp()-sort_opt_start<<endl;
    cout<<"insert sort count:"<<q.insert_sort_cnt<<endl;
    return 0;
}
