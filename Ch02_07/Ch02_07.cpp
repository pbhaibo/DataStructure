// Ch02_07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "RandomDisplace.h"
#include <ctime>


int _tmain(int argc, _TCHAR* argv[])
{
	//set random seed
	srand(time(NULL));

	
	int N1[4] = {250, 500, 1000, 2000};
	int N2[6] = {2500, 5000, 10000, 20000, 40000, 80000};
	int N3[7] = {10000, 20000, 40000, 80000, 160000, 320000, 640000};

	clock_t cStart, cEnd;
	
	std::cout<<"The running time for every algorithm are as follows:\n";

	//Algorithm 1
	std::cout<<"No.1:\t";
	for (int i=0; i<4; i++)
	{
		int *A = new int[N1[i]];
		memset(A, 0, sizeof(int)*N1[i]);

		cStart = clock();
		RandDis_a1(A, N1[i]);
		cEnd = clock();

		delete[] A;	
		std::cout<<(cEnd-cStart)<<' ';
	}
	std::cout<<" ms"<<std::endl;

	//Algorithm 2
	std::cout<<"No.2:\t";
	for (int i=0; i<4; i++)
	{
		int *A = new int[N2[i]];
		memset(A, 0, sizeof(int)*N2[i]);

		cStart = clock();
		RandDis_a2(A, N2[i]);
		cEnd = clock();

		delete[] A;	
		std::cout<<(cEnd-cStart)<<' ';
	}
	std::cout<<" ms"<<std::endl;

	//Algorithm 3
	std::cout<<"No.3:\t";
	for (int i=0; i<7; i++)
	{
		int *A = new int[N3[i]];
		memset(A, 0, sizeof(int)*N3[i]);

		cStart = clock();
		RandDis_a3(A, N3[i]);
		cEnd = clock();

		delete[] A;	
		std::cout<<(cEnd-cStart)<<' ';
	}
	std::cout<<" ms"<<std::endl;



	return 0;
}

