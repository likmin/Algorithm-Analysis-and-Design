#include<iostream>
using namespace std;
int k=1;
void dicomp(int n,int a[]){
	/*1,2都不能满足条件，所以结果等于0*/
	if(n<3){a[1]=0;return;}
	/*对于3和4，只有两种1和n-1*/
	if(n<5){a[k]=1;a[++k]=n-1;return;}
	/*如果a+b为一常量，如果|a-b|越小，a*b越大*/
	a[1]=2;n-=2;
	/*
		从2开始分配，依次增大，直到不足以分配为止
	*/
	while(n>a[k]){
		k++;
		a[k]=a[k-1]+1;
		n-=a[k];
	}
	//以为接下来要把剩余的n平均分配给数组
	//如果n=a[k]会多一个，把多的这一个数分配给最后一个即可
	if(n==a[k]){
		a[k]++;n--;
	}
	for(int i=0;i<n;i++)a[k-i]++;
}
int main(){

	int a[10];
	int n,sum=1;
	cin>>n;
	dicomp(n,a);
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=k;i++){
		sum*=a[i];
	}
	cout<<"max Multiply = "<<sum;
}