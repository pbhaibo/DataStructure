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

template <class T>
void QuickSort(T *pArray, int nStart, int nEnd)
{
	int i = nStart;
	int j = nEnd;

	T tmp;
	if (nStart<nEnd)
	{
		tmp = pArray[nStart];
		while (i!=j)
		{
			while(i<j && pArray[j]>=tmp)
				j--;
			pArray[i] = pArray[j];
			while(i<j && pArray[i]<=tmp)
				i++;
			pArray[j] = pArray[i];
		}
		pArray[i] = tmp;
		QuickSort(pArray, nStart, i-1);
		QuickSort(pArray, t+1, nEnd);
	}	
}


#endif /* Sort_h */
