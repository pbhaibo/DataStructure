//
//  main.cpp
//  Sort
//
//  Created by PengBo on 16/2/22.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "Sort.h"
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N = 100;
    unsigned int *pArray = new unsigned int[N];
    
    clock_t cStart_t, cEnd_t;
    
    srand(time(NULL));
    for (int i=0; i<N; i++)
    {
        pArray[i] = rand()%(N+1);
        // cout<<dArray[i]<<endl;
    }
    
    //select
    cStart_t = clock();
    BubbleSort(pArray, N);  //sort the array pArray
    cEnd_t = clock();
    
    for (int i=0 ; i<N; i++) {
        cout<<pArray[i]<<endl;
    }
    
    cout<<"The time cost on sorting is "<<(cEnd_t-cStart_t)/1000<<" s\n";
    
    return 0;
}
