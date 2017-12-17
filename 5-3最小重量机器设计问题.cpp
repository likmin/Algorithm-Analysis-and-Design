// 5-3最小重量机器设计问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	struct node *right, *left;
};
vector<int> s1,S;
int n, c,depth=-1;
void print() {
	vector<int>::iterator it2 = s1.begin();
	while (it2 != s1.end()) {
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
/*
0-1背包问题，
深度优先遍历二叉树，depth为二叉树的深度，
如果要遍历左子树，就把当前层的值S[depth]放进栈s1中，
并赋值当前节点为上一节点加上当前层的值，即root->left->data=root->data+S[depth]
如果是要遍历右子树，不把当前层的值放进去，
把上一节点的值赋值给当前节点即可，即root->right->data=root->data;
*/
void DFS(node *root) {
	if (root->data == c)print();
	else if (root->data > c)return;
	if (depth < n-1) {
		depth++;
		root->left = new node;
		root->left->data = root->data + S[depth];
		s1.push_back(S[depth]);
		DFS(root->left);
		s1.pop_back();

		root->right = new node;
		root->right->data = root->data;
		DFS(root->right);
		depth--;
	}

}
int main()
{
	cin >> n >> c;
	S.resize(n+1);
	for (int i = 0; i < n; i++) cin >> S[i];
	node *root = new node;
	root->data = 0;
	root->left = root->right = NULL;
	DFS(root);
    return 0;
}

