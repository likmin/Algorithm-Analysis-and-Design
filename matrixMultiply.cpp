// matrixMultiply.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{


	int p[7] = { 30,35,15,5,10,20,25 };
	int n = 6;
	int m[7][7], s[7][7];
	fill(m[0], m[0] + 6 * 6, 99999999);
	fill(m[0], m[0] + 6 * 6, 99999999);
	for (int i = 1; i <= n; i++)m[i][i] = 0;
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%10d ", m[i][j]);
		}
		cout << endl;
	}
	
    return 0;
}

