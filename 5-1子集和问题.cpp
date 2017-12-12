// 5-1子集和问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include<algorithm>
using namespace std;
int n, c;
vector<int> v, X;


void subsetSum(vector<int>& W, vector<int>& X, int sum, int k) {
	X[k] = 1; // try one branch of tree  
	if (sum + W[k] == c) {//如果当前加上当前节点等于最终的值
		for (int i = 0; i < X.size(); ++i) {
			if (X[i])
				cout << v[i] << " ";
		}
		cout << endl;
	}
	else if (k + 1 < W.size() && sum + W[k] <= c)
		subsetSum(W, X, sum + W[k], k + 1);

	X[k] = 0;
	if (k + 1 < W.size() && sum + W[k+1] <= c)
		subsetSum(W, X, sum, k + 1);

}

int main() {
	//cin >> n >> c;
	/*for (int i = 0; i < n; i++) {
	int temp;
	cin >> temp;
	v.push_back(temp);
	}*/
	n = 5; c = 14;
	v = { 2,2,6,5,4 };
	for (int i = 0; i < v.size(); i++) {
		X.resize(v.size());
		swap(v[0], v[i]);
		subsetSum(v, X, 0, 0);
	}
	return 0;
}
