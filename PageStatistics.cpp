// PageStatistics.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<fstream>
using namespace std;
int count(long long n, int i) {
	long long iCount = 0;//统计i的个数
	long long iFactor = 1;//当前位数
	long long iLowerNum = 0;//比当前位数低的数的大小
	long long iCurrNum = 0;//当前位数的大小
	long long iHigherNum = 0;//比当前位大的数的大小
	/*
	比如说，n=1234,iFactor=10,那么，iCurrNum=3,iLowerNum=4,iHigherNum=12
	*/

	while (n / iFactor != 0) {
		iCurrNum = (n / iFactor) % 10;
		iLowerNum = n%iFactor;
		iHigherNum = n / (iFactor * 10);
		printf("i = %d  ", i);
		//printf("iLowerNum = %4lld  iCurrNum = %4lld  iHigherNum = %4lld  ", iLowerNum, iCurrNum, iHigherNum);
		if (iCurrNum < i)
			iCount += iHigherNum*iFactor;
		/*
		如果n=1234,iFactor=10,则iCurrNum=3,iLowerNum=4,iHigherNum=12，
		如果统计i=4，即十位上i=4的，
		40，41,42...49,    //10个
		140,141,142...149, //10个
		240...,			   //10个
		.........
		1140...1149

		共iHigherNum行,即12行，所以十位上有12*10
		*/
		else if (i == iCurrNum)
			iCount += iHigherNum*iFactor + iLowerNum + 1;
		/*
		如果n=1234,iFactor=10,则iCurrNum=3,iLowerNum=4,iHigherNum=12，
		如果统计i=3，即十位上i=3的，
		30,31,32...39,    //10个
		130,131,132...139, //10个
		230...,			   //10个
		.........
		1130...1139
		1230,1231,1232,1233,1234//iLowerNum+1个
		共iHigherNum行,即13行，
		前12行个数都是iFactor个，即10个，最后一行有iLowerNum+1个
		所以十位上有iHigherNum*iFactor + iLowerNum + 1个;即12*10+4+1个
		*/

		else if (iCurrNum > i)
			iCount += (iHigherNum + 1)*iFactor;
		/*
		如果n=1234,iFactor=10,则iCurrNum=3,iLowerNum=4,iHigherNum=12，
		如果统计i=2，即十位上i=2的，
		20,21,22...29,     //10个
		120,121,122...129, //10个
		220...,			   //10个
		.........
		1120...1129
		1220...1229		   //10个
		共iHigherNum行,即iHigherNum+1行，即13行，每一行都有iFactor个，即10个
		所以十位上有（iHigherNum+1）*iFactor 个;即13*10个
		*/
		printf("iCount = %4lld ", iCount);
		if (i == 0)iCount -= iFactor;
		/*
		但是必须考虑0的情况，如果统计是0，那必须把多余的0给取出来。
		统计个位数的0时，即iFactor等于1时，多了1个0，
		统计十位数的0时，即iFactor等于10时，多了10个0，
		...
		以此类推，iFactor等于多少就多几个0
		*/
		printf("iCount = %4lld \n", iCount);
		iFactor *= 10;
	}
	return iCount;
}
int main() {
	long long n;
	int num[10] = { 0 };
	fstream file;
	file.open("input.txt");
	file >> n;
	file.close();
	file.open("output.txt");
	for (int i = 0; i < 10; i++) {
		file << count(n, i) << endl ;
		 cout << endl;
	}
	file.close();
	return 0;
}