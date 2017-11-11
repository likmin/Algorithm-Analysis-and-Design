// 4-1会场安排问题.cpp : 定义控制台应用程序的入口点。
//
/*
5
1 23
12 28
25 35
27 80
36 50


3
1 45
22 45
44 54
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	int start, end,N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		if (v.empty()) {
			v.push_back(end);
		}
		else {
			sort(v.begin(), v.end());
			int i = 0;
			while (i<v.size()&&start < v[i])i++;
			if (i == v.size())
				v.push_back(end);
			else v[i] = end;
		}
	}
	cout << v.size();
    return 0;
}

