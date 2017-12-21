// 5-3最小重量机器设计问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int n, m, d, w[100][100], c[100][100];
bool flag[100][100];
int a = 0;
int minnum = 99999999;
vector<int> v,v1;
void dfs(int depth,int u) {
	v.push_back(u);
	a =a+ w[depth][u];
	if (depth == n) { 
		/*for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "a = "<<a<<endl;*/
		if (minnum > a) { minnum = a; v1 = v; }
		v.pop_back();
		a -= w[depth][u];
		return;
	}
	for (int i = 1; i <= m; i++) {
			dfs(depth + 1, i);
	}
	v.pop_back();
	a -= w[depth][u];
}
int main()
{
	cin >> n >> m >> d;
	
	for (int i = 1; i <=n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> c[i][j];
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> w[i][j];

	fill(flag[0], flag[0] + 100 * 100, false);
	cout << endl;
	for (int i = 1; i <= m; i++) {
		v.clear();
		dfs(1, i);
	}
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i]<<" ";
	cout << minnum;
}

