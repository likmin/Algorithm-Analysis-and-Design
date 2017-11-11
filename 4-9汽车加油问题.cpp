// 4-9汽车加油问题.cpp : 定义控制台应用程序的入口点。
//
/*
7 7
1 2 3 4 5 1 6 6

7 7
1 9 2 3 4 5 3 2
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(k + 2);
	v[0] = 0;
	for (int i = 1; i < k + 2; i++)
		cin >> v[i];
	int temp = n,flag=0,num=0;
	for (int i = 0; i < k + 1; i++) {
		if (n < v[i + 1]) {//如果加满油了还无法到达下一加油站
			flag = 1;
			break;
		}
		if (temp >= v[i + 1])//当前油量能够到达下一加油站
			temp = temp - v[i + 1];
		else {
			temp = n;
			temp = temp - v[i + 1];
			num++;
		}	
	}
	if (flag)printf("No Solution");
	else printf("%d", num);
    return 0;
}

