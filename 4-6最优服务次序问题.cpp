// 4-6最优服务次序问题.cpp : 定义控制台应用程序的入口点。
//
/*
10
56 12 1 99 1000 234 33 55 99 812
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{


	int N, sum = 0, wait = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i<N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	/*
	从小到大排序，先服务服务时间少的顾客
	wait表示当前顾客需要等待的时间
	*/
	for (int i = 0; i<N; i++) {
		wait += v[i];
		sum += wait;

	}

	printf("sum = %d\n", sum);
	printf("%0.2f", sum*1.0 / N);
}
