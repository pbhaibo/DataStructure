#ifndef PRINTREALNUM_H_
#define PRINTREALNUM_H_

#include <stdio.h>
//print digit number
bool PrintDigit(int n)
{
	//if n is not a digit, return false
	if (n>9 || n<0)
	{
		return 0;
	}
	else
	{
		printf("%d", n);
	}
	
}

void PrintIntPart(int tNum)
{
	if (tNum > 10)
	{
		PrintIntPart(tNum / 10);
	}
	PrintDigit(tNum % 10);
}

void PrintFloatPart(double tNum)
{
	if ((tNum-(int)tNum) > 0.000000000000000000001 || ((int)tNum - tNum) > 0.000000000000000000001)
	{
		PrintDigit((int)(tNum*10));
		tNum = (tNum*10) - (int)(tNum*10);
		PrintFloatPart(tNum);
	}
}

template<class T>
void PrintOut(T tNum)
{
	if (tNum<0)
	{
		printf("-");
		tNum = -tNum;
	}

	int nIntPart = (int)tNum;
	double nFloatPart = tNum - nIntPart;

	PrintIntPart(nIntPart);
	printf(".");
	PrintFloatPart(nFloatPart);
}

#endif