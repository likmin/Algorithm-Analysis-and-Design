// SetSplit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int S(int n,int m) {
	if (m>n ||m==0)return 0;
	else if (m==1||n==1||m==n)return 1;
	else return m*S(n - 1, m) + S(n - 1, m - 1);
}
int main()
{
	int n,m;
	cin >> n>>m;
	cout<<S(n,m);
    return 0;
}

