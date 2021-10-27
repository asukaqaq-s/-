#include <iostream>
#include <algorithm>
using namespace std;
/*�����㷨������˼·��
	1.ʱ�临�Ӷ�O(n3*logn):������ö������ֵ�����������������һ��ֵ
	2.ʱ�临�Ӷ�O(n2*lognƽ��):�ȶ���ö������ֵ�������ǵĺʹ���һ��������
	�ٶ���������������Ƿ��������Ҫ��ֵ
*/
int k[55];
int kk[2505];
bool BINARY_search( int x,int n,int a[])
{//��дһ����������
	int left = 0, right = n;
	while (right - left > 0)	
	{/*x������м�Ԫ�ش�left=i��right����
	   x������м�Ԫ��С��right=i��left����*/
		int i = (right + left) / 2;		//�м�Ԫ��
		if (a[i] == x) return true;
		if (a[i] < x) left = i;
		else right = i;

	}
	//���ѭ���껹û���ҵ���ֱ��return
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		cin >> k[i];
	sort(k, k + n);
	/*�����ǵ�һ�ַ���*/
	bool flag=false;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			for (int z = 0;z < n;z++)
			{
				if (binary_search(k, k + n, m - k[i] - k[j] - k[z]))
					flag = true;
			}
	cout << flag << '\n';
	/*�����ǵڶ��ַ���������ʱ�临�Ӷ�*/
	flag = false;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			kk[n * i + j] = k[i] + k[j];		//���γ�ǩ����ĺ�
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (binary_search(kk, kk + n * n, m - k[i] - k[j]))
				flag = true;
	cout << flag << '\n';
}