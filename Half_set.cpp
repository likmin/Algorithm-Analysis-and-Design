#include<iostream>
using namespace std;
int half_set(int n) {
	int ans = 1;
	if(n>1)for (int i = 1; i <=n / 2; i++)ans += half_set(i);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << half_set(n);
    return 0;
}
