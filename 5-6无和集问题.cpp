// 5-6无和集问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>  
#define N 100  
int F[N][N], answer[N][N];//F用于存取临时数据，answer用于存取最终结果
int n, maxValue;
bool judge(int k, int t) {
	for (int i = 1; i <= F[k][0]; i++) {
		for (int j = i + 1; j <= F[k][0]; j++) {
			if (F[k][i] + F[k][j] == t)return false;
		}
	}
	return true;
}
void DFS(int t) {

	if (t > maxValue) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j <= F[i][0]; j++) //F[i][0]存取F[i]中的数据的个数，初始值为0;
				answer[i][j] = F[i][j];
		maxValue = t;
	}

	for (int i = 0; i < n; i++) {
		F[i][F[i][0] + 1] = t;
		if (judge(i,t)) {//判断t是否可以放在F[i]数组中，如果可以放进去， 继续深度优先搜索
			F[i][0] += 1;//把t放进F[i]数组中
			DFS(t + 1);
			F[i][0] -= 1;//回溯再把t从F[i]数组中取出来
		}
	}
}
int main() {
	scanf("%d", &n);
	maxValue = 0;
	DFS(1);
	/*
	DFS(1)  F[0][0]=0;满足条件，F[0][1]=1, F[0][0]++;	t++
	DFS(2)	F[0][0]=1;满足条件，F[0][2]=2,	F[0][0]++;	t++
	DFS(3)	F[0][0]=2;不满足条件，F[1][0]=0,F[1][1]=3;F[1][0]++; t++;
	DFS(4)  都满足条件，回溯尝试，找到k最大的情况
	。。。。
	DFS(9)	F[0],F[1]都不满足
	*/

	printf("%d\n", maxValue - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <=answer[i][0]; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}

	return 0;
}


