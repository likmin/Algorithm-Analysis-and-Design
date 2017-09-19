// BinarySearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int BinarySearch(int a[],int x,int n) {
	int left = left = 0, right = n - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (x == a[middle])return middle;
		if (x > a[middle])left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

int main()
{
	int a[10] = { 2,3,54,764,2333,2543,22332,87422,191910,1111111 },k;
	cout<<BinarySearch(a,191910,10);
    return 0;
}

