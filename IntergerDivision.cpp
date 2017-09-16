// IntergerDivision.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int q(int n,int m) {
	if (n < 1 || m < 1)return 0;
	if (m == 1|| n== 1)return 1;
	if (m > n)return q(n, n);
	if (m == n)return 1 + q(n, m - 1);
	return q(n, m - 1) + q(n - m, m);
}
int main()
{
	int n;
	cin >> n;
	cout << q(n, n);
}

