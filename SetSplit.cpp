#include<iostream>
using namespace std;
int S(int n,int m) {
	//如果m=0,或者m>n,不存在，
	if (m>n ||m==0)return 0;
	//如果划分成1个非空集合，或者只对1个集合划分，或者划分的个数等于集合的个数
	else if (m==1||n==1||m==n)return 1;
	/*
	对n个元素进行编号，对于最后那个n号元素进行分别讨论。
	1.把n号元素独立组成一个集合，也就是说把前n-1个元素分成m-1份，然后n号元素单独放，也就是S(n - 1, m - 1)种;
	2.另一种就是把前n-1个元素分成m份，然后把n号元素放入这m个集合中，也就是m*S(n-1,m)种方法
	*/
	else return m*S(n - 1, m) + S(n - 1, m - 1);
}
int main()
{
	int n,m;
	cin >> n>>m;
	cout<<S(n,m);
    return 0;
}
