// 3-3石子合并问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int dp[101][101],//dp[i][j]表示从第i对石子开始，长度为j的各队石子的最优组合的分数，分数最小
	dp2[101][101],//dp2[i][j]表示从第i对石子开始，长度为j的各队石子的最优组合的分数，分数最大
	sum[101][101],//sum[i][j]表示从第i堆石子开始，长度为j的各队石子的总分。
	p[101];//p[i]表示第i堆石子的个数
int inf = INT32_MAX;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	for (int i = 1; i <=N; i++)
		sum[i][1] = p[i];

	for (int j = 2; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			sum[i][j] = sum[i][j - 1] + p[(i + j - 2) % N + 1];
		}
	}
	/*
	p 4 4 5 9
	sum
	4 8 13 22
	4 9 18 22
	5 14 18 22
	9 13 17 22
	*/
	for (int i = 1; i <= N; i++) {
		dp[i][1] = 0;
		dp2[i][1] = 0;
	}
	/*
	其中dp[i][1]=0;
    dp[i][j]=min(dp[i][k]+dp[(i+k-1)%n+1][j-k]+sum[i][j]),其中1<=k<j

	dp
	0 8 21 43
	0 9 27 44
	0 14 31 44
	0 13 25 43
	dp2
	0 8 22 54
	0 9 32 54
	0 14 32 54
	0 13 30 52
	*/
	for (int j = 2; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			dp[i][j] = inf; dp2[i][j] = 0;
			for (int k = 1; k < j; k++) {
				int temp = dp[i][k] + dp[(i + k - 1) % N + 1][j - k] + sum[i][j];
				dp[i][j] = (temp<dp[i][j]?temp:dp[i][j]);
			}
			for (int k = 1; k < j; k++) {
				int temp = dp2[i][k] + dp2[(i + k - 1) % N + 1][j - k] + sum[i][j];
				dp2[i][j] = (temp>dp2[i][j] ? temp : dp2[i][j]);
			}
		}
	}
	int minScore = dp[1][N];
	int maxScore = dp2[1][N];
	for (int i = 2; i <= N; i++) {
		minScore = (minScore<dp[i][N]? minScore: dp[i][N]);
		maxScore = (maxScore>dp2[i][N] ? maxScore : dp2[i][N]);
	}
	printf("minScore = %d\nmaxScore = %d\n", minScore,maxScore);
    return 0;
}


