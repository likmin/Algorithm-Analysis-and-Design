// 矩阵连乘问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define n 6
int p[7]={30,35,15,5,10,20,25};
int m[7][7]={0};
/*

如果i=j,m[i][j]=0;
如果i<j,那就要去找断点的位置
所以m[i][j]=min{m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]}其中i=<k<j

*/
int main(){
	for(int i=1;i<=n;i++)m[i][i]=0;
	for(int r=2;r<=n;r++){//r表示子问题矩阵的个数，从而开始
		for(int i=1;i<=n-r+1;i++){//i表示子问题矩阵开始的下标
			int j=i+r-1;//j表示子问题矩阵的结束下标
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			/*
			刚开始在点i处断开,所以这里应该是m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
			但是m[i][i]=0,所以这里写成了m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			*/
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
				}
			
			}
		
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%6d ",m[i][j]);
		}
		cout<<endl;
	}
}
