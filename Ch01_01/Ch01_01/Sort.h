//
//  Sort.h
//  test
//
//  Created by PengBo on 16/2/22.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

//Bubble Sort
template <class T>
void BubbleSort(T *pArray, int n)
{
    for (int i=0 ; i<n-1 ; i++)
    {
        for (int j=0 ; j<n-i-1; j++)
        {
            if (pArray[j] > pArray[j+1]) {
                T tmp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = tmp;
            }
        }
    }
}


#endif /* Sort_h */
