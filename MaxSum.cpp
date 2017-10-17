// MaxSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int a[6] = { -2,11,-4,13,-5,-2 };
	int besti, bestj;
	int n=6, sum = 0,thissum=0;
	for (int i = 0; i < n; i++) {
		thissum = 0;
		for (int j = i; j < n; j++) {
			thissum += a[j];
			if (thissum > sum) {
				sum = thissum;
				besti = i;
				bestj = j;
			}
		}
	}
	cout << "sum = " << sum;
    return 0;
}

