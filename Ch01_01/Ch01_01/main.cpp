//
//  main.cpp
//  test
//
//  Created by PengBo on 16/1/31.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "Sort.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //random generate an array
    int N = 100;
    unsigned int *pArray = new unsigned int[N];
    srand(time(NULL));
    for (int i=0; i<N; i++)
    {
        pArray[i] = rand()%(N+1);
        // cout<<dArray[i]<<endl;
    }
    
    //select
    int k = N / 2 ;
    BubbleSort(pArray, N);  //sort the array pArray
    
    for (int i=0 ; i<N; i++) {
        cout<<pArray[i]<<endl;
    }
    
    cout<<"The Kth greatest number is "<<pArray[k]<<endl;
    
    delete[] pArray;
    return 0;
}