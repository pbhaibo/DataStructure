//
//  main.cpp
//  Ch01_01
//
//  Created by PengBo on 16/1/31.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "Sort.h"
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //random generate an array
    clock_t cStart_t, cEnd_t;
    for (int N=1; N<20001; N++)  //set N from 0~20000
    {
        cStart_t = clock();
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
        
 /*       for (int i=0 ; i<N; i++) {
            cout<<pArray[i]<<endl;
        }*/
        
//        cout<<"The Kth greatest number is "<<pArray[k]<<endl;
        delete[] pArray;
        
        cEnd_t = clock();
        cout<<(cEnd_t-cStart_t)/1000<<endl;
    }
    
    
 
    return 0;
}