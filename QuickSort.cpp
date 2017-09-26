// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int Partition(int a[], int p, int r) {
	int i = p, j = r + 1;
	int x = a[p];
	while (1) {
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}
void QuickSort(int a[],int p,int r) {
	if (p < r) {
		
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
int main()
{
	int a[10] = { 12,45,55,4,8,1,14,5,32,78 };
	QuickSort(a, 0, 10);
	//sort(a, a + 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
    return 0;
}

