#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{


	int N,sum=0,wait=0;
	cin>>N;
	vector<int> v(N);
	for(int i=0;i<N;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++){
		wait+=v[i];
		sum+=wait;
		
	}

	printf("sum = %d\n",sum);
	printf("%0.2f",sum*1.0/N);               
}
