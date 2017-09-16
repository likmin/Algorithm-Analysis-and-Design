// Perm.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void Perm(char c[], int k, int m) {//k表示数组的第一个数下标，
								   //m表示数组的最后一个数下标
	if (k == m) {//递归到只有一个了，输出排列
		for (int i = 0; i <= m; i++)cout << c[i];
		cout << endl;
	}else //还有多个元素待排列，递归产生排列
		for (int i = k; i <= m; i++) {
			swap(c[k], c[i]);//交换c[k],c[i],
			Perm(c, k + 1, m);//寻找Ri的全排列
			swap(c[k], c[i]);//恢复原来的排序
		}
}
int main()
{
	char c[5] = "abc";
	Perm(c, 0, 2);
    return 0;
}

