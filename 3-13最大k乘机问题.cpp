// 3-13最大k乘机问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int n,k;
string I;
int f[101][101],ka[101][101];
int conv(int i,int j){

	string str1=I.substr(i,j);
	return atoi(str1.c_str());
}
void solve(int n,int m){
	int i,j,k;
	int temp,maxt,tk;
	for(i=1;i<=n;i++)f[i][1]=conv(0,i);
	for( j=2;j<=m;j++){
		for( i=j;i<=n;i++){		
			for(k=1,temp=0;k<i;k++){
				maxt=f[k][j-1]*conv(k,i-k);
				if(temp<maxt){temp=maxt;tk=k;}
			}
			f[i][j]=temp;ka[i][j]=tk;
		}
	}
}
void out(int n,int m){
	cout<<f[n][m]<<endl;

	for(int i=m,k=n;i>=1&&k>0;k=ka[k][i],i--){
		printf("f[%d][%d] = %d \n",k,i,f[k][i]);
	
	}

}
int main(){

	cin>>n>>k;
	cin>>I;
	if(n<k||n==0||n!=I.size()){
		cout<<"0"<<endl;
		return 0;
	}
	solve(n,k);
	out(n,k);
	
}
