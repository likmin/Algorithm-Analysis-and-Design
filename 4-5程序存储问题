
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N,L,sum=0;
	cin >> N>>L;
	vector<int> v1(N);
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	int i=0;
	while(sum+v1[i]<L){
		sum+=v1[i++];
	}
	cout<<i;
    return 0;
}
