#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
/*���ڱ����ǹ���һ�������Σ����Ǹ�����һ��ѡ�����Ŀ�̶���3
�Ͳ���Ҫʹ�õݹ��ˣ�ֱ������ö�ټ���*/
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
	/*����һ����������forѭ��ö������������������Ͼ�������max�Ƚϣ�����˭�����ֵ
	���û�еĻ�����������0*/
	for(int i=0;i<n;i++)
		for (int j = 0;j < n;j++)
			for (int k = 0;k < n;k++)
			{
				if (i == j || i == k || j == k) continue;
				if (check(i,j,k))
					MAX = max(MAX, a[i] + a[j] + a[k]);
			}
	cout << MAX << '\n';
	/*������������algorithm��ֱ�ӽ��������������Ӻ���ǰѰ��*/
	sort(a, a + n);
	int max2 = 0;
	for(int i=n-1;i>=0;i--)
		for(int j=n-2;j>=0;j--)
			for (int k = n - 3;k >= 0;k--)
			{
				if (check(i, j, k))
				{
					max2 = max(max2, a[i] + a[j] + a[k]);
					break;
				}
			}
	cout << max2;
}