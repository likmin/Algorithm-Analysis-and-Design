#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dist[6][7];
int min(int A, int B, int C) {
	if (B < A)
		A = B;
	if (C < A)
		A = C;
	return A;
}
int main()
{

	string a = "fxpimu";
	string b = "xwrs";
	for (int i = 0; i <b.size(); i++) {
		for (int j = 0; j <a.size(); j++) {
			if (i == 0 && j == 0)dist[i][j] = 0;
			else if (i == 0 && j > 0)dist[i][j] = j;
			else if (i > 0 && j == 0)dist[i][j] = i;
			else {
				int k = b[i] == a[j] ? 0 : 1;
				dist[i][j] = min(dist[i - 1][j]+1, dist[i][j - 1] + 1, dist[i - 1][ j - 1] + k);
			}
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	printf("编辑距离为%d",dist[b.size()][a.size()]);
     return 0;
}
