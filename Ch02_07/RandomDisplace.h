#ifndef RANDOMDISPLACE_H_
#define RANDOMDISPLACE_H_

#include <cstdlib>
#include <ctime>

int RandInt(int i, int j)
{
	return i+rand()%(j-i+1);
}

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void RandDis_a1(int *A, int N)
{
	A[0] = RandInt(1,N);

	int ntmp = 0;
	bool bFind = 1;
	for (int i=1; i<N; i++)
	{
		do 
		{
			ntmp = RandInt(1,N);
			bFind = 1;
			for (int j=0; j<i; j++)
			{
				if (ntmp==A[j])
				{
					bFind = 0;
					break;
				}				
			}
			if (bFind)
			{
				A[i] = ntmp;
			}
		} while (A[i]==0);
	}
}

void RandDis_a2(int *A, int N)
{
	bool *pUsed = new bool[N];
	memset(pUsed, 0, sizeof(bool)*N);
	int nRan = 0;

	for (int i=0; i<N; i++)
	{
		do 
		{
			nRan = RandInt(1,N);
			if (!pUsed[nRan-1])
			{
				A[i] = nRan;
				pUsed[nRan-1] = 1;
			}
		} while (A[i]==0);
	}
}

void RandDis_a3(int *A, int N)
{
	for (int i=0; i<N; i++)
	{
		A[i] = i+1;
	}

	for (int i=1; i<N; i++)
	{
		Swap(A[i], A[RandInt(0, i)]);
	}
}

#endif