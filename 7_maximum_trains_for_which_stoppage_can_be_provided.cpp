#include <bits/stdc++.h>
using namespace std;

#define n 2
#define m 5

int maxStop(int arr[][3])
{
	vector<pair<int, int>> vect[n + 1];
	for (int i = 0; i < m; i++)
		vect[arr[i][2]].push_back({arr[i][1], arr[i][0]});

	for (int i = 0; i <= n; i++)
		sort(vect[i].begin(), vect[i].end());

	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		if (vect[i].empty())
			continue;
		int x = 0;
		count++;
		for (int j = 1; j < vect[i].size(); j++)
		{
			if (vect[i][j].second >= vect[i][x].first)
			{
				x = j;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int arr[m][3] = {{1000, 1030, 1}, {1010, 1020, 1}, {1025, 1040, 1}, {1130, 1145, 2}, {1130, 1140, 2}};
	cout << "Maximum Stopped Trains = " << maxStop(arr);
	return 0;
}
