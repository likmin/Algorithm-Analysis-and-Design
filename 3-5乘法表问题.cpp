// 3-5乘法表问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	char c;
	int p[100][100][3] = { 0 };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		p[n][n][s[i] - 'a'] = 1;
		n++;
	}
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			int j = i + k;
			for (int t = i; t < j; t++) {
				p[i][j][0] += p[i][t][2] * p[t + 1][j][0] + p[i][t][0] * p[t + 1][j][2] + p[i][t][1] * p[t + 1][j][2];
				p[i][j][1] += p[i][t][0] * p[t + 1][j][0] + p[i][t][0] * p[t + 1][j][1] + p[i][t][1] * p[t + 1][j][1];
				p[i][j][2] += p[i][t][1] * p[t + 1][j][0] + p[i][t][2] * p[t + 1][j][1] + p[i][t][2] * p[t + 1][j][2];
			}
		}
	}
	printf("%d", p[0][n - 1][0]);
    return 0;
}

