// 5-13工作分配问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int n,a[21][21],sum=0,minsum=99999999;
bool flag[21];
vector<int> v,v1;
void dfs(int depth, int u) {
	flag[u] = true;
	//v.push_back(u);
	sum += a[depth][u];
	if (depth == n) {
	/*	for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "sum = " << sum << endl;*/
		if (sum < minsum)minsum = sum;
		sum -= a[depth][u];
		//v.pop_back();
		flag[u] = false;
		return;
	}
	for (int i = 1; i <=n; i++) {
		if (flag[i] == false)
			dfs(depth + 1, i);
	}
	sum -= a[depth][u];
	//v.pop_back();
	flag[u] = false;
}
int main()
{
	cin >> n;
	fill(flag, flag + 21, false);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <=n; i++) {
		sum = 0;
		dfs(1, i);
	}
	cout << minsum;
    return 0;
}

