// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a[10] = { 15,21,4,1,75,11,2,5,8,14 };
int b[10] = { 0 };
void Merge(int left, int m, int right) {
	int i = left, j = i + 1,k=left;
	while (i <= m&&j <= right) {
		if (a[i] <= a[j]) b[k++]=a[i++];
		else b[k++] = a[j++];
	}
	if (i > m)
		for (int n = j; n <= right; n++)
			b[k++] = a[n];
	else
		for (int n = i; n <= right; n++)
			b[k++] = a[n];
}
void copy(int left,int right) {
	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}
}
void MergeSort(int left,int right) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	if (left < right) {
		int i = (left + right) / 2;
		MergeSort( left, i);
		MergeSort(i + 1, right);
		Merge(left, i, right);
		copy(left, right);
	}

}
int main()
{
	int a[10] = {15,21,4,1,75,11,2,5,8,14};
	MergeSort(0, 10);
	
    return 0;
}

