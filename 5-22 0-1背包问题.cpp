//0-1背包问题，DFS，二叉树
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int w;
	int v;
	struct node *right, *left;
};
vector<int> s1,s2, S,V;
int maxvalue = -1;
int n, c, depth = -1;
void DFS(node *root) {
	if (depth == n - 1) { 
		if (root->v > maxvalue) {
			maxvalue = root->v;
			for (int i = 0; i < n; i++)	s2[i] = s1[i];
		}
		return;
	}
	if (depth < n - 1) {
		  
		depth++;
		root->left = new node;
		if (root->w + S[depth] <= c) {//Èç¹ûµ±Ç°ÎïÆ·¿ÉÒÔ·Åœø±³°ü£¬·ÅœøÈ¥
			root->left->w = root->w + S[depth];
			root->left->v = root->v + V[depth];
			s1[depth] = 1;
			DFS(root->left);
		}
		//µ±Ç°ÎïÆ·²»·Åœø±³°üÖÐ£¬ËûºÍÇ°Õß²»ÊÇif...else...µÄ¹ØÏµ£¬
		//ÓÉÓÚÊÇ²»¶Ï±éÀúµÄ£¬ÊÜ¿ÕŒäÏÞÖÆ£¬×ó×ÓÊ÷¿ÉÒÔ²»±éÀú£¬ÓÒ×ÓÊ÷±ØÐë±éÀúµÄ

			s1[depth] = 0;
			root->right = new node;
			root->right->w = root->w;
			root->right->v = root->v;
			DFS(root->right);	
		depth--;
	}

}
int main()
{
	cin >> n >> c;
	S.resize(n + 1);
	V.resize(n + 1);
	s1.resize(n + 1);
	s2.resize(n + 1);

	for (int i = 0; i < n; i++) cin >> V[i];
	for (int i = 0; i < n; i++) cin >> S[i];
	

	node *root = new node;
	root->w = 0;
	root->v = 0;
	root->left = root->right = NULL;
	DFS(root);
	cout << maxvalue << endl;
	for (int i = 0; i < n; i++)cout << s2[i]<<" ";
	system("pause");
	return 0;
}