#include <iostream>
//#include <stdio.h>
#include <vector>

using namespace std;



long long CreateKthLuckNum(int k)
{
	vector<long long>  history;
	history.push_back(4);
	history.push_back(7);
	if (k <= 2)
	{
		return history[k-1];
	}

	history.assign(k, 0);
	history[0] = 4;
	history[1] = 7;

	for (int i = 2; i < k;i++)
	{
		for (int j = 0; j < i;j++)
		{
			long long minVal = history[j] * 10 + 4;
			if (minVal>history[i-1])
			{
				history[i] = minVal;
				break;
			}
			minVal = history[j] * 10 + 7;
			if (minVal>history[i - 1])
			{
				history[i] = minVal;
				break;
			}
		}
	}
	return history[k - 1];
}



int main()
{
	int count = 0;
	int k = 0;
	//while (scanf("%d",&count)!=EOF)
	while (cin>>count)
	{
		while (count--)
		{
			//scanf("%d", &k);
			cin >> k;
			printf("%lld", CreateKthLuckNum(k));			
		}
	}
	return 0;
}