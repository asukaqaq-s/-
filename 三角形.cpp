#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
/*由于本题是构造一个三角形，于是给定了一个选择的数目固定是3
就不需要使用递归了，直接三重枚举即可*/
bool check(int i, int j, int k)
{
	if (a[i] + a[j] <= a[k] || a[i] + a[k] <= a[j] || a[k] + a[j] <= a[i])
		return false;
	return true;
}
int main()
{
	int n;
	int MAX = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	/*方法一：运用三重for循环枚举三个变量，如果符合就让他和max比较，看看谁是最大值
	如果没有的话，那他就是0*/
	for(int i=0;i<n;i++)
		for (int j = 0;j < n;j++)
			for (int k = 0;k < n;k++)
			{
				if (i == j || i == k || j == k) continue;
				if (check(i,j,k))
					MAX = max(MAX, a[i] + a[j] + a[k]);
			}
	cout << MAX << '\n';
	/*如果给入的数据是乱序的，可以运用sort去把他排序*/
}
