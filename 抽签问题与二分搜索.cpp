#include <iostream>
#include <algorithm>
using namespace std;
/*二分算法的两种思路：
	1.时间复杂度O(n3*logn):先三重枚举三个值，再最后二分搜索最后一个值
	2.时间复杂度O(n2*logn平方):先二重枚举两个值，让他们的和存入一个数组中
	再二分搜索这个数组是否存在所需要的值
*/
int k[55];
int kk[2505];
bool BINARY_search( int x,int n,int a[])
{//手写一个二叉搜索
	int left = 0, right = n;
	while (right - left > 0)	
	{/*x如果比中间元素大，left=i，right不变
	   x如果比中间元素小，right=i，left不变*/
		int i = (right + left) / 2;		//中间元素
		if (a[i] == x) return true;
		if (a[i] < x) left = i;
		else right = i;

	}
	//如果循环完还没有找到，直接return
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		cin >> k[i];
	sort(k, k + n);
	/*以下是第一种方法*/
	bool flag=false;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			for (int z = 0;z < n;z++)
			{
				if (binary_search(k, k + n, m - k[i] - k[j] - k[z]))
					flag = true;
			}
	cout << flag << '\n';
	/*以下是第二种方法，简化了时间复杂度*/
	flag = false;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			kk[n * i + j] = k[i] + k[j];		//两次抽签结果的和
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (binary_search(kk, kk + n * n, m - k[i] - k[j]))
				flag = true;
	cout << flag << '\n';
}