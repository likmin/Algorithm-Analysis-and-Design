#include<iostream>
using namespace std;
int main()
{

	/*
		A1			A2			A3			A4			A5			A6
	  30*35		   35*15	  15*5		   5*10		   10*20	  20*25
	  p0 p1			  p2	     p3          p4           p5         p6
	  m数组和s数组下标从1开始
	  初始化m数组和s数组的每一个数为99999999
	  m用于存储矩阵连乘积的最优值，例如，m[i][j]表示从i计算到j连乘积的最优值
	  s数组用于记录在哪里加括号能取得最优值，比如s[i][j]=m,表示从i到j在m处加括号。
  */
	int p[7] = { 30,35,15,5,10,20,25 };
	int n = 6;
	int m[7][7], s[7][7];
	fill(m[0], m[0] + 6 * 6, 99999999);
	fill(m[0], m[0] + 6 * 6, 99999999);

	/*
		m[i][i]=0,也就是说只有一个矩阵时,不存在连乘积问题
	*/
	for (int i = 1; i <= n; i++)m[i][i] = 0;

	/*
		我们要找A1A2A3A4A5A6六个矩阵的连乘积最优值问题，我们就要先找到
		五个矩阵最优值，以此类推，我们先找到两个问题的最优值的解。
		这里r代表矩阵的个数
	*/

	for (int r = 2; r <= n; r++) {
		/*
		i表示矩阵开始的下标，到n-r+1结束
		*/
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;

			/*
			直接计算从矩阵i到矩阵j的连乘积，
			记录加括号处
			*/
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;



			for (int k = i + 1; k < j; k++) {

		
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%10d ", m[i][j]);
		}
		cout << endl;
	}
	
    return 0;
}
