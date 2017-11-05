// 3-13最大k乘积问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int n, k;
string I;
int f[101][101];
int conv(int i, int j) {

	string str1 = I.substr(i, j);
	return atoi(str1.c_str());
}
void solve(int n, int m) {
	int i, j, k;
	int temp, maxt, tk;
	for (i = 1; i <= n; i++)//如果之分成一分，那等该数本身
		f[i][1] = conv(0, i);


	for (j = 2; j <= m; j++) {//j表示分的段数，j从2开始
		for (i = j; i <= n; i++) {//i表示字符串前i个

			for (k = 1, temp = 0; k<i; k++) {//k用于去寻找在哪里切割
				/*
				比如j=2,i=4吧
				1   0   0
				12   2   0
				123  36   6
				1234 492 144
				k从1开始，k<i;
				k=1时，maxt=f[k][j-1]*conv(k,i-k)=f[1][1]*conv(1,1)=1*2=2;
				k=2时，maxt=f[k][j-1]*conv(k,i-k)=f[2][1]*conv(2,1)=12*3=6;
				k=3时，maxt=f[k][j-1]*conv(k,i-k)=f[1][1]*conv(3,1)=123*4=492;
				把最大的放到temp中
				*/
				maxt = f[k][j - 1] * conv(k, i - k);
				if (temp<maxt) { temp = maxt; }
			}
			f[i][j] = temp;
		}
	}
}

int main() {

	cin >> n >> k;
	cin >> I;
	if (n<k || n == 0 || n != I.size()) {
		cout << "0" << endl;
		return 0;
	}
	solve(n, k);
	printf("%d\n",f[n][k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			printf("%4d", f[i][j]);
		}
		cout << endl;
	}

}
