#include<iostream>
using namespace std;
int *a=NULL;
int half_set(int n) {
	long ans = 1;
	if (a[n] > 0)return a[n];//如果数组中已经有了数
	if(n>1)for (int i = 1; i <=n / 2; i++)ans += half_set(i);
	a[n] = ans;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	a = new int[n + 1];//申请空间
	memset(a, sizeof(a), 0);//将空间里的每个数设为0
	cout << half_set(n);
    return 0;
}
