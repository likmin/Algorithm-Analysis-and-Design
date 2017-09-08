// PageStatistics.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int count(long long n, int i) {
	long long iCount = 0;
	long long iFactor = 1;
	long long iLowerNum = 0;
	long long iCurrNum = 0;
	long long iHigherNum = 0;
	while (n / iFactor != 0) {
		iCurrNum = (n / iFactor) % 10;
		iLowerNum = n%iFactor;
		iHigherNum = n / (iFactor * 10);
		printf("i = %d  ", i);
		printf("iLowerNum = %4lld  iCurrNum = %4lld  iHigherNum = %4lld  ", iLowerNum, iCurrNum, iHigherNum);
		if (iCurrNum < i)
			iCount += iHigherNum*iFactor;
		else if (i == iCurrNum)
			iCount += iHigherNum*iFactor + iLowerNum + 1;
		else if (iCurrNum > i)
			iCount += (iHigherNum + 1)*iFactor;
		printf("iCount = %4lld ", iCount);
		if (i == 0)iCount -= iFactor;
		printf("iCount = %4lld \n", iCount);
		iFactor *= 10;
	}
	return iCount;
}
int main() {
	long long n;
	int num[10] = { 0 };
	cin >> n;
	for (int i = 0; i < 10; i++) {
		 cout<<count(n, i) ;
		 cout << endl;
	}
	return 0;
}