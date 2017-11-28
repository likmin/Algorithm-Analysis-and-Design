// 5-1子集和问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int n,c,sum=0;
vector<int> v,fin,visit;
int backtrack(int i){
	if(i>n){
		if(sum==c)return true;
		else return false;
	}
	if(sum+v[i]<=c){
		sum+=v[i];
		if(backtrack(i+1)){
			fin.push_back(v[i]);
			return true;
		}
		sum-=v[i];		
	}


}
int main(){


	cin>>n>>c;
	v.resize(n);
	visit.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++){
		fill(visit.begin(),visit.end(),0);
		backtrack(i);
		if(sum==c)break;
	}
	for(int i=0;i<fin.size();i++)
		cout<<fin[i]<<" ";
}
