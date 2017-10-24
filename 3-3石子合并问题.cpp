// 3-3石子合并问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int inf=99999999;
int n,a[101],sum=0;
bool flag[101]={false};
int findmin(){
	int min=inf,u=-1;
	for(int i=0;i<n;i++){
		if(flag[i]==false&&a[i]<min){
			min=a[i];
			u=i;
		}
	}
	flag[u]=true;
	return u;
}

int findmax(){
	int max=-1,u=-1;
	for(int i=0;i<n;i++){
		if(flag[i]==false&&a[i]>max){
			max=a[i];
			u=i;
		}
	}
	flag[u]=true;
	return u;

}
int main(){
/*
求最小值就是以此找到数组中的最小值，找到后标记上，temp表示上一次找到的最小值，
找到最小值后加到temp上，再把temp加到sum上。
求最大值与此类似
*/
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int temp=a[findmin()];
	cout<<"temp = "<<temp<<endl;;
	int u=findmin();
	while(u!=-1){
		temp+=a[u];
		sum+=temp;
		cout<<"u = "<<u<<" temp = "<<temp<<endl;
		u=findmin();
	}
	cout<<sum;
	fill(flag,flag+101,false);
	sum=0;
	temp=a[findmax()];
	cout<<"temp = "<<temp<<endl;;
	 u=findmax();
	while(u!=-1){
		temp+=a[u];
		sum+=temp;
		cout<<"u = "<<u<<" temp = "<<temp<<endl;
		u=findmax();
	}
	cout<<sum;
}