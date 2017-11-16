#include  <iostream>
#include  <cstdlib>
#include  <string>
#include  <fstream>
#define   N   100
using  namespace  std;
typedef  struct  BiTNode
{
	char  data;
	struct  BiTNode  *lchild, *rchild;
}BiTNode, *BiTree;

void  preorder(BiTNode  *root)
{
	if (root == NULL)return;
	printf("%c ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void  inOrder(BiTNode  *root)
{
	if (root == NULL)return;
	inOrder(root->lchild);
	printf("%c ", root->data);
	inOrder(root->rchild);
}
void  lastOrder(BiTNode  *root)
{
	if (root == NULL)return;
	inOrder(root->lchild);
	inOrder(root->rchild);
	printf("%c ", root->data);
}
void createBiTree(char  *pre,int i,int j, char  *in, int m,int n,BiTree *t)
{
	*t = (BiTNode *)malloc(sizeof(BiTNode));
	(*t)->data = pre[i];//先序数组中的第一个点为父节点
	int k = m;			//我们从中序数组中找到父节点，中序的左边为该节点的左孩子，中序的右边为该节点的右孩子，
	while (in[k] != pre[i])k++;
	if (k == m)(*t)->lchild = NULL;//如果k==m，说明该节点没有左孩子，else 去构造左孩子
	else createBiTree(pre, i + 1, i + k - m, in, m, k - 1, &((*t)->lchild));

	if (k == n)(*t)->rchild = NULL;//如果k==n，说明该节点没有右孩子,else 去构造右孩子
	else createBiTree(pre, i + k - m + 1, j, in, k + 1, n, &((*t)->rchild));
}

int main()

{

	char preNode[N];
	char inNode[N];
	int n, i = 0;
	char ch;
	BiTNode* root = NULL;
	cin >> n;
	printf("请输入先序序列\n");
	while (i < n) {
		cin >> ch;
		preNode[i++] = ch;
	}
	i = 0;
	printf("请输入中序序列\n");
	while (i < n) {
		cin >> ch;
		inNode[i++] = ch;
	}
	 createBiTree(preNode,0,n-1, inNode,0,n-1, &root);
	printf("先序序列\n");
	preorder(root);
	printf("\n中序序列\n");
	inOrder(root);
	printf("\n后序序列\n");
	lastOrder(root);
	return 0;
}
