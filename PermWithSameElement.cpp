// PermWithSameElement.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "stdafx.h"
#include<iostream>
using namespace std;
int IsSame(char c[], int k, int i) {
	if (i > k)
		for (int t = k; t < i; t++)
			if (c[t] == c[i])return 0;
	return 1;
}
void Perm(char c[], int k, int m) {//k表示数组的第一个数下标，
								   //m表示数组的最后一个数下标
	if (k == m) {//递归到只有一个了，输出排列
		for (int i = 0; i <= m; i++)cout << c[i];
		cout << endl;
	}
	else //还有多个元素待排列，递归产生排列
		for (int i = k; i <= m; i++) {
			if(IsSame(c,k,i)){//查找后缀序列中有没有相同，有则跳过
				swap(c[k], c[i]);//交换c[k],c[i],
				Perm(c, k + 1, m);//寻找Ri的全排列
				swap(c[k], c[i]);//恢复原来的排序
			}
			else continue;
			
		}
}
int main()
{
	char c[5] = "aacc";
	Perm(c, 0, 3);
	return 0;
}

