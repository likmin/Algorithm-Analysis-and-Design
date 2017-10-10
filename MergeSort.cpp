#include<iostream>
using namespace std;
int a[10] = { 15,21,4,1,75,11,2,5,8,14 };
int b[10];
void Merge(int left, int m, int right) {
	int i = left, j = m + 1, k = left;
	while (i <= m&&j <= right) {
		if (a[i] <= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	if (i > m)
		for (int n = j; n <= right; n++)
			b[k++] = a[n];
	else
		for (int n = i; n <= m; n++)
			b[k++] = a[n];
}
void copy(int left, int right) {
	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}
}
void MergeSort(int left, int right) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	if (left < right) {
		int i = (left + right) / 2;//取中点
		MergeSort(left, i);//合并排列左侧数据
		MergeSort(i + 1, right);//合并排列右侧侧数据
		Merge(left, i, right);//合并到数组b中
		copy(left, right);//复制到数组a
	}

}
int main()
{
	MergeSort(0, 10);
	for (int i = 0; i < 11; i++) {//都越界了！！！！
		printf("%d ", a[i]);
	}
	return 0;
}
