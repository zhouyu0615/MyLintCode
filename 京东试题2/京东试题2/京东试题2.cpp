// 京东试题2.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int Count(vector<int>& height)
{
	int count = 1;
	int len = height.size();
	for (int i = 0; i < len;i++)
	{
		int pathMaxVal = height[i];
		for (int j = i; j < len;j++)
		{
			if (height[j]>=height[i]&&height[j]>pathMaxVal)
			{
				count++;
			}
			pathMaxVal = max(pathMaxVal, height[j]);
		}
	}
	return count;
}

int main()
{
	int n = 0;
	vector<int> height;
	int num = 0;
	//while (scanf("%d",&n)!=EOF)
	while (cin>>n)
	{
		int temp = n;
		while (temp--)
		{
		
			//scanf("&d", &num);
			cin >> num;
			height.push_back(num);
		}
		printf("%d\n", Count(height));
	}
	return 0;
}
